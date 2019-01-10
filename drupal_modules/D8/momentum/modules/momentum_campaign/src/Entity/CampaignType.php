<?php

namespace Drupal\momentum_campaign\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBundleBase;

/**
 * Defines the Campaign type entity.
 *
 * @ConfigEntityType(
 *   id = "campaign_type",
 *   label = @Translation("Campaign type"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\momentum_campaign\CampaignTypeListBuilder",
 *     "form" = {
 *       "add" = "Drupal\momentum_campaign\Form\CampaignTypeForm",
 *       "edit" = "Drupal\momentum_campaign\Form\CampaignTypeForm",
 *       "delete" = "Drupal\momentum_campaign\Form\CampaignTypeDeleteForm"
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\momentum_campaign\CampaignTypeHtmlRouteProvider",
 *     },
 *   },
 *   config_prefix = "campaign_type",
 *   admin_permission = "administer site configuration",
 *   bundle_of = "campaign",
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid"
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/campaign_type/{campaign_type}",
 *     "add-form" = "/admin/structure/campaign_type/add",
 *     "edit-form" = "/admin/structure/campaign_type/{campaign_type}/edit",
 *     "delete-form" = "/admin/structure/campaign_type/{campaign_type}/delete",
 *     "collection" = "/admin/structure/campaign_type"
 *   }
 * )
 */
class CampaignType extends ConfigEntityBundleBase implements CampaignTypeInterface {

  /**
   * The Campaign type ID.
   *
   * @var string
   */
  protected $id;

  /**
   * The Campaign type label.
   *
   * @var string
   */
  protected $label;

}
