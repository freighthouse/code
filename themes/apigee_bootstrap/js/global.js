(function($) {
  Drupal.behaviors.apigeeBootstrap = {
    attach: function(context, settings) {
      $(".view-customers-ctas .col-lg-6").addClass("col-sm-6 col-md-6");
      $(".view-resources .col-lg-3").addClass("col-sm-3 col-md-3");

      //urlEngine = new UrlBox();
      //linkEngine = new LinkBox();
      //formEngine = new FormBox();

      ticToc();
      goGlobal();
      goForm();
      goSharing();
      //dropTag();
    }
  };

/*
var dropTag = function() {
    var navToggle = document.getElementsByClassName("navbar-toggle")[0];
    var isMobile = (window.getComputedStyle(navToggle).display === "block");
    if (!isMobile) {
        window.dataLayer = window.dataLayer || [];
        var bodyTag = document.getElementsByTagName("body")[0];
        var dropTag = document.createElement("div");
        dropTag.setAttribute("id", "apigee_dropTag");
        dropTag.style.position = "fixed";
        dropTag.style.top = "30%";
        dropTag.style.right = "0";
        dropTag.style.zIndex = "7777";
        dropTag.style.height = "140px";
        dropTag.style.boxShadow = "0 3px 3px rgba(0,0,0,0.3)";
        var dropHandle = document.createElement("div");
        dropHandle.setAttribute("class", "dropHandle");
        dropHandle.style.width = "40px";
        dropHandle.style.height = "100%";
        dropHandle.style.cursor = "pointer";
        dropHandle.style.float = "left";
        dropHandle.style.background = 'transparent url("//apigee.com/about/sites/mktg-new/files/iloveapis_handle.jpg") no-repeat 0 0';
        dropHandle.addEventListener("click", function(event) {
            var tempDrawer = document.getElementsByClassName("dropDrawer")[0];
            var drawerShowing = (window.getComputedStyle(tempDrawer).display === "block");
            if (drawerShowing) {
                tempDrawer.style.display = "none";
            } else {
                dataLayer.push({
    				"event" : "AdvertisingClick",
    				"action" : "openIloveapissidebar",
    				"label" : document.location.href
    			});
    		    tempDrawer.style.display = "block";
            }
        });
        dropTag.appendChild(dropHandle);
        var dropDrawer = document.createElement("div");
        dropDrawer.setAttribute("class", "dropDrawer");
        dropDrawer.style.display = "none";
        dropDrawer.style.width = "360px";
        dropDrawer.style.height = "100%";
        dropDrawer.style.background = 'transparent url("//apigee.com/about/sites/mktg-new/files/iloveapis_drawer.jpg") no-repeat 0 0';
        dropDrawer.style.cursor = "pointer";
        dropDrawer.addEventListener("click", function(event) {
            var apiDestination = "http://iloveapis.com";
			dataLayer.push({
				"event" : "AdvertisingClick",
				"action" : apiDestination
			});
			document.location.href = apiDestination;
        });
        dropDrawer.addEventListener("mouseleave", function(event) {
            this.style.display = "none";
        });
        dropTag.appendChild(dropDrawer);
        bodyTag.appendChild(dropTag);
    }
};
*/

var goSharing = function() {
    var sharingClasses = ["node-type-blog-content", "page-events"];
    var sharingIndex = -1;
    for (var i=0; i<sharingClasses.length; i++) {
        if ($("body").hasClass(sharingClasses[i])) {
            sharingIndex = i;
            break;
        }
    }
    if (sharingIndex >= 0) {
        window.dataLayer = window.dataLayer || [];
        var safeUrl = encodeURIComponent(document.location.href);
        var safeTitle = encodeURIComponent($("title").text());
        var shareMap = {
            twitter : {
                href : "https://twitter.com/share?url="+safeUrl+"&via=apigee&text="+safeTitle,
                iclass : "fa-twitter"
            },
            facebook : {
                href : "https://www.facebook.com/sharer/sharer.php?u="+safeUrl+"&t="+safeTitle,
                iclass : "fa-facebook"
            },
            linkedin : {
                href : "https://www.linkedin.com/shareArticle?mini=true&url="+safeUrl+"&title="+safeTitle+"&source=Apigee",
                iclass : "fa-linkedin"
            },
            googleplus : {
                href : "https://plus.google.com/share?url="+safeUrl,
                iclass : "fa-google-plus"
            },
            delicious : {
                href : "https://delicious.com/save?v=5&provider=Apigee&noui&jump=close&url="+safeUrl+"&title="+safeTitle,
                iclass : "fa-delicious"
            }
        }
        var shareList = '<div class="outbound_sharing_block"><h2>Share</h2><ul>';
        for (var theKey in shareMap) {
            if (shareMap.hasOwnProperty(theKey)) {
                var theValue = shareMap[theKey];
                var theHref = theValue["href"];
                var theClass = theValue["iclass"];
                shareList += '<li><a target="_blank" href="'+theValue["href"]+'" title="'+theKey+'"><i class="fa '+theClass+'"></i></a></li>';
            };
        }
        shareList += '</ul></div>';
        var bodyField;
        if ($(".field-name-body").length > 0) {
            bodyField = $(".field-name-body").first();
        } else if ($(".view-id-events .view-content").length > 0) {
            bodyField = $(".view-id-events .view-content").first();
        } else {
            bodyField = $(".region-content").first();
        }
        $(bodyField).after(shareList);
        $(".outbound_sharing_block a").click(function(event) {
            var thisTitle = $(this).attr("title");
            var thisUrl = $(this).attr("href");
            dataLayer.push({
                "event" : "outboundShare",
                "outbound-sharing-link" : thisTitle,
                "outbound-sharing-url" : thisHref
            });
            window.open(thisHref, '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,width=600,height=500');
            return false;
        });
    }
};



  Drupal.behaviors.footer = {
    attach: function(context, settings) {
      $('.footer li.dropdown').each(function() {
        //$(this).addClass('col-md-3');
      });
      $('.footer .dropdown-menu').each(function() {
        $(this).removeClass('dropdown-menu');
      });
    }
  };

  Drupal.behaviors.carousel = {
    attach: function(context, settings) {

        $('.carousel-inner .item.active video').trigger('play');

      /*$('.carousel').carousel({
        interval: 3000
      });
*/

      $('.previous-slide-button').click(function() {
        var carouselContainer = $(this).closest(".carousel");
        var carouselVideo = $(carouselContainer).find('.carousel-inner .item.active video').first();
        $(carouselContainer).carousel('prev');
        $(carouselVideo).trigger('pause');
        $(carouselVideo).currentTime = 0;
        $(carouselVideo).load();
      });

      $('.next-slide-button').click(function() {
        var carouselContainer = $(this).closest(".carousel");
        var carouselVideo = $(carouselContainer).find('.carousel-inner .item.active video').first();
        $(carouselContainer).carousel('next');
        $(carouselVideo).trigger('pause');
        $(carouselVideo).currentTime = 0;
        $(carouselVideo).load();
      });

      $('.carousel-inner .item.active video').each(function(){
      //$('.carousel-inner .item video').each(function(){
        $(this).bind("ended", function(){
            var carouselContainer = $(this).closest(".carousel");
        var carouselVideo = $(carouselContainer).find('.carousel-inner .item.active video').first();
/*         console.log($(carouselVideo)); */
        var isMatch = ($(carouselVideo)[0] === $(this)[0]);
        //console.log(isMatch);
        if (!isMatch) carouselVideo = $('.carousel-inner .item video').first();
        $(carouselContainer).carousel('next');
        $(carouselVideo).currentTime = 0;
        $(carouselVideo).trigger('play');
/*
        $(carouselVideo).trigger('pause');
        $(carouselVideo).currentTime = 0;
        $(carouselVideo).load();
*/

            /*
var carouselContainer = $(this).closest(".carousel");
            var carouselVideo = $(carouselContainer).find('.carousel-inner .item.active video').first();
            $(carouselContainer).carousel('next');
            $(carouselVideo).trigger('play');
*/
        });
      });

    }
  };

  Drupal.behaviors.customersPage = {
    attach: function(context, settings) {
      // Convert isotope filter block to a select list
      $("#filters").change(function() {
        var catergory = $("option:selected", this).val();
        $('#isotope-container').isotope({filter: catergory});
        return false;
      });

      // Show/Hide Customer text on hover
      $(".view-customers-page .isotope-element").each(function() {
        if ($(this).children().hasClass("views-field-view-node")) {
          $(this).addClass('has-story');
        };
        if ($(this).children().hasClass("views-field-field-customer-featured")) {
            $(this).addClass('has-featured');
        }
        if($(this).children().hasClass("views-field-field-customer-text")) {
          $(this).addClass('has-nugget');
          $(this).hover(function() {
            $(this).children(".views-field-field-customer-logo").toggle();
            $(this).children(".views-field-field-customer-text").toggle();
            $(this).children(".views-field.views-field-view-node").toggle();
          });
        };
      });

      // Change the text of the Customer Story link in the slider
      $(".view-featured-customer-slideshow .field-name-field-customer-story a").text("read their story >");

      /** Repair colorbox link images. */
      $(".view-customers-video-slideshow .views-field-colorbox img").each(function() {
          var parentLink = $(this).closest('.file-video').find("a").first() || false;
          if (parentLink) $(this).appendTo(parentLink);
      });

      /** change pause buttons to something more interesting. */
/*
      $(".views-slideshow-controls-text-previous a").first().html('<i class="fa fa-angle-left"></i>');
      $(".views-slideshow-controls-text-pause").html('More resources');
      $("#views_slideshow_controls_text_pause_customers_video_slideshow-block").html('More resources about Analytic services');
      $(".views-slideshow-controls-text-next a").first().html('<i class="fa fa-angle-right"></i>');
*/
    $(".views-slideshow-controls-text-previous a").first().html('<i class="fa fa-chevron-circle-left"></i>');
    $(".views-slideshow-controls-text-pause").remove();
    $(".views-slideshow-controls-text-next a").first().html('<i class="fa fa-chevron-circle-right"></i>');

      // Add Video Overlay Containers
      //$(".customer-story-header .views-field-colorbox img").before('<span class="vid-overlay"></span>');
      //$(".view-customers-video-slideshow .views-field-colorbox img").before('<span class="vid-overlay"></span>');

    }
  };

  Drupal.behaviors.partnersPage = {
    attach: function(context, settings) {
      // Show/Hide Customer text on hover
      $(".view-partners-page .isotope-element").each(function() {
        if ($(this).children().hasClass("views-field-view-node")) {
          $(this).addClass('has-story');
        };
        if ($(this).children().hasClass("views-field-field-customer-featured")) {
            $(this).addClass('has-featured');
        }
        if($(this).children().hasClass("views-field-field-partner-text")) {
          $(this).addClass('has-nugget');
          $(this).hover(function() {
            $(this).children(".views-field-field-partner-logo").toggle();
            $(this).children(".views-field-field-partner-text").toggle();
            $(this).children(".views-field.views-field-view-node").toggle();
          });
        };
      });

      // Change the text of the Customer Story link in the slider
      $(".view-partner-feature-slideshow .field-name-field-pls-partner-story a").text("read their story >");

      // Add Video Overlay Containers
      $(".view-partners-video-slideshow .views-field-colorbox img").before('<span class="vid-overlay"></span>');

    }
  };

  Drupal.behaviors.resourcesPage = {
    attach: function(context, settings) {
      // Resources page popovers
      $(".view-resources .attachment .thumbnail").popover({
        html : true,
        content: function() {
          return $(this).children('.views-field-field-summary').html();
        },
        title: function() {
          return $(this).children('.views-field-title').text();
        },
        trigger: 'hover',
        placement: 'auto'
      });

      $(".view-resources #views-bootstrap-thumbnail-5 .thumbnail").popover({
        html : true,
        content: function() {
          return $(this).children('.views-field-field-summary').html();
        },
        title: function() {
          return $(this).children('.views-field-title').text();
        },
        trigger: 'hover',
        placement: 'auto'
      });

      // Hide inactive popovers
      $('.view-resources .thumbnail').click(function () {
        $('.thumbnail').not(this).popover('hide');
      });

      // Hide popover after clicking anywhere outside of it's container
      $('body.resources').on('click', function (e) {
        $('.thumbnail').each(function () {
          if (!$(this).is(e.target) && $(this).has(e.target).length === 0 && $('.popover').has(e.target).length === 0) {
              $(this).popover('hide');
          }
        });
      });

      //
      $(".resources #edit-tid-1-wrapper").css("visibility","visible");

      // Display search box after last filter
      $(".resources .views-widget-filter-keys").insertAfter(".resources .views-widget-sort-order");

      // Resources Interest filters - Change -Any- to All
      $(".resources .bef-select-as-links #edit-tid-1-all a").text("All");

      // Convert Resources Interest filters to buttons
      $(".resources .form-type-bef-link").addClass("btn btn-primary");

      if ($(window).width() < 768){
        $(".resources .views-exposed-widgets").addClass("hidden-xs");
        $('.view-resources .view-content').hide();
        $('.view-resources .view-header').addClass('thumbnail');
        $('.view-resources .view-header h2').each(function() {
          $(this).on('click', function () {
            $(this).parent().next('.view-content').toggle();
            e.preventDefault();
          });
        });
      }
    }
  };

  // Products
  Drupal.behaviors.apigeeProducts = {
    attach: function (context, settings) {
      // Column layout for Product Features
      $(".field-name-field-product-feature-list > .field-items").addClass("row");
      $(".field-name-field-product-feature-list > .field-items > .field-item").each(function(){
        $(this).addClass("col-md-3");
      });

      // Insert TOC after Product Header
      $(".node-type-product #toc").insertAfter(".products .group-product-header");
    }
  };

  Drupal.behaviors.apigeeAboutNavigation = {
    attach: function (context) {
      $('.about-apigee-navigation').each(function() {
        $(this).children('.nav').affix({
          offset: {
            top: $(this).offset().top
          }
        });
        $('body')
          .scrollspy({
            target: '.about-apigee-navigation'
          })
          .on('activate.bs.scrollspy', function() {
            $(this).data('bs.scrollspy').refresh();
          });
      });
      // Show search box when clicking search icon
      /*
$('#navbar .form-search').appendTo('#superfish-1 #menu-4111-1')
      .addClass('form-search-hover')
      .css('position','relative').css('bottom','25px').hide();
      $('#superfish-1 #menu-4111-1 a').click(function(e) {
        $('.form-search-hover').show();
        e.preventDefault();
      });
      $('.form-search-hover').blur(function() {
        $(this).fadeOut();
      });
*/
    }
  };

  Drupal.behaviors.apigeeTeam = {
    attach: function (context) {
      $('.node-team-member').each(function() {
        var $member = $(this);
        var $bio = $member.find('.field-name-field-team-member-bio');
        var $toggle = $('<button class="btn btn-default bio-toggle"></button>');

        $toggle
          .bind('show', function() {
            $bio
              .removeClass('hidden')
              .show();

              $toggle.text(Drupal.t('Less')).addClass('showing');
          })
          .bind('hide', function() {
            $bio
              .addClass('hidden')
              .hide();

            $toggle.text(Drupal.t('More')).removeClass('showing');
          })
          .bind('toggle', function() {
            if ($bio.is('.hidden')) {
                var contentElement = $(this)[0];
                $(this).closest("div.view-content").find("button.bio-toggle").each(function() {
                    if ($(this)[0] !== contentElement) $(this).trigger('hide');
                });
              $toggle.trigger('show');
            }
            else {
              $toggle.trigger('hide');
            }
          })
          .bind('click', function() {
            $toggle.trigger('toggle');
          })
          .trigger('hide')
          .appendTo($member);
      });
    }
  };

  Drupal.behaviors.apigeeCTABar = {
    attach: function(context) {
      var $ctaBarBlock = $('#block-views-cta-bar-block', context);

      $ctaBarBlock.each(function() {
        var $ctaBarBlock = $(this);
        var ctaBarBlockTop = $ctaBarBlock.offset().top;
        var $ctaBar = $ctaBarBlock.find('.view-cta-bar');
        var ctaBarHeight = $ctaBar.height();
        var $window = $(window);
        var isStatic;

        $window.on('scroll', function() {
          var scrollTop = $window.scrollTop();
          var windowHeight = $window.height();

          if ((scrollTop + windowHeight) > (ctaBarBlockTop + ctaBarHeight)) {
            if (!isStatic) {
              $ctaBar.addClass('static');
              isStatic = true;
            }
          }
          else {
            if (isStatic) {
              $ctaBar.removeClass('static');
              isStatic = false;
            }
          }
        });
      });
    }
  };

  Drupal.behaviors.apigeeCustomerTeaser = {
    attach: function(context) {
      var $window = $(window);
      var $customerStatement = $('.node-customer.node-customer-statement.node-teaser', context);

      $customerStatement.each(function() {
        var $node = $(this);
        var $statement = $node.find('.field-name-field-customer-statement');
        var $items = $statement.find('.field-items');

        var $button = $('<button><span>' + Drupal.t('View Statement') + '</span></button>');

        $button
          .colorbox({
            href: $items,
            inline: true,
            width: '80%'
          })
          .prependTo($statement);
      });
    }
  };

  Drupal.behaviors.supportSearch = {
    attach: function(context) {

      // Check if user is on a mobile device
      mobileUser = function() {
        var check = false;
        (function(a,b){if(/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|mobile.+firefox|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows ce|xda|xiino/i.test(a)||/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0,4)))check = true})(navigator.userAgent||navigator.vendor||window.opera);

        if (screen.height < 400 && screen.width < 650) {
          check = true;
        }
        return check;
      }

      var includeSupportSearch = function () {
        if (document.URL.indexOf('/about/support/portal') > 0) {
          if (mobileUser()) {
            enableMobileLayout();
          }
          attachEnterKeySearchHandler();
          $('#search').on('click', function () {
            executeSearch();
          });
        }
      }

      var enableMobileLayout = function () {
        $('#login-container').addClass('tab-pane active');
        $('#search-container').each(function () {
          $(this).addClass('tab-pane');
          $(this).height($('#login-container').height());
        });
        $('#search-container > h3, #login-container > h3').remove();
      }

      var executeSearch = function (page, filter) {
        var gss_url;
        var excludedSites = '-site:community.apigee.com/topics -site:community.apigee.com/spaces -site:community.apigee.com/academy -site:community.apigee.com/themes'
        var query = $('input.supportSearch').val();

        $('.search-window').scrollTop(0);

        $('.search-window').each(function () {
          if ($(this).length != 0) {
            $(this).addClass('blurred');
          }
        });

        if (filter) {
          query += ' more:' + filter;
        }

        if (page) {
          var startIndex = ((page - 1) * 10) + 1;
          query += '&startIndex=' + startIndex;
        }

        gss_url = 'https://apigeedocs-prod.apigee.net/community_search/search/?q=' + query + ' ' + excludedSites;

        detachEnterKeySearchHandler();

        $.get(gss_url, function (response) {

          if ($('.search-window').length == 0) {
            insertSearchOverlays();
          } else {
            $('.search-window').removeClass('blurred');
            $('.search-results').empty();
          }

          populateSearchResults(response);

          if ($('.pagination').length == 0) {
            appendPagination(response);
          }

        });
      }

      var populateSearchResults = function (response) {
        for (i in response.results) {
          //remove '| Apigee Documentation' from the title
          var title = response.results[i].title;
          var link = response.results[i].link;
          var linkText = truncateUrl(link);
          var site = parseSiteFromURL(link);
          var snippet = response.results[i].snippet;
          var targetList;
          var result;

          title = appendSiteToTitle(title, site);
          result = '<div class="search-result"><h4><a href="' + link + '">' + title + '</a></h4><p class="search-link"><a href="' + link + '">' + linkText + '</a></p><p>' + snippet + '</p></div>'
          $('.search-results').append(result);
        }
      }

      var appendPagination = function (searchResults) {

        var paginationData;
        var paginationHTML = "";
        var pageCount;

        if(searchResults.nextPage) {
          paginationData = searchResults.nextPage;
        } else if (searchResults.previousPage) {
          paginationData = searchResults.previousPage;
        }

        if (paginationData.totalResults < 100) {
          pageCount = Math.floor(paginationData.totalResults/10);
        } else {
          pageCount = 10;
        }

        for (i = 1; i <= pageCount; i++) {
          paginationHTML += '<div class="page">' + i + '</div>'
        }

        $('.searchResults-wrapper').append('<div class="pagination"></div>');

        $('.pagination').each(function () {
          if (mobileUser()) {
            $(this).append('<div class="page prev" data-page=0>&lt Prev</div>');
            $(this).append('<div class="page next" data-page=2>Next &gt;</div>');
          } else {
            $(this).append('<div class="page prev">&lt</div>');
            $(this).append(paginationHTML);
            $(this).append('<div class="page next">&gt;</div>');
          }
        });

        resetPagination();

        attachPaginationHandler();
      }

      var resetPagination = function () {
        $('.activePagination').removeClass('activePagination');
        $('.page:contains("1")').each(function() {
          if ($(this).text() == 1) {
            $(this).addClass('activePagination');
          }
        });
      }

      var attachPaginationHandler = function () {
        var page;
        var target;
        $('.page').on('click', function () {
          if (mobileUser()) {
            target = $(this).data('page');
            if (target >= 1 && target <=10) {
            $('.page.next').data('page', target + 1);
            $('.page.prev').data('page', target - 1);
              executeSearch(target);
            }
          } else {
            if ($(this).hasClass('next')) {
              if (!$('.activePagination').next().hasClass('next')) {
                target = $('.activePagination').next();
              }
            } else if ($(this).hasClass('prev')) {
              if (!$('.activePagination').prev().hasClass('prev')) {
                target = $('.activePagination').prev();
              }
            } else {
              target = this;
            }

            if (target) {
              $('.activePagination').removeClass('activePagination');
              $(target).addClass('activePagination');
              page = +($(target).text());
              executeSearch(page);
            }
          }
        });
      }

      var attachFilterHandler = function () {
        var filter;

        $('.search-filter a').on('click', function () {
          switch ($(this).text()) {
            case 'Documentation':
              filter = 'docs';
              break;
            case 'Apigee Community':
              filter = 'community';
              break;
            case 'Apigee Blog':
              filter = 'blog';
              break;
          }
          resetPagination();
          executeSearch(null, filter);
        });
      }

      var insertSearchOverlays = function () {
        $('.main-container').each(function() {
          $(this).before('<div class="search-overlay"></div>');
          $(this).before('\
              <div class="search-window">\
                <div class="search-dismiss">&times;</div>\
                <h3>Search Results</h3>\
                <div class="searchResults-wrapper">\
                  <div class="search-results"></div>\
                </div>\
                <div class="search-filter">\
                  <h4>Filter Search</h4>\
                  <ul>\
                    <li><a>Documentation</a></li>\
                    <li><a>Apigee Community</a></li>\
                    <li><a>Apigee Blog</a></li>\
                  </ul>\
                </div>\
              </div>');
        });
        $('body').css('overflow-y', 'hidden');
        attachDismissHandler();
        attachFilterHandler();
      }

      var attachEnterKeySearchHandler = function () {
        $(document).keypress(function(event){
          var keyCode = (event.keyCode ? event.keyCode : event.which);
          if(keyCode == '13' && $('.supportSearch').is(':focus')){
            executeSearch();
          }
        });
      }

      var detachEnterKeySearchHandler = function () {
        $(document).off('keypress');
      }

      var attachDismissHandler = function () {
        $('.search-overlay, .search-dismiss').on('click', function() {
          attachEnterKeySearchHandler();
          $('body').removeAttr('style');
          $('input.supportSearch').val('');
          $('.search-overlay, .search-window').remove();
        });
      }

      var parseSiteFromURL = function (url) {
        var site;
        if (url.indexOf('/docs/') > 0) {
          site = 'Apigee Documentation';
        } else if (url.indexOf('community.apigee.com') > 0) {
          site = 'Apigee Community';
        } else if (url.indexOf('blog.apigee.com') > 0) {
          site = 'Apigee Blog';
        }
        return site;
      }

      var appendSiteToTitle = function (title, site) {
        if (title.match(/\s[\-\|]\sApigee.+$/)) {
          title = title.replace(/\s[\-\|]\sApigee.+$/, ' | ' + site);
        } else if (title.match(/\.\.\.$/)) {
          title = title + ' | ' + site;
        }
        return title;
      }

      var truncateUrl = function (url) {
        if (url.length > 75) {
          url = url.substring(0, 75) + '&#8230;';
        }
        return url;
      }

      includeSupportSearch();
    }
  };

  Drupal.behaviors.apigeeCustomersFrontBlock = {
    attach: function(context) {
      var $window = $(window);
      var $view = $('.view-customers-front', context);
      var $footer = $view.find('.view-footer');

      $footer
        .bind('widefit', function() {
          $footer.css({
            'margin-left': 0,
            'margin-right': 0,
          });
          var wWidth = $window.width();
          var fWidth = $footer.width();
          var mLeft = Math.floor((wWidth - fWidth) / 2);
          var mRight = (wWidth - fWidth) - mLeft;

          $footer.css({
            'margin-left': -1 * mLeft + 'px',
            'margin-right': -1 * mRight + 'px',
          });
        })
        .trigger('widefit');

      $window.bind('resize', function() {
        $footer.trigger('widefit');
      });
    }
  };

  // Solutions
/*
  Drupal.behaviors.apigeeSolutions = {
    attach: function (context, settings) {
      $('.view-solutions .field-name-body,.view-solutions .field-name-field-cv-customer,.view-solutions .field-name-field-cv-customer,.field-collection-container,.view-solutions .field-name-field-customer-feature-text,.view-solutions .field-name-field-customer-text,.view-solutions .field-name-field-customer-story').addClass('col-sm-8');
      $('.view-solutions .field-name-field-datasheet-pdf,.view-solutions .field-name-field-resources-links,.solutions .field-name-field-resources,.view-solutions .field-name-field-solution-video').addClass('col-sm-4');
      $('.view-solutions .field-name-field-datasheet-pdf a').addClass('paper-work-icon');
      $('.solutions-links').insertAfter('.field-name-body');
      $('.solutions-video-slideshow').insertAfter('.field-name-field-cv-customer');
      if ($('.view-solutions .field-collection-container').find('.field-name-field-customer-feature-text') || $('.view-solutions .field-collection-container').find('.field-name-field-customer-text')) {
        $(this).removeClass('col-sm-8').addClass('col-sm-4');
      }
      $('.view-solutions .field-label').each(function() {
        $(this).text($(this).text().replace(/\:/g,''));
      });
      $('.solutions .field-name-field-cv-customer .node h2 a,.view-solutions .field-name-field-customer-story .node h2 a').text('Read more');
    }
  };
*/

  var ticToc = function() {
      var sudoToc = ($("nav.about-apigee-navigation").length > 0) ? $("nav.about-apigee-navigation ul").first() : false;
      if (sudoToc) {
          $(sudoToc).attr({"id":"toc", "class":""});
      }
      var thisSection = ($(".field-name-field-section").length > 0) ? $(".field-name-field-section").first() : false;
      var isResources = (!thisSection && $("body").first().hasClass("resources"));
      var isPress = (!thisSection && $("body").first().hasClass("press"));
      var thisToc = ($("#toc").length > 0) ? $("#toc") : false;
        if (isResources || isPress) {
            thisSection = ($(".region-content").length > 0) ? $(".region-content").first() : false;
        }
      if (thisSection) {
          var sectionItems;
          if (isResources) {
            sectionItems = $(thisSection).find(".view-resources-updated");
          } else if (isPress) {
            sectionItems = $(thisSection).find(".view-press-page-elements");
          } else {
            sectionItems = $(thisSection).find(".entity-field-collection-item");
          }
          if (!thisToc && ($(sectionItems).length > 1)) {
                var tocTarget = (isResources || isPress) ? $(thisSection).closest("section") : $(thisSection).closest(".node-structured-page").find(".content").first();
              $(tocTarget).prepend('<ul id="toc" class="row-fluid"></ul>');
              //$('<ul id="toc" class="row-fluid"></ul>').insertBefore(thisSection);
              thisToc = $("#toc");
          }
          if (thisToc) {
             if ($(sectionItems).length > 6) $(thisToc).addClass("toc-full");
              $(sectionItems).each(function(section_index) {
                  var sectionId = "section_"+section_index;
                  if ($("#"+sectionId).length === 0) {
                      $(this).attr("id", sectionId);
                      var sectionTitle = $(this).find(".section_title").first().text();
                      $(thisToc).append('<li><a href="#'+sectionId+'">'+sectionTitle+'</a></li>');
                    }
              });
        }

      }
      if (thisToc) {
            var thisPost = $("#block-views-apigee-blog-posts-block") || false;
          var fixToc = function() {
              var navBottom = 54;
              var tocTop = false;
              $(window).scroll(function(event) {
                  if (!tocTop) {
                      tocTop = $("#toc").offset().top;
                      var parentWidth = $(thisToc).parent().css("width");
                      $(thisToc).css({"width":parentWidth, "top":navBottom+"px"});
                  }
                  var tocScroll = (($(window).scrollTop() + navBottom) - tocTop);
                  if (tocScroll > 0) {
                      $(thisToc).addClass("scrolling");
                      if (thisPost) $(thisPost).addClass("scrolling");
                  } else {
                      $(thisToc).removeClass("scrolling");
                      if (thisPost) $(thisPost).removeClass("scrolling");
                  }
              });
          }();
          var scrollOffset = ($(thisToc).outerHeight(true) + $("#navbar").outerHeight(true)) * -1;
          $(thisToc).find("a").click(function(event) {
              event.preventDefault();
              var extraOffset = ($(thisToc).hasClass("scrolling")) ? scrollOffset : scrollOffset - $(thisToc).outerHeight(true);
              var thisTarget = $(this).attr("href");
              $("html, body").animate({scrollTop: ($(thisTarget).offset().top + extraOffset)}, "slow");
              return false;
          });
      }
  }

  var goForm = function() {
    var urlEngine = new UrlBox();
    $("form.ctools-auto-submit-full-form, form.ctools-auto-submit-processed").find("input, select").on("change keypress", function(event) {
        urlEngine.setCurrentParam($(this).attr("name"), $(this).val());
    });
    $("form.ctools-auto-submit-full-form .bef-select-as-links a, form.ctools-auto-submit-processed .bef-select-as-links a").unbind("click").click(function(event) {
        var parentParamArray = $(this).parent().attr("id").split("-");
        parentParamArray.shift();
        var parentValue = parentParamArray.pop();
        var parentKey = parentParamArray.join("-");
        urlEngine.setCurrentParam(parentKey, parentValue);
        location.reload();
        return false;
    })
  }

  var breakWidth = function() {
      var pixelWidth = $(document).width();
      var containerWidth = $(".main-container").first().outerWidth() - 30;
      var marginBreak = Math.floor((pixelWidth - containerWidth) / 2) + "px";
      $(".width_break, .width-break").each(function() {
        $(this).css({
            "marginLeft" : "-"+marginBreak,
            "marginRight" : "-"+marginBreak
        });
        if ($(this).hasClass("padIn")) {
            $(this).css({
                "paddingLeft" : marginBreak,
                "paddingRight" : marginBreak,
                "width" : pixelWidth + "px"
            });
        }
      });
  }


  /** Global functions. */
  var goGlobal = function() {
        var isMobile = ($(".navbar-toggle").css("display") === "block");
        if (isMobile) {
            $("#_BH_frame").css({"display" : "none", "visibility" : "hidden"}).remove();
        } else {
        breakWidth();
        $(window).resize(function() {
             breakWidth();
          });
        $("#block-views-trending-tags-block .view-content a, .node-type-blog-content .field-name-field-keywords a").each(function() {
            var thisHref = $.trim($(this).text().toLowerCase()).split(" ").join("-");
            $(this).attr("href", "/about/blog/taglist/"+thisHref);
        });
        $("body.node-type-blog-content, body.page-blog-taglist, body.page-blog, body.blog").each(function() {
            if (!$(this).hasClass("has-subnav")) {
                var iconMap = {
                    "engineering" : "server",
                    "digital-business" : "bar-chart",
                    "technology" : "cogs",
                    "developer" : "terminal"
                }
                var blogLinks = ["Digital Business", "Developer", "Technology", "Engineering"];
                var allLength = (blogLinks.length + 1);
                var colNum = Math.floor(12 / allLength);
                var masterClass = ((colNum * allLength) !== 12) ? " col-md-offset-1" : "";
                var colClass = "col-md-"+colNum;
                var subNav = '<div id="blog-sub-nav"><div class="container"><a href="/about/blog" class="'+colClass+masterClass+'"><i class="fa fa-home"></i>Home</a>';
                for (var i=0; i<blogLinks.length; i++) {
                    var thisText = blogLinks[i];
                    var thisId = thisText.toLowerCase().split(" ").join("-");
                    var iconClass = (iconMap.hasOwnProperty(thisId)) ? iconMap[thisId] : "pencil";
                    var subHref = "/about/blog/" + thisId;
                    var pathClass = (subHref === window.location.pathname) ? " active" : "";
                    subNav += '<a href="'+subHref+'" class="'+thisId+' '+colClass+pathClass+'"><i class="fa fa-'+iconClass+'"></i>'+thisText+'</a>';
                }
                subNav += "</div></div>";
                $("#navbar").append(subNav);
                if (($("#blog-sub-nav .container a.active").length === 0) && $("body").hasClass("node-type-page")) $("#blog-sub-nav .container a").first().addClass("active");
                $("body").addClass("has-subnav");
            }
        });
        }
        $("body.page-partners-partners-list").each(function() {
            var categoryList = ["all", "strategic", "consulting", "technology"];
            $(this).find(".isotope-element").each(function() {
                var that = $(this);
                $(this).find("a").click(function(event) {
                    document.location.href = $(this).attr("href");
                    return false;
                });
                var partnerLink = $(this).find(".partner-link a");
                var partnerUrl = ($(partnerLink).length > 0) ? $(partnerLink).attr("href") : false;
                if (partnerUrl) $(that).css("cursor", "pointer").click(function(event) {
                    window.open(partnerUrl);
                    return false;
                });
                var thisCategoryList = $(this).attr("data-category").split(" ");
                for (var i=0; i<thisCategoryList.length; i++) {
                    var thisCategory = $.trim(thisCategoryList[i].toLowerCase());
                    if ((thisCategory !== "") && ($.inArray(thisCategory, categoryList) === -1)) categoryList.push(thisCategory);
                }
            });
            var activeCat = "";
            var hashString = document.location.hash;
            if (hashString.length > 0) {
                hashString = $.trim(hashString.substr(1));
                if (($.inArray(hashString, categoryList) !== -1)) activeCat = hashString;
            }
            for (var i=0; i<categoryList.length; i++) {
                var thisCategory = categoryList[i];
                var activeString = (thisCategory === activeCat) ? ' class="active"' : "";
                $("#category-navigation").append('<li><a href="#"'+activeString+' title="'+thisCategory+'" data-category="'+thisCategory+'">'+thisCategory+'</a></li>');
            }
            $("#category-navigation a").click(function(event) {
                $(this).closest("ul").find("a").removeClass("active");
                $(this).addClass("active");
                var rawCategory = $(this).attr("data-category");
                var thisCategory = (rawCategory === "all") ? "*" : "."+rawCategory;
                $("#isotope-container").isotope({filter:thisCategory});
                document.location.hash = rawCategory;
                return false;
            });
            if (activeCat !== "all") $("#category-navigation").find("a[data-category="+activeCat+"]").click();
        });
      $("body.apigee").parent().find("title").first().text("About Us | Apigee");
      $("body.blog").each(function() {
          $(this).find(".view-display-id-featured_posts_block").each(function() {
              $(this).find(".views-row").each(function() {
                var hasCategory = false;
                $(this).find(".views-field-field-cateogory, .views-field-field-category").each(function() {
                    hasCategory = $(this).find(".field-content").first().text();
                    hasCategory = $.trim(hasCategory.toLowerCase()).split(" ").join("-");
                });
                if (hasCategory) {
                    $(this).css("cursor","pointer").click(function() {
                        document.location.href = "../blog/"+hasCategory;
                        return false;
                    });
                }
                $(this).find("a").click(function(event) {
                    document.location.href = $(this).attr("href");
                    return false;
                });
              });
          });
      });
      $("body.node-type-blog-content").each(function() {
          var thisTitle = $(this).find(".field-name-dynamic-title h2").text();
          var crumbLength = 30;
          if (thisTitle.length > crumbLength) {
            var theElip = "...";
            crumbLength -= theElip.length;
            var tempText = thisTitle.substr(0, crumbLength);
            var lastSpace = tempText.lastIndexOf(" ");
            var trimmedText = (lastSpace !== -1) ? tempText.substr(0, lastSpace) : tempText;
            thisTitle = trimmedText + theElip;
          }
          var thisPath = document.location.pathname.split("/").pop();
          var thisIndex = false;
          var postLinks = [];
          $(this).find("#block-views-blog-assets-blog-post-list").each(function() {
              postLinks = $(this).find(".view-content .views-row .views-field-title .field-content a");
              $(postLinks).each(function(index) {
                  var tempPath = $(this).attr("href").split("/").pop();
                  if (tempPath === thisPath) {
                      thisIndex = index;
                      return false;
                  }
              });
          });
          if (thisIndex || (thisIndex === 0)) {
            var linkString = '<div class="prevNextLinks topLinks"><div class="col-md-6 prevLink"></div><div class="col-md-6 nextLink"></div></div>';
            $(".field-name-dynamic-title").before(linkString);
            if (thisIndex > 0) {
                $(".prevNextLinks div").first().html($(postLinks[thisIndex - 1]));
            }
            if (thisIndex < (postLinks.length - 1)) {
                $(".prevNextLinks div").last().html($(postLinks[thisIndex + 1]));
            }
            $(".prevNextLinks").clone(true).appendTo("#block-system-main");
            $(".prevNextLinks").last().removeClass("topLinks").addClass("bottomLinks");
            $(".prevNextLinks .prevLink a").addClass("prevLink");
            $(".prevNextLinks .nextLink a").addClass("nextLink");
          }
          var blogCategories = [];
          $(this).find(".field-name-field-cateogory, .field-name-field-category").each(function() {
              var thisLink = $(this).find("a").first();
              var thisText = $.trim($(thisLink).text());
            var linkText = thisText.toLowerCase().split(" ").join("-");
            var linkHref = "/about/blog/"+linkText;
            $(thisLink).attr("href", linkHref);
            blogCategories.push({
                text : thisText,
                href : linkHref,
                class : linkText
            });
            var linkParent = $(thisLink).closest("div");
            $(linkParent).append('<a href="#">'+thisTitle+'</a>').prepend('<a href="/about/blog">Blog</a>');
            $("#blog-sub-nav a").each(function() {
                if ($(this).attr("href") === linkHref) $(this).addClass("active");
            });
          });
          $(this).find(".field-name-field-secondary-category").each(function() {
                var thisLink = $(this).find("a").first();
                var thisText = $.trim($(thisLink).text());
                var linkText = thisText.toLowerCase().split(" ").join("-");
                var linkHref = "/about/blog/"+linkText;
                var addLink = true;
                for (var i=0; i<blogCategories.length; i++) {
                    if (blogCategories[i]["class"] === linkText) addLink = false;
                }
                if (addLink) { blogCategories.push({
                        text : thisText,
                        href : linkHref,
                        class : linkText
                    });
                }
          });
          if (blogCategories.length > 0) {
              var postingLinks = '<div class="postingCategories"><h2>Posted In</h2><ul>';
              for (var i=0; i<blogCategories.length; i++) {
                  var thisCategory = blogCategories[i];
                  postingLinks += '<li><a href="'+thisCategory.href+'" class="'+thisCategory.class+'">'+thisCategory.text+'</a></li>';
              }
              postingLinks += '</ul></div>';
              $(".node-blog-content").after(postingLinks);
          }
          $(this).find(".name_or_screen_name").each(function() {
              var author_name = $(this).find(".author_name").text();
              var screen_name = $(this).find(".screen_name").text();
              var twitter_handle = $(this).find(".twitter_handle").text();
              author_name = $.trim(author_name);
              screen_name = $.trim(screen_name);
              twitter_handle = $.trim(twitter_handle);
              var clean_screen = (screen_name === "") ? author_name : screen_name;
              var clean_handle = (twitter_handle === "") ? "" : ' (<a href="http://twitter.com/'+twitter_handle+'" target="_blank">@'+twitter_handle+'</a>)';
              $(".field-name-creator").find(".field-item").first().html(clean_screen+clean_handle);
          });
      });
      $("table.group-table-wrapper").each(function() {
          $(this).find("tr.field-name-field-table-head, tr.field-name-field-table-footer").prepend("<td>&nbsp;</td>");
          $(this).find(".field-name-field-tooltip").each(function() {
            var tooltipContent = $(this).find(".field-item").first().text();
            var prevElement = $(this).prev().find(".field-item").last();
            $(prevElement).append('<i class="fa fa-info-circle" title="'+tooltipContent+'"></i>').find("i").tooltip({"placement":"right"});
          });
          var rowsToShow = 0;
          var bodyRows = $(this).find("tr").not(".field-name-field-table-head, .field-name-field-table-footer");
          var specifiedRows = $(this).closest("body").find(".field-name-field-rows-to-show");
          if (specifiedRows.length > 0) {
              var rawSpec = $(specifiedRows).find(".field-item").first().text();
              rowsToShow = parseInt(rawSpec);
          }
          var firstRow = $(bodyRows)[0];
          var lastIndex = (rowsToShow > 0) ? rowsToShow : $(bodyRows).length;
          var lastRow = $(bodyRows)[lastIndex - 1];
          var rowCells = $(lastRow).find("td");
          if ((rowsToShow > 0) && (bodyRows.length > rowsToShow)) {
            $(bodyRows).each(function(index) {
               if (index >= rowsToShow) {
                   $(this).css("display","none").addClass("forceHide");
               }
            });
            var emptyCells = "";
            for (var i=1; i<rowCells.length; i++) {
                emptyCells += '<td>&nbsp;</td>';
            }
            $(lastRow).after('<tr><td class="moreLink"><a href="#">Show Full List <strong>+</strong></a></td>'+emptyCells+'</tr>');
            $("table.group-table-wrapper .moreLink a").unbind("click").click(function(event) {
                $(this).closest("table").find("tr").not(".field-name-field-table-head, .field-name-field-table-footer").removeClass("forceHide").slideDown("slow");
                $(this).closest("tr").remove();
                return false;
            });
          }
          if (isMobile) {
              $(this).closest("div.col-sm-12").removeClass("col-sm-12");
              $(this).find("tr").find("td:gt(1), th:gt(0)").hide();
              $(this).find("tr").find("td:gt(0), th").addClass("targetedCol");
              $(this).find("td").css({"width":"50%","white-space":"normal"});
              $(this).attr("data-current_col", 1);
              var emptyCells = "";
              var controlDisks = '<i class="fa fa-circle" data-disk_anchor="1"></i>';
              for (var i=2; i<rowCells.length; i++) {
                  emptyCells += '<td class="forceHide"></td>';
                  controlDisks += '<i class="fa fa-circle-thin" data-disk_anchor="'+i+'"></i>';
              }
              var controlRow = '<tr class="controlRow"><td>&nbsp;</td><td><a href="#" class="prevArrow">&lsaquo;</a><a class="nextArrow" href="#">&rsaquo;</a><span>'+controlDisks+'</span></td>'+emptyCells+'</tr>';
              $(".field-name-field-table-head").before(controlRow);
              $(".field-name-field-table-footer").after(controlRow);
              $(this).find("tr.controlRow i").click(function(event) {
                  var targetCol = $(this).attr("data-disk_anchor");
                  var parentTable = $(this).closest("table");
                  $(parentTable).find("tr.controlRow i").each(function() {
                      var tempCol = $(this).attr("data-disk_anchor");
                      if (tempCol !== targetCol) {
                          $(this).removeClass("fa-circle").addClass("fa-circle-thin");
                      } else {
                          $(this).removeClass("fa-circle-thin").addClass("fa-circle");
                      }
                  });
                  var intCol = parseInt(targetCol);
                  var intHead = targetCol - 1;
                  $(parentTable).find("tr").not(".controlRow").each(function() {
                      $(this).find("td:gt(0), th").hide();
                      $(this).find("td:eq("+intCol+"), th:eq("+intHead+")").show();
                    });
              });
              $(this).find("tr.controlRow a").click(function(event) {
                    var controlCell = $(this).closest("td");
                    var currentCol = $(controlCell).find("i.fa-circle").first().attr("data-disk_anchor");
                    var prevNext = $(this).hasClass("prevArrow") ? -1 : 1;
                    var nextCol = parseInt(currentCol) + prevNext;
                    var lastCol = $(controlCell).find("i").last().attr("data-disk_anchor");
                    lastCol = parseInt(lastCol);
                    if (nextCol < 1) {
                        nextCol = lastCol;
                    } else if (nextCol > lastCol) {
                        nextCol = 1;
                    }
                    $(controlCell).find("i[data-disk_anchor="+nextCol+"]").click();
                  return false;
              });
            }
      });
      $(".menu li.dropdown").hover(function(event) {
          var theSubmenu = $(this).find("ul.dropdown-menu").first();
          if ($(theSubmenu).css("display") !== "block") {
              $(theSubmenu).show();
          } else {
              $(theSubmenu).hide();
          }
      });
      $("body.page-products .view-product-picker").each(function() {
            $(this).find(".view-content .row > .col").css({"cursor":"pointer"}).click(function(event) {
                document.location.href = $(this).find("a").first().attr("href");
                return false;
            });
      });
      $("body.node-type-product-page").each(function() {
          var isResourceView = ($(".view-mode-product-resources-full").length > 0);
          if (isResourceView) $("body").first().addClass("view-mode-product-resources-full");
          var iconMap = {
              "ebook" : "file-book",
              "whitepaper" : "file-pdf-o",
              "datasheet" : "file-pdf-o",
              "video" : "video-camera",
              "webinar" : "video-camera",
              "screencast" : "video-camera",
              "internal_link" : "link",
              "blog_post" : "pencil",
              "blogpost" : "pencil",
              "pdf" : "file-pdf-o",
              "outbound" : "external-link",
              "image" : "picture-o",
              "external_link" : "external-link",
              "article" : "comment",
              "contact" : "envelope-o",
              "webcast" : "video-camera",
              "webcase" : "link"
          }
          $(this).find(".field-name-field-datasheet-link").each(function() {
              var datasheetLink = $(this).find("a");
              datasheetLink = (datasheetLink.length > 0) ? datasheetLink[0] : false;
              if (datasheetLink) {
                  var popWin = $(datasheetLink).attr("target") || false;
                  popWin = (popWin && (popWin === "_blank"));
                  $(".field-name-field-lifecycle-graphic img").css("cursor", "pointer").attr({"data-link" : $(datasheetLink).attr("href"), "data-popwin" : popWin}).click(function(event) {
                      if ($(this).attr("data-popwin") === "true") {
                          window.open($(this).attr("data-link"));
                      } else {
                          document.location.href = $(this).attr("data-link");
                      }
                      return false;
                  });
              }
          });
          $(this).find(".field-name-field-article-cta-link").each(function() {
              var ctaLink = $(this).find("a");
              ctaLink = (ctaLink.length > 0) ? ctaLink[0] : false;
              if (ctaLink) {
                  var popWin = $(ctaLink).attr("target") || false;
                  popWin = (popWin && (popWin === "_blank"));
                  $(".field-name-field-page-header-image img").css("cursor", "pointer").attr({"data-link" : $(ctaLink).attr("href"), "data-popwin" : popWin}).click(function(event) {
                      if ($(this).attr("data-popwin") === "true") {
                          window.open($(this).attr("data-link"));
                      } else {
                          document.location.href = $(this).attr("data-link");
                      }
                      return false;
                  });
              }
          });
          $(this).find(".field-collection-item-field-pane .field-name-field-media-video, .field-collection-item-field-testimonial .field-name-field-testimonial-video").each(function() {
              var targetIframe = $(this).find("iframe").first();
              var frameWidth = $(targetIframe).outerWidth(true);
              var newHeight = Math.ceil((frameWidth / 16) * 9);
              $(targetIframe).css({"min-height" : newHeight+"px"});
          });
          $(this).find(".field-name-field-button-type, .field-name-field-link-type").each(function() {
            var buttonTypeRaw = $(this).find(".field-item").text();
            var buttonType = $.trim(buttonTypeRaw).replace(/\s+/g,"_").toLowerCase();
            var iconClass = (iconMap.hasOwnProperty(buttonType)) ? iconMap[buttonType] : iconMap["link"];
            $(this).closest(".content").find(".field-name-field-button-link a, .field-name-field-point-link a, .field-name-field-link-information a").prepend('<i class="fa fa-'+iconClass+'"></i>');
          });
          if (!isMobile) {
            $(this).find(".field-name-field-proof-points > .field-items > .field-item, .field-name-field-product-customer-story > .field-items > .field-item").each(function() {
                 var sibLength = $(this).siblings(".field-item").length + 1;
                 if (sibLength !== 3) {
                     var sibWidth = Math.floor(100 / sibLength);
                     $(this).css("width", sibWidth + "%");
                 }
              });

        $(this).find(".group-proofheader").hover(function() {
            $(this).closest(".field-name-field-proof-points").find(".group-differentiator").slideDown("slow");
        });
        $(this).find(".field-name-field-create-resource-link").each(function() {
            var makeButton = ($(this).find(".field-item").first().text() == 1);
            if (makeButton) {
                var buttonContainer = $(this).closest(".field-collection-item-field-product-section").find(".field-name-field-buttons").first().find(".field-items").first();
                $(buttonContainer).append('<div class="field-item"><a href="'+document.location.href+'?v=product_resources"><i class="fa fa-link"></i>View resources</a></div>');
            }
        });
              //dynamic nav
        if (!isResourceView) {
          var navOrder = [];
          var navItems = {};
          $(this).find(".field-collection-item-field-product-section").each(function() {
            var sectionId = "section_"+$(this).attr("about").split("/").pop();
            navOrder.push(sectionId);
            $(this).attr({"id":sectionId,"name":sectionId});
            var sectionName = $(this).find(".field-name-field-section-identifier").first().find(".field-item").first().text();
            navItems[sectionId] = sectionName;
          });
          var navLinks = "";
          for (var i=0; i<navOrder.length; i++) {
              var thisItem = navOrder[i];
            navLinks += '<li><a href="#'+thisItem+'">'+navItems[thisItem]+'</a></li>';
          }
          navLinks = '<div id="product_side_nav"><ul class="nav">'+navLinks+'</ul></div>';
          $("#product_side_nav").remove();
          $("body").append(navLinks).scrollspy({target: "#product_side_nav", offset: 80}).on('activate.bs.scrollspy', function() {$(this).data('bs.scrollspy').refresh()});
          $("#product_side_nav a").click(function(event) {
                var scrollTargetId = $(this).attr("href");
                console.log(scrollTargetId);
                var scrollTargetTop = ($(scrollTargetId).offset().top) - 70;
                console.log(scrollTargetTop);
                $("html, body").animate({scrollTop: scrollTargetTop}, "slow");
                return false;
            });
          } else {
              $("h2 a").each(function() {
                  var titleText = $(this).text();
                  $(this).append(" Overview");
                  $(this).closest("h2").prepend(titleText+" Resources");
              });
              //$("h2 a").append(" Resources");
            $(".field-name-field-video-resources a").prepend('<i class="fa fa-video-camera"></i>');
            $(".field-name-field-pdf-resources a").prepend('<i class="fa fa-file-pdf-o"></i>');
            $(".field-name-field-blog-posts a").prepend('<i class="fa fa-pencil"></i>');
            $(".field-name-field-ebooks a").prepend('<i class="fa fa-book"></i>');
            $(".field-name-field-press-articles a").prepend('<i class="fa fa-comment"></i>');
            $(".field-name-field-links a").prepend('<i class="fa fa-external-link"></i>');
          }
          }

      }); //end product page
      $(".view-homepage-slideshow .view-footer").click(function(event) {
        document.location.href = $(this).find("a").attr("href");
          event.preventDefault;
          event.stopPropagation();
      });
      $(".page-front-page .view-mini-ctas .views-row a").click(function(event) {
            $(this).closest(".views-row").attr("data-bubbleclick", "true");
      });
      $(".page-front-page .view-mini-ctas .views-row").click(function(event) {
          if ($(this).attr("data-bubbleclick") === "true") {
              $(this).attr("data-bubbleclick", "false");
          } else {
               var targetLink = $(this).find(".views-field-field-minicta-link a").first();
               $(targetLink).click();
               document.location.href = $(targetLink).attr("href");
            }
      });
      $("body.events #block-views-events-block-1 .views-row").click(function(event) {
          document.location.href = $(this).find(".views-field-field-cta-read-more-link a").attr("href");
          event.preventDefault;
          event.stopPropagation();
      });
      $(".menu li.dropdown a.dropdown-toggle").click(function(event) {
          document.location.href = $(this).attr("href");
      });
      if (!isMobile) $(".menu a.js-addicon").html("").closest("li").addClass("floatright");
      $(".menu a").each(function() {
          var thisClass = $(this).attr("class") || "";
          thisClass = thisClass.split(" ");
          var addParentClass = false;
          forEach(thisClass, function(thisClassName) {
              if (thisClassName.indexOf("js-addParentClass") === 0) {
                addParentClass = thisClassName.split("_")[1];
                return false;
              }
          });
          if (addParentClass) $(this).parent().addClass(addParentClass);
      });
      //js-addParentClass_signinNav
      $(".dropdown .dropdown-menu li a").each(function() {
          $(this).unbind("touchstart click").bind("touchstart click", function(event) {
             document.location.href = $(this).attr("href");
             event.stopPropagation();
             return false;
          });
      });

      $(".menuparent ol").mouseover(function() {
          $(this).closest("ul").closest("li").addClass("temp-active-trail");
      }).mouseout(function() {
          $(this).closest("ul").closest("li").removeClass("temp-active-trail");
      });

      $(".node-type-solution .field-name-field-cs-customer .field-name-field-customer-logo a, .solutions .field-name-field-cs-customer .field-name-field-customer-logo a").each(function() {
          var linkHref = $(this).attr("href");
          var newLink = '<a href="'+linkHref+'" class="customer-logo-story">read their story</a>';
          $(this).closest("div").prepend(newLink);
      });
      $(".node-type-solution .field-name-field-more-company-stories .node-customer-story, .solutions .field-name-field-more-company-stories .node-customer-story").click(function(event) {
          document.location.href = $(this).find(".field-name-field-customer-logo a").first().attr("href");
          return false;
      });

      $(".resources .view-resources-updated ul.pagination a").unbind("click").click(function(event) {
          document.location.href = $(this).attr("href");
          event.preventDefault();
          event.stopPropagation();
          return false;
      });

      $(".press-releases .panel-title a.accordion-toggle").each(function() {
          var dateSplit = $(this).text().split("||");
          console.log(dateSplit.length);
          console.log(dateSplit);
          var dateString = '<span class="pr_titleDate">'+dateSplit[0]+'</span>';
          var titleString = '<span class="pr_titleTitle">'+dateSplit[1]+'</span>';
          $(this).html(dateString+titleString);
      });

      var showLength = function(inputId, maxLength) {
            maxLength = parseInt(maxLength);

            var charsRemaining = (maxLength - $("#"+inputId).val().length);

            var thisLabel = $("label[for='"+inputId+"']");
            $(thisLabel).append('<br />(<span class="characterWarning">'+charsRemaining+'</span> characters remaining)');


            $("#"+inputId).keydown(function() {
                var charsRemaining = (maxLength - $(this).val().length);
                var inputId = $(this).attr("id");
                $("label[for='"+inputId+"']").find("span.characterWarning").first().text(charsRemaining);
            });
        }
      $("input, textarea, select").each(function() {
            var thisClassName = $(this).attr("class") || false;
            var thisId = $(this).attr("id") || false;
            if (thisClassName && thisId) {
                var classArray = thisClassName.split(" ");
                for (var i=0; i<classArray.length; i++) {
                    var thisClass = classArray[i];
                    if (thisClass.indexOf("js_maxlength") !== -1) showLength(thisId, thisClass.split("_").pop());
                }
            }

        });

        $("body.customer-story").each(function() {
            var targetClassPrefix = "page-node-";
            var classList = $(this).attr("class").split(" ");
            var nodeId = false;
            for (var i=0; i<classList.length; i++) {
                var thisClass = classList[i];
                if (thisClass.indexOf(targetClassPrefix) === 0) nodeId = thisClass.substring(targetClassPrefix.length);
            }
            if (nodeId) {
                var parentItem = $(".js_cs_"+nodeId).parent();
                var parentContainer = $(parentItem).parent();
                $(parentItem).remove();
                if ($(parentContainer).children().length <= 0) $(parentContainer).closest("section").remove();
            }
            $(this).find(".col-sm-4 .field-name-field-video").each(function() {
                $(this).css({"width":$(this).next().innerWidth()});
            });
            $(this).find(".isotope-element").each(function() {
                if ($(this).children().hasClass("views-field-field-customer-featured")) {
                    $(this).addClass('has-featured');
                }
            });
        });

      $(".field-name-field--productoffering-image img").each(function() {
          var sibLink = $(this).closest(".row").find(".field-name-field--productoffering-link").first().find("a").first() || [];
          var sibHref = (sibLink.length > 0) ? $(sibLink).attr("href") : false;
          $(this).css({"cursor":"pointer"}).click(function(event) {
              document.location.href = sibHref;
          });
      });
      $(".field-collection-item-field-product-feature .field-name-field-prod-feat-intro-image img").each(function() {
          var sibLink = $(this).closest(".row").find(".learn-more-link").first().find("a").first() || [];
          var sibHref = (sibLink.length > 0) ? $(sibLink).attr("href") : false;
          $(this).css({"cursor":"pointer"}).click(function(event) {
              document.location.href = sibHref;
          });
      });
      $(".file a").each(function() {
          var cleanText = $(this).text().split('__').join(', ').split('_').join(' ').split(".")[0];
          $(this).text(cleanText);
      });
      $(".js_intercap").each(function() {
          var newClass = $(this).text().replace(/\s+/g, '-').toLowerCase().split("+").join("-").split("&").join("").split("--").join("-");
          $(this).addClass(newClass).removeClass("js_intercap");
      });
      $("[data-css]").each(function() {
          var newClass = $(this).attr("data-css").replace(/\s+/g, '-').toLowerCase().split("+").join("-");
          $(this).addClass(newClass).removeAttr("data-css");
      });
      $("[data-href]").each(function() {
          $(this).css({"cursor":"pointer"}).click(function(event) {
              document.location.href = $(this).attr("data-href");
          });
      });
      $(".page-apigee .more-link a").each(function() {
        var thisHref = $(this).attr("href") || false;
         var thisLabel = $(this).closest("div.form-item").find("label").first() || [];
         if (($(thisLabel).length > 0) && thisHref) {
             $(thisLabel).css({"cursor":"pointer"}).attr("data-href", thisHref).click(function(event) {
                 document.location.href = $(this).attr("data-href");
                 return false;
             });
         }
      });
      $(".view-id-events .view-footer h3").each(function() {
          var sibLink = $(this).parent().find("a").first() || [];
          var sibHref = (sibLink.length > 0) ? $(sibLink).attr("href") : false;
          if (sibHref) {
            $(this).css({"cursor":"pointer"}).click(function(event) {
                  document.location.href = sibHref;
              });
            }
      });
      $("#block-views-apigee-blog-posts-block .block-title").each(function() {
          var lastLink = $(this).parent().find("a").last() || [];
          var lastHref = $(lastLink).attr("href") || false;
          if (($(lastLink).length > 0) && lastHref) {
                var splitHref = lastHref.split("//");
                var thisProtocol;
                var thisHref;
                if (splitHref.length > 1) {
                    thisProtocol = splitHref[0];
                    thisHref = splitHref[1];
                } else {
                    thisProtocol = "";
                    thisHref = splitHref[0];
                }
                thisHref = thisProtocol + "//" + thisHref.split("/")[0];
              $(this).css({"cursor":"pointer"}).attr("data-href", thisHref).click(function(event) {
                  document.location.href = $(this).attr("data-href");
                 return false;
              });
          }
      });
      $("body.request-access form, body.request-support form").addClass("form-horizontal").each(function() {
          $(this).find("div.form-item").addClass("form-group").removeClass("webform-container-inline").find("label").addClass("col-sm-4 control-label").parent().find("input, select, textarea").each(function() {
            $(this).addClass("form-control").wrap('<div class="col-sm-8">');
            if ($(this).is("textarea")) $(this).removeAttr("cols").attr("rows", "12").css({"height":"auto"});
        });
          $(this).find(".grippie").remove();
      });
      var thisHash = location.hash || false;
      if (thisHash) {
          $(".views-bootstrap-accordion-plugin-style a.node_anchor").each(function() {
              if (thisHash === "#"+$(this).attr("id")) {
                  var clickId = $(this).closest(".panel-collapse").attr("id");
                  var clickLink = $("a[href='#"+clickId+"']");
                  $(clickLink).click().removeClass("collapsed");
                  $("#"+clickId).addClass("in").css({"height":"auto"});
                  $("html, body").animate({scrollTop: (clickLink.offset().top - 200)}, "slow");
                  return false;
              }
          });
      }
      $(".isotope-element .icons-container a").each(function() {
          var thisHref = $(this).attr("href");
          $(this).closest(".isotope-element").find(".views-field-field-customer-logo").css({"cursor":"pointer"}).attr("data-href", thisHref).click(function(event) {
                  document.location.href = $(this).attr("data-href");
                 return false;
              });
      });
      $(".carousel-inner .item").each(function() {
          var thisLink = $(this).find(".views-field-field-homepage-slide-button").find("a").first() || [];
          var thisHref = $(thisLink).attr("href") || false;
          if (($(thisLink).length > 0) && thisHref) {
              $(this).find("video").css({"cursor":"pointer"}).attr("data-href", thisHref).click(function(event) {
                  document.location.href = $(this).attr("data-href");
                 return false;
              });
          }
      });
      $(".products .field-name-field-prod-cap-image img").css({"cursor":"pointer"}).click(function(event) {
          var lastLink = $(this).closest(".field-item").find("a").last() || [];
          var lastHref = $(lastLink).attr("href") || false;
          if (($(lastLink).length > 0) && lastHref) document.location.href = lastHref;
      });
      $(".tab-pane a").click(function(event) {
          if ($(this).attr("href")) document.location.href = $(this).attr("href");
          return false;
      });
      $(".js-fixHeight").each(function() {
          var parentNode = $(this).parent();
          if (!$(parentNode).hasClass("js-heightHolder")) {
              $(parentNode).addClass("js-heightHolder").attr("data-maxHeight", "0");
          }
          var thisHeight = $(this).innerHeight();
          var topicHeight = $(this).find(".views-field-field-primary-topic");
          topicHeight = ($(topicHeight).length > 0) ? $(topicHeight).find("field-content").outerHeight() : 0;
          console.log(topicHeight);
          thisHeight -= topicHeight;
          var thatHeight = $(parentNode).attr("data-maxHeight");
          if (parseInt(thisHeight) > parseInt(thatHeight)) $(parentNode).attr("data-maxHeight", thisHeight);
          var primaryTopic = $(this).find(".views-field-field-primary-topic");
          primaryTopic = ($(primaryTopic).length > 0) ? $(primaryTopic).find(".field-content").first().text().replace(/\s+/g, '-').toLowerCase().split("+").join("-") : false;
          if (primaryTopic) $(this).addClass("primaryTopicHolder "+primaryTopic);
      });
      $(".js-heightHolder").each(function() {
          var maxHeight = parseInt($(this).attr("data-maxHeight"));
          $(this).find(".js-fixHeight").css("height", maxHeight);
      });
      $(".rollover_summary").each(function() {
          var parentNode = $(this).closest(".views-row");
          $(this).css({"height" : $(parentNode).outerHeight()+"px"});
          $(this).click(function(event) {
                document.location.href = $(this).find("a").first().attr("href");
              return false;
          });
          $(parentNode).click(function(event) {
                document.location.href = $(this).find("a").first().attr("href");
              return false;
          });
      });
      $(".js-resourceDetail").each(function() {
          $(this).css("cursor", "pointer").click(function() {
              document.location.href = $(this).find("a").first().attr("href");
              return false;
          });
      });
        $("#block-views-team-team .field-name-field-team-member-title .field-item").each(function() {
            $(this).text(truncateText($(this).text(), 56, true));
        });
        var thisHash = location.hash || false;
          if (thisHash) {
            $("html, body").animate({scrollTop: 0}, "fast", function() {
                $('a[href="'+thisHash+'"]').first().click();
            });

        }
  }

  /** Form builder and handler. */
    var formEngine;
    var FormBox = function() {
        var that = this;

        this.showLength = function(inputId, maxLength) {
            console.log(inputId);
            var thisDescription = $("#"+inputId).closest(".form-item"); //.find(".description").first();
            console.log(thisDescription);
            $(this).on("focus, change, click", function() {

            });
        }

        var init = function() {
            /** When an input is focused, changed, or clicked, remove the error state and clear any alerts. */
            //$("input, textarea, select").on("focus, change, click", function() {
            $("input, textarea, select").each(function() {
                var thisClassName = $(this).attr("class") || false;
                var thisId = $(this).attr("id") || false;
                if (thisClassName && thisId) {
                    var classArray = thisClassName.split(" ");
                    for (var i=0; i<classArray.length; i++) {
                        var thisClass = classArray[i];
                        if (thisClass.indexOf("js_maxlength") !== -1) that.showLength(thisId, thisClass.split("_").pop());
                    }
                }

            });
        }();
    };

  /** URL handler. */
    var urlEngine;
    var UrlBox = function() {
        var that = this;

        /**
            Set the working URL.
            @param {string} theUrl - the URL to work with.
        */
        this.setUrl = function(theUrl) {
            that.workingUrl = theUrl;
        };

        /**
            Get all parameters from a URL, and return them as an object.
            If a URL is not supplied, use the UrlBox instance's working URL.
            @param {string} [theUrl=workingUrl] - the URL to work with.
            @returns {object} paramObject - the URL parameters.
        */
        this.getParams = function(theUrl) {
            var theUrl = theUrl || that.workingUrl;
            var paramObject = {};
            var urlArray = theUrl.split("?");
            var urlPath = urlArray.shift();
            var urlParams = (urlArray.length > 0) ? urlArray.join("?").split("&") : [];
            forEach(urlParams, function(thisPair) {
                var pairArray = thisPair.split("=");
                var pairKey = pairArray.shift();
                var pairVal = (pairArray.length > 0) ? pairArray.join("=") : null;
                paramObject[pairKey] = pairVal;
            });
            return paramObject;
        };

        /**
            Add params to a URL and return it.
            @param {object} newParams - the parameters/values to add.
            @param {string} theUrl - the URL to work with.
            @returns {string} - the URL with new params.
        */
        this.setParams = function(newParams, theUrl) {
            var theUrl = theUrl || that.workingUrl;
            var oldParams = that.getParams(theUrl);
            forEach(oldParams, function(paramValue, paramKey) {
                if (!newParams.hasOwnProperty(paramKey)) newParams[paramKey] = paramValue;
            });
            theUrl = theUrl.split("?")[0] + "?";
            var paramArray = [];
            forEach(newParams, function(paramValue, paramKey) {
                paramArray.push(paramKey+"="+paramValue);
            });
            return theUrl + paramArray.join("&");
        };

        /**
            Return the value of a given URL param.
            @param {string} paramKey - the parameter key.
            @param {string} theUrl - the URL to work with.
            @returns {string} paramVal - the value of the URL parameter.
        */
        this.getParam = function(paramKey, theUrl) {
            var theUrl = theUrl || that.workingUrl;
            var allParams = that.getParams(theUrl);
            var paramVal = (allParams.hasOwnProperty(paramKey)) ? allParams[paramKey] : false;
            return paramVal;
        };

        /**
            Create/Set the value of a given URL param.
            @param {string} paramKey - the parameter key.
            @param {string} paramValue - the parameter value.
            @param {string} theUrl - the URL to work with.
            @returns {string} - the URL with the new parameter set.
        */
        this.setParam = function(paramKey, paramValue, theUrl) {
            var theUrl = theUrl || that.workingUrl;
            var allParams = that.getParams(theUrl);
            allParams[paramKey] = paramValue;
            return that.setParams(allParams, theUrl);
        }

        /**
            Try to add a new param to the current URL.
            If the attempt fails, refresh the page with the modified URL.
        */
        this.setCurrentParam = function(paramKey, paramValue) {
            var hashSplit = that.workingUrl.split("#");
            var newUrl = that.setParam(paramKey, paramValue, hashSplit[0]);
            newUrl += (hashSplit.length > 1) ? "#"+hashSplit[1] : "";
            try {
                history.pushState({}, "", newUrl);
                that.setUrl(newUrl);
            } catch (e) {
                document.location.href = newUrl;
            }
        }

        /**
            Try to remove a param from the current URL.
            If the attempt fails, refresh the page with the modified URL.
        */
        this.clearCurrentParam = function(paramKey) {
            var newUrl = that.clearParam(paramKey, that.workingUrl);
            try {
                history.pushState({}, "", newUrl);
                that.setUrl(newUrl);
            } catch (e) {
                document.location.href = newUrl;
            }
        }

        /**
            Clear a given URL param.
            @param {string} paramKey - the parameter key.
            @param {string} theUrl - the URL to work with.
            @returns {string} - the URL with the parameter removed.
        */
        this.clearParam = function(paramKey, theUrl) {
            var theUrl = theUrl || that.workingUrl;
            var allParams = that.getParams(theUrl);
            if (allParams.hasOwnProperty(paramKey)) delete allParams[paramKey];
            return that.setParams(allParams, theUrl.split("?")[0]);
        }

        /**
            Get the filename from a given URL; assumes "index.html" if there's no filename in the URL.
            @param {string} [theUrl] - the URL to work with.
            @returns {string} - the file name.
        */
        this.getFilename = function(theUrl) {
            var theUrl = theUrl || that.workingUrl;
            var rawFileName = theUrl.substring(theUrl.lastIndexOf("/") + 1, theUrl.length).split("?")[0].split("#")[0];
            return (rawFileName.length > 0) ? rawFileName : "index.html";
        }

        var init = function() {

            /** Set this instance's working URL to be the document location. */
            that.setUrl(document.location.href);

        }();
    }

    /** Link handler. */
    var linkEngine;
    var LinkBox = function() {
        var that = this;
        this.setClicks = function(theContext) {
            var theContext = theContext || that.workingContext;

            /** If a link has an "addclass" parameter, set the class to that parameter value and remove the parameter. */
            $("a").each(function() {
                var thisHref = $(this).attr("href") || false;
                if (thisHref) {
                    var classParam = urlEngine.getParam("addclass", thisHref);
                    if (classParam) {
                        var newHref = urlEngine.clearParam("addclass", thisHref);
                        $(this).addClass(unescape(classParam)).attr("href", newHref);
                    }
                }
            });

            /** Don't allow disabled links to return. */
            $(theContext+" a").click(function(event) {
                if ($(this).hasClass("disabled")) return false;
            });

            /** Any link with the "js_doPopup" class will open in a new window. */
            $(theContext+" a.js_doPopup").click(function(event) {
                window.open($(this).attr("href"));
                return false;
            });

            /**
                Move url params to session storage params before following the link.
                @see UrlBox.getParams.
            */
            $(theContext+" a.js_storeParams").click(function(event) {
                var thisHref = $(this).attr("href");
                var paramsToStore = urlEngine.getParams(thisHref);
                forEach(paramsToStore, function(paramValue, paramKey) {
                    sessionStorage.setItem(paramKey, paramValue);
                });
                document.location.href = thisHref.split("?")[0];
                return false;
            });

        }

        /**
            Add params to link hrefs.
            @param {object} newParams - the parameters/values to add.
            @param {string} [targetClass] - optional CSS to target; if this param is included, only links bearing the given class will be changed.
            @see UrlBox.setParams.
        */
        this.setLinkParams = function(newParams, targetClass) {
            var targetClass = targetClass || false;
            $("a").each(function() {
                var changeLink = (!targetClass || (targetClass && $(this).hasClass(targetClass)));
                if (changeLink && urlEngine) {
                    var newHref = urlEngine.setParams(newParams, $(this).attr("href"));
                    $(this).attr("href", newHref);
                }
            });
        }

        /**
            Clear param from link hrefs.
            @param {string} paramKey - the parameter key.
            @param {string} [targetClass] - optional CSS to target; if this param is included, only links bearing the given class will be changed.
            @see UrlBox.clearParam.
        */
        this.clearLinkParam = function(paramKey, targetClass) {
            var targetClass = targetClass || false;
            $("a").each(function() {
                var changeLink = (!targetClass || (targetClass && $(this).hasClass(targetClass)));
                if (changeLink && urlEngine) {
                    var newHref = urlEngine.clearParam(paramKey, $(this).attr("href"));
                    $(this).attr("href", newHref);
                }
            });
        }

        var init = function() {
            that.workingContext = "body";
            that.setClicks(that.workingContext);
        }();
    };

    /**
        Iterate through an object, performing the specified function on each property.
        @param {object} theObject - the object to iterate through.
        @param {object} theFunction - the function to execute on each property.
    */
    var forEach = function(theObject, theFunction, theInterval) {
        var theInterval = theInterval || false;
        if (theInterval && $.isArray(theObject)) {
            var objectIterator = 0;
            var timedFunction = setInterval(function() {
                if (objectIterator < theObject.length) {
                    theFunction(theObject[objectIterator], objectIterator++);
                } else {
                    clearInterval(timedFunction);
                }
            }, theInterval);
        } else {
            for (var theKey in theObject) {
                if (theObject.hasOwnProperty(theKey)) theFunction(theObject[theKey], theKey);
            }
        }
    };

    var truncateText = function(theText, theLength, doAbbreviate) {
        if ($.type(theText) === "string") {
            var theLength = (theLength && ($.type(theLength) === "number")) ? theLength : false;
            var doAbbreviate = doAbbreviate || false;
            if (doAbbreviate) {
                var abbreviateTerm = function(thisTerm) {
                    var newTerm = "";
                    var termArray = thisTerm.split(" ");
                    forEach(termArray, function(thisWord) {
                        newTerm += thisWord.charAt(0);
                    });
                    return(newTerm.toUpperCase());
                };
                var termPrefixes = ["Senior", "Chief", "Lead", "Executive"];
                var termSuffixes = ["President", "Officer"];
                var termWords = ["Vice", "Technology", "Financial", "Information", "Marketing", "Managing", "Executive"];
                var threeTerms = [];
                var twoTerms = [];
                forEach(termPrefixes, function(thisPrefix) {
                    forEach(termWords, function(thisWord) {
                        forEach(termSuffixes, function(thisSuffix) {
                            threeTerms.push([thisPrefix, thisWord, thisSuffix].join(" "));
                            twoTerms.push(thisWord + " " + thisSuffix);
                            twoTerms.push(thisPrefix + " " + thisWord);
                        });
                    });
                });
                var allTerms = threeTerms.concat(twoTerms);
                forEach(allTerms, function(thisTerm) {
                    var abbreviatedTerm = abbreviateTerm(thisTerm);
                    theText = theText.split(thisTerm).join(abbreviatedTerm);
                });
            }
            if (theLength && (theText.length > theLength)) {
                var theElip = "...";
                theLength -= theElip.length;
                var tempText = theText.substr(0, theLength);
                var lastSpace = tempText.lastIndexOf(" ");
                var trimmedText = (lastSpace !== -1) ? tempText.substr(0, lastSpace) : tempText;
                theText = trimmedText + theElip;
            }
        }
        return(theText);
    };




/*
    var urlEngine = new UrlBox();
    var linkEngine = new LinkBox();
*/

//jcerda

// Header Video Background
// if( ( onMobile === false ) ) {
//     var headerVdAutoPlay = Drupal.settings.headerVideoAutoPlay;
//     var headerVideoRes = Drupal.settings.headerVideoRes;
//     // The videoplayer - controlled background video
//     $(".player").mb_YTPlayer({
//         containment: ".intro-video",
//         opacity: 1, // Set the opacity of the player;
//         mute: true, // Mute the audio;
//         // ratio: "4/3" or "16/9" to set the aspect ratio of the movie;
//         quality: headerVideoRes,// quality: "default" or "small", "medium", "large", "hd720", "hd1080", "highres";
//         // containment: The CSS selector of the DOM element where you want the video background; if not specified it takes the "body"; if set to "self" the player will be instanced on that element;
//         // optimizeDisplay: True will fit the video size into the window size optimizing the view;
//         loop: false, // True or false loops the movie once ended.
//         // vol: 1 to 100 (number) set the volume level of the video.
//         startAt: 0, // Set the seconds the video should start at.
//         autoPlay: headerVdAutoPlay, // True or false play the video once ready.
//         showYTLogo: false, // Show or hide the YT logo and the link to the original video URL.
//         showControls: false // Show or hide the controls bar at the bottom of the page.
//     });
//     //$('#home').addClass('video-section');
//     // Start the movie
//     if(headerVdAutoPlay == true) {
//         // First we're going to hide these elements
//         // Start the movie
//         $("#bgndVideo").on("YTPStart",function(){
//             $('#home').removeClass('video-section');
//             $("#video-play").hide();
//             $("#video-pause").show();
//             //$(".fullscreen-image").hide();
//         });

//         // Pause the movie
//         $("#bgndVideo").on("YTPPause",function(){
//             $("#video-play").show();
//             $("#video-pause").hide();
//         });
//         // After the movie
//         $("#bgndVideo").on("YTPEnd",function(){
//             //$('#home').addClass('video-section');
//             //$(".fullscreen-image").show();
//         });
//     }
//     if (headerVdAutoPlay == false){
//         // First we're going to show img fallback
//         $("#video-pause").hide();
//         $("#bgndVideo").on("YTPStart",function(){
//             $("#video-play").hide();
//             $("#video-pause").show();
//         });
//         //$(".fullscreen-image").hide();
//         // Pause the movie
//         $("#bgndVideo").on("YTPPause",function(){
//             $("#video-play").show();
//             $("#video-pause").hide();
//         });
//         // After the movie
//         $("#bgndVideo").on("YTPEnd",function(){
//             //$('#home').addClass('video-section');
//             //$(".fullscreen-image").show();
//         });
//     }

// } else {
//     // Fallback for mobile devices
//     /* as a fallback we add a special class to the header which displays a poster image */
//     //$('#home').addClass('video-section');

//     /* hide player */
//     $(".player").hide();

//     $("#home #video-controls").hide();
// }
// //FullScreen Slider
// var hdSlideEffect = Drupal.settings.hdSlideEffect;
// var hdAutoSlide = Drupal.settings.hdAutoSlide;

// //FullScreen Slider
// $('#fullscreen-slider').maximage({
//     cycleOptions : {
//         fx : 'fade',
//         speed : 1500,
//         timeout : 6000,
//         prev : '#slider_left',
//         next : '#slider_right',
//         pause : 0,

//         before : function(last, current) {
//             jQuery('.slide-content').fadeOut().animate({ top : '190px'}, {queue : false, easing : hdSlideEffect,duration : 550});
//             jQuery('.slide-content').fadeOut().animate({ top : '-190px'});
//         },
//         after : function(last, current) {
//             jQuery('.slide-content').fadeIn().animate({top : '0'}, {queue : false, easing : hdSlideEffect, duration : 450});
//         }
//     },
//     onFirstImageLoaded : function() {
//         jQuery('#cycle-loader').delay(800).hide();
//         jQuery('#fullscreen-slider').delay(800).fadeIn('slow');
//         jQuery('.slide-content').fadeIn().animate({
//             top : '0'
//         });
//         jQuery('.slide-content a').bind('click', function(event) {
//             var $anchor = $(this);
//             jQuery('html, body').stop().animate({
//                 scrollTop : $($anchor.attr('href')).offset().top - 44
//             }, 1500, hdSlideEffect);
//             event.preventDefault();
//         });
//     }
// });


// //-----EFFECTS-----

// //Elements Appear from top

// $('.item_top').each(function() {
//     $(this).appear(function() {
//         $(this).delay(300).animate({
//             opacity : 1,
//             top : "0px"
//         }, 1000);
//     });
// });

// //Elements Appear from bottom
// $('.item_bottom').each(function() {
//     $(this).appear(function() {
//         $(this).delay(150).animate({
//             opacity : 1,
//             bottom : "0px"
//         }, 1000);
//     });
// });

// //Elements Appear from left
// $('.item_left').each(function() {
//     $(this).appear(function() {
//         $(this).delay(150).animate({
//             opacity : 1,
//             left : "0px"
//         }, 1000);
//     });
// });

// //Elements Appear from right
// $('.item_right').each(function() {
//     $(this).appear(function() {
//         $(this).delay(150).animate({
//             opacity : 1,
//             right : "0px"
//         }, 1000);
//     });
// });

// //Elements Appear in fadeIn effect
// $('.item_fade_in').each(function() {
//     $(this).appear(function() {
//         $(this).delay(150).animate({
//             opacity : 1,
//             right : "0px"
//         }, 1000);
//     });
// });

})(jQuery);
