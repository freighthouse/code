(function ($) { Drupal.behaviors.ebay_issue_conditional = { attach: function (context, settings) {
// Start Drupal Behaviors

  // Start the timeline
  if ($('body').hasClass('page-node-edit') && $('body').hasClass('node-type-issue')) {

    // Show/hide views on load based on current value
    $('#field-issue-type-collection-values .field-type-list-text .form-type-select .form-select').each(function() {
      var selectedValue = $(this).val();
      if (selectedValue == 'timeline') {
        $(this).parent().parent().siblings('.field-name-field-issue-video').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-textarea').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-timeline').show();
      }
      if (selectedValue == 'video') {
        $(this).parent().parent().siblings('.field-name-field-issue-video').show();
        $(this).parent().parent().siblings('.field-name-field-issue-textarea').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-timeline').hide();
      }
      if (selectedValue == 'textarea') {
        $(this).parent().parent().siblings('.field-name-field-issue-video').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-textarea').show();
        $(this).parent().parent().siblings('.field-name-field-issue-timeline').hide();
      }
    });

    // Show/hide views based on selection
    $('#field-issue-type-collection-values .field-type-list-text .form-type-select .form-select').change(function() {
      var selectedValue = $(this).val();
      if (selectedValue == 'timeline') {
        $(this).parent().parent().siblings('.field-name-field-issue-video').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-textarea').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-timeline').show();
      }
      if (selectedValue == 'video') {
        $(this).parent().parent().siblings('.field-name-field-issue-video').show();
        $(this).parent().parent().siblings('.field-name-field-issue-textarea').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-timeline').hide();
      }
      if (selectedValue == 'textarea') {
        $(this).parent().parent().siblings('.field-name-field-issue-video').hide();
        $(this).parent().parent().siblings('.field-name-field-issue-textarea').show();
        $(this).parent().parent().siblings('.field-name-field-issue-timeline').hide();
      }
    });
  }

// End Drupal Behaviors
}};}(jQuery));
