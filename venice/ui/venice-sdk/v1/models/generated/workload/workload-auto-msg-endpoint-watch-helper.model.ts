/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { WorkloadAutoMsgEndpointWatchHelperWatchEvent, IWorkloadAutoMsgEndpointWatchHelperWatchEvent } from './workload-auto-msg-endpoint-watch-helper-watch-event.model';

export interface IWorkloadAutoMsgEndpointWatchHelper {
    'Events'?: Array<IWorkloadAutoMsgEndpointWatchHelperWatchEvent>;
}


export class WorkloadAutoMsgEndpointWatchHelper extends BaseModel implements IWorkloadAutoMsgEndpointWatchHelper {
    'Events': Array<WorkloadAutoMsgEndpointWatchHelperWatchEvent>;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (WorkloadAutoMsgEndpointWatchHelper.enumProperties[prop] != null &&
                        WorkloadAutoMsgEndpointWatchHelper.enumProperties[prop].default != null &&
                        WorkloadAutoMsgEndpointWatchHelper.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Events'] = new Array<WorkloadAutoMsgEndpointWatchHelperWatchEvent>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<WorkloadAutoMsgEndpointWatchHelperWatchEvent>(this, 'Events', values['Events'], WorkloadAutoMsgEndpointWatchHelperWatchEvent);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'Events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<WorkloadAutoMsgEndpointWatchHelperWatchEvent>('Events', this['Events'], WorkloadAutoMsgEndpointWatchHelperWatchEvent);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<WorkloadAutoMsgEndpointWatchHelperWatchEvent>(this, 'Events', this['Events'], WorkloadAutoMsgEndpointWatchHelperWatchEvent);
        }
    }
}

