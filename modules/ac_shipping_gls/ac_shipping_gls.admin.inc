<?php
/**
 * @file
 * Admin settings pages for Commerce shipping GLS.
 */

/**
 * Creates module configuration form for setting shipping service rate amount.
 */
function ac_shipping_gls_settings() {
  $form = array();
  $form['rates'] = array(
    '#type' => 'fieldset',
    '#title' => t('GLS shipping rates'),
  );
  $form['rates']['ac_shipping_gls_shipping_rate_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping service rate amount'),
    '#description' => t('Amount is integer value. But will be interpreted as float value. so, if it is set to 3900, it will be used as 39.00.'),
    '#default_value' => variable_get('ac_shipping_gls_shipping_rate_amount', 3900),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['rates']['ac_shipping_gls_shipping_rate_amount_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Total price that enables free shipping service (>=)'),
    '#description' => t('Amount is integer value. But will be interpreted as float value. so, if it is set to 50000, it will be used as 500.00.'),
    '#default_value' => variable_get('ac_shipping_gls_shipping_rate_amount_limit', 50000),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  return system_settings_form($form);
}
