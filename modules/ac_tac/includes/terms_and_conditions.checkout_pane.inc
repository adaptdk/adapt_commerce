<?php
/**
 * @file
 *   Terms and conditions pane
 */

/**
 * Implements hook_settings_form()
 */
function ac_tac_settings_form($checkout_pane) {
  $title = '';

  if (variable_get('ac_tac_node', '')) {
    $nid = variable_get('ac_tac_node', '');
    $query = db_query('SELECT title FROM node WHERE nid = :nid', array(':nid' => $nid));
    $title = $query->fetchField();
    $title .= ' [id: ' . $nid . ']';
  }

  $form['ac_tac_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Select node to link to.'),
    '#description' => t('Input the title of the node that contain your terms and conditions'),
    '#maxlength' => 60,
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#element_validate' => array('ac_tac_settings_form_validate'),
    '#default_value' => $title,
    '#required' => TRUE,
  );

  $form['ac_tac_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Terms and conditions link tekst'),
    '#description' => t('Enter the text you want the terms and conditions link to have.'),
    '#default_value' => variable_get('ac_tac_text', ''),
  );

  // We already have a submit btn
  $drupal_form = system_settings_form($form);
  unset($drupal_form['#submit']);
  unset($drupal_form['actions']);

  return $drupal_form;
}

/**
 * Validate function for extra panes settings form.
 */
function ac_tac_settings_form_validate($element, &$form_state, $form) {
  $preg_matches = array();
  $match = preg_match('/\[id: (\d+)\]/', $form_state['values']['ac_tac_node'], $preg_matches);
  if (!$match) {
    form_set_error('node-pane', t('You must select a node for adding a pane.'));
  }
  else {
    $form_state['values']['ac_tac_node'] = $preg_matches[1];
  }
}

/**
 * Implements hook_checkout_form()
 */
function ac_tac_checkout_form($form, $form_state, $checkout_pane, $order) {
  $link_text = variable_get('ac_tac_text', t('Read the terms and conditions here'));

  $link = l(t($link_text), 'node/' . variable_get('ac_tac_node', ''), array('attributes' => array('target'=>'_blank')));
  $text = t('I accept the terms and conditions. !link', array('!link' => $link));

  $checkout_form['ac_terms_and_conditions'] = array(
    '#type' => 'checkbox',
    '#title' => $text,
    '#required' => TRUE,
  );

  return $checkout_form;
}
