// Code generated by protoc-gen-grpc-pensando DO NOT EDIT.

/*
Package eventtypes is a auto generated package.
Input file: github.com/pensando/sw/events/protos/eventtypes.proto
*/

package eventtypes

import "sort"

// EventTypeAttributes attributes belong to each event type
type EventTypeAttributes struct {
	EType    string
	Category string
	Severity string
	Desc     string
}

// EventDetails contains all the attributes of an events
type EventDetails struct {
	Name     string `json:name`
	Severity string `json:severity`
	Desc     string `json:desc`
}

// map containing the list of all event types and it's associated attributes
var eventTypes map[EventType]*EventTypeAttributes

// map containing the list of all events grouped by category
var eventTypesByCategory map[string][]*EventDetails

func init() {
	eventTypes = map[EventType]*EventTypeAttributes{}

	eventTypes[ELECTION_STARTED] = &EventTypeAttributes{
		EType:    ELECTION_STARTED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Leader election started in the cluster"}

	eventTypes[ELECTION_CANCELLED] = &EventTypeAttributes{
		EType:    ELECTION_CANCELLED.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "Leader election cancelled"}

	eventTypes[ELECTION_NOTIFICATION_FAILED] = &EventTypeAttributes{
		EType:    ELECTION_NOTIFICATION_FAILED.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "Failed to send leader election notification"}

	eventTypes[ELECTION_STOPPED] = &EventTypeAttributes{
		EType:    ELECTION_STOPPED.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "Leader election stopped"}

	eventTypes[LEADER_ELECTED] = &EventTypeAttributes{
		EType:    LEADER_ELECTED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Leader elected for the cluster"}

	eventTypes[LEADER_LOST] = &EventTypeAttributes{
		EType:    LEADER_LOST.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Node lost leadership during the election"}

	eventTypes[LEADER_CHANGED] = &EventTypeAttributes{
		EType:    LEADER_CHANGED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Leader changed in the election"}

	eventTypes[NODE_JOINED] = &EventTypeAttributes{
		EType:    NODE_JOINED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Node joined the cluster"}

	eventTypes[NODE_DISJOINED] = &EventTypeAttributes{
		EType:    NODE_DISJOINED.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "Node disjoined from the cluster"}

	eventTypes[NODE_HEALTHY] = &EventTypeAttributes{
		EType:    NODE_HEALTHY.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Node is healthy"}

	eventTypes[NODE_UNREACHABLE] = &EventTypeAttributes{
		EType:    NODE_UNREACHABLE.String(),
		Severity: "critical",
		Category: "cluster",
		Desc:     "Node is unreachable"}

	eventTypes[QUORUM_MEMBER_ADD] = &EventTypeAttributes{
		EType:    QUORUM_MEMBER_ADD.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Added member to quorum"}

	eventTypes[QUORUM_MEMBER_REMOVE] = &EventTypeAttributes{
		EType:    QUORUM_MEMBER_REMOVE.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Removed member from quorum"}

	eventTypes[QUORUM_MEMBER_HEALTHY] = &EventTypeAttributes{
		EType:    QUORUM_MEMBER_HEALTHY.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "Quorum member is now healthy"}

	eventTypes[QUORUM_MEMBER_UNHEALTHY] = &EventTypeAttributes{
		EType:    QUORUM_MEMBER_UNHEALTHY.String(),
		Severity: "critical",
		Category: "cluster",
		Desc:     "Quorum member is now unhealthy"}

	eventTypes[UNSUPPORTED_QUORUM_SIZE] = &EventTypeAttributes{
		EType:    UNSUPPORTED_QUORUM_SIZE.String(),
		Severity: "critical",
		Category: "cluster",
		Desc:     "Quorum size is below supported minimum"}

	eventTypes[QUORUM_UNHEALTHY] = &EventTypeAttributes{
		EType:    QUORUM_UNHEALTHY.String(),
		Severity: "critical",
		Category: "cluster",
		Desc:     "Quorum does not have enough healthy members"}

	eventTypes[MODULE_CREATION_FAILED] = &EventTypeAttributes{
		EType:    MODULE_CREATION_FAILED.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "Module creation for diagnostics failed"}

	eventTypes[DSC_ADMITTED] = &EventTypeAttributes{
		EType:    DSC_ADMITTED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "DSC admitted to the cluster"}

	eventTypes[DSC_REJECTED] = &EventTypeAttributes{
		EType:    DSC_REJECTED.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "DSC admission request was rejected"}

	eventTypes[DSC_UNREACHABLE] = &EventTypeAttributes{
		EType:    DSC_UNREACHABLE.String(),
		Severity: "critical",
		Category: "cluster",
		Desc:     "DSC is unreachable"}

	eventTypes[DSC_HEALTHY] = &EventTypeAttributes{
		EType:    DSC_HEALTHY.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "DSC is healthy"}

	eventTypes[DSC_UNHEALTHY] = &EventTypeAttributes{
		EType:    DSC_UNHEALTHY.String(),
		Severity: "critical",
		Category: "cluster",
		Desc:     "DSC is unhealthy"}

	eventTypes[HOST_DSC_SPEC_CONFLICT] = &EventTypeAttributes{
		EType:    HOST_DSC_SPEC_CONFLICT.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "The system has detected a conflict between the DSC specifications of different Host objects"}

	eventTypes[DSC_DEADMITTED] = &EventTypeAttributes{
		EType:    DSC_DEADMITTED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "DSC de-admitted from the cluster"}

	eventTypes[DSC_DECOMMISSIONED] = &EventTypeAttributes{
		EType:    DSC_DECOMMISSIONED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "DSC decommissioned from the cluster"}

	eventTypes[AUTO_GENERATED_TLS_CERT] = &EventTypeAttributes{
		EType:    AUTO_GENERATED_TLS_CERT.String(),
		Severity: "warn",
		Category: "cluster",
		Desc:     "Auto generated certificate is being used for API Gateway TLS"}

	eventTypes[LOGIN_FAILED] = &EventTypeAttributes{
		EType:    LOGIN_FAILED.String(),
		Severity: "info",
		Category: "cluster",
		Desc:     "User login failed"}

	eventTypes[AUDITING_FAILED] = &EventTypeAttributes{
		EType:    AUDITING_FAILED.String(),
		Severity: "critical",
		Category: "cluster",
		Desc:     "Writing of AuditEvent failed"}

	eventTypes[LINK_UP] = &EventTypeAttributes{
		EType:    LINK_UP.String(),
		Severity: "info",
		Category: "network",
		Desc:     "Port is linked up"}

	eventTypes[LINK_DOWN] = &EventTypeAttributes{
		EType:    LINK_DOWN.String(),
		Severity: "warn",
		Category: "network",
		Desc:     "Port link status is down"}

	eventTypes[SERVICE_STARTED] = &EventTypeAttributes{
		EType:    SERVICE_STARTED.String(),
		Severity: "debug",
		Category: "system",
		Desc:     "Service started"}

	eventTypes[SERVICE_STOPPED] = &EventTypeAttributes{
		EType:    SERVICE_STOPPED.String(),
		Severity: "warn",
		Category: "system",
		Desc:     "Service stopped"}

	eventTypes[NAPLES_SERVICE_STOPPED] = &EventTypeAttributes{
		EType:    NAPLES_SERVICE_STOPPED.String(),
		Severity: "critical",
		Category: "system",
		Desc:     "Naples service stopped"}

	eventTypes[SERVICE_PENDING] = &EventTypeAttributes{
		EType:    SERVICE_PENDING.String(),
		Severity: "debug",
		Category: "system",
		Desc:     "Service pending"}

	eventTypes[SERVICE_RUNNING] = &EventTypeAttributes{
		EType:    SERVICE_RUNNING.String(),
		Severity: "debug",
		Category: "system",
		Desc:     "Service running"}

	eventTypes[SERVICE_UNRESPONSIVE] = &EventTypeAttributes{
		EType:    SERVICE_UNRESPONSIVE.String(),
		Severity: "critical",
		Category: "system",
		Desc:     "Service unresponsive due to lack of system resources"}

	eventTypes[SYSTEM_COLDBOOT] = &EventTypeAttributes{
		EType:    SYSTEM_COLDBOOT.String(),
		Severity: "warn",
		Category: "system",
		Desc:     "System cold booted"}

	eventTypes[ROLLOUT_STARTED] = &EventTypeAttributes{
		EType:    ROLLOUT_STARTED.String(),
		Severity: "info",
		Category: "rollout",
		Desc:     "Rollout initiated"}

	eventTypes[ROLLOUT_SUCCESS] = &EventTypeAttributes{
		EType:    ROLLOUT_SUCCESS.String(),
		Severity: "info",
		Category: "rollout",
		Desc:     "Rollout successfully completed"}

	eventTypes[ROLLOUT_FAILED] = &EventTypeAttributes{
		EType:    ROLLOUT_FAILED.String(),
		Severity: "critical",
		Category: "rollout",
		Desc:     "Rollout failed"}

	eventTypes[ROLLOUT_SUSPENDED] = &EventTypeAttributes{
		EType:    ROLLOUT_SUSPENDED.String(),
		Severity: "info",
		Category: "rollout",
		Desc:     "Rollout suspended"}

}

func GetEventTypeAttrs(eType EventType) *EventTypeAttributes {
	if attrs, ok := eventTypes[eType]; ok {
		return attrs
	}

	return nil
}

func GetEventsByCategory() map[string][]*EventDetails {
	var eTypes []string
	for _, eType := range eventTypes {
		eTypes = append(eTypes, eType.EType)
	}
	sort.Strings(eTypes)

	eventTypesByCategory = map[string][]*EventDetails{}
	for _, eTypeStr := range eTypes {
		eType, ok := EventType_value[eTypeStr]
		if ok {
			eAttrs := eventTypes[EventType(eType)]
			eventTypesByCategory[eAttrs.Category] = append(eventTypesByCategory[eAttrs.Category],
				&EventDetails{Name: eAttrs.EType, Desc: eAttrs.Desc, Severity: eAttrs.Severity})
		}
	}

	return eventTypesByCategory
}
