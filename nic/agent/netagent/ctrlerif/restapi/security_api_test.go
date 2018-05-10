// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: security.proto
*/
package restapi

import (
	"testing"

	api "github.com/pensando/sw/api"
	"github.com/pensando/sw/venice/ctrler/npm/rpcserver/netproto"
	"github.com/pensando/sw/venice/utils/netutils"
	. "github.com/pensando/sw/venice/utils/testutils"
)

func TestSecurityGroupList(t *testing.T) {
	t.Parallel()
	var ok bool
	var securitygroupList []*netproto.SecurityGroup

	err := netutils.HTTPGet("http://"+agentRestURL+"/api/sgs/", &securitygroupList)

	AssertOk(t, err, "Error getting securitygroups from the REST Server")
	for _, o := range securitygroupList {
		if o.Name == "preCreatedSecurityGroup" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find preCreatedSecurityGroup in Response: %v", securitygroupList)
	}

}

func TestSecurityGroupPost(t *testing.T) {
	t.Parallel()
	var resp Response
	var ok bool
	var securitygroupList []*netproto.SecurityGroup

	postData := netproto.SecurityGroup{
		TypeMeta: api.TypeMeta{Kind: "SecurityGroup"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testPostSecurityGroup",
		},
		Spec: netproto.SecurityGroupSpec{
			SecurityProfile: "unknown",
			Rules: []netproto.SecurityRule{
				{
					Direction: "Incoming",
					PeerGroup: "",
					Action:    "Allow",
				},
			},
		},
	}
	err := netutils.HTTPPost("http://"+agentRestURL+"/api/sgs/", &postData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/sgs/", &securitygroupList)

	AssertOk(t, err, "Error posting securitygroup to REST Server")
	AssertOk(t, getErr, "Error getting securitygroups from the REST Server")
	for _, o := range securitygroupList {
		if o.Name == "testPostSecurityGroup" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find testPostSecurityGroup in Response: %v", securitygroupList)
	}

}

func TestSecurityGroupUpdate(t *testing.T) {
	t.Parallel()
	var resp Response
	var securitygroupList []*netproto.SecurityGroup

	var actualSecurityGroupSpec netproto.SecurityGroupSpec
	updatedSecurityGroupSpec := netproto.SecurityGroupSpec{
		SecurityProfile: "unknown",
		Rules: []netproto.SecurityRule{
			{
				Direction: "Incoming",
				PeerGroup: "",
				Action:    "Deny",
			},
		},
	}
	putData := netproto.SecurityGroup{
		TypeMeta: api.TypeMeta{Kind: "SecurityGroup"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "preCreatedSecurityGroup",
		},
		Spec: updatedSecurityGroupSpec,
	}
	err := netutils.HTTPPut("http://"+agentRestURL+"/api/sgs/default/default/preCreatedSecurityGroup", &putData, &resp)
	AssertOk(t, err, "Error updating securitygroup to REST Server")

	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/sgs/", &securitygroupList)
	AssertOk(t, getErr, "Error getting securitygroups from the REST Server")

	for _, o := range securitygroupList {
		if o.Name == "preCreatedSecurityGroup" {
			actualSecurityGroupSpec = o.Spec
			break
		}
	}
	AssertEquals(t, updatedSecurityGroupSpec, actualSecurityGroupSpec, "Could not validate updated spec.")

}

func TestSecurityGroupDelete(t *testing.T) {
	t.Parallel()
	var resp Response
	var found bool
	var securitygroupList []*netproto.SecurityGroup

	postData := netproto.SecurityGroup{
		TypeMeta: api.TypeMeta{Kind: "SecurityGroup"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testDeleteSecurityGroup",
		},
		Spec: netproto.SecurityGroupSpec{
			SecurityProfile: "unknown",
			Rules: []netproto.SecurityRule{
				{
					Direction: "Incoming",
					PeerGroup: "",
					Action:    "Allow",
				},
			},
		},
	}
	postErr := netutils.HTTPPost("http://"+agentRestURL+"/api/sgs/", &postData, &resp)
	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/sgs/default/default/testDeleteSecurityGroup", &postData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/sgs/", &securitygroupList)

	AssertOk(t, postErr, "Error posting securitygroup to REST Server")
	AssertOk(t, err, "Error deleting securitygroup from REST Server")
	AssertOk(t, getErr, "Error getting securitygroups from the REST Server")
	for _, o := range securitygroupList {
		if o.Name == "testDeleteSecurityGroup" {
			found = true
			break
		}
	}
	if found {
		t.Errorf("Found testDeleteSecurityGroup in Response after deleting: %v", securitygroupList)
	}

}
