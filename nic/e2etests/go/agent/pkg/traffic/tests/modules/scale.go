package modules

import (
	"github.com/pkg/errors"

	Pkg "github.com/pensando/sw/nic/e2etests/go/agent/pkg"
	Tests "github.com/pensando/sw/nic/e2etests/go/agent/pkg/traffic/tests"
	TestApi "github.com/pensando/sw/nic/e2etests/go/agent/pkg/traffic/tests/api"
	Infra "github.com/pensando/sw/nic/e2etests/go/infra"
)

type FlowScale struct {
}

func (FlowScale) Run(srcEp *Infra.Endpoint, dstEp *Infra.Endpoint) error {
	/* If differet Network, setup routes */

	cmd := []string{"hping3", dstEp.GetIP(), "-S", "-p", "6666", "-i", "u700000",
		"-c", "10"}

	if _, err := srcEp.AppEngine.RunCommand(cmd, 0, false); err != nil {
		return errors.Wrap(err, "FlowScale test failed")
	}
	cmd[1] = srcEp.GetIP()
	if _, err := dstEp.AppEngine.RunCommand(cmd, 0, false); err != nil {
		return errors.Wrap(err, "FlowScale test failed")
	}

	return nil
}

func (FlowScale) FilterEpPairs(epPairs []TestApi.EpPair, agentCfg *Pkg.AgentConfig) []TestApi.EpPair {
	return epPairs
}

func init() {
	tm := Tests.GetTestManager()
	tm.Register(FlowScale{})
}
