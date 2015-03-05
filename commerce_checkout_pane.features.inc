<?php

/**
 * Implements hook_features_export().
 */
function commerce_checkout_pane_features_export($data, &$export, $module_name) {
  // Add required dependencies.
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['commerce_checkout'] = 'commerce_checkout';

  $panes = commerce_checkout_panes();
  foreach ($data as $pane_id) {
    $export['features']['commerce_checkout_pane'][$pane_id] = $pane_id;
    $module = $panes[$pane_id]['module'];
    $export['dependencies'][$module] = $module;
  }

  return array();
}

/**
 * Implements hook_features_export_options().
 */
function commerce_checkout_pane_features_export_options() {
  $options = array();

  foreach (commerce_checkout_panes() as $pane_id => $pane) {
    $options[$pane_id] = $pane['title'];
  }

  return $options;
}

/**
 * Implements hook_features_export_render().
 */
function commerce_checkout_pane_features_export_render($module_name, $data, $export = NULL) {
  $output = array();

  $panes = commerce_checkout_panes();

  $schema = drupal_get_schema('commerce_checkout_pane');
  $fields = array_fill_keys(array_keys($schema['fields']), NULL);

  $output[] = '  $panes = array();';

  foreach ($data as $pane_id) {
    if (isset($panes[$pane_id])) {
      $exportable_pane = array_intersect_key($panes[$pane_id], $fields);

      $output[] = '';
      $output[] = "  \$panes['{$pane_id}'] = " . features_var_export($exportable_pane, '  ') . ";";
    }
  }

  $output[] = '';
  $output[] = '  return $panes;';
  $output = implode("\n", $output);

  return array('commerce_features_default_checkout_panes' => $output);
}

/**
 * Implements hook_features_revert().
 */
function commerce_checkout_pane_features_revert($module_name) {
  if ($defaults = features_get_default('commerce_checkout_pane', $module_name)) {
    commerce_checkout_panes_reset();
    $existing = commerce_checkout_panes();
    foreach ($defaults as $pane_id => $pane) {
      $pane['saved'] = isset($existing[$pane_id]['saved']) ? $existing[$pane_id]['saved'] : FALSE;

      commerce_checkout_pane_save($pane);
    }
  }
}

/**
 * Implements hook_features_rebuild().
 */
function commerce_checkout_pane_features_rebuild($module_name) {
  return commerce_checkout_pane_features_revert($module_name);
}

/**
 * Implements hook_features_enable_feature().
 */
function commerce_checkout_pane_features_enable_feature($module) {
  commerce_checkout_pane_features_revert($module);
}

/**
 * Implements hook_features_disable_feature().
 */
function commerce_checkout_pane_features_disable_feature($module) {
  if (module_hook($module, 'commerce_features_default_checkout_panes')) {
    $default_panes = module_invoke($module, 'commerce_features_default_checkout_panes');
    foreach ($default_panes as $pane_id => $default_pane) {
      commerce_checkout_pane_reset($pane_id);
    }
  }
}
