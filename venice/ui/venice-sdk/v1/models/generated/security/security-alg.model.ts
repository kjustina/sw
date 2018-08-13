/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel, PropInfoItem } from './base-model';

import { SecurityDNS, ISecurityDNS } from './security-dns.model';
import { SecuritySIP, ISecuritySIP } from './security-sip.model';
import { SecuritySunRPC, ISecuritySunRPC } from './security-sun-rpc.model';
import { SecurityFTP, ISecurityFTP } from './security-ftp.model';
import { SecurityMSRPC, ISecurityMSRPC } from './security-msrpc.model';
import { SecurityTFTP, ISecurityTFTP } from './security-tftp.model';
import { SecurityRSTP, ISecurityRSTP } from './security-rstp.model';

export interface ISecurityALG {
    'dns'?: ISecurityDNS;
    'sip'?: ISecuritySIP;
    'sunrpc'?: ISecuritySunRPC;
    'ftp'?: ISecurityFTP;
    'msrpc'?: ISecurityMSRPC;
    'tftp'?: ISecurityTFTP;
    'rstp'?: ISecurityRSTP;
}


export class SecurityALG extends BaseModel implements ISecurityALG {
    'dns': SecurityDNS = null;
    'sip': SecuritySIP = null;
    'sunrpc': SecuritySunRPC = null;
    'ftp': SecurityFTP = null;
    'msrpc': SecurityMSRPC = null;
    'tftp': SecurityTFTP = null;
    'rstp': SecurityRSTP = null;
    public static propInfo: { [prop: string]: PropInfoItem } = {
        'dns': {
            type: 'object'
        },
        'sip': {
            type: 'object'
        },
        'sunrpc': {
            type: 'object'
        },
        'ftp': {
            type: 'object'
        },
        'msrpc': {
            type: 'object'
        },
        'tftp': {
            type: 'object'
        },
        'rstp': {
            type: 'object'
        },
    }

    public getPropInfo(propName: string): PropInfoItem {
        return SecurityALG.propInfo[propName];
    }

    /**
     * Returns whether or not there is an enum property with a default value
    */
    public static hasDefaultValue(prop) {
        return (SecurityALG.propInfo[prop] != null &&
                        SecurityALG.propInfo[prop].default != null &&
                        SecurityALG.propInfo[prop].default != '');
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['dns'] = new SecurityDNS();
        this['sip'] = new SecuritySIP();
        this['sunrpc'] = new SecuritySunRPC();
        this['ftp'] = new SecurityFTP();
        this['msrpc'] = new SecurityMSRPC();
        this['tftp'] = new SecurityTFTP();
        this['rstp'] = new SecurityRSTP();
        this.setValues(values);
    }

    /**
     * set the values. If a value isn't provided and we have a default, we use that.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this['dns'].setValues(values['dns']);
        }
        if (values) {
            this['sip'].setValues(values['sip']);
        }
        if (values) {
            this['sunrpc'].setValues(values['sunrpc']);
        }
        if (values) {
            this['ftp'].setValues(values['ftp']);
        }
        if (values) {
            this['msrpc'].setValues(values['msrpc']);
        }
        if (values) {
            this['tftp'].setValues(values['tftp']);
        }
        if (values) {
            this['rstp'].setValues(values['rstp']);
        }
    }




    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'dns': this['dns'].$formGroup,
                'sip': this['sip'].$formGroup,
                'sunrpc': this['sunrpc'].$formGroup,
                'ftp': this['ftp'].$formGroup,
                'msrpc': this['msrpc'].$formGroup,
                'tftp': this['tftp'].$formGroup,
                'rstp': this['rstp'].$formGroup,
            });
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this['dns'].setFormGroupValues();
            this['sip'].setFormGroupValues();
            this['sunrpc'].setFormGroupValues();
            this['ftp'].setFormGroupValues();
            this['msrpc'].setFormGroupValues();
            this['tftp'].setFormGroupValues();
            this['rstp'].setFormGroupValues();
        }
    }
}

