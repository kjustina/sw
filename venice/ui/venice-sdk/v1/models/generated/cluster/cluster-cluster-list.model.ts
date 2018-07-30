/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { ClusterCluster, IClusterCluster } from './cluster-cluster.model';

export interface IClusterClusterList {
    'kind'?: string;
    'api-version'?: string;
    'resource-version'?: string;
    'Items'?: Array<IClusterCluster>;
}


export class ClusterClusterList extends BaseModel implements IClusterClusterList {
    'kind': string;
    'api-version': string;
    'resource-version': string;
    'Items': Array<ClusterCluster>;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (ClusterClusterList.enumProperties[prop] != null &&
                        ClusterClusterList.enumProperties[prop].default != null &&
                        ClusterClusterList.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Items'] = new Array<ClusterCluster>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        }
        if (values && values['resource-version'] != null) {
            this['resource-version'] = values['resource-version'];
        }
        if (values) {
            this.fillModelArray<ClusterCluster>(this, 'Items', values['Items'], ClusterCluster);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': new FormControl(this['kind']),
                'api-version': new FormControl(this['api-version']),
                'resource-version': new FormControl(this['resource-version']),
                'Items': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<ClusterCluster>('Items', this['Items'], ClusterCluster);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['api-version'].setValue(this['api-version']);
            this._formGroup.controls['resource-version'].setValue(this['resource-version']);
            this.fillModelArray<ClusterCluster>(this, 'Items', this['Items'], ClusterCluster);
        }
    }
}

