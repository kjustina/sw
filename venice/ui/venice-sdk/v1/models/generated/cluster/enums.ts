/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */

// generate enum based on strings instead of numbers
// (see https://blog.rsuter.com/how-to-implement-an-enum-with-string-values-in-typescript/)
export enum ConfigurationSnapshotStatusConfigSaveStatus_dest_type {
    'objectstore' = "objectstore",
}

export enum ApiListWatchOptions_sort_order {
    'none' = "none",
    'by-name' = "by-name",
    'by-name-reverse' = "by-name-reverse",
    'by-version' = "by-version",
    'by-version-reverse' = "by-version-reverse",
    'by-creation-time' = "by-creation-time",
    'by-creation-time-reverse' = "by-creation-time-reverse",
    'by-mod-time' = "by-mod-time",
    'by-mod-time-reverse' = "by-mod-time-reverse",
}

export enum ClusterClusterCondition_type {
    'healthy' = "healthy",
}

export enum ClusterClusterCondition_status {
    'unknown' = "unknown",
    'true' = "true",
    'false' = "false",
}

export enum ClusterDSCCondition_type {
    'healthy' = "healthy",
    'nic_health_unknown' = "nic_health_unknown",
    'reboot_needed' = "reboot_needed",
}

export enum ClusterDSCCondition_status {
    'unknown' = "unknown",
    'true' = "true",
    'false' = "false",
}

export enum ClusterDSCProfileSpec_fwd_mode {
    'transparent' = "transparent",
    'insertion' = "insertion",
}

export enum ClusterDSCProfileSpec_policy_mode {
    'basenet' = "basenet",
    'flowaware' = "flowaware",
    'enforced' = "enforced",
}

export enum ClusterDistributedServiceCardSpec_mgmt_mode {
    'host' = "host",
    'network' = "network",
}

export enum ClusterDistributedServiceCardSpec_network_mode {
    'oob' = "oob",
    'inband' = "inband",
}

export enum ClusterDistributedServiceCardStatus_admission_phase {
    'unknown' = "unknown",
    'registering' = "registering",
    'rejected' = "rejected",
    'pending' = "pending",
    'admitted' = "admitted",
    'decommissioned' = "decommissioned",
}

export enum ClusterMemInfo_type {
    'unknown' = "unknown",
    'hbm' = "hbm",
    'ddr' = "ddr",
}

export enum ClusterNodeCondition_type {
    'leader' = "leader",
    'healthy' = "healthy",
}

export enum ClusterNodeCondition_status {
    'unknown' = "unknown",
    'true' = "true",
    'false' = "false",
}

export enum ClusterNodeStatus_phase {
    'unknown' = "unknown",
    'pending' = "pending",
    'joined' = "joined",
    'failed' = "failed",
}

export enum ClusterQuorumMemberCondition_type {
    'healthy' = "healthy",
}

export enum ClusterQuorumMemberCondition_status {
    'unknown' = "unknown",
    'true' = "true",
    'false' = "false",
}

export enum ClusterSnapshotDestination_Type {
    'objectstore' = "objectstore",
}

export enum ClusterSnapshotRestoreStatus_status {
    'unknown' = "unknown",
    'active' = "active",
    'completed' = "completed",
    'failed' = "failed",
}


export enum ApiListWatchOptions_sort_order_uihint {
    'by-creation-time' = "By Creation Time",
    'by-creation-time-reverse' = "By Creation Time Reverse",
    'by-mod-time' = "By Modification Time",
    'by-mod-time-reverse' = "By Modification Time Reverse",
    'by-name' = "By Name",
    'by-name-reverse' = "By Name Reverse",
    'by-version' = "By Version",
    'by-version-reverse' = "By Version Reverse",
    'none' = "None",
}

export enum ClusterClusterCondition_type_uihint {
    'healthy' = "Healthy",
}

export enum ClusterClusterCondition_status_uihint {
    'false' = "False",
    'true' = "True",
    'unknown' = "Unknown",
}

export enum ClusterDSCCondition_type_uihint {
    'healthy' = "Healthy",
    'nic_health_unknown' = "Not Reachable",
    'reboot_needed' = "Reboot needed",
}

export enum ClusterDSCCondition_status_uihint {
    'false' = "False",
    'true' = "True",
    'unknown' = "Unknown",
}

export enum ClusterDistributedServiceCardSpec_mgmt_mode_uihint {
    'host' = "Host",
    'network' = "Network",
}

export enum ClusterDistributedServiceCardSpec_network_mode_uihint {
    'inband' = "Inband",
    'oob' = "Out of Band",
}

export enum ClusterDistributedServiceCardStatus_admission_phase_uihint {
    'admitted' = "Admitted",
    'decommissioned' = "Decommissioned",
    'pending' = "Pending",
    'registering' = "Registering",
    'rejected' = "Rejected",
    'unknown' = "Unknown",
}

export enum ClusterNodeCondition_type_uihint {
    'healthy' = "Healthy",
    'leader' = "Leader",
}

export enum ClusterNodeCondition_status_uihint {
    'false' = "False",
    'true' = "True",
    'unknown' = "Unknown",
}

export enum ClusterNodeStatus_phase_uihint {
    'failed' = "Failed",
    'joined' = "Joined",
    'pending' = "Pending",
    'unknown' = "Unknown",
}

export enum ClusterQuorumMemberCondition_type_uihint {
    'healthy' = "Healthy",
}

export enum ClusterQuorumMemberCondition_status_uihint {
    'false' = "False",
    'true' = "True",
    'unknown' = "Unknown",
}




/**
 * bundle of all enums for databinding to options, radio-buttons etc.
 * usage in component:
 *   import { AllEnums, minValueValidator, maxValueValidator } from '../../models/webapi';
 *
 *   @Component({
 *       ...
 *   })
 *   export class xxxComponent implements OnInit {
 *       allEnums = AllEnums;
 *       ...
 *       ngOnInit() {
 *           this.allEnums = AllEnums.instance;
 *       }
 *   }
*/
export class AllEnums {
    private static _instance: AllEnums = new AllEnums();
    constructor() {
        if (AllEnums._instance) {
            throw new Error("Error: Instantiation failed: Use AllEnums.instance instead of new");
        }
        AllEnums._instance = this;
    }
    static get instance(): AllEnums {
        return AllEnums._instance;
    }

    ConfigurationSnapshotStatusConfigSaveStatus_dest_type = ConfigurationSnapshotStatusConfigSaveStatus_dest_type;
    ApiListWatchOptions_sort_order = ApiListWatchOptions_sort_order;
    ClusterClusterCondition_type = ClusterClusterCondition_type;
    ClusterClusterCondition_status = ClusterClusterCondition_status;
    ClusterDSCCondition_type = ClusterDSCCondition_type;
    ClusterDSCCondition_status = ClusterDSCCondition_status;
    ClusterDSCProfileSpec_fwd_mode = ClusterDSCProfileSpec_fwd_mode;
    ClusterDSCProfileSpec_policy_mode = ClusterDSCProfileSpec_policy_mode;
    ClusterDistributedServiceCardSpec_mgmt_mode = ClusterDistributedServiceCardSpec_mgmt_mode;
    ClusterDistributedServiceCardSpec_network_mode = ClusterDistributedServiceCardSpec_network_mode;
    ClusterDistributedServiceCardStatus_admission_phase = ClusterDistributedServiceCardStatus_admission_phase;
    ClusterMemInfo_type = ClusterMemInfo_type;
    ClusterNodeCondition_type = ClusterNodeCondition_type;
    ClusterNodeCondition_status = ClusterNodeCondition_status;
    ClusterNodeStatus_phase = ClusterNodeStatus_phase;
    ClusterQuorumMemberCondition_type = ClusterQuorumMemberCondition_type;
    ClusterQuorumMemberCondition_status = ClusterQuorumMemberCondition_status;
    ClusterSnapshotDestination_Type = ClusterSnapshotDestination_Type;
    ClusterSnapshotRestoreStatus_status = ClusterSnapshotRestoreStatus_status;

    ApiListWatchOptions_sort_order_uihint = ApiListWatchOptions_sort_order_uihint;
    ClusterClusterCondition_type_uihint = ClusterClusterCondition_type_uihint;
    ClusterClusterCondition_status_uihint = ClusterClusterCondition_status_uihint;
    ClusterDSCCondition_type_uihint = ClusterDSCCondition_type_uihint;
    ClusterDSCCondition_status_uihint = ClusterDSCCondition_status_uihint;
    ClusterDistributedServiceCardSpec_mgmt_mode_uihint = ClusterDistributedServiceCardSpec_mgmt_mode_uihint;
    ClusterDistributedServiceCardSpec_network_mode_uihint = ClusterDistributedServiceCardSpec_network_mode_uihint;
    ClusterDistributedServiceCardStatus_admission_phase_uihint = ClusterDistributedServiceCardStatus_admission_phase_uihint;
    ClusterNodeCondition_type_uihint = ClusterNodeCondition_type_uihint;
    ClusterNodeCondition_status_uihint = ClusterNodeCondition_status_uihint;
    ClusterNodeStatus_phase_uihint = ClusterNodeStatus_phase_uihint;
    ClusterQuorumMemberCondition_type_uihint = ClusterQuorumMemberCondition_type_uihint;
    ClusterQuorumMemberCondition_status_uihint = ClusterQuorumMemberCondition_status_uihint;
}
