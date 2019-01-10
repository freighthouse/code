<div class="block-container standard-leadform-horizontal standard-leadform">
    <div class="inner">
    	<div class="row">
        <?php           

          if($headline): ?>
          <div id="headline-container">
            <h3 class="blue text-center" id="standard-leadform-horizontal-headline"><?php echo $headline; ?></h3>
        		<div class="logo-rule col-sm-12 center-text"><svg class="icon icon-block-sr-logo"><use xlink:href="#icon-block-sr-logo"/></svg></div>
        		<!-- //.logo-rule.col-sm-12.center-text -->
          </div>
          
    		<?php endif; ?>
          <?php if($blurb): ?><p><?php echo $blurb; ?></p><?php endif; ?>
    	</div><!-- //.row -->
      <div class="row">
          <div class="col-sm-12">
              <?php
              $sidebar = false;
              $inline = true;
              include 'standard-quote-form-inc.php'; ?>
          </div><!-- /.col-sm-6 -->            
      </div><!-- /.row -->
    </div><!-- /.inner -->
</div><!-- /.standard-leadform-horizontal -->
