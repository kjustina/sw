/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { ClusterPortCondition } from './cluster-port-condition.model';

export interface IClusterPortStatus {
    'mac-addrs'?: Array<string>;
    'link-speed'?: string;
    'conditions'?: Array<ClusterPortCondition>;
}


export class ClusterPortStatus extends BaseModel implements IClusterPortStatus {
    'mac-addrs': Array<string>;
    'link-speed': string;
    'conditions': Array<ClusterPortCondition>;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['mac-addrs'] = new Array<string>();
        this['conditions'] = new Array<ClusterPortCondition>();
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
            this.fillModelArray<string>(this, 'mac-addrs', values['mac-addrs']);
            this['link-speed'] = values['link-speed'];
            this.fillModelArray<ClusterPortCondition>(this, 'conditions', values['conditions'], ClusterPortCondition);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'mac-addrs': new FormArray([]),
                'link-speed': new FormControl(this['link-speed']),
                'conditions': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('mac-addrs', this['mac-addrs']);
            // generate FormArray control elements
            this.fillFormArray<ClusterPortCondition>('conditions', this['conditions'], ClusterPortCondition);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<string>(this, 'mac-addrs', this['mac-addrs']);
            this._formGroup.controls['link-speed'].setValue(this['link-speed']);
            this.fillModelArray<ClusterPortCondition>(this, 'conditions', this['conditions'], ClusterPortCondition);
        }
    }
}

