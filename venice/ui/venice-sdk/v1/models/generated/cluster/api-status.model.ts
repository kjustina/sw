/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { ApiStatusResult, IApiStatusResult } from './api-status-result.model';
import { ApiObjectRef, IApiObjectRef } from './api-object-ref.model';

export interface IApiStatus {
    'kind'?: string;
    'api-version'?: string;
    'result'?: IApiStatusResult;
    'message'?: Array<string>;
    'code'?: number;
    'object-ref'?: IApiObjectRef;
}


export class ApiStatus extends BaseModel implements IApiStatus {
    'kind': string = null;
    'api-version': string = null;
    /** Result contains the status of the operation, success or failure. */
    'result': ApiStatusResult = null;
    /** Message contains human readable form of the error. */
    'message': Array<string> = null;
    /** Code is the HTTP status code. */
    'code': number = null;
    /** Reference to the object (optional) for which this status is being sent. */
    'object-ref': ApiObjectRef = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'kind': {
            type: 'string'
                    },
        'api-version': {
            type: 'string'
                    },
        'result': {
            description:  'Result contains the status of the operation, success or failure.',
            type: 'object'
        },
        'message': {
            description:  'Message contains human readable form of the error.',
            type: 'object'
        },
        'code': {
            description:  'Code is the HTTP status code.',
            type: 'number'
                    },
        'object-ref': {
            description:  'Reference to the object (optional) for which this status is being sent.',
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ApiStatus.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ApiStatus.propInfo[prop] != null &&
                        ApiStatus.propInfo[prop].default != null &&
                        ApiStatus.propInfo[prop].default != '');
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
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        } else if (ApiStatus.hasDefaultValue('kind')) {
            this['kind'] = ApiStatus.propInfo['kind'].default;
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        } else if (ApiStatus.hasDefaultValue('api-version')) {
            this['api-version'] = ApiStatus.propInfo['api-version'].default;
        }
        if (values) {
            this['result'].setValues(values['result']);
        }
        if (values) {
            this.fillModelArray<string>(this, 'message', values['message']);
        }
        if (values && values['code'] != null) {
            this['code'] = values['code'];
        } else if (ApiStatus.hasDefaultValue('code')) {
            this['code'] = ApiStatus.propInfo['code'].default;
        }
        if (values) {
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

