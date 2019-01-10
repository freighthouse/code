<?php

  /**
   * @file
   *   Theme implementation for bipac
   *
   * Available variables:
   * - $officials: Array of elected official with values
   *
   * Values:
   * - photo
   * - title
   * - first_name
   * - last_name
   * - party
   * - address
   * - city
   * - state
   * - zip
   * - phone
   * - fax
   * - site
   * - youtube
   * - facebook
   */

?>
<div class="bipac">
  <div class="officials" id="results">
  <?php foreach($officials as $official): ?>
    <div class="official <?php echo $official['type']; ?> <?php echo strtolower($official['party']); ?>">
      <?php if ($official['type'] === 'state_official'): ?>
        <?php if (!isset($state_block)): ?>
          <?php echo '<h4 class="official--level">' . t('State Officials') . '</h4>'; ?>
        <?php endif; ?>
        <?php $state_block = 1; ?>
      <?php else: ?>
        <?php if (!isset($fed_block)): ?>
          <?php echo '<h4 class="official--level">' . t('Federal Officials') . '</h4>'; ?>
        <?php endif; ?>
        <?php $fed_block = 1; ?>
      <?php endif; ?>
      <?php if(isset($official['photo'])): ?>
          <img src="<?php echo $official['photo']; ?>" alt="<?php echo $official['title'] . ' ' .  $official['first_name'] . ' ' . $official['last_name']; ?>" class="official--photo" />
      <?php endif; ?>

      <div class="official-text-content">

        <h5 class="official--name">
        <?php if ($official['type'] === 'state_official'): ?>
          <?php echo 'State '; ?>
        <?php endif; ?>
        <?php echo $official['title']; ?> <?php echo $official['first_name']; ?> <?php echo $official['last_name']; ?> (<?php echo $official['party']; ?>)</h5>

        <ul class="official--social-media-list">
          <?php if(!empty($official['site'])): ?>
            <li class="official-website-icon official-icon-item">
              <a href="<?php echo $official['site']; ?>" title="official site" target="_blank">
                <?php echo $official['site']; ?>
              </a>
            </li>
          <?php endif; ?>
          <?php if(!empty($official['facebook'])): ?>
            <li  class="official-facebook-icon official-icon-item">
              <a href="<?php echo $official['facebook']; ?>" title="official facebook" target="_blank">
                <?php echo $official['facebook']; ?>
              </a>
            </li>
          <?php endif; ?>
          <?php if(!empty($official['twitter'])): ?>
            <li class="official-twitter-icon official-icon-item">
              <a href="<?php echo $official['twitter']; ?>" title="official twitter" target="_blank">
                <?php echo $official['twitter']; ?>
              </a>
            </li>
          <?php endif; ?>
          <?php if(!empty($official['youtube'])): ?>
            <li class="official-youtube-icon official-icon-item">
              <a href="<?php echo $official['youtube']; ?>" title="official youtube" target="_blank">
                <?php echo $official['youtube']; ?>
              </a>
            </li>
          <?php endif; ?>
        </ul>
        <ul class="official--contact-info">
          <?php if (!empty($official['address'])): ?>
            <li class="official--address official-location-icon official-icon-item"><?php echo $official['address']; ?><br />
            <?php echo $official['city']; ?>, <?php echo $official['state']; ?> <?php echo substr($official['zip'],0,5); ?></li>
          <?php endif; ?>
          <?php if (!empty($official['phone'])): ?><li class="official--phone official-phone-icon official-icon-item">Phone: <?php echo $official['phone']; ?></li><?php endif; ?>
          <?php if (!empty($official['fax'])): ?><li class="official--fax official-fax-icon official-icon-item">Fax: <?php echo $official['fax']; ?></li><?php endif; ?>
        </ul>

      </div>

    </div>
  <?php endforeach; ?>
  </div>
</div>
