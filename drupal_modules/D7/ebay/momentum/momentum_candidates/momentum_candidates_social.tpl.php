<?php

/**
 * @file
 *   Social template for BIPAC Officials
 *
 * @args
 *   $website
 *   $webform
 *   $Facebook
 *   $Twitter
 *   $YouTube
 */
?>

<ul class="official-social">

  <?php if (!empty($website)): ?>
    <li class="official-social-website">
      <a class="official-social-website-link" href="<?php print $website; ?>">
        <span class="official-social-link-text"><?php print t('Website'); ?></span>
      </a>
    </li>
  <?php endif; ?>

  <?php if (!empty($webform)): ?>
    <li class="official-social-webform">
      <a class="official-social-webform-link" href="<?php print $webform; ?>">
        <span class="official-social-link-text"><?php print t('Webform'); ?></span>
      </a>
    </li>
  <?php endif; ?>

  <?php if (!empty($Facebook)): ?>
    <li class="official-social-facebook">
      <a class="official-social-facebook-link" href="<?php print $Facebook; ?>">
        <span class="official-social-link-text"><?php print t('Facebook'); ?></span>
      </a>
    </li>
  <?php endif; ?>

  <?php if (!empty($Twitter)): ?>
    <li class="official-social-twitter">
      <a class="official-social-twitter-link" href="<?php print $Twitter; ?>">
        <span class="official-social-link-text"><?php print t('Twitter'); ?></span>
      </a>
      <?php if (!empty($handle)): ?>
        <div class="official-social-twitter-follow">
          <?php // echo l(t('Follow @' . $handle), 'https://twitter.com/intent/follow', array('query' => array('screen_name' => $handle))); ?>
          <a href="https://twitter.com/<?php print $handle; ?>" class="twitter-follow-button" data-show-count="false" data-dnt="true">Follow @<?php print $handle; ?></a>
          <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+'://platform.twitter.com/widgets.js';fjs.parentNode.insertBefore(js,fjs);}}(document, 'script', 'twitter-wjs');</script>
        </div>
      <?php endif; ?>
    </li>
  <?php endif; ?>

  <?php if (!empty($YouTube)): ?>
    <li class="official-social-youtube">
      <a class="official-social-youtube-link" href="<?php print $YouTube; ?>">
        <span class="official-social-link-text"><?php print t('YouTube'); ?></span>
      </a>
    </li>
  <?php endif; ?>

</ul>
