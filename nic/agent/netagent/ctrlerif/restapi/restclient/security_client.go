// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: security.proto
*/
package restclient

import (
	"github.com/pensando/sw/venice/ctrler/npm/rpcserver/netproto"
	"github.com/pensando/sw/venice/utils/netutils"
)

// SecurityGroupList lists all SecurityGroup objects
func (cl *NetagentClient) SecurityGroupList() ([]netproto.SecurityGroup, error) {
	var securitygroupList []netproto.SecurityGroup

	err := netutils.HTTPGet("http://"+cl.agentURL+"/api/sgs/", &securitygroupList)

	return securitygroupList, err

}

// SecurityGroupPost creates SecurityGroup object
func (cl *NetagentClient) SecurityGroupCreate(postData netproto.SecurityGroup) error {
	var resp Response

	err := netutils.HTTPPost("http://"+cl.agentURL+"/api/sgs/", &postData, &resp)

	return err

}

// SecurityGroupPut updates SecurityGroup object
func (cl *NetagentClient) SecurityGroupUpdate(putData netproto.SecurityGroup) error {
	var resp Response

	err := netutils.HTTPPut("http://"+cl.agentURL+"/api/sgs/default/default/preCreatedSecurityGroup", &putData, &resp)

	return err
}

// SecurityGroupDelete deletes SecurityGroup object
func (cl *NetagentClient) SecurityGroupDelete(deleteData netproto.SecurityGroup) error {
	var resp Response

	err := netutils.HTTPDelete("http://"+cl.agentURL+"/api/sgs/default/default/testDeleteSecurityGroup", &deleteData, &resp)

	return err
}
