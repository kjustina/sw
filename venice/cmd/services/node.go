package services

import (
	"fmt"
	"sync"

	"github.com/pensando/sw/venice/cmd/env"
	configs "github.com/pensando/sw/venice/cmd/systemd-configs"
	"github.com/pensando/sw/venice/cmd/types"
	"github.com/pensando/sw/venice/utils/log"
)

// Services that run on all controller nodes
var (
	nodeServices = []string{"pen-kubelet"}
)

type nodeService struct {
	sync.Mutex
	sysSvc    types.SystemdService
	virtualIP string
	enabled   bool
	configs   configs.Interface
	nodeID    string
}

// NodeOption fills the optional params
type NodeOption func(service *nodeService)

// WithConfigsNodeOption to pass a specifc types.SystemdService implementation
func WithConfigsNodeOption(configs configs.Interface) NodeOption {
	return func(o *nodeService) {
		o.configs = configs
	}
}

// WithSystemdSvcNodeOption to pass a specifc types.SystemdService implementation
func WithSystemdSvcNodeOption(sysSvc types.SystemdService) NodeOption {
	return func(o *nodeService) {
		o.sysSvc = sysSvc
	}
}

// NewNodeService returns a NodeService
func NewNodeService(nodeID, virtualIP string, options ...NodeOption) types.NodeService {
	s := nodeService{
		virtualIP: virtualIP,
		sysSvc:    env.SystemdService,
		configs:   configs.New(),
		nodeID:    nodeID,
	}

	for _, o := range options {
		if o != nil {
			o(&s)
		}
	}

	s.sysSvc.Register(&s)
	return &s
}

// Start starts the services that run on all controller nodes in
// the cluster.
func (s *nodeService) Start() error {
	s.sysSvc.Start()

	s.Lock()
	defer s.Unlock()
	s.enabled = true
	if err := s.configs.GenerateKubeletConfig(s.nodeID, s.virtualIP); err != nil {
		return err
	}

	if err := s.configs.GenerateFilebeatConfig(s.virtualIP); err != nil {
		return err
	}

	for ii := range nodeServices {
		if err := s.sysSvc.StartUnit(fmt.Sprintf("%s.service", nodeServices[ii])); err != nil {
			return err
		}
	}
	return nil
}

// Stop stops the services that run on all controller nodes in the
// cluster.
func (s *nodeService) Stop() {
	s.Lock()
	defer s.Unlock()
	s.enabled = false
	for ii := range nodeServices {
		if err := s.sysSvc.StopUnit(fmt.Sprintf("%s.service", nodeServices[ii])); err != nil {
			log.Errorf("Failed to stop node service %v with error: %v", nodeServices[ii], err)
		}
	}
	s.configs.RemoveKubeletConfig()
	s.configs.RemoveFilebeatConfig()

}

// AreNodeServicesRunning returns if all the controller node services are
// running.
func (s *nodeService) AreNodeServicesRunning() bool {
	// TODO: Need systemd API for this
	return true
}

func (s *nodeService) OnNotifySystemdEvent(e types.SystemdEvent) error {
	found := false
	for _, n := range nodeServices {
		if e.Name == n {
			found = true
			break
		}
	}
	if !found {
		return nil // service that i am not interested in
	}
	switch e.Status {
	case types.SystemdUnitDead:
		if s.enabled {
			log.Errorf("service %v stopped", e.Name)
		}
	case types.SystemdUnitActive:
	case types.SystemdUnitInTransit:
	}
	return nil
}
