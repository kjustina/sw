/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { Telemetry_queryMetricsQuerySpec, ITelemetry_queryMetricsQuerySpec } from './telemetry-query-metrics-query-spec.model';

export interface ITelemetry_queryMetricsQueryList {
    'tenant'?: string;
    'namespace'?: string;
    'queries'?: Array<ITelemetry_queryMetricsQuerySpec>;
}


export class Telemetry_queryMetricsQueryList extends BaseModel implements ITelemetry_queryMetricsQueryList {
    'tenant': string = null;
    'namespace': string = null;
    'queries': Array<Telemetry_queryMetricsQuerySpec> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'tenant': {
            required: false,
            type: 'string'
        },
        'namespace': {
            required: false,
            type: 'string'
        },
        'queries': {
            required: false,
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return Telemetry_queryMetricsQueryList.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return Telemetry_queryMetricsQueryList.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (Telemetry_queryMetricsQueryList.propInfo[prop] != null &&
                        Telemetry_queryMetricsQueryList.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['queries'] = new Array<Telemetry_queryMetricsQuerySpec>();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['tenant'] != null) {
            this['tenant'] = values['tenant'];
        } else if (fillDefaults && Telemetry_queryMetricsQueryList.hasDefaultValue('tenant')) {
            this['tenant'] = Telemetry_queryMetricsQueryList.propInfo['tenant'].default;
        } else {
            this['tenant'] = null
        }
        if (values && values['namespace'] != null) {
            this['namespace'] = values['namespace'];
        } else if (fillDefaults && Telemetry_queryMetricsQueryList.hasDefaultValue('namespace')) {
            this['namespace'] = Telemetry_queryMetricsQueryList.propInfo['namespace'].default;
        } else {
            this['namespace'] = null
        }
        if (values) {
            this.fillModelArray<Telemetry_queryMetricsQuerySpec>(this, 'queries', values['queries'], Telemetry_queryMetricsQuerySpec);
        } else {
            this['queries'] = [];
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'tenant': CustomFormControl(new FormControl(this['tenant']), Telemetry_queryMetricsQueryList.propInfo['tenant']),
                'namespace': CustomFormControl(new FormControl(this['namespace']), Telemetry_queryMetricsQueryList.propInfo['namespace']),
                'queries': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<Telemetry_queryMetricsQuerySpec>('queries', this['queries'], Telemetry_queryMetricsQuerySpec);
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('queries') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('queries').get(field);
                control.updateValueAndValidity();
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['tenant'].setValue(this['tenant']);
            this._formGroup.controls['namespace'].setValue(this['namespace']);
            this.fillModelArray<Telemetry_queryMetricsQuerySpec>(this, 'queries', this['queries'], Telemetry_queryMetricsQuerySpec);
        }
    }
}

