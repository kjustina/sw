/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { ClusterQuorumMemberCondition, IClusterQuorumMemberCondition } from './cluster-quorum-member-condition.model';

export interface IClusterQuorumMemberStatus {
    'id'?: string;
    'name'?: string;
    'status'?: string;
    'term'?: string;
    'conditions'?: Array<IClusterQuorumMemberCondition>;
}


export class ClusterQuorumMemberStatus extends BaseModel implements IClusterQuorumMemberStatus {
    'id': string = null;
    'name': string = null;
    'status': string = null;
    'term': string = null;
    'conditions': Array<ClusterQuorumMemberCondition> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'id': {
            required: false,
            type: 'string'
        },
        'name': {
            required: false,
            type: 'string'
        },
        'status': {
            required: false,
            type: 'string'
        },
        'term': {
            required: false,
            type: 'string'
        },
        'conditions': {
            required: false,
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ClusterQuorumMemberStatus.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return ClusterQuorumMemberStatus.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ClusterQuorumMemberStatus.propInfo[prop] != null &&
                        ClusterQuorumMemberStatus.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['conditions'] = new Array<ClusterQuorumMemberCondition>();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['id'] != null) {
            this['id'] = values['id'];
        } else if (fillDefaults && ClusterQuorumMemberStatus.hasDefaultValue('id')) {
            this['id'] = ClusterQuorumMemberStatus.propInfo['id'].default;
        } else {
            this['id'] = null
        }
        if (values && values['name'] != null) {
            this['name'] = values['name'];
        } else if (fillDefaults && ClusterQuorumMemberStatus.hasDefaultValue('name')) {
            this['name'] = ClusterQuorumMemberStatus.propInfo['name'].default;
        } else {
            this['name'] = null
        }
        if (values && values['status'] != null) {
            this['status'] = values['status'];
        } else if (fillDefaults && ClusterQuorumMemberStatus.hasDefaultValue('status')) {
            this['status'] = ClusterQuorumMemberStatus.propInfo['status'].default;
        } else {
            this['status'] = null
        }
        if (values && values['term'] != null) {
            this['term'] = values['term'];
        } else if (fillDefaults && ClusterQuorumMemberStatus.hasDefaultValue('term')) {
            this['term'] = ClusterQuorumMemberStatus.propInfo['term'].default;
        } else {
            this['term'] = null
        }
        if (values) {
            this.fillModelArray<ClusterQuorumMemberCondition>(this, 'conditions', values['conditions'], ClusterQuorumMemberCondition);
        } else {
            this['conditions'] = [];
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'id': CustomFormControl(new FormControl(this['id']), ClusterQuorumMemberStatus.propInfo['id']),
                'name': CustomFormControl(new FormControl(this['name']), ClusterQuorumMemberStatus.propInfo['name']),
                'status': CustomFormControl(new FormControl(this['status']), ClusterQuorumMemberStatus.propInfo['status']),
                'term': CustomFormControl(new FormControl(this['term']), ClusterQuorumMemberStatus.propInfo['term']),
                'conditions': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<ClusterQuorumMemberCondition>('conditions', this['conditions'], ClusterQuorumMemberCondition);
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('conditions') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('conditions').get(field);
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
            this._formGroup.controls['id'].setValue(this['id']);
            this._formGroup.controls['name'].setValue(this['name']);
            this._formGroup.controls['status'].setValue(this['status']);
            this._formGroup.controls['term'].setValue(this['term']);
            this.fillModelArray<ClusterQuorumMemberCondition>(this, 'conditions', this['conditions'], ClusterQuorumMemberCondition);
        }
    }
}

