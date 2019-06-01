// {C} Copyright 2018 Pensando Systems Inc. All rights reserved.

package finder

import (
	"context"
	"encoding/json"
	"fmt"
	"strings"
	"sync"
	"time"

	"github.com/gogo/protobuf/proto"
	"github.com/gogo/protobuf/types"
	es "github.com/olivere/elastic"
	"github.com/pkg/errors"
	"google.golang.org/grpc"
	grpccode "google.golang.org/grpc/codes"
	grpcstatus "google.golang.org/grpc/status"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/api/fields"
	"github.com/pensando/sw/api/generated/audit"
	"github.com/pensando/sw/api/generated/auth"
	diagapi "github.com/pensando/sw/api/generated/diagnostics"
	evtsapi "github.com/pensando/sw/api/generated/events"
	monapi "github.com/pensando/sw/api/generated/monitoring"
	"github.com/pensando/sw/api/generated/search"
	"github.com/pensando/sw/api/labels"
	"github.com/pensando/sw/venice/globals"
	"github.com/pensando/sw/venice/spyglass/cache"
	"github.com/pensando/sw/venice/utils"
	venutils "github.com/pensando/sw/venice/utils"
	"github.com/pensando/sw/venice/utils/authz"
	authzgrpc "github.com/pensando/sw/venice/utils/authz/grpc"
	authzgrpcctx "github.com/pensando/sw/venice/utils/authz/grpc/context"
	"github.com/pensando/sw/venice/utils/ctxutils"
	"github.com/pensando/sw/venice/utils/diagnostics"
	"github.com/pensando/sw/venice/utils/diagnostics/module"
	diagsvc "github.com/pensando/sw/venice/utils/diagnostics/service"
	"github.com/pensando/sw/venice/utils/elastic"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/resolver"
	"github.com/pensando/sw/venice/utils/rpckit"
	"github.com/pensando/sw/venice/utils/runtime"
)

const (
	elasticWaitIntvl  = time.Second
	maxElasticRetries = 200
	tenantAggKey      = "tenant_agg"
	kindAggKey        = "kind_agg"
	topHitsKey        = "top_agg"
)

// ErrInvalidParams is error returns when search parameters
// are either invalid or out of range.
var ErrInvalidParams = errors.New("Invalid search parameters")

// Option fills the optional params for Finder
type Option func(*Finder)

// Finder is an implementation of the finder.Interface
type Finder struct {
	sync.WaitGroup
	ctx           context.Context
	logger        log.Logger
	elasticClient elastic.ESClient
	rsr           resolver.Interface
	finderAddr    string
	rpcServer     *rpckit.RPCServer
	cache         cache.Interface
	diagSvc       diagnostics.Service
	moduleWatcher module.Watcher
}

// WithElasticClient passes a custom client for Elastic
func WithElasticClient(esClient elastic.ESClient) Option {
	return func(fdr *Finder) {
		fdr.elasticClient = esClient
	}
}

// WithModuleWatcher passes a custom module watcher
func WithModuleWatcher(moduleWatcher module.Watcher) Option {
	return func(fdr *Finder) {
		fdr.moduleWatcher = moduleWatcher
	}
}

// WithDiagnosticsService passes a custom diagnostics service
func WithDiagnosticsService(diagSvc diagnostics.Service) Option {
	return func(fdr *Finder) {
		fdr.diagSvc = diagSvc
	}
}

// NewFinder instantiates a new finder instance
func NewFinder(ctx context.Context, finderAddr string, rsr resolver.Interface, cache cache.Interface, logger log.Logger, opts ...Option) (Interface, error) {

	fdr := Finder{
		ctx:        ctx,
		finderAddr: finderAddr,
		rsr:        rsr,
		cache:      cache,
		logger:     logger,
	}

	for _, opt := range opts {
		if opt != nil {
			opt(&fdr)
		}
	}

	log.Debugf("Created Finder {+%v}", &fdr)
	return &fdr, nil
}

// Start finder service
func (fdr *Finder) Start() error {

	// Start the rpc-server
	fdr.logger.Infof("Starting finder rpc server at: %s", fdr.finderAddr)
	err := fdr.startRPCServer(globals.Spyglass, fdr.finderAddr)
	if err != nil {
		fdr.logger.Errorf("Failed to start rpc-server, err: %s", err)
		return err
	}

	// Initialize elastic client
	if fdr.elasticClient == nil {
		result, err := utils.ExecuteWithRetry(func(ctx context.Context) (interface{}, error) {
			return elastic.NewAuthenticatedClient("", fdr.rsr, fdr.logger.WithContext("submodule", "elastic"))
		}, elasticWaitIntvl, maxElasticRetries)
		if err != nil {
			fdr.logger.Errorf("Failed to create elastic client, err: %v", err)
			return err
		}
		fdr.logger.Debug("Created Elastic client")
		fdr.elasticClient = result.(elastic.ESClient)
	}

	if fdr.moduleWatcher == nil {
		// start module watcher
		fdr.moduleWatcher = module.GetWatcher(fmt.Sprintf("%s-%s", utils.GetHostname(), globals.Spyglass), globals.APIServer, fdr.rsr, fdr.logger, fdr.moduleChangeCb)
	}

	return nil
}

// Stop finder service
func (fdr *Finder) Stop() {
	fdr.logger.Debug("Stopping finder")
	fdr.diagSvc.Stop()
	fdr.stopRPCServer()
	fdr.elasticClient.Close()
	fdr.moduleWatcher.Stop()
	fdr.logger.Info("Stopped finder")
}

// QueryBuilder builds Elastic Bool query based on search requirements
func (fdr *Finder) QueryBuilder(req *search.SearchRequest) (es.Query, error) {

	// Validate request
	if req == nil {
		return nil, errors.New("Nil search request")
	}

	// Check if QueryString is valid and construct QueryStringQuery
	if len(req.QueryString) != 0 {
		return es.NewQueryStringQuery(req.QueryString), nil
	}

	// Constuct Bool query based on search requirements
	if req.Query == nil {
		fdr.logger.Error("Query in Body is nil")
		return nil, errors.New("Nil search request")
	}

	query := es.NewBoolQuery().QueryName("CompleteQuery")

	// Process Text Requirements
	textReq := es.NewBoolQuery().QueryName("TextQuery")
	for _, treq := range req.Query.Texts {

		tQuery := es.NewBoolQuery()
		for _, text := range treq.Text {
			if strings.Contains(text, " ") {
				// Phrase query
				tQuery = tQuery.Must(es.NewQueryStringQuery(fmt.Sprintf("\"%s\"", text)))
			} else {
				// Word query
				tQuery = tQuery.Must(es.NewQueryStringQuery(text))
			}
		}
		textReq = textReq.Should(tQuery).MinimumNumberShouldMatch(1)
	}
	if len(req.Query.Texts) > 0 {
		query = query.Must(textReq)
	}

	// Process categories requirement
	catReq := es.NewBoolQuery().QueryName("CategoryQuery")
	for _, cat := range req.Query.Categories {
		catReq = catReq.Should(es.NewTermQuery("meta.labels._category.keyword", cat)).MinimumNumberShouldMatch(1)
	}
	if len(req.Query.Categories) > 0 {
		query = query.Must(catReq)
	}

	// Process kinds requirement
	kindReq := es.NewBoolQuery().QueryName("KindQuery")
	for _, cat := range req.Query.Kinds {
		kindReq = kindReq.Should(es.NewTermQuery("kind.keyword", cat)).MinimumNumberShouldMatch(1)
	}
	if len(req.Query.Kinds) > 0 {
		query = query.Must(kindReq)
	}

	// Process field requirement if it is valid
	if req.Query.Fields != nil {
		for _, field := range req.Query.Fields.Requirements {
			switch field.Operator {
			case fields.Operator_name[int32(fields.Operator_equals)]:
				if len(field.Values) > 0 {
					query = query.Must(es.NewMatchPhraseQuery(field.Key, field.Values[0]))
				}
			case fields.Operator_name[int32(fields.Operator_notEquals)]:
				if len(field.Values) > 0 {
					query = query.MustNot(es.NewMatchPhraseQuery(field.Key, field.Values[0]))
				}
			case fields.Operator_name[int32(fields.Operator_in)]:
				fieldQuery := es.NewBoolQuery().MinimumNumberShouldMatch(1)
				for _, val := range field.GetValues() {
					fieldQuery.Should(es.NewMatchPhraseQuery(field.Key, val))
				}
				query = query.Must(fieldQuery)
			case fields.Operator_name[int32(fields.Operator_notIn)]:
				for _, val := range field.GetValues() {
					query = query.MustNot(es.NewMatchPhraseQuery(field.Key, val))
				}
			case fields.Operator_name[int32(fields.Operator_gt)]:
				if len(field.Values) > 0 {
					query = query.Must(es.NewRangeQuery(field.Key).Gt(field.Values[0]))
				}
			case fields.Operator_name[int32(fields.Operator_gte)]:
				if len(field.Values) > 0 {
					query = query.Must(es.NewRangeQuery(field.Key).Gte(field.Values[0]))
				}
			case fields.Operator_name[int32(fields.Operator_lt)]:
				if len(field.Values) > 0 {
					query = query.Must(es.NewRangeQuery(field.Key).Lt(field.Values[0]))
				}
			case fields.Operator_name[int32(fields.Operator_lte)]:
				if len(field.Values) > 0 {
					query = query.Must(es.NewRangeQuery(field.Key).Lte(field.Values[0]))
				}
			}
		}
	}

	// Process label requirements if it is valid
	if req.Query.Labels != nil {
		for _, label := range req.Query.Labels.Requirements {
			lKey := fmt.Sprintf("%s.keyword", label.Key)
			switch label.Operator {
			case labels.Operator_name[int32(labels.Operator_equals)]:
				if len(label.Values) > 0 {
					query = query.Must(es.NewTermQuery(lKey, label.Values[0]))
				}
			case labels.Operator_name[int32(labels.Operator_notEquals)]:
				if len(label.Values) > 0 {
					query = query.MustNot(es.NewTermQuery(lKey, label.Values[0]))
				}
			case labels.Operator_name[int32(labels.Operator_in)]:
				values := make([]interface{}, len(label.Values))
				for i, v := range label.Values {
					values[i] = v
				}
				query = query.Must(es.NewTermsQuery(lKey, values...))
			case labels.Operator_name[int32(labels.Operator_notIn)]:
				values := make([]interface{}, len(label.Values))
				for i, v := range label.Values {
					values[i] = v
				}
				query = query.MustNot(es.NewTermsQuery(lKey, values...))
			}
		}
	}

	return query, nil
}

// AutoWatchSvcSearchV1 is not implemented
func (fdr *Finder) AutoWatchSvcSearchV1(*api.ListWatchOptions, search.SearchV1_AutoWatchSvcSearchV1Server) error {
	return errors.New("not implemented")
}

// AutoWatchSvcEventsV1 is not implemented
func (fdr *Finder) AutoWatchSvcEventsV1(*api.ListWatchOptions, evtsapi.EventsV1_AutoWatchSvcEventsV1Server) error {
	return errors.New("not implemented")
}

// Query is the handler for Search request
func (fdr *Finder) Query(ctx context.Context, in *search.SearchRequest) (*search.SearchResponse, error) {

	var sr search.SearchResponse

	fdr.logger.Infof("Search request: {%+v}", *in)

	// Validate search params
	if errs := in.Validate("", "", true, false); errs != nil {
		sr.Error = &search.Error{
			Type:   grpccode.InvalidArgument.String(),
			Reason: ErrInvalidParams.Error(),
		}
		return &sr, grpc.Errorf(grpccode.InvalidArgument, ErrInvalidParams.Error())
	}

	// ElasticSearch's Query and Aggregations JSON structure
	// While constructing start building inside out
	//
	// {
	//   "aggregations": {
	//     "tenant_agg": { <-- #1 Aggregate by Tenant
	//       "aggregations": {
	//         "category_agg": { <-- #2 Aggregate by Category
	//           "aggregations": {
	//             "kind_agg": { <-- #3 Aggregate by Kind
	//               "aggregations": {
	//                 "top_agg": { <-- #3 Aggregate top hits
	//                   "top_hits": {
	//                     "size": 10
	//                   }
	//                 }
	//               },
	//               "terms": {
	//                 "field": "kind"
	//               }
	//             }
	//           },
	//           "terms": {
	//             "field": "_type"
	//           }
	//         }
	//       },
	//       "terms": {
	//         "field": "meta.tenant"
	//       }
	//     }
	//   },
	//   "from": 0,
	//   "query": {
	//     "query_string": {
	//       "query": "us-west" <-- #0 Query string query parameter
	//     }
	//   },
	//   "size": 10
	// }

	// Build Elastic query
	query := es.NewBoolQuery().QueryName("CompleteQueryWithAuthorizedKinds")

	rQuery, err := fdr.QueryBuilder(in)
	if err != nil {
		fdr.logger.Errorf("error building query from *search.SearchRequest")
		return &sr, err
	}
	query = query.Must(rQuery)
	// returns authz query only if request is coming from API Gw
	aQuery, err := fdr.authzQuery(ctx, in.Tenants)
	if err != nil {
		fdr.logger.Errorf("error adding authorization to search query :%v", err)
		return &sr, err
	}
	if aQuery != nil {
		// aQuery could be nil if the search request is not coming from API Gw and authz is not required
		query = query.Must(aQuery)
	}

	// Top-hits Aggregation #4
	topAgg := es.NewTopHitsAggregation().From(int(in.From)).Size(int(in.MaxResults))

	// Add sort option if it is valid
	sortAscending := false
	if in.SortOrder == search.SearchRequest_Ascending.String() {
		sortAscending = true
	}
	if len(in.SortBy) != 0 {
		sortInfo := es.SortInfo{
			Field:     in.SortBy,
			Ascending: sortAscending,
			Missing:   "_last",
			// UnmappedType prevents search failing when an index
			// doesn't have a mapping for the field.
			UnmappedType: "keyword",
		}
		topAgg = topAgg.SortWithInfo(sortInfo)
	}

	// Kind-Aggregation #3
	aggKind := es.NewTermsAggregation().Field("kind.keyword")

	// Add Top-aggregations to Kind-Aggregation
	aggKind = aggKind.SubAggregation(elastic.TopHitsKey, topAgg)

	// Category-Aggregation #2
	aggCategory := es.NewTermsAggregation().Field("meta.labels._category.keyword")

	// Add Kind-Aggregation to Category-Aggregation
	aggCategory = aggCategory.SubAggregation(elastic.KindAggKey, aggKind)

	// Tenant-Aggregation #1
	aggTenant := es.NewTermsAggregation().Field("meta.tenant.keyword")

	// Add Category-Aggregation to Tenant-Aggregation
	aggTenant = aggTenant.SubAggregation(elastic.CategoryAggKey, aggCategory)

	// Execute Search with required index, query etc

	result, err := fdr.elasticClient.Search(ctx,
		fmt.Sprintf("%s.*", elastic.ExternalIndexPrefix),
		"", //  Skip the index/doc type for search
		query,
		aggTenant,
		in.From,
		in.MaxResults,
		in.SortBy,
		sortAscending)
	if err != nil {
		fdr.logger.Errorf("Search failed for query: %v, result: %+v err: %v", query, result, err)
		var eType, eReason string
		if result != nil && result.Error != nil {
			eType = result.Error.Type
			eReason = result.Error.Reason
		} else {
			eType = err.Error()
		}
		sr.Error = &search.Error{
			Type:   eType,
			Reason: eReason,
		}
		return &sr, err
	}

	// Elastic Aggregations JSON structure
	//
	//   "aggregations": { <-- AggregationSingleBucket
	//     "tenant_agg": { <—- AggregationBucketKeyItems  (Tenant Aggregation)
	//       "doc_count_error_upper_bound": 0,
	//       "sum_other_doc_count": 0,
	//       "buckets": [  <—- AggregationBucketKeyItem
	//         {
	//           "key": "tesla",
	//           "doc_count": 3,
	//           "category_agg": { <—- AggregationBucketKeyItems (Category Aggregation)
	//             "doc_count_error_upper_bound": 0,
	//             "sum_other_doc_count": 0,
	//             "buckets": [ <—- AggregationBucketKeyItem
	//               {
	//                 "key": "Security",
	//                 "doc_count": 3,
	//                 "kind_agg": { <—- AggregationBucketKeyItems (Kind Aggregation)
	//                   "doc_count_error_upper_bound": 0,
	//                   "sum_other_doc_count": 0,
	//                   "buckets": [ <—- AggregationBucketKeyItem
	//                     {
	//                       "key": "SecurityGroup",
	//                       "doc_count": 3,
	//                       "top_agg": { <-AggregationTopHitsMetric (Tophits aggregation)
	//                         "hits": { <- SearchHits
	//                           "total": 3,
	//                           "max_score": 0.2876821,
	//                           "hits": [ <- SearchHit
	//                             {
	//                               "_index": "venice.external.default.configs.security",
	//                               "_type": "Security",
	//                               "_id": "c2856295-4c81-40e1-8061-4a6ea6ac0f37",
	//                               "_score": 0.2876821,
	//                               "_source": { <-- Venice Object
	//                                 "kind": "SecurityGroup",
	//                                 "api-version": "v1",
	//                                 "meta": {
	//                                   "name": "sg02",
	//                                   "tenant": "tesla",
	//                                   "namespace": "staging",
	//                                   "resource-version": "12",
	//                                   "uuid": "c2856295-4c81-40e1-8061-4a6ea6ac0f37",
	//                                   "labels": {
	//                                     "Application": "SAP-HANA",
	//                                     "Location": "us-west-zone2"
	//                                   },
	//                                   "creation-time": "2018-04-24T22:26:06.677102059Z",
	//                                   "mod-time": "2018-04-24T22:26:06.6771034Z",
	//                                   "self-link": "/venice/security-groups/security-groups/tesla/sg02"
	//                                 },
	//                                 "spec": {
	//                                   "workload-selector": {
	//                                     "requirements": [
	//                                       {
	//                                         "key": "app",
	//                                         "operator": "equals",
	//                                         "values": [
	//                                           "procurement"
	//                                         ]
	//                                       },
	//                                       {
	//                                         "key": "env",
	//                                         "operator": "equals",
	//                                         "values": [
	//                                           "production"
	//                                         ]
	//                                       }
	//                                     ]
	//                                   }
	//                                 },
	//                                 "status": {}
	//                               }
	//                             },
	//                             {
	//                               "_index": "venice.external.default.configs.security",
	//                               "_type": "Security",
	//                               "_id": "0b4f98dc-127b-43c1-94af-506d7c6aacf2",
	//                               "_score": 0.18232156,
	//                               "_source": {  <-- Venice Object
	//                                 "kind": "SecurityGroup",
	//                                 "api-version": "v1",
	//                                 "meta": {
	//                                   "name": "sg00",
	//                                   "tenant": "tesla",
	//                                   "namespace": "staging",
	//                                   "resource-version": "6",
	//                                   "uuid": "0b4f98dc-127b-43c1-94af-506d7c6aacf2",
	//                                   "labels": {
	//                                     "Application": "SAP-HANA",
	//                                     "Location": "us-west-zone2"
	//                                   },
	//                                   "creation-time": "2018-04-24T22:26:06.607595144Z",
	//                                   "mod-time": "2018-04-24T22:26:06.607596286Z",
	//                                   "self-link": "/venice/security-groups/security-groups/tesla/sg00"
	//                                 },
	//                                 "spec": {
	//                                   "workload-selector": {
	//                                     "requirements": [
	//                                       {
	//                                         "key": "app",
	//                                         "operator": "equals",
	//                                         "values": [
	//                                           "procurement"
	//                                         ]
	//                                       },
	//                                       {
	//                                         "key": "env",
	//                                         "operator": "equals",
	//                                         "values": [
	//                                           "production"
	//                                         ]
	//                                       }
	//                                     ]
	//                                   }
	//                                 },
	//                                 "status": {}
	//                               }
	//                             },
	//                             {
	//                               "_index": "venice.external.default.configs.security",
	//                               "_type": "Security",
	//                               "_id": "b658a5ff-8220-4fa4-a380-77f61e4c2f23",
	//                               "_score": 0.18232156,
	//                               "_source": {
	//                                 "kind": "SecurityGroup",
	//                                 "api-version": "v1",
	//                                 "meta": {
	//                                   "name": "sg04",
	//                                   "tenant": "tesla",
	//                                   "namespace": "staging",
	//                                   "resource-version": "18",
	//                                   "uuid": "b658a5ff-8220-4fa4-a380-77f61e4c2f23",
	//                                   "labels": {
	//                                     "Application": "SAP-HANA",
	//                                     "Location": "us-west-zone2"
	//                                   },
	//                                   "creation-time": "2018-04-24T22:26:06.747949636Z",
	//                                   "mod-time": "2018-04-24T22:26:06.747950841Z",
	//                                   "self-link": "/venice/security-groups/security-groups/tesla/sg04"
	//                                 },
	//                                 "spec": {
	//                                   "workload-selector": {
	//                                     "requirements": [
	//                                       {
	//                                         "key": "app",
	//                                         "operator": "equals",
	//                                         "values": [
	//                                           "procurement"
	//                                         ]
	//                                       },
	//                                       {
	//                                         "key": "env",
	//                                         "operator": "equals",
	//                                         "values": [
	//                                           "production"
	//                                         ]
	//                                       }
	//                                     ]
	//                                   }
	//                                 },
	//                                 "status": {}
	//                               }
	//                             }
	//                           ]
	//                         }
	//                       }
	//                     }
	//                   ]
	//                 }
	//               }
	//             ]
	//           }
	//         }
	//       ]
	//     }
	//   }

	// Marshall the elasticDB response and populate the SearchResult
	var resp search.SearchResponse
	resp.TotalHits = result.Hits.TotalHits
	resp.ActualHits = int64(len(result.Hits.Hits))
	resp.TimeTakenMsecs = result.TookInMillis

	// Decode the Hits when the request mode is "full"
	if in.Mode == search.SearchRequest_Full.String() {
		resp.Entries = make([]*search.Entry, len(result.Hits.Hits))

		for i, entry := range result.Hits.Hits {
			fdr.logger.Debugf("SearchHit - entry: %d {%+v}", i, entry)
			jsondata, err := entry.Source.MarshalJSON()
			if err == nil {

				var entry *search.ConfigEntry
				var robj runtime.Object
				databytes := []byte(jsondata)

				fdr.logger.Debugf("Search hits result - raw string: %d [ %s ]", i, string(databytes))
				err = json.Unmarshal([]byte(databytes), &entry)
				if err != nil {
					fdr.logger.Errorf("Error unmarshalling json data to search result event entry : %+v", err)
					continue
				}
				fdr.logger.Debugf("Search hits result - entry: %d {%+v}", i, entry)

				switch entry.Kind {
				case "Event":
					eObj := &evtsapi.Event{}
					err = json.Unmarshal([]byte(databytes), eObj)
					if err != nil {
						fdr.logger.Errorf("Error unmarshalling json data to search result event entry : %+v", err)
						continue
					}
					delete(eObj.ObjectMeta.Labels, globals.CategoryLabel)
					fdr.logger.Debugf("Search hits result - event entry: %d {%+v}", i, eObj)
					robj = eObj
					obj, err := types.MarshalAny(robj.(proto.Message))
					if err != nil {
						fdr.logger.Errorf("Unable to unmarshall event object {%+v} (%v) ", obj, err)
						continue
					}
					resp.Entries[i] = &search.Entry{
						Object: &api.Any{
							Any: *obj,
						},
					}

				case "Alert":
					aObj := &monapi.Alert{}
					err = json.Unmarshal([]byte(databytes), &aObj)
					if err != nil {
						fdr.logger.Errorf("Error unmarshalling json data to search result alert entry : %+v", err)
						continue
					}
					delete(aObj.ObjectMeta.Labels, globals.CategoryLabel)
					fdr.logger.Debugf("Search hits result - alert entry: %d {%+v}", i, aObj)
					robj = aObj
					obj, err := types.MarshalAny(robj.(proto.Message))
					if err != nil {
						fdr.logger.Errorf("Unable to unmarshall alert object {%+v} (%v) ", obj, err)
						continue
					}
					resp.Entries[i] = &search.Entry{
						Object: &api.Any{
							Any: *obj,
						},
					}
				case "AuditEvent":
					eObj := &audit.Event{}
					err = json.Unmarshal([]byte(databytes), eObj)
					if err != nil {
						fdr.logger.Errorf("Error un-marshalling json data to search result audit event entry : %+v", err)
						continue
					}
					delete(eObj.ObjectMeta.Labels, globals.CategoryLabel)
					// removing response and request to make audit event small
					eObj.ResponseObject = ""
					eObj.RequestObject = ""
					fdr.logger.Debugf("Search hits result - audit event entry: %d {%+v}", i, eObj)
					robj = eObj
					obj, err := types.MarshalAny(robj.(proto.Message))
					if err != nil {
						fdr.logger.Errorf("Unable to unmarshal audit event object {%+v} (%v) ", obj, err)
						continue
					}
					resp.Entries[i] = &search.Entry{
						Object: &api.Any{
							Any: *obj,
						},
					}
				default:
					cObj := &search.ConfigEntry{}
					err = json.Unmarshal([]byte(databytes), &cObj)
					if err != nil {
						fdr.logger.Errorf("Error unmarshalling json data to search result config entry : %+v", err)
						continue
					}
					delete(cObj.ObjectMeta.Labels, globals.CategoryLabel)
					fdr.logger.Debugf("Search hits result - config entry: %d {%+v}", i, cObj)
					robj = cObj
					obj, err := types.MarshalAny(robj.(proto.Message))
					if err != nil {
						fdr.logger.Errorf("Unable to unmarshall config object {%+v} (%v) ", obj, err)
						continue
					}
					resp.Entries[i] = &search.Entry{
						Object: &api.Any{
							Any: *obj,
						},
					}
				}
			} else {
				resp.Entries[i] = nil
				fdr.logger.Errorf("Failed to marshal hits result-Source i:%d err:%v", i, err)
				// TBD: Stop here with error or continue with best effort ?
			}
		}
	}

	// Deserialize Tenant aggregations
	if tenantAgg, found := result.Aggregations.Terms(elastic.TenantAggKey); found {

		if in.Mode == search.SearchRequest_Full.String() {
			resp.AggregatedEntries = &search.TenantAggregation{
				Tenants: make(map[string]*search.CategoryAggregation, len(result.Aggregations)),
			}
		}

		if in.Mode == search.SearchRequest_Preview.String() {
			resp.PreviewEntries = &search.TenantPreview{
				Tenants: make(map[string]*search.CategoryPreview, len(result.Aggregations)),
			}
		}

		for _, tenantBucket := range tenantAgg.Buckets {

			// Deserialize Category aggregations
			if categoryAgg, found := tenantBucket.Terms(elastic.CategoryAggKey); found {

				if in.Mode == search.SearchRequest_Full.String() {
					resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)] = &search.CategoryAggregation{
						Categories: make(map[string]*search.KindAggregation, len(categoryAgg.Buckets)),
					}
				}

				if in.Mode == search.SearchRequest_Preview.String() {
					resp.PreviewEntries.Tenants[tenantBucket.Key.(string)] = &search.CategoryPreview{
						Categories: make(map[string]*search.KindPreview, len(categoryAgg.Buckets)),
					}
				}

				for _, categoryBucket := range categoryAgg.Buckets {

					// Deserialize Kind aggregations
					if kindAgg, found := categoryBucket.Terms(elastic.KindAggKey); found {

						if in.Mode == search.SearchRequest_Full.String() {
							resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)] = &search.KindAggregation{
								Kinds: make(map[string]*search.EntryList, len(kindAgg.Buckets)),
							}
						}

						if in.Mode == search.SearchRequest_Preview.String() {
							resp.PreviewEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)] = &search.KindPreview{
								Kinds: make(map[string]int64, len(kindAgg.Buckets)),
							}
						}

						for _, kindBucket := range kindAgg.Buckets {

							kind := kindBucket.Key.(string)
							// Deserialize Top hits aggregations
							if topHits, ok := kindBucket.TopHits(string(elastic.TopHitsKey)); ok {

								hits := topHits.Hits.Hits
								if in.Mode == search.SearchRequest_Full.String() {
									resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)].Kinds[kindBucket.Key.(string)] = &search.EntryList{
										Entries: make([]*search.Entry, len(hits)),
									}

									for i, entry := range hits {

										jsondata, err := entry.Source.MarshalJSON()
										if err == nil {

											var robj runtime.Object
											databytes := []byte(jsondata)
											fdr.logger.Debugf("Agg Search hits result - raw string: %d [ %s ]", i, string(databytes))
											switch kind {
											case "Event":
												eObj := &evtsapi.Event{}
												err = json.Unmarshal([]byte(databytes), eObj)
												if err != nil {
													fdr.logger.Errorf("Error unmarshalling json data to search result event entry : %+v", err)
													continue
												}
												delete(eObj.ObjectMeta.Labels, globals.CategoryLabel)
												fdr.logger.Debugf("Search hits result - event entry: %d {%+v}", i, eObj)
												robj = eObj
												obj, err := types.MarshalAny(robj.(proto.Message))
												if err != nil {
													fdr.logger.Errorf("Unable to unmarshall event object {%+v} (%v) ", obj, err)
													continue
												}
												resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)].Kinds[kindBucket.Key.(string)].Entries[i] = &search.Entry{
													Object: &api.Any{
														Any: *obj,
													},
												}

											case "Alert":
												aObj := &monapi.Alert{}
												err = json.Unmarshal([]byte(databytes), &aObj)
												if err != nil {
													fdr.logger.Errorf("Error unmarshalling json data to search result alert entry : %+v", err)
													continue
												}
												delete(aObj.ObjectMeta.Labels, globals.CategoryLabel)
												fdr.logger.Debugf("Search hits result - alert entry: %d {%+v}", i, aObj)
												robj = aObj
												obj, err := types.MarshalAny(robj.(proto.Message))
												if err != nil {
													fdr.logger.Errorf("Unable to unmarshall alert object {%+v} (%v) ", obj, err)
													continue
												}
												resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)].Kinds[kindBucket.Key.(string)].Entries[i] = &search.Entry{
													Object: &api.Any{
														Any: *obj,
													},
												}

											case "AuditEvent":
												eObj := &audit.Event{}
												err = json.Unmarshal([]byte(databytes), eObj)
												if err != nil {
													fdr.logger.Errorf("Error un-marshalling json data to search result audit event entry : %+v", err)
													continue
												}
												delete(eObj.ObjectMeta.Labels, globals.CategoryLabel)
												// removing response and request to make audit event small
												eObj.ResponseObject = ""
												eObj.RequestObject = ""
												fdr.logger.Debugf("Search hits result - audit event entry: %d {%+v}", i, eObj)
												robj = eObj
												obj, err := types.MarshalAny(robj.(proto.Message))
												if err != nil {
													fdr.logger.Errorf("Unable to unmarshal audit event object {%+v} (%v) ", obj, err)
													continue
												}
												resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)].Kinds[kindBucket.Key.(string)].Entries[i] = &search.Entry{
													Object: &api.Any{
														Any: *obj,
													},
												}

											default:
												cObj := &search.ConfigEntry{}
												err = json.Unmarshal([]byte(databytes), &cObj)
												if err != nil {
													fdr.logger.Errorf("Error unmarshalling json data to search result config entry : %+v", err)
													continue
												}
												delete(cObj.ObjectMeta.Labels, globals.CategoryLabel)
												fdr.logger.Debugf("Search hits result - config entry: %d {%+v}", i, cObj)
												robj = cObj
												obj, err := types.MarshalAny(robj.(proto.Message))
												if err != nil {
													fdr.logger.Errorf("Unable to unmarshall config object {%+v} (%v) ", obj, err)
													continue
												}
												resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)].Kinds[kindBucket.Key.(string)].Entries[i] = &search.Entry{
													Object: &api.Any{
														Any: *obj,
													},
												}
											}
										} else {
											resp.AggregatedEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)].Kinds[kindBucket.Key.(string)].Entries[i] = nil
											fdr.logger.Errorf("Failed to marshal Agg hits result-Source i:%d err:%v", i, err)
											// TBD: Stop here with error or continue with best effort ?
										}
									}
								}

								if in.Mode == search.SearchRequest_Preview.String() {
									resp.PreviewEntries.Tenants[tenantBucket.Key.(string)].Categories[categoryBucket.Key.(string)].Kinds[kindBucket.Key.(string)] = int64(len(hits))
								}

							}
						}
					}
				}
			}
		}
	}

	fdr.logger.Infof("Search response: {%+v}", resp)
	return &resp, nil
}

// authzQuery returns query to limit search by authorized kinds for tenants specified in search request. It returns nil query
// if request is not coming from API Gw.
func (fdr *Finder) authzQuery(ctx context.Context, tenants []string) (es.Query, error) {
	// add authorization only if request is coming from API GW
	if ctxutils.GetPeerID(ctx) != globals.APIGw {
		fdr.logger.Infof("not constraining search query with authz info")
		return nil, nil
	}
	userMeta, ok := authzgrpcctx.UserMetaFromIncomingContext(ctx)
	if !ok {
		fdr.logger.Errorf("no user in grpc metadata")
		return nil, errors.New("no user in context")
	}
	user := &auth.User{ObjectMeta: *userMeta}
	// constrain search by authorized kinds
	authorizer, err := authzgrpc.NewAuthorizer(ctx)
	if err != nil {
		fdr.logger.Errorf("error creating grpc authorizer for search: %v", err)
		return nil, err
	}
	var authorizedTenantsFound, authorizedClusterKindsFound bool
	query := es.NewBoolQuery().QueryName("AllowedKindsForTenants")
	for _, tenant := range tenants {
		allowedTenantScopedOps := authorizer.AuthorizedOperations(user, tenant, authz.ResourceNamespaceAll, auth.Permission_Read)
		if len(allowedTenantScopedOps) > 0 {
			var allowedTenantScopedKinds []string
			kquery := es.NewBoolQuery().QueryName("AllowedKindsForTenant")
			kquery = kquery.Must(es.NewMatchPhraseQuery("meta.tenant", tenant))
			kindReq := es.NewBoolQuery().QueryName("AllowedKinds")
			for _, op := range allowedTenantScopedOps {
				kindReq = kindReq.Should(es.NewTermQuery("kind.keyword", op.GetResource().GetKind())).MinimumNumberShouldMatch(1)
				allowedTenantScopedKinds = append(allowedTenantScopedKinds, op.GetResource().GetKind())
			}
			kquery = kquery.Must(kindReq)
			query = query.Should(kquery).MinimumNumberShouldMatch(1)
			authorizedTenantsFound = true
			fdr.logger.Infof("user [%s|%s] allowed to search kinds [%#v] in tenant [%s]", user.Tenant, user.Name, allowedTenantScopedKinds, tenant)
		}
	}
	allowedClusterScopedOps := authorizer.AuthorizedOperations(user, "", "", auth.Permission_Read)
	kindReq := es.NewBoolQuery().QueryName("AllowedClusterKinds")
	var allowedClusterScopedKinds []string
	for _, op := range allowedClusterScopedOps {
		kindReq = kindReq.Should(es.NewTermQuery("kind.keyword", op.GetResource().GetKind())).MinimumNumberShouldMatch(1)
		allowedClusterScopedKinds = append(allowedClusterScopedKinds, op.GetResource().GetKind())
		authorizedClusterKindsFound = true
	}
	if authorizedClusterKindsFound {
		query = query.Should(kindReq).MinimumNumberShouldMatch(1)
		fdr.logger.Infof("user [%s|%s] allowed to search cluster kinds [%#v]", user.Tenant, user.Name, allowedClusterScopedKinds)
	}
	if !authorizedTenantsFound && !authorizedClusterKindsFound {
		fdr.logger.Errorf("user [%s|%s] unauthorized to search any kind", user.Tenant, user.Name)
		return nil, grpcstatus.Error(grpccode.PermissionDenied, "unauthorized to search any objects")
	}
	return query, nil
}

// Start the RPC-server for the Query backend handling
func (fdr *Finder) startRPCServer(serverName, listenURL string) error {

	// Valids args
	if venutils.IsEmpty(serverName) || venutils.IsEmpty(listenURL) {
		return errors.New("all parameters are required")
	}

	// Create an RPC server
	rpcServer, err := rpckit.NewRPCServer(serverName, listenURL)
	if err != nil {
		return errors.Wrap(err, "Error creating rpc server")
	}

	// Register the RPC handlers and start the rpc server
	search.RegisterSearchV1Server(rpcServer.GrpcServer, fdr)

	// Register events handler
	evtsapi.RegisterEventsV1Server(rpcServer.GrpcServer, fdr)

	// Register audit handler
	audit.RegisterAuditV1Server(rpcServer.GrpcServer, newAuditHandler(fdr))

	// Register diagnostics handler
	if fdr.diagSvc == nil {
		fdr.diagSvc = diagsvc.GetDiagnosticsServiceWithDefaults(globals.Spyglass, utils.GetHostname(), diagapi.ModuleStatus_Venice, fdr.rsr, fdr.logger)
	}
	diagnostics.RegisterService(rpcServer.GrpcServer, fdr.diagSvc)

	rpcServer.Start()
	fdr.rpcServer = rpcServer
	fdr.logger.Infof("Started finder rpcserver at: %s", fdr.rpcServer.GetListenURL())
	return nil
}

// Stop the RPC-server
func (fdr *Finder) stopRPCServer() error {

	// stop the rpc server
	return fdr.rpcServer.Stop()
}

func (fdr *Finder) moduleChangeCb(diagmod *diagapi.Module) {
	fdr.logger.ResetFilter(diagnostics.GetLogFilter(diagmod.Spec.LogLevel))
	fdr.logger.InfoLog("method", "moduleChangeCb", "msg", "setting log level", "moduleLogLevel", diagmod.Spec.LogLevel)
}

// GetListenURL returns the listen URL for the server
func (fdr *Finder) GetListenURL() string {
	return fdr.rpcServer.GetListenURL()
}

// PolicyQuery is the handler for security policy search query
func (fdr *Finder) PolicyQuery(ctx context.Context, in *search.PolicySearchRequest) (*search.PolicySearchResponse, error) {

	fdr.logger.Infof("Policy Search request: {%+v}", *in)
	resp, err := fdr.cache.SearchPolicy(in)
	fdr.logger.Infof("Policy Search response: {%+v} err: %v", *resp, err)
	return resp, err
}

// ConfigEntry alias to make it compatible with runtime.Object
type ConfigEntry search.ConfigEntry

// Clone clones the object into into or creates one of into is nil
func (m *ConfigEntry) Clone(into interface{}) (interface{}, error) {
	var out *ConfigEntry
	var ok bool
	if into == nil {
		out = &ConfigEntry{}
	} else {
		out, ok = into.(*ConfigEntry)
		if !ok {
			return nil, fmt.Errorf("mismatched object types")
		}
	}
	*out = *m
	return out, nil
}
