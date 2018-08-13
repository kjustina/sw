/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { LabelsSelector, ILabelsSelector } from './labels-selector.model';

export interface IMetrics_queryObjectSelector {
    'kind'?: string;
    'name'?: string;
    'tenant'?: string;
    'namespace'?: string;
    'labels'?: ILabelsSelector;
}


export class Metrics_queryObjectSelector extends BaseModel implements IMetrics_queryObjectSelector {
    /** Kind represents the type of the API object. */
    'kind': string = null;
    /** Name is the name of the API object. */
    'name': string = null;
    /** Tenant the object belongs to. */
    'tenant': string = null;
    /** Namespace the object belongs to. */
    'namespace': string = null;
    /** Labels is a selector expression that selects one or more objects
    based on attached labels. */
    'labels': LabelsSelector = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'kind': {
            description:  'Kind represents the type of the API object.',
            type: 'string'
                    },
        'name': {
            description:  'Name is the name of the API object.',
            type: 'string'
                    },
        'tenant': {
            description:  'Tenant the object belongs to.',
            type: 'string'
                    },
        'namespace': {
            description:  'Namespace the object belongs to.',
            type: 'string'
                    },
        'labels': {
            description:  'Labels is a selector expression that selects one or more objects based on attached labels.',
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return Metrics_queryObjectSelector.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (Metrics_queryObjectSelector.propInfo[prop] != null &&
                        Metrics_queryObjectSelector.propInfo[prop].default != null &&
                        Metrics_queryObjectSelector.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['labels'] = new LabelsSelector();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['kind'] != null) {
            this['kind'] = values['kind'];
        } else if (Metrics_queryObjectSelector.hasDefaultValue('kind')) {
            this['kind'] = Metrics_queryObjectSelector.propInfo['kind'].default;
        }
        if (values && values['name'] != null) {
            this['name'] = values['name'];
        } else if (Metrics_queryObjectSelector.hasDefaultValue('name')) {
            this['name'] = Metrics_queryObjectSelector.propInfo['name'].default;
        }
        if (values && values['tenant'] != null) {
            this['tenant'] = values['tenant'];
        } else if (Metrics_queryObjectSelector.hasDefaultValue('tenant')) {
            this['tenant'] = Metrics_queryObjectSelector.propInfo['tenant'].default;
        }
        if (values && values['namespace'] != null) {
            this['namespace'] = values['namespace'];
        } else if (Metrics_queryObjectSelector.hasDefaultValue('namespace')) {
            this['namespace'] = Metrics_queryObjectSelector.propInfo['namespace'].default;
        }
        if (values) {
            this['labels'].setValues(values['labels']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'kind': new FormControl(this['kind']),
                'name': new FormControl(this['name']),
                'tenant': new FormControl(this['tenant']),
                'namespace': new FormControl(this['namespace']),
                'labels': this['labels'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['kind'].setValue(this['kind']);
            this._formGroup.controls['name'].setValue(this['name']);
            this._formGroup.controls['tenant'].setValue(this['tenant']);
            this._formGroup.controls['namespace'].setValue(this['namespace']);
            this['labels'].setFormGroupValues();
        }
    }
}

