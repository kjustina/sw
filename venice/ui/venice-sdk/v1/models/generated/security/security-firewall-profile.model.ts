/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { ApiObjectMeta, IApiObjectMeta } from './api-object-meta.model';
import { SecurityFirewallProfileSpec, ISecurityFirewallProfileSpec } from './security-firewall-profile-spec.model';
import { SecurityFirewallProfileStatus, ISecurityFirewallProfileStatus } from './security-firewall-profile-status.model';

export interface ISecurityFirewallProfile {
    'kind'?: string;
    'api-version'?: string;
    'meta'?: IApiObjectMeta;
    'spec'?: ISecurityFirewallProfileSpec;
    'status'?: ISecurityFirewallProfileStatus;
}


export class SecurityFirewallProfile extends BaseModel implements ISecurityFirewallProfile {
    'kind': string = null;
    'api-version': string = null;
    'meta': ApiObjectMeta = null;
    'spec': SecurityFirewallProfileSpec = null;
    'status': SecurityFirewallProfileStatus = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'kind': {
            required: false,
            type: 'string'
        },
        'api-version': {
            required: false,
            type: 'string'
        },
        'meta': {
            required: false,
            type: 'object'
        },
        'spec': {
            required: false,
            type: 'object'
        },
        'status': {
            required: false,
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SecurityFirewallProfile.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return SecurityFirewallProfile.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SecurityFirewallProfile.propInfo[prop] != null &&
                        SecurityFirewallProfile.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['meta'] = new ApiObjectMeta();
        this['spec'] = new SecurityFirewallProfileSpec();
        this['status'] = new SecurityFirewallProfileStatus();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        } else if (fillDefaults && SecurityFirewallProfile.hasDefaultValue('kind')) {
            this['kind'] = SecurityFirewallProfile.propInfo['kind'].default;
        } else {
            this['kind'] = null
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        } else if (fillDefaults && SecurityFirewallProfile.hasDefaultValue('api-version')) {
            this['api-version'] = SecurityFirewallProfile.propInfo['api-version'].default;
        } else {
            this['api-version'] = null
        }
        if (values) {
            this['meta'].setValues(values['meta'], fillDefaults);
        } else {
            this['meta'].setValues(null, fillDefaults);
        }
        if (values) {
            this['spec'].setValues(values['spec'], fillDefaults);
        } else {
            this['spec'].setValues(null, fillDefaults);
        }
        if (values) {
            this['status'].setValues(values['status'], fillDefaults);
        } else {
            this['status'].setValues(null, fillDefaults);
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': CustomFormControl(new FormControl(this['kind']), SecurityFirewallProfile.propInfo['kind']),
                'api-version': CustomFormControl(new FormControl(this['api-version']), SecurityFirewallProfile.propInfo['api-version']),
                'meta': CustomFormGroup(this['meta'].$formGroup, SecurityFirewallProfile.propInfo['meta'].required),
                'spec': CustomFormGroup(this['spec'].$formGroup, SecurityFirewallProfile.propInfo['spec'].required),
                'status': CustomFormGroup(this['status'].$formGroup, SecurityFirewallProfile.propInfo['status'].required),
            });
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('meta') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('meta').get(field);
                control.updateValueAndValidity();
            });
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('spec') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('spec').get(field);
                control.updateValueAndValidity();
            });
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('status') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('status').get(field);
                control.updateValueAndValidity();
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['api-version'].setValue(this['api-version']);
            this['meta'].setFormGroupValuesToBeModelValues();
            this['spec'].setFormGroupValuesToBeModelValues();
            this['status'].setFormGroupValuesToBeModelValues();
        }
    }
}

