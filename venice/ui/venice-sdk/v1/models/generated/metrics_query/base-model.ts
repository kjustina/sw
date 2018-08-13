/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */

import { ValidatorFn } from '@angular/forms';
import { FormControl, FormGroup, FormArray } from '@angular/forms';

export interface PropInfoItem {
    enum?: any,
    default?: any,
    description?: string,
    hint?: string,
    type: string
}

export abstract class BaseModel {

    constructor() {
        // define non enumerable properties so these are ommitted in JSON.stringify.
        Object.defineProperty(this, "$formGroup", {
            get: this.getFormGroup,
            enumerable: false,
        });
        Object.defineProperty(this, "_formGroup", {
            enumerable: false,
            writable: true,
        });
        Object.defineProperty(this, "propInfo", {
            enumerable: false,
            writable: true,
        });
    }

    /** 
     * use $formGroup in angular's formBuilder to make a model driven (reactive) form. 
     *   this.form = this.formBuilder.group({
     *       pet: this.pet.$formGroup,
     *   }); 
    */
    $formGroup: FormGroup;

    protected _formGroup: FormGroup;
    protected static propInfo: { [prop: string]: PropInfoItem };
    protected abstract getFormGroup(): FormGroup;
    public abstract getPropInfo(propName: string): PropInfoItem;

    getValues() {
        return this.$formGroup.value;
    }

    /** 
     * add one or more additional validators to the control
     * @param key Name of the control (is the same as the name of the attached model property) 
     * @param validators Validator(s) to add to the control 
    */
    addValidatorToControl(key: string, validators: ValidatorFn | ValidatorFn[]) {
        let control = this.$formGroup.controls[key];
        let vals: any = validators instanceof Array ? validators : [validators];
        if (control.validator) {
            vals.push(control.validator);
        }
        control.setValidators(vals);
    }

    protected fillModelArray<T>(object: BaseModel, key: string, values: Array<T>, type = undefined): void {
        if (values) {
            object[key] = new Array<T>();
            for(let value of values) {
                if (type) {
                    object[key].push(new type(value));
                } else {
                    object[key].push(value);
                }
            }
            // generate FormArray control elements
            this.fillFormArray<T>(key, object[key], type);
        }
    }
    protected fillFormArray<T>(key: string, modelValues: any, type = undefined): void {
        if (this._formGroup) {
            let formArray = BaseModel.clearFormArray(this._formGroup, key);
            for (let modelValue of modelValues) {
                if (type) {
                    formArray.push((<BaseModel>modelValue).$formGroup);
                } else {
                    formArray.push(new FormControl(modelValue));
                }
            }
        }
    }
    private static clearFormArray(formGroup: FormGroup, key: string): FormArray {
        if (formGroup) {
            let formArray = <FormArray>formGroup.controls[key];
            for (let i = formArray.length-1; i >= 0; i--) {
                formArray.removeAt(i);                    
            }
            return formArray;
        }
    }
}
