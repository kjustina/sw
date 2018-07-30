/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';


export interface INetworkServiceStatus {
    'workloads'?: Array<string>;
}


export class NetworkServiceStatus extends BaseModel implements INetworkServiceStatus {
    'workloads': Array<string>;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (NetworkServiceStatus.enumProperties[prop] != null &&
                        NetworkServiceStatus.enumProperties[prop].default != null &&
                        NetworkServiceStatus.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['workloads'] = new Array<string>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<string>(this, 'workloads', values['workloads']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'workloads': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('workloads', this['workloads']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<string>(this, 'workloads', this['workloads']);
        }
    }
}

