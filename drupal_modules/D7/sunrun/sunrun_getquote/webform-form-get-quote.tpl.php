<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 *
 * If a preview is enabled, these keys will be available on the preview page:
 * - $form['preview_message']: The preview message renderable.
 * - $form['preview']: A renderable representing the entire submission preview.
 */
?>

<?php
  // Print out the progress bar at the top of the page
  print drupal_render($form['progressbar']);

  // Print out the preview message if on the preview page.
  if (isset($form['preview_message'])) {
    print '<div class="messages warning">';
    print drupal_render($form['preview_message']);
    print '</div>';
  }
?>

<div id="hero-form-top">
  <h2><?php print t('Get your customized quote:'); ?></h2>
  <table id="form-quote" border="0" cellpadding="0" cellspacing="0">
    <tr>
      <td><table width="100%" border="0" cellpadding="0" cellspacing="0">
          <tr>
            <td class="td-label" align="left" valign="top"><label><?php print t('First name:'); ?></label></td>
            <td class="td-field" align="left" valign="top"><?php print drupal_render($form['submitted']['first_name']); ?></td>
          </tr>
          <tr><td colspan="2"><p class='form-error-message'></p></td></tr>
          <tr>
            <td><img class="spacer" src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
          </tr>
          <tr>
            <td class="td-label" align="left" valign="top"><label><?php print t('Last name:'); ?></label></td>
            <td class="td-field" align="left" valign="top"><?php print drupal_render($form['submitted']['last_name']); ?></td>
          </tr>
          <tr><td colspan="2"><p class='form-error-message'></p></td></tr>
          <tr>
            <td><img class="spacer" src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
          </tr>
          <tr>
            <td class="td-label" align="left" valign="top"><label><?php print t('Email:'); ?></label></td>
            <td class="td-field" align="left" valign="top"><?php print drupal_render($form['submitted']['email']); ?></td>
          </tr>
          <tr><td colspan="2"><p class='form-error-message'></p></td></tr>
          <tr>
            <td><img class="spacer" src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
          </tr>
          <tr>
            <td class="td-label" align="left" valign="top"><label><?php print t('Phone:'); ?></label></td>
            <td class="td-field" align="left" valign="top"><?php print drupal_render($form['submitted']['phone']); ?></td>
          </tr>
          <tr><td colspan="2"><p class='form-error-message'></p></td></tr>
          <tr>
            <td><img class="spacer" src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
          </tr>
          <tr>
            <td class="td-label" align="left" valign="top"><label><?php print t('ZIP code:'); ?></label></td>
            <td class="td-field" align="left" valign="top"><?php print drupal_render($form['submitted']['zip_code']); ?></td>
          </tr>
          <tr><td colspan="2"><p class='form-error-message'></p></td></tr>
          <tr>
            <td><img class="spacer" src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
          </tr>
          <tr>
            <td class="td-label" align="left" valign="top"><label><?php print t('Electric bill $:'); ?></label></td>
            <td class="td-field" align="left" valign="top"><?php print drupal_render($form['submitted']['electric_bill']); ?></td>
          </tr>
          <tr><td colspan="2"><p class='form-error-message'></p></td></tr>
          <tr>
            <td><img class="spacer-2" src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
          </tr>
        </table></td>
    </tr>
    <tr>
      <td><table width="100%" border="0" cellpadding="0" cellspacing="0">
          <tr>
            <td class="td-checkbox" colspan="4">
              <?php print drupal_render($form['submitted']['updates']); ?>
            </td>
          </tr>
          <tr>
            <td><img class="spacer-4" src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
            <td><img src="/<?php print drupal_get_path('theme', 'sunrun_form'); ?>/images/spacer.gif" width="1" height="1" alt="" border="0" style="display: block;"></td>
          </tr>
          <tr>
            <td class="td-checkbox" colspan="4">
              <?php print drupal_render($form['submitted']['referred']); ?>
            </td>
          </tr>
        </table></td>
    </tr>
  </table>
</div>
<div id="hero-form-bottom">
  <?php print drupal_render($form['actions']['submit']); ?>
</div>

<?php
  // Always print out the entire $form. This renders the remaining pieces of the
  // form that haven't yet been rendered above (buttons, hidden elements, etc).
  print drupal_render_children($form);

?>