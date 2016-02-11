<?php

/**
 * @file mailchimp_extension.checkout_pane.inc
 */

/**
 * Implements hook_settings_form()
 */
function ac_mailchimp_extension_settings_form($checkout_pane) {
  $form['ac_mailchimp_extension_panel_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Panel title'),
    '#description' => t('Text promoting to subscribe. Enter the text you want to have as a title of newsletter subscription block.'),
    '#default_value' => variable_get('ac_mailchimp_extension_panel_title', 'Subscribe to be updated?'),
  );

  $lists = mailchimp_get_lists();
  if (!empty($lists)) {
    $checkboxes = array();
    foreach ($lists as $key => $value) {
      $checkboxes[$key] = $value['name'];
    }
    $form['ac_mailchimp_extension_list'] = array(
      '#type' => 'checkboxes',
      '#options' => $checkboxes,
      '#default_value' => variable_get('ac_mailchimp_extension_list', array()),
    );
  }

  // We already have a submit btn
  $drupal_form = system_settings_form($form);
  unset($drupal_form['#submit']);
  unset($drupal_form['actions']);

  return $drupal_form;
}

/**
 * Implements hook_checkout_form()
 */
function ac_mailchimp_extension_checkout_form($form, $form_state, $checkout_pane, $order) {
  $link_text = variable_get('ac_tac_text', t('Read the terms and conditions here'));
  $checkout_form = array();
  $link = l(t($link_text), 'node/' . variable_get('ac_tac_node', ''));
  $text = t('I accept the terms and conditions. !link', array('!link' => $link));
  $promoted_subscription_lists = variable_get('ac_mailchimp_extension_list');

  $lists = mailchimp_get_lists();
  if (!empty($lists) && !empty($promoted_subscription_lists)) {
    foreach ($lists as $key => $value) {
      if (in_array($key, $promoted_subscription_lists)) {
        $checkout_form['ac_mailchimp_extension_list'][$key] = array(
          '#type' => 'checkbox',
          '#title' => $value['name'],
        );
      }
    }
  }

  //@todo - add submit hook from here.
  //$checkout_form['buttons']['continue']['#submit'][] = 'ac_mailchimp_extension_subscribtion_submit';
  //$checkout_form['#submit'][] = 'ac_mailchimp_extension_subscribtion_submit';

  return $checkout_form;
}
