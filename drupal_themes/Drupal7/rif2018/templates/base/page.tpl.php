<?php

/**
 * @file
 * Bartik's theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['featured']: Items for the featured region.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['triptych_first']: Items for the first triptych.
 * - $page['triptych_middle']: Items for the middle triptych.
 * - $page['triptych_last']: Items for the last triptych.
 * - $page['footer_firstcolumn']: Items for the first footer column.
 * - $page['footer_secondcolumn']: Items for the second footer column.
 * - $page['footer_thirdcolumn']: Items for the third footer column.
 * - $page['footer_fourthcolumn']: Items for the fourth footer column.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 * @see html.tpl.php
 */

?>

<?php print render($page['navigation']); ?>

<?php print render($page['header']); ?>

<div id="main-wrapper" data-current-uid="<?php print $user->uid; ?>">
  <div id="main">
    <?php if ($page['featured']) : ?>
      <div class="featured-wrapper">
        <div id="featured" class="container">
          <div class="row">
            <div class="col-xs-12">
              <div class="section">
                <?php print render($page['featured']); ?>
              </div>
            </div>
          </div> <!-- /.section, /#featured -->
        </div>
      </div>
    <?php endif; ?>

    <?php if ($page['sidebar_first'] || $page['highlighted'] || $page['sidebar_second']) : ?>
      <div class="admin-container">
        <div class="container">
          <div class="row">
            <?php if ($page['sidebar_first']) : ?>
              <div class="col-xs-12 col-sm-3">
                <div id="sidebar-first" class="column sidebar">
                  <div class="section">
                    <?php print render($page['sidebar_first']); ?>
                  </div>
                </div> <!-- /.section, /#sidebar-first -->
              </div>
            <?php endif; ?>
            <div class="col-xs-12 <?= ($page['sidebar_first'] xor $page['sidebar_second']) ? "col-sm-9" : "col-sm-6"; ?>">
              <?php if ($page['highlighted']) : ?>
                <div id="highlighted"><?php print render($page['highlighted']); ?></div>
              <?php endif; ?>
            </div>
            <?php if ($page['sidebar_second']) : ?>
              <div class="col-xs-12 col-sm-3">
                <div id="sidebar-second" class="column sidebar">
                  <div class="section">
                    <?php print render($page['sidebar_second']); ?>
                  </div>
                </div> <!-- /.section, /#sidebar-second -->
              </div>
            <?php endif; ?>
          </div> <!-- /.row -->
        </div> <!-- /.container -->
      </div>
    <?php endif; ?>

    <div id="content" class="column">
      <div class="section">
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php print render($title_suffix); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links) : ?>
          <ul class="action-links">
            <?php print render($action_links); ?>
          </ul>
        <?php endif; ?>
        <?php print $feed_icons; ?>
        <?php print render($page['content']); ?>

      </div>
    </div> <!-- /.section, /#content -->

    <?php if ($tabs) : ?>
			<div class="container">
				<div class="tabs">
					<?php print render($tabs); ?>
				</div>
			</div>
    <?php endif; ?>
    <?php if ($messages || $auto_popup_message/*&& !isset($node)*/ ) : ?>
      <script type="text/javascript">
        jQuery(window).on('load',function(){
          jQuery('#modal-messages').modal('show');
        });
      </script>
      <div class="modal fade" tabindex="-1" role="dialog" id="modal-messages">
        <div class="modal-dialog modal-lg" role="document">
          <div class="modal-content">
            <div class="modal-header">
              <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
              <h4 class="modal-title">
                <img src="/sites/all/themes/custom/rif2018/build/img/logo-rif.png" />
              </h4>
            </div>
            <?php if ($auto_popup_message) { ?>
              <div class="modal-body">
                <?php if ($messages) { ?>
                  <?php print $messages; ?>
                <?php
      } ?>
                <?php print $auto_popup_message; ?>
              </div>
              <div class="modal-footer">
                <?php print $auto_popup_message_footer; ?>
              </div>
            <?php
    } elseif ($messages) { ?>
              <div class="modal-body">
                <?php print $messages; ?>
              </div>
            <?php
    } ?>
          </div><!-- /.modal-content -->
        </div><!-- /.modal-dialog -->
      </div><!-- /.modal -->
      <!--<div id="messages" class="container">
        <div class="section clearfix">
          <?php /*print $messages; */ ?>
        </div>
      </div> <!-- /.section, /#messages -->
    <?php endif; ?>

  </div>
</div> <!-- /#main, /#main-wrapper -->

<?php if ($page['triptych_first'] || $page['triptych_middle'] || $page['triptych_last']) : ?>
  <div id="triptych-wrapper">
    <div id="triptych">
      <div class="container">
        <div class="row">
          <div class="col-xs-12 col-sm-4">
            <?php print render($page['triptych_first']); ?>
          </div>
          <div class="col-xs-12 col-sm-4">
            <?php print render($page['triptych_middle']); ?>
          </div>
          <div class="col-xs-12 col-sm-4">
            <?php print render($page['triptych_last']); ?>
          </div>
        </div>
      </div>
    </div>
  </div> <!-- /#triptych, /#triptych-wrapper -->
<?php endif; ?>

<?php if ($page['sponsorship']) : ?>
  <div class="sponsorship--site-wide">
    <div class="section">
      <div class="container">
        <div class="row">
          <?php print render($page['sponsorship']); ?>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if ($footer_donation) : ?>
  <?php print render($footer_donation); ?>
<?php endif; ?>

<div class="footer">
  <div class="section">
    <div class="container">
      <?php if ($page['footer_firstcolumn'] || $page['footer_secondcolumn'] || $page['footer_thirdcolumn'] || $page['footer_fourthcolumn']) : ?>
        <div class="row">
          <div class="col-xs-12 col-sm-6 col-md-2 ">
            <?php print render($page['footer_firstcolumn']); ?>
          </div>
          <div class="col-xs-12 col-sm-6 col-md-3 ">
            <?php print render($page['footer_secondcolumn']); ?>
          </div>
          <div class="col-xs-12 col-sm-6 col-md-3 ">
            <?php print render($page['footer_thirdcolumn']); ?>
          </div>
          <div class="col-xs-12 col-sm-6 col-md-4 ">
            <?php print render($page['footer_fourthcolumn']); ?>
          </div>
        </div>
      <?php endif; ?>
    </div>
    <?php if ($page['footer']) : ?>
      <?php print render($page['footer']); ?>
    <?php endif; ?>
  </div>
</div> <!-- /.container /.section, /.footer -->
<?php if ($page['sub_footer']) : ?>
  <?php print render($page['sub_footer']); ?>
<?php endif; ?>
