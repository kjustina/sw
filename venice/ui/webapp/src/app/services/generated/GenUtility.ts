import { HttpClient, HttpResponse, HttpErrorResponse } from '@angular/common/http';
import { Utility } from '@app/common/Utility';
import * as oboe from 'oboe';
import { publishReplay, refCount, delay } from 'rxjs/operators';
import { Observable ,  Subject, Subscriber, TeardownLogic, NEVER } from 'rxjs';
import { VeniceResponse } from '@app/models/frontend/shared/veniceresponse.interface';
import { MockDataUtil } from '@app/common/MockDataUtil';
import { AUTH_KEY } from '@app/core/auth/auth.reducer';
import { WebSocketSubject } from 'rxjs/observable/dom/WebSocketSubject';
import { MethodOpts } from '@sdk/v1/services/generated/abstract.service';
import { UIRolePermissions } from '@sdk/v1/models/generated/UI-permissions-enum';

export class GenServiceUtility {
  protected _http;
  protected urlServiceMap: { [method: string]: Observable<VeniceResponse> } = {};
  protected urlWsMap: { [method: string]: WebSocketSubject<any> } = {};
  protected ajaxStartCallback: (payload: any) => void;
  protected ajaxEndCallback: (payload: any) => void;
  protected useWebSockets: boolean;

  constructor(http: HttpClient, ajaxStartCallback, ajaxEndCallback, useWebSockets = true) {
    this._http = http;
    this.ajaxStartCallback = ajaxStartCallback;
    this.ajaxEndCallback = ajaxEndCallback;
    this.useWebSockets = useWebSockets;
    window.addEventListener('unload', (event) => {
      for (const key in this.urlWsMap) {
        if (this.urlWsMap.hasOwnProperty(key)) {
          const ws = this.urlWsMap[key];
          if (ws != null) {
            // Closing websocket
            try {
              ws.unsubscribe();
            } catch (e) {
              console.error(e);
            }
          }
        }
      }
    });
  }

  convertEventID(opts: MethodOpts): UIRolePermissions {
    let action;
    if (opts.eventID.startsWith('Watch')) {
      action = 'read';
      opts.objType = opts.objType.replace('AutoMsg', '');
      opts.objType = opts.objType.replace('WatchHelper', '');
    } else if (opts.eventID.startsWith('List')) {
      action = 'read';
      opts.objType = opts.objType.replace('List', '');
    } else if (opts.eventID.startsWith('Get')) {
      action = 'read';
    } else if (opts.eventID.startsWith('Update')) {
      action = 'update';
    } else if (opts.eventID.startsWith('Delete')) {
      if (opts.isStaging) {
        action = 'clear';
      } else {
        action = 'delete';
      }
    } else if (opts.eventID.startsWith('Add')) {
      if (opts.isStaging) {
        action = 'commit';
      } else {
        action = 'create';
      }
    } else {
      const catKind = Utility.actionMethodNameToObject(opts.eventID);
      action = 'create';
      opts.objType = catKind.category + catKind.kind;
    }
    const key = opts.objType.toLowerCase() + '_' + action;
    return UIRolePermissions[key];
  }


  /**
   * Function to create an observer that starts an oboe instance
   * and emits whenever oboe receives a full object. When an observer unsubscribes,
   * it will close the connection
   *
   * @param url URL for oboe to listen to
   * @param payload Query param object to send with the request
   * @param eventPayload payload to publish on connection end
   */
  protected oboeObserverCreate(url: string, payload: any, eventPayload: any): ((this: Observable<any>, subscriber: Subscriber<any>) => TeardownLogic) {
    return (observer) => {
      const headers = {};
      headers[AUTH_KEY] = Utility.getInstance().getXSRFtoken();

      const config = {
        'url': url,
        'method': 'GET',
        headers: headers
      };
      const oboeService = oboe(config);

      // The '!' will only consume complete json objects
      oboeService.node('!', (data) => {
        observer.next({ body: data, statusCode: null });
      });

      // If the connection fails for any reason
      oboeService.fail(result => {
        observer.error({ body: result.jsonBody, statusCode: result.statusCode });
      });

      // When the consumer unsubscribes, close the connection and publish ajax end
      return {
        unsubscribe: () => {
          oboeService.abort();
          this.ajaxEndCallback(eventPayload);
          delete this.urlServiceMap[url];
        }
      };
    };
  }

  /**
   * If no watch connection exists for the given method, we create a new one and
   * return the observable.
   * If one exists, we return the observable. Since we use a replay subject, and late
   * subscribers will receive all events that have happened in the connection.
   *
   * @param method HTTP method
   * @param url Url to issue a GET request against, used to uniquely idenitfy the observer objects
   * @param eventPayload EventPayload that will be published on AJAX End
   */
  protected handleWatchRequest(url: string, payload: any, eventPayload: any): Observable<VeniceResponse> {
    if (payload != null) {
      // we add the query params to the url
      url += '?' + Utility.getJQuery().param(payload);
    }
    if (this.useWebSockets) {
      if (this.urlWsMap[url] == null) {
        url = url.replace('http://', 'ws://');
        url = url.replace('https://', 'wss://');
        const observer = new WebSocketSubject({
          url: url,
        });

        this.urlWsMap[url] = observer;
      }
      return this.urlWsMap[url];
    }

    // Watch
    if (this.urlServiceMap[url] == null) {
      // Creating cold observer that emits events when oboe receives new data
      const oboeObserver: Observable<any> = new Observable(this.oboeObserverCreate(url, payload, eventPayload));
      // Creating a replay subject that subscribes and unsubscribes from the oboeObserver source
      // only if it has subscribers.
      // The connection will only be open if there is a listener, and closed as soon as there
      // are no more listeners
      const observer = oboeObserver.pipe(publishReplay(), refCount());
      this.urlServiceMap[url] = observer;
    }
    return this.urlServiceMap[url];
  }

  public isAllowed(eventPayloadID: any) {
    // checking maintenance mode (but get version object)
    const blockCondition = (Utility.getInstance().getMaintenanceMode() && eventPayloadID !== 'WatchVersion' && eventPayloadID !== 'WatchRollout' && eventPayloadID !== 'GetRollout' && eventPayloadID !== 'WatchDistributedServiceCard' && eventPayloadID !== 'StopRollout' ) ;

    if (blockCondition) {
      return false;
    }
    return true;
  }

  public invokeAJAX(method: string, url: string, payload: any,
    eventPayloadID: any, isOnline: boolean = false): Observable<VeniceResponse> {
    if (!this.isAllowed(eventPayloadID)) {
      return NEVER;
    }
    // Removing time fields as null values will be attempted to be parsed
    if (payload != null) {
      if (payload.meta != null) {
        delete payload.meta['creation-time'];
        delete payload.meta['mod-time'];
      }
      // Removing time fields from api list watch options
      if (payload['creation-time'] == null) {
        delete payload['creation-time'];
      }
      if (payload['mod-time'] == null) {
        delete payload['mod-time'];
      }
    }

    const eventPayload = { 'ajax': 'start', 'method': method, 'name': eventPayloadID + '-ajax', 'url': url };
    this.ajaxStartCallback(eventPayload);

    if (!isOnline) {
      return this.handleOfflineAJAX(url, method, eventPayload);
    }

    if (url.indexOf('watch') >= 0) {
      // We use oboe to load the chunked responses if it is a watch request
      return this.handleWatchRequest(url, payload, eventPayload);
    }

    let observer: Observable<HttpResponse<Object>>;
    switch (method) {
      case 'GET':
        if (payload == null) {
          observer = this._http.get(url, { observe: 'response' });
        } else {
          observer = this._http.get(url, { params: payload, observe: 'response' });
        }
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
        this.ajaxEndCallback(eventPayload);
        const statusCode = response.status;
        const body = response.body;
        retObserver.next({ body: body, statusCode: statusCode });
        retObserver.complete();
      },
      (error: HttpErrorResponse) => {
        this.ajaxEndCallback(eventPayload);
        retObserver.error({ body: error.error, statusCode: error.status });
      }
    );

    return retObserver;
  }

  /**
   * This is the key API of Data-mocking framework
   * @param url
   * @param method
   * @param eventpayload
   */
  protected handleOfflineAJAX(url: string, method: string, eventpayload: any): Observable<VeniceResponse> {
    const mockedData = MockDataUtil.getMockedData(url, method, eventpayload);
    const fakeObservable = new Observable<VeniceResponse>(obs => {
      obs.next({ body: mockedData, statusCode: 200 });
      obs.complete();
    }).pipe(delay(1000));
    return fakeObservable;
  }

}

