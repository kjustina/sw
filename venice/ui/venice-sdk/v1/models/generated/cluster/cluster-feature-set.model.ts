/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';


export interface IClusterFeatureSet {
    'InterVMServices'?: boolean;
    'FlowAware'?: boolean;
    'Firewall'?: boolean;
    '_ui'?: any;
}


export class ClusterFeatureSet extends BaseModel implements IClusterFeatureSet {
    /** Field for holding arbitrary ui state */
    '_ui': any = {};
    /** Ui-hint: InterVMServices. */
    'InterVMServices': boolean = null;
    /** Ui-hint: FlowAware. */
    'FlowAware': boolean = null;
    /** Ui-hint: Firewall. */
    'Firewall': boolean = null;
    public static propInfo: { [prop in keyof IClusterFeatureSet]: PropInfoItem } = {
        'InterVMServices': {
            description:  `Ui-hint: InterVMServices.`,
            required: false,
            type: 'boolean'
        },
        'FlowAware': {
            description:  `Ui-hint: FlowAware.`,
            required: false,
            type: 'boolean'
        },
        'Firewall': {
            description:  `Ui-hint: Firewall.`,
            required: false,
            type: 'boolean'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return ClusterFeatureSet.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return ClusterFeatureSet.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (ClusterFeatureSet.propInfo[prop] != null &&
                        ClusterFeatureSet.propInfo[prop].default != null);
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
        if (values && values['_ui']) {
            this['_ui'] = values['_ui']
        }
        if (values && values['InterVMServices'] != null) {
            this['InterVMServices'] = values['InterVMServices'];
        } else if (fillDefaults && ClusterFeatureSet.hasDefaultValue('InterVMServices')) {
            this['InterVMServices'] = ClusterFeatureSet.propInfo['InterVMServices'].default;
        } else {
            this['InterVMServices'] = null
        }
        if (values && values['FlowAware'] != null) {
            this['FlowAware'] = values['FlowAware'];
        } else if (fillDefaults && ClusterFeatureSet.hasDefaultValue('FlowAware')) {
            this['FlowAware'] = ClusterFeatureSet.propInfo['FlowAware'].default;
        } else {
            this['FlowAware'] = null
        }
        if (values && values['Firewall'] != null) {
            this['Firewall'] = values['Firewall'];
        } else if (fillDefaults && ClusterFeatureSet.hasDefaultValue('Firewall')) {
            this['Firewall'] = ClusterFeatureSet.propInfo['Firewall'].default;
        } else {
            this['Firewall'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'InterVMServices': CustomFormControl(new FormControl(this['InterVMServices']), ClusterFeatureSet.propInfo['InterVMServices']),
                'FlowAware': CustomFormControl(new FormControl(this['FlowAware']), ClusterFeatureSet.propInfo['FlowAware']),
                'Firewall': CustomFormControl(new FormControl(this['Firewall']), ClusterFeatureSet.propInfo['Firewall']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['InterVMServices'].setValue(this['InterVMServices']);
            this._formGroup.controls['FlowAware'].setValue(this['FlowAware']);
            this._formGroup.controls['Firewall'].setValue(this['Firewall']);
        }
    }
}

