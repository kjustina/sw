/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { ClusterAutoMsgNodeWatchHelperWatchEvent, IClusterAutoMsgNodeWatchHelperWatchEvent } from './cluster-auto-msg-node-watch-helper-watch-event.model';

export interface IClusterAutoMsgNodeWatchHelper {
    'events'?: Array<IClusterAutoMsgNodeWatchHelperWatchEvent>;
}


export class ClusterAutoMsgNodeWatchHelper extends BaseModel implements IClusterAutoMsgNodeWatchHelper {
    'events': Array<ClusterAutoMsgNodeWatchHelperWatchEvent> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'events': {
            required: false,
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ClusterAutoMsgNodeWatchHelper.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return ClusterAutoMsgNodeWatchHelper.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ClusterAutoMsgNodeWatchHelper.propInfo[prop] != null &&
                        ClusterAutoMsgNodeWatchHelper.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['events'] = new Array<ClusterAutoMsgNodeWatchHelperWatchEvent>();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values) {
            this.fillModelArray<ClusterAutoMsgNodeWatchHelperWatchEvent>(this, 'events', values['events'], ClusterAutoMsgNodeWatchHelperWatchEvent);
        } else {
            this['events'] = [];
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'events': new FormArray([]),
            });
            // generate FormArray control elements
            this.fillFormArray<ClusterAutoMsgNodeWatchHelperWatchEvent>('events', this['events'], ClusterAutoMsgNodeWatchHelperWatchEvent);
            // We force recalculation of controls under a form group
            Object.keys((this._formGroup.get('events') as FormGroup).controls).forEach(field => {
                const control = this._formGroup.get('events').get(field);
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
            this.fillModelArray<ClusterAutoMsgNodeWatchHelperWatchEvent>(this, 'events', this['events'], ClusterAutoMsgNodeWatchHelperWatchEvent);
        }
    }
}

