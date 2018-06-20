/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { AuthAutoMsgUserWatchHelperWatchEvent } from './auth-auto-msg-user-watch-helper-watch-event.model';

export interface IAuthAutoMsgUserWatchHelper {
    'Events'?: Array<AuthAutoMsgUserWatchHelperWatchEvent>;
}


export class AuthAutoMsgUserWatchHelper extends BaseModel implements IAuthAutoMsgUserWatchHelper {
    'Events': Array<AuthAutoMsgUserWatchHelperWatchEvent>;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Events'] = new Array<AuthAutoMsgUserWatchHelperWatchEvent>();
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
            this.fillModelArray<AuthAutoMsgUserWatchHelperWatchEvent>(this, 'Events', values['Events'], AuthAutoMsgUserWatchHelperWatchEvent);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'Events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<AuthAutoMsgUserWatchHelperWatchEvent>('Events', this['Events'], AuthAutoMsgUserWatchHelperWatchEvent);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<AuthAutoMsgUserWatchHelperWatchEvent>(this, 'Events', this['Events'], AuthAutoMsgUserWatchHelperWatchEvent);
        }
    }
}

