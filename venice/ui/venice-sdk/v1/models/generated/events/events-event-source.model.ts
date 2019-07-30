/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, minLengthValidator, maxLengthValidator, required, enumValidator, patternValidator, CustomFormControl, CustomFormGroup } from '../../../utils/validators';
import { BaseModel, PropInfoItem } from '../basemodel/base-model';


export interface IEventsEventSource {
    'component'?: string;
    'node-name'?: string;
}


export class EventsEventSource extends BaseModel implements IEventsEventSource {
    /** Component from which the event is generated. */
    'component': string = null;
    /** Name of the venice or workload node which is generating the event. */
    'node-name': string = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'component': {
            description:  'Component from which the event is generated.',
            required: false,
            type: 'string'
        },
        'node-name': {
            description:  'Name of the venice or workload node which is generating the event.',
            required: false,
            type: 'string'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return EventsEventSource.propInfo[propName];
    }

    public getPropInfoConfig(): { [key:string]:PropInfoItem } {
        return EventsEventSource.propInfo;
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (EventsEventSource.propInfo[prop] != null &&
                        EventsEventSource.propInfo[prop].default != null);
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any, setDefaults:boolean = true) {
        super();
        this.setValues(values, setDefaults);
    }

    /**
     * set the values for both the Model and the Form Group. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any, fillDefaults = true): void {
        if (values && values['component'] != null) {
            this['component'] = values['component'];
        } else if (fillDefaults && EventsEventSource.hasDefaultValue('component')) {
            this['component'] = EventsEventSource.propInfo['component'].default;
        } else {
            this['component'] = null
        }
        if (values && values['node-name'] != null) {
            this['node-name'] = values['node-name'];
        } else if (fillDefaults && EventsEventSource.hasDefaultValue('node-name')) {
            this['node-name'] = EventsEventSource.propInfo['node-name'].default;
        } else {
            this['node-name'] = null
        }
        this.setFormGroupValuesToBeModelValues();
    }


    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'component': CustomFormControl(new FormControl(this['component']), EventsEventSource.propInfo['component']),
                'node-name': CustomFormControl(new FormControl(this['node-name']), EventsEventSource.propInfo['node-name']),
            });
        }
        return this._formGroup;
    }

    setModelToBeFormGroupValues() {
        this.setValues(this.$formGroup.value, false);
    }

    setFormGroupValuesToBeModelValues() {
        if (this._formGroup) {
            this._formGroup.controls['component'].setValue(this['component']);
            this._formGroup.controls['node-name'].setValue(this['node-name']);
        }
    }
}

