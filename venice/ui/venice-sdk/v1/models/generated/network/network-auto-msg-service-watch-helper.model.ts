/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { NetworkAutoMsgServiceWatchHelperWatchEvent, INetworkAutoMsgServiceWatchHelperWatchEvent } from './network-auto-msg-service-watch-helper-watch-event.model';

export interface INetworkAutoMsgServiceWatchHelper {
    'events'?: Array<INetworkAutoMsgServiceWatchHelperWatchEvent>;
}


export class NetworkAutoMsgServiceWatchHelper extends BaseModel implements INetworkAutoMsgServiceWatchHelper {
    'events': Array<NetworkAutoMsgServiceWatchHelperWatchEvent> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'events': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return NetworkAutoMsgServiceWatchHelper.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (NetworkAutoMsgServiceWatchHelper.propInfo[prop] != null &&
                        NetworkAutoMsgServiceWatchHelper.propInfo[prop].default != null &&
                        NetworkAutoMsgServiceWatchHelper.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['events'] = new Array<NetworkAutoMsgServiceWatchHelperWatchEvent>();
        this.setValues(values);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values) {
            this.fillModelArray<NetworkAutoMsgServiceWatchHelperWatchEvent>(this, 'events', values['events'], NetworkAutoMsgServiceWatchHelperWatchEvent);
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<NetworkAutoMsgServiceWatchHelperWatchEvent>('events', this['events'], NetworkAutoMsgServiceWatchHelperWatchEvent);
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this.fillModelArray<NetworkAutoMsgServiceWatchHelperWatchEvent>(this, 'events', this['events'], NetworkAutoMsgServiceWatchHelperWatchEvent);
        }
    }
}

