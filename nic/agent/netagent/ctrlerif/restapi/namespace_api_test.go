// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: namespace.proto
*/
package restapi

import (
	"testing"

	api "github.com/pensando/sw/api"
	"github.com/pensando/sw/venice/ctrler/npm/rpcserver/netproto"
	"github.com/pensando/sw/venice/utils/netutils"
	. "github.com/pensando/sw/venice/utils/testutils"
)

func TestNamespaceList(t *testing.T) {
	t.Parallel()
	var ok bool
	var namespaceList []*netproto.Namespace

	err := netutils.HTTPGet("http://"+agentRestURL+"/api/namespaces/", &namespaceList)

	AssertOk(t, err, "Error getting namespaces from the REST Server")
	for _, o := range namespaceList {
		if o.Name == "preCreatedNamespace" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find preCreatedNamespace in Response: %v", namespaceList)
	}

}

func TestNamespacePost(t *testing.T) {
	t.Parallel()
	var resp Response
	var ok bool
	var namespaceList []*netproto.Namespace

	postData := netproto.Namespace{
		TypeMeta: api.TypeMeta{Kind: "Tenant"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "testPostNamespace",
			Name:      "testPostNamespace",
			Namespace: "testPostNamespace",
		},
	}

	err := netutils.HTTPPost("http://"+agentRestURL+"/api/namespaces/", &postData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/namespaces/", &namespaceList)

	AssertOk(t, err, "Error posting namespace to REST Server")
	AssertOk(t, getErr, "Error getting namespaces from the REST Server")
	for _, o := range namespaceList {
		if o.Name == "testPostNamespace" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find testPostNamespace in Response: %v", namespaceList)
	}

}

func TestNamespaceDelete(t *testing.T) {
	t.Parallel()
	var resp Response
	var found bool
	var namespaceList []*netproto.Namespace

	deleteData := netproto.Namespace{
		TypeMeta: api.TypeMeta{Kind: "Namespace"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "preCreatedTenant",
			Name:      "testDeleteNamespace",
			Namespace: "testDeleteNamespace",
		},
	}
	postErr := netutils.HTTPPost("http://"+agentRestURL+"/api/namespaces/", &deleteData, &resp)
	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/namespaces/preCreatedTenant/testDeleteNamespace", &deleteData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/namespaces/", &namespaceList)

	AssertOk(t, postErr, "Error posting namespace to REST Server")
	AssertOk(t, err, "Error deleting namespace from REST Server")
	AssertOk(t, getErr, "Error getting namespaces from the REST Server")
	for _, o := range namespaceList {
		if o.Name == "testDeleteNamespace" {
			found = true
			break
		}
	}
	if found {
		t.Errorf("Found testDeleteNamespace in Response after deleting: %v", namespaceList)
	}

}

func TestNamespaceUpdate(t *testing.T) {
	t.Parallel()
	var resp Response
	var namespaceList []*netproto.Namespace

	var actualNamespaceSpec netproto.NamespaceSpec
	updatedNamespaceSpec := netproto.NamespaceSpec{
		Meta: &api.ObjectMeta{
			ResourceVersion: "v2",
		},
	}
	putData := netproto.Namespace{
		TypeMeta: api.TypeMeta{Kind: "Namespace"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "preCreatedTenant",
			Name:      "preCreatedNamespace",
			Namespace: "preCreatedNamespace",
		},
		Spec: updatedNamespaceSpec,
	}
	err := netutils.HTTPPut("http://"+agentRestURL+"/api/namespaces/preCreatedTenant/preCreatedNamespace", &putData, &resp)
	AssertOk(t, err, "Error updating namespace to REST Server")

	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/namespaces/", &namespaceList)
	AssertOk(t, getErr, "Error getting namespaces from the REST Server")
	for _, o := range namespaceList {
		if o.Name == "preCreatedNamespace" {
			actualNamespaceSpec = o.Spec
			break
		}
	}
	AssertEquals(t, updatedNamespaceSpec, actualNamespaceSpec, "Could not validate updated spec.")

}

func TestNamespaceCreateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badPostData := netproto.Namespace{
		TypeMeta: api.TypeMeta{Kind: "Namespace"},
		ObjectMeta: api.ObjectMeta{
			Name: "",
		},
	}

	err := netutils.HTTPPost("http://"+agentRestURL+"/api/namespaces/", &badPostData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestNamespaceDeleteErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.Namespace{
		TypeMeta: api.TypeMeta{Kind: "Namespace"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/namespaces/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestNamespaceUpdateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.Namespace{
		TypeMeta: api.TypeMeta{Kind: "Namespace"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPPut("http://"+agentRestURL+"/api/namespaces/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}
