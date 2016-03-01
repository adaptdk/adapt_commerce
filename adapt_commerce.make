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

; Commerce discount
projects[commerce_discount][subdir] = 'contrib'
projects[commerce_discount][type] = module
projects[commerce_discount][version] = '1.0-alpha7'

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
projects[commerce_features][patch][1402762] = 'http://drupal.org/files/1402762_export_flat_rate_commerce_features-6.patch'
projects[commerce_features][patch][1973602] = 'http://www.drupal.org/files/issues/make_commerce_checkout-1973602-8.patch'

; commerce_rules_extra
projects[commerce_rules_extra][type] = 'module'
projects[commerce_rules_extra][subdir] = 'contrib'
projects[commerce_rules_extra][version] = '2.1'

; commerce_coupon
projects[commerce_coupon][subdir] = "contrib"
projects[commerce_coupon][type] = module
projects[commerce_coupon][download][type] = git
projects[commerce_coupon][download][url] = http://git.drupal.org/project/commerce_coupon.git
projects[commerce_coupon][download][revision] = 124fd85c49ae33885e3da4ecab1f71dcb92268b9
projects[commerce_coupon][patch][] = "http://svnhosttest.adapt.dk/case_and_space_insensitive_coupon.patch"
projects[commerce_coupon][patch][1797184] = http://www.drupal.org/files/commerce_coupon-1797184-do-not-load-all-coupons-on-checkout-24.patch

; commerce_coupon_pct
projects[commerce_coupon_pct][type] = 'module'
projects[commerce_coupon_pct][subdir] = 'contrib'
projects[commerce_coupon_pct][version] = '1.0-beta7'

; commerce_coupon_fixed_amount
projects[commerce_coupon_fixed_amount][type] = 'module'
projects[commerce_coupon_fixed_amount][subdir] = 'contrib'
projects[commerce_coupon_fixed_amount][version] = '1.0-beta7'

; ********************
; * MODULES SEARCH *
; ********************

; facetapi
projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.5"

; Regression: 'Show more/fewer' links are no longer translatable - https://www.drupal.org/node/2311585
projects[facetapi][patch][] = 'http://www.drupal.org/files/issues/2311585-3-facetapi-7.x-1.x-translate_more_link.patch'

; search_api
projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.14"

; TrackItemChange not checking for empty $item_ids - https://www.drupal.org/node/1956650
; Says committed, but still not in version 1.14
projects[search_api][patch][] = https://www.drupal.org/files/1956650-2--tracking_empty_item_ids--debugging.patch

; search_api_solr
projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.6"

; search_api_sorts
projects[search_api_sorts][subdir] = "contrib"
projects[search_api_sorts][version] = "1.5"
projects[search_api_sorts][patch][] = https://www.drupal.org/files/issues/search-api-sorts-inability-to-add-fields-2202093-6_0.patch

; search_api_ranges
projects[search_api_ranges][type] = 'module'
projects[search_api_ranges][subdir] = 'contrib'
projects[search_api_ranges][download][type] = 'git'
projects[search_api_ranges][download][url] = 'http://git.drupal.org/project/search_api_ranges.git'
projects[search_api_ranges][download][revision] = 'bcc17c1'
projects[search_api_ranges][download][branch] = "7.x-1.x"
projects[search_api_ranges][patch][] = https://www.drupal.org/files/issues/search_api_ranges-existing-filter-tag-2294807-1.patch

; ******************
; * EMAIL MESSAGES *
; ******************

; Commerce Message
projects[commerce_message][subdir] = 'contrib'
projects[commerce_message][version] = '1.0-rc4'
projects[commerce_message][patch][1895418] = https://www.drupal.org/files/issues/commerce_message-1895418-63-order-summary-missing.patch
projects[commerce_message][patch][2366413] = https://www.drupal.org/files/issues/2366413-unlock-order-summary-for-other-message-types.patch

; Emogrifier
projects[emogrifier][subdir] = 'contrib'
projects[emogrifier][version] = '2.0-beta1'

; HTMLMail
projects[htmlmail][subdir] = 'contrib'
projects[htmlmail][version] = '2.65'
projects[htmlmail][patch][1692966] = https://www.drupal.org/files/1692966-htmlmail-mailsystem-html-to-text.patch

; Mailsystem
projects[mailsystem][subdir] = 'contrib'
projects[mailsystem][version] = '2.34'

; Message
projects[message][subdir] = 'contrib'
projects[message][version] = '1.10'
projects[message][patch][2629474] = https://www.drupal.org/files/issues/message-mysql57_compatibility-2629474-4.patch

; Message Notify
projects[message_notify][subdir] = 'contrib'
projects[message_notify][version] = '2.5'

; Pathologic
projects[pathologic][subdir] = 'contrib'
projects[pathologic][version] = '2.12'

;---- LIBRARIES -----
; Emogrifier library
libraries[emogrifier_lib][download][type] = git
libraries[emogrifier_lib][download][url] = 'git@github.com:jjriv/emogrifier.git'
libraries[emogrifier_lib][destination] = libraries
libraries[emogrifier_lib][directory_name] = 'emogrifier'

; ****************
; * TRANSLATIONS *
; ****************

; translations[] = da
