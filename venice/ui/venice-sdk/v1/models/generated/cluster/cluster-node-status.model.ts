/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { ClusterNodeStatus_phase } from './enums';
import { ClusterNodeCondition } from './cluster-node-condition.model';

export interface IClusterNodeStatus {
    'phase'?: ClusterNodeStatus_phase;
    'conditions'?: Array<ClusterNodeCondition>;
}


export class ClusterNodeStatus extends BaseModel implements IClusterNodeStatus {
    /** Current lifecycle phase of the node. */
    'phase': ClusterNodeStatus_phase;
    'conditions': Array<ClusterNodeCondition>;
    public static enumProperties = {
        'phase': ClusterNodeStatus_phase,
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['conditions'] = new Array<ClusterNodeCondition>();
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
            this['phase'] = values['phase'];
            this.fillModelArray<ClusterNodeCondition>(this, 'conditions', values['conditions'], ClusterNodeCondition);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'phase': new FormControl(this['phase'], [enumValidator(ClusterNodeStatus_phase), ]),
                'conditions': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<ClusterNodeCondition>('conditions', this['conditions'], ClusterNodeCondition);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['phase'].setValue(this['phase']);
            this.fillModelArray<ClusterNodeCondition>(this, 'conditions', this['conditions'], ClusterNodeCondition);
        }
    }
}

