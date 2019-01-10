<?php

/**
 * @file
 * rif_sponsorship.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function rif_sponsorship_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_sponsor:node/add/sponsor.
  $menu_links['navigation_sponsor:node/add/sponsor'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/sponsor',
    'router_path' => 'node/add/sponsor',
    'link_title' => 'Sponsor',
    'options' => array(
      'attributes' => array(
        'title' => 'Sponsor logo',
      ),
      'identifier' => 'navigation_sponsor:node/add/sponsor',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_sponsorship-footer:block/add/sponsorship-footer.
  $menu_links['navigation_sponsorship-footer:block/add/sponsorship-footer'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'block/add/sponsorship-footer',
    'router_path' => 'block/add/sponsorship-footer',
    'link_title' => 'Sponsorship Footer',
    'options' => array(
      'identifier' => 'navigation_sponsorship-footer:block/add/sponsorship-footer',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-block:block/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Sponsor');
  t('Sponsorship Footer');

  return $menu_links;
}
