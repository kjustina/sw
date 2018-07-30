/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { WorkloadAutoMsgWorkloadWatchHelperWatchEvent, IWorkloadAutoMsgWorkloadWatchHelperWatchEvent } from './workload-auto-msg-workload-watch-helper-watch-event.model';

export interface IWorkloadAutoMsgWorkloadWatchHelper {
    'Events'?: Array<IWorkloadAutoMsgWorkloadWatchHelperWatchEvent>;
}


export class WorkloadAutoMsgWorkloadWatchHelper extends BaseModel implements IWorkloadAutoMsgWorkloadWatchHelper {
    'Events': Array<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (WorkloadAutoMsgWorkloadWatchHelper.enumProperties[prop] != null &&
                        WorkloadAutoMsgWorkloadWatchHelper.enumProperties[prop].default != null &&
                        WorkloadAutoMsgWorkloadWatchHelper.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Events'] = new Array<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>(this, 'Events', values['Events'], WorkloadAutoMsgWorkloadWatchHelperWatchEvent);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'Events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>('Events', this['Events'], WorkloadAutoMsgWorkloadWatchHelperWatchEvent);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>(this, 'Events', this['Events'], WorkloadAutoMsgWorkloadWatchHelperWatchEvent);
        }
    }
}

