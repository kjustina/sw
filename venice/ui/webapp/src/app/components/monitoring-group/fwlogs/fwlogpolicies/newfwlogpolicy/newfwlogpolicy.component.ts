import { AfterViewInit, Component, EventEmitter, Input, OnInit, Output, ViewEncapsulation, ViewChild } from '@angular/core';
import { Animations } from '@app/animations';
import { ToolbarButton } from '@app/models/frontend/shared/toolbar.interface';
import { ControllerService } from '@app/services/controller.service';
import { MonitoringService } from '@app/services/generated/monitoring.service';
import { IMonitoringFwlogPolicy, MonitoringFwlogPolicy, MonitoringFwlogPolicySpec, IMonitoringPSMExportTarget, MonitoringPSMExportTarget } from '@sdk/v1/models/generated/monitoring';
import { SelectItem, MultiSelect } from 'primeng/primeng';
import { SyslogComponent } from '@app/components/shared/syslog/syslog.component';
import { Utility } from '@app/common/Utility';
import { CreationForm } from '@app/components/shared/tableviewedit/tableviewedit.component';
import { UIConfigsService } from '@app/services/uiconfigs.service';
import { AbstractControl } from '@angular/forms';

@Component({
  selector: 'app-newfwlogpolicy',
  templateUrl: './newfwlogpolicy.component.html',
  styleUrls: ['./newfwlogpolicy.component.scss'],
  animations: [Animations],
  encapsulation: ViewEncapsulation.None,
})
export class NewfwlogpolicyComponent extends CreationForm<IMonitoringFwlogPolicy, MonitoringFwlogPolicy> implements OnInit, AfterViewInit {
  public static LOGOPTIONS_ALL = 'FIREWALL_ACTION_ALL';
  public static LOGOPTIONS_NONE = 'FIREWALL_ACTION_NONE';
  public static PSM_TARGET = 'psm-target';

  createButtonTooltip: string ;
  @ViewChild('syslogComponent') syslogComponent: SyslogComponent;
  @ViewChild('logOptions') logOptionsMultiSelect: MultiSelect;

  @Input() maxTargets: number;

  filterOptions: SelectItem[] = Utility.convertEnumToSelectItem(MonitoringFwlogPolicySpec.propInfo['filter'].enum, [NewfwlogpolicyComponent.LOGOPTIONS_NONE]);

  constructor(protected _controllerService: ControllerService,
    protected uiconfigsService: UIConfigsService,
    protected _monitoringService: MonitoringService,
  ) {
    super(_controllerService, uiconfigsService, MonitoringFwlogPolicy);
  }

  getClassName(): string {
    return this.constructor.name;
  }

  postNgInit() {
      // Existing fwl-policies may not have spec['psm-target'],  so we  build it
      if (!this.newObject.spec[NewfwlogpolicyComponent.PSM_TARGET]) {
        this.newObject.spec[NewfwlogpolicyComponent.PSM_TARGET] =  new MonitoringPSMExportTarget(this.newObject.spec[NewfwlogpolicyComponent.PSM_TARGET]);
        this.newObject.setFormGroupValuesToBeModelValues();
      }
  }

  // Empty Hook
  isFormValid(): boolean {
    this.createButtonTooltip = null;
     if (!this.syslogComponent.isSyLogFormValid()['valid']) {
       this.createButtonTooltip = this.syslogComponent.isSyLogFormValid()['errorMessage'];
       return false;
     }
     this.createButtonTooltip = 'Ready to save Firewall log Policy.';
     return true;
  }

  setToolbar() {
    const currToolbar = this.controllerService.getToolbarData();
    currToolbar.buttons = [
      {
        cssClass: 'global-button-primary fwlogpolicies-button fwlogpolicies-button-SAVE',
        text: 'CREATE FIREWALL LOG POLICY',
        callback: () => { this.saveObject(); },
        genTooltip: () => this.getTooltip(),
        computeClass: () => this.computeButtonClass()
      },
      {
        cssClass: 'global-button-neutral fwlogpolicies-button fwlogpolicies-button-CANCEL',
        text: 'CANCEL',
        callback: () => { this.cancelObject(); }
      },
    ];

    this._controllerService.setToolbarData(currToolbar);
  }

  getObjectValues(): IMonitoringFwlogPolicy {
    const obj = this.newObject.getFormGroupValues();
    const syslogValues = this.syslogComponent.getValues();
    Object.keys(syslogValues).forEach((key) => {
      obj.spec[key] = syslogValues[key];
    });
    return obj;
  }

  createObject(object: IMonitoringFwlogPolicy) {
    return this._monitoringService.AddFwlogPolicy(object);
  }

  updateObject(newObject: IMonitoringFwlogPolicy, oldObject: IMonitoringFwlogPolicy) {
    return this._monitoringService.UpdateFwlogPolicy(oldObject.meta.name, newObject, null, oldObject);
  }

  generateCreateSuccessMsg(object: IMonitoringFwlogPolicy) {
    return 'Created policy ' + object.meta.name;
  }

  generateUpdateSuccessMsg(object: IMonitoringFwlogPolicy) {
    return 'Updated policy ' + object.meta.name;
  }

  /**
   * event.itemValue is the changed item. event.value has the selections
   * @param event
   */
  /* VS-124.
     When there is any NONE-ALL options selected, OPTION_ALL will be removed
     When none is seleced, we set OPTION_ALL as default.
  */
  onLogOptionChange(event) {
    const values = this.logOptionsMultiSelect.value;
    if (values.length >= 1 && values.includes(NewfwlogpolicyComponent.LOGOPTIONS_ALL)) {
      // When all is set, we untoggle everything else.
      if (event.itemValue === NewfwlogpolicyComponent.LOGOPTIONS_ALL) {
        this.logOptionsMultiSelect.value = [NewfwlogpolicyComponent.LOGOPTIONS_ALL];
      } else {
        const index = values.indexOf(NewfwlogpolicyComponent.LOGOPTIONS_ALL);
        values.splice(index, 1);
        this.logOptionsMultiSelect.value = values;
      }
    }
  }

  getTooltip() {
    if (Utility.isEmpty(this.newObject.$formGroup.get(['meta', 'name']).value)) {
      return 'Error: Name field is empty.';
    }
    if (!this.newObject.$formGroup.get(['meta', 'name']).valid)  {
      return 'Error: Name field is invalid.';
    }
    return this.createButtonTooltip;
  }
}
