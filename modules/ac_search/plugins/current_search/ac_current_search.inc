<?php

/**
 * Class acCurrentSearchGroup
 */
class acCurrentSearchGroup extends CurrentSearchGroup {
  /**
   * Implements CurrentSearchItem::getFacetPath().
   * Override getFacetPath to handle dynamic term paths
   */
  public function getFacetPath(array $item, FacetapiAdapter $adapter) {
    if (in_array($item['field alias'], array('field_category', 'field_brand'))) {
      // Set path to search page so active items enable by path can be removed (this is not optimal and should be
      // fixed in a better way
      $path = 's';
    }
    else {
      $path = $adapter
        ->getProcessor($item['facets'][0])
        ->getFacetPath($this->getItemValues($item, $adapter), 1);
    }

    return $path;
  }
}
