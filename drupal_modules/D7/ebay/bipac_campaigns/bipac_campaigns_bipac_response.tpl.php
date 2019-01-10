<?php

/**
 * @file
 *   Theme template for BIPAC response with pictures
 *
 * Available variables in the theme include:
 *
 * 1) An array of $legislators, where each item has:
 *   $legislator->name
 *   $legislator->photo
 *   $legislator->dphone (district phone)
 *   $legislator->cphone (capital phone)
 *   $legislator->type (senator or representative)
 *
 */
?>
<?php if($legislators): ?>
<div class="bipac-response-legislators">
  <?php foreach($legislators as $legislator): ?>
    <div class = "<?php echo $legislator['type']; ?>">
      <?php if($legislator['name']): ?>
        <div class = "name"><?php echo $legislator['name']; ?></div>
      <?php endif; ?>
      <?php if($legislator['dphone']): ?>
        <div class = "district-phone"><?php echo $legislator['dphone']; ?></div>
      <?php endif; ?>
      <?php if($legislator['cphone']): ?>
        <div class = "capital-phone"><?php echo $legislator['cphone']; ?></div>
      <?php endif; ?>
      <?php if($legislator['photo']): ?>
        <div class = "photo"><img src = "<?php echo $legislator['photo']; ?>" alt = "legislator photo" /></div>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif; ?>
