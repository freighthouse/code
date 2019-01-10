<?php global $base_url;?>
<?php foreach ($items as $delta => $item): ?>
  <?php if (isset($item['entity'])): //because this stupid tpl will carry on down through all the child fields otherwise ?>
    <?php foreach ($item['entity']['field_collection_item'] as $key => $value): ?>
      <?php
        $rownum = $delta + 1;
        if ($rownum % 2 == 0) {
          $row_type = 'even';
        }
        else {
          $row_type = 'odd';
        }

        // Get the title
        if (isset($value['field_title_2']['#items'][0]['safe_value'])) {
          $take_action_title = $value['field_title_2']['#items'][0]['safe_value'];
        }
        else {
          $take_action_title = "";
        }
        //Get the Twitter Text 

        if (isset($value['field_twitter_text']['#items'][0]['safe_value'])) {
          $take_twitter_text = $value['field_twitter_text']['#items'][0]['safe_value'];
        }
        else {
          $take_twitter_text = "";
        }

        // Get the icon
        if (isset($value['field_body_2']['#items'][0]['value'])) {
          $take_action_icon = $value['field_body_2']['#items'][0]['value'];
        }
        else {
          $take_action_icon = "";
        }
          $href= "https://twitter.com/intent/tweet?text=".$take_twitter_text."&url=".$base_url."/fr/ebaysengage/nos-propositions";
      ?>
        <div class="content">
              <h3><a class="social-media-twitter" href="<?php print $href;?>" target="_blank"></a><?php print $take_action_title ?></h3>
              <?php print $take_action_icon; ?>
        </div>

    <?php endforeach; ?>
  <?php endif; ?>
<?php endforeach; ?>