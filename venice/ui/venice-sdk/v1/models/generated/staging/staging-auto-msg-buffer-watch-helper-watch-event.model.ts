/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { StagingBuffer, IStagingBuffer } from './staging-buffer.model';

export interface IStagingAutoMsgBufferWatchHelperWatchEvent {
    'type'?: string;
    'object'?: IStagingBuffer;
}


export class StagingAutoMsgBufferWatchHelperWatchEvent extends BaseModel implements IStagingAutoMsgBufferWatchHelperWatchEvent {
    'type': string = null;
    'object': StagingBuffer = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'type': {
            type: 'string'
        },
        'object': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return StagingAutoMsgBufferWatchHelperWatchEvent.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (StagingAutoMsgBufferWatchHelperWatchEvent.propInfo[prop] != null &&
                        StagingAutoMsgBufferWatchHelperWatchEvent.propInfo[prop].default != null &&
                        StagingAutoMsgBufferWatchHelperWatchEvent.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['object'] = new StagingBuffer();
        this.setValues(values);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['type'] != null) {
            this['type'] = values['type'];
        } else if (fillDefaults && StagingAutoMsgBufferWatchHelperWatchEvent.hasDefaultValue('type')) {
            this['type'] = StagingAutoMsgBufferWatchHelperWatchEvent.propInfo['type'].default;
        }
        if (values) {
            this['object'].setValues(values['object']);
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'type': new FormControl(this['type']),
                'object': this['object'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['type'].setValue(this['type']);
            this['object'].setFormGroupValuesToBeModelValues();
        }
    }
}

