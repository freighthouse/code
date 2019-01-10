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
 *
 */
?>
<div class="tweets-pulled-listing">

  <?php if (is_array($tweets)): ?>
    <?php $tweet_count = count($tweets); ?>


    <?php foreach ($tweets as $tweet_key => $tweet): ?>

	<?php if ($tweet_key == 0) : ?>
	<img src="<?php print $tweet->userphoto; ?>" alt="<?php print $tweet->username; ?>" class="tweet-authorphoto" />
    <div class="tweet-author">
	  <?php print l($tweet->proper_name, 'http://twitter.com/' . $tweet->username, array('attributes' => array('class' => 'tweet-author-propername'))); ?>
	  <?php print l('@' . $tweet->handle, 'http://twitter.com/' . $tweet->username, array('attributes' => array('class' => 'tweet-author-handle'))); ?>
	 </div>
	<ul class="tweets-list">
	<?php endif; ?>
	<?php foreach ($tweet->text as $timestamp => $value): ?>
    <li class="tweet <?php if($tweet_key == $tweet_count - 1){ print "last"; }; ?>">
      <p class="tweet-text">
        <?php print twitter_pull_oauth_add_links($value['text']); ?>
      </p>
      <p class="tweet-time">
        <?php $date = date('g:ia | j M y', $timestamp);
		print l($date, 'http://twitter.com/' . $tweet->username . '/status/' . $tweet->id);?>  </p>
  		<div class="tweets-pulled-actions">
    		<ul class="tweet-actions">
      		<li>
            <?php print l('Reply', 'https://twitter.com/intent/tweet?in_reply_to=' . $value['id'], array('attributes' => array('class' => 'tweet-reply')));?>
          </li>
      		<li>
            <?php print l('Retweet', 'https://twitter.com/intent/retweet?tweet_id=' . $value['id'], array('attributes' => array('class' => 'tweet-retweet')));?>
          </li>
      		<li>
            <?php print l('Favorite', 'https://twitter.com/intent/favorite?tweet_id=' . $value['id'], array('attributes' => array('class' => 'tweet-favorite')));?>
          </li>
    		</ul>
        <?php  if (isset($value['retweets']) && ($value['retweets'] > 0)): ?>
          <p class="retweets">
            <?php print $value['retweets']; ?>
            <?php if ($value['retweets'] == 1) print t('Retweet'); else print t('Retweets'); ?>
          </p>
        <?php endif; ?>
  		</div>
      </li>
	  <?php endforeach; ?>
    <?php endforeach; ?>
    </ul>
    <p class="tweets-follow"><?php print l('Follow Us', 'http://twitter.com/' . $tweet->username, array('attributes' => array('class' => 'tweets-follow-link'))); ?></p>
  <?php endif; ?>
</div>
