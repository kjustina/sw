//-----------------------------------------------------------------------------
// {C} Copyright 2017 Pensando Systems Inc. All rights reserved
//-----------------------------------------------------------------------------

package cmd

import (
	"context"
	"fmt"
	"os"
	"reflect"
	"strings"

	"github.com/spf13/cobra"
	yaml "gopkg.in/yaml.v2"

	"github.com/pensando/sw/nic/agent/cmd/halctl/utils"
	"github.com/pensando/sw/nic/agent/netagent/datapath/halproto"
	"github.com/pensando/sw/venice/utils/log"
)

var nwShowCmd = &cobra.Command{
	Use:   "network",
	Short: "show network objects",
	Long:  "show network object information",
	Run:   nwShowCmdHandler,
}

var nwDetailShowCmd = &cobra.Command{
	Use:   "detail",
	Short: "show detailed network information",
	Long:  "show detailed information about network objects",
	Run:   nwDetailShowCmdHandler,
}

func init() {
	showCmd.AddCommand(nwShowCmd)
	nwShowCmd.AddCommand(nwDetailShowCmd)
}

func nwShowCmdHandler(cmd *cobra.Command, args []string) {
	// Connect to HAL
	c, err := utils.CreateNewGRPCClient()
	defer c.Close()
	if err != nil {
		log.Fatalf("Could not connect to the HAL. Is HAL Running?")
	}
	client := halproto.NewNetworkClient(c.ClientConn)

	// Get all Nw
	req := &halproto.NetworkGetRequest{}
	networkGetReqMsg := &halproto.NetworkGetRequestMsg{
		Request: []*halproto.NetworkGetRequest{req},
	}

	// HAL call
	respMsg, err := client.NetworkGet(context.Background(), networkGetReqMsg)
	if err != nil {
		log.Errorf("Getting Network failed. %v", err)
	}

	// Print Header
	nwShowHeader()

	// Print NHs
	for _, resp := range respMsg.Response {
		if resp.ApiStatus != halproto.ApiStatus_API_STATUS_OK {
			log.Errorf("HAL Returned non OK status. %v", resp.ApiStatus)
			continue
		}
		nwShowOneResp(resp)
	}
}

func handleNwDetailShowCmd(cmd *cobra.Command, ofile *os.File) {
	// Connect to HAL
	c, err := utils.CreateNewGRPCClient()
	defer c.Close()
	if err != nil {
		log.Fatalf("Could not connect to the HAL. Is HAL Running?")
	}
	client := halproto.NewNetworkClient(c.ClientConn)

	// Get all Nw
	req := &halproto.NetworkGetRequest{}
	networkGetReqMsg := &halproto.NetworkGetRequestMsg{
		Request: []*halproto.NetworkGetRequest{req},
	}

	// HAL call
	respMsg, err := client.NetworkGet(context.Background(), networkGetReqMsg)
	if err != nil {
		log.Errorf("Getting Network failed. %v", err)
	}

	// Print NHs
	for _, resp := range respMsg.Response {
		if resp.ApiStatus != halproto.ApiStatus_API_STATUS_OK {
			log.Errorf("HAL Returned non OK status. %v", resp.ApiStatus)
			continue
		}
		respType := reflect.ValueOf(resp)
		b, _ := yaml.Marshal(respType.Interface())
		if ofile != nil {
			if _, err := ofile.WriteString(string(b)); err != nil {
				log.Errorf("Failed to write to file %s, err : %v",
					ofile.Name(), err)
			}
		} else {
			fmt.Println(string(b))
			fmt.Println("---")
		}
	}
}

func nwDetailShowCmdHandler(cmd *cobra.Command, args []string) {
	handleNwDetailShowCmd(cmd, nil)
}

func nwShowHeader() {
	fmt.Printf("\n")
	fmt.Printf("Handle:      Network Handle      VrfId:    Network's vrf id\n")
	fmt.Printf("GatewayIP:   Gateway IP          Subnet:   Network's subnet\n")
	fmt.Printf("Router MAC:  Router MAC          SGHandle: Security Group Handle\n")
	hdrLine := strings.Repeat("-", 96)
	fmt.Println(hdrLine)
	fmt.Printf("%-10s%-6s%-18s%-32s%-18s%-24s\n",
		"Handle", "VrfId", "GatewayIP", "Subnet", "Router MAC", "SGHandle")
	fmt.Println(hdrLine)
}

func nwShowOneResp(resp *halproto.NetworkGetResponse) {
	spec := resp.GetSpec()
	status := resp.GetStatus()

	sgKhList := spec.GetSgKeyHandle()
	sgKhStr := ""
	first := true
	for _, sgKh := range sgKhList {
		if first == true {
			first = false
			sgKhStr += fmt.Sprintf("%d", sgKh.GetSecurityGroupHandle())
		} else {
			sgKhStr += fmt.Sprintf(", %d", sgKh.GetSecurityGroupHandle())
		}
	}
	if len(sgKhStr) == 0 {
		sgKhStr += "-"
	}

	fmt.Printf("%-10d%-6d%-18s%-32s%-18s%-24s\n",
		status.GetNwHandle(),
		spec.GetKeyOrHandle().GetNwKey().GetVrfKeyHandle().GetVrfId(),
		utils.IPAddrToStr(spec.GetGatewayIp()),
		utils.IPPrefixToStr(spec.GetKeyOrHandle().GetNwKey().GetIpPrefix()),
		utils.MactoStr(spec.GetRmac()), sgKhStr)
}
