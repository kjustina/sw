/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { MonitoringAlertStatus_severity,  MonitoringAlertStatus_severity_uihint  } from './enums';
import { MonitoringAlertSource, IMonitoringAlertSource } from './monitoring-alert-source.model';
import { ApiObjectRef, IApiObjectRef } from './api-object-ref.model';
import { MonitoringAlertReason, IMonitoringAlertReason } from './monitoring-alert-reason.model';
import { MonitoringAuditInfo, IMonitoringAuditInfo } from './monitoring-audit-info.model';

export interface IMonitoringAlertStatus {
    'severity'?: MonitoringAlertStatus_severity;
    'source'?: IMonitoringAlertSource;
    'object-ref'?: IApiObjectRef;
    'message'?: string;
    'reason'?: IMonitoringAlertReason;
    'acknowledged'?: IMonitoringAuditInfo;
    'resolved'?: IMonitoringAuditInfo;
}


export class MonitoringAlertStatus extends BaseModel implements IMonitoringAlertStatus {
    'severity': MonitoringAlertStatus_severity;
    'source': MonitoringAlertSource;
    'object-ref': ApiObjectRef;
    'message': string;
    /** Captures all the requirements from the alert policy rule with matched value.
All these requirements must be cleared to auto-resolve an alert. */
    'reason': MonitoringAlertReason;
    'acknowledged': MonitoringAuditInfo;
    'resolved': MonitoringAuditInfo;
    public static enumProperties: { [key: string] : EnumDef } = {
        'severity': {
            enum: MonitoringAlertStatus_severity_uihint,
            default: 'INFO',
        },
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (MonitoringAlertStatus.enumProperties[prop] != null &&
                        MonitoringAlertStatus.enumProperties[prop].default != null &&
                        MonitoringAlertStatus.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['source'] = new MonitoringAlertSource();
        this['object-ref'] = new ApiObjectRef();
        this['reason'] = new MonitoringAlertReason();
        this['acknowledged'] = new MonitoringAuditInfo();
        this['resolved'] = new MonitoringAuditInfo();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['severity'] != null) {
            this['severity'] = values['severity'];
        } else if (MonitoringAlertStatus.hasDefaultEnumValue('severity')) {
            this['severity'] = <MonitoringAlertStatus_severity> MonitoringAlertStatus.enumProperties['severity'].default;
        }
        if (values) {
            this['source'].setValues(values['source']);
        }
        if (values) {
            this['object-ref'].setValues(values['object-ref']);
        }
        if (values && values['message'] != null) {
            this['message'] = values['message'];
        }
        if (values) {
            this['reason'].setValues(values['reason']);
        }
        if (values) {
            this['acknowledged'].setValues(values['acknowledged']);
        }
        if (values) {
            this['resolved'].setValues(values['resolved']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'severity': new FormControl(this['severity'], [enumValidator(MonitoringAlertStatus_severity), ]),
                'source': this['source'].$formGroup,
                'object-ref': this['object-ref'].$formGroup,
                'message': new FormControl(this['message']),
                'reason': this['reason'].$formGroup,
                'acknowledged': this['acknowledged'].$formGroup,
                'resolved': this['resolved'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['severity'].setValue(this['severity']);
            this['source'].setFormGroupValues();
            this['object-ref'].setFormGroupValues();
            this._formGroup.controls['message'].setValue(this['message']);
            this['reason'].setFormGroupValues();
            this['acknowledged'].setFormGroupValues();
            this['resolved'].setFormGroupValues();
        }
    }
}

