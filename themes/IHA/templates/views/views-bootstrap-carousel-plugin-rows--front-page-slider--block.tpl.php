<div class="col-xs-12 col-sm-6 hero_image">
  <div class="pull-right">
    <?php print $image ?>
  </div>
</div>
<div class="col-xs-12 col-sm-6">
<?php if (!empty($title) || !empty($description)): ?>
  <div class="carousel-caption">
    <?php if (!empty($title)): ?>
      <div class="hero_title"><?php print $title ?></div>
    <?php endif ?>
    <?php if (!empty($description)): ?>
      <div class="hero_description"><?php print $description ?></div>
    <?php endif ?>
    <div class="hero_button">
      <?php if (!empty($buttontext)): ?>
      <?php if (!empty($buttonlink)): ?>
       <a href="<?php print $buttonlink ?>" class="btn btn-primary active" role="button">
      <?php endif ?>
      <?php print $buttontext ?>
      <?php if (!empty($buttonlink)): ?></a><?php endif ?>
      <?php endif ?>
    </div>
  </div>
<?php endif ?>
</div>
