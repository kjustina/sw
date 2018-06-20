/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';


export interface IWorkloadWorkloadIntfSpec {
    'micro-seg-vlan'?: number;
    'external-vlan'?: number;
}


export class WorkloadWorkloadIntfSpec extends BaseModel implements IWorkloadWorkloadIntfSpec {
    /** value should be between 1 and 4095
 */
    'micro-seg-vlan': number;
    /** value should be between 1 and 4095
 */
    'external-vlan': number;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
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
            this['micro-seg-vlan'] = values['micro-seg-vlan'];
            this['external-vlan'] = values['external-vlan'];
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'micro-seg-vlan': new FormControl(this['micro-seg-vlan'], [minValueValidator(1), maxValueValidator(4095), ]),
                'external-vlan': new FormControl(this['external-vlan'], [minValueValidator(1), maxValueValidator(4095), ]),
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['micro-seg-vlan'].setValue(this['micro-seg-vlan']);
            this._formGroup.controls['external-vlan'].setValue(this['external-vlan']);
        }
    }
}

