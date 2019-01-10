<?php

/**
 * @file
 * Theme overrides.
 */

/**
 * Implements theme_preprocess_html().
 */
function rif2018_preprocess_html(&$variablies) {
  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  if (!$variablies['is_front']) {
    // Add unique class for each page.
    if (isset($_GET['q'])) {
      $path = drupal_get_path_alias($_GET['q']);
      // Add unique class for each website section.
      list($section,) = explode('/', $path, 2);
      if (arg(0) == 'node') {
        if (arg(1) == 'add') {
          $section = 'node-add';
        }
        elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
          $section = 'node-' . arg(2);
        }
      }

      global $base_path;
      list(,$path) = explode($base_path, $_SERVER['REQUEST_URI'], 2);
      list($path,) = explode('?', $path, 2);
      $path = rtrim($path, '/');
      // Construct the id name from the path, replacing slashes with dashes.
      $body_id = str_replace('/', '-', $path);
      // Construct the class name from the first part of the path only.
      // list($body_class,) = explode('/', $path, 2);
      // $body_class = $body_class . ' not-front';
      $body_id = 'page--' . $body_id;
      // $body_class = 'section-'. $body_class;
      // $vars['classes_array'][] = ' ' . $body_id; . ' ' . $body_class;

      if($section == "beeline" || $section == "nba") {
        $variablies['classes_array'][] = drupal_html_class('section-literacy-central');
      }

      $variablies['classes_array'][] = drupal_html_class($body_id);
      $variablies['classes_array'][] = drupal_html_class('section-' . $section);
    }
  }
}

/**
 * Implements theme_preprocess_page().
 */
function rif2018_preprocess_page(&$variables) {
  if ($donate_id = variable_get('rif_donate_footer_feature', FALSE)) {
    $entity_type = 'landing_page_component';
    $donate_entity = entity_load_single($entity_type, $donate_id);
    $donate_view = entity_view(
      $entity_type,
      array($donate_entity),
      'teaser'
    );
    $variables['footer_donation'] = $donate_view[$entity_type][$donate_id];
  }
}

/**
 * Implements theme_preprocess_entity().
 */
function rif2018_preprocess_entity(&$variables) {
  // Add a template suggestion for our donation entity.
  $entity = $variables[$variables['entity_type']];

  if (isset($entity->id) && $entity->id == variable_get('rif_donate_footer_feature', FALSE)) {
    $variables['theme_hook_suggestions'][] = "{$variables['entity_type']}__donate";
  }

  // Add suggestions for our layout entities. Make sure they're setup to
  // optionally display a header if the fields exist.
  $layout_bundles = array(
    'layout_one_column',
    'layout_two_column',
    'layout_three_column',
  );
  if (
    $variables['entity_type'] == 'paragraphs_item' &&
    in_array($entity->bundle, $layout_bundles)
  ) {
    $variables['theme_hook_suggestions'][] = 'paragraphs_item__layout_header';
  }

  // If our paragraph item is a three col layout, for the body field, in the
  // second position.
  if (
    $variables['entity_type'] == 'paragraphs_item' &&
    $entity->bundle == 'layout_three_column' &&
    $entity->field_name == 'field_lp_body' &&
    $entity->delta() === 1
  ) {
    $wrapper = entity_metadata_wrapper($entity->hostEntityType(), $entity->hostEntity());
    $layout_wrapper = entity_metadata_wrapper('paragraphs_item', $wrapper->field_lp_body[0]->value()->item_id);

    if (
      $layout_wrapper->getBundle() == 'layout_top_of_page' &&
      $layout_wrapper->field_layout_top_component->value()->bundle == 'component_marquee'
    ) {
      $variables['theme_hook_suggestions'][] = 'paragraphs_item__3col_post_marquee';
    }
  }

  // Logic for three column feature template.
  if (
    isset($entity->bundle) &&
    $entity->bundle == 'component_feature' &&
    $variables['view_mode'] == 'clickable'
  ) {
    $wrapper = entity_metadata_wrapper('paragraphs_item', $entity->item_id);
    $feature = entity_metadata_wrapper('landing_page_component', $wrapper->field_feature_reference->value()->id);

    $variables['theme_hook_suggestions'][] = 'paragraphs_item__feature_clickable';
    $variables['feature_title'] = $feature->title->value();
    $variables['feature_description'] = $feature->field_feature_description->value();
    $variables['feature_image'] = file_create_url($feature->field_feature_image->value()['uri']);

    if ($feature->field_feature_url->value()) {
      $variables['feature_url'] = $feature->field_feature_url->value();
    }
  }

  if (
    $variables['entity_type'] == 'landing_page_component' &&
    $entity->type == 'feature_large'
  ) {
    $wrapper = entity_metadata_wrapper('landing_page_component', $entity);
    $styles = array();

    if ($wrapper->field_feature_bg_position->value()) {
      $variables['img_pos'] = $wrapper->field_feature_bg_position->value();
    }
    else {
      $variables['img_pos'] = 'left';
    }

    if ($wrapper->field_feature_background_color->value()['rgb']) {
      $color = $wrapper->field_feature_background_color->value()['rgb'];
      $variables['bg_color'] = $wrapper->field_feature_background_color->value()['rgb'];
      $styles[] = t('background-color: @color;', array(
        '@color' => $color,
      ));
    }

    if ($wrapper->field_feature_color->value()) {
      $variables['classes_array'][] = "feature-large--color-{$wrapper->field_feature_color->value()}";
    }

    $variables['attributes_array']['style'] = implode(' ', $styles);
  }

  if (
    $variables['entity_type'] == 'landing_page_component' &&
    $entity->type == 'video'
  ) {
    $wrapper = entity_metadata_wrapper('landing_page_component', $entity);

    if ($wrapper->field_video_color->value()) {
      $variables['classes_array'][] = "video--color-{$wrapper->field_video_color->value()}";
    }

    if ($wrapper->field_video_button_text->value()) {
      $variables['video_button_text'] = $wrapper->field_video_button_text->value();
    }

    if ($wrapper->field_video_modal_reference->value()) {
      $variables['modal_trigger_target'] = $wrapper->field_video_modal_reference->field_modal_trigger_target->value();
    }

    if ($wrapper->field_video_position->value()) {
      $variables['video_pos'] = $wrapper->field_video_position->value();
    }
    else {
      $variables['video_pos'] = 'left';
    }
  }
}

/**
 * Implements theme_preprocess_field().
 */
function rif2018_preprocess_field(&$variables) {
  $element = $variables['element'];
  $wrapper = entity_metadata_wrapper($element['#entity_type'], $element['#object']);

  switch ($element['#field_name']) {
    // Set some fields to render with no field markup.
    case 'field_marquee_reference':
    case 'field_feature_large_reference':
    case 'field_video_reference':
      $variables['theme_hook_suggestions'][] = 'field__raw';
      break;

    case 'field_layout_component':
      $variables['theme_hook_suggestions'][] = 'field__1col';
      break;

    case 'field_layout_2col_components':
      $variables['theme_hook_suggestions'][] = 'field__2col';
      break;

    case 'field_layout_3col_components':
      $variables['theme_hook_suggestions'][] = 'field__3col';
      break;

    case 'field_feature_url':
      foreach ($variables['items'] as &$item) {
        $item['#element']['attributes']['class'] = 'btn btn-yellow';
      }
      break;

    case 'field_feature_button_url':
      // Get the color field.
      $color = $wrapper->field_feature_color->value();
      foreach ($variables['items'] as &$item) {
        $item['#element']['attributes']['class'] = "btn btn-{$color}";
      }
      break;

    case 'field_video_button':
      // Get the color field.
      $color = $wrapper->field_video_color->value();
      foreach ($variables['items'] as &$item) {
        $item['#element']['attributes']['class'] = "btn btn-{$color}";
      }
      break;

    case 'field_marquee_url':
      // Get the color field.
      $color = $wrapper->field_marquee_color->value();
      foreach ($variables['items'] as &$item) {
        $item['#element']['attributes']['class'] = "btn btn-{$color}";
      }
      break;
  }
}

/**
 * Theme function overrides from main rif theme.
 */

function rif2018_menu_tree__menu_literacy_tools(&$variables) {
  return $variables['tree'];
}

function rif2018_menu_link__menu_literacy_tools(array $variables) {
  $element = $variables['element'];

  if (!empty($element['#below'])) {
    $element['#localized_options']['attributes']['class'] = 'dropdown-toggle';
    $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    $element['#localized_options']['attributes']['role'] = 'button';
    $element['#localized_options']['attributes']['aria-haspopup'] = 'true';
    $element['#localized_options']['attributes']['data-expanded'] = 'false';

    $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

    return '<li class="dropdown">' .
      l($element['#title'], $element['#href'], $element['#localized_options']) .
      $sub_menu
    . '</li>';
  }

  // Removed Attributes from this menu.
  return '<li>' . l($element['#title'], $element['#href'], $element['#localized_options']) . "</li>\n";
}

/* Book Resource */
function rif2018_preprocess_node__book_resource__header_display(&$vars)
{

  $node_wrapper = entity_metadata_wrapper('node', $vars['node']);

  $vars['field_image_uri'] = file_create_url('public://placeholder263by180.png');
  if (!empty($vars['field_book_cover_file_name'])) {
    $book_cover_filename = $node_wrapper->field_book_cover_file_name->value();
    $book_cover_uri = 'public://Book_Covers/' . $book_cover_filename;
    if (file_exists($book_cover_uri)) {
      $file_url = file_create_url($book_cover_uri);
      $vars['field_book_cover_file_name'] = $node_wrapper->field_book_cover_file_name->value();
      $vars['field_image_uri'] = $file_url;
    }
  }

  $vars['field_display_position'] = "right";
  // $vars['field_background_color'] = "#003e77";//"#075f99";
  $vars['field_background_color'] = "#002C76";//"#075f99";
  $vars['fade']['left'] = "
  background: -moz-linear-gradient(left, transparent 0%, " . $vars['field_background_color'] . " 60%, " . $vars['field_background_color'] . " 80%);
      background: -webkit-gradient(left top, right top, color-stop(0%, transparent), color-stop(60%, " . $vars['field_background_color'] . "), color-stop(80%, " . $vars['field_background_color'] . "));
      background: -webkit-linear-gradient(left, transparent 0%, " . $vars['field_background_color'] . " 60%, " . $vars['field_background_color'] . " 80%);
      background: linear-gradient(to right, transparent 0%, " . $vars['field_background_color'] . " 60%, " . $vars['field_background_color'] . " 80%);
      ";

  $vars['fade']['right'] = "
  background: -moz-linear-gradient(left, " . $vars['field_background_color'] . " 0%, " . $vars['field_background_color'] . " 40%, " . $vars['field_background_color'] . " 80%);
      background: -webkit-gradient(left top, right top, color-stop(0%, " . $vars['field_background_color'] . "), color-stop(40%, " . $vars['field_background_color'] . "), color-stop(80%, " . $vars['field_background_color'] . "));
      background: -webkit-linear-gradient(left, " . $vars['field_background_color'] . " 0%, " . $vars['field_background_color'] . " 40%, rgba(7, 95, 153, 0) 80%);
      background: linear-gradient(to right, " . $vars['field_background_color'] . " 0%, " . $vars['field_background_color'] . " 40%, rgba(7, 95, 153, 0) 80%);
      ";
  $vars['fade']['top'] = "
      background: -moz-linear-gradient(top, " . $vars['field_background_color'] . " 0%, " . $vars['field_background_color'] . " 25%, rgba(56, 56, 43, 0) 100%);
    background: -webkit-gradient(left top, left bottom, color-stop(0%, " . $vars['field_background_color'] . "), color-stop(25%, " . $vars['field_background_color'] . "), color-stop(100%, rgba(56, 56, 43, 0)));
    background: -webkit-linear-gradient(top, " . $vars['field_background_color'] . " 0%, " . $vars['field_background_color'] . " 25%, rgba(56, 56, 43, 0) 100%);
    background: linear-gradient(to bottom, " . $vars['field_background_color'] . " 0%, " . $vars['field_background_color'] . " 25%, rgba(56, 56, 43, 0) 100%);
      ";
}
