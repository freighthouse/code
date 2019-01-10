/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
// useful function to quote strings for literal match in regular expressions

(function ($, Drupal, window, document, undefined) {


	$(document).ready(function() { 
		/** Slide Togges Blog's Archive
		 *
		 *
		 */

		// setup-active trail
		var parse_url = /^(?:([A-Za-z]+):)?(\/{0,3})([0-9.\-A-Za-z]+)(?::(\d+))?(?:\/([^?#]*))?(?:\?([^#]*))?(?:#(.*))?$/;
		var url = window.location;

		var result = parse_url.exec(url);
		var names = ['url', 'scheme', 'slash', 'host', 'port', 'path', 'query', 'hash'];

		$("#block-views-blog-archives-block a[href='/" + result[5] + "']").addClass("active");
		$(document).find("a.active").parents(".view-grouping").children("h3").children("a").addClass("active-trail");

		//initialize toggle

		$("#block-views-blog-archives-block ul").each(function(){
			if ($(this).siblings("h3").children("a").hasClass("active-trail") || $(this).siblings("h3").children("a").hasClass("active")) {
				$(this).siblings("h3").children(".collapse-icon").text("▼").addClass("toggle-open");
			}
			else $(this).hide();
		});
	  
		 // click event: toggle visibility of group clicked (and update icon)
		$("#block-views-blog-archives-block .collapse-icon").click(function()
		{
			var icon = $(this).parent("h3").children(".collapse-icon");
			$(this).parent("h3").siblings("ul").slideToggle(function()
			{
				(icon.text()=="▼") ? icon.text("►").addClass("toggle-open") : icon.text("▼").removeClass("toggle-open");
			});
		});

		/** Hides extra taxonomy terms and implements show more feature
		 *
		 *
		 */
		//initial display
		$("#block-views-tags-block-top-tags ul.views-summary > li").each(function(i){
			if(i>9) $(this).hide();
			else ( $(this).css("display", "list-item"))
		});

		//implement toggle

		$("a.see-more-tags").click(function()
		{
			if ($(this).hasClass("toggle-open")) {
				$("#block-views-tags-block-top-tags ul.views-summary > li").each(function(i) {
					if(i>9) 
					{
						$(this).hide();
					}
					else ( $(this).css("display", "list-item"))

				})
				$(this).text("more");
				$(this).removeClass("toggle-open");
			}
			else {
				$("#block-views-tags-block-top-tags ul.views-summary > li").each(function() {
					$(this).show();
				})
				$(this).addClass("toggle-open");
				$(this).text("hide");	
			}
		});

		//homepage js
		var heros = [
			{"hero_message":["Add Voice and SMS to your software application"],"hero_image":["homepage1.png"]},
			{"hero_message":["Power Dial through your cold call list"],"hero_image":["homepage2.png"]},
			{"hero_message":["Build a phone system using text-to-speech"],"hero_image":["homepage3.png"]},
			{"hero_message":["Track and record phone calls from your ads"],"hero_image":["homepage4.png"]},
			{"hero_message":["Send automated phone calls and text messages"],"hero_image":["homepage5.png"]}
		];

		heroNumber = 0;
		
		function rotateHeros() {
			$('#rotating-message').animate({
				'opacity': 0
			}, 1000);
			$('#rotating-image').animate({
				'opacity': 0
			}, 1000, function() {
				currentHero = heros[heroNumber];
				$('#rotating-image').attr('src', '/sites/default/files/images/home-page/'+currentHero.hero_image[0]);
				$('#rotating-message').text(currentHero.hero_message[0]);
				$('#rotating-image,#rotating-message').delay(300).animate({ 'opacity':1 }, 1000);
			});
			if (heroNumber >= (heros.length - 1)) {
				heroNumber = 0;
			} else {
				heroNumber = heroNumber+1;
			}
		}
		if ($('.front').length) { setInterval(rotateHeros, 5000); };

		//tour js
		if ($('#product-menu').length) {
			menuOffset = $('#product-menu').offset();
			$(window).scroll(function() {
				if ($(window).scrollTop() > menuOffset.top) {
					if ($.browser.msie==true && $.browser.version < 8)
						$('#product-menu').css({'margin': 0});
				$('#product-menu').css({
					'position': 'fixed',
					'top': 0
				});
				$('.intro').css({
					'margin-bottom': '80px'
				});
				} else {
					$('#product-menu').css({
						'position': 'static',
						'margin' : '0 -20px'
					});
					$('.intro').css({
						'margin-bottom': '30px'
					});
				}
			}); 
		}
		
		//pricing page js
		cccOverlay = $('.section-pricing #ccc-overlay').html();
	    $('.section-pricing #ccc-overlay').remove();

	    ivrOverlay = $('.section-pricing #ivr-overlay').html();
	    $('.section-pricing #ivr-overlay').remove();

	    numbersOverlay = $('.section-pricing #numbers-overlay').html();
	    $('.section-pricing #numbers-overlay').remove();

	    textOverlay = $('.section-pricing #text-messaging-overlay').html();
	    $('.section-pricing #text-messaging-overlay').remove();

	    vbOverlay = $('.section-pricing #voice-broadcast-overlay').html();
	    $('.section-pricing #voice-broadcast-overlay').remove();

	    function hideOverlay() {
	      $('.pricing-overlay').hide();
	      $('.pricing-overlay').removeClass('vb text numbers ivr ccc');
	    }

	    function teslaSignUp() {
	      $('.pricing-overlay .sign-up .button').attr('href', '/ui/register');
	    }

	    var params = QueryString();

		if (params['refcd'] !=null ) {
			writeCookie("refcd", params['refcd']);
		}

		if (params['tsacr'] !=null ) {
			writeCookie("tsacr", params['tsacr']);
		}

		function writeCookie(name,value) {
			if (value == null) {
				return;
			} 
			var expiryDate = new Date();
			// 1 year exipry is the max for most browsers
			expiryDate.setTime(expiryDate.getTime()+(364*24*60*60*1000));
			var cookievalue = escape(value);
			document.cookie= name + "=" + cookievalue + ";expires=" + expiryDate.toUTCString() + ";";
		}

		function readCookie(name) {
			var nameEQ = name + "=";
			var ca = document.cookie.split(';');
			for(var i=0;i < ca.length;i++) {
				var c = ca[i];
				while (c.charAt(0)==' ') c = c.substring(1,c.length);
				if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
			}
			return null;
		}

		function parseGoogleValues(utmz) {
			var pairs = utmz.split('.').slice(4).join('.').split('|');
			var ga = {};
			for (var i = 0; i < pairs.length; i++) {
				var temp = pairs[i].split('=');
				ga[temp[0]] = temp[1];
			}
			return ga;
		}



		var utmz = readCookie('__utmz');

		if (utmz !=null) {
			var google_vals = parseGoogleValues(utmz);

			var pageviews = readCookie('__utmb').split('.')[1];
			var visits = readCookie('__utma').split('.').pop()

			writeCookie('utmcmd', google_vals.utmcmd); // medium (organic, referral, direct, etc)
			writeCookie('utmcsr', google_vals.utmcsr); // source (google, facebook.com, etc)
			writeCookie('utmcct', google_vals.utmcct) // content (index.html, etc)
			writeCookie('urmccn', google_vals.utmccn); // campaign 
			writeCookie('utmctr', google_vals.utmctr); // term (search term)
			writeCookie('utmgclid', google_vals.utmgclid); //adwords-only
			writeCookie('visits', visits); // visits
			writeCookie('pageviews', pageviews) // pageviews

			if (+visits===1) {
				writeCookie('first_utmcmd', google_vals.utmcmd); // medium (organic, referral, direct, etc)
                		writeCookie('first_utmcsr', google_vals.utmcsr); // source (google, facebook.com, etc)
                		writeCookie('first_utmcct', google_vals.utmcct) // content (index.html, etc)
                		writeCookie('first_urmccn', google_vals.utmccn); // campaign 
                		writeCookie('first_utmctr', google_vals.utmctr); // term (search term)
                		writeCookie('first_utmgclid', google_vals.utmgclid); //adwords-only

				if (+pageviews===1) {
					writeCookie('first_landing', window.location.pathname);
				}
			}
		}	


	    function QueryString() {
		  // This function is anonymous, is executed immediately and 
		  // the return value is assigned to QueryString!
		  var query_string = {};
		  var query = window.location.search.substring(1);
		  var vars = query.split("&");
		  for (var i=0;i<vars.length;i++) {
		    var pair = vars[i].split("=");
		        // If first entry with this name
		    if (typeof query_string[pair[0]] === "undefined") {
		      query_string[pair[0]] = pair[1];
		        // If second entry with this name
		    } else if (typeof query_string[pair[0]] === "string") {
		      var arr = [ query_string[pair[0]], pair[1] ];
		      query_string[pair[0]] = arr;
		        // If third or later entry with this name
		    } else {
		      query_string[pair[0]].push(pair[1]);
		    }
		  } 
		    return query_string;
		}

	    var lastClicked;

	    $('.price-display a').click(function() {
	      $('.pricing-overlay').css('top', $('.price-display a').offset().top + 30);
	      if ($('.pricing-overlay').is(':hidden') || $(this).attr('class') != lastClicked) {
	        hideOverlay();
	        if ($(this).hasClass('voice-broadcast-overlay')) {
	          overlayContent = vbOverlay;
	          $('.pricing-overlay').addClass('vb');
	          teslaSignUp()
	        } else if ($(this).hasClass('text-messaging-overlay')) {
	          overlayContent = textOverlay;
	          $('.pricing-overlay').addClass('text');
	          teslaSignUp();
	        } else if ($(this).hasClass('numbers-overlay')) {
	          overlayContent = numbersOverlay;
	          $('.pricing-overlay').addClass('numbers');
	          teslaSignUp()
	        } else if ($(this).hasClass('ivr-overlay')) {
	          overlayContent = ivrOverlay;
	          $('.pricing-overlay').addClass('ivr');
	          teslaSignUp()
	        } else if ($(this).hasClass('ccc-overlay')) {
	          overlayContent = cccOverlay;
	          $('.pricing-overlay').addClass('ccc');
	          $('.pricing-overlay .sign-up .button').attr('href', 'https://www.callfire.com/dialer/signup.do');
	        }
	        $('.pricing-overlay-content').html(overlayContent);
	        $('.pricing-overlay').show();
		  } 
		  else {
		  	hideOverlay();
		  }
  		  lastClicked = $(this).attr('class');
	      
	      return false;
	    });

	    $('.overlay-close').click(function() {
	      hideOverlay();
	      return false;
	    });

		$('.section-pricing .button-group a').live("click", function() {
	      $(this).closest('.button-group').find('.button').removeClass('active');
	      $(this).addClass('active');
	      $(this).closest('.pricing-overlay').find('table').hide();
	      if ($(this).hasClass('local-rates')) {
	        $(this).closest('.pricing-overlay').find('#local-number-pricing').show();
	        return false;
	      } else if ($(this).hasClass('toll-rates')) {
	        $(this).closest('.pricing-overlay').find('#toll-free-number-pricing').show();
	        return false;
	      } else if ($(this).hasClass('number-rates')) {
	        $(this).closest('.pricing-overlay').find('#number-prices').show();
	        return false;
	      }
	      return false;
	    });

	    $('#numbers-expanded-pricing .button-group a').live("click", function() {
	    	$(this).closest('.button-group').find('.button').removeClass('active');
	    	$(this).addClass('active');
	    	$('#numbers-expanded-pricing').find('table').hide();
	    	if ($(this).hasClass('number-rates')) {
	    		$('#number-prices').show();
	    		return false;
	    	}
	    	else if($(this).hasClass('local-toll-free-rates')) {
	    		$('#local-toll-free-number-pricing').show();
	    		return false;
	    	}
	    	return false;
	    });

	  //show&hide short code pricing 
	  $('.short-code-toggle').click(function() {
	  	$('.short-code-pricing').toggle();
	  	var text = $('.short-code-toggle').text();
	  	$('.short-code-toggle').text(
        text == "Show short code pricing" ? "Hide short code pricing" : "Show short code pricing");
	  	return false;
	  });

		//end pricing page js

		$('#rates-toggle').live("click", function() {
			$('#rates-overview').toggle();
			return false;
		});

		$('.rates-close').live("click", function() {
			$('#rates-overview').hide();
			return false;
		});

		$(".select2").select2({
            data:[{id:'afghanistan', text: 'Afghanistan'},
				{id:'alaska', text: 'Alaska'},
				{id:'albania', text: 'Albania'},
				{id:'algeria', text: 'Algeria'},
				{id:'american samoa', text: 'American Samoa'},
				{id:'andorra', text: 'Andorra'},
				{id:'angola', text: 'Angola'},
				{id:'anguilla', text: 'Anguilla'},
				{id:'antarctica', text: 'Antarctica'},
				{id:'antigua & barbuda', text: 'Antigua & Barbuda'},
				{id:'argentina', text: 'Argentina'},
				{id:'armenia', text: 'Armenia'},
				{id:'aruba', text: 'Aruba'},
				{id:'ascension island', text: 'Ascension Island'},
				{id:'australia territories', text: 'Australia Territories'},
				{id:'australia', text: 'Australia'},
				{id:'austria', text: 'Austria'},
				{id:'azerbaijan', text: 'Azerbaijan'},
				{id:'bahamas', text: 'Bahamas'},
				{id:'bahrain', text: 'Bahrain'},
				{id:'bangladesh', text: 'Bangladesh'},
				{id:'barbados', text: 'Barbados'},
				{id:'belarus', text: 'Belarus'},
				{id:'belgium', text: 'Belgium'},
				{id:'belize', text: 'Belize'},
				{id:'benin', text: 'Benin'},
				{id:'bermuda', text: 'Bermuda'},
				{id:'bhutan', text: 'Bhutan'},
				{id:'bolivia', text: 'Bolivia'},
				{id:'bosnia & herzegovina', text: 'Bosnia & Herzegovina'},
				{id:'botswana', text: 'Botswana'},
				{id:'brazil', text: 'Brazil'},
				{id:'british virgin islands', text: 'British Virgin Islands'},
				{id:'brunei', text: 'Brunei'},
				{id:'bulgaria', text: 'Bulgaria'},
				{id:'burkina faso', text: 'Burkina Faso'},
				{id:'burundi', text: 'Burundi'},
				{id:'cambodia', text: 'Cambodia'},
				{id:'cameroon', text: 'Cameroon'},
				{id:'canada', text: 'Canada'},
				{id:'cape verde', text: 'Cape Verde'},
				{id:'cayman islands', text: 'Cayman Islands'},
				{id:'central african republic', text: 'Central African Republic'},
				{id:'chad', text: 'Chad'},
				{id:'chile', text: 'Chile'},
				{id:'china', text: 'China'},
				{id:'colombia', text: 'Colombia'},
				{id:'comoros', text: 'Comoros'},
				{id:'congo', text: 'Congo'},
				{id:'cook islands', text: 'Cook Islands'},
				{id:'costa rica', text: 'Costa Rica'},
				{id:'croatia', text: 'Croatia'},
				{id:'cuba', text: 'Cuba'},
				{id:'cyprus', text: 'Cyprus'},
				{id:'czech republic', text: 'Czech Republic'},
				{id:'dem. rep. of congo', text: 'Dem. Rep. of Congo'},
				{id:'denmark', text: 'Denmark'},
				{id:'diego garcia', text: 'Diego Garcia'},
				{id:'djibouti', text: 'Djibouti'},
				{id:'dominica', text: 'Dominica'},
				{id:'dominican republic', text: 'Dominican Republic'},
				{id:'east timor', text: 'East Timor'},
				{id:'ecuador', text: 'Ecuador'},
				{id:'egypt', text: 'Egypt'},
				{id:'el salvador', text: 'El Salvador'},
				{id:'equatorial guinea', text: 'Equatorial Guinea'},
				{id:'eritrea', text: 'Eritrea'},
				{id:'estonia', text: 'Estonia'},
				{id:'ethiopia', text: 'Ethiopia'},
				{id:'falkland islands', text: 'Falkland Islands'},
				{id:'faroe islands', text: 'Faroe Islands'},
				{id:'fiji', text: 'Fiji'},
				{id:'finland', text: 'Finland'},
				{id:'france', text: 'France'},
				{id:'french guiana', text: 'French Guiana'},
				{id:'french polynesia', text: 'French Polynesia'},
				{id:'gabon', text: 'Gabon'},
				{id:'gambia', text: 'Gambia'},
				{id:'georgia', text: 'Georgia'},
				{id:'germany', text: 'Germany'},
				{id:'ghana', text: 'Ghana'},
				{id:'gibraltar', text: 'Gibraltar'},
				{id:'greece', text: 'Greece'},
				{id:'greenland', text: 'Greenland'},
				{id:'grenada', text: 'Grenada'},
				{id:'guadeloupe', text: 'Guadeloupe'},
				{id:'guam', text: 'Guam'},
				{id:'guatemala', text: 'Guatemala'},
				{id:'guinea bissau', text: 'Guinea Bissau'},
				{id:'guinea', text: 'Guinea'},
				{id:'guyana', text: 'Guyana'},
				{id:'haiti', text: 'Haiti'},
				{id:'hawaii', text: 'Hawaii'},
				{id:'honduras', text: 'Honduras'},
				{id:'hong kong', text: 'Hong Kong'},
				{id:'hungary', text: 'Hungary'},
				{id:'iceland', text: 'Iceland'},
				{id:'india', text: 'India'},
				{id:'indonesia', text: 'Indonesia'},
				{id:'iran', text: 'Iran'},
				{id:'iraq', text: 'Iraq'},
				{id:'ireland', text: 'Ireland'},
				{id:'israel', text: 'Israel'},
				{id:'italy', text: 'Italy'},
				{id:'ivory coast', text: 'Ivory Coast'},
				{id:'jamaica', text: 'Jamaica'},
				{id:'japan', text: 'Japan'},
				{id:'jordan', text: 'Jordan'},
				{id:'kazakhstan', text: 'Kazakhstan'},
				{id:'kenya', text: 'Kenya'},
				{id:'kiribati', text: 'Kiribati'},
				{id:'kuwait', text: 'Kuwait'},
				{id:'kyrgyzstan', text: 'Kyrgyzstan'},
				{id:'laos', text: 'Laos'},
				{id:'latvia', text: 'Latvia'},
				{id:'lebanon', text: 'Lebanon'},
				{id:'lesotho', text: 'Lesotho'},
				{id:'liberia', text: 'Liberia'},
				{id:'libya', text: 'Libya'},
				{id:'liechtenstein', text: 'Liechtenstein'},
				{id:'lithuania', text: 'Lithuania'},
				{id:'luxembourg', text: 'Luxembourg'},
				{id:'macau', text: 'Macau'},
				{id:'macedonia', text: 'Macedonia'},
				{id:'madagascar', text: 'Madagascar'},
				{id:'malawi', text: 'Malawi'},
				{id:'malaysia', text: 'Malaysia'},
				{id:'maldives', text: 'Maldives'},
				{id:'mali', text: 'Mali'},
				{id:'malta', text: 'Malta'},
				{id:'marshall islands', text: 'Marshall Islands'},
				{id:'martinique', text: 'Martinique'},
				{id:'mauritania', text: 'Mauritania'},
				{id:'mauritius island', text: 'Mauritius Island'},
				{id:'mayotte', text: 'Mayotte'},
				{id:'mexico', text: 'Mexico'},
				{id:'micronesia', text: 'Micronesia'},
				{id:'moldova', text: 'Moldova'},
				{id:'monaco', text: 'Monaco'},
				{id:'mongolia', text: 'Mongolia'},
				{id:'montenegro', text: 'Montenegro'},
				{id:'montserrat', text: 'Montserrat'},
				{id:'morocco', text: 'Morocco'},
				{id:'mozambique', text: 'Mozambique'},
				{id:'myanmar (burma)', text: 'Myanmar (Burma)'},
				{id:'namibia', text: 'Namibia'},
				{id:'nauru', text: 'Nauru'},
				{id:'nepal', text: 'Nepal'},
				{id:'netherlands antilles', text: 'Netherlands Antilles'},
				{id:'netherlands', text: 'Netherlands'},
				{id:'new caledonia', text: 'New Caledonia'},
				{id:'new zealand', text: 'New Zealand'},
				{id:'nicaragua', text: 'Nicaragua'},
				{id:'niger', text: 'Niger'},
				{id:'nigeria', text: 'Nigeria'},
				{id:'niue island', text: 'Niue Island'},
				{id:'north korea', text: 'North Korea'},
				{id:'norway', text: 'Norway'},
				{id:'oman', text: 'Oman'},
				{id:'pakistan', text: 'Pakistan'},
				{id:'palau', text: 'Palau'},
				{id:'palestine', text: 'Palestine'},
				{id:'panama', text: 'Panama'},
				{id:'papua new guinea', text: 'Papua New Guinea'},
				{id:'paraguay', text: 'Paraguay'},
				{id:'peru', text: 'Peru'},
				{id:'philippines', text: 'Philippines'},
				{id:'poland', text: 'Poland'},
				{id:'portugal', text: 'Portugal'},
				{id:'puerto rico', text: 'Puerto Rico'},
				{id:'qatar', text: 'Qatar'},
				{id:'reunion island', text: 'Reunion Island'},
				{id:'romania', text: 'Romania'},
				{id:'russia', text: 'Russia'},
				{id:'rwanda', text: 'Rwanda'},
				{id:'san marino', text: 'San Marino'},
				{id:'sao tome & principe', text: 'Sao Tome & Principe'},
				{id:'saudi arabia', text: 'Saudi Arabia'},
				{id:'senegal', text: 'Senegal'},
				{id:'serbia', text: 'Serbia'},
				{id:'seychelles', text: 'Seychelles'},
				{id:'sierra leone', text: 'Sierra Leone'},
				{id:'singapore', text: 'Singapore'},
				{id:'slovakia', text: 'Slovakia'},
				{id:'slovenia', text: 'Slovenia'},
				{id:'solomon islands', text: 'Solomon Islands'},
				{id:'somalia', text: 'Somalia'},
				{id:'south africa', text: 'South Africa'},
				{id:'south korea', text: 'South Korea'},
				{id:'spain', text: 'Spain'},
				{id:'sri lanka', text: 'Sri Lanka'},
				{id:'st. helena', text: 'St. Helena'},
				{id:'st. helena', text: 'Saint Helena'},
				{id:'st. kitts & nevis', text: 'St. Kitts & Nevis'},
				{id:'st. kitts & nevis', text: 'Saint Kitts & Nevis'},
				{id:'st. lucia', text: 'St. Lucia'},
				{id:'st. lucia', text: 'Saint Lucia'},
				{id:'st. pierre & miquelon', text: 'St. Pierre & Miquelon'},
				{id:'st. pierre & miquelon', text: 'Saint Pierre & Miquelon'},
				{id:'st. vincent & grenadines', text: 'St. Vincent & Grenadines'},
				{id:'st. vincent & grenadines', text: 'Saint Vincent & Grenadines'},
				{id:'sudan', text: 'Sudan'},
				{id:'suriname', text: 'Suriname'},
				{id:'swaziland', text: 'Swaziland'},
				{id:'sweden', text: 'Sweden'},
				{id:'switzerland', text: 'Switzerland'},
				{id:'syria', text: 'Syria'},
				{id:'taiwan', text: 'Taiwan'},
				{id:'tajikistan', text: 'Tajikistan'},
				{id:'tanzania', text: 'Tanzania'},
				{id:'thailand', text: 'Thailand'},
				{id:'togo', text: 'Togo'},
				{id:'tokelau', text: 'Tokelau'},
				{id:'tonga', text: 'Tonga'},
				{id:'trinidad & tobago', text: 'Trinidad & Tobago'},
				{id:'tunisia', text: 'Tunisia'},
				{id:'turkey', text: 'Turkey'},
				{id:'turkmenistan', text: 'Turkmenistan'},
				{id:'turks & caicos', text: 'Turks & Caicos'},
				{id:'tuvalu', text: 'Tuvalu'},
				{id:'uganda', text: 'Uganda'},
				{id:'ukraine', text: 'Ukraine'},
				{id:'united arab emirates', text: 'United Arab Emirates'},
				{id:'united kingdom', text: 'United Kingdom'},
				{id:'united states', text: 'United States'},
				{id:'uruguay', text: 'Uruguay'},
				{id:'us virgin islands', text: 'US Virgin Islands'},
				{id:'uzbekistan', text: 'Uzbekistan'},
				{id:'vanuatu', text: 'Vanuatu'},
				{id:'vatican city', text: 'Vatican City'},
				{id:'venezuela', text: 'Venezuela'},
				{id:'vietnam', text: 'Vietnam'},
				{id:'wallis & futuna', text: 'Wallis & Futuna'},
				{id:'western samoa', text: 'Western Samoa'},
				{id:'yemen (arab republic)', text: 'Yemen (Arab Republic)'},
				{id:'zambia', text: 'Zambia'},
				{id:'zimbabwe', text: 'Zimbabwe'}],
			createSearchChoice: function(term, data) {
				if (term==="us" || term === "usa") {
					return {id:"united states", text:"United States"};
				}
				else if (term==="uk") {
					return {id:"united kingdom", text:"United Kingdom"};
				}
				/*if ($(data).filter(function() {
					return this.text.localeCompare(term)===0; 
				}).length===0) {
					return {id:term, text:term};
				}*/
			}
        });
	});

	/* attach a submit handler to the form */
	$(".select2").change(function(e) {
		$("#result").empty().append('<div class="loading"/>');
		/* get some values from elements on the page: */
		var $form = $("#searchForm"),
		    term = $form.find( 'input[name="international-lookup"]' ).val(),
		    url = "/sites/all/themes/callfire/php/international_rates.php";

		$.post(url, {"international-lookup": term},
		  	function(data) {
		  		setTimeout( function() {
		 			$("#result").empty().append(data);
		  		}, 500);
		  	});
	});

	/* placeholder replacement for ie */
	$('#landing-page-sign-up-form input').placeholder();

	if (window.Rainbow) window.Rainbow.linecount = (function(Rainbow) {
	    Rainbow.onHighlight(function(block) {
	        var $block = $(block);
	        var $dummy = $block.clone().empty();
	        var $lines = $('<table />').addClass('rainbow').appendTo($dummy);
	        var $header = $('<tr />').addClass('rainbow-header').appendTo($lines);

	        $('<th />').appendTo($header);
	        $('<th />').addClass('rainbow-language').text($block.data('language')).appendTo($header);
	        var lines = $block.html().split('\n');
	        jQuery.each(lines, function(index, value) {
	            index++;
	            var $row = $('<tr />').addClass('rainbow-line rainbow-line-'+index);

	            $('<td />').addClass('rainbow-line-number').appendTo($row).attr("data-number", index);
	            $('<td />').addClass('rainbow-line-code').html(value).appendTo($row);

	            $lines.append($row);
	        });
	        $block.replaceWith($lines);
	    });
	})(window.Rainbow);

})(jQuery, Drupal, this, this.document);
