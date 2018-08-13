/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { SecurityAutoMsgSecurityGroupWatchHelperWatchEvent, ISecurityAutoMsgSecurityGroupWatchHelperWatchEvent } from './security-auto-msg-security-group-watch-helper-watch-event.model';

export interface ISecurityAutoMsgSecurityGroupWatchHelper {
    'Events'?: Array<ISecurityAutoMsgSecurityGroupWatchHelperWatchEvent>;
}


export class SecurityAutoMsgSecurityGroupWatchHelper extends BaseModel implements ISecurityAutoMsgSecurityGroupWatchHelper {
    'Events': Array<SecurityAutoMsgSecurityGroupWatchHelperWatchEvent> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'Events': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SecurityAutoMsgSecurityGroupWatchHelper.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SecurityAutoMsgSecurityGroupWatchHelper.propInfo[prop] != null &&
                        SecurityAutoMsgSecurityGroupWatchHelper.propInfo[prop].default != null &&
                        SecurityAutoMsgSecurityGroupWatchHelper.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Events'] = new Array<SecurityAutoMsgSecurityGroupWatchHelperWatchEvent>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<SecurityAutoMsgSecurityGroupWatchHelperWatchEvent>(this, 'Events', values['Events'], SecurityAutoMsgSecurityGroupWatchHelperWatchEvent);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'Events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<SecurityAutoMsgSecurityGroupWatchHelperWatchEvent>('Events', this['Events'], SecurityAutoMsgSecurityGroupWatchHelperWatchEvent);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<SecurityAutoMsgSecurityGroupWatchHelperWatchEvent>(this, 'Events', this['Events'], SecurityAutoMsgSecurityGroupWatchHelperWatchEvent);
        }
    }
}

