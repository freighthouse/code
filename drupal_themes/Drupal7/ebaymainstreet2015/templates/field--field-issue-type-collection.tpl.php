<?php foreach ($items as $delta => $item): ?>
  <?php if (isset($item['entity'])): ?>
    <?php foreach ($item['entity']['field_collection_item'] as $key => $value): ?>
      <?php

        // Get data for row numbers
        $rownum = $delta + 1;
        if ($rownum % 2 == 0) {
          $row_type = 'even';
        }
        else {
          $row_type = 'odd';
        }

        // Get the currently selected display field type
        if(isset($value['field_content_field_type']['#items'][0]['value'])) {
          $current_field_type = $value['field_content_field_type']['#items'][0]['value'];
        }
        else {
          $current_field_type = '';
        }

        // Get the textarea content
        if($current_field_type == 'textarea' && isset($value['field_issue_textarea']['#items'][0]['safe_value'])) {
          $textarea_output = $value['field_issue_textarea']['#items'][0]['safe_value'];
        }

        // Get the video url
        if($current_field_type == 'video' && isset($value['field_issue_video']['#items'][0]['video_url'])) {
          $video_url = $value['field_issue_video']['#items'][0]['video_url'];
        }

        // Get the timeline node id
        if($current_field_type == 'timeline' && isset($value['field_issue_timeline']['#items'][0]['nid'])) {
          $timeline_nid = $value['field_issue_timeline']['#items'][0]['nid'];
        }
      ?>

      <div class="issue-page-field-types-wrapper">
        <?php if($current_field_type == 'timeline'): ?>
          <div class="issue-page-field-types-timeline">
            <?php $timeline_content = node_view(node_load($timeline_nid)); ?>
            <?php print drupal_render($timeline_content); ?>
          </div>
        <?php endif; ?>

        <?php if($current_field_type == 'textarea'): ?>
          <div class="issue-page-field-types-textarea">
            <?php print $textarea_output; ?>
          </div>
        <?php endif; ?>

        <?php if($current_field_type == 'video'): ?>
          <div class="issue-page-field-types-video">
            <div class="embedded-video">
              <div class="player">
                <?php
                $handler = video_embed_get_handler($video_url);
                if ($handler['title'] == 'Youtube') {
                  $video_result = video_embed_field_handle_youtube($video_url, array('rel' => '0'));
                  print $video_result['#markup'];
                }
                else {
                  $video_result = video_embed_field_handle_vimeo($video_url);
                  print $video_result['#markup'];
                }
                ?>
              </div>
            </div>
          </div>
        <?php endif; ?>
      </div>

    <?php endforeach; ?>
  <?php endif; ?>
<?php endforeach; ?>