/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { AuthAuthenticators_authenticator_order,  AuthAuthenticators_authenticator_order_uihint  } from './enums';
import { AuthLdap, IAuthLdap } from './auth-ldap.model';
import { AuthLocal, IAuthLocal } from './auth-local.model';
import { AuthRadius, IAuthRadius } from './auth-radius.model';

export interface IAuthAuthenticators {
    'authenticator-order'?: Array<AuthAuthenticators_authenticator_order>;
    'ldap'?: IAuthLdap;
    'local'?: IAuthLocal;
    'radius'?: IAuthRadius;
}


export class AuthAuthenticators extends BaseModel implements IAuthAuthenticators {
    'authenticator-order': Array<AuthAuthenticators_authenticator_order> = null;
    'ldap': AuthLdap = null;
    'local': AuthLocal = null;
    'radius': AuthRadius = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'authenticator-order': {
            enum: AuthAuthenticators_authenticator_order_uihint,
            default: 'LOCAL',
            type: 'Array<string>'
        },
        'ldap': {
            type: 'object'
        },
        'local': {
            type: 'object'
        },
        'radius': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return AuthAuthenticators.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (AuthAuthenticators.propInfo[prop] != null &&
                        AuthAuthenticators.propInfo[prop].default != null &&
                        AuthAuthenticators.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['authenticator-order'] = new Array<AuthAuthenticators_authenticator_order>();
        this['ldap'] = new AuthLdap();
        this['local'] = new AuthLocal();
        this['radius'] = new AuthRadius();
        this.setValues(values);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['authenticator-order'] != null) {
            this['authenticator-order'] = values['authenticator-order'];
        } else if (fillDefaults && AuthAuthenticators.hasDefaultValue('authenticator-order')) {
            this['authenticator-order'] = [ AuthAuthenticators.propInfo['authenticator-order'].default];
        }
        if (values) {
            this['ldap'].setValues(values['ldap']);
        }
        if (values) {
            this['local'].setValues(values['local']);
        }
        if (values) {
            this['radius'].setValues(values['radius']);
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'authenticator-order': new FormControl(this['authenticator-order']),
                'ldap': this['ldap'].$formGroup,
                'local': this['local'].$formGroup,
                'radius': this['radius'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['authenticator-order'].setValue(this['authenticator-order']);
            this['ldap'].setFormGroupValuesToBeModelValues();
            this['local'].setFormGroupValuesToBeModelValues();
            this['radius'].setFormGroupValuesToBeModelValues();
        }
    }
}

