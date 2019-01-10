<?php /**
 * @file
 * Contains \Drupal\momentum\EventSubscriber\InitSubscriber.
 */

namespace Drupal\momentum\EventSubscriber;

use Symfony\Component\HttpKernel\KernelEvents;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;

abstract class InitSubscriber implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   */
//  public static function getSubscribedEvents() {
//    return [KernelEvents::REQUEST => ['onEvent', 0]];
//  }

  // OLD DEPRECATED FUNCTION FROM V7
//  public function onEvent() {
//    drupal_add_css(drupal_get_path('module', 'momentum') . '/css/momentum.css', [
//      'group' => CSS_DEFAULT,
//      'every_page' => TRUE,
//    ]);
//  }

  function momentum_element_info_alter(array &$types) {
    $types['table']['#attached']['library'][] = 'momentum/momentum-libs';
  }

}
