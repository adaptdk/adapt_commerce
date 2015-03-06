<?php
/**
 * @file
 * ac_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function ac_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'ac_standard';
  $item->label = 'AC standard';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Search found [facetapi_results:result-count] item',
        'plural' => 1,
        'text_plural' => 'Search found [facetapi_results:result-count] items',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h3',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
      'ac_items' => array(
        'field_pattern' => '[facetapi_facet:facet-label]:',
        'nofollow' => 1,
        'id' => 'ac_active',
        'label' => 'ac_items',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '3',
    ),
  );
  $export['ac_standard'] = $item;

  return $export;
}
