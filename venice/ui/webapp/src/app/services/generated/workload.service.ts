import { HttpClient, HttpErrorResponse, HttpResponse } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Eventtypes } from '@app/enum/eventtypes.enum';
import { VeniceResponse } from '@app/models/frontend/shared/veniceresponse.interface';
import { ControllerService } from '@app/services/controller.service';
import { WorkloadV1Service } from '@sdk/v1/services/generated/WorkloadV1.service';
import { Observable } from 'rxjs/Observable';
import { Subject } from 'rxjs/Subject';
import 'rxjs/add/observable/of';
import 'rxjs/add/operator/catch';
import 'rxjs/add/operator/delay';
import { environment } from '../../../environments/environment';
import { MockDataUtil } from '../../common/MockDataUtil';
import { Utility } from '../../common/Utility';
import { _throw } from 'rxjs/observable/throw';


@Injectable()
export class WorkloadService extends WorkloadV1Service {
  // Attributes used by generated services
  protected O_Tenant: string = this.getTenant();
  protected baseUrlAndPort = window.location.protocol + '//' + window.location.hostname + ':' + window.location.port;


  constructor(protected _http: HttpClient,
              protected _controllerService: ControllerService) {
      super(_http);
  }
  
  /**
   * Get the service class-name
   */
  getClassName(): string {
    return this.constructor.name;
  }

  protected publishAJAXStart(eventPayload: any) {
    this._controllerService.publish(Eventtypes.AJAX_START, eventPayload);
  }

  protected publishAJAXEnd(eventPayload: any) {
    this._controllerService.publish(Eventtypes.AJAX_END, eventPayload);
  }

  protected invokeAJAX(method: string, url: string, payload: any, eventPayloadID: any, forceReal: boolean = false): Observable<VeniceResponse> {
    // Removing time fields as null values will be attempted to be parsed
    if (payload != null && payload.meta != null) {
      delete payload.meta['creation-time'];
      delete payload.meta['mod-time'];
    }
    const eventPayload = { 'ajax': 'start', 'method': method, 'name': eventPayloadID + '-ajax', 'url': url }
    this.publishAJAXStart(eventPayload);

    if (this.isToMockData() && !forceReal) {
      return this.handleOfflineAJAX(url, method, eventPayload);
    }

    let observer: Observable<HttpResponse<Object>>;
    switch (method) {
      case 'GET':
        observer = this._http.get(url, { observe: 'response' });
        break;
      case 'POST':
        observer = this._http.post(url, payload, { observe: 'response' });
        break;
      case 'PUT':
        observer = this._http.put(url, payload, { observe: 'response' });
        break;
      case 'DELETE':
        observer = this._http.delete(url, { observe: 'response' });
        break;
      default:
        break;
    }

    const retObserver = new Subject<VeniceResponse>();

    observer.subscribe(
      (response: HttpResponse<any>) => {
        this.publishAJAXEnd(payload);
        const statusCode = response.status;
        const body = response.body;
        retObserver.next({ body: body, statusCode: statusCode })
        retObserver.complete();
      },
      (error: HttpErrorResponse) => {
        this.publishAJAXEnd(payload);
        if (error.error instanceof Error) {
          // A client-side or network error occurred
          _throw(error.error.message);
        }
        // Error code was returned by backend
        const statusCode = error.status;
        const body = error.error;
        retObserver.next({ body: body, statusCode: statusCode })
        retObserver.complete();
      }
    )

    return retObserver;
  }

  /**
   * Override-able api
   */
  public isToMockData(): boolean {
    const isUseRealData = this._controllerService.useRealData;
    return (!isUseRealData) ? isUseRealData : environment.isRESTAPIReady;
  }

  /**
   * This is the key API of Data-mocking framework
   * @param url
   * @param method
   * @param eventpayload
   */
  protected handleOfflineAJAX(url: string, method: string, eventpayload: any): Observable<VeniceResponse> {
    const mockedData = MockDataUtil.getMockedData(url, method, eventpayload);
    const fakeObservable = Observable.create(obs => {
      obs.next({ body: mockedData, statusCode: 200 });
      obs.complete();
    }).delay(1000);
    return fakeObservable;
  }

  /**
   * Get login user tenant information
   *
   */
  getTenant(): string {
    return Utility.getInstance().getTenant();
  }
}
