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
    foreach ($build as $value => &$item) {
      if ($item['#active']) {

        // Set path to search page so active items enable by path can be removed (this is not optimal and should be
        // fixed in a better way)
        $item['#path'] = 's';
      }
    }

    $items = parent::buildListItems($build);
    return $items;
  }
}
