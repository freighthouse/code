<div class="block-container gray standard-leadform-homepage standard-leadform">
    <div class="inner">
        <?php if($headline): ?><h2 class="blue"><?php echo $headline; ?></h2><?php endif; ?>
      <?php if($blurb): ?><p><?php echo $blurb; ?></p><?php endif; ?>
        <div class="row">
            <div class="col-sm-6">
                <img src="/<?php print drupal_get_path('module', 'sunrun_leadforms'); ?>/assets/images/house.jpg" alt="" />
            </div><!-- /.col-sm-6 -->
            <div class="col-sm-6">
                <?php
                $sidebar = false;
                include 'standard-quote-form-inc.php'; ?>
            </div><!-- /.col-sm-6 -->
        </div><!-- /.row -->
    </div><!-- /.inner -->
</div><!-- /.standard-leadform-homepage -->
