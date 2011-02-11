<?php
// $Id:$

/**
 * @file
 * Contains the default style plugin.
 */

/**
 * Default style plugin to render a view as columns that can be stacked or floated
 * decorations.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_columns extends views_plugin_style {

  function option_definition() {
    $options = parent::option_definition();
    $options['columns'] = array('default' => '1');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $form['columns'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of columns'),
      '#default_value' => $this->options['columns'],
    );
  }
}
