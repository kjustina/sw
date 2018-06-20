/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { ApiStatusResult } from './api-status-result.model';
import { ApiObjectRef } from './api-object-ref.model';

export interface IApiStatus {
    'kind'?: string;
    'api-version'?: string;
    'result'?: ApiStatusResult;
    'message'?: Array<string>;
    'code'?: number;
    'object-ref'?: ApiObjectRef;
}


export class ApiStatus extends BaseModel implements IApiStatus {
    'kind': string;
    'api-version': string;
    /** Result contains the status of the operation, success or failure. */
    'result': ApiStatusResult;
    /** Message contains human readable form of the error. */
    'message': Array<string>;
    /** Code is the HTTP status code. */
    'code': number;
    /** Reference to the object (optional) for which this status is being sent. */
    'object-ref': ApiObjectRef;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['result'] = new ApiStatusResult();
        this['message'] = new Array<string>();
        this['object-ref'] = new ApiObjectRef();
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
            this['result'].setValues(values['result']);
            this.fillModelArray<string>(this, 'message', values['message']);
            this['code'] = values['code'];
            this['object-ref'].setValues(values['object-ref']);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': new FormControl(this['kind']),
                'api-version': new FormControl(this['api-version']),
                'result': this['result'].$formGroup,
                'message': new FormArray([]),
                'code': new FormControl(this['code']),
                'object-ref': this['object-ref'].$formGroup,
            });
            // generate FormArray control elements
            this.fillFormArray<string>('message', this['message']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['api-version'].setValue(this['api-version']);
            this['result'].setFormGroupValues();
            this.fillModelArray<string>(this, 'message', this['message']);
            this._formGroup.controls['code'].setValue(this['code']);
            this['object-ref'].setFormGroupValues();
        }
    }
}

