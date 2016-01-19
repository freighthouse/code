<div class="container page_tabs">
  <div class="col-sm-2 col-xs-12 news_button_div">
    <a class="btn news_button" href="../news-front" type="button" style="width:116%;background-color:#ed9b33!important;color:#fff!important">All</a>
  </div>
  <div class="col-sm-2 col-xs-12 news_button_div">
    <a class="btn news_button" href="../news-events/press-releases" type="button" style="width:116%">Press Releases</a>
  </div>
  <div class="col-sm-2 col-xs-12 news_button_div">
    <a class="btn news_button" href="../news-events/conferences" type="button" style="width:116%">Conferences</a>
  </div>
  <div class="col-sm-2 col-xs-12 news_button_div">
    <a class="btn news_button" href="../news-events/webinars" type="button" style="width:116%">Webinars</a>
  </div>
  <div class="col-sm-2 col-xs-12 news_button_div">
    <a class="btn news_button" href="../news-events/blog" type="button" style="width:116%">Blog</a>
  </div>
  <div class="col-sm-2 col-xs-12 news_button_div">
    <a class="btn news_button" href="../news-events/newsletters" type="button" style="width:116%">Newsletters</a>
  </div>
</div>
<div class="col-md-8 col-sm-12">
<div class="all_news_title">News</div>
<?php if ($rows): ?>
  <div class="view-content">
    <?php print $rows; ?>
  </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>
</div>
<div class="col-md-4 col-sm-12">
<div class="all_events_title">Events</div>
  <?php echo views_embed_view('news_events', $display_id = 'events');?>
</div>
