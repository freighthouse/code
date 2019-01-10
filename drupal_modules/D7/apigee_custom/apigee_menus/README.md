#Apigee Menu Module

This module allows you to share menus across multiple sites in a multi-site. The shared defaults are in this module's config folder and should be changed via git checkins and tightly version managed. To export a menu system choose Strucutre => Apigee Menus. Choose a menu system to export and click "submit".

Once submitted, the YAML file will be exported to the private:// filesystem and then downloaded to your computer. After export, the exported menu system will show up as overridden. Feel free to delete or allow it to be overridden. Because the private:// filesystem is private to every site in the multi-site overriden menus are private to the specific overriding site.

Once removed from being overridden, The value returns to the default values as detailed in this module's "config" folder.

To use this system in the theme, find the following code:


<code>
if (module_exists("apigee_menus")) {
  module_load_include("module", "apigee_menus");
  $variables['main_menu'] = apigee_menus_load(<menu_machine_name>));
} else {
  // Build links the "deep" way
  $main_menu_tree = menu_tree(<menu_machine_name>);
  $main_menu_tree['#attributes']['class'][] = 'nav';
  $main_menu_tree['#attributes']['id'][] = 'main-menu';
  $main_menu_tree['#theme_wrappers'][0] = 'menu_tree_top_main';
  $variables['main_menu'] = $main_menu_tree;
}
</code>

This code will use the apigee_menus system and fallback on the default drupal menu system.