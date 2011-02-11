<?php

/**
 * Display the view as columns of rows
 */
function template_preprocess_views_view_columns(&$vars) {
  $view     = $vars['view'];
  $rows     = $vars['rows'];
  $options  = $vars['options'];
  
  $column_count = $options['columns'];
  $columns = array();
  $row_count = count($rows);
  $offset = 0;
  
  $items_per_column = ceil($row_count / $column_count);

  for ($i = 1; $i <= $column_count; $i++) {
    $columns[] = array_slice($rows, $offset, $items_per_column); 
    $offset = $i * $items_per_column;
  }

  $leftover = array_slice($rows, $offset, ($row_count % $column_count));
  $columns[$column_count - 1] = array_merge($columns[$column_count - 1], $leftover);
  $vars['columns'] = $columns;
  
  foreach ($columns as $cid => $column) {
    $vars['classes_array'][$cid]['column'][] = 'views-col';
    $vars['classes_array'][$cid]['column'][] = 'views-col-' . ($cid + 1);
    $vars['classes_array'][$cid]['column'][] = 'views-col-' . ($cid % 2 ? 'even' : 'odd');
    if ($cid == 0) {
      $vars['classes_array'][$cid]['column'][] = 'views-col-first';
    }
    if ($cid == count($columns) -1) {
      $vars['classes_array'][$cid]['column'][] = 'views-col-last';
    }
    
    $vars['classes'][$cid]['column'] = implode(' ', $vars['classes_array'][$cid]['column']);
    
    foreach ($column as $rid => $row) {
      $vars['classes_array'][$cid][$rid][] = 'views-row';
      $vars['classes_array'][$cid][$rid][] = 'views-row-' . ($rid + 1);
      $vars['classes_array'][$cid][$rid][] = 'views-row-' . ($rid % 2 ? 'even' : 'odd');
      if ($rid == 0) {
        $vars['classes_array'][$cid][$rid][] = 'views-row-first';
      }
      if ($rid == count($column) -1) {
        $vars['classes_array'][$cid][$rid][] = 'views-row-last';
      }
      // Flatten the classes to a string for each row for the template file.
      $vars['classes'][$cid][$rid] = implode(' ', $vars['classes_array'][$cid][$rid]);
    }
  }
}
