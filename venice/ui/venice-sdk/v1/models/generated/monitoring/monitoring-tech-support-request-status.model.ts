/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';

import { MonitoringTechSupportRequestStatus_status,  } from './enums';

export interface IMonitoringTechSupportRequestStatus {
    'instance-id'?: string;
    'status': MonitoringTechSupportRequestStatus_status;
    'ctrlr-node-results'?: object;
    'dsc-results'?: object;
}


export class MonitoringTechSupportRequestStatus extends BaseModel implements IMonitoringTechSupportRequestStatus {
    'instance-id': string = null;
    'status': MonitoringTechSupportRequestStatus_status = null;
    'ctrlr-node-results': object = null;
    'dsc-results': object = null;
    public static propInfo: { [prop in keyof IMonitoringTechSupportRequestStatus]: PropInfoItem } = {
        'instance-id': {
            required: false,
            type: 'string'
        },
        'status': {
            enum: MonitoringTechSupportRequestStatus_status,
            default: 'scheduled',
            required: true,
            type: 'string'
        },
        'ctrlr-node-results': {
            required: false,
            type: 'object'
        },
        'dsc-results': {
            required: false,
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return MonitoringTechSupportRequestStatus.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return MonitoringTechSupportRequestStatus.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (MonitoringTechSupportRequestStatus.propInfo[prop] != null &&
                        MonitoringTechSupportRequestStatus.propInfo[prop].default != null);
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
        if (values && values['instance-id'] != null) {
            this['instance-id'] = values['instance-id'];
        } else if (fillDefaults && MonitoringTechSupportRequestStatus.hasDefaultValue('instance-id')) {
            this['instance-id'] = MonitoringTechSupportRequestStatus.propInfo['instance-id'].default;
        } else {
            this['instance-id'] = null
        }
        if (values && values['status'] != null) {
            this['status'] = values['status'];
        } else if (fillDefaults && MonitoringTechSupportRequestStatus.hasDefaultValue('status')) {
            this['status'] = <MonitoringTechSupportRequestStatus_status>  MonitoringTechSupportRequestStatus.propInfo['status'].default;
        } else {
            this['status'] = null
        }
        if (values && values['ctrlr-node-results'] != null) {
            this['ctrlr-node-results'] = values['ctrlr-node-results'];
        } else if (fillDefaults && MonitoringTechSupportRequestStatus.hasDefaultValue('ctrlr-node-results')) {
            this['ctrlr-node-results'] = MonitoringTechSupportRequestStatus.propInfo['ctrlr-node-results'].default;
        } else {
            this['ctrlr-node-results'] = null
        }
        if (values && values['dsc-results'] != null) {
            this['dsc-results'] = values['dsc-results'];
        } else if (fillDefaults && MonitoringTechSupportRequestStatus.hasDefaultValue('dsc-results')) {
            this['dsc-results'] = MonitoringTechSupportRequestStatus.propInfo['dsc-results'].default;
        } else {
            this['dsc-results'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'instance-id': CustomFormControl(new FormControl(this['instance-id']), MonitoringTechSupportRequestStatus.propInfo['instance-id']),
                'status': CustomFormControl(new FormControl(this['status'], [required, enumValidator(MonitoringTechSupportRequestStatus_status), ]), MonitoringTechSupportRequestStatus.propInfo['status']),
                'ctrlr-node-results': CustomFormControl(new FormControl(this['ctrlr-node-results']), MonitoringTechSupportRequestStatus.propInfo['ctrlr-node-results']),
                'dsc-results': CustomFormControl(new FormControl(this['dsc-results']), MonitoringTechSupportRequestStatus.propInfo['dsc-results']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['instance-id'].setValue(this['instance-id']);
            this._formGroup.controls['status'].setValue(this['status']);
            this._formGroup.controls['ctrlr-node-results'].setValue(this['ctrlr-node-results']);
            this._formGroup.controls['dsc-results'].setValue(this['dsc-results']);
        }
    }
}

