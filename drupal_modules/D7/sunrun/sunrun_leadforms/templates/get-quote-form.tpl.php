<div class="block-container gray get-quote-form">
  <div class="inner">
    <h2 class="blue">lead form headline</h2>
    <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.</p>
    <div class="row">
        <div class="col-sm-6">
            <img src="<?php print drupal_get_path('module', 'sunrun_leadforms'); ?>/assets/images/house.jpg" alt="" />
        </div><!-- /.col-sm-6 -->
      <div class="col-sm-6">
        <script src="<?php echo $environment; ?>/js/forms2/js/forms2.min.js"></script>
        <form id="mktoForm_<?php echo $form_id; ?>"></form>
      </div><!-- /.col-sm-6 -->
    </div><!-- /.row -->
  </div><!-- /.inner -->
</div><!-- /.get-quote-form -->
