/**
 * Create namespace for api doc methods.
 */
(function ($, Drupal, window, document, undefined) {

	/** Initialize functions on page load. */
	$(function() {
		// Using Handlebars for templating. Data can come from an external file,
		// service, or for testing just from here.

	    $("#navigator-sidebar a, .documentation-links a.api-link, #breadcrumb a").live("click", function(e) {
	        var _href = $(this).attr("href");
	        loadContent(_href);

	        history.pushState('', '', _href);
	        e.preventDefault();
	    });

	    //This makes BACK/FORWARD buttons work
	    window.onpopstate = function (event) {
	    	loadContent(location.pathname);
	    }

	    //sets up sidebar
		$(document).ready(function() {
			$('#navigator-sidebar').find(".service-item").addClass('toggle-close');
			$('a[href="'+location.pathname+'"]').parent("li").addClass('active');
			$('a[href="'+location.pathname+'"]').parents(".service-item").removeClass("toggle-close").addClass('active-trail').find(".collapse-icon").text("▼");
			initData();
		});

		//loads content based on the url either the browser's url or the href attached to the clicked element
        function loadContent(url){
        	$dpg = $('.content-link.node').attr('id').replace('-', '/');
        	$('#operation-documentation').empty().append('<div id="breadcrumb"></div><div class="loading"/>');
        	//Documentation
        	//get's aliased url
        	if(url.indexOf($('.content-link.node').attr('about')) != -1) {
        		$link = url.substring($('.content-link.node').attr('about').length);
        	}
        	//get's system path url
        	else {
				$link = url.substring($('.content-link.node').attr('id').length + 1); //8
        	}
        	$.ajax({
        		url: "/sites/all/themes/callfire/php/api-request.php",
        		data: {contentlink: $link, dpg: $dpg},
        		success:function(data) {
       				var $template = $('#operation-documentation').empty().append(data);
					initData();
				},
				error: function(jqXHR, textStatus, errorThrown) {
					alert('textStatus: ' + textStatus + '\nerrorThrown: ' + errorThrown);
				}
	        });
			$('.service-item').removeClass('active-trail').addClass('toggle-close').find(".collapse-icon").text("►");
			$('li').removeClass('active');
			$('a[href="'+url+'"]').parent().addClass('active');
			$('a[href="'+url+'"]').parents(".service-item").removeClass("toggle-close").addClass('active-trail').find(".collapse-icon").text("▼");
		}

		$(".collapse-icon").live("click", function() {
			($(this).text()=="▼") ? $(this).text("►").parents(".service-item").addClass("toggle-close") : $(this).text("▼").parents(".service-item").removeClass("toggle-close");
		});


		$(".drilldown").live("click", function() {
			var $parent = $(this);
			var drilldown_parent_string = escapeStr($(this).attr('id'));
			if($parent.hasClass('tree-closed')) {
				$parent.removeClass('tree-closed').addClass('tree-open');
				$('.'+drilldown_parent_string).each(function() {
					$(this).removeClass('close');
				});
			}
			else {
				$parent.removeClass('tree-open').addClass('tree-closed');
				$('tr[class*="'+drilldown_parent_string+'"]').each(function() {
					if($(this).hasClass('tree-open')) {
						$(this).removeClass('tree-open').addClass('tree-closed');
					}
					$(this).addClass('close');
				});
			}
		});



	});
	
	function escapeStr( str) {
	 if(str)
	     return str.replace(/([ #;&,.+*~\':"!^$[\]()=>|\/@])/g,'\\$1');
	 else
	     return str;
	}

	function switchexamplecode(lang, current) {
		$children = $(current).parents(".code-example").find(".code-sample");
		$children.each(function(){
			if($(this).hasClass(lang.val)) {
				$(this).removeClass('close');
			}
			else
				$(this).addClass('close');
		});
	}

	//formats all code blocks, sets initial coded language, and sets tree-collapses
	function initData() {
		//RAINBOWS
		Rainbow.color();

		//tree-collapses
		$('table').each(function() {
			var hasdrilldown = false;
			$(this).find('.param-row').each(function() {
				$(this).addClass('close');
				if($(this).hasClass('drilldown')) {
					hasdrilldown = true;
					$(this).addClass('tree-closed');
				}
			});
			//if is a drilldown
			$(this).find('.level-0').each(function() {
				$(this).closest('.param-row').toggleClass('close');
				if(hasdrilldown) {	
					$(this).closest('.drilldown').addClass('tree-closed');
				}
			});
		});

		//set language
		$(".lang-select2").select2({
			width: "element",
			minimumResultsForSearch: 10,
		}).on('change', function(e){
			switchexamplecode(e,this);
		});
		$(".lang-select2").each(function(){
			value = $(this).val();
			$codeSample = $(this).parents(".code-example").find(".code-sample");
			$codeSample.each(function() {
				if($(this).hasClass(value)) {
					$(this).removeClass('close');
				}
				else {
					$(this).addClass('close');
				}
			})
		});

	}


})(jQuery, Drupal, this, this.document);
		
