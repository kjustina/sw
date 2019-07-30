/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';


export interface IApiAny {
    'type_url'?: string;
    'value'?: string;
}


export class ApiAny extends BaseModel implements IApiAny {
    'type_url': string = null;
    'value': string = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'type_url': {
            required: false,
            type: 'string'
        },
        'value': {
            required: false,
            type: 'string'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ApiAny.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return ApiAny.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ApiAny.propInfo[prop] != null &&
                        ApiAny.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['type_url'] != null) {
            this['type_url'] = values['type_url'];
        } else if (fillDefaults && ApiAny.hasDefaultValue('type_url')) {
            this['type_url'] = ApiAny.propInfo['type_url'].default;
        } else {
            this['type_url'] = null
        }
        if (values && values['value'] != null) {
            this['value'] = values['value'];
        } else if (fillDefaults && ApiAny.hasDefaultValue('value')) {
            this['value'] = ApiAny.propInfo['value'].default;
        } else {
            this['value'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'type_url': CustomFormControl(new FormControl(this['type_url']), ApiAny.propInfo['type_url']),
                'value': CustomFormControl(new FormControl(this['value']), ApiAny.propInfo['value']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['type_url'].setValue(this['type_url']);
            this._formGroup.controls['value'].setValue(this['value']);
        }
    }
}

