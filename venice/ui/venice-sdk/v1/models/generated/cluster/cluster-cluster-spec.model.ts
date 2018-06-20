/**
 * This file is generated by the SwaggerTSGenerator.
 * Do not edit.
*/
/* tslint:disable */
import { Validators, FormControl, FormGroup, FormArray, ValidatorFn } from '@angular/forms';
import { minValueValidator, maxValueValidator, enumValidator } from './validators';
import { BaseModel } from './base-model';


export interface IClusterClusterSpec {
    'quorum-nodes'?: Array<string>;
    'virtual-ip'?: string;
    'ntp-servers'?: Array<string>;
    'dns-subdomain'?: string;
    'auto-admit-nics'?: boolean;
}


export class ClusterClusterSpec extends BaseModel implements IClusterClusterSpec {
    /** QuorumNodes contains the list of hostnames for nodes configured to be quorum
nodes in the cluster. */
    'quorum-nodes': Array<string>;
    /** VirtualIP is the IP address for managing the cluster. It will be hosted by
the winner of election between quorum nodes. */
    'virtual-ip': string;
    /** NTPServers contains the list of NTP servers for the cluster. */
    'ntp-servers': Array<string>;
    /** DNSSubDomain is the DNS subdomain for the default tenant. */
    'dns-subdomain': string;
    /** AutoAdmitNICs when enabled auto-admits NICs that are validated
into Venice Cluster. When it is disabled, NICs validated by CMD are
set to Pending state and it requires Manual approval to be admitted
into the cluster. */
    'auto-admit-nics': boolean;
    public static enumProperties = {
    }

    /**
     * constructor
     * @param values Can be used to set a webapi response to this newly constructed model
    */
    constructor(values?: any) {
        super();
        this['quorum-nodes'] = new Array<string>();
        this['ntp-servers'] = new Array<string>();
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
            this.fillModelArray<string>(this, 'quorum-nodes', values['quorum-nodes']);
            this['virtual-ip'] = values['virtual-ip'];
            this.fillModelArray<string>(this, 'ntp-servers', values['ntp-servers']);
            this['dns-subdomain'] = values['dns-subdomain'];
            this['auto-admit-nics'] = values['auto-admit-nics'];
        }
    }

    protected getFormGroup(): FormGroup {
        if (!this._formGroup) {
            this._formGroup = new FormGroup({
                'quorum-nodes': new FormArray([]),
                'virtual-ip': new FormControl(this['virtual-ip']),
                'ntp-servers': new FormArray([]),
                'dns-subdomain': new FormControl(this['dns-subdomain']),
                'auto-admit-nics': new FormControl(this['auto-admit-nics']),
            });
            // generate FormArray control elements
            this.fillFormArray<string>('quorum-nodes', this['quorum-nodes']);
            // generate FormArray control elements
            this.fillFormArray<string>('ntp-servers', this['ntp-servers']);
        }
        return this._formGroup;
    }

    setFormGroupValues() {
        if (this._formGroup) {
            this.fillModelArray<string>(this, 'quorum-nodes', this['quorum-nodes']);
            this._formGroup.controls['virtual-ip'].setValue(this['virtual-ip']);
            this.fillModelArray<string>(this, 'ntp-servers', this['ntp-servers']);
            this._formGroup.controls['dns-subdomain'].setValue(this['dns-subdomain']);
            this._formGroup.controls['auto-admit-nics'].setValue(this['auto-admit-nics']);
        }
    }
}

