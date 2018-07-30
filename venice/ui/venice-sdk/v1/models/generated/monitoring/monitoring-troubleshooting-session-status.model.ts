/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { MonitoringTroubleshootingSessionStatus_state,  MonitoringTroubleshootingSessionStatus_state_uihint  } from './enums';
import { MonitoringTsResult, IMonitoringTsResult } from './monitoring-ts-result.model';

export interface IMonitoringTroubleshootingSessionStatus {
    'state'?: MonitoringTroubleshootingSessionStatus_state;
    'troubleshooting-results'?: Array<IMonitoringTsResult>;
}


export class MonitoringTroubleshootingSessionStatus extends BaseModel implements IMonitoringTroubleshootingSessionStatus {
    'state': MonitoringTroubleshootingSessionStatus_state;
    'troubleshooting-results': Array<MonitoringTsResult>;
    public static enumProperties: { [key: string] : EnumDef } = {
        'state': {
            enum: MonitoringTroubleshootingSessionStatus_state_uihint,
            default: 'TS_RUNNING',
        },
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (MonitoringTroubleshootingSessionStatus.enumProperties[prop] != null &&
                        MonitoringTroubleshootingSessionStatus.enumProperties[prop].default != null &&
                        MonitoringTroubleshootingSessionStatus.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['troubleshooting-results'] = new Array<MonitoringTsResult>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['state'] != null) {
            this['state'] = values['state'];
        } else if (MonitoringTroubleshootingSessionStatus.hasDefaultEnumValue('state')) {
            this['state'] = <MonitoringTroubleshootingSessionStatus_state> MonitoringTroubleshootingSessionStatus.enumProperties['state'].default;
        }
        if (values) {
            this.fillModelArray<MonitoringTsResult>(this, 'troubleshooting-results', values['troubleshooting-results'], MonitoringTsResult);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'state': new FormControl(this['state'], [enumValidator(MonitoringTroubleshootingSessionStatus_state), ]),
                'troubleshooting-results': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<MonitoringTsResult>('troubleshooting-results', this['troubleshooting-results'], MonitoringTsResult);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['state'].setValue(this['state']);
            this.fillModelArray<MonitoringTsResult>(this, 'troubleshooting-results', this['troubleshooting-results'], MonitoringTsResult);
        }
    }
}

