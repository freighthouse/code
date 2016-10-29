<div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title) : ?>
    <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($header) : ?>
    <div class="view-header">
        <?php print $header; ?>
    </div>
    <?php endif; ?>

    <?php if ($categories_menu) : ?>
    <?php print $categories_menu; ?>
    <?php endif; ?>

    <?php if ($exposed) : ?>
    <div class="view-filters">
        <?php print $exposed; ?>
    </div>
    <?php endif; ?>

    <?php if ($attachment_before) : ?>
    <div class="row">
      <div class="attachment attachment-before col-sm-9 col-md-9 col-lg-9">
        <?php print $attachment_before; ?>
      </div>

      <div class="attachment attachment-after col-sm-3 col-md-3 col-lg-3">
        <? if ($social_links): ?>
            <?php print $social_links; ?>
        <? endif; ?>
      </div>
    </div>
    <?php endif; ?>

    <?php if ($attachment_after) : ?>
    <div class="attachment attachment-after">
        <?php print $attachment_after; ?>
    </div>
    <?php endif; ?>

    <?php if ($more) : ?>
    <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer) : ?>
    <div class="view-footer">
        <?php print $footer; ?>
    </div>
    <?php endif; ?>

    <?php if ($feed_icon) : ?>
    <div class="feed-icon">
        <?php print $feed_icon; ?>
    </div>
    <?php endif; ?>

</div><?php /* class view */ ?>

<?php if ($events_ctas) : ?>
    <?php print $events_ctas; ?>
<?php endif; ?>
