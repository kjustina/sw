/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { MonitoringMatchedRequirement, IMonitoringMatchedRequirement } from './monitoring-matched-requirement.model';

export interface IMonitoringAlertReason {
    'matched-requirements'?: Array<IMonitoringMatchedRequirement>;
    'alert-policy-id'?: string;
}


export class MonitoringAlertReason extends BaseModel implements IMonitoringAlertReason {
    'matched-requirements': Array<MonitoringMatchedRequirement>;
    'alert-policy-id': string;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (MonitoringAlertReason.enumProperties[prop] != null &&
                        MonitoringAlertReason.enumProperties[prop].default != null &&
                        MonitoringAlertReason.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['matched-requirements'] = new Array<MonitoringMatchedRequirement>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<MonitoringMatchedRequirement>(this, 'matched-requirements', values['matched-requirements'], MonitoringMatchedRequirement);
        }
        if (values && values['alert-policy-id'] != null) {
            this['alert-policy-id'] = values['alert-policy-id'];
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'matched-requirements': new FormArray([]),
                'alert-policy-id': new FormControl(this['alert-policy-id']),
            });
            // generate FormArray control elements
            this.fillFormArray<MonitoringMatchedRequirement>('matched-requirements', this['matched-requirements'], MonitoringMatchedRequirement);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<MonitoringMatchedRequirement>(this, 'matched-requirements', this['matched-requirements'], MonitoringMatchedRequirement);
            this._formGroup.controls['alert-policy-id'].setValue(this['alert-policy-id']);
        }
    }
}

