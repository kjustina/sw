/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { ApiObjectMeta, IApiObjectMeta } from './api-object-meta.model';
import { NetworkServiceSpec, INetworkServiceSpec } from './network-service-spec.model';
import { NetworkServiceStatus, INetworkServiceStatus } from './network-service-status.model';

export interface INetworkService {
    'kind'?: string;
    'api-version'?: string;
    'meta'?: IApiObjectMeta;
    'spec'?: INetworkServiceSpec;
    'status'?: INetworkServiceStatus;
}


export class NetworkService extends BaseModel implements INetworkService {
    'kind': string;
    'api-version': string;
    'meta': ApiObjectMeta;
    /** Spec contains the configuration of the Service. */
    'spec': NetworkServiceSpec;
    /** Status contains the current state of the Service. */
    'status': NetworkServiceStatus;
    public static enumProperties: { [key: string] : EnumDef } = {
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (NetworkService.enumProperties[prop] != null &&
                        NetworkService.enumProperties[prop].default != null &&
                        NetworkService.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['meta'] = new ApiObjectMeta();
        this['spec'] = new NetworkServiceSpec();
        this['status'] = new NetworkServiceStatus();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        }
        if (values) {
            this['meta'].setValues(values['meta']);
        }
        if (values) {
            this['spec'].setValues(values['spec']);
        }
        if (values) {
            this['status'].setValues(values['status']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': new FormControl(this['kind']),
                'api-version': new FormControl(this['api-version']),
                'meta': this['meta'].$formGroup,
                'spec': this['spec'].$formGroup,
                'status': this['status'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['api-version'].setValue(this['api-version']);
            this['meta'].setFormGroupValues();
            this['spec'].setFormGroupValues();
            this['status'].setFormGroupValues();
        }
    }
}

