package objects

import (
	"bytes"
	"context"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"

	"github.com/pensando/sw/api/generated/workload"
	iota "github.com/pensando/sw/iota/protos/gogen"
	"github.com/pensando/sw/iota/test/venice/iotakit/cfg/objClient"
	"github.com/pensando/sw/iota/test/venice/iotakit/testbed"
	"github.com/pensando/sw/venice/utils/log"
)

// Workload represents a VM/container/Baremetal workload (endpoints are associated with the workload)
type Workload struct {
	iotaWorkload       *iota.Workload
	VeniceWorkload     *workload.Workload
	host               *Host
	subnet             *Network
	IsFTPServerRunning bool // is FTP server running already on this workload
}

// WorkloadCollection is the collection of Workloads
type WorkloadCollection struct {
	CollectionCommon
	Workloads []*Workload
}

// WorkloadsMove is a pair of Workloads
type WorkloadsMove struct {
	Workload []*Workload
	Dst      *Host
}

// WorkloadsMoveCollection spec
type WorkloadsMoveCollection struct {
	CollectionCommon
	Moves []*WorkloadsMove
}

func (w *Workload) Name() string {
	return w.iotaWorkload.WorkloadName
}

func (w *Workload) NaplesUUID() string {
	return w.host.Naples.SmartNic.Name
}

func (w *Workload) NodeName() string {
	return w.iotaWorkload.NodeName
}

func (w *Workload) SetNodeName(nodeName string) {
	w.iotaWorkload.NodeName = nodeName
}

func (w *Workload) SetMgmtIP(ip string) {
	w.iotaWorkload.MgmtIp = ip
}

func (w *Workload) GetMgmtIP() string {
	return w.iotaWorkload.MgmtIp
}

func (w *Workload) GetIP() string {
	return strings.Split(w.iotaWorkload.IpPrefix, "/")[0]
}

func (w *Workload) GetIotaWorkload() *iota.Workload {
	return w.iotaWorkload
}

func (w *Workload) SetInterface(intf string) {
	w.iotaWorkload.Interface = intf
}

func (w *Workload) SetIotaWorkload(wl *iota.Workload) {
	w.iotaWorkload = wl
}

//Used after workload move
func (w *Workload) SetIotaNodeName(name string) {
	w.iotaWorkload.NodeName = name
}

func (w *Workload) GetInterface() string {
	return w.iotaWorkload.Interface
}

func NewWorkload(host *Host, w *workload.Workload, wtype iota.WorkloadType, wimage string) *Workload {

	convertMac := func(s string) string {
		mac := strings.Replace(s, ".", "", -1)
		var buffer bytes.Buffer
		var l1 = len(mac) - 1
		for i, rune := range mac {
			buffer.WriteRune(rune)
			if i%2 == 1 && i != l1 {
				buffer.WriteRune(':')
			}
		}
		return buffer.String()
	}

	// create iota workload object
	iotaWorkload := iota.Workload{
		WorkloadType:    wtype,
		WorkloadName:    w.GetName(),
		NodeName:        host.iotaNode.Name,
		WorkloadImage:   wimage,
		EncapVlan:       w.Spec.Interfaces[0].MicroSegVlan,
		IpPrefix:        w.Spec.Interfaces[0].IpAddresses[0] + "/24", //Assuming it is /24 for now
		MacAddress:      convertMac(w.Spec.Interfaces[0].MACAddress),
		Interface:       "lif100", // ugly hack here: iota agent creates interfaces like lif100. matching that behavior
		ParentInterface: "lif100", // ugly hack here: iota agent creates interfaces like lif100. matching that behavior
		InterfaceType:   iota.InterfaceType_INTERFACE_TYPE_VSS,
		PinnedPort:      1, // another hack: always pinning to first uplink
		UplinkVlan:      w.Spec.Interfaces[0].ExternalVlan,
	}

	return &Workload{
		iotaWorkload:   &iotaWorkload,
		VeniceWorkload: w,
		host:           host,
		//	subnet:         subnet,
	}
}

func NewWorkloadCollection(client objClient.ObjClient, testbed *testbed.TestBed) *WorkloadCollection {
	return &WorkloadCollection{
		CollectionCommon: CollectionCommon{Client: client,
			Testbed: testbed},
	}
}

func NewWorkloadPairCollection(client objClient.ObjClient, testbed *testbed.TestBed) *WorkloadPairCollection {
	return &WorkloadPairCollection{
		CollectionCommon: CollectionCommon{Client: client,
			Testbed: testbed},
	}
}

// WorkloadPair is a pair of Workloads
type WorkloadPair struct {
	First  *Workload
	Second *Workload
	Proto  string
	Ports  []int
}

// WorkloadPairCollection is collection of workload pairs
type WorkloadPairCollection struct {
	CollectionCommon
	Pairs []*WorkloadPair
}

// GetSingleWorkloadPair gets a single pair collection based on index
func (wlpc *WorkloadPairCollection) GetSingleWorkloadPair(i int) *WorkloadPairCollection {
	collection := WorkloadPairCollection{}
	collection.Pairs = append(collection.Pairs, wlpc.Pairs[i])
	return &collection
}

// ListIPAddr lists work load ip address
func (wpc *WorkloadPairCollection) ListIPAddr() [][]string {
	workloadNames := [][]string{}

	for _, pair := range wpc.Pairs {
		workloadNames = append(workloadNames, []string{pair.First.GetIP(), pair.Second.GetIP()})
	}

	return workloadNames
}

// WithinNetwork filters workload pairs to only withon subnet
func (wpc *WorkloadPairCollection) WithinNetwork() *WorkloadPairCollection {
	if wpc.HasError() {
		return wpc
	}
	newCollection := WorkloadPairCollection{}

	for _, pair := range wpc.Pairs {
		if pair.First.iotaWorkload.UplinkVlan == pair.Second.iotaWorkload.UplinkVlan {
			newCollection.Pairs = append(newCollection.Pairs, pair)
		}
	}

	return &newCollection
}
func (wpc *WorkloadPairCollection) policyHelper(policyCollection *NetworkSecurityPolicyCollection, action, proto string) *WorkloadPairCollection {
	if wpc.err != nil {
		return wpc
	}
	newCollection := WorkloadPairCollection{}
	type ipPair struct {
		sip   string
		dip   string
		proto string
		ports string
	}
	actionCache := make(map[string][]ipPair)

	ipPairPresent := func(pair ipPair) bool {
		for _, pairs := range actionCache {
			for _, ippair := range pairs {
				if ippair.dip == pair.dip && ippair.sip == pair.sip && ippair.proto == pair.proto {
					return true
				}
			}
		}
		return false
	}
	for _, pol := range policyCollection.Policies {
		for _, rule := range pol.VenicePolicy.Spec.Rules {
			for _, sip := range rule.FromIPAddresses {
				for _, dip := range rule.ToIPAddresses {
					for _, proto := range rule.ProtoPorts {
						pair := ipPair{sip: sip, dip: dip, proto: proto.Protocol, ports: proto.Ports}
						if _, ok := actionCache[rule.Action]; !ok {
							actionCache[rule.Action] = []ipPair{}
						}
						//if this IP pair was already added, then don't pick it as precedence is based on order
						if !ipPairPresent(pair) {
							//Copy ports
							actionCache[rule.Action] = append(actionCache[rule.Action], pair)
						}
					}
				}
			}
		}
	}

	getPortsFromRange := func(ports string) []int {
		if ports == "any" {
			//Random port if any
			return []int{5555}
		}
		values := strings.Split(ports, "-")
		start, _ := strconv.Atoi(values[0])
		if len(values) == 1 {
			return []int{start}
		}
		end, _ := strconv.Atoi(values[1])
		portValues := []int{}
		for i := start; i <= end; i++ {
			portValues = append(portValues, i)
		}
		return portValues
	}
	for _, pair := range wpc.Pairs {
		cache, ok := actionCache[action]
		if ok {
			for _, ippair := range cache {
				if ((ippair.dip == "any") || ippair.dip == strings.Split(pair.First.iotaWorkload.GetIpPrefix(), "/")[0]) &&
					((ippair.sip == "any") || ippair.sip == strings.Split(pair.Second.iotaWorkload.GetIpPrefix(), "/")[0]) &&
					ippair.proto == proto &&
					pair.First.iotaWorkload.UplinkVlan == pair.Second.iotaWorkload.UplinkVlan {
					pair.Ports = getPortsFromRange(ippair.ports)
					pair.Proto = ippair.proto
					newCollection.Pairs = append(newCollection.Pairs, pair)
				}
			}
		}
	}

	return &newCollection
}

// Permit get allowed Workloads with proto
func (wpc *WorkloadPairCollection) Permit(policyCollection *NetworkSecurityPolicyCollection, proto string) *WorkloadPairCollection {
	return wpc.policyHelper(policyCollection, "PERMIT", proto)
}

// Deny get Denied Workloads with proto
func (wpc *WorkloadPairCollection) Deny(policyCollection *NetworkSecurityPolicyCollection, proto string) *WorkloadPairCollection {
	return wpc.policyHelper(policyCollection, "DENY", proto)
}

// Reject get rejected Workloads with proto
func (wpc *WorkloadPairCollection) Reject(policyCollection *NetworkSecurityPolicyCollection, proto string) *WorkloadPairCollection {
	return wpc.policyHelper(policyCollection, "REJECT", proto)
}

// ExcludeWorkloads excludes some Workloads from collection
func (wpc *WorkloadPairCollection) ExcludeWorkloads(wc *WorkloadCollection) *WorkloadPairCollection {
	if wpc.err != nil {
		return wpc
	}
	newCollection := WorkloadPairCollection{}

	for _, pair := range wpc.Pairs {
		for _, w := range wc.Workloads {
			if pair.First.iotaWorkload.WorkloadName != w.iotaWorkload.WorkloadName &&
				pair.Second.iotaWorkload.WorkloadName != w.iotaWorkload.WorkloadName {
				newCollection.Pairs = append(newCollection.Pairs, pair)
			}
		}
	}

	return &newCollection
}

// Any returna one pair from the collection in random
func (wpc *WorkloadPairCollection) Any(num int) *WorkloadPairCollection {
	if wpc.err != nil || len(wpc.Pairs) <= num {
		return wpc
	}
	newWpc := WorkloadPairCollection{Pairs: []*WorkloadPair{}}
	tmpArry := make([]*WorkloadPair, len(wpc.Pairs))
	copy(tmpArry, wpc.Pairs)
	for i := 0; i < num; i++ {
		idx := rand.Intn(len(tmpArry))
		wpair := tmpArry[idx]
		tmpArry = append(tmpArry[:idx], tmpArry[idx+1:]...)
		newWpc.Pairs = append(newWpc.Pairs, wpair)
	}

	return &newWpc
}

// ReversePairs reverses the pairs by swapping first and second entries
func (wpc *WorkloadPairCollection) ReversePairs() *WorkloadPairCollection {
	if wpc.err != nil || len(wpc.Pairs) < 1 {
		return wpc
	}
	newWpc := WorkloadPairCollection{Pairs: []*WorkloadPair{}}
	for _, pair := range wpc.Pairs {
		newPair := WorkloadPair{
			First:  pair.Second,
			Second: pair.First,
		}
		newWpc.Pairs = append(newWpc.Pairs, &newPair)
	}

	return &newWpc
}

// Bringup brings up all Workloads in the collection
func (wc *WorkloadCollection) Bringup(tb *testbed.TestBed) error {
	var Workloads []*iota.Workload

	// if there are no Workloads, nothing to do
	if len(wc.Workloads) == 0 {
		return nil
	}

	// build workload list
	for _, wrk := range wc.Workloads {
		Workloads = append(Workloads, wrk.iotaWorkload)
	}

	// send workload add message
	wrkLd := &iota.WorkloadMsg{
		ApiResponse: &iota.IotaAPIResponse{},
		WorkloadOp:  iota.Op_ADD,
		Workloads:   Workloads,
	}
	topoClient := iota.NewTopologyApiClient(tb.Client().Client)
	appResp, err := topoClient.AddWorkloads(context.Background(), wrkLd)
	log.Debugf("Got add workload resp: %+v, err: %v", appResp, err)
	if err != nil {
		log.Errorf("Failed to instantiate Apps. Err: %v", err)
		return fmt.Errorf("Error creating IOTA workload. err: %v", err)
	} else if appResp.ApiResponse.ApiStatus != iota.APIResponseType_API_STATUS_OK {
		log.Errorf("Failed to instantiate Apps. resp: %+v.", appResp.ApiResponse)
		return fmt.Errorf("Error creating IOTA workload. Resp: %+v", appResp.ApiResponse)
	}
	for _, wrk := range wc.Workloads {
		for _, gwrk := range appResp.Workloads {
			if gwrk.WorkloadName == wrk.iotaWorkload.WorkloadName {
				wrk.iotaWorkload.MgmtIp = gwrk.MgmtIp
				wrk.iotaWorkload.Interface = gwrk.GetInterface()
			}
		}
	}

	// copy over some binaries after Workloads are brought up
	fuzBinPath := os.Getenv("GOPATH") + "/src/github.com/pensando/sw/iota/bin/fuz"
	for _, wrk := range wc.Workloads {
		if err := tb.CopyToWorkload(wrk.iotaWorkload.NodeName, wrk.iotaWorkload.WorkloadName, []string{fuzBinPath}, "."); err != nil {
			log.Errorf("error copying fuz binary to workload: %s", err)
		}
	}

	return nil
}

// Any returna one pair from the collection in random
func (wpc *WorkloadCollection) Any(num int) *WorkloadCollection {
	if wpc.err != nil || len(wpc.Workloads) <= num {
		return wpc
	}
	newWpc := WorkloadCollection{CollectionCommon: wpc.CollectionCommon}
	tmpArry := make([]*Workload, len(wpc.Workloads))
	copy(tmpArry, wpc.Workloads)
	for i := 0; i < num; i++ {
		idx := rand.Intn(len(tmpArry))
		wpair := tmpArry[idx]
		tmpArry = append(tmpArry[:idx], tmpArry[idx+1:]...)
		newWpc.Workloads = append(newWpc.Workloads, wpair)
	}

	return &newWpc
}

// MeshPairs returns full-mesh pair of workloads
func (wc *WorkloadCollection) MeshPairs() *WorkloadPairCollection {
	if wc.HasError() {
		return &WorkloadPairCollection{CollectionCommon: CollectionCommon{Client: wc.Client, err: wc.Error()}}
	}

	collection := WorkloadPairCollection{}

	for i, wf := range wc.Workloads {
		for j, ws := range wc.Workloads {
			if i != j {
				pair := WorkloadPair{
					First:  wf,
					Second: ws,
				}
				collection.Pairs = append(collection.Pairs, &pair)
			}
		}
	}

	return &collection
}

// MeshPairs returns full-mesh pair of Workloads
func (wc *WorkloadCollection) MeshPairsWithOther(other *WorkloadCollection) *WorkloadPairCollection {
	if wc.HasError() {
		return NewWorkloadPairCollection(wc.CollectionCommon.Client, wc.CollectionCommon.Testbed)
	}

	collection := WorkloadPairCollection{}

	for _, wf := range wc.Workloads {
		for _, ws := range other.Workloads {
			pair := WorkloadPair{
				First:  wf,
				Second: ws,
			}
			collection.Pairs = append(collection.Pairs, &pair)
		}
	}

	return &collection
}

// LocalPairs returns pairs of Workloads in same host
func (wc *WorkloadCollection) LocalPairs() *WorkloadPairCollection {

	collection := NewWorkloadPairCollection(wc.Client, wc.Testbed)

	for i, wf := range wc.Workloads {
		for j, ws := range wc.Workloads {
			if i != j && wf.iotaWorkload.NodeName == ws.iotaWorkload.NodeName {
				pair := WorkloadPair{
					First:  wf,
					Second: ws,
				}
				collection.Pairs = append(collection.Pairs, &pair)
			}
		}
	}

	return collection
}