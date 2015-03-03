; make file
core = 7.x
api = 2

; ********************
; * MODULES COMMERCE *
; ********************

; commerce
projects[commerce][type] = 'module'
projects[commerce][subdir] = 'contrib'
projects[commerce][version] = '1.11'

; commerce_checkout_progress
projects[commerce_checkout_progress][type] = 'module'
projects[commerce_checkout_progress][subdir] = 'contrib'
projects[commerce_checkout_progress][version] = '1.3'

; commerce_add_to_cart_confirmation
projects[commerce_add_to_cart_confirmation][type] = 'module'
projects[commerce_add_to_cart_confirmation][subdir] = 'contrib'
projects[commerce_add_to_cart_confirmation][download][type] = 'git'
projects[commerce_add_to_cart_confirmation][download][url] = 'http://git.drupal.org/project/commerce_add_to_cart_confirmation.git'
projects[commerce_add_to_cart_confirmation][download][revision] = '69ee3178724e688b0c388b051e1a58a7a54636f1'
projects[commerce_add_to_cart_confirmation][download][branch] = "7.x-1.x"

; commerce_price_components
projects[commerce_price_components][type] = 'module'
projects[commerce_price_components][subdir] = 'contrib'
projects[commerce_price_components][download][type] = 'git'
projects[commerce_price_components][download][url] = 'http://git.drupal.org/project/commerce_price_components.git'
projects[commerce_price_components][download][revision] = 'b1c63c97057e63ba6ff199a91d7c31a28e5e0595'
projects[commerce_price_components][download][branch] = "7.x-1.x"

; commerce_extra_price_formatters
projects[commerce_extra_price_formatters][type] = 'module'
projects[commerce_extra_price_formatters][subdir] = 'contrib'
projects[commerce_add_to_cart_confirmation][version] = '1.1'

; commerce_shipping
projects[commerce_shipping][type] = 'module'
projects[commerce_shipping][subdir] = 'contrib'
projects[commerce_shipping][version] = '2.1'

; commerce_flat_rate
projects[commerce_flat_rate][type] = 'module'
projects[commerce_flat_rate][subdir] = 'contrib'
projects[commerce_flat_rate][version] = '1.0-beta2'

; commerce_features
projects[commerce_features][type] = 'module'
projects[commerce_features][subdir] = 'contrib'
projects[commerce_features][version] = '1.0'
projects[commerce_features][patch][] = 'http://drupal.org/files/1402762_export_flat_rate_commerce_features-6.patch'

; commerce_rules_extra
projects[commerce_rules_extra][type] = 'module'
projects[commerce_rules_extra][subdir] = 'contrib'
projects[commerce_rules_extra][version] = '2.1'

; ****************
; * TRANSLATIONS *
; ****************

translations[] = da
