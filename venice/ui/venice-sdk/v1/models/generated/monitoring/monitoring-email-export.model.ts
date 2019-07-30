/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';


export interface IMonitoringEmailExport {
    'email-list'?: Array<string>;
}


export class MonitoringEmailExport extends BaseModel implements IMonitoringEmailExport {
    'email-list': Array<string> = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'email-list': {
            required: false,
            type: 'Array<string>'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return MonitoringEmailExport.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return MonitoringEmailExport.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (MonitoringEmailExport.propInfo[prop] != null &&
                        MonitoringEmailExport.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this['email-list'] = new Array<string>();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['email-list'] != null) {
            this['email-list'] = values['email-list'];
        } else if (fillDefaults && MonitoringEmailExport.hasDefaultValue('email-list')) {
            this['email-list'] = [ MonitoringEmailExport.propInfo['email-list'].default];
        } else {
            this['email-list'] = [];
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'email-list': CustomFormControl(new FormControl(this['email-list']), MonitoringEmailExport.propInfo['email-list']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['email-list'].setValue(this['email-list']);
        }
    }
}

