/**
 * Main JS for saving calculator
 */
 /* global ScaleRaphael, usMap */
(function ($) {
  Drupal.behaviors.sunrunUsMap = {
    attach: function ( context, settings ) {
      var interactive   = true;
      var initialHeight = 600,
      initialWidth = 940,
      attr = {
        'fill': '#e7eaec',
        'stroke': '#fff',
        'stroke-opacity': '1',
        'stroke-linejoin': 'round',
        'stroke-miterlimit': '4',
        'stroke-width': '2',
        'stroke-dasharray': 'none'
      },
        activeColors = ['#269ccc'],
        inactiveColors = ['#E48A36'],
      maxInterval = 300,
      animationType = '<',
      // Mapping of state names where Sunrun is available
      // for use with hash of state objects drawn by Raphael.
      // These should be highlighted.
      // whereWeAre = {
      //   'az': 'Arizona',
      //   'ca': 'California',
      //   'co': 'Colorado',
      //   'ct': 'Connecticut',
      //   'de': 'Delaware',
      //   'hi': 'Hawaii',
      //   'ma': 'Massachusetts',
      //   'md': 'Maryland',
      //   'nh': 'New Hampshire',
      //   'nv': 'Nevada',
      //   'nj': 'New Jersey',
      //   'ny': 'New York',
      //   'or': 'Oregon',
      //   'pa': 'Pennsylvania',
      //   'sc': 'South Carolina',
      //   'ut': 'Utah',
      // };
      whereWeAre = settings.whereWeAre[0];
      
      // Fit map to container
      function resizePaper(map, paper){
        var tMap = map.parentNode;
        var tWidth = $(tMap).width();
        var tHeight = tWidth * 0.63;
        $('.sr-interactive-map').height(tHeight);
        paper.changeSize(tWidth, tHeight, true, true);
      }


      function colorChange(elem, colors, interval){
        if(colors.length){
          elem.animate({
            fill: colors.shift()},
            interval, animationType,
            colorChange(elem, colors, interval));
        }
      }

      // Helper function to crossfade highlights on states
      function crossFade(show, hide){
        hide.animate({'opacity': 0}, maxInterval, animationType);
        show.animate({'opacity': 1}, maxInterval, animationType);
      }


      // closure function for each interactive map element on page
      $('.interactive-map').each(function(idx, elem){

        var R = ScaleRaphael(elem, initialWidth, initialHeight),
              usRaphael = {}, srRaphael = {};

        var tooltip = R.set()
        , tooltipRect
        , tooltipText;

        // Create the tooltip for reuse.
        // The single tooltip should be updated and repositioned
        // rather than reinstantiated.
        tooltipText = R.text(0, 0, 'Hello Sunrun!')
          .attr({
            'font-size': '20',
            'fill': '#FFF'
          });

        var box = tooltipText.getBBox()
          , boxPadding = 8
          , boxBorderWidth = 2;
        tooltipRect = R.rect(-(box.width + 2*boxPadding)/2,
                             -(box.height + 2*boxPadding)/2,
                             box.width + 2*boxPadding,
                             box.height + 2*boxPadding, 5)
          .attr({
            'fill': '#269ccc',
            'stroke': '#FFF',
            'stroke-width': boxBorderWidth + 'px'
          });

        tooltipText.toFront();

        tooltip.push(tooltipRect, tooltipText);
        tooltip.attr({'opacity': 0});



        resizePaper(elem, R);

        $(window).resize(function(){
          resizePaper(elem, R);
        });

          //Draw Map and store Raphael paths
          for (var state in usMap) {
            if ({}.hasOwnProperty.call(usMap, state)) {
              usRaphael[state] = R.path(usMap[state]).attr(attr);
            }
          }

          // Draw duplicates of available states
          // to support crossfade for highlighting.
          for (var availableState in whereWeAre){
            if ({}.hasOwnProperty.call(whereWeAre, availableState)) {
              srRaphael[availableState] = R.path(usMap[availableState])
                .attr(attr)
                .attr({'opacity': 0, fill: '#269ccc'})
                .toBack();
              }
          }

          function updateTooltip(label){
            // Update tooltip label.
            tooltipText.attr({ 'text': label });

            // Get resulting bounding box.
            var currentBoundingBox = tooltipText.getBBox();

            tooltipText.attr({
              'x': currentBoundingBox.width/2 + 2*boxPadding,
              'y': currentBoundingBox.height/2 + 2*boxPadding
            });
            // Use the bounding box to reposition the text background.
            tooltipRect.attr({
              'x': boxPadding,
              'y': boxPadding,
              'height': currentBoundingBox.height + 2*boxPadding,
              'width': currentBoundingBox.width + 2*boxPadding
            });
          }

          // Declare once for update listener.
          var mapCtr, containerX, containerY
              , containerHeight, containerWidth
              , xPosition, yPosition;
          // Named function to use for adding/removing
          // mouse move listener.

          function updateTooltipPosition(tooltip, e){
            mapCtr = $(elem)
          , containerHeight = mapCtr.height()
          , containerWidth = mapCtr.width()
            if(e.offsetX===undefined){
              e.offsetX = e.pageX-$(mapCtr).offset().left;
              e.offsetY = e.pageY-$(mapCtr).offset().top;
            }
            var transform_adjusted_X = initialWidth * (e.offsetX / containerWidth)

            xPosition = (transform_adjusted_X > containerWidth*3/4) ?
              transform_adjusted_X - tooltipRect.getBBox().width : transform_adjusted_X;

            var transform_adjusted_Y = initialHeight * (e.offsetY / containerHeight)

            yPosition = (transform_adjusted_Y > containerHeight*3/4) ?
              transform_adjusted_Y - tooltipRect.getBBox().height - (boxPadding * 2) : transform_adjusted_Y + (boxPadding * 2);
            // Apply transform to tooltip set to move in unison.
            tooltip.transform('t'+ xPosition + ',' + yPosition);
            tooltip.toFront();
          }

          // Add selected state fills and event listeners.
          for (var state in usRaphael) {
            if ({}.hasOwnProperty.call(usRaphael, state)) {
              (function(st, state) {
                var tooltipTimer;

                // Check if the current state is in the set
                // of states where Sunrun is available.
                if (whereWeAre.hasOwnProperty(state)) {
                  if (interactive) {
                    // Update the color and pointer behavior
                    // of qualifying states.
                    st[0].style.cursor = 'pointer';
                    if (state === 'pr' || state === 'hi') {
                      st.attr({
                        'stroke': '#025494'
                      });
                    }
                    st.attr({
                      'fill': '#025494',
                      'href': '/solar-by-state/' + state + '/'
                    });

                    // Add mouse event listeners to highlight
                    // and unhighlight states, and to show a tooltip
                    // after a short delay.
                    $(st[0]).on('touchend', function(e) {
                      window.location.pathname = e.target.parentElement.href.baseVal;
                    })
                    $(st[0]).mouseover(function(e) {
                      updateTooltip(whereWeAre[state]);
                      $(document).mousemove(function() {
                        updateTooltipPosition(tooltip, e)
                      });

                      tooltipTimer = setTimeout(function() {
                        // Fade in tooltip
                        tooltip.animate({
                          'opacity': 1
                        }, 200, 'linear');
                        tooltip.toFront();
                      }, 500);
                      // colorChange(st, activeColors.slice(0), maxInterval/activeColors.length);
                      crossFade(srRaphael[state], st);
                      // st.toFront();
                      R.safari();
                    });

                    $(st[0]).mouseout(function(e) {
                      clearTimeout(tooltipTimer);
                      tooltip.attr({
                        'x': -9999,
                        'y': -9999,
                        'opacity': 0
                      });
                      $(document).unbind('mousemove', updateTooltipPosition);
                      // colorChange(st, inactiveColors.slice(0), maxInterval/inactiveColors.length);
                      crossFade(st, srRaphael[state]);
                      // st.toFront();
                      R.safari();
                    });
                  } else {
                    st.attr({
                      'fill': '#E48A36'
                    });
                  }
                }
              })(usRaphael[state], state);
            }
          }
        });
      }
  }
})(jQuery);
