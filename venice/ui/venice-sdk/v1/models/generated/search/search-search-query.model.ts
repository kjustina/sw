/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, EnumDef } from './base-model';

import { SearchTextRequirement, ISearchTextRequirement } from './search-text-requirement.model';
import { SearchSearchQuery_categories,  } from './enums';
import { SearchSearchQuery_kinds,  } from './enums';
import { FieldsSelector, IFieldsSelector } from './fields-selector.model';
import { LabelsSelector, ILabelsSelector } from './labels-selector.model';

export interface ISearchSearchQuery {
    'texts'?: Array<ISearchTextRequirement>;
    'categories'?: Array<SearchSearchQuery_categories>;
    'kinds'?: Array<SearchSearchQuery_kinds>;
    'fields'?: IFieldsSelector;
    'labels'?: ILabelsSelector;
}


export class SearchSearchQuery extends BaseModel implements ISearchSearchQuery {
    'texts': Array<SearchTextRequirement>;
    /** length of string should be between 0 and 64
 */
    'categories': Array<SearchSearchQuery_categories>;
    /** length of string should be between 0 and 64
 */
    'kinds': Array<SearchSearchQuery_kinds>;
    'fields': FieldsSelector;
    'labels': LabelsSelector;
    public static enumProperties: { [key: string] : EnumDef } = {
        'categories': {
            enum: SearchSearchQuery_categories,
            default: 'Cluster',
        },
        'kinds': {
            enum: SearchSearchQuery_kinds,
            default: 'Cluster',
        },
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultEnumValue(prop) {
        return (SearchSearchQuery.enumProperties[prop] != null &&
                        SearchSearchQuery.enumProperties[prop].default != null &&
                        SearchSearchQuery.enumProperties[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['texts'] = new Array<SearchTextRequirement>();
        this['categories'] = new Array<SearchSearchQuery_categories>();
        this['kinds'] = new Array<SearchSearchQuery_kinds>();
        this['fields'] = new FieldsSelector();
        this['labels'] = new LabelsSelector();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this.fillModelArray<SearchTextRequirement>(this, 'texts', values['texts'], SearchTextRequirement);
        }
        if (values) {
            this.fillModelArray<SearchSearchQuery_categories>(this, 'categories', values['categories']);
        }
        if (values) {
            this.fillModelArray<SearchSearchQuery_kinds>(this, 'kinds', values['kinds']);
        }
        if (values) {
            this['fields'].setValues(values['fields']);
        }
        if (values) {
            this['labels'].setValues(values['labels']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'texts': new FormArray([]),
                'categories': new FormArray([]),
                'kinds': new FormArray([]),
                'fields': this['fields'].$formGroup,
                'labels': this['labels'].$formGroup,
            });
            // generate FormArray control elements
            this.fillFormArray<SearchTextRequirement>('texts', this['texts'], SearchTextRequirement);
            // generate FormArray control elements
            this.fillFormArray<SearchSearchQuery_categories>('categories', this['categories']);
            // generate FormArray control elements
            this.fillFormArray<SearchSearchQuery_kinds>('kinds', this['kinds']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<SearchTextRequirement>(this, 'texts', this['texts'], SearchTextRequirement);
            this.fillModelArray<SearchSearchQuery_categories>(this, 'categories', this['categories']);
            this.fillModelArray<SearchSearchQuery_kinds>(this, 'kinds', this['kinds']);
            this['fields'].setFormGroupValues();
            this['labels'].setFormGroupValues();
        }
    }
}

