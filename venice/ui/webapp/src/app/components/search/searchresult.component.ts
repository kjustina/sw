import { Component, OnDestroy, OnInit, ViewEncapsulation } from '@angular/core';
import { BaseComponent } from '@app/components/base/base.component';
import { ControllerService } from '@app/services/controller.service';
import { Utility } from '@app/common/Utility';
import { SearchUtil } from '@app/common/SearchUtil';
import { Eventtypes } from '@app/enum/eventtypes.enum';


import { SearchSearchResponse, SearchSearchRequest, ApiStatus, SearchSearchQuery_categories, SearchSearchQuery_kinds } from '@sdk/v1/models/generated/search';

/**
 * SearchResult is a component hosted in VenicUI app main page.
 * When component is initialized, it expects this._controllerService.LoginUserInfo[Utility.LAST_SEARCH_DATA] has search result.
 *
 * When user invokes get search result while playing search-widget, an 'Eventtypes.SEARCH_RESULT_LOAD_REQUEST' will be fired.
 * Search-result component listens to this event and re-render search result UI.
 *
 * In case, SearchResult already in present, if user invokes search again, this search-result component will act on new search-result data.
 */

@Component({
  selector: 'app-searchresult',
  templateUrl: './searchresult.component.html',
  styleUrls: ['./searchresult.component.scss'],
  encapsulation: ViewEncapsulation.None
})
export class SearchresultComponent extends BaseComponent implements OnInit, OnDestroy {
  searchResult: any;
  categories: any[];

  searchSearchResponse: SearchSearchResponse;
  selectedCategory: any;
  selectedKind: any;


  private _started = false;

  constructor(protected _controllerService: ControllerService) {
    super(_controllerService);
  }

  getClassName(): string {
    return this.constructor.name;
  }

  /**
   * Component life cycle API.
   * It subscribe to event.
   */
  ngOnInit() {
    if (!this._started) {
      this.getSearchResult();
      this._started = true;
    }
    this.subscriptions[Eventtypes.SEARCH_RESULT_LOAD_REQUEST] = this._controllerService.subscribe(Eventtypes.SEARCH_RESULT_LOAD_REQUEST, (payload) => {
      this.getSearchResult();
    });
  }

  /**
   * This API assumes the last search-result is stored in this._controllerService.LoginUserInfo[SearchUtil.LAST_SEARCH_DATA]
   * It process the search-result and let UI render data.
   * Structure-wise
   *   tenant -> category -> kind -> entries[]
   */
  getSearchResult() {
    this.categories = [];

    if (this._controllerService.LoginUserInfo) {
      const data = this._controllerService.LoginUserInfo[SearchUtil.LAST_SEARCH_DATA];
      const result = data['result'];
      const searchSearchResponse = new SearchSearchResponse(result);
      this.searchSearchResponse = searchSearchResponse;
      const tenants = searchSearchResponse['aggregated-entries'].tenants;
      if (!tenants) {
        // it means search service returns no record.
        return ;
      }
      const tenantKeys = Object.keys(tenants);
      for (let i = 0; i < tenantKeys.length; i++) {
        const cat = tenants[tenantKeys[i]].categories;
        const catKeys = Object.keys(cat);
        for (let j = 0; j < catKeys.length; j++) {
          const catUIObj = {
            name: catKeys[j],
            value: cat[catKeys[j]]
          };
          this.categories.push(catUIObj);
        }
      }
      this.selectedCategory = this.categories[0];
    }
  }

  ngOnDestroy(): void {

  }

  getCategoryTitle(category) {
    return category.name;
  }

  /**
   * This API serves html template.
   * @param category
   */
  getKinds(category): any {
    const kinds = [];
    const cat = category.value.kinds;
    const kindKeys = Object.keys(cat);
    for (let j = 0; j < kindKeys.length; j++) {
      const kind = cat[kindKeys[j]];
      const kindUIObj = {
        name: kindKeys[j],
        value: kind
      };
      kinds.push(kindUIObj);
    }
    if (!this.selectedKind) {
      this.selectedKind = kinds[0];
    }
    return kinds;
  }

  /**
   *
   * @param category
   */
  getCategoryCount(category) {
    const kinds = this.getKinds(category);
    let counts = 0;
    kinds.forEach(kind => {
      counts += kind.value.entries.length;
    });
    return counts;
  }

   /**
   * This API serves html.
   */
  getEntries(selectedKind): any {
    const entries = selectedKind.value.entries;
    return entries;
  }

  /**
   * This API serves html.
   * UI should fire an event and display object detail UI
   * @param $event
   * @param category
   * @param entry
   */
  onSearchResultEntryClick($event, category, entry) {
    // console.log(this.getClassName() + '.onSearchResultEntryClick(..)', $event, category, entry.kind, entry);
    // TODO: check entry.meta['self-link'] and fire up an event to display entry object detail.
    return false;
  }

  /**
   * This API serves html.
   * When user switches tab, we want to load category tab content. (load the right "kind")
   */
  onTabChange($event) {
    const selectedTabIndex = $event;
    this.selectedCategory = this.categories[selectedTabIndex];
    const kinds = this.getKinds(this.selectedCategory);
    if (kinds && kinds[0]) {
      this.selectedKind = kinds[0];
    }
  }


  /**
   * This API serves html template.
   * Display object.meta.label.
   * @param entry
   */
  displayLabels(entry): string {
    const list = [];
    const keys = Object.keys(entry.meta.labels);
    keys.forEach(key => {
      list.push( key + ' = ' + entry.meta.labels[key]);
    });
    return list.toString();
  }

}
