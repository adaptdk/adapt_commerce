<?php

/**
 * Callback for 'admin/commerce/config/checkout/multiplier'
 */
function ac_cpm_multipier_settings_form($form, &$form_state) {
  $form = array();
  $duplicates = _ac_cpm_variable_select(AC_CPM_CHECKOUT_PREFIX, array());
  $availabel_checkout_panes = commerce_checkout_panes();
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'ac_cpm') . '/css/ac_cpm.css',
  );
  $form['#attributes'] = array('class' => array('ac-cpm-settings-form'));
  $form['description'] = array(
    '#markup' => 'Change the number next to an existing checkout pane to have it duplicate in checkout workflow',
  );
  foreach ($availabel_checkout_panes as $key => $pane) {
    if (strpos($key, AC_CPM_CHECKOUT_PREFIX) === false) {
      $form[AC_CPM_CHECKOUT_PREFIX . $key] = array(
        '#type' => 'textfield',
        '#title' => $pane['title'],
        '#size' => 3,
        '#default_value' => variable_get(AC_CPM_CHECKOUT_PREFIX . $key, 1),
        '#attributes' => array('class' => array('container-inline')),
      );
    }
  }

  return system_settings_form($form);
}
