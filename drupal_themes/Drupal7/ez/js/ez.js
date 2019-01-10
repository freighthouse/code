(function($,sr){

  var debounce = function (func, threshold, execAsap) {
    var timeout;

    return function debounced () {
      var obj = this, args = arguments;
      function delayed () {
        if (!execAsap) {
          func.apply(obj, args);
        }
        timeout = null;
      };

      if (timeout) {
        clearTimeout(timeout);
      }
      else if (execAsap) {
        func.apply(obj, args);
      }

      timeout = setTimeout(delayed, threshold || 100);
    };
  }
  // smartresize
  jQuery.fn[sr] = function(fn){  return fn ? this.bind('resize', debounce(fn)) : this.trigger(sr); };

})(jQuery,'smartresize');

jQuery(document).ready(function($) {

  prettyPrint();

  $("img.lazy").lazyload();

  //tooltips!
  $('.tip').tooltipster({
    maxWidth: 300
  });

  //delay function
  var delay = (function(){
    var timer = 0;

    return function(callback, ms){
      clearTimeout (timer);
      timer = setTimeout(callback, ms);
    };
  })();

  //homepage styles
  if ($('.front').length > 0) {
    $('body').addClass('loaded');

    var cnt=0, texts=[];
    $('.rotated').each(function() {
      texts[cnt++]=$(this).text();
    });
    function slide() {
      if (cnt>=texts.length) cnt=0;
      $('.rotate').html(texts[cnt++]);
      $('.rotate')
        .fadeIn('slow').animate({opacity: 1.0}, 1500).fadeOut('fast',
         function() {
           return slide()
         }
      );
    }
    slide();

    $(window).scroll(function() {
      if ($(window).scrollTop() > 125) {
        $('.navbar').addClass('scrolled');
      } else {
        $('.navbar').removeClass('scrolled');
      }
    });
    $(".videoplay").fancybox({
      padding   : 0,
      maxWidth  : 800,
      maxHeight : 600,
      fitToView : false,
      width   : '70%',
      height    : '70%',
      autoSize  : false,
      openEffect  : 'fade',
      closeEffect : 'fade',
      helpers: {
        title: null
      }
    });
  };


  function showError(message) {
    $('#feedback-icon').removeClass('fa-circle-o-notch fa-spin fa-check').addClass('fa-times');
    $('#text-feedback').html('<p class="text-danger">'+message+'</p>');
    $('#kwvalidate .form-group:first-child').removeClass('has-success').addClass('has-error');
  }

  function searchKeyword() {
    var search = $('#kwvalidate input');
    var locale = $('select[name="country"]');
    delay(function(){
      if ($.trim(search.val()).length > 1) {
        var feedback = $('#text-feedback');
        var keyword = $.trim(search.val());
        var country = $.trim(locale.val());
        console.log('starting search');
        $.ajax({
          url: '/sites/all/themes/ez/php/keyword-check.php',
          data: 'keyword='+keyword+'&country='+country,
          type: 'POST',
          success: function (responseData) {
              var message;
              if (responseData == 1) {
                message = 'Your keyword is available, sign up now to claim it!';
                $('#feedback-icon').removeClass('fa-circle-o-notch fa-spin fa-times').addClass('fa-check');
                feedback.html('<p class="text-success">'+message+'</p>');
                $('#kwvalidate .form-group:first-child').removeClass('has-error').addClass('has-success');
                $('#text-feedback').append('<a href="/start" class="btn btn-large btn-green btn-rounded">Sign up for free!</a>');
              } else {
                message = 'Your keyword is unavailable, please try another.';
                showError(message);
              }
          },
          error: function(){
            showError('Your request could not be processed, please try again.');
          }
        });
      } else {
        showError('Keywords must contain at least 2 characters and be only numbers & letters. Please try again.');
      }
    }, 500);
  }

  $(document)
  .ajaxStart(function () {
    $('#kwvalidate .form-group:first-child').removeClass('has-error has-success');
    $('#feedback-icon').removeClass('fa-search fa-times fa-check').addClass('fa-circle-o-notch fa-spin');
    $('#text-feedback').html('');
  })
  .ajaxStop(function () {
    $('#feedback-icon').removeClass('fa-circle-o-notch fa-spin').addClass('form-control-feedback');
  });

  $('#kwvalidate input').on('keypress keydown keyup', function(e) {
    $('#kwvalidate #response').html('&nbsp;');
    searchKeyword();
    if(e.keyCode == 13) { e.preventDefault(); }
  });
  $('select[name="country"]').change(function() {
    searchKeyword();
  });

    // CONVERT NAV-LINED TO DROPDOWN ON MOBILE


  $(window).smartresize(responsive);
  $(window).trigger('resize');


  function responsive() {

    // get resolution
    var resolution = document.documentElement.clientWidth;

    // mobile layout
    if (resolution <= 768) {

      if($('.select-menu').length === 0) {

        // create select menu
        var select = $('<select></select>');

        // add classes to select menu
        select.addClass('form-control select-menu');

        // each link to option tag
        $('.nav-stacked li a').each(function () {
          // create element option
          var option = $('<option></option>');

          // add href value to jump
          option.val(this.href);

          // add text
          option.text($(this).text());
          if ($(this).closest('li').hasClass('active')) {
            console.log($(this).text());
            option.attr('selected', 'selected');
          }
          // append to select menu
          select.append(option);
        });
        // add change event to select
        select.change(function () {
          window.location.href = this.value;
        });
        // add select element to dom, hide the .nav-tabs
        $('.nav-stacked').before(select).hide();
      }
    }
    // max width 768px
    if (resolution > 768) {
      $('.select-menu').remove();
      $('.nav-stacked').show();
    }

  }

});
