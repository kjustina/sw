import { ChangeDetectorRef, Component, ViewEncapsulation, OnInit, OnDestroy } from '@angular/core';
import { Animations } from '@app/animations';
import { HttpEventUtility } from '@app/common/HttpEventUtility';
import { Utility } from '@app/common/Utility';
import { TablevieweditAbstract } from '@app/components/shared/tableviewedit/tableviewedit.component';
import { Icon } from '@app/models/frontend/shared/icon.interface';
import { ControllerService } from '@app/services/controller.service';
import { MonitoringService } from '@app/services/generated/monitoring.service';
import { NetworkNetworkInterface, INetworkNetworkInterface, INetworkNetworkInterfaceList, IApiStatus } from '@sdk/v1/models/generated/network';
import { ClusterDistributedServiceCard, ClusterDistributedServiceCardStatus_admission_phase_uihint, IClusterDistributedServiceCard } from '@sdk/v1/models/generated/cluster';
import { Observable, forkJoin } from 'rxjs';
import { UIConfigsService } from '@app/services/uiconfigs.service';
import { UIRolePermissions } from '@sdk/v1/models/generated/UI-permissions-enum';
import { TableCol, RowClickEvent, CustomExportMap } from '@app/components/shared/tableviewedit';
import { TableUtility } from '@app/components/shared/tableviewedit/tableutility';
import { ClusterService } from '@app/services/generated/cluster.service';
import { NetworkService } from '@app/services/generated/network.service';
import { BrowserService } from '@app/services/generated/browser.service';
import { LabelEditorMetadataModel } from '@app/components/shared/labeleditor';
import { ObjectsRelationsUtility, DSCsNameMacMap } from '@app/common/ObjectsRelationsUtility';

/**
 * NetworkinterfacesComponent is linked to DSC object.
 * Each DSC has logical interfaces (Lif) and physical interfaces (up-links)
 *
 * Network interface objects are created by backend. User can manipulate labels (CRUD)
 *
 * Metrics should be on DSC.networkinterface.
 *
 * ERSPAN (Mirror Session) will use DSC.networkinterface labels
 *
 * TODO: 2020-02-27
 *  1. Scale test,  1000 DSCs will generate 16000 network interfaces.
 *  2. Add advance search
 *
 */

@Component({
  selector: 'app-networkinterfaces',
  templateUrl: './networkinterfaces.component.html',
  styleUrls: ['./networkinterfaces.component.scss'],
  animations: [Animations],
  encapsulation: ViewEncapsulation.None
})
export class NetworkinterfacesComponent extends TablevieweditAbstract<INetworkNetworkInterface, NetworkNetworkInterface> implements OnInit, OnDestroy {

  public static NETWORKINTERFACE_FIELD_DSC: string = 'associatedDSC';
  dataObjects: ReadonlyArray<NetworkNetworkInterface> ;
  naplesList: ClusterDistributedServiceCard[] = [];

  techsupportrequestsEventUtility: HttpEventUtility<NetworkNetworkInterface>;

  labelEditorMetaData: LabelEditorMetadataModel;

  bodyicon: any = {
    margin: {
      top: '9px',
      left: '8px',
    },
    url: '/assets/images/icons/monitoring/ic_tech_support-black.svg',   // TODO: wait for new svg file
  };
  headerIcon: Icon = {
    margin: {
      top: '0px',
      left: '10px',
    },
    matIcon: 'grid_on'
  };

  cols: TableCol[] = [
    { field: 'meta.name', header: 'Name', class: 'networkinterfaces-column-name', sortable: true, width: 15, notReorderable: true },
    { field: 'status.dsc', header: 'DSC', class: ' networkinterfaces-column-dsc', sortable: true, width: 15 },
    { field: 'meta.creation-time', header: 'Creation Time', class: 'networkinterfaces-column-date', sortable: true, width: '180px', notReorderable: true },
    { field: 'spec.admin-status', header: 'Admin Status', class: ' networkinterfaces-column-admintype', sortable: false, width: 45 },
    { field: 'spec.type', header: 'Type', class: ' networkinterfaces-column-type', sortable: true, width: 15 },
    { field: 'meta.labels', header: 'Labels', class: '', sortable: true, width: 7 },
     { field: 'status.oper-status', header: 'OP Status', class: ' networkinterfaces-column-opstatus', sortable: true, width: 15 }
  ];

  exportFilename: string = 'Venice-networkinterfaces';
  exportMap: CustomExportMap = {};

  isTabComponent = false;
  disableTableWhenRowExpanded = true;
  tableLoading: boolean = false;
  inLabelEditMode: boolean = false;
  constructor(protected controllerService: ControllerService,
    protected clusterService: ClusterService,
    protected uiConfigsService: UIConfigsService,
    protected networkService: NetworkService,
    protected cdr: ChangeDetectorRef,
    protected browserService: BrowserService
  ) {
    super(controllerService, cdr, uiConfigsService);
  }

  /**
  * Overide super's API
  * It will return this Component name
  */
 getClassName(): string {
  return this.constructor.name;
}

postNgInit() {
  this.watchNetworkInterfaces();
  this.watchNaples();
}

setDefaultToolbar() {
  const buttons = [];
  this.controllerService.setToolbarData({
    buttons: buttons,
    breadcrumb: [{ label: 'Network Interfaces', url: Utility.getBaseUIUrl() + '/cluster/networkinterfaces' }]
  });
}

watchNaples() {
  const dscSubscription = this.clusterService.ListDistributedServiceCardCache().subscribe(
    (response) => {
      if (response.connIsErrorState) {
        return;
      }
      this.naplesList  = response.data as ClusterDistributedServiceCard[];
      this.handleDataReady();
    }
  );
  this.subscriptions.push(dscSubscription);
}

watchNetworkInterfaces() {
  const dscSubscription = this.networkService.ListNetworkInterfacesCache().subscribe(
    (response) => {
      if (response.connIsErrorState) {
        return;
      }
      this.dataObjects  = response.data ;
      this.handleDataReady();
    }
  );
  this.subscriptions.push(dscSubscription);
}

handleDataReady() {
  // When naplesList and networkinterfaces list are ready, build networkinterface-dsc map.
  if (this.naplesList && this.dataObjects) {
    const _myDSCnameToMacMap: DSCsNameMacMap = ObjectsRelationsUtility.buildDSCsNameMacMap(this.naplesList);
    this.dataObjects.forEach( (networkNetworkInterface: NetworkNetworkInterface) => {
          const dscname = _myDSCnameToMacMap.macToNameMap[networkNetworkInterface.status.dsc];
          networkNetworkInterface._ui[NetworkinterfacesComponent.NETWORKINTERFACE_FIELD_DSC] = (dscname) ? dscname : networkNetworkInterface.status.dsc;
    });
  }
}

showDeleteIcon(): boolean {
  return true;
}

generateDeleteConfirmMsg(object: INetworkNetworkInterface) {
  return 'Are you sure to delete network interface: ' + object.meta.name;
}

generateDeleteSuccessMsg(object: INetworkNetworkInterface) {
  return 'Deleted network interface ' + object.meta.name;
}

deleteRecord(object: NetworkNetworkInterface): Observable<{ body: INetworkNetworkInterface | IApiStatus | Error; statusCode: number; }> {
  throw new Error('Method not supported.');
}

editLabels() {
  this.labelEditorMetaData = {
    title: 'Editing network interface objects',
    keysEditable: true,
    valuesEditable: true,
    propsDeletable: true,
    extendable: true,
    save: true,
    cancel: true,
  };

  if (!this.inLabelEditMode) {
    this.inLabelEditMode = true;
  }
}

handleEditSave(networkinterfaces: NetworkNetworkInterface[]) {
  this.updateWithForkjoin(networkinterfaces);
}

handleEditCancel($event) {
  this.inLabelEditMode = false;
}

updateWithForkjoin(networkinterfaces: NetworkNetworkInterface[]) {
  const observables: Observable<any>[] = [];
  for (const networkinterfaceObj of networkinterfaces) {
    const name = networkinterfaceObj.meta.name;
    const sub = this.networkService.UpdateNetworkInterface(name, networkinterfaceObj);
    observables.push(sub);
  }

  const summary = 'Network Interface update';
  const objectType = 'Network Interface';
  this.handleForkJoin(observables, summary, objectType);
}

private handleForkJoin(observables: Observable<any>[], summary: string, objectType: string) {
  forkJoin(observables).subscribe((results: any[]) => {
    let successCount: number = 0;
    let failCount: number = 0;
    const errors: string[] = [];
    for (let i = 0; i < results.length; i++) {
      if (results[i]['statusCode'] === 200) {
        successCount += 1;
      } else {
        failCount += 1;
        errors.push(results[i].body.message);
      }
    }
    if (successCount > 0) {
      const msg = 'Successfully updated ' + successCount.toString() + ' ' + objectType + '.';
      this._controllerService.invokeSuccessToaster(summary, msg);
      this.inLabelEditMode = false;
    }
    if (failCount > 0) {
      this._controllerService.invokeRESTErrorToaster(summary, errors.join('\n'));
    }
  },
    this._controllerService.restErrorHandler(summary + ' Failed'));
}



}