/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';


export interface IClusterClusterStatus {
    'leader'?: string;
    'last-leader-transition-time'?: Date;
    'build-version'?: string;
    'vcs-commit'?: string;
    'build-date'?: string;
}


export class ClusterClusterStatus extends BaseModel implements IClusterClusterStatus {
    /** Leader contains the node name of the cluster leader. */
    'leader': string = null;
    'last-leader-transition-time': Date = null;
    'build-version': string = null;
    'vcs-commit': string = null;
    'build-date': string = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'leader': {
            description:  'Leader contains the node name of the cluster leader.',
            type: 'string'
                    },
        'last-leader-transition-time': {
            type: 'Date'
                    },
        'build-version': {
            type: 'string'
                    },
        'vcs-commit': {
            type: 'string'
                    },
        'build-date': {
            type: 'string'
                    },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ClusterClusterStatus.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ClusterClusterStatus.propInfo[prop] != null &&
                        ClusterClusterStatus.propInfo[prop].default != null &&
                        ClusterClusterStatus.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values && values['leader'] != null) {
            this['leader'] = values['leader'];
        } else if (ClusterClusterStatus.hasDefaultValue('leader')) {
            this['leader'] = ClusterClusterStatus.propInfo['leader'].default;
        }
        if (values && values['last-leader-transition-time'] != null) {
            this['last-leader-transition-time'] = values['last-leader-transition-time'];
        } else if (ClusterClusterStatus.hasDefaultValue('last-leader-transition-time')) {
            this['last-leader-transition-time'] = ClusterClusterStatus.propInfo['last-leader-transition-time'].default;
        }
        if (values && values['build-version'] != null) {
            this['build-version'] = values['build-version'];
        } else if (ClusterClusterStatus.hasDefaultValue('build-version')) {
            this['build-version'] = ClusterClusterStatus.propInfo['build-version'].default;
        }
        if (values && values['vcs-commit'] != null) {
            this['vcs-commit'] = values['vcs-commit'];
        } else if (ClusterClusterStatus.hasDefaultValue('vcs-commit')) {
            this['vcs-commit'] = ClusterClusterStatus.propInfo['vcs-commit'].default;
        }
        if (values && values['build-date'] != null) {
            this['build-date'] = values['build-date'];
        } else if (ClusterClusterStatus.hasDefaultValue('build-date')) {
            this['build-date'] = ClusterClusterStatus.propInfo['build-date'].default;
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'leader': new FormControl(this['leader']),
                'last-leader-transition-time': new FormControl(this['last-leader-transition-time']),
                'build-version': new FormControl(this['build-version']),
                'vcs-commit': new FormControl(this['vcs-commit']),
                'build-date': new FormControl(this['build-date']),
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['leader'].setValue(this['leader']);
            this._formGroup.controls['last-leader-transition-time'].setValue(this['last-leader-transition-time']);
            this._formGroup.controls['build-version'].setValue(this['build-version']);
            this._formGroup.controls['vcs-commit'].setValue(this['vcs-commit']);
            this._formGroup.controls['build-date'].setValue(this['build-date']);
        }
    }
}

