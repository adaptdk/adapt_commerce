<?php
/**
 * @file
 * ac_shipping_gls.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function ac_shipping_gls_defaultconfig_features() {
  return array(
    'ac_shipping_gls' => array(
      'field_default_fields' => 'field_default_fields',
    ),
  );
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function ac_shipping_gls_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'commerce_order-commerce_order-field_gls_parcelshop'.
  $fields['commerce_order-commerce_order-field_gls_parcelshop'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_gls_parcelshop',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_order',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Customer selected ParcelShop in the checkout form.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_order',
      'field_name' => 'field_gls_parcelshop',
      'label' => 'GLS ParcelShop',
      'required' => 0,
      'settings' => array(
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 0,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Customer selected ParcelShop in the checkout form.');
  t('GLS ParcelShop');

  return $fields;
}
