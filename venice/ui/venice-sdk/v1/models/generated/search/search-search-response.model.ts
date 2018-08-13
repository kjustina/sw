/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { SearchError, ISearchError } from './search-error.model';
import { SearchEntry, ISearchEntry } from './search-entry.model';
import { SearchTenantPreview, ISearchTenantPreview } from './search-tenant-preview.model';
import { SearchTenantAggregation, ISearchTenantAggregation } from './search-tenant-aggregation.model';

export interface ISearchSearchResponse {
    'total-hits'?: string;
    'actual-hits'?: string;
    'time-taken-msecs'?: string;
    'error'?: ISearchError;
    'entries'?: Array<ISearchEntry>;
    'preview-entries'?: ISearchTenantPreview;
    'aggregated-entries'?: ISearchTenantAggregation;
}


export class SearchSearchResponse extends BaseModel implements ISearchSearchResponse {
    'total-hits': string = null;
    'actual-hits': string = null;
    'time-taken-msecs': string = null;
    'error': SearchError = null;
    'entries': Array<SearchEntry> = null;
    'preview-entries': SearchTenantPreview = null;
    'aggregated-entries': SearchTenantAggregation = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'total-hits': {
            type: 'string'
                    },
        'actual-hits': {
            type: 'string'
                    },
        'time-taken-msecs': {
            type: 'string'
                    },
        'error': {
            type: 'object'
        },
        'entries': {
            type: 'object'
        },
        'preview-entries': {
            type: 'object'
        },
        'aggregated-entries': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SearchSearchResponse.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SearchSearchResponse.propInfo[prop] != null &&
                        SearchSearchResponse.propInfo[prop].default != null &&
                        SearchSearchResponse.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['error'] = new SearchError();
        this['entries'] = new Array<SearchEntry>();
        this['preview-entries'] = new SearchTenantPreview();
        this['aggregated-entries'] = new SearchTenantAggregation();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['total-hits'] != null) {
            this['total-hits'] = values['total-hits'];
        } else if (SearchSearchResponse.hasDefaultValue('total-hits')) {
            this['total-hits'] = SearchSearchResponse.propInfo['total-hits'].default;
        }
        if (values && values['actual-hits'] != null) {
            this['actual-hits'] = values['actual-hits'];
        } else if (SearchSearchResponse.hasDefaultValue('actual-hits')) {
            this['actual-hits'] = SearchSearchResponse.propInfo['actual-hits'].default;
        }
        if (values && values['time-taken-msecs'] != null) {
            this['time-taken-msecs'] = values['time-taken-msecs'];
        } else if (SearchSearchResponse.hasDefaultValue('time-taken-msecs')) {
            this['time-taken-msecs'] = SearchSearchResponse.propInfo['time-taken-msecs'].default;
        }
        if (values) {
            this['error'].setValues(values['error']);
        }
        if (values) {
            this.fillModelArray<SearchEntry>(this, 'entries', values['entries'], SearchEntry);
        }
        if (values) {
            this['preview-entries'].setValues(values['preview-entries']);
        }
        if (values) {
            this['aggregated-entries'].setValues(values['aggregated-entries']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'total-hits': new FormControl(this['total-hits']),
                'actual-hits': new FormControl(this['actual-hits']),
                'time-taken-msecs': new FormControl(this['time-taken-msecs']),
                'error': this['error'].$formGroup,
                'entries': new FormArray([]),
                'preview-entries': this['preview-entries'].$formGroup,
                'aggregated-entries': this['aggregated-entries'].$formGroup,
            });
            // generate FormArray control elements
            this.fillFormArray<SearchEntry>('entries', this['entries'], SearchEntry);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['total-hits'].setValue(this['total-hits']);
            this._formGroup.controls['actual-hits'].setValue(this['actual-hits']);
            this._formGroup.controls['time-taken-msecs'].setValue(this['time-taken-msecs']);
            this['error'].setFormGroupValues();
            this.fillModelArray<SearchEntry>(this, 'entries', this['entries'], SearchEntry);
            this['preview-entries'].setFormGroupValues();
            this['aggregated-entries'].setFormGroupValues();
        }
    }
}

