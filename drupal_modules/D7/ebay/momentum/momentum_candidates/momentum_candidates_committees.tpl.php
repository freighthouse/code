<?php

/**
 * @file
 *   Committee template for BIPAC Officials
 *
 * @args
 *   $committee_chamber
 *   $committee_type
 *   $title
 *   $name
 */
?>

<?php if (!empty($name)): ?><p><?php echo $name; ?></p><?php endif; ?>
<ul>
<?php if (!empty($title)): ?><li><?php echo $title; ?></li><?php endif; ?>
</ul>
