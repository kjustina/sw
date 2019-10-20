/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { WorkloadEndpointMigrationStatus_status,  WorkloadEndpointMigrationStatus_status_uihint  } from './enums';

export interface IWorkloadEndpointMigrationStatus {
    'status': WorkloadEndpointMigrationStatus_status;
    'start-time'?: Date;
    'end-time'?: Date;
    'source-ip'?: string;
    'destination-ip'?: string;
    'reason'?: string;
}


export class WorkloadEndpointMigrationStatus extends BaseModel implements IWorkloadEndpointMigrationStatus {
    'status': WorkloadEndpointMigrationStatus_status = null;
    'start-time': Date = null;
    'end-time': Date = null;
    'source-ip': string = null;
    'destination-ip': string = null;
    'reason': string = null;
    public static propInfo: { [prop in keyof IWorkloadEndpointMigrationStatus]: PropInfoItem } = {
        'status': {
            enum: WorkloadEndpointMigrationStatus_status_uihint,
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
        'source-ip': {
            required: false,
            type: 'string'
        },
        'destination-ip': {
            required: false,
            type: 'string'
        },
        'reason': {
            required: false,
            type: 'string'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return WorkloadEndpointMigrationStatus.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return WorkloadEndpointMigrationStatus.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (WorkloadEndpointMigrationStatus.propInfo[prop] != null &&
                        WorkloadEndpointMigrationStatus.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this._inputValue = values;
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['status'] != null) {
            this['status'] = values['status'];
        } else if (fillDefaults && WorkloadEndpointMigrationStatus.hasDefaultValue('status')) {
            this['status'] = <WorkloadEndpointMigrationStatus_status>  WorkloadEndpointMigrationStatus.propInfo['status'].default;
        } else {
            this['status'] = null
        }
        if (values && values['start-time'] != null) {
            this['start-time'] = values['start-time'];
        } else if (fillDefaults && WorkloadEndpointMigrationStatus.hasDefaultValue('start-time')) {
            this['start-time'] = WorkloadEndpointMigrationStatus.propInfo['start-time'].default;
        } else {
            this['start-time'] = null
        }
        if (values && values['end-time'] != null) {
            this['end-time'] = values['end-time'];
        } else if (fillDefaults && WorkloadEndpointMigrationStatus.hasDefaultValue('end-time')) {
            this['end-time'] = WorkloadEndpointMigrationStatus.propInfo['end-time'].default;
        } else {
            this['end-time'] = null
        }
        if (values && values['source-ip'] != null) {
            this['source-ip'] = values['source-ip'];
        } else if (fillDefaults && WorkloadEndpointMigrationStatus.hasDefaultValue('source-ip')) {
            this['source-ip'] = WorkloadEndpointMigrationStatus.propInfo['source-ip'].default;
        } else {
            this['source-ip'] = null
        }
        if (values && values['destination-ip'] != null) {
            this['destination-ip'] = values['destination-ip'];
        } else if (fillDefaults && WorkloadEndpointMigrationStatus.hasDefaultValue('destination-ip')) {
            this['destination-ip'] = WorkloadEndpointMigrationStatus.propInfo['destination-ip'].default;
        } else {
            this['destination-ip'] = null
        }
        if (values && values['reason'] != null) {
            this['reason'] = values['reason'];
        } else if (fillDefaults && WorkloadEndpointMigrationStatus.hasDefaultValue('reason')) {
            this['reason'] = WorkloadEndpointMigrationStatus.propInfo['reason'].default;
        } else {
            this['reason'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'status': CustomFormControl(new FormControl(this['status'], [required, enumValidator(WorkloadEndpointMigrationStatus_status), ]), WorkloadEndpointMigrationStatus.propInfo['status']),
                'start-time': CustomFormControl(new FormControl(this['start-time']), WorkloadEndpointMigrationStatus.propInfo['start-time']),
                'end-time': CustomFormControl(new FormControl(this['end-time']), WorkloadEndpointMigrationStatus.propInfo['end-time']),
                'source-ip': CustomFormControl(new FormControl(this['source-ip']), WorkloadEndpointMigrationStatus.propInfo['source-ip']),
                'destination-ip': CustomFormControl(new FormControl(this['destination-ip']), WorkloadEndpointMigrationStatus.propInfo['destination-ip']),
                'reason': CustomFormControl(new FormControl(this['reason']), WorkloadEndpointMigrationStatus.propInfo['reason']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['status'].setValue(this['status']);
            this._formGroup.controls['start-time'].setValue(this['start-time']);
            this._formGroup.controls['end-time'].setValue(this['end-time']);
            this._formGroup.controls['source-ip'].setValue(this['source-ip']);
            this._formGroup.controls['destination-ip'].setValue(this['destination-ip']);
            this._formGroup.controls['reason'].setValue(this['reason']);
        }
    }
}

