<?php
/**
 * @file
 * ac_commerce.features.inc
 */

/**
 * Implements hook_commerce_tax_default_rates().
 */
function ac_commerce_commerce_tax_default_rates() {
  $items = array(
    'dk_moms' => array(
      'name' => 'dk_moms',
      'display_title' => 'moms',
      'description' => '',
      'rate' => 0.25,
      'type' => 'vat',
      'rules_component' => 'commerce_tax_rate_dk_moms',
      'default_rules_component' => 1,
      'price_component' => 'tax|dk_moms',
      'calculation_callback' => 'commerce_tax_rate_calculate',
      'module' => 'commerce_tax_ui',
      'title' => 'dk moms',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_types().
 */
function ac_commerce_commerce_tax_default_types() {
  $items = array(
    'vat' => array(
      'name' => 'vat',
      'display_title' => 'VAT',
      'description' => 'A basic type for taxes that display inclusive with product prices.',
      'display_inclusive' => 1,
      'round_mode' => 1,
      'rule' => 'commerce_tax_type_vat',
      'module' => 'commerce_tax_ui',
      'title' => 'VAT',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ac_commerce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
