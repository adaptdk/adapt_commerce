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

  return $checkout_form;
}

/**
 * Custom submit handler for newsletter signup checkbox.
 * Checks if user is already subscribed and if not, adds his/her email to given email lists.
 */
function ac_mailchimp_extension_checkout_form_submit($form, &$form_state, $checkout_pane, $order){
  $subscriptions = $form_state['values']['adapt_commerce_mailchimp_extension']['ac_mailchimp_extension_list'];

  // If none is chosen, skip subscribtion.
  if (empty($subscriptions)) {
    return;
  }

  $selected = false;
  // if we have zero subscriptions selected, skip.
  foreach ($subscriptions as $value) {
    if ($value == 1) {
      $selected = true;
      break;
    }
  }

  if (!$selected) {
    return;
  }

  // Load order and wrap it as entity.
  $order = $form_state['order'];
  $ow = entity_metadata_wrapper('commerce_order', $order);
  // Create cache id for order.
  $subscribtion_cache_id = 'ac_mailchimp_extension_subscribtion_order' . $ow->order_number->value();
  // get cache data for order.
  $subscribtion_cache = cache_get($subscribtion_cache_id, 'cache');

  // If there is no cache data returned start subscribtion.
  if (!$subscribtion_cache) {
    // Set user email value for subscribtion and checks.
    $email = $ow->mail->value();
    $vars = array(
      'FNAME' => $ow->commerce_customer_billing->commerce_customer_address->name_line->value(),
      'EMAIL' => $email,
    );
    // Get all lists.
    $lists = mailchimp_get_lists();
    // If there are no lists defined, stop subscribtion.
    if (empty($lists)) {
      return;
    }
    // Proceed subscriptions.
    foreach ($subscriptions as $key => $value) {
      if ($value == 1 && !mailchimp_is_subscribed($key, $email)) {
        // If email is not in subscribtion list - subscribe.
        mailchimp_subscribe($list['id'], $email, $mergevars);
      }
    }

    // Set cache value after subscribtion is done, if payment server is not responding and
    // checkout form tries to reconnect multiple times to prevent multiple
    // subscribtion requests with same data to MailChimp.
    cache_set($subscribtion_cache_id, TRUE, 'cache', time() + 60 * 60);
  }
}