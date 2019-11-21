/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';


export interface INetworkNetworkStatus {
    'workloads'?: Array<string>;
    'allocated-ipv4-addrs'?: string;
    'id'?: string;
}


export class NetworkNetworkStatus extends BaseModel implements INetworkNetworkStatus {
    /** list of all workloads in this network */
    'workloads': Array<string> = null;
    /** allocated IPv4 addresses (bitmap) */
    'allocated-ipv4-addrs': string = null;
    /** Handle is the internal Handle allocated to this network */
    'id': string = null;
    public static propInfo: { [prop in keyof INetworkNetworkStatus]: PropInfoItem } = {
        'workloads': {
            description:  'List of all workloads in this network',
            required: false,
            type: 'Array<string>'
        },
        'allocated-ipv4-addrs': {
            description:  'Allocated IPv4 addresses (bitmap)',
            required: false,
            type: 'string'
        },
        'id': {
            description:  'Handle is the internal Handle allocated to this network',
            required: false,
            type: 'string'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return NetworkNetworkStatus.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return NetworkNetworkStatus.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (NetworkNetworkStatus.propInfo[prop] != null &&
                        NetworkNetworkStatus.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['workloads'] = new Array<string>();
        this._inputValue = values;
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['workloads'] != null) {
            this['workloads'] = values['workloads'];
        } else if (fillDefaults && NetworkNetworkStatus.hasDefaultValue('workloads')) {
            this['workloads'] = [ NetworkNetworkStatus.propInfo['workloads'].default];
        } else {
            this['workloads'] = [];
        }
        if (values && values['allocated-ipv4-addrs'] != null) {
            this['allocated-ipv4-addrs'] = values['allocated-ipv4-addrs'];
        } else if (fillDefaults && NetworkNetworkStatus.hasDefaultValue('allocated-ipv4-addrs')) {
            this['allocated-ipv4-addrs'] = NetworkNetworkStatus.propInfo['allocated-ipv4-addrs'].default;
        } else {
            this['allocated-ipv4-addrs'] = null
        }
        if (values && values['id'] != null) {
            this['id'] = values['id'];
        } else if (fillDefaults && NetworkNetworkStatus.hasDefaultValue('id')) {
            this['id'] = NetworkNetworkStatus.propInfo['id'].default;
        } else {
            this['id'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'workloads': CustomFormControl(new FormControl(this['workloads']), NetworkNetworkStatus.propInfo['workloads']),
                'allocated-ipv4-addrs': CustomFormControl(new FormControl(this['allocated-ipv4-addrs']), NetworkNetworkStatus.propInfo['allocated-ipv4-addrs']),
                'id': CustomFormControl(new FormControl(this['id']), NetworkNetworkStatus.propInfo['id']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['workloads'].setValue(this['workloads']);
            this._formGroup.controls['allocated-ipv4-addrs'].setValue(this['allocated-ipv4-addrs']);
            this._formGroup.controls['id'].setValue(this['id']);
        }
    }
}

