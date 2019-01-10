jQuery(document).ready(function($) {
  var current_region = $.cookie('ebay_region');

  if ($('body').hasClass('region-splash')) {
    var link = '<a onclick="region_filter(\'global\'); return false;" href="#" class="region-global">Visit Main Street Global</a>';
    $('#region-selection').after(link);
  }

  $.each($('#edit-ebay-regionality-regions option'), function() {
    if ($(this).val() == current_region) {
      $(this).attr('selected', 'selected');
    }
  });

  $('#edit-ebay-regionality-regions').change(function() {
    var selected_region = $(this).val();
    $.cookie('ebay_region', selected_region, {path: "/", domain: document.location.hostname});
    var region_href = region_filter(selected_region);
    window.location.href = region_href;
  });
  //for home page click based selection
  $('#region-select, #global-select').find('a').click(function(event){
    event.preventDefault;
    var selected_region = $(this).attr('href');
    $.cookie('ebay_region', selected_region, {path: "/", domain: document.location.hostname});
    var region_href = region_filter(selected_region);
    window.location.href = region_href;
    return false;
  })
});

function region_filter(region) {
  var path_array = window.location.pathname.split( '/' );
  var directories = path_array.length;
	var base = path_array[1];
  var newURL = false;

  if (region == 'global') { // "global" is a special case. If that region is selected then pages with no region are used
    switch (base) {
      case 'news':
      case 'issues':
      case 'team':
      case 'about':
				newURL = '/' + base;
				break;

      default:
				newURL = '/node';
    }
  }
  else {
    if (directories <= 1) { // Paths with only one level
      switch (base) {
				case 'news':
				case 'issues':
				case 'team':
				  // second level pages that are really views with a region filter... so add it
				  newURL = '/' + base + '/' + region;
				  break;

      	case 'about':
				  newURL = '/' + base + '/region/' + region;
				  break;

				default:
				  // second level pages that have no need for a region filter...so add the filter to the homepage
      	  newURL = '/region/' + region;
      }
    }
    else if (directories >= 2) { // Paths with two or more levels
     // third level pages and beyond are assumed to be nodes and not views,
     // so we will either travel to a second level section filtered by region,
     switch (base) {
       case 'news':
       case 'issues':
       case 'team':
         newURL = '/' + base + '/' + region;
				 break;

       case 'about':
				 newURL = '/' + base + '/region/' + region;
         break;

       default: // or the homepage filtered by region
				 newURL = '/region/' + region;
      }
    }
  }
  return newURL;
}