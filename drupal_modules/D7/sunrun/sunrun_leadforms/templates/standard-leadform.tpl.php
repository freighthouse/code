<div class="standard-leadform leadform">
  <?php if (isset($form_id) && in_array($form_id, array(1404, 1406, 214, 217, 1187, 110) ) ): ?>
    <script src="<?php echo $environment; ?>/js/forms2/js/forms2.min.js"></script>
    <form id="mktoForm_<?php echo $form_id; ?>"></form>
    <form id="mktoForm_<?php echo $form_id_step_2; ?>"></form>
  <?php else: ?>
    <?php
    $sidebar = true;
    include 'standard-quote-form-inc.php';
    ?>
  <?php endif; ?>
</div><!-- /.standard-leadform -->
