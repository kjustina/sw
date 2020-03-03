package ctrlerif

import (
	"context"
	"fmt"
	"strings"
	"sync"
	"time"

	"github.com/pensando/sw/events/generated/eventtypes"
	"github.com/pensando/sw/venice/utils/events/recorder"

	"github.com/pensando/sw/api"
	tpmproto "github.com/pensando/sw/nic/agent/protos/tpmprotos"
	"github.com/pensando/sw/nic/agent/tmagent/types"
	"github.com/pensando/sw/venice/utils/balancer"
	"github.com/pensando/sw/venice/utils/log"
	"github.com/pensando/sw/venice/utils/resolver"
	"github.com/pensando/sw/venice/utils/rpckit"
)

const watchlen = 100

// TpClient is the telemetry policy client
type TpClient struct {
	sync.Mutex
	agentName      string
	srvURL         string
	resolverClient resolver.Interface
	waitGrp        sync.WaitGroup
	state          types.CtrlerIntf
	rpcClient      *rpckit.RPCClient
	watchCtx       context.Context
	watchCancel    context.CancelFunc
}

var syncInterval = time.Minute * 5

const maxRetry = 3

// NewTpClient creates telemetry policy client object
func NewTpClient(name string, state types.CtrlerIntf, srvURL string, resolverClient resolver.Interface) (*TpClient, error) {
	watchCtx, watchCancel := context.WithCancel(context.Background())
	tpClient := TpClient{
		agentName:      name,
		srvURL:         srvURL,
		resolverClient: resolverClient,
		state:          state,
		watchCtx:       watchCtx,
		watchCancel:    watchCancel,
	}
	go tpClient.runWatcher(tpClient.watchCtx)

	return &tpClient, nil
}

// watch telemetry/fwlog/flow-export policies
func (client *TpClient) runWatcher(ctx context.Context) {
	client.waitGrp.Add(1)
	defer client.waitGrp.Done()

	for ctx.Err() == nil {
		bl := balancer.New(client.resolverClient)
		// create a grpc client
		rpcClient, err := rpckit.NewRPCClient(client.agentName, client.srvURL, rpckit.WithBalancer(bl))
		if err != nil {
			bl.Close()
			log.Errorf("Error connecting to %s, Err: %v", client.srvURL, err)
			time.Sleep(time.Second)
			continue
		}
		log.Infof("grpc client connected to %v", client.srvURL)

		client.rpcClient = rpcClient
		client.processEvents(ctx)

		client.rpcClient.Close()

		time.Sleep(time.Second)
	}
}

func (w *watchChan) watchFwlogPolicy(ctx context.Context, cl tpmproto.FwlogPolicyApiV1_WatchFwlogPolicyClient) {
	defer func() {
		close(w.fwlogChan)
		w.wg.Done()
	}()

	for ctx.Err() == nil {
		event, err := cl.Recv()
		if err != nil {
			log.Errorf("stop watching fwlog policy, error:%s", err)
			return
		}
		select {
		case w.fwlogChan <- event:
		case <-ctx.Done():
		}
	}
}

type watchChan struct {
	wg        sync.WaitGroup
	fwlogChan chan *tpmproto.FwlogPolicyEvent
}

func (client *TpClient) processEvents(pctx context.Context) error {
	wc := &watchChan{
		fwlogChan: make(chan *tpmproto.FwlogPolicyEvent, watchlen),
	}

	ctx, cancel := context.WithCancel(pctx)
	defer func() {
		cancel()
		wc.wg.Wait()
	}()

	fwlogClient := tpmproto.NewFwlogPolicyApiV1Client(client.rpcClient.ClientConn)
	fwlogPolicyStream, err := fwlogClient.WatchFwlogPolicy(ctx, &api.ObjectMeta{})
	if err != nil {
		log.Errorf("Error watching fwlog policy: Err: %v", err)
		return err
	}
	wc.wg.Add(1)
	go wc.watchFwlogPolicy(ctx, fwlogPolicyStream)

	for {
		select {

		case event, ok := <-wc.fwlogChan:
			if !ok {
				log.Errorf("fwlog policy channel closed")
				return nil
			}

			log.Infof("received policy(%s) %+v", event.EventType, event.Policy)

			func() {
				var err error
				for iter := 0; iter < maxRetry; iter++ {
					switch event.EventType {
					case api.EventType_CreateEvent:
						if err = client.state.CreateFwlogPolicy(ctx, event.Policy); err != nil {
							if strings.Contains(err.Error(), "already exists") {
								err = client.state.UpdateFwlogPolicy(ctx, event.Policy)
							}
						}
					case api.EventType_UpdateEvent:
						if err = client.state.UpdateFwlogPolicy(ctx, event.Policy); err != nil {
							if strings.Contains(err.Error(), "doesn't exist") {
								err = client.state.CreateFwlogPolicy(ctx, event.Policy)
							}
						}
					case api.EventType_DeleteEvent:
						if err = client.state.DeleteFwlogPolicy(ctx, event.Policy); err != nil {
							if strings.Contains(err.Error(), "doesn't exist") {
								err = nil
							}
						}
					}

					if err == nil {
						return
					}

					log.Errorf("[%v] fwlog policy failed, err: %v", event.EventType, err)
					time.Sleep(time.Second * 5)
				}
				recorder.Event(eventtypes.CONFIG_FAIL, fmt.Sprintf("Failed to %v %v %v, error: %v",
					strings.Split(strings.ToLower(event.EventType.String()), "-event")[0], event.Policy.Kind,
					event.Policy.Name, err), event.Policy)
			}()

			// periodic sync
		case <-time.After(syncInterval):
			// fwlog
			fwEvent, err := fwlogClient.ListFwlogPolicy(ctx, &api.ObjectMeta{})
			if err == nil {
				ctrlFw := map[string]*tpmproto.FwlogPolicy{}
				for _, fw := range fwEvent.EventList {
					ctrlFw[fw.Policy.GetKey()] = fw.Policy
				}

				// read policy from agent
				agFw, err := client.state.ListFwlogPolicy(ctx)
				if err == nil {
					for _, pol := range agFw {
						if _, ok := ctrlFw[pol.GetKey()]; !ok {
							log.Infof("sync deleting fwlog policy %v", pol.GetKey())
							if err := client.state.DeleteFwlogPolicy(ctx, pol); err != nil {
								log.Errorf("failed to delete %v, err: %v", pol.GetKey(), err)
							}
						}
					}
				}
			}

		case <-pctx.Done():
			log.Warnf("canceled telemetry policy watch while there are %d events in fwlogChan ",
				len(wc.fwlogChan))
			return nil
		}
	}
}

// Stop stops all the watchers
func (client *TpClient) Stop() {
	client.watchCancel()
	client.waitGrp.Wait()
}
