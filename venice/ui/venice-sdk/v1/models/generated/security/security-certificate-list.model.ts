/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { SecurityCertificate, ISecurityCertificate } from './security-certificate.model';

export interface ISecurityCertificateList {
    'kind'?: string;
    'api-version'?: string;
    'resource-version'?: string;
    'Items'?: Array<ISecurityCertificate>;
}


export class SecurityCertificateList extends BaseModel implements ISecurityCertificateList {
    'kind': string = null;
    'api-version': string = null;
    'resource-version': string = null;
    'Items': Array<SecurityCertificate> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'kind': {
            type: 'string'
                    },
        'api-version': {
            type: 'string'
                    },
        'resource-version': {
            type: 'string'
                    },
        'Items': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SecurityCertificateList.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SecurityCertificateList.propInfo[prop] != null &&
                        SecurityCertificateList.propInfo[prop].default != null &&
                        SecurityCertificateList.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Items'] = new Array<SecurityCertificate>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        } else if (SecurityCertificateList.hasDefaultValue('kind')) {
            this['kind'] = SecurityCertificateList.propInfo['kind'].default;
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        } else if (SecurityCertificateList.hasDefaultValue('api-version')) {
            this['api-version'] = SecurityCertificateList.propInfo['api-version'].default;
        }
        if (values && values['resource-version'] != null) {
            this['resource-version'] = values['resource-version'];
        } else if (SecurityCertificateList.hasDefaultValue('resource-version')) {
            this['resource-version'] = SecurityCertificateList.propInfo['resource-version'].default;
        }
        if (values) {
            this.fillModelArray<SecurityCertificate>(this, 'Items', values['Items'], SecurityCertificate);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': new FormControl(this['kind']),
                'api-version': new FormControl(this['api-version']),
                'resource-version': new FormControl(this['resource-version']),
                'Items': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<SecurityCertificate>('Items', this['Items'], SecurityCertificate);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['api-version'].setValue(this['api-version']);
            this._formGroup.controls['resource-version'].setValue(this['resource-version']);
            this.fillModelArray<SecurityCertificate>(this, 'Items', this['Items'], SecurityCertificate);
        }
    }
}

