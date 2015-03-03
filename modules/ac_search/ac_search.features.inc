<?php
/**
 * @file
 * ac_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function ac_search_default_search_api_index() {
  $items = array();
  $items['ac_index'] = entity_import('search_api_index', '{
    "name" : "ac index",
    "machine_name" : "ac_index",
    "description" : null,
    "server" : "ac_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "300",
      "fields" : { "search_api_language" : { "type" : "string" } }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
