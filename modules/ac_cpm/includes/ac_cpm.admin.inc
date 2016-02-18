<?php

/**
 * Callback for 'admin/commerce/config/checkout/multiplier'
 */
function ac_cpm_multipier_settings_form($form, &$form_state) {
  $ac_cpm_prefix = 'ac_cpm';
  $form = array();
  $duplicates = ac_cpm_variable_select($ac_cpm_prefix.'_duplicates',array());


  return system_settings_form($form);
}