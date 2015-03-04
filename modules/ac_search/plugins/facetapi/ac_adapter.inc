<?php

/**
 * @file
 * Classes used by the Facet API module.
 */

/**
 * AC Facet API adapter for the Search API module.
 */
class acSearchApiFacetapiAdapter extends SearchApiFacetapiAdapter {

  protected $activeTerms = array();

  /**
   * Expose active terms
   * @return array
   */
  public function getActiveTerms() {
    return $this->activeTerms;
  }

  /**
   * Override processActiveItems to include active dynamic terms
   */
  public function processActiveItems() {
    // Load in standard active filters first
    parent::processActiveItems();
    $this->activeTerms = ac_search_active_terms();

    // Loop all dynamic terms and set them as active facets
    if (!empty($this->activeTerms)) {
      $enabled_aliases = array();
      foreach ($this->getEnabledFacets() as $facet) {
        $enabled_aliases[$facet['field alias']][] = $facet['name'];
      }

      // Implemented as in FacetapiAdapter::processActiveItems().
      foreach ($this->activeTerms as $term) {
        $field_alias = 'field_' . $term->vocabulary_machine_name;
        $filter = $field_alias . ':' . $term->tid;

        if (isset($enabled_aliases[$field_alias])) {

          $item = array(
            'field alias' => $field_alias,
            'value' => $term->tid,
            'pos' => sizeof($this->activeItems['filter']),
          );

          $this->activeItems['filter'][$filter] = $item;
          $this->activeItems['filter'][$filter]['facets'] = array();
          foreach ($enabled_aliases[$field_alias] as $facet_name) {
            $item += $this->queryTypes[$facet_name]->extract($item);
            $this->activeItems['filter'][$filter]['facets'][] = $facet_name;

            // Flag dynamic terms for later use
            $this->activeItems['filter'][$filter]['dtp'] = TRUE;
            $this->activeItems['facet'][$facet_name][$term->tid] = $item;
          }
        }
      }
    }
  }
}
