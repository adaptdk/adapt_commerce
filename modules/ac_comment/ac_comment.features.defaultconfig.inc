<?php
/**
 * @file
 * ac_comment.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function ac_comment_defaultconfig_features() {
  return array(
    'ac_comment' => array(
      'field_default_fields' => 'field_default_fields',
    ),
  );
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function ac_comment_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'commerce_order-commerce_order-field_comment'.
  $fields['commerce_order-commerce_order-field_comment'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_comment',
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
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_order',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => -3,
        ),
      ),
      'entity_type' => 'commerce_order',
      'field_name' => 'field_comment',
      'label' => 'Comment',
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
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => -3,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comment');

  return $fields;
}
