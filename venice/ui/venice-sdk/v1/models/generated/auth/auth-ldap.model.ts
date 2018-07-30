/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { AuthLdapAttributeMapping, IAuthLdapAttributeMapping } from './auth-ldap-attribute-mapping.model';
import { AuthLdapServer, IAuthLdapServer } from './auth-ldap-server.model';

export interface IAuthLdap {
    'enabled'?: boolean;
    'base-dn'?: string;
    'bind-dn'?: string;
    'bind-password'?: string;
    'attribute-mapping'?: IAuthLdapAttributeMapping;
    'servers'?: Array<IAuthLdapServer>;
}


export class AuthLdap extends BaseModel implements IAuthLdap {
    'enabled': boolean;
    'base-dn': string;
    'bind-dn': string;
    'bind-password': string;
    'attribute-mapping': AuthLdapAttributeMapping;
    'servers': Array<AuthLdapServer>;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (AuthLdap.enumProperties[prop] != null &&
                        AuthLdap.enumProperties[prop].default != null &&
                        AuthLdap.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['attribute-mapping'] = new AuthLdapAttributeMapping();
        this['servers'] = new Array<AuthLdapServer>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['enabled'] != null) {
            this['enabled'] = values['enabled'];
        }
        if (values && values['base-dn'] != null) {
            this['base-dn'] = values['base-dn'];
        }
        if (values && values['bind-dn'] != null) {
            this['bind-dn'] = values['bind-dn'];
        }
        if (values && values['bind-password'] != null) {
            this['bind-password'] = values['bind-password'];
        }
        if (values) {
            this['attribute-mapping'].setValues(values['attribute-mapping']);
        }
        if (values) {
            this.fillModelArray<AuthLdapServer>(this, 'servers', values['servers'], AuthLdapServer);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'enabled': new FormControl(this['enabled']),
                'base-dn': new FormControl(this['base-dn']),
                'bind-dn': new FormControl(this['bind-dn']),
                'bind-password': new FormControl(this['bind-password']),
                'attribute-mapping': this['attribute-mapping'].$formGroup,
                'servers': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<AuthLdapServer>('servers', this['servers'], AuthLdapServer);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['enabled'].setValue(this['enabled']);
            this._formGroup.controls['base-dn'].setValue(this['base-dn']);
            this._formGroup.controls['bind-dn'].setValue(this['bind-dn']);
            this._formGroup.controls['bind-password'].setValue(this['bind-password']);
            this['attribute-mapping'].setFormGroupValues();
            this.fillModelArray<AuthLdapServer>(this, 'servers', this['servers'], AuthLdapServer);
        }
    }
}

