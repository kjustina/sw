/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { SecurityApp, ISecurityApp } from './security-app.model';

export interface ISecurityAutoMsgAppWatchHelperWatchEvent {
    'Type'?: string;
    'Object'?: ISecurityApp;
}


export class SecurityAutoMsgAppWatchHelperWatchEvent extends BaseModel implements ISecurityAutoMsgAppWatchHelperWatchEvent {
    'Type': string = null;
    'Object': SecurityApp = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'Type': {
            type: 'string'
                    },
        'Object': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SecurityAutoMsgAppWatchHelperWatchEvent.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SecurityAutoMsgAppWatchHelperWatchEvent.propInfo[prop] != null &&
                        SecurityAutoMsgAppWatchHelperWatchEvent.propInfo[prop].default != null &&
                        SecurityAutoMsgAppWatchHelperWatchEvent.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Object'] = new SecurityApp();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['Type'] != null) {
            this['Type'] = values['Type'];
        } else if (SecurityAutoMsgAppWatchHelperWatchEvent.hasDefaultValue('Type')) {
            this['Type'] = SecurityAutoMsgAppWatchHelperWatchEvent.propInfo['Type'].default;
        }
        if (values) {
            this['Object'].setValues(values['Object']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'Type': new FormControl(this['Type']),
                'Object': this['Object'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['Type'].setValue(this['Type']);
            this['Object'].setFormGroupValues();
        }
    }
}

