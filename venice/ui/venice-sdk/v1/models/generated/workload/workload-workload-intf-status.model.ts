/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';


export interface IWorkloadWorkloadIntfStatus {
    'ip-addresses'?: Array<string>;
    'endpoint'?: string;
}


export class WorkloadWorkloadIntfStatus extends BaseModel implements IWorkloadWorkloadIntfStatus {
    'ip-addresses': Array<string> = null;
    'endpoint': string = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'ip-addresses': {
            required: false,
            type: 'Array<string>'
        },
        'endpoint': {
            required: false,
            type: 'string'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return WorkloadWorkloadIntfStatus.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return WorkloadWorkloadIntfStatus.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (WorkloadWorkloadIntfStatus.propInfo[prop] != null &&
                        WorkloadWorkloadIntfStatus.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['ip-addresses'] = new Array<string>();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['ip-addresses'] != null) {
            this['ip-addresses'] = values['ip-addresses'];
        } else if (fillDefaults && WorkloadWorkloadIntfStatus.hasDefaultValue('ip-addresses')) {
            this['ip-addresses'] = [ WorkloadWorkloadIntfStatus.propInfo['ip-addresses'].default];
        } else {
            this['ip-addresses'] = [];
        }
        if (values && values['endpoint'] != null) {
            this['endpoint'] = values['endpoint'];
        } else if (fillDefaults && WorkloadWorkloadIntfStatus.hasDefaultValue('endpoint')) {
            this['endpoint'] = WorkloadWorkloadIntfStatus.propInfo['endpoint'].default;
        } else {
            this['endpoint'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'ip-addresses': CustomFormControl(new FormControl(this['ip-addresses']), WorkloadWorkloadIntfStatus.propInfo['ip-addresses']),
                'endpoint': CustomFormControl(new FormControl(this['endpoint']), WorkloadWorkloadIntfStatus.propInfo['endpoint']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['ip-addresses'].setValue(this['ip-addresses']);
            this._formGroup.controls['endpoint'].setValue(this['endpoint']);
        }
    }
}

