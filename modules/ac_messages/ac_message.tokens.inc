<?php
/**
 * Created by PhpStorm.
 * User: jesperbisgaard
 * Date: 15/02/16
 * Time: 14:27
 */

/**
 * Implements hook_token_info().
 */
function ac_messages_token_info_alter(&$data) {
  $data['tokens']['commerce-order']['order-overview'] = array(
    'name' => t('Order overview'),
    'description' => t('The current order overview'),
  );
  $data['tokens']['commerce-order']['order-shipping-contact-address'] = array(
    'name' => t('Shipping and contact address'),
    'description' => t('Show table of shipping and contact address.'),
  );
  return $data;
}
/**
 * Implements hook_tokens().
 */
function ac_messages_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  foreach ($tokens as $name => $original) {
    if ($name == 'order-overview' && isset($data['commerce-order'])) {
      $order = $data['commerce-order'];
      $view = commerce_embed_view('commerce_cart_summary', 'mail', array($order->order_id));
      if (is_array($view)) {
        $view = "<div class='commerce-mail-confirmation-table'>" . render($view) . "</div>";
      }
      else {
        $view = "<div class='commerce-mail-confirmation-table'>" . $view . "</div>";
      }
      $replacements[$original] = $view;
    }
    if ($name == 'order-shipping-contact-address' && isset($data['commerce-order'])) {
      $shipping_address = _ac_messages_get_address($data['commerce-order']);
      $billing_address = _ac_messages_get_address($data['commerce-order'], 'commerce_customer_billing');
      $replacements[$original] = theme(
        'ac_contact_information',
        array(
          'shipping_address' => $shipping_address,
          'billing_address' => $billing_address
        )
      );
    }
  }
  return $replacements;
}