<?php

class acSearchApiAlterCallback extends SearchApiAbstractAlterCallback {
  public function alterItems(array &$items) {
    foreach ($items as $id => &$item) {
      if ($item->type == 'product_display') {
        $nw = entity_metadata_wrapper('node', $item);
        if ($nw->__isset('field_products')) {
          $products = $nw->field_products->value();
          $product = reset($products);

          $pw = entity_metadata_wrapper('commerce_product', $product);

          // Define sortable price
          $item->sortable_price = (int) $pw->commerce_price->amount->value();
        }
      }
    }
  }

  public function propertyInfo() {
    $ret = array();

    $ret['sortable_price'] = array(
      'label' => 'Sortable price',
      'description' => 'Sortable price',
      'type' => 'integer',
    );

    return $ret;
  }
}
