<?php if (!$page): ?>
  <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
<?php endif; ?>

<?php if ($display_submitted): ?>
  <span class="submitted"><?php print $date; ?> — <?php print $name; ?></span>
<?php endif; ?>


  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['book_navigation']);
    print render($content);
   ?>


<?php if (!empty($content['links']['terms'])): ?>
  <div class="terms"><?php print render($content['links']['terms']); ?></div>
<?php endif;?>

<?php if (!empty($content['links'])): ?>
  <div class="links"><?php print render($content['links']); ?></div>
<?php endif; ?>