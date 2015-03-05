<?php
/**
 * @file
 * ac_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ac_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ac_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

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
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "string" },
        "field_brand" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_color" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_products:commerce_price:amount_decimal" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_products:field_size" : { "type" : "list\\u003Cstring\\u003E" },
        "field_products_commerce_price_amount_decimal_asc" : { "type" : "decimal" },
        "field_products_commerce_price_amount_decimal_desc" : { "type" : "decimal" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "sortable_price" : { "type" : "integer" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "default" : "0", "bundles" : { "product_display" : "product_display" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "ac_search_alter" : { "status" : 1, "weight" : "-47", "settings" : [] },
        "search_api_ranges_alter" : {
          "status" : 1,
          "weight" : "-46",
          "settings" : { "fields" : { "field_products:commerce_price:amount_decimal" : {
                "name" : "Products \\u00bb Price \\u00bb Amount (decimal)",
                "description" : "",
                "type" : "decimal"
              }
            }
          }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "-45",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-44", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-43", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-42", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-41", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_brand" : true, "field_color" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function ac_search_default_search_api_sort() {
  $items = array();
  $items['ac_index__created'] = entity_import('search_api_sort', '{
    "index_id" : "ac_index",
    "field" : "created",
    "name" : "Date created",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "ac_index__created",
    "default_sort" : "1",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Date created" }
  }');
  $items['ac_index__sortable_price'] = entity_import('search_api_sort', '{
    "index_id" : "ac_index",
    "field" : "sortable_price",
    "name" : "Sortable price",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "ac_index__sortable_price",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Sortable price" }
  }');
  return $items;
}
