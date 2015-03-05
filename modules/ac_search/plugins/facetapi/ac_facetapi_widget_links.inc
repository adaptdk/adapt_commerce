<?php

/**
 * @file
 * The ac_facetapi_checkbox_links widget plugin classes.
 */

/**
 * Widget that renders facets as a list of clickable checkboxes.
 *
 * AC specific class to be able to override paths
 */
class acFacetapiWidgetCheckboxLinks extends FacetapiWidgetCheckboxLinks {

  protected $filterKey = 'f';

  /**
   * Override buildListItems
   * @param array $build
   * @return array|void
   */
  function buildListItems($build) {
    $settings = $this->settings->settings;

    foreach ($build as $value => &$item) {
      //$build[$value]['#path'] = '';
      if ($item['#active']) {
        // Strip any query filters
        //$this->strip_filters_for_facet($item['#query'], $this->facet['field alias']);

        // Set path to term url
        //$item['#path'] = 'taxonomy/term/' . $item['#indexed_value'];

        // Set path to search page so active items enable by path can be removed
        $item['#path'] = 's';
      }

    }

    $items = parent::buildListItems($build);
    return $items;
  }

  /**
   * Strip all filters for given facet
   * @param array $qstring
   * @param string $facet_alias
   */
  private function strip_filters_for_facet(&$qstring, $facet_alias) {
    if (isset($qstring[$this->filterKey])) {
      foreach ($qstring[$this->filterKey] as $k => $v) {
        if (stripos($v, $facet_alias) !== FALSE) {
          unset($qstring[$this->filterKey][$k]);
        }
      }
    }
  }
}
