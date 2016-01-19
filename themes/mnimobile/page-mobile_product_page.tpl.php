<?php require_once(dirname(__FILE__).'/header.tpl.php'); ?>

<?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
<?php if ($tabs): print '<div id="tabs-wrapper">'; endif; ?>
<?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
<?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
<?php if ($show_messages && $messages): print '<div class="error-box">'.$messages.'</div>'; endif; ?>
<?php print $help; ?>
<?php print $content ?>
<div class="mobile_product_form">
<?php print $product_form ?>
</div>

<?php require_once(dirname(__FILE__).'/footer.tpl.php'); ?>