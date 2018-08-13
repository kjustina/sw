/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { SecurityALG, ISecurityALG } from './security-alg.model';

export interface ISecurityAppSpec {
    'protocol'?: Array<string>;
    'alg'?: ISecurityALG;
}


export class SecurityAppSpec extends BaseModel implements ISecurityAppSpec {
    'protocol': Array<string> = null;
    'alg': SecurityALG = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'protocol': {
            type: 'object'
        },
        'alg': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SecurityAppSpec.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SecurityAppSpec.propInfo[prop] != null &&
                        SecurityAppSpec.propInfo[prop].default != null &&
                        SecurityAppSpec.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['protocol'] = new Array<string>();
        this['alg'] = new SecurityALG();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<string>(this, 'protocol', values['protocol']);
        }
        if (values) {
            this['alg'].setValues(values['alg']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'protocol': new FormArray([]),
                'alg': this['alg'].$formGroup,
            });
            // generate FormArray control elements
            this.fillFormArray<string>('protocol', this['protocol']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<string>(this, 'protocol', this['protocol']);
            this['alg'].setFormGroupValues();
        }
    }
}

