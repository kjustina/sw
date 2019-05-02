// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package netproto is a auto generated package.
Input file: ipsec.proto
*/
package restapi_test

import (
	"testing"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/protos/netproto"
	"github.com/pensando/sw/venice/utils/netutils"
	. "github.com/pensando/sw/venice/utils/testutils"
)

func TestIPSecPolicyList(t *testing.T) {
	t.Parallel()
	var ok bool
	var ipsecpolicyList []*netproto.IPSecPolicy

	err := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/policies/", &ipsecpolicyList)

	AssertOk(t, err, "Error getting ipsecpolicys from the REST Server")
	for _, o := range ipsecpolicyList {
		if o.Name == "preCreatedIPSecPolicy" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find preCreatedIPSecPolicy in Response: %v", ipsecpolicyList)
	}

}

func TestIPSecPolicyPost(t *testing.T) {
	t.Parallel()
	var resp Response
	var ok bool
	var ipsecpolicyList []*netproto.IPSecPolicy

	postData := netproto.IPSecPolicy{
		TypeMeta: api.TypeMeta{Kind: "IPSecPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testPostIPSecPolicy",
		},
		Spec: netproto.IPSecPolicySpec{
			VrfName: "default",
			Rules: []netproto.IPSecRule{
				{
					Src: &netproto.MatchSelector{
						Addresses: []string{"192.168.1.1/24", "8.8.8.8"},
					},
					Dst: &netproto.MatchSelector{
						Addresses: []string{"10.0.0.0 - 10.0.1.0", "172.17.0.0/24", "4.4.4.4"},
					},
					SAName: "preCreatedIPSecSAEncrypt",
					SAType: "ENCRYPT",
				},
				{
					Src: &netproto.MatchSelector{
						Addresses: []string{"10.0.0.0 - 10.0.1.0", "172.17.0.0/24", "4.4.4.4"},
					},
					Dst: &netproto.MatchSelector{
						Addresses: []string{"192.168.0.1 - 192.168.1.0", "64.0.0.1/16"},
					},
					SAName: "preCreatedIPSecSADecrypt",
					SAType: "DECRYPT",
					SPI:    42,
				},
			},
		},
	}
	err := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/policies/", &postData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/policies/", &ipsecpolicyList)

	AssertOk(t, err, "Error posting ipsecpolicy to REST Server")
	AssertOk(t, getErr, "Error getting ipsecpolicys from the REST Server")
	for _, o := range ipsecpolicyList {
		if o.Name == "testPostIPSecPolicy" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find testPostIPSecPolicy in Response: %v", ipsecpolicyList)
	}

}

func TestIPSecPolicyUpdate(t *testing.T) {
	t.Parallel()
	var resp Response
	var ipsecpolicyList []*netproto.IPSecPolicy

	var actualIPSecPolicySpec netproto.IPSecPolicySpec
	updatedIPSecPolicySpec := netproto.IPSecPolicySpec{
		VrfName: "default",
		Rules: []netproto.IPSecRule{
			{
				SAName: "updatedEncryptSA",
			},
		},
	}
	putData := netproto.IPSecPolicy{
		TypeMeta: api.TypeMeta{Kind: "IPSecPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Name:      "preCreatedIPSecPolicy",
			Namespace: "default",
		},
		Spec: updatedIPSecPolicySpec,
	}
	err := netutils.HTTPPut("http://"+agentRestURL+"/api/ipsec/policies/default/default/preCreatedIPSecPolicy", &putData, &resp)
	AssertOk(t, err, "Error updating ipsecpolicy to REST Server")

	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/policies/", &ipsecpolicyList)
	AssertOk(t, getErr, "Error getting ipsecpolicys from the REST Server")
	for _, o := range ipsecpolicyList {
		if o.Name == "preCreatedIPSecPolicy" {
			actualIPSecPolicySpec = o.Spec
			break
		}
	}
	AssertEquals(t, updatedIPSecPolicySpec, actualIPSecPolicySpec, "Could not validate updated spec.")

}

func TestIPSecPolicyDelete(t *testing.T) {
	t.Parallel()
	var resp Response
	var found bool
	var ipsecpolicyList []*netproto.IPSecPolicy

	deleteData := netproto.IPSecPolicy{
		TypeMeta: api.TypeMeta{Kind: "IPSecPolicy"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testDeleteIPSecPolicy",
		},
		Spec: netproto.IPSecPolicySpec{
			VrfName: "default",
			Rules: []netproto.IPSecRule{
				{
					Src: &netproto.MatchSelector{
						Addresses: []string{"10.0.0.0 - 10.0.1.0", "172.17.0.0/24", "4.4.4.4"},
						AppConfigs: []*netproto.AppConfig{
							{
								Port:     "80",
								Protocol: "tcp",
							},
						},
					},

					Dst: &netproto.MatchSelector{
						Addresses: []string{"10.0.0.0 - 10.0.1.0", "172.17.0.0/24", "4.4.4.4"},
						AppConfigs: []*netproto.AppConfig{
							{
								Port:     "80",
								Protocol: "tcp",
							},
						},
					},
					SAName: "preCreatedIPSecSAEncrypt",
					SAType: "ENCRYPT",
				},
				{
					Src: &netproto.MatchSelector{
						Addresses: []string{"10.0.0.0 - 10.0.1.0", "172.17.0.0/24", "4.4.4.4"},
						AppConfigs: []*netproto.AppConfig{
							{
								Port:     "80",
								Protocol: "tcp",
							},
						},
					},

					Dst: &netproto.MatchSelector{
						Addresses: []string{"192.168.0.1 - 192.168.1.0"},
						AppConfigs: []*netproto.AppConfig{
							{
								Port:     "80",
								Protocol: "tcp",
							},
						},
					},

					SAName: "preCreatedIPSecSADecrypt",
					SAType: "DECRYPT",
					SPI:    42,
				},
			},
		},
	}
	postErr := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/policies/", &deleteData, &resp)
	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/ipsec/policies/default/default/testDeleteIPSecPolicy", &deleteData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/policies/", &ipsecpolicyList)

	AssertOk(t, postErr, "Error posting ipsecpolicy to REST Server")
	AssertOk(t, err, "Error deleting ipsecpolicy from REST Server")
	AssertOk(t, getErr, "Error getting ipsecpolicys from the REST Server")
	for _, o := range ipsecpolicyList {
		if o.Name == "testDeleteIPSecPolicy" {
			found = true
			break
		}
	}
	if found {
		t.Errorf("Found testDeleteIPSecPolicy in Response after deleting: %v", ipsecpolicyList)
	}

}

func TestIPSecPolicyCreateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badPostData := netproto.IPSecPolicy{
		TypeMeta: api.TypeMeta{Kind: "IPSecPolicy"},
		ObjectMeta: api.ObjectMeta{
			Name: "",
		},
	}

	err := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/policies/", &badPostData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecPolicyDeleteErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.IPSecPolicy{
		TypeMeta: api.TypeMeta{Kind: "IPSecPolicy"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/ipsec/policies/default/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecPolicyUpdateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.IPSecPolicy{
		TypeMeta: api.TypeMeta{Kind: "IPSecPolicy"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPPut("http://"+agentRestURL+"/api/ipsec/policies/default/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecSADecryptList(t *testing.T) {
	t.Parallel()
	var ok bool
	var ipsecsadecryptList []*netproto.IPSecSADecrypt

	err := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/decryption/", &ipsecsadecryptList)

	AssertOk(t, err, "Error getting ipsecsadecrypts from the REST Server")
	for _, o := range ipsecsadecryptList {
		if o.Name == "preCreatedIPSecSADecrypt" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find preCreatedIPSecSADecrypt in Response: %v", ipsecsadecryptList)
	}

}

func TestIPSecSADecryptPost(t *testing.T) {
	t.Parallel()
	var resp Response
	var ok bool
	var ipsecsadecryptList []*netproto.IPSecSADecrypt

	postData := netproto.IPSecSADecrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSADecrypt"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testPostIPSecSADecrypt",
		},
		Spec: netproto.IPSecSADecryptSpec{
			VrfName:            "default",
			Protocol:           "ESP",
			AuthAlgo:           "AES_GCM",
			AuthKey:            "someRandomString",
			DecryptAlgo:        "AES_GCM_256",
			DecryptionKey:      "someRandomKey",
			RekeyDecryptAlgo:   "DES3",
			RekeyDecryptionKey: "someRandomString",
			LocalGwIP:          "10.0.0.1",
			RemoteGwIP:         "192.168.1.1",
			SPI:                1,
			TepVrf:             "default",
		},
	}
	err := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/decryption/", &postData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/decryption/", &ipsecsadecryptList)

	AssertOk(t, err, "Error posting ipsecsadecrypt to REST Server")
	AssertOk(t, getErr, "Error getting ipsecsadecrypts from the REST Server")
	for _, o := range ipsecsadecryptList {
		if o.Name == "testPostIPSecSADecrypt" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find testPostIPSecSADecrypt in Response: %v", ipsecsadecryptList)
	}

}

func TestIPSecSADecryptUpdate(t *testing.T) {
	t.Parallel()
	var resp Response
	var ipsecsadecryptList []*netproto.IPSecSADecrypt

	var actualIPSecSADecryptSpec netproto.IPSecSADecryptSpec
	updatedIPSecSADecryptSpec := netproto.IPSecSADecryptSpec{
		VrfName:  "default",
		Protocol: "AH",
	}
	putData := netproto.IPSecSADecrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSADecrypt"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Name:      "preCreatedIPSecSADecrypt",
			Namespace: "default",
		},
		Spec: updatedIPSecSADecryptSpec,
	}
	err := netutils.HTTPPut("http://"+agentRestURL+"/api/ipsec/decryption/default/default/preCreatedIPSecSADecrypt", &putData, &resp)
	AssertOk(t, err, "Error updating ipsecsadecrypt to REST Server")

	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/decryption/", &ipsecsadecryptList)
	AssertOk(t, getErr, "Error getting ipsecsadecrypts from the REST Server")
	for _, o := range ipsecsadecryptList {
		if o.Name == "preCreatedIPSecSADecrypt" {
			actualIPSecSADecryptSpec = o.Spec
			break
		}
	}
	AssertEquals(t, updatedIPSecSADecryptSpec, actualIPSecSADecryptSpec, "Could not validate updated spec.")

}

func TestIPSecSADecryptDelete(t *testing.T) {
	t.Parallel()
	var resp Response
	var found bool
	var ipsecsadecryptList []*netproto.IPSecSADecrypt

	deleteData := netproto.IPSecSADecrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSADecrypt"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testDeleteIPSecSADecrypt",
		},
		Spec: netproto.IPSecSADecryptSpec{
			VrfName:       "default",
			Protocol:      "ESP",
			AuthAlgo:      "AES_GCM",
			AuthKey:       "someRandomString",
			DecryptAlgo:   "AES_GCM_256",
			DecryptionKey: "someRandomKey",
			LocalGwIP:     "10.0.0.1",
			RemoteGwIP:    "192.168.1.1",
			SPI:           1,
			TepVrf:        "default",
		},
	}
	postErr := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/decryption/", &deleteData, &resp)
	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/ipsec/decryption/default/default/testDeleteIPSecSADecrypt", &deleteData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/decryption/", &ipsecsadecryptList)

	AssertOk(t, postErr, "Error posting ipsecsadecrypt to REST Server")
	AssertOk(t, err, "Error deleting ipsecsadecrypt from REST Server")
	AssertOk(t, getErr, "Error getting ipsecsadecrypts from the REST Server")
	for _, o := range ipsecsadecryptList {
		if o.Name == "testDeleteIPSecSADecrypt" {
			found = true
			break
		}
	}
	if found {
		t.Errorf("Found testDeleteIPSecSADecrypt in Response after deleting: %v", ipsecsadecryptList)
	}

}

func TestIPSecSADecryptCreateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badPostData := netproto.IPSecSADecrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSADecrypt"},
		ObjectMeta: api.ObjectMeta{
			Name: "",
		},
	}

	err := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/decryption/", &badPostData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecSADecryptDeleteErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.IPSecSADecrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSADecrypt"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/ipsec/decryption/default/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecSADecryptUpdateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.IPSecSADecrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSADecrypt"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPPut("http://"+agentRestURL+"/api/ipsec/decryption/default/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecSAEncryptList(t *testing.T) {
	t.Parallel()
	var ok bool
	var ipsecsaencryptList []*netproto.IPSecSAEncrypt

	err := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/encryption/", &ipsecsaencryptList)

	AssertOk(t, err, "Error getting ipsecsaencrypts from the REST Server")
	for _, o := range ipsecsaencryptList {
		if o.Name == "preCreatedIPSecSAEncrypt" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find preCreatedIPSecSAEncrypt in Response: %v", ipsecsaencryptList)
	}

}

func TestIPSecSAEncryptPost(t *testing.T) {
	t.Parallel()
	var resp Response
	var ok bool
	var ipsecsaencryptList []*netproto.IPSecSAEncrypt

	postData := netproto.IPSecSAEncrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSAEncrypt"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testPostIPSecSAEncrypt",
		},
		Spec: netproto.IPSecSAEncryptSpec{
			VrfName:       "default",
			Protocol:      "ESP",
			AuthAlgo:      "AES_GCM",
			AuthKey:       "someRandomString",
			EncryptAlgo:   "AES_GCM_256",
			EncryptionKey: "someRandomKey",
			LocalGwIP:     "10.0.0.1",
			RemoteGwIP:    "192.168.1.1",
			SPI:           1,
			TepVrf:        "default",
		},
	}
	err := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/encryption/", &postData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/encryption/", &ipsecsaencryptList)

	AssertOk(t, err, "Error posting ipsecsaencrypt to REST Server")
	AssertOk(t, getErr, "Error getting ipsecsaencrypts from the REST Server")
	for _, o := range ipsecsaencryptList {
		if o.Name == "testPostIPSecSAEncrypt" {
			ok = true
			break
		}
	}
	if !ok {
		t.Errorf("Could not find testPostIPSecSAEncrypt in Response: %v", ipsecsaencryptList)
	}

}

func TestIPSecSAEncryptUpdate(t *testing.T) {
	t.Parallel()
	var resp Response
	var ipsecsaencryptList []*netproto.IPSecSAEncrypt

	var actualIPSecSAEncryptSpec netproto.IPSecSAEncryptSpec
	updatedIPSecSAEncryptSpec := netproto.IPSecSAEncryptSpec{
		VrfName:  "default",
		Protocol: "AH",
	}
	putData := netproto.IPSecSAEncrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSAEncrypt"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Name:      "preCreatedIPSecSAEncrypt",
			Namespace: "default",
		},
		Spec: updatedIPSecSAEncryptSpec,
	}
	err := netutils.HTTPPut("http://"+agentRestURL+"/api/ipsec/encryption/default/default/preCreatedIPSecSAEncrypt", &putData, &resp)
	AssertOk(t, err, "Error updating ipsecsaencrypt to REST Server")

	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/encryption/", &ipsecsaencryptList)
	AssertOk(t, getErr, "Error getting ipsecsaencrypts from the REST Server")
	for _, o := range ipsecsaencryptList {
		if o.Name == "preCreatedIPSecSAEncrypt" {
			actualIPSecSAEncryptSpec = o.Spec
			break
		}
	}
	AssertEquals(t, updatedIPSecSAEncryptSpec, actualIPSecSAEncryptSpec, "Could not validate updated spec.")

}

func TestIPSecSAEncryptDelete(t *testing.T) {
	t.Parallel()
	var resp Response
	var found bool
	var ipsecsaencryptList []*netproto.IPSecSAEncrypt

	deleteData := netproto.IPSecSAEncrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSAEncrypt"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "testDeleteIPSecSAEncrypt",
		},
		Spec: netproto.IPSecSAEncryptSpec{
			VrfName:       "default",
			Protocol:      "ESP",
			AuthAlgo:      "AES_GCM",
			AuthKey:       "someRandomString",
			EncryptAlgo:   "AES_GCM_256",
			EncryptionKey: "someRandomKey",
			LocalGwIP:     "10.0.0.1",
			RemoteGwIP:    "192.168.1.1",
			SPI:           1,
			TepVrf:        "default",
		},
	}
	postErr := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/encryption/", &deleteData, &resp)
	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/ipsec/encryption/default/default/testDeleteIPSecSAEncrypt", &deleteData, &resp)
	getErr := netutils.HTTPGet("http://"+agentRestURL+"/api/ipsec/encryption/", &ipsecsaencryptList)

	AssertOk(t, postErr, "Error posting ipsecsaencrypt to REST Server")
	AssertOk(t, err, "Error deleting ipsecsaencrypt from REST Server")
	AssertOk(t, getErr, "Error getting ipsecsaencrypts from the REST Server")
	for _, o := range ipsecsaencryptList {
		if o.Name == "testDeleteIPSecSAEncrypt" {
			found = true
			break
		}
	}
	if found {
		t.Errorf("Found testDeleteIPSecSAEncrypt in Response after deleting: %v", ipsecsaencryptList)
	}

}

func TestIPSecSAEncryptCreateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badPostData := netproto.IPSecSAEncrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSAEncrypt"},
		ObjectMeta: api.ObjectMeta{
			Name: "",
		},
	}

	err := netutils.HTTPPost("http://"+agentRestURL+"/api/ipsec/encryption/", &badPostData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecSAEncryptDeleteErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.IPSecSAEncrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSAEncrypt"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPDelete("http://"+agentRestURL+"/api/ipsec/encryption/default/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}

func TestIPSecSAEncryptUpdateErr(t *testing.T) {
	t.Parallel()
	var resp Response
	badDelData := netproto.IPSecSAEncrypt{
		TypeMeta: api.TypeMeta{Kind: "IPSecSAEncrypt"},
		ObjectMeta: api.ObjectMeta{Tenant: "default",
			Namespace: "default",
			Name:      "badObject"},
	}

	err := netutils.HTTPPut("http://"+agentRestURL+"/api/ipsec/encryption/default/default/badObject", &badDelData, &resp)

	Assert(t, err != nil, "Expected test to error out with 500. It passed instead")
}
