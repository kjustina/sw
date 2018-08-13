/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';


export interface IClusterHostIntfSpec {
    'mac-addrs'?: Array<string>;
}


export class ClusterHostIntfSpec extends BaseModel implements IClusterHostIntfSpec {
    'mac-addrs': Array<string> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'mac-addrs': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ClusterHostIntfSpec.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ClusterHostIntfSpec.propInfo[prop] != null &&
                        ClusterHostIntfSpec.propInfo[prop].default != null &&
                        ClusterHostIntfSpec.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['mac-addrs'] = new Array<string>();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<string>(this, 'mac-addrs', values['mac-addrs']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'mac-addrs': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('mac-addrs', this['mac-addrs']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<string>(this, 'mac-addrs', this['mac-addrs']);
        }
    }
}

