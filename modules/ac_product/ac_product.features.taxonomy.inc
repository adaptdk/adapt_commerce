<?php
/**
 * @file
 * ac_product.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ac_product_taxonomy_default_vocabularies() {
  return array(
    'brand' => array(
      'name' => 'Brand',
      'machine_name' => 'brand',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'category' => array(
      'name' => 'Category',
      'machine_name' => 'category',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'color' => array(
      'name' => 'Color',
      'machine_name' => 'color',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
