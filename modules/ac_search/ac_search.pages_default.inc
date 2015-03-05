<?php
/**
 * @file
 * ac_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ac_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Search';
  $page->admin_description = '';
  $page->path = 's';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible:100_25_75';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '151f7a20-1f94-40e4-8cd5-44f238f4e98c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-028acbd0-055b-480f-9f0f-a9cd4161b304';
    $pane->panel = 'center';
    $pane->type = 'solrsearch_dynamic';
    $pane->subtype = 'solrsearch_dynamic';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '028acbd0-055b-480f-9f0f-a9cd4161b304';
    $display->content['new-028acbd0-055b-480f-9f0f-a9cd4161b304'] = $pane;
    $display->panels['center'][0] = 'new-028acbd0-055b-480f-9f0f-a9cd4161b304';
    $pane = new stdClass();
    $pane->pid = 'new-94aa6b17-bdde-40d3-b8f5-718c8bb6f923';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'current_search-ac_standard';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '94aa6b17-bdde-40d3-b8f5-718c8bb6f923';
    $display->content['new-94aa6b17-bdde-40d3-b8f5-718c8bb6f923'] = $pane;
    $display->panels['left'][0] = 'new-94aa6b17-bdde-40d3-b8f5-718c8bb6f923';
    $pane = new stdClass();
    $pane->pid = 'new-39699cc9-2b58-4b99-9559-3972a761013d';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-t1JuUwKPzvCdbrtcboDMUaPgwIW26KYF';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Category',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '39699cc9-2b58-4b99-9559-3972a761013d';
    $display->content['new-39699cc9-2b58-4b99-9559-3972a761013d'] = $pane;
    $display->panels['left'][1] = 'new-39699cc9-2b58-4b99-9559-3972a761013d';
    $pane = new stdClass();
    $pane->pid = 'new-8d6a7ec4-048b-4a4e-8430-d2041537ebf0';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-kJE2pVQbmoTNVe6RyNJpI0CcdoKMvEiD';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Brand',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8d6a7ec4-048b-4a4e-8430-d2041537ebf0';
    $display->content['new-8d6a7ec4-048b-4a4e-8430-d2041537ebf0'] = $pane;
    $display->panels['left'][2] = 'new-8d6a7ec4-048b-4a4e-8430-d2041537ebf0';
    $pane = new stdClass();
    $pane->pid = 'new-6e10a187-d3a5-482b-a9b4-2e02a3f2ec30';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-vSVHdx0LEQWkESKeSGgh4rcv3dY9NiT3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Price',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6e10a187-d3a5-482b-a9b4-2e02a3f2ec30';
    $display->content['new-6e10a187-d3a5-482b-a9b4-2e02a3f2ec30'] = $pane;
    $display->panels['left'][3] = 'new-6e10a187-d3a5-482b-a9b4-2e02a3f2ec30';
    $pane = new stdClass();
    $pane->pid = 'new-501080d5-4380-41aa-8328-aad7a3c74a48';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-TMc2mSY3vBfoBExAfnuoFD3nutUblKP8';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Size',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '501080d5-4380-41aa-8328-aad7a3c74a48';
    $display->content['new-501080d5-4380-41aa-8328-aad7a3c74a48'] = $pane;
    $display->panels['left'][4] = 'new-501080d5-4380-41aa-8328-aad7a3c74a48';
    $pane = new stdClass();
    $pane->pid = 'new-bfa6dbab-57ff-4053-b64f-76ae4af56457';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-MLK3c0QQPhRQ0kY2E1Q7CugXdyIHsKH0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Color',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'bfa6dbab-57ff-4053-b64f-76ae4af56457';
    $display->content['new-bfa6dbab-57ff-4053-b64f-76ae4af56457'] = $pane;
    $display->panels['left'][5] = 'new-bfa6dbab-57ff-4053-b64f-76ae4af56457';
    $pane = new stdClass();
    $pane->pid = 'new-fac8c0f7-df29-438b-a208-cf619bfbfc95';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Sort by',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'fac8c0f7-df29-438b-a208-cf619bfbfc95';
    $display->content['new-fac8c0f7-df29-438b-a208-cf619bfbfc95'] = $pane;
    $display->panels['left'][6] = 'new-fac8c0f7-df29-438b-a208-cf619bfbfc95';
    $pane = new stdClass();
    $pane->pid = 'new-f4320376-5c39-4410-b653-a2b572c6cbfa';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-solr_search-search_default';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f4320376-5c39-4410-b653-a2b572c6cbfa';
    $display->content['new-f4320376-5c39-4410-b653-a2b572c6cbfa'] = $pane;
    $display->panels['top'][0] = 'new-f4320376-5c39-4410-b653-a2b572c6cbfa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
