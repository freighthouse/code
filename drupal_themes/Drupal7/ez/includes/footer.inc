<section class="footer">
  <footer class="container">
    <div class="row">
      <div class="col-sm-3">
        <h3>About EZ Texting</h3>
        <?php print theme('links', array('links' => menu_navigation_links('menu-about')));?>
      </div>
      <div class="col-sm-3">
        <h3>Resources</h3>
        <?php print theme('links', array('links' => menu_navigation_links('menu-resources')));?>
      </div>
      <div class="col-sm-3">
        <h3>Help / Contact</h3>
        <?php print theme('links', array('links' => menu_navigation_links('menu-help-contact')));?>
      </div>
      <div class="footer-brand col-sm-3">
        <p class="social"><a href="https://www.facebook.com/EzTexting"><i class="fa fa-facebook"></i></a> <a href="https://twitter.com/EzTexting"><i class="fa fa-twitter"></i></a> <a href="https://plus.google.com/104053580645373212760"><i class="fa fa-google-plus"></i></a></p>
      </div>
    </div>
    <p class="disclaimer">EZ Texting is a 100% opt-in service. Please see our <a href="<?php print base_path(); ?>privacy-policy" rel="nofollow">Privacy Policy</a>, <a href="<?php print base_path(); ?>terms" rel="nofollow">Terms Of Use</a> &amp; <a href="<?php print base_path(); ?>anti-spam-policy" rel="nofollow">Anti-Spam Policy</a> to learn about our position on SPAM and the privacy of your data.</p>
    <p class="disclaimer">Msg&amp;data rates may apply in the US. Standard message and data rates apply in Canada. To unsubscribe from an EZ Texting ® list, simply text ‘STOP’ to the originating short code or <a href="https://www.eztexting.com/help">contact Support</a>.</p>
    <p class="disclaimer">EZ Texting neither provides lists of phone numbers nor do we access our clients' contact lists </p>
    <p class="disclaimer">EZ Texting is part of the trusted <a href="https://www.callfire.com">CallFire</a> family of companies.<br>
    &copy; CallFire Inc. <?php echo date("Y") ?></p>
  </footer>
</section>
