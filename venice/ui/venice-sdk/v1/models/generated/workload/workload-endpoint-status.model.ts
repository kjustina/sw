/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';


export interface IWorkloadEndpointStatus {
    'endpoint-uuid'?: string;
    'workload-uuid'?: string;
    'workload-name'?: string;
    'network'?: string;
    'homing-host-addr'?: string;
    'homing-host-name'?: string;
    'ipv4-address'?: string;
    'ipv4-gateway'?: string;
    'ipv6-address'?: string;
    'ipv6-gateway'?: string;
    'mac-address'?: string;
    'node-uuid'?: string;
    'EndpointState'?: string;
    'SecurityGroups'?: Array<string>;
    'micro-segment-vlan'?: number;
    'workload-attributes'?: object;
}


export class WorkloadEndpointStatus extends BaseModel implements IWorkloadEndpointStatus {
    'endpoint-uuid': string;
    'workload-uuid': string;
    'workload-name': string;
    'network': string;
    'homing-host-addr': string;
    'homing-host-name': string;
    'ipv4-address': string;
    'ipv4-gateway': string;
    'ipv6-address': string;
    'ipv6-gateway': string;
    'mac-address': string;
    'node-uuid': string;
    'EndpointState': string;
    'SecurityGroups': Array<string>;
    'micro-segment-vlan': number;
    'workload-attributes': object;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['SecurityGroups'] = new Array<string>();
        if (values) {
            this.setValues(values);
        }
    }

    /**
     * set the values.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this['endpoint-uuid'] = values['endpoint-uuid'];
            this['workload-uuid'] = values['workload-uuid'];
            this['workload-name'] = values['workload-name'];
            this['network'] = values['network'];
            this['homing-host-addr'] = values['homing-host-addr'];
            this['homing-host-name'] = values['homing-host-name'];
            this['ipv4-address'] = values['ipv4-address'];
            this['ipv4-gateway'] = values['ipv4-gateway'];
            this['ipv6-address'] = values['ipv6-address'];
            this['ipv6-gateway'] = values['ipv6-gateway'];
            this['mac-address'] = values['mac-address'];
            this['node-uuid'] = values['node-uuid'];
            this['EndpointState'] = values['EndpointState'];
            this.fillModelArray<string>(this, 'SecurityGroups', values['SecurityGroups']);
            this['micro-segment-vlan'] = values['micro-segment-vlan'];
            this['workload-attributes'] = values['workload-attributes'];
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'endpoint-uuid': new FormControl(this['endpoint-uuid']),
                'workload-uuid': new FormControl(this['workload-uuid']),
                'workload-name': new FormControl(this['workload-name']),
                'network': new FormControl(this['network']),
                'homing-host-addr': new FormControl(this['homing-host-addr']),
                'homing-host-name': new FormControl(this['homing-host-name']),
                'ipv4-address': new FormControl(this['ipv4-address']),
                'ipv4-gateway': new FormControl(this['ipv4-gateway']),
                'ipv6-address': new FormControl(this['ipv6-address']),
                'ipv6-gateway': new FormControl(this['ipv6-gateway']),
                'mac-address': new FormControl(this['mac-address']),
                'node-uuid': new FormControl(this['node-uuid']),
                'EndpointState': new FormControl(this['EndpointState']),
                'SecurityGroups': new FormArray([]),
                'micro-segment-vlan': new FormControl(this['micro-segment-vlan']),
                'workload-attributes': new FormControl(this['workload-attributes']),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('SecurityGroups', this['SecurityGroups']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['endpoint-uuid'].setValue(this['endpoint-uuid']);
            this._formGroup.controls['workload-uuid'].setValue(this['workload-uuid']);
            this._formGroup.controls['workload-name'].setValue(this['workload-name']);
            this._formGroup.controls['network'].setValue(this['network']);
            this._formGroup.controls['homing-host-addr'].setValue(this['homing-host-addr']);
            this._formGroup.controls['homing-host-name'].setValue(this['homing-host-name']);
            this._formGroup.controls['ipv4-address'].setValue(this['ipv4-address']);
            this._formGroup.controls['ipv4-gateway'].setValue(this['ipv4-gateway']);
            this._formGroup.controls['ipv6-address'].setValue(this['ipv6-address']);
            this._formGroup.controls['ipv6-gateway'].setValue(this['ipv6-gateway']);
            this._formGroup.controls['mac-address'].setValue(this['mac-address']);
            this._formGroup.controls['node-uuid'].setValue(this['node-uuid']);
            this._formGroup.controls['EndpointState'].setValue(this['EndpointState']);
            this.fillModelArray<string>(this, 'SecurityGroups', this['SecurityGroups']);
            this._formGroup.controls['micro-segment-vlan'].setValue(this['micro-segment-vlan']);
            this._formGroup.controls['workload-attributes'].setValue(this['workload-attributes']);
        }
    }
}

