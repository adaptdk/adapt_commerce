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
function ac_comment_token_info_alter(&$data) {
  $data['tokens']['commerce-order']['order-comment-view'] = array(
    'name' => t('Order comment'),
    'description' => t('Show the order comment if any.'),
  );
  return $data;
}
/**
 * Implements hook_tokens().
 */
function ac_comment_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  foreach ($tokens as $name => $original) {
    if ($name == 'order-comment-view') {
      if (isset($data['entity_type']) && $data['entity_type'] == 'commerce_order') {
        if (isset($data['commerce-order'])) {
          $order = $data['commerce-order'];
        }
        else {
          $order = $data['entity'];
        }
        $wrapper = entity_metadata_wrapper('commerce_order', $order);
        // Lets get shipping service.
        $comment = $wrapper->field_comment->value();
        if (isset($comment)) {
          $header = array(
            t('Comment'),
          );
          $rows = array(0 => array($comment));
          $attributes = array(
            'class' => array('contact-info'),
          );
          $table = theme(
            'table',
            array(
              'header' => $header,
              'rows' => $rows,
              'attributes' => $attributes,
            )
          );
          $replacements[$original] = $table;
        }
        else {
          $replacements[$original] = "";
        }
      }
    }
  }
  return $replacements;
}