/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';


export interface INetworkNetworkStatus {
    'workloads'?: Array<string>;
    'allocated-ipv4-addrs'?: string;
}


export class NetworkNetworkStatus extends BaseModel implements INetworkNetworkStatus {
    'workloads': Array<string>;
    'allocated-ipv4-addrs': string;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['workloads'] = new Array<string>();
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
            this.fillModelArray<string>(this, 'workloads', values['workloads']);
            this['allocated-ipv4-addrs'] = values['allocated-ipv4-addrs'];
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'workloads': new FormArray([]),
                'allocated-ipv4-addrs': new FormControl(this['allocated-ipv4-addrs']),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('workloads', this['workloads']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<string>(this, 'workloads', this['workloads']);
            this._formGroup.controls['allocated-ipv4-addrs'].setValue(this['allocated-ipv4-addrs']);
        }
    }
}

