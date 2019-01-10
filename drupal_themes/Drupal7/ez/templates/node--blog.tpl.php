<?php if (!$page): ?>
  <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
<?php endif; ?>

<?php if ($display_submitted): ?>
  <span class="submitted"><?php print format_date($node->created, 'custom', 'F j, Y'); ?> — <?php print $name; ?></span>
<?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['book_navigation']);
    print render($content);
  ?>