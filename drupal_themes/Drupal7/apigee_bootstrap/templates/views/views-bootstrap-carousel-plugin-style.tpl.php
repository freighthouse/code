<div id="views-bootstrap-carousel-<?php print $id ?>" class="<?php print $classes ?>" <?php print $attributes ?>>
  <?php if ($indicators): ?>
    <!-- Carousel indicators -->
    <ol class="carousel-indicators">
      <?php foreach ($rows as $key => $value): ?>
        <li data-target="#views-bootstrap-carousel-<?php print $id ?>" data-slide-to="<?php print $key ?>" class="<?php if ($key === 0) print 'active' ?>"></li>
      <?php endforeach ?>
    </ol>
  <?php endif ?>

  <!-- Carousel items -->
  <div class="carousel-inner">
    <?php foreach ($rows as $key => $row): ?>
      <div class="item <?php if ($key === 0) print 'active' ?>">
        <?php print $row ?>
      </div>
    <?php endforeach ?>
  </div>

  <?php if ($navigation): ?>
    <!-- Carousel navigation -->
    <a class="previous-slide-button" href="#views-bootstrap-carousel-<?php print $id ?>" data-slide="prev">
      <i class="fa fa-angle-left"></i>
    </a>
    <a class="next-slide-button" href="#views-bootstrap-carousel-<?php print $id ?>" data-slide="next">
      <i class="fa fa-angle-right"></i>
    </a>
  <?php endif ?>
</div>
