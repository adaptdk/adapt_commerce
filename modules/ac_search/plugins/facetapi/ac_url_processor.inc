<?php

/**
 * @file
 * The ac url processor class.
 */
class acFacetapiUrlProcessor extends FacetapiUrlProcessorStandard {

  /**
   * Implements FacetapiUrlProcessor::getQueryString().
   */
  public function getQueryString(array $facet, array $values, $active) {
    $qstring = parent::getQueryString($facet, $values, $active);
dd('a');
    // Special rules for vocabularies in dynamic term pages
    if (in_array($facet['field'], array(
      'field_category',
      'field_manufacturer',
      'field_brand',
      'field_gender',
      'field_sport',
      'field_type'
    ))) {
      // Always reset facet
      $this->strip_filters_for_facet($qstring, $facet['field alias']);
    }

    // Set qstring to nothing if no filters are set to avoid a ? to be appended to the url needlessly
    if (empty($qstring[$this->filterKey])) {
      $qstring = '';
    }

    return $qstring;
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
