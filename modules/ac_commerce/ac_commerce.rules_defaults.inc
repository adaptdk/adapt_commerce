<?php
/**
 * @file
 * ac_commerce.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ac_commerce_default_rules_configuration() {
  $items = array();
  $items['commerce_tax_rate_dk_moms'] = entity_import('rules_config', '{ "commerce_tax_rate_dk_moms" : {
      "LABEL" : "Calculate dk moms",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Tax", "vat" ],
      "REQUIRES" : [ "commerce_tax" ],
      "USES VARIABLES" : { "commerce_line_item" : { "type" : "commerce_line_item", "label" : "Line item" } },
      "DO" : [
        { "commerce_tax_rate_apply" : {
            "USING" : {
              "commerce_line_item" : [ "commerce-line-item" ],
              "tax_rate_name" : "dk_moms"
            },
            "PROVIDE" : { "applied_tax" : { "applied_tax" : "Applied tax" } }
          }
        }
      ]
    }
  }');
  return $items;
}
