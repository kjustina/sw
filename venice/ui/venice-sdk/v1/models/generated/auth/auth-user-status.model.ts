/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';


export interface IAuthUserStatus {
    'roles'?: Array<string>;
    'user-groups'?: Array<string>;
    'last-successful-login'?: Date;
}


export class AuthUserStatus extends BaseModel implements IAuthUserStatus {
    'roles': Array<string>;
    'user-groups': Array<string>;
    'last-successful-login': Date;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['roles'] = new Array<string>();
        this['user-groups'] = new Array<string>();
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
            this.fillModelArray<string>(this, 'roles', values['roles']);
            this.fillModelArray<string>(this, 'user-groups', values['user-groups']);
            this['last-successful-login'] = values['last-successful-login'];
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'roles': new FormArray([]),
                'user-groups': new FormArray([]),
                'last-successful-login': new FormControl(this['last-successful-login']),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('roles', this['roles']);
            // generate FormArray control elements
            this.fillFormArray<string>('user-groups', this['user-groups']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<string>(this, 'roles', this['roles']);
            this.fillModelArray<string>(this, 'user-groups', this['user-groups']);
            this._formGroup.controls['last-successful-login'].setValue(this['last-successful-login']);
        }
    }
}

