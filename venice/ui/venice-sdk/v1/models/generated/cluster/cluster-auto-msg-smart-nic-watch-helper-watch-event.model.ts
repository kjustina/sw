/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { ClusterSmartNIC, IClusterSmartNIC } from './cluster-smart-nic.model';

export interface IClusterAutoMsgSmartNICWatchHelperWatchEvent {
    'Type'?: string;
    'Object'?: IClusterSmartNIC;
}


export class ClusterAutoMsgSmartNICWatchHelperWatchEvent extends BaseModel implements IClusterAutoMsgSmartNICWatchHelperWatchEvent {
    'Type': string = null;
    'Object': ClusterSmartNIC = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'Type': {
            type: 'string'
                    },
        'Object': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ClusterAutoMsgSmartNICWatchHelperWatchEvent.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ClusterAutoMsgSmartNICWatchHelperWatchEvent.propInfo[prop] != null &&
                        ClusterAutoMsgSmartNICWatchHelperWatchEvent.propInfo[prop].default != null &&
                        ClusterAutoMsgSmartNICWatchHelperWatchEvent.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['Object'] = new ClusterSmartNIC();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['Type'] != null) {
            this['Type'] = values['Type'];
        } else if (ClusterAutoMsgSmartNICWatchHelperWatchEvent.hasDefaultValue('Type')) {
            this['Type'] = ClusterAutoMsgSmartNICWatchHelperWatchEvent.propInfo['Type'].default;
        }
        if (values) {
            this['Object'].setValues(values['Object']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'Type': new FormControl(this['Type']),
                'Object': this['Object'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['Type'].setValue(this['Type']);
            this['Object'].setFormGroupValues();
        }
    }
}

