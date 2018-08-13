/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';


export interface IClusterHostSpec {
    'interfaces'?: object;
}


export class ClusterHostSpec extends BaseModel implements IClusterHostSpec {
    'interfaces': object = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'interfaces': {
            type: 'object'
                    },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ClusterHostSpec.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ClusterHostSpec.propInfo[prop] != null &&
                        ClusterHostSpec.propInfo[prop].default != null &&
                        ClusterHostSpec.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['interfaces'] != null) {
            this['interfaces'] = values['interfaces'];
        } else if (ClusterHostSpec.hasDefaultValue('interfaces')) {
            this['interfaces'] = ClusterHostSpec.propInfo['interfaces'].default;
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'interfaces': new FormControl(this['interfaces']),
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['interfaces'].setValue(this['interfaces']);
        }
    }
}

