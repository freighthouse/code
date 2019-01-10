<?php

  /**
   * @file
   *   Display tweet information for senators and representatives
   * @args
   * 'variables' => array('senators' => NULL, 'representatives'=> NULL),
   */
?>

<?php if ((!empty($senators)) && (count($senators) > 0)): ?>
  <h3>Tweet Your U.S. Senators</h3>
  <?php foreach ($senators as $senator): ?>
  <div class="preview">
    <textarea disabled="disabled"><?php echo $senator; ?></textarea>
  </div>
  <div class="link">
    <a id="post-to-twitter" class="senator" href="http://twitter.com/intent/tweet?text=<?php echo urlencode($senator); ?>" target="_blank">Tweet This</a>
  </div>
  <?php endforeach; ?>

<?php endif; ?>

<?php if (!empty($representatives[0])): ?>
  <h3>Tweet Your U.S. Representative</h3>
  <?php foreach ($representatives as $rep): ?>
  <div class="preview">
    <textarea disabled="disabled"><?php echo $rep; ?></textarea>
  </div>
  <div class="link">
    <a id="post-to-twitter" class="representative" href="http://twitter.com/intent/tweet?text=<?php echo urlencode($rep); ?>" target="_blank">Tweet This</a>
  </div>
  <?php endforeach; ?>

<?php endif; ?>
