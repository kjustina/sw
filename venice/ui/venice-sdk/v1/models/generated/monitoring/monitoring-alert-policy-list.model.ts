/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { MonitoringAlertPolicy, IMonitoringAlertPolicy } from './monitoring-alert-policy.model';

export interface IMonitoringAlertPolicyList {
    'kind'?: string;
    'api-version'?: string;
    'resource-version'?: string;
    'Items'?: Array<IMonitoringAlertPolicy>;
}


export class MonitoringAlertPolicyList extends BaseModel implements IMonitoringAlertPolicyList {
    'kind': string = null;
    'api-version': string = null;
    'resource-version': string = null;
    'Items': Array<MonitoringAlertPolicy> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'kind': {
            type: 'string'
                    },
        'api-version': {
            type: 'string'
                    },
        'resource-version': {
            type: 'string'
                    },
        'Items': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return MonitoringAlertPolicyList.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (MonitoringAlertPolicyList.propInfo[prop] != null &&
                        MonitoringAlertPolicyList.propInfo[prop].default != null &&
                        MonitoringAlertPolicyList.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Items'] = new Array<MonitoringAlertPolicy>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        } else if (MonitoringAlertPolicyList.hasDefaultValue('kind')) {
            this['kind'] = MonitoringAlertPolicyList.propInfo['kind'].default;
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        } else if (MonitoringAlertPolicyList.hasDefaultValue('api-version')) {
            this['api-version'] = MonitoringAlertPolicyList.propInfo['api-version'].default;
        }
        if (values && values['resource-version'] != null) {
            this['resource-version'] = values['resource-version'];
        } else if (MonitoringAlertPolicyList.hasDefaultValue('resource-version')) {
            this['resource-version'] = MonitoringAlertPolicyList.propInfo['resource-version'].default;
        }
        if (values) {
            this.fillModelArray<MonitoringAlertPolicy>(this, 'Items', values['Items'], MonitoringAlertPolicy);
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
            this.fillFormArray<MonitoringAlertPolicy>('Items', this['Items'], MonitoringAlertPolicy);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['api-version'].setValue(this['api-version']);
            this._formGroup.controls['resource-version'].setValue(this['resource-version']);
            this.fillModelArray<MonitoringAlertPolicy>(this, 'Items', this['Items'], MonitoringAlertPolicy);
        }
    }
}

