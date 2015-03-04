<?php
$plugin = array(
  'title' => t('AC search dynamic view'),
  'category' => t('Solr search panes'),
  'defaults' => array(),
  'render last' => 1,
);

/**
 * It's necessary to render the view manually, so we can set render last.
 */
function ac_search_solrsearch_dynamic_content_type_render($subtype, $conf, $panel_args, $context) {
  // prepare the block element
  $block = new stdClass();

  // Find the arguments to filter on before the view is even loaded
  // This way, the ac_adapter:processActiveItems handles setting the filters
  ac_search_active_terms();

  $view = views_get_view('solr_search');
  if ($view) {
    //Set the display to use
    $view->set_display('search_default');
    //Execute view
    $view->pre_execute();
    $view->execute();

    //Render the block using the view
    $block->content = $view->render();
  }

  return $block;
}
