jQuery(document).ready(function(){
  var app_id = Drupal.settings.re_socialtools.re_socialtools_fb_app_id;
  if (app_id) {
    FB.init({appId: app_id, status: true, cookie: true});
  }
});
