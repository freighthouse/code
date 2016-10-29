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
 * @ingroup templates
 */
?>
<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="<?php print $container_class; ?>">
    <div class="navbar-header">
        <?php if ($logo) : ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
        <?php endif; ?>

        <?php if (!empty($site_name)) : ?>
        <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
        <?php endif; ?>
      <div id="iha_mobile_menu">
        <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])) : ?>
            <nav class="mobile">
                <?php print $mobile_menu; ?>
            </nav>
            <a id="nav-expander" class="nav-expander fixed">
              <i class="fa fa-bars fa-lg white"></i>
            </a>
        <?php endif; ?>
      </div>
    </div>
    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])) : ?>
      <div class="navbar-collapse collapse">
        <nav role="navigation">
            <?php if (!empty($primary_nav)) : ?>
            <?php print render($primary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($secondary_nav)) : ?>
            <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])) : ?>
            <?php print render($page['navigation']); ?>
            <?php endif; ?>
        </nav>
      </div>
    <?php endif; ?>
  <div class="iha_menus">
    <div class="meta_navigation">
      <span class="iha_user_menu">
        <?php $block = block_load('superfish', 3);
        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
        $output = drupal_render($render_array);
        print $output; ?>
        <span class="iha_search">
          <a data-toggle="modal" href="#iha_search_form" title="Search">
            <span class="icon glyphicon glyphicon-search" aria-hidden="true"></span>
          </a>
          <div class="modal fade" id="iha_search_form">
            <div class="modal-dialog modal-sm">
              <div class="modal-content">
                <!-- <div class="modal-header">
                  <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                </div> -->
                <div class="modal-body">
                    <?php print $search_box; ?>
                </div>
              </div>
            </div>
          </div>
        </span>
      </span>
    </div>
    <div class="main_navigation">
    </div>
  </div>
</header>

<div class="main-container <?php print $container_class; ?>">

  <div class="iha_header">
    <?php if (!empty($site_slogan)) : ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>
    <div class="row container">
      <div class="col-sm-12 page_header_top hide_on_mobile"></div>
      <div class="page_header_bottom">
          <span class="iha_title">
            <h1>Press Release</h1>
          </span>
          <span class="header_image">
            <?php print (!empty($fields['field_header_image'])) ?
              $fields['field_header_image']->content : ''; ?>
          </span>
      </div>
    </div>
  <!-- /#page-header -->
  </div>

  <!-- #page tabs -->
  <div class="container page_tabs node_tabs">
    <div class="col-sm-2 col-xs-12 news_button_div">
      <a class="btn btn-default register_button" href="news-events" type="button">All</a>
    </div>
    <div class="col-sm-2 col-xs-12 news_button_div">
      <a class="btn btn-default register_button" href="news-events/press-releases" type="button">Press Releases</a>
    </div>
    <div class="col-sm-2 col-xs-12 news_button_div">
      <a class="btn btn-default register_button" href="news-events/conferences" type="button">Conferences</a>
    </div>
    <div class="col-sm-2 col-xs-12 news_button_div">
      <a class="btn btn-default register_button" href="news-events/webinars" type="button">Webinars</a>
    </div>
    <div class="col-sm-2 col-xs-12 news_button_div">
      <a class="btn btn-default register_button" href="blog" type="button">Blog</a>
    </div>
    <div class="col-sm-2 col-xs-12 news_button_div">
      <a class="btn btn-default register_button" href="news-events/newsletters" type="button">Newsletters</a>
    </div>
  </div>
  <!-- /#page tabs -->
  <div class="row">
    <?php if (!empty($page['sidebar_first'])) : ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
        <?php if (!empty($page['highlighted'])) : ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>
        <?php if (!empty($breadcrumb)) : print $breadcrumb; 
        endif;?>
      <!-- <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if (!empty($title)) : ?>
        <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?> -->
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php if (!empty($tabs)) : ?>
        <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if (!empty($page['help'])) : ?>
        <?php print render($page['help']); ?>
        <?php endif; ?>
        <?php if (!empty($action_links)) : ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
      <div class="container">
        <?php print render($page['content']); ?>
        <div class="page_back">
          <p>&nbsp;</p>
            <button class="btn btn-default back_button" onclick="goBack()">Back to press releases</button>
            <script>function goBack() {window.history.back();}</script>
          <p>&nbsp;</p>
        </div>
      </div>
    </section>

    <?php if (!empty($page['sidebar_second'])) : ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>

<footer class="footer container" id="footer">
  <div class="col-sm-12 big_foot">
    <?php print render($page['footer']); ?>
    <div id="footer_about_menu" class="col-xs-12 col-sm-4">
        <?php
          $menu = menu_navigation_links('main-menu');
          print theme('links__main_menu', array('links' => $menu));
        ?>
    </div>
    <div class="col-xs-12 col-sm-4">
      <div class="contact_foot">
        <h5>Contact Us</h5>
        <p>Integrated Healthcare Association<br>500 12th Street, Suite 310 | Oakland, CA</p>
        <span id="iha_link">
          <a href="//www.iha.org">www.iha.org</a>
        </span>
        <span class="iha_social">
          <span>
            <a href="//linkedin.com/company/467230"><i class="fa fa-linkedin"></i></a>
          </span>
          <span>
            <a href="//facebook.com/IHAConvene"><i class="fa fa-facebook"></i></a>
          </span>
          <span>
            <a href="//twitter.com/ihaconvene"><i class="fa fa-twitter"></i></a>
          </span>
        </span>
      </div>
    </div>
    <div class="col-xs-12 col-sm-4 news_pre">
      <div class="news_foot">
      <h5>Sign up for our newsletter</h5>
        <?php
        $block = block_load('constant_contact', 1);
        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
        $output = drupal_render($render_array);
        print $output; ?>
      </div>
    </div>
  </div>
  <div class="col-sm-12 sub_foot">
    <div class="col-md-6 copy_legal">
      <span class="copyright">
        <p>&copy; <?php echo date('Y'); ?> IHA. All rights reserved.</p>
      </span>
      <span class="legal_menu">
        <a href="terms-of-use">Terms of Use</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href="privacy-policy">Privacy Policy</a>
      </span>
    </div>
<!--       <div class="col-md-6">
    </div> -->
  </div>
</footer>