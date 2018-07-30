/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { LabelsRequirement_operator,  LabelsRequirement_operator_uihint  } from './enums';

export interface ILabelsRequirement {
    'key'?: string;
    'operator'?: LabelsRequirement_operator;
    'values'?: Array<string>;
}


export class LabelsRequirement extends BaseModel implements ILabelsRequirement {
    /** The label key that the condition applies to. */
    'key': string;
    /** Condition checked for the key. */
    'operator': LabelsRequirement_operator;
    /** Values contains one or more values corresponding to the label key. "equals" and
"notEquals" operators need a single Value. "in" and "notIn" operators can have
one or more values. */
    'values': Array<string>;
    public static enumProperties: { [key: string] : EnumDef } = {
        'operator': {
            enum: LabelsRequirement_operator_uihint,
            default: 'equals',
        },
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (LabelsRequirement.enumProperties[prop] != null &&
                        LabelsRequirement.enumProperties[prop].default != null &&
                        LabelsRequirement.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['values'] = new Array<string>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['key'] != null) {
            this['key'] = values['key'];
        }
        if (values && values['operator'] != null) {
            this['operator'] = values['operator'];
        } else if (LabelsRequirement.hasDefaultEnumValue('operator')) {
            this['operator'] = <LabelsRequirement_operator> LabelsRequirement.enumProperties['operator'].default;
        }
        if (values) {
            this.fillModelArray<string>(this, 'values', values['values']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'key': new FormControl(this['key']),
                'operator': new FormControl(this['operator'], [enumValidator(LabelsRequirement_operator), ]),
                'values': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('values', this['values']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['key'].setValue(this['key']);
            this._formGroup.controls['operator'].setValue(this['operator']);
            this.fillModelArray<string>(this, 'values', this['values']);
        }
    }
}

