/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';


export interface ISearchTextRequirement {
    'text'?: Array<string>;
}


export class SearchTextRequirement extends BaseModel implements ISearchTextRequirement {
    /** length of string should be between 0 and 256
     */
    'text': Array<string> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'text': {
            description:  'length of string should be between 0 and 256 ',
            type: 'Array<string>'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SearchTextRequirement.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SearchTextRequirement.propInfo[prop] != null &&
                        SearchTextRequirement.propInfo[prop].default != null &&
                        SearchTextRequirement.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['text'] = new Array<string>();
        this.setValues(values);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['text'] != null) {
            this['text'] = values['text'];
        } else if (fillDefaults && SearchTextRequirement.hasDefaultValue('text')) {
            this['text'] = [ SearchTextRequirement.propInfo['text'].default];
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'text': new FormControl(this['text']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['text'].setValue(this['text']);
        }
    }
}

