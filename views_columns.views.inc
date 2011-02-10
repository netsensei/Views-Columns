<?php

/**
 * Implements hook_views_plugins().
 */
function views_columns_views_plugins() {
  $path = drupal_get_path('module', 'views_columns');
  return array(
    'style' => array(
      'columns' => array(
        'title' => t('Columns'),
        'help' => t('Displays columns one after another.'),
        'handler' => 'views_plugin_style_columns',
        'theme' => 'views_view_columns',
        'theme path' => $path .'/theme',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'path' => $path . '/plugins',
      ),
    ),
  );
}