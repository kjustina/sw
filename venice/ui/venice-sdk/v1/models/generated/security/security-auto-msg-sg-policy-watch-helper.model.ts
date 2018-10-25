/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { SecurityAutoMsgSGPolicyWatchHelperWatchEvent, ISecurityAutoMsgSGPolicyWatchHelperWatchEvent } from './security-auto-msg-sg-policy-watch-helper-watch-event.model';

export interface ISecurityAutoMsgSGPolicyWatchHelper {
    'events'?: Array<ISecurityAutoMsgSGPolicyWatchHelperWatchEvent>;
}


export class SecurityAutoMsgSGPolicyWatchHelper extends BaseModel implements ISecurityAutoMsgSGPolicyWatchHelper {
    'events': Array<SecurityAutoMsgSGPolicyWatchHelperWatchEvent> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'events': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SecurityAutoMsgSGPolicyWatchHelper.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SecurityAutoMsgSGPolicyWatchHelper.propInfo[prop] != null &&
                        SecurityAutoMsgSGPolicyWatchHelper.propInfo[prop].default != null &&
                        SecurityAutoMsgSGPolicyWatchHelper.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['events'] = new Array<SecurityAutoMsgSGPolicyWatchHelperWatchEvent>();
        this.setValues(values);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values) {
            this.fillModelArray<SecurityAutoMsgSGPolicyWatchHelperWatchEvent>(this, 'events', values['events'], SecurityAutoMsgSGPolicyWatchHelperWatchEvent);
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<SecurityAutoMsgSGPolicyWatchHelperWatchEvent>('events', this['events'], SecurityAutoMsgSGPolicyWatchHelperWatchEvent);
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this.fillModelArray<SecurityAutoMsgSGPolicyWatchHelperWatchEvent>(this, 'events', this['events'], SecurityAutoMsgSGPolicyWatchHelperWatchEvent);
        }
    }
}

