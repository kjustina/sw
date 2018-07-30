/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { MonitoringFlowExportTarget_format,  } from './enums';
import { ApiExportConfig, IApiExportConfig } from './api-export-config.model';

export interface IMonitoringFlowExportTarget {
    'interval'?: string;
    'format'?: MonitoringFlowExportTarget_format;
    'exports'?: Array<IApiExportConfig>;
}


export class MonitoringFlowExportTarget extends BaseModel implements IMonitoringFlowExportTarget {
    'interval': string;
    'format': MonitoringFlowExportTarget_format;
    /** Export contains export parameters. */
    'exports': Array<ApiExportConfig>;
    public static enumProperties: { [key: string] : EnumDef } = {
        'format': {
            enum: MonitoringFlowExportTarget_format,
            default: 'Ipfix',
        },
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (MonitoringFlowExportTarget.enumProperties[prop] != null &&
                        MonitoringFlowExportTarget.enumProperties[prop].default != null &&
                        MonitoringFlowExportTarget.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['exports'] = new Array<ApiExportConfig>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['interval'] != null) {
            this['interval'] = values['interval'];
        }
        if (values && values['format'] != null) {
            this['format'] = values['format'];
        } else if (MonitoringFlowExportTarget.hasDefaultEnumValue('format')) {
            this['format'] = <MonitoringFlowExportTarget_format> MonitoringFlowExportTarget.enumProperties['format'].default;
        }
        if (values) {
            this.fillModelArray<ApiExportConfig>(this, 'exports', values['exports'], ApiExportConfig);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'interval': new FormControl(this['interval']),
                'format': new FormControl(this['format'], [enumValidator(MonitoringFlowExportTarget_format), ]),
                'exports': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<ApiExportConfig>('exports', this['exports'], ApiExportConfig);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['interval'].setValue(this['interval']);
            this._formGroup.controls['format'].setValue(this['format']);
            this.fillModelArray<ApiExportConfig>(this, 'exports', this['exports'], ApiExportConfig);
        }
    }
}

