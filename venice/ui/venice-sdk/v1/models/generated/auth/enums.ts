/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */

// generate enum based on strings instead of numbers
// (see https://blog.rsuter.com/how-to-implement-an-enum-with-string-values-in-typescript/)
export enum AuthAuthenticators_authenticator_order {
    'LOCAL' = <any>"LOCAL",
    'LDAP' = <any>"LDAP",
    'RADIUS' = <any>"RADIUS",
}

export enum AuthPermission_resource_kind {
    'ALL_RESOURCE_KINDS' = <any>"ALL_RESOURCE_KINDS",
    'TENANT' = <any>"TENANT",
    'CLUSTER' = <any>"CLUSTER",
    'NODE' = <any>"NODE",
    'SMARTNIC' = <any>"SMARTNIC",
    'CERTIFICATE' = <any>"CERTIFICATE",
    'NETWORK' = <any>"NETWORK",
    'SERVICE' = <any>"SERVICE",
    'LBPOLICY' = <any>"LBPOLICY",
    'ENDPOINT' = <any>"ENDPOINT",
    'SECURITYGROUP' = <any>"SECURITYGROUP",
    'SGPOLICY' = <any>"SGPOLICY",
    'APP' = <any>"APP",
    'ENCRYPTIONPOLICY' = <any>"ENCRYPTIONPOLICY",
    'ALERT' = <any>"ALERT",
    'ALERTPOLICY' = <any>"ALERTPOLICY",
    'ALERTDESTINATION' = <any>"ALERTDESTINATION",
    'EVENTPOLICY' = <any>"EVENTPOLICY",
    'STATSPOLICY' = <any>"STATSPOLICY",
    'FWLOGPOLICY' = <any>"FWLOGPOLICY",
    'FLOWEXPORTPOLICY' = <any>"FLOWEXPORTPOLICY",
    'USER' = <any>"USER",
    'AUTHPOLICY' = <any>"AUTHPOLICY",
    'ROLE' = <any>"ROLE",
    'ROLEBINDING' = <any>"ROLEBINDING",
    'APIENDPOINT' = <any>"APIENDPOINT",
}

export enum AuthPermission_actions {
    'ALL_ACTIONS' = <any>"ALL_ACTIONS",
    'CREATE' = <any>"CREATE",
    'READ' = <any>"READ",
    'UPDATE' = <any>"UPDATE",
    'DELETE' = <any>"DELETE",
    'COMMIT' = <any>"COMMIT",
}

export enum AuthUserSpec_type {
    'LOCAL' = <any>"LOCAL",
    'EXTERNAL' = <any>"EXTERNAL",
}


export enum AuthAuthenticators_authenticator_order_uihint {
    'LOCAL' = <any> "Local",
}

export enum AuthPermission_resource_kind_uihint {
    'ALERT' = <any> "Alert",
    'ALERTDESTINATION' = <any> "AlertDestination",
    'ALERTPOLICY' = <any> "AlertPolicy",
    'ALL_RESOURCE_KINDS' = <any> "All Resource Kinds",
    'APIENDPOINT' = <any> "API Endpoint",
    'APP' = <any> "App",
    'AUTHPOLICY' = <any> "AuthenticationPolicy",
    'CERTIFICATE' = <any> "Certificate",
    'CLUSTER' = <any> "Cluster",
    'ENCRYPTIONPOLICY' = <any> "EncryptionPolicy",
    'ENDPOINT' = <any> "Endpoint",
    'EVENTPOLICY' = <any> "EventPolicy",
    'FLOWEXPORTPOLICY' = <any> "FlowExportPolicy",
    'FWLOGPOLICY' = <any> "FwlogPolicy",
    'LBPOLICY' = <any> "LBPolicy",
    'NETWORK' = <any> "Network",
    'NODE' = <any> "Node",
    'ROLE' = <any> "Role",
    'ROLEBINDING' = <any> "RoleBinding",
    'SECURITYGROUP' = <any> "SecurityGroup",
    'SERVICE' = <any> "Service",
    'SGPOLICY' = <any> "SGPolicy",
    'SMARTNIC' = <any> "SmartNIC",
    'STATSPOLICY' = <any> "StatsPolicy",
    'TENANT' = <any> "Tenant",
    'USER' = <any> "User",
}

export enum AuthPermission_actions_uihint {
    'ALL_ACTIONS' = <any> "All Actions",
    'COMMIT' = <any> "Commit Config",
    'CREATE' = <any> "Create",
    'DELETE' = <any> "Delete",
    'READ' = <any> "Read",
    'UPDATE' = <any> "Update",
}

export enum AuthUserSpec_type_uihint {
    'EXTERNAL' = <any> "External",
    'LOCAL' = <any> "Local",
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

    AuthAuthenticators_authenticator_order = AuthAuthenticators_authenticator_order;
    AuthPermission_resource_kind = AuthPermission_resource_kind;
    AuthPermission_actions = AuthPermission_actions;
    AuthUserSpec_type = AuthUserSpec_type;

    AuthAuthenticators_authenticator_order_uihint = AuthAuthenticators_authenticator_order_uihint;
    AuthPermission_resource_kind_uihint = AuthPermission_resource_kind_uihint;
    AuthPermission_actions_uihint = AuthPermission_actions_uihint;
    AuthUserSpec_type_uihint = AuthUserSpec_type_uihint;
}
