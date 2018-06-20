/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { NetworkAutoMsgNetworkWatchHelperWatchEvent } from './network-auto-msg-network-watch-helper-watch-event.model';

export interface INetworkAutoMsgNetworkWatchHelper {
    'Events'?: Array<NetworkAutoMsgNetworkWatchHelperWatchEvent>;
}


export class NetworkAutoMsgNetworkWatchHelper extends BaseModel implements INetworkAutoMsgNetworkWatchHelper {
    'Events': Array<NetworkAutoMsgNetworkWatchHelperWatchEvent>;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Events'] = new Array<NetworkAutoMsgNetworkWatchHelperWatchEvent>();
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
            this.fillModelArray<NetworkAutoMsgNetworkWatchHelperWatchEvent>(this, 'Events', values['Events'], NetworkAutoMsgNetworkWatchHelperWatchEvent);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'Events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<NetworkAutoMsgNetworkWatchHelperWatchEvent>('Events', this['Events'], NetworkAutoMsgNetworkWatchHelperWatchEvent);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<NetworkAutoMsgNetworkWatchHelperWatchEvent>(this, 'Events', this['Events'], NetworkAutoMsgNetworkWatchHelperWatchEvent);
        }
    }
}

