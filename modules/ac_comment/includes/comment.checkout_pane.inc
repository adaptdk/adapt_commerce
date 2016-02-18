<?php

/**
 * @file comment.checkout_pane.inc
 */

/**
 * Implements hook_settings_form()
 */
function ac_comment_settings_form($checkout_pane) {
  $form['ac_comment_panel_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Panel title'),
    '#description' => t('Text that will appear on the top as a block/panel title.'),
    '#default_value' => variable_get('ac_comment_panel_title', 'Leave a comment'),
  );

  // We already have a submit btn
  $drupal_form = system_settings_form($form);
  unset($drupal_form['#submit']);
  unset($drupal_form['actions']);

  return $drupal_form;
}

/**
 * Implements hook_checkout_form()
 */
function ac_comment_checkout_form($form, $form_state, $checkout_pane, $order) {
  $checkout_form = array();
  $checkout_form['ac_comment'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#default_value' => (isset($order->field_comment[LANGUAGE_NONE][0]['value']))?$order->field_comment[LANGUAGE_NONE][0]['value']:'',
  );

  return $checkout_form;
}

function ac_comment_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  $form_state['order']->field_comment[LANGUAGE_NONE][0]['value'] = $form_state['values']['adapt_commerce_comment']['ac_comment'];
}

/**
 * Checkout pane callback: returns comment for a review pane/table.
 *   Review checkout pane.
 */
function ac_comment_review($form, $form_state, $checkout_pane, $order) {
  return $order->field_comment[LANGUAGE_NONE][0]['value'];
}
