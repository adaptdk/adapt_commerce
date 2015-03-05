<?php
/**
 * @file
 * ac_commerce.features.inc
 */

/**
 * Implements hook_commerce_features_default_checkout_panes().
 */
function ac_commerce_commerce_features_default_checkout_panes() {
  $panes = array();

  $panes['account'] = array(
    'page' => 'checkout',
    'weight' => -5,
    'pane_id' => 'account',
    'fieldset' => TRUE,
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'enabled' => TRUE,
    'review' => TRUE,
  );

  $panes['cart_contents'] = array(
    'page' => 'checkout',
    'weight' => -10,
    'pane_id' => 'cart_contents',
    'fieldset' => TRUE,
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'enabled' => TRUE,
    'review' => TRUE,
  );

  $panes['checkout_completion_message'] = array(
    'page' => 'complete',
    'fieldset' => FALSE,
    'pane_id' => 'checkout_completion_message',
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'weight' => 0,
    'enabled' => TRUE,
    'review' => TRUE,
  );

  $panes['checkout_review'] = array(
    'page' => 'review',
    'fieldset' => FALSE,
    'pane_id' => 'checkout_review',
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'weight' => 0,
    'enabled' => TRUE,
    'review' => TRUE,
  );

  $panes['commerce_payment'] = array(
    'page' => 'review',
    'weight' => 10,
    'pane_id' => 'commerce_payment',
    'fieldset' => TRUE,
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'enabled' => TRUE,
    'review' => TRUE,
  );

  $panes['commerce_payment_redirect'] = array(
    'page' => 'payment',
    'pane_id' => 'commerce_payment_redirect',
    'fieldset' => TRUE,
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'weight' => 0,
    'enabled' => TRUE,
    'review' => TRUE,
  );

  $panes['commerce_shipping'] = array(
    'page' => 'shipping',
    'weight' => 2,
    'review' => FALSE,
    'pane_id' => 'commerce_shipping',
    'fieldset' => TRUE,
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'enabled' => TRUE,
  );

  $panes['customer_profile_billing'] = array(
    'page' => 'checkout',
    'weight' => 5,
    'pane_id' => 'customer_profile_billing',
    'fieldset' => TRUE,
    'collapsible' => FALSE,
    'collapsed' => FALSE,
    'enabled' => TRUE,
    'review' => TRUE,
  );

  $panes['customer_profile_shipping'] = array(
    'page' => 'checkout',
    'weight' => 0,
    'pane_id' => 'customer_profile_shipping',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 1,
    'review' => 1,
  );

  return $panes;
}

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
