<?php
/**
 * @file
 * product_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function product_page_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attribution|field_collection_item|field_testimonial|form';
  $field_group->group_name = 'group_attribution';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_testimonial';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attribution',
    'weight' => '8',
    'children' => array(
      0 => 'field_attribution_name',
      1 => 'field_attribution_title',
      2 => 'field_attribution_company',
      3 => 'field_attribution_logo',
      4 => 'field_company_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-attribution field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_attribution|field_collection_item|field_testimonial|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_differentiator|field_collection_item|field_proof_points|default';
  $field_group->group_name = 'group_differentiator';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_proof_points';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'differentiator',
    'weight' => '1',
    'children' => array(
      0 => 'field_differentiator_text',
      1 => 'field_differentiator_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'differentiator',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-differentiator field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_differentiator|field_collection_item|field_proof_points|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_differentiator|field_collection_item|field_proof_points|form';
  $field_group->group_name = 'group_differentiator';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_proof_points';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Differentiator',
    'weight' => '3',
    'children' => array(
      0 => 'field_differentiator_text',
      1 => 'field_differentiator_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-differentiator field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_differentiator|field_collection_item|field_proof_points|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link|field_collection_item|field_proof_points|form';
  $field_group->group_name = 'group_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_proof_points';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '4',
    'children' => array(
      0 => 'field_point_link',
      1 => 'field_link_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-link field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_link|field_collection_item|field_proof_points|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|field_collection_item|field_pane|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_pane';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '3',
    'children' => array(
      0 => 'field_media_video',
      1 => 'field_pane_media_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_media|field_collection_item|field_pane|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_panemedia|field_collection_item|field_pane|default';
  $field_group->group_name = 'group_panemedia';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_pane';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pane Media',
    'weight' => '2',
    'children' => array(
      0 => 'field_media_video',
      1 => 'field_pane_media_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pane Media',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-panemedia field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_panemedia|field_collection_item|field_pane|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_panetext|field_collection_item|field_pane|default';
  $field_group->group_name = 'group_panetext';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_pane';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pane Text',
    'weight' => '3',
    'children' => array(
      0 => 'field_big_idea',
      1 => 'field_buttons',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pane Text',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-panetext field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_panetext|field_collection_item|field_pane|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_proofheader|field_collection_item|field_proof_points|default';
  $field_group->group_name = 'group_proofheader';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_proof_points';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'proof header',
    'weight' => '0',
    'children' => array(
      0 => 'field_point_headline',
      1 => 'field_point_link',
      2 => 'field_link_type',
      3 => 'field_for_instance',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'proof header',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-proofheader field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_proofheader|field_collection_item|field_proof_points|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_resources|field_collection_item|field_product_section|form';
  $field_group->group_name = 'group_related_resources';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_product_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Resources',
    'weight' => '8',
    'children' => array(
      0 => 'field_video_resources',
      1 => 'field_pdf_resources',
      2 => 'field_blog_posts',
      3 => 'field_ebooks',
      4 => 'field_press_articles',
      5 => 'field_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-resources field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_related_resources|field_collection_item|field_product_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_testimonial_media|field_collection_item|field_testimonial|default';
  $field_group->group_name = 'group_testimonial_media';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_testimonial';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Testimonial Media',
    'weight' => '1',
    'children' => array(
      0 => 'field_testimonial_video',
      1 => 'field_testimonial_text',
      2 => 'field_attribution_logo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Testimonial Media',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-testimonial-media field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_testimonial_media|field_collection_item|field_testimonial|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_testimonial_text|field_collection_item|field_testimonial|default';
  $field_group->group_name = 'group_testimonial_text';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_testimonial';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Testimonial Text',
    'weight' => '2',
    'children' => array(
      0 => 'field_quote',
      1 => 'field_attribution_name',
      2 => 'field_attribution_title',
      3 => 'field_company_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Testimonial Text',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-testimonial-text field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_testimonial_text|field_collection_item|field_testimonial|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_text|field_collection_item|field_testimonial|form';
  $field_group->group_name = 'group_video_text';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_testimonial';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video or Text',
    'weight' => '2',
    'children' => array(
      0 => 'field_testimonial_video',
      1 => 'field_testimonial_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video-text field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_video_text|field_collection_item|field_testimonial|form'] = $field_group;

  return $export;
}
