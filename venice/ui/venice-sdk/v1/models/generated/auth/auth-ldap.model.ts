/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';

import { AuthTLSOptions } from './auth-tls-options.model';
import { AuthLdapAttributeMapping } from './auth-ldap-attribute-mapping.model';

export interface IAuthLdap {
    'enabled'?: boolean;
    'url'?: string;
    'tls-options'?: AuthTLSOptions;
    'base-dn'?: string;
    'bind-dn'?: string;
    'bind-password'?: string;
    'attribute-mapping'?: AuthLdapAttributeMapping;
}


export class AuthLdap extends BaseModel implements IAuthLdap {
    'enabled': boolean;
    'url': string;
    'tls-options': AuthTLSOptions;
    'base-dn': string;
    'bind-dn': string;
    'bind-password': string;
    'attribute-mapping': AuthLdapAttributeMapping;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['tls-options'] = new AuthTLSOptions();
        this['attribute-mapping'] = new AuthLdapAttributeMapping();
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
            this['enabled'] = values['enabled'];
            this['url'] = values['url'];
            this['tls-options'].setValues(values['tls-options']);
            this['base-dn'] = values['base-dn'];
            this['bind-dn'] = values['bind-dn'];
            this['bind-password'] = values['bind-password'];
            this['attribute-mapping'].setValues(values['attribute-mapping']);
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'enabled': new FormControl(this['enabled']),
                'url': new FormControl(this['url']),
                'tls-options': this['tls-options'].$formGroup,
                'base-dn': new FormControl(this['base-dn']),
                'bind-dn': new FormControl(this['bind-dn']),
                'bind-password': new FormControl(this['bind-password']),
                'attribute-mapping': this['attribute-mapping'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['enabled'].setValue(this['enabled']);
            this._formGroup.controls['url'].setValue(this['url']);
            this['tls-options'].setFormGroupValues();
            this._formGroup.controls['base-dn'].setValue(this['base-dn']);
            this._formGroup.controls['bind-dn'].setValue(this['bind-dn']);
            this._formGroup.controls['bind-password'].setValue(this['bind-password']);
            this['attribute-mapping'].setFormGroupValues();
        }
    }
}

