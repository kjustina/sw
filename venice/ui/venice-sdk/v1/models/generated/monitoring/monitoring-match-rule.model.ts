/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { MonitoringMatchSelector } from './monitoring-match-selector.model';
import { MonitoringAppProtoSelector } from './monitoring-app-proto-selector.model';

export interface IMonitoringMatchRule {
    'source'?: MonitoringMatchSelector;
    'destination'?: MonitoringMatchSelector;
    'app-protocol-selectors'?: MonitoringAppProtoSelector;
}


export class MonitoringMatchRule extends BaseModel implements IMonitoringMatchRule {
    'source': MonitoringMatchSelector;
    'destination': MonitoringMatchSelector;
    'app-protocol-selectors': MonitoringAppProtoSelector;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['source'] = new MonitoringMatchSelector();
        this['destination'] = new MonitoringMatchSelector();
        this['app-protocol-selectors'] = new MonitoringAppProtoSelector();
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
            this['source'].setValues(values['source']);
            this['destination'].setValues(values['destination']);
            this['app-protocol-selectors'].setValues(values['app-protocol-selectors']);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'source': this['source'].$formGroup,
                'destination': this['destination'].$formGroup,
                'app-protocol-selectors': this['app-protocol-selectors'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this['source'].setFormGroupValues();
            this['destination'].setFormGroupValues();
            this['app-protocol-selectors'].setFormGroupValues();
        }
    }
}

