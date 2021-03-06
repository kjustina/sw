/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { BaseModel, PropInfoItem } from '../generated/basemodel/base-model';

import { Telemetry_queryMetricsResultSeries, ITelemetry_queryMetricsResultSeries } from './telemetry-query-metrics-result-series.model';

export interface ITelemetry_queryMetricsQueryResult {
    'statement_id'?: number;
    'series'?: Array<ITelemetry_queryMetricsResultSeries>;
}


export class Telemetry_queryMetricsQueryResult extends BaseModel implements ITelemetry_queryMetricsQueryResult {
    'statement_id': number = null;
    'series': Array<Telemetry_queryMetricsResultSeries> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'statement_id': {
            required: true,
            type: 'number'
        },
        'series': {
            required: false,
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return Telemetry_queryMetricsQueryResult.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (Telemetry_queryMetricsQueryResult.propInfo[prop] != null &&
            Telemetry_queryMetricsQueryResult.propInfo[prop].default != null &&
            Telemetry_queryMetricsQueryResult.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['series'] = new Array<Telemetry_queryMetricsResultSeries>();
        this.setValues(values);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['statement_id'] != null) {
            this['statement_id'] = values['statement_id'];
        } else if (fillDefaults && Telemetry_queryMetricsQueryResult.hasDefaultValue('statement_id')) {
            this['statement_id'] = Telemetry_queryMetricsQueryResult.propInfo['statement_id'].default;
        }
        if (values) {
            this.fillModelArray<Telemetry_queryMetricsResultSeries>(this, 'series', values['series'], Telemetry_queryMetricsResultSeries);
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'statement_id': new FormControl(this['statement_id']),
                'series': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<Telemetry_queryMetricsResultSeries>('series', this['series'], Telemetry_queryMetricsResultSeries);
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['statement_id'].setValue(this['statement_id']);
            this.fillModelArray<Telemetry_queryMetricsResultSeries>(this, 'series', this['series'], Telemetry_queryMetricsResultSeries);
        }
    }
}

