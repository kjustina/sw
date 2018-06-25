/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */

// generate enum based on strings instead of numbers
// (see https://blog.rsuter.com/how-to-implement-an-enum-with-string-values-in-typescript/)
export enum FieldsRequirement_operator {
    'equals' = <any>"equals",
    'notEquals' = <any>"notEquals",
    'in' = <any>"in",
    'notIn' = <any>"notIn",
    'gt' = <any>"gt",
    'gte' = <any>"gte",
    'lt' = <any>"lt",
    'lte' = <any>"lte",
}

export enum LabelsRequirement_operator {
    'equals' = <any>"equals",
    'notEquals' = <any>"notEquals",
    'in' = <any>"in",
    'notIn' = <any>"notIn",
}

export enum SearchSearchQuery_categories {
    'Cluster' = <any>"Cluster",
    'Workload' = <any>"Workload",
    'Security' = <any>"Security",
    'Auth' = <any>"Auth",
    'Network' = <any>"Network",
    'Monitoring' = <any>"Monitoring",
    'Telemetry' = <any>"Telemetry",
    'Events' = <any>"Events",
    'Alerts' = <any>"Alerts",
    'AuditTrail' = <any>"AuditTrail",
}

export enum SearchSearchQuery_kinds {
    'Cluster' = <any>"Cluster",
    'Node' = <any>"Node",
    'SmartNIC' = <any>"SmartNIC",
    'Rollout' = <any>"Rollout",
    'Tenant' = <any>"Tenant",
    'Endpoint' = <any>"Endpoint",
    'SecurityGroup' = <any>"SecurityGroup",
    'Sgpolicy' = <any>"Sgpolicy",
    'App' = <any>"App",
    'AppUser' = <any>"AppUser",
    'AppUserGrp' = <any>"AppUserGrp",
    'Certificate' = <any>"Certificate",
    'TrafficEncryptionPolicy' = <any>"TrafficEncryptionPolicy",
    'User' = <any>"User",
    'AuthenticationPolicy' = <any>"AuthenticationPolicy",
    'Role' = <any>"Role",
    'RoleBinding' = <any>"RoleBinding",
    'Network' = <any>"Network",
    'Service' = <any>"Service",
    'LbPolicy' = <any>"LbPolicy",
    'Alert' = <any>"Alert",
    'AlertDestination' = <any>"AlertDestination",
    'AlertPolicy' = <any>"AlertPolicy",
    'Event' = <any>"Event",
    'EventPolicy' = <any>"EventPolicy",
    'StatsPolicy' = <any>"StatsPolicy",
    'FlowExportPolicy' = <any>"FlowExportPolicy",
    'FwlogPolicy' = <any>"FwlogPolicy",
    'MirrorSession' = <any>"MirrorSession",
}

export enum SearchSearchRequest_mode {
    'Full' = <any>"Full",
    'Preview' = <any>"Preview",
}


export enum FieldsRequirement_operator_uihint {
    'gt' = <any> "greater than",
    'gte' = <any> "greater than or equals",
    'lt' = <any> "less than",
    'lte' = <any> "less than or equals",
    'notEquals' = <any> "not equals",
    'notIn' = <any> "not in",
}

export enum LabelsRequirement_operator_uihint {
    'notEquals' = <any> "not equals",
    'notIn' = <any> "not in",
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

    FieldsRequirement_operator = FieldsRequirement_operator;
    LabelsRequirement_operator = LabelsRequirement_operator;
    SearchSearchQuery_categories = SearchSearchQuery_categories;
    SearchSearchQuery_kinds = SearchSearchQuery_kinds;
    SearchSearchRequest_mode = SearchSearchRequest_mode;

    FieldsRequirement_operator_uihint = FieldsRequirement_operator_uihint;
    LabelsRequirement_operator_uihint = LabelsRequirement_operator_uihint;
}
