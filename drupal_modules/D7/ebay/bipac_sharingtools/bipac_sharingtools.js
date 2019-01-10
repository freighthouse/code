jQuery(document).ready(function(){
  var app_id = Drupal.settings.bipac_sharingtools.bipac_sharingtools_fb_app_id;
  if (app_id) {
    FB.init({appId: app_id, status: true, cookie: true});
  }
});
