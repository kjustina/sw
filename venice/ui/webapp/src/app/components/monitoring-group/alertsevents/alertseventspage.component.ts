import { Component, OnInit, ViewEncapsulation } from '@angular/core';
import { BaseComponent } from '@app/components/base/base.component';
import { ControllerService } from '@app/services/controller.service';
import { UIConfigsService } from '@app/services/uiconfigs.service';
import { MessageService } from 'primeng/primeng';

@Component({
  selector: 'app-alertsevents',
  templateUrl: './alertseventspage.component.html',
  styleUrls: ['./alertseventspage.component.scss'],
  encapsulation: ViewEncapsulation.None
})
export class AlertseventspageComponent extends BaseComponent implements OnInit {
  hideAlertpolicies: boolean = this.uiconfigsService.isObjectDisabled('AlertPolicies');

  constructor(protected _controllerService: ControllerService,
    protected uiconfigsService: UIConfigsService,
    protected messageService: MessageService) {
    super(_controllerService, messageService);
  }

  ngOnInit() {
    let buttons = [];
    if (!this.hideAlertpolicies) {
      buttons = [
        {
          cssClass: 'global-button-primary alertsevents-button',
          text: 'ALERT POLICIES',
          callback: () => { this._controllerService.navigate(['/monitoring', 'alertsevents', 'alertpolicies']); }
        }
      ];
    }

    this._controllerService.setToolbarData({
      buttons: buttons,
      breadcrumb: [{ label: 'Alerts & Events', url: '/#/monitoring/alertsevents' }]
    });
  }

  getClassName(): string {
    return this.constructor.name;
  }
}
