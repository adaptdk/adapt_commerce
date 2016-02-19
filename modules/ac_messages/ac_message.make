api = 2
core = 7.x

; Commerce Message
projects[commerce_message][subdir] = 'contrib'
projects[commerce_message][version] = '1.0-rc4'
projects[commerce_message][patch][2171201] = https://www.drupal.org/files/issues/undefined_property-2171201-19.patch
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
