<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
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
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<header id="navbar" role="banner" class="navbar navbar-default navbar-static-top">
  <div class="topbar col-lg-12">
    <div class="container">
      <div class="topitems">
        <div class="toplinks">
            <?php $menu = menu_navigation_links('menu-top-bar-menu');
            print theme('links__menu_top_bar_menu', array('links' => $menu)); ?>
          <div class="apisearch">
            <?php print $search_box; ?>
          </div>
          <div class="apilang">
          </div>
        </div>
      </div>
        <?php if (!empty($page['header'])) : ?>
        <section class ="col-lg-12">
            <?php print render($page['header']); ?>
        </section>
        <?php endif; ?>
    </div>
  </div>
  <div class="container">
    <div class="navbar-header">
      <a class="logo" href="<?php print $front_page; ?>" title="<?php print t('Apigee.com'); ?>"></a>
        <?php if (!empty($primary_nav) || !empty($page['navigation'])) : ?>
          <div class="navbar-collapse collapse">
            <nav role="navigation">
                <?php $block = block_load('superfish', 1);
                    $output = render(_block_get_renderable_array(_block_render_blocks(array($block))));
                    print $output; ?>

                <?php if (!empty($page['navigation'])) : ?>
                <?php print render($page['navigation']); ?>
                <?php endif; ?>

                <?php if (!empty($secondary_nav) || !empty($page['navigation'])) : ?>
                <div class="navbar-collapse collapse">
                  <nav role="navigation">
                    <?php if (!empty($secondary_nav)) : ?>
                        <?php print render($secondary_nav); ?>
                    <?php endif; ?>
                  </nav>
                </div>
                <?php endif; ?>

            </nav>
          </div>
        <?php endif; ?>

      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>

    </div>
  </div>
</header>

<div class="apiheader">
    <?php if (!empty($page['apiheader'])) : ?>
      <section>
        <?php print render($page['apiheader']); ?>
      </section>
    <?php endif; ?>
</div>

<div class="banners">
    <div class="row">
      <div class="promo_left">
            <?php if (!empty($page['promo_left'])) : ?>
            <div class="col-md-6">
                <?php print render($page['promo_left']); ?>
            </div>
            <?php endif; ?>
      </div>
      <div class="promo_right">
            <?php if (!empty($page['promo_right'])) : ?>
            <div class="col-md-6">
                <?php print render($page['promo_right']); ?>
            </div>
            <?php endif; ?>
      </div>
    </div>
    <div class="row">
      <div class="promo">
            <?php if (!empty($page['promo'])) : ?>
            <div class="col-sm-12">
                <?php print render($page['promo']); ?>
            </div>
            <?php endif; ?>
      </div>
    </div>
</div>
<div><?php print $messages; ?></div>
<div class="main-container">
  <section>
    <div class="container">
      <div class="fp_products_overview">
            <?php
            $block = block_load('views', 'product_overview-front_page_products');
            echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
            ?>
      </div>
    </div>
  </section>
  <!-- <section>
    <div class="fp_cta2 field-name-field-cta-button text-center">
      <div class="row">
        <?php
          print render_block_content('block', 66);
        ?>
      </div>
    </div>
  </section> -->
  <section>
    <div class="row">
        <?php
          print render_block_content('block', 81);
        ?>
    </div>
    <div class="customer_overview">
      <!-- <div class="row"> -->
        <div class="customer_background">
          <div class="container customer_videos">
            <div class="customer_content">
              <div>
                <div class="customer_stories col-md-8">
                    <?php
                    $block = block_load('views', 'customers_video_slideshow-featured_video');
                    echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
                    ?>
                </div>
              </div>
              <div class="innovator_spotlights col-md-3">
                <?php
                  $block = block_load('views', 'customers_video_slideshow-front_page_videos');
                  echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
                ?>
              </div>
            </div>
          </div>
        </div>
      <!-- </div> -->
    </div>
  </section>
  <section>
    <div class="customers_block">
      <div class="container">
        <div>
            <?php
            $block = block_load('views', 'customers_front-block');
            echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
            ?>
        </div>
      </div>
    </div>
  </section>
  <section>
    <div class="row">
      <div class="sharing_block fp_sharing_block">
        <?php
          print render_block_content('block', 51);
        ?>
      </div>
    </div>
  </section>
  <section>
    <div class="fp_cta">
      <div class="row">
        <div class="container">
            <?php
            print render_block_content('block', 66);
            ?>
        </div>
      </div>
    </div>
  </section>
  <div class="ebooks_block">
    <section>
      <div class="row">
        <div class="container">
            <?php
            $block = block_load('views', 'ebooks_block-front_page_resources');
            echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
            ?>
        </div>
      </div>
    </section>
  </div>
  <div class="news_block"
    <section>
      <div class="row">
        <div class="container">
            <?php
            $block = block_load('views', 'apigee_in_the_news-front_page_news');
            echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
            ?>
        </div>
      </div>
    </section>
  </div>
  <section>
    <div class="row">
        <?php if (!empty($page['front_page_content'])) : ?>
        <div>
            <?php print render($page['front_page_content']); ?>
        </div>
        <?php endif; ?>
    </div>
  </section>
</div>

<footer class="footer fp_footer">
  <div class="container">
    <?php if (!empty($page['footer_left'])) : ?>
    <div class="footer-left col-sm-2">
        <?php print render($page['footer_left']); ?>
    </div>
    <?php endif; ?>
    <?php if (!empty($page['footer'])) : ?>
    <div class="footer-main col-sm-10">
        <?php print render($page['footer']); ?>
    </div>
    <?php endif; ?>
  </div>
  <div class="copyright">
    &copy; <?php echo date('Y'); ?> Apigee Corp. All rights reserved.
  </div>
</footer>