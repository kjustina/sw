/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';


export interface ISecurityCertificateSpec {
    'description'?: string;
    'usages'?: Array<string>;
    'body'?: string;
    'trust-chain'?: string;
}


export class SecurityCertificateSpec extends BaseModel implements ISecurityCertificateSpec {
    'description': string;
    /** Usage can be "client", "server" or "trust-root" in any combination.
A "server" certificate is used by a server to authenticate itself to the client
A "client" certificate is used by a client to authenticate itself to a server
A "trust-root" certificate is self-signed and is only used to validate
certificates presented by peers.
"client" and "server" certificates are always accompanied by a private key,
whereas "trust-root"-only certificates are not. */
    'usages': Array<string>;
    'body': string;
    /** Trust chain of the certificate in PEM encoding.
These certificates are treated opaquely. We do not process them in any way
other than decoding them for informational purposes. */
    'trust-chain': string;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['usages'] = new Array<string>();
        if (values) {
            this.setValues(values);
        }
    }

    /**
     * set the values.
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    setValues(values: any): void {
        if (values) {
            this['description'] = values['description'];
            this.fillModelArray<string>(this, 'usages', values['usages']);
            this['body'] = values['body'];
            this['trust-chain'] = values['trust-chain'];
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'description': new FormControl(this['description']),
                'usages': new FormArray([]),
                'body': new FormControl(this['body']),
                'trust-chain': new FormControl(this['trust-chain']),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('usages', this['usages']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this._formGroup.controls['description'].setValue(this['description']);
            this.fillModelArray<string>(this, 'usages', this['usages']);
            this._formGroup.controls['body'].setValue(this['body']);
            this._formGroup.controls['trust-chain'].setValue(this['trust-chain']);
        }
    }
}

