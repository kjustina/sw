// +build iris

package iris

import (
	"reflect"
	"testing"

	"github.com/pensando/sw/api"
	"github.com/pensando/sw/nic/agent/dscagent/types"
	"github.com/pensando/sw/nic/agent/protos/netproto"
)

func TestHandleColUpdates(t *testing.T) {
	col := Collector{
		Name:        "testCollector",
		Destination: "192.168.100.101",
	}
	err := HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Create, col, 65)
	if err != nil {
		t.Fatal(err)
	}
	internalCol := "192.168.100.101"
	internalCol1 := "192.168.100.103"
	if _, ok := lateralDB[internalCol]; !ok {
		t.Fatalf("192.168.100.101 collector not created. DB %v", lateralDB)
	}
	if len(lateralDB[internalCol]) != 1 {
		t.Fatalf("Collector keys not populated for 192.168.100.101. %v", lateralDB[internalCol])
	}
	err = HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Delete, col, 65)
	if err != nil {
		t.Fatal(err)
	}
	col.Destination = "192.168.100.103"
	err = HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Create, col, 65)
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := lateralDB[internalCol]; ok && len(lateralDB[internalCol]) != 0 {
		t.Fatalf("192.168.100.101 should be removed. DB %v", lateralDB)
	}
	if _, ok := lateralDB[internalCol1]; !ok {
		t.Fatalf("192.168.100.103 collector not created. DB %v", lateralDB)
	}
	if len(lateralDB[internalCol1]) != 1 {
		t.Fatalf("Collector keys not populated. %v", lateralDB[internalCol1])
	}
	err = HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Delete, col, 65)
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := lateralDB[internalCol]; ok && len(lateralDB[internalCol]) != 0 {
		t.Fatalf("192.168.100.101 should be removed. DB %v", lateralDB)
	}
	if _, ok := lateralDB[internalCol1]; ok && len(lateralDB[internalCol1]) != 0 {
		t.Fatalf("192.168.100.101 should be removed. DB %v", lateralDB)
	}
}

func TestMirrorSessionIDRefcoutingCol(t *testing.T) {
	cols := []Collector{
		{
			Name:        "testCollector1",
			VrfName:     "default",
			Destination: "192.168.100.101",
			PacketSize:  128,
		},
		{
			Name:        "testCollector2",
			VrfName:     "default",
			Destination: "192.168.100.102",
			PacketSize:  128,
		},
	}
	mirrors := []netproto.MirrorSession{
		{
			TypeMeta: api.TypeMeta{Kind: "MirrorSession"},
			ObjectMeta: api.ObjectMeta{
				Tenant:    "default",
				Namespace: "default",
				Name:      "testMirror1",
			},
			Spec: netproto.MirrorSessionSpec{
				VrfName:    "default",
				PacketSize: 128,
				Collectors: []netproto.MirrorCollector{
					{
						ExportCfg: netproto.MirrorExportConfig{Destination: "192.168.100.101"},
						Type:      "ERSPAN_Type_3",
					},
				},
			},
		},
		{
			TypeMeta: api.TypeMeta{Kind: "MirrorSession"},
			ObjectMeta: api.ObjectMeta{
				Tenant:    "default",
				Namespace: "default",
				Name:      "testMirror2",
			},
			Spec: netproto.MirrorSessionSpec{
				VrfName:    "default",
				PacketSize: 128,
				Collectors: []netproto.MirrorCollector{
					{
						ExportCfg: netproto.MirrorExportConfig{Destination: "192.168.100.101"},
						Type:      "ERSPAN_Type_3",
					},
				},
			},
		},
		{
			TypeMeta: api.TypeMeta{Kind: "MirrorSession"},
			ObjectMeta: api.ObjectMeta{
				Tenant:    "default",
				Namespace: "default",
				Name:      "testMirror3",
			},
			Spec: netproto.MirrorSessionSpec{
				VrfName:    "default",
				PacketSize: 128,
				Collectors: []netproto.MirrorCollector{
					{
						ExportCfg: netproto.MirrorExportConfig{Destination: "192.168.100.103"},
						Type:      "ERSPAN_Type_3",
					},
				},
			},
		},
	}
	vrf := netproto.Vrf{
		TypeMeta: api.TypeMeta{Kind: "Vrf"},
		ObjectMeta: api.ObjectMeta{
			Tenant:    "default",
			Namespace: "default",
			Name:      "default",
		},
		Spec: netproto.VrfSpec{
			VrfType: "INFRA",
		},
	}
	err := HandleVrf(infraAPI, vrfClient, types.Create, vrf)
	if err != nil {
		t.Fatal(err)
	}
	// Create collectors
	for _, col := range cols {
		err := HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Create, col, 65)
		if err != nil {
			t.Fatal(err)
		}
	}
	// Create mirror sessions
	for _, mirror := range mirrors {
		err := HandleMirrorSession(infraAPI, telemetryClient, intfClient, epClient, types.Create, mirror, 65)
		if err != nil {
			t.Fatal(err)
		}
	}
	if len(MirrorDestToIDMapping) != 3 {
		t.Fatalf("Must have 3 items in the map, %v", MirrorDestToIDMapping)
	}
	// Verify that first collector delete is successful
	if err := HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Delete, cols[0], 65); err != nil {
		t.Fatalf("Must return a valid error. Err: %v", err)
	}
	// Verify that second collector delete is successful
	if err := HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Delete, cols[1], 65); err != nil {
		t.Fatalf("Must not return an error. Err: %v", err)
	}
	// Verify the mappings
	mirrorIDs, ok := MirrorDestToIDMapping["default-192.168.100.101"]
	if !ok {
		t.Fatalf("Expected default-192.168.100.101 to be a key in MirrorDestToIDMapping, %v", MirrorDestToIDMapping)
	}
	if len(mirrorIDs.MirrorKeys) != 2 {
		t.Fatalf("Expected 2 entries in MirrorKeys %v", mirrorIDs.MirrorKeys)
	}
	if !reflect.DeepEqual(mirrorIDs.MirrorKeys, []string{"testMirror2-default-192.168.100.101", "testMirror1-default-192.168.100.101"}) {
		t.Fatalf("Unexpected mirror %v", mirrorIDs.MirrorKeys)
	}

	mirrorIDs, ok = MirrorDestToIDMapping["default-192.168.100.103"]
	if !ok {
		t.Fatalf("Expected default-192.168.100.103 to be a key in MirrorDestToIDMapping, %v", MirrorDestToIDMapping)
	}
	if len(mirrorIDs.MirrorKeys) != 1 {
		t.Fatalf("Expected 1 entry in MirrorKeys %v", mirrorIDs.MirrorKeys)
	}
	if !reflect.DeepEqual(mirrorIDs.MirrorKeys, []string{"testMirror3-default-192.168.100.103"}) {
		t.Fatalf("Unexpected mirror %v", mirrorIDs.MirrorKeys)
	}

	_, ok = MirrorDestToIDMapping["default-192.168.100.102"]
	if ok {
		t.Fatalf("Expected default-192.168.100.102 to not be in MirrorDestToIDMapping, %v", MirrorDestToIDMapping)
	}

	// Remove one mirror sessions and verify the mappings
	err = HandleMirrorSession(infraAPI, telemetryClient, intfClient, epClient, types.Delete, mirrors[0], 65)
	if err != nil {
		t.Fatal(err)
	}

	mirrorIDs, ok = MirrorDestToIDMapping["default-192.168.100.101"]
	if !ok {
		t.Fatalf("Expected default-192.168.100.101 to be a key in MirrorDestToIDMapping, %v", MirrorDestToIDMapping)
	}
	if len(mirrorIDs.MirrorKeys) != 1 {
		t.Fatalf("Expected 1 entries in MirrorKeys %v", mirrorIDs.MirrorKeys)
	}
	if !reflect.DeepEqual(mirrorIDs.MirrorKeys, []string{"testMirror2-default-192.168.100.101"}) {
		t.Fatalf("Unexpected mirror %v", mirrorIDs.MirrorKeys)
	}

	// Remove the second mirror session and verify that no mappings are present for default-192.168.100.101
	err = HandleMirrorSession(infraAPI, telemetryClient, intfClient, epClient, types.Delete, mirrors[1], 65)
	if err != nil {
		t.Fatal(err)
	}

	// Verify that first collector delete is erred as already deleted
	if err := HandleCol(infraAPI, telemetryClient, intfClient, epClient, types.Delete, cols[0], 65); err == nil {
		t.Fatal(err)
	}

	if _, ok = MirrorDestToIDMapping["default-192.168.100.101"]; ok {
		t.Fatalf("Expected MirrorDestToIDMapping to not have default-192.168.100.101 %v", MirrorDestToIDMapping["default-192.168.100.101"])
	}
	// Remove the last mirror session and verify that no mappings are present
	err = HandleMirrorSession(infraAPI, telemetryClient, intfClient, epClient, types.Delete, mirrors[2], 65)
	if err != nil {
		t.Fatal(err)
	}

	if _, ok = MirrorDestToIDMapping["default-192.168.100.103"]; ok {
		t.Fatalf("Expected MirrorDestToIDMapping to not have default-192.168.100.103 %v", MirrorDestToIDMapping["default-192.168.100.103"])
	}
}
