/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { ApiObjectMeta, IApiObjectMeta } from './api-object-meta.model';
import { BrowserObject_query_type,  } from './enums';

export interface IBrowserObject {
    'kind'?: string;
    'api-version'?: string;
    'meta'?: IApiObjectMeta;
    'uri'?: string;
    'reverse'?: string;
    'query-type': BrowserObject_query_type;
    'links'?: object;
}


export class BrowserObject extends BaseModel implements IBrowserObject {
    'kind': string = null;
    'api-version': string = null;
    'meta': ApiObjectMeta = null;
    'uri': string = null;
    'reverse': string = null;
    'query-type': BrowserObject_query_type = null;
    /** Links points to the relations of the object. The key for the map is the path to the filed which
      is causing the relation. */
    'links': object = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'kind': {
            required: false,
            type: 'string'
        },
        'api-version': {
            required: false,
            type: 'string'
        },
        'meta': {
            required: false,
            type: 'object'
        },
        'uri': {
            required: false,
            type: 'string'
        },
        'reverse': {
            required: false,
            type: 'string'
        },
        'query-type': {
            enum: BrowserObject_query_type,
            default: 'dependencies',
            required: true,
            type: 'string'
        },
        'links': {
            description:  'Links points to the relations of the object. The key for the map is the path to the filed which   is causing the relation.',
            required: false,
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return BrowserObject.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return BrowserObject.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (BrowserObject.propInfo[prop] != null &&
                        BrowserObject.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['meta'] = new ApiObjectMeta();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        } else if (fillDefaults && BrowserObject.hasDefaultValue('kind')) {
            this['kind'] = BrowserObject.propInfo['kind'].default;
        } else {
            this['kind'] = null
        }
        if (values && values['api-version'] != null) {
            this['api-version'] = values['api-version'];
        } else if (fillDefaults && BrowserObject.hasDefaultValue('api-version')) {
            this['api-version'] = BrowserObject.propInfo['api-version'].default;
        } else {
            this['api-version'] = null
        }
        if (values) {
            this['meta'].setValues(values['meta'], fillDefaults);
        } else {
            this['meta'].setValues(null, fillDefaults);
        }
        if (values && values['uri'] != null) {
            this['uri'] = values['uri'];
        } else if (fillDefaults && BrowserObject.hasDefaultValue('uri')) {
            this['uri'] = BrowserObject.propInfo['uri'].default;
        } else {
            this['uri'] = null
        }
        if (values && values['reverse'] != null) {
            this['reverse'] = values['reverse'];
        } else if (fillDefaults && BrowserObject.hasDefaultValue('reverse')) {
            this['reverse'] = BrowserObject.propInfo['reverse'].default;
        } else {
            this['reverse'] = null
        }
        if (values && values['query-type'] != null) {
            this['query-type'] = values['query-type'];
        } else if (fillDefaults && BrowserObject.hasDefaultValue('query-type')) {
            this['query-type'] = <BrowserObject_query_type>  BrowserObject.propInfo['query-type'].default;
        } else {
            this['query-type'] = null
        }
        if (values && values['links'] != null) {
            this['links'] = values['links'];
        } else if (fillDefaults && BrowserObject.hasDefaultValue('links')) {
            this['links'] = BrowserObject.propInfo['links'].default;
        } else {
            this['links'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': CustomFormControl(new FormControl(this['kind']), BrowserObject.propInfo['kind']),
                'api-version': CustomFormControl(new FormControl(this['api-version']), BrowserObject.propInfo['api-version']),
                'meta': CustomFormGroup(this['meta'].$formGroup, BrowserObject.propInfo['meta'].required),
                'uri': CustomFormControl(new FormControl(this['uri']), BrowserObject.propInfo['uri']),
                'reverse': CustomFormControl(new FormControl(this['reverse']), BrowserObject.propInfo['reverse']),
                'query-type': CustomFormControl(new FormControl(this['query-type'], [required, enumValidator(BrowserObject_query_type), ]), BrowserObject.propInfo['query-type']),
                'links': CustomFormControl(new FormControl(this['links']), BrowserObject.propInfo['links']),
            });
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('meta') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('meta').get(field);
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
            this['meta'].setFormGroupValuesToBeModelValues();
            this._formGroup.controls['uri'].setValue(this['uri']);
            this._formGroup.controls['reverse'].setValue(this['reverse']);
            this._formGroup.controls['query-type'].setValue(this['query-type']);
            this._formGroup.controls['links'].setValue(this['links']);
        }
    }
}

