<?php

/**
 * @file
 * Customize confirmation screen after successful submission.
 *
 * This file may be renamed "webform-confirmation-[nid].tpl.php" to target a
 * specific webform e-mail on your site. Or you can leave it
 * "webform-confirmation.tpl.php" to affect all webform confirmations on your
 * site.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $confirmation_message: The confirmation message input by the webform author.
 * - $sid: The unique submission ID of this submission.
 */
?>

<div class="webform-confirmation">
  <?php if ($confirmation_message): ?>
    <?php print $confirmation_message ?>
  <?php else: ?>
    <p><?php print t('Thank you, your submission has been received.'); ?></p>
  <?php endif; ?>
</div>

<!--div class="links">
  <a href="<?php //print url('node/'. $node->nid) ?>"><?php //print t('Go back to the form') ?></a>
</div-->
<script type="text/javascript">
   var hostProtocol = (("https:" == document.location.protocol) ? "https" : "http");
   document.write('<scr'+'ipt src="', hostProtocol+
   '://105.xg4ken.com/media/getpx.php?cid=ed4a2658-4a57-44c8-9309-3127d56bfb1a','" type="text/JavaScript"><\/scr'+'ipt>');
</script>
<?php
$type_var = (arg(0) == "contact-sales" ? "US:ContactSales" : "US:ContactPartner");
$orderId_var = date('m-d-Y');?>
<script type="text/javascript">
   var params = new Array();
   params[0]='id=ed4a2658-4a57-44c8-9309-3127d56bfb1a';
   params[1]='type=<?php echo $type_var;?>';
   params[2]='val=0.0';
   params[3]='orderId=<?php echo $orderId_var;?>';
   params[4]='promoCode=';
   params[5]='valueCurrency=USD';
   k_trackevent(params,'105');
</script>

<?php if(arg(0) == 'contact-sales'){?>
<!-- Do Not Remove - Turn Tracking Beacon Code - Do Not Remove -->
<!-- Advertiser Name : Turn Corporate Advertising -->
<!-- Beacon Name : Contact Sales Form Complete -->
<!-- If Beacon is placed on a Transaction or Lead Generation based page, please populate the turn_client_track_id with your order/confirmation ID -->
<script type="text/javascript">
  turn_client_track_id = "";
</script>
<script type="text/javascript" src="http://r.turn.com/server/beacon_call.js?b2=H3JG7xu9Q08ZIyoQcf5Fzc0NCq72PqhSOGaz5rb8kCMFAw6xuleMrUF6oMH_cc9nmNPG2EID6siy90ubjD4yqw">
</script>
<noscript>
  <img border="0" src="http://r.turn.com/r/beacon?b2=H3JG7xu9Q08ZIyoQcf5Fzc0NCq72PqhSOGaz5rb8kCMFAw6xuleMrUF6oMH_cc9nmNPG2EID6siy90ubjD4yqw&cid=">
</noscript>
<!-- End Turn Tracking Beacon Code Do Not Remove -->
<img border="0" src="http://r.turn.com/r/beacon?b2=H3JG7xu9Q08ZIyoQcf5Fzc0NCq72PqhSOGaz5rb8kCMFAw6xuleMrUF6oMH_cc9nmNPG2EID6siy90ubjD4yqw&cid=">
<!--
Start of DoubleClick Floodlight Tag: Please do not remove
Activity name of this tag: Contact Sales form complete
URL of the webpage where the tag is expected to be placed: http://www.turn.com/contact-sales
This tag must be placed between the <body> and </body> tags, as close as possible to the opening tag.
Creation Date: 01/25/2013
-->
<script type="text/javascript">
var axel = Math.random() + "";
var a = axel * 10000000000000;
document.write('<iframe src="http://3718076.fls.doubleclick.net/activityi;src=3718076;type=turn2744;cat=conta835;ord=' + a + '?" width="1" height="1" frameborder="0" style="display:none"></iframe>');
</script>
<noscript>
<iframe src="http://3718076.fls.doubleclick.net/activityi;src=3718076;type=turn2744;cat=conta835;ord=1?" width="1" height="1" frameborder="0" style="display:none"></iframe>
</noscript>

<!-- End of DoubleClick Floodlight Tag: Please do not remove -->
<?php }?>

<noscript>
   <img src="https://105.xg4ken.com/media/redir.php?track=1&token=ed4a2658-4a57-44c8-9309-3127d56bfb1a&type=<?php echo urlencode($type_var);?>&val=0.0&orderId=<?php echo urlencode($orderId_var);?>&promoCode=&valueCurrency=USD" width="1" height="1">
</noscript>