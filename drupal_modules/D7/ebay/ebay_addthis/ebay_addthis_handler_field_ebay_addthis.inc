<?php

/**
 * @file
 * Definition of mymodule_handler_handlername.
 */
 
/**
 * Description of what my handler does.
 */
class ebay_addthis_handler_field_ebay_addthis extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Remove the alteration stuff
    unset($form['alter']);
  }

  function render($values) {
    if (isset($values->_field_data['nid']['entity'])) {
      $node = $values->_field_data['nid']['entity'];
    }
    else {
      $node = NULL;
    }

    return ebay_addthis_buttons_render($node);
  }
}