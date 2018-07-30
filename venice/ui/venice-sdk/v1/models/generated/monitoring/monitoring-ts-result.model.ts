/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { MonitoringTimeWindow, IMonitoringTimeWindow } from './monitoring-time-window.model';

export interface IMonitoringTsResult {
    'time-window'?: IMonitoringTimeWindow;
    'report-url'?: string;
}


export class MonitoringTsResult extends BaseModel implements IMonitoringTsResult {
    'time-window': MonitoringTimeWindow;
    'report-url': string;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (MonitoringTsResult.enumProperties[prop] != null &&
                        MonitoringTsResult.enumProperties[prop].default != null &&
                        MonitoringTsResult.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['time-window'] = new MonitoringTimeWindow();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this['time-window'].setValues(values['time-window']);
        }
        if (values && values['report-url'] != null) {
            this['report-url'] = values['report-url'];
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'time-window': this['time-window'].$formGroup,
                'report-url': new FormControl(this['report-url']),
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this['time-window'].setFormGroupValues();
            this._formGroup.controls['report-url'].setValue(this['report-url']);
        }
    }
}

