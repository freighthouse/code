<?php
// $Id: twitter-pull-listing.tpl.php,v 1.1.2.5 2011/01/11 02:49:38 inadarei Exp $

/**
 * @file
 * Theme template for a list of tweets.
 *
 * Available variables in the theme include:
 *
 * 1) An array of $tweets, where each tweet object has:
 *   $tweet->id
 *   $tweet->username
 *   $tweet->userphoto
 *   $tweet->text
 *   $tweet->timestamp
 *
 * 2) $twitkey string containing initial keyword.
 *
 * 3) $title
 */
?>
<div class="tweets-pulled-listing">

    <?php if (!empty($title)) : ?>
    <h2><?php print $title; ?></h2>
    <?php endif; ?>

    <?php if (is_array($tweets)) : ?>
    <?php $tweet_count = count($tweets); ?>
    
    <ul class="tweets-pulled-listing">
    <?php 
        //replace twitter img server with one that can use ssl
        //$pattern = '/http:\/\/([A-Z0-9][A-Z0-9_-]*\.twimg\.com/i';
        $pattern = '/http:\/\/([A-Z0-9][A-Z0-9_-])*\.twimg\.com/i';

    foreach ($tweets as $tweet_key => $tweet){
        $img=$tweet->userphoto;
        $img=preg_replace($pattern, "https://s3.amazonaws.com/twitter_production", $img);
        //$img=preg_replace($pattern,"https://",$img);
    ?>
     <li>
       <div class="tweet-authorphoto"><img src="<?php print $img; ?>" alt="<?php print $tweet->username; ?>" /></div>
       <span class="tweet-author"><a href="http://twitter.com/<?php print $tweet->username; ?>" target="_blank"><?php print $tweet->username; ?></a></span>
       <span class="tweet-text"><?php print twitter_pull_add_links($tweet->text); ?></span>
       <div class="tweet-time"><a href="http://twitter.com/<?php print $tweet->username.'/status/'.$tweet->id;?>" target="_blank"><?php print $tweet->time_ago;?></a></div>
        
        

        <?php if ($tweet_key < $tweet_count - 1) : ?>
          <div class="tweet-divider"></div>
        <?php endif; ?>
        
     </li>
    <?php } ?>
    </ul>
    <?php endif; ?>
</div>
