/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { WorkloadAutoMsgWorkloadWatchHelperWatchEvent } from './workload-auto-msg-workload-watch-helper-watch-event.model';

export interface IWorkloadAutoMsgWorkloadWatchHelper {
    'Events'?: Array<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>;
}


export class WorkloadAutoMsgWorkloadWatchHelper extends BaseModel implements IWorkloadAutoMsgWorkloadWatchHelper {
    'Events': Array<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Events'] = new Array<WorkloadAutoMsgWorkloadWatchHelperWatchEvent>();
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

