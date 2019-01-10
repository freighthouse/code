<?php

/**
 * @file
 * rif_sponsorship.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function rif_sponsorship_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'sponsorship_footer',
    'description' => NULL,
    'title' => 'Made Possible By',
    'type' => 'sponsorship_footer',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'sponsor-footer-ex',
    'view_mode' => 'default',
    'created' => 1542835218,
    'log' => '',
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => '16fafa93-3a78-4563-9367-842262f0dcba',
    'uuid' => '92ad1c6c-0594-470f-ad1a-2872fbc7dfd0',
    'field_sponsor' => array(
      'und' => array(
        0 => array(
          'target_id' => '2dc9f9c1-418a-42a7-8744-abc186df7aa3',
          'uuid' => '2dc9f9c1-418a-42a7-8744-abc186df7aa3',
        ),
        1 => array(
          'target_id' => '92646ce5-0ab2-4140-b593-c7b12978f2eb',
          'uuid' => '92646ce5-0ab2-4140-b593-c7b12978f2eb',
        ),
        2 => array(
          'target_id' => '2dc9f9c1-418a-42a7-8744-abc186df7aa3',
          'uuid' => '2dc9f9c1-418a-42a7-8744-abc186df7aa3',
        ),
        3 => array(
          'target_id' => '92646ce5-0ab2-4140-b593-c7b12978f2eb',
          'uuid' => '92646ce5-0ab2-4140-b593-c7b12978f2eb',
        ),
      ),
    ),
    'field_sponsors_description' => array(
      'und' => array(
        0 => array(
          'value' => 'Here is some text and stuff!',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(),
    'user_uuid' => '34b72a8d-90f0-45f8-aed6-e0a27007a76e',
  );
  return $beans;
}
