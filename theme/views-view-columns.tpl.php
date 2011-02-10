<?php
// $Id:$
/**
 * @file views-view-columns.tpl.php
 * Default simple view template to display a list of rows as columns
 *
 * @ingroup views_templates
 */
?>

<?php foreach ($columns as $col_id => $column): ?>
  <div class="<?php print $classes[$col_id]['column']; ?>">
    <?php foreach ($column as $id => $row): ?>
      <div class="<?php print $classes[$col_id][$id]; ?>">
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
<?php endforeach; ?>

