(function ($) {
  // Use jQuery with the shortcut:
  // console.log($.browser);
// Here we immediately call the function with jQuery as the parameter.

var autoInterval = setInterval(autoNext, 3000);

function autoNext() {
  var currentButton = $('.dots-v7-container .dot-v7.active');
  var currentBold = $('.header-b span.active-bold');
  var currentPosition = currentButton.index();
  var currentBoldPosition = currentBold.index();
  currentButton.removeClass('active');
  currentBold.removeClass('active-bold');

  if (currentPosition != $('.dots-v7-container .dot-v7:last-child').index()) {
    currentButton.next().addClass('active');
    $('.iphone-v7 img').attr('src', currentButton.next().attr('data-image'));
  } else {
    $('.dots-v7-container .dot-v7:first-child').addClass('active');
    $('.iphone-v7 img').attr('src', $('.dots-v7-container .dot-v7:first-child').attr('data-image'));
  }

  if (currentBoldPosition != $('.header-b .bold-head:last-child').index()) {
    currentBold.next("span").not(document.getElementsByTagName('br')).addClass('active-bold');
  } else {
    $('.header-b .bold-head:first-child').addClass('active-bold');
  }
}
}(jQuery));

jQuery(function(){
  jQuery('body').on('click','.plus-faq', function() {
    jQuery(this).parent('.open-icons').next('.expand-down').toggleClass('active');
    jQuery(this).parent('.open-icons').parent('.faq-main-box').children('h1').toggleClass('expand-yellow');
    jQuery(this).toggleClass('clicked');
  });
  jQuery('body').on('click','.expand', function() {
    jQuery('.open-icons').next('.expand-down').toggleClass('active');
    jQuery('.faq-main-box').children('h1').toggleClass('expand-yellow');
    jQuery('.plus-faq').toggleClass('clicked');
    jQuery(this).toggleClass('exbg-yellow');
  });
  jQuery('body').on('click','.faq-list li', function() {
    jQuery(this).next().toggleClass('show-answer');
  });
})
