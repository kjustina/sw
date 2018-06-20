/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { ApiObjectMeta } from './api-object-meta.model';
import { MonitoringEventPolicySpec } from './monitoring-event-policy-spec.model';
import { MonitoringEventPolicyStatus } from './monitoring-event-policy-status.model';

export interface IMonitoringEventPolicy {
    'kind'?: string;
    'api-version'?: string;
    'meta'?: ApiObjectMeta;
    'spec'?: MonitoringEventPolicySpec;
    'status'?: MonitoringEventPolicyStatus;
}


export class MonitoringEventPolicy extends BaseModel implements IMonitoringEventPolicy {
    'kind': string;
    'api-version': string;
    'meta': ApiObjectMeta;
    /** Spec contains the configuration of an event policy. */
    'spec': MonitoringEventPolicySpec;
    /** Status contains the current state of an event policy. */
    'status': MonitoringEventPolicyStatus;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['meta'] = new ApiObjectMeta();
        this['spec'] = new MonitoringEventPolicySpec();
        this['status'] = new MonitoringEventPolicyStatus();
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
            this['kind'] = values['kind'];
            this['api-version'] = values['api-version'];
            this['meta'].setValues(values['meta']);
            this['spec'].setValues(values['spec']);
            this['status'].setValues(values['status']);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': new FormControl(this['kind']),
                'api-version': new FormControl(this['api-version']),
                'meta': this['meta'].$formGroup,
                'spec': this['spec'].$formGroup,
                'status': this['status'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['api-version'].setValue(this['api-version']);
            this['meta'].setFormGroupValues();
            this['spec'].setFormGroupValues();
            this['status'].setFormGroupValues();
        }
    }
}

