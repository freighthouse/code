<?php

/**
 * @file
 * Contains \Drupal\momentum\Controller\MomentumController.
 */

namespace Drupal\momentum\Controller;

use Drupal\Core\Url;
use Drupal\Core\Link;

/**
 * Controller routines for page example routes.
 */
class MomentumController {
  /**
   * Constructs a page with descriptive content.
   *
   * Our router maps this method to the path 'examples/momentum'.
   */
  public function dashboard() {
    return ['#markup' => '<h2>' . t('Momentum') . '</h2>'];
  }



}
