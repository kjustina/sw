/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { FieldsSelector, IFieldsSelector } from './fields-selector.model';
import { Telemetry_queryMetricsQuerySpec_function,  } from './enums';
import { Telemetry_queryPaginationSpec, ITelemetry_queryPaginationSpec } from './telemetry-query-pagination-spec.model';
import { Telemetry_queryMetricsQuerySpec_sort_order,  } from './enums';

export interface ITelemetry_queryMetricsQuerySpec {
    'kind'?: string;
    'api-version'?: string;
    'name'?: string;
    'selector'?: IFieldsSelector;
    'fields'?: Array<string>;
    'function': Telemetry_queryMetricsQuerySpec_function;
    'start-time'?: Date;
    'end-time'?: Date;
    'group-by-time'?: string;
    'group-by-field'?: string;
    'pagination'?: ITelemetry_queryPaginationSpec;
    'sort-order': Telemetry_queryMetricsQuerySpec_sort_order;
}


export class Telemetry_queryMetricsQuerySpec extends BaseModel implements ITelemetry_queryMetricsQuerySpec {
    'kind': string = null;
    'api-version': string = null;
    /** Name is the name of the API object. */
    'name': string = null;
    'selector': FieldsSelector = null;
    /** must start and end with alpha numeric and can have alphanumeric, -, _, . */
    'fields': Array<string> = null;
    'function': Telemetry_queryMetricsQuerySpec_function = null;
    'start-time': Date = null;
    'end-time': Date = null;
    /** should be a valid time duration
     */
    'group-by-time': string = null;
    /** must start and end with alpha numeric and can have alphanumeric, -, _, . */
    'group-by-field': string = null;
    'pagination': Telemetry_queryPaginationSpec = null;
    'sort-order': Telemetry_queryMetricsQuerySpec_sort_order = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'kind': {
            required: false,
            type: 'string'
        },
        'api-version': {
            required: false,
            type: 'string'
        },
        'name': {
            description:  'Name is the name of the API object.',
            required: false,
            type: 'string'
        },
        'selector': {
            required: false,
            type: 'object'
        },
        'fields': {
            description:  'must start and end with alpha numeric and can have alphanumeric, -, _, .',
            required: false,
            type: 'Array<string>'
        },
        'function': {
            enum: Telemetry_queryMetricsQuerySpec_function,
            default: 'none',
            required: true,
            type: 'string'
        },
        'start-time': {
            required: false,
            type: 'Date'
        },
        'end-time': {
            required: false,
            type: 'Date'
        },
        'group-by-time': {
            description:  'should be a valid time duration ',
            hint:  '2h',
            required: false,
            type: 'string'
        },
        'group-by-field': {
            description:  'must start and end with alpha numeric and can have alphanumeric, -, _, .',
            required: false,
            type: 'string'
        },
        'pagination': {
            required: false,
            type: 'object'
        },
        'sort-order': {
            enum: Telemetry_queryMetricsQuerySpec_sort_order,
            default: 'ascending',
            required: true,
            type: 'string'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return Telemetry_queryMetricsQuerySpec.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return Telemetry_queryMetricsQuerySpec.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (Telemetry_queryMetricsQuerySpec.propInfo[prop] != null &&
                        Telemetry_queryMetricsQuerySpec.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['selector'] = new FieldsSelector();
        this['fields'] = new Array<string>();
        this['pagination'] = new Telemetry_queryPaginationSpec();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('kind')) {
            this['kind'] = Telemetry_queryMetricsQuerySpec.propInfo['kind'].default;
        } else {
            this['kind'] = null
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('api-version')) {
            this['api-version'] = Telemetry_queryMetricsQuerySpec.propInfo['api-version'].default;
        } else {
            this['api-version'] = null
        }
        if (values && values['name'] != null) {
            this['name'] = values['name'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('name')) {
            this['name'] = Telemetry_queryMetricsQuerySpec.propInfo['name'].default;
        } else {
            this['name'] = null
        }
        if (values) {
            this['selector'].setValues(values['selector'], fillDefaults);
        } else {
            this['selector'].setValues(null, fillDefaults);
        }
        if (values && values['fields'] != null) {
            this['fields'] = values['fields'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('fields')) {
            this['fields'] = [ Telemetry_queryMetricsQuerySpec.propInfo['fields'].default];
        } else {
            this['fields'] = [];
        }
        if (values && values['function'] != null) {
            this['function'] = values['function'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('function')) {
            this['function'] = <Telemetry_queryMetricsQuerySpec_function>  Telemetry_queryMetricsQuerySpec.propInfo['function'].default;
        } else {
            this['function'] = null
        }
        if (values && values['start-time'] != null) {
            this['start-time'] = values['start-time'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('start-time')) {
            this['start-time'] = Telemetry_queryMetricsQuerySpec.propInfo['start-time'].default;
        } else {
            this['start-time'] = null
        }
        if (values && values['end-time'] != null) {
            this['end-time'] = values['end-time'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('end-time')) {
            this['end-time'] = Telemetry_queryMetricsQuerySpec.propInfo['end-time'].default;
        } else {
            this['end-time'] = null
        }
        if (values && values['group-by-time'] != null) {
            this['group-by-time'] = values['group-by-time'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('group-by-time')) {
            this['group-by-time'] = Telemetry_queryMetricsQuerySpec.propInfo['group-by-time'].default;
        } else {
            this['group-by-time'] = null
        }
        if (values && values['group-by-field'] != null) {
            this['group-by-field'] = values['group-by-field'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('group-by-field')) {
            this['group-by-field'] = Telemetry_queryMetricsQuerySpec.propInfo['group-by-field'].default;
        } else {
            this['group-by-field'] = null
        }
        if (values) {
            this['pagination'].setValues(values['pagination'], fillDefaults);
        } else {
            this['pagination'].setValues(null, fillDefaults);
        }
        if (values && values['sort-order'] != null) {
            this['sort-order'] = values['sort-order'];
        } else if (fillDefaults && Telemetry_queryMetricsQuerySpec.hasDefaultValue('sort-order')) {
            this['sort-order'] = <Telemetry_queryMetricsQuerySpec_sort_order>  Telemetry_queryMetricsQuerySpec.propInfo['sort-order'].default;
        } else {
            this['sort-order'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': CustomFormControl(new FormControl(this['kind']), Telemetry_queryMetricsQuerySpec.propInfo['kind']),
                'api-version': CustomFormControl(new FormControl(this['api-version']), Telemetry_queryMetricsQuerySpec.propInfo['api-version']),
                'name': CustomFormControl(new FormControl(this['name'], [patternValidator('^[a-zA-Z0-9][\\w\\-\\.]*[a-zA-Z0-9]$', 'Name is the name of the API object.'), ]), Telemetry_queryMetricsQuerySpec.propInfo['name']),
                'selector': CustomFormGroup(this['selector'].$formGroup, Telemetry_queryMetricsQuerySpec.propInfo['selector'].required),
                'fields': CustomFormControl(new FormControl(this['fields']), Telemetry_queryMetricsQuerySpec.propInfo['fields']),
                'function': CustomFormControl(new FormControl(this['function'], [required, enumValidator(Telemetry_queryMetricsQuerySpec_function), ]), Telemetry_queryMetricsQuerySpec.propInfo['function']),
                'start-time': CustomFormControl(new FormControl(this['start-time']), Telemetry_queryMetricsQuerySpec.propInfo['start-time']),
                'end-time': CustomFormControl(new FormControl(this['end-time']), Telemetry_queryMetricsQuerySpec.propInfo['end-time']),
                'group-by-time': CustomFormControl(new FormControl(this['group-by-time']), Telemetry_queryMetricsQuerySpec.propInfo['group-by-time']),
                'group-by-field': CustomFormControl(new FormControl(this['group-by-field'], [patternValidator('^[a-zA-Z0-9][\\w\\-\\.]*[a-zA-Z0-9]$', 'must start and end with alpha numeric and can have alphanumeric, -, _, .'), ]), Telemetry_queryMetricsQuerySpec.propInfo['group-by-field']),
                'pagination': CustomFormGroup(this['pagination'].$formGroup, Telemetry_queryMetricsQuerySpec.propInfo['pagination'].required),
                'sort-order': CustomFormControl(new FormControl(this['sort-order'], [required, enumValidator(Telemetry_queryMetricsQuerySpec_sort_order), ]), Telemetry_queryMetricsQuerySpec.propInfo['sort-order']),
            });
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('selector') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('selector').get(field);
                control.updateValueAndValidity();
            });
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('pagination') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('pagination').get(field);
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
            this._formGroup.controls['name'].setValue(this['name']);
            this['selector'].setFormGroupValuesToBeModelValues();
            this._formGroup.controls['fields'].setValue(this['fields']);
            this._formGroup.controls['function'].setValue(this['function']);
            this._formGroup.controls['start-time'].setValue(this['start-time']);
            this._formGroup.controls['end-time'].setValue(this['end-time']);
            this._formGroup.controls['group-by-time'].setValue(this['group-by-time']);
            this._formGroup.controls['group-by-field'].setValue(this['group-by-field']);
            this['pagination'].setFormGroupValuesToBeModelValues();
            this._formGroup.controls['sort-order'].setValue(this['sort-order']);
        }
    }
}

