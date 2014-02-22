<?php

/**
 * @file:
 * Settings and variables for Adapt Commerce module
 */

// List of modules to enable on install. All these must be present in the .make
// file of adapt_commerce. These modules are not depencies as we wan't to be able
// to disadble them on a pr. project basis.
$modules_enable = array(
  'commerce_shipping',
  'commerce_checkout_progress',
  'commerce_add_to_cart_confirmation',
  'commerce_price_components',
  'commerce_extra_price_formatters',
  'commerce_shipping',
  'commerce_flat_rate',
);
