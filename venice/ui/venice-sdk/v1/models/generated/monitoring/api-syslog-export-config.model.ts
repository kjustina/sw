/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';


export interface IApiSyslogExportConfig {
    'facility-override'?: string;
    'prefix'?: string;
}


export class ApiSyslogExportConfig extends BaseModel implements IApiSyslogExportConfig {
    'facility-override': string;
    'prefix': string;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
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
            this['facility-override'] = values['facility-override'];
            this['prefix'] = values['prefix'];
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'facility-override': new FormControl(this['facility-override']),
                'prefix': new FormControl(this['prefix']),
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['facility-override'].setValue(this['facility-override']);
            this._formGroup.controls['prefix'].setValue(this['prefix']);
        }
    }
}

