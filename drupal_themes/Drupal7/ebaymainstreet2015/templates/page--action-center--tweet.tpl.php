<?php print render($page['alerts']); ?>
<header class="header" id="header" role="header">
  <div class="header-content">
    <?php print render($page['header']); ?>
  </div>
  <div class="header-megamenu">
    <div class="header-megamenu-content">
      <?php print render($page['mega_menu']); ?>
    </div>
  </div>
</header>

<main class="main action-center-tweet-page" id="main" role="main">

  <div class="hero">
    <div class="hero-content">
      <?php print render($page['hero']); ?>
    </div>
  </div>

  <div class="content-feature">
    <div class="content-feature-content">
      <?php print render($page['content_feature']); ?>
    </div>
  </div>

  <div class="content-top">
    <div class="content-top-content">
      <?php print render($page['content_top']); ?>
    </div>
  </div>

  <div class="main-content">
    <?php print $messages; ?>
    <?php print render($page['content']); ?>

    <?php if ($page['sidebar']): ?>
      <div class="content-sidebar">
        <?php print render($page['sidebar']); ?>
      </div>
    <?php endif; ?>

  </div>

  <div class="content-bottom">
    <div class="content-bottom-content">
      <?php print render($page['content_bottom']); ?>
    </div>
  </div>

</main>

<footer class="footer" id="footer" role="footer">
  <div class="footer-content">
    <?php print render($page['footer']); ?>
  </div>
</footer>