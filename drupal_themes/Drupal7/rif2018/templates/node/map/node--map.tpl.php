<?php

	/**
	 * @file
	 * Default theme implementation to display a node.
	 *
	 * Available variables:
	 * - $title: the (sanitized) title of the node.
	 * - $content: An array of node items. Use render($content) to print them all,
	 *   or print a subset such as render($content['field_example']). Use
	 *   hide($content['field_example']) to temporarily suppress the printing of a
	 *   given element.
	 * - $user_picture: The node author's picture from user-picture.tpl.php.
	 * - $date: Formatted creation date. Preprocess functions can reformat it by
	 *   calling format_date() with the desired parameters on the $created variable.
	 * - $name: Themed username of node author output from theme_username().
	 * - $node_url: Direct URL of the current node.
	 * - $display_submitted: Whether submission information should be displayed.
	 * - $submitted: Submission information created from $name and $date during
	 *   template_preprocess_node().
	 * - $classes: String of classes that can be used to style contextually through
	 *   CSS. It can be manipulated through the variable $classes_array from
	 *   preprocess functions. The default values can be one or more of the
	 *   following:
	 *   - node: The current template type; for example, "theming hook".
	 *   - node-[type]: The current node type. For example, if the node is a
	 *     "Blog entry" it would result in "node-blog". Note that the machine
	 *     name will often be in a short form of the human readable label.
	 *   - node-teaser: Nodes in teaser form.
	 *   - node-preview: Nodes in preview mode.
	 *   The following are controlled through the node publishing options.
	 *   - node-promoted: Nodes promoted to the front page.
	 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
	 *     listings.
	 *   - node-unpublished: Unpublished nodes visible only to administrators.
	 * - $title_prefix (array): An array containing additional output populated by
	 *   modules, intended to be displayed in front of the main title tag that
	 *   appears in the template.
	 * - $title_suffix (array): An array containing additional output populated by
	 *   modules, intended to be displayed after the main title tag that appears in
	 *   the template.
	 *
	 * Other variables:
	 * - $node: Full node object. Contains data that may not be safe.
	 * - $type: Node type; for example, story, page, blog, etc.
	 * - $comment_count: Number of comments attached to the node.
	 * - $uid: User ID of the node author.
	 * - $created: Time the node was published formatted in Unix timestamp.
	 * - $classes_array: Array of html class attribute values. It is flattened
	 *   into a string within the variable $classes.
	 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
	 *   teaser listings.
	 * - $id: Position of the node. Increments each time it's output.
	 *
	 * Node status variables:
	 * - $view_mode: View mode; for example, "full", "teaser".
	 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
	 * - $page: Flag for the full page state.
	 * - $promote: Flag for front page promotion state.
	 * - $sticky: Flags for sticky post setting.
	 * - $status: Flag for published status.
	 * - $comment: State of comment settings for the node.
	 * - $readmore: Flags true if the teaser content of the node cannot hold the
	 *   main body content.
	 * - $is_front: Flags true when presented in the front page.
	 * - $logged_in: Flags true when the current user is a logged-in member.
	 * - $is_admin: Flags true when the current user is an administrator.
	 *
	 * Field variables: for each field instance attached to the node a corresponding
	 * variable is defined; for example, $node->body becomes $body. When needing to
	 * access a field's raw values, developers/themers are strongly encouraged to
	 * use these variables. Otherwise they will have to explicitly specify the
	 * desired field language; for example, $node->body['en'], thus overriding any
	 * language negotiation rule that was previously applied.
	 *
	 * @see template_preprocess()
	 * @see template_preprocess_node()
	 * @see template_process()
	 *
	 * @ingroup themeable
	 */
?>

<?php
$printing = substr($_SERVER['REQUEST_URI'], 0, 6) === '/print';
?>

<!-- VERY crude implementation. The CSS should be moved out ideally - perhaps even the javascript. There's some inline styling here that should be cleaned up. -->
<style type="text/css">
/*
#mapcontainer {
    position: relative;
    overflow: auto;
    width: 100%;
    max-width: 1500px;
    min-width: 768px;
    text-align: center;
    margin: 0 auto;
}
#mapcontainer > .content {
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
}
#mapcontainer > h2 {
    font-family: 'Gotham A', 'Gotham B', 'Helvetica Neue', Arial, Helvetica, sans-serif;
    text-transform: uppercase;
    font-weight: 900;
    font-size: 36px;
    color: #a6ce39;
}
#mapcontainer > p {
    font-size: 16px;
    font-weight: 700;
    line-height: 20px;
    color: #666666;
}
#mapmodal p cite,
#mapcontainer > p cite {
    font-size: 0.8em;
}
#statePreview {
    width: 300px;
    height: 200px;
    background-color: transparent;
    margin: 0 auto;
    margin-bottom: 32px;
}
#map {
    width: 100%;
    height: 100%;
    background-color: transparent;
    margin: 0 auto;
    max-width: 1024px;
    height: 600px;
}
#map .leaflet-control-container,
#map .leaflet-control-container .leaflet-bottom,
#statePreview .leaflet-control-container {
    width: 100%;
}
#mapmodal .modal-content {
    background-color: #0079c1;
    color: white;
}
#mapmodal .state-name {
    font-family: 'Gotham A', 'Gotham B', 'Helvetica Neue', Arial, Helvetica, sans-serif;
    font-size: 34px;
    text-transform: uppercase;
    text-align: center;
}
#mapmodal .modal-body {
    margin-top: 30px;
    border-bottom: 12px solid #fff200;
    -webkit-box-shadow: 0px 5px 5px 0px rgba(0, 0, 0, 0.05);
    -moz-box-shadow: 0px 5px 5px 0px rgba(0, 0, 0, 0.05);
    box-shadow: 0px 5px 5px 0px rgba(0, 0, 0, 0.05);
}
#mapmodal .modal-body a {
    color: #ffffff;
    text-decoration: underline;
}
#mapmodal .modal-header {
    border-bottom: none;
    padding-bottom: 20px;
    background-color: #0059a9;
    border-radius: 6px;
    height: auto;
}
#mapmodal .modal-footer {
    border-top: none;
    background-color: #0059a9;
    border-radius: 6px;
}
#mapmodal .modal-title img {
    height: 60px;
}
#mapmodal .modal-header button {
    color: white;
    opacity: 1;
}
#mapmodal .map-stats {
    width: 60%;
    margin-left: 20%;
}
#mapmodal .map-stats tbody {
    border-top: none;
}
#mapmodal .map-stats tr td {
    padding: 5px;
    vertical-align: middle;
    border: none;
}
#mapmodal .map-stats tr td .lbl {
    min-height: 54px;
    margin-bottom: 10px;
    background-color: rgba(0,0,0,0.1);
    border-radius: 6px;
    padding: 5px 10px;
    box-shadow: 0px 0px 5px rgba(0,0,0,0.5);
}
#mapmodal .map-stats tr td .val:not(.state-average-hilo) {
    height: 54px;
    margin-bottom: 10px;
    background-color: rgba(0,0,0,0.1);
    border-radius: 6px;
    border: 1px solid rgba(255,255,255,0.3);
    text-align: center;
    line-height: 54px;
    width: 44px;
}
#mapmodal .map-stats tr td .val.state-average-hilo img {
    border-radius: 4px;
    margin-top: -6px;
    width: 44px;
}
#mapmodal .state-reading-not-level {
    font-weight: bold;
    text-align: center;
    font-size: 40px;
    top: -30px;
    color: white;
    z-index: 1000000;
    position: relative;
    display: inline-block;
    padding: 20px;
    background-color: rgba(0,0,0,0.4);
    border-radius: 10px;
    left: 42%;
    width: 16%;
    margin-top: 30px;
}
#mapmodal .state-reading-not-level-lbl {
    text-align: center;
    top: -15px;
    padding-bottom: 20px;
    width: 300px;
    margin: 0 auto;
    position: relative;
    margin-bottom: -8px;
}
#mapmodal .state-average-hilo {
    font-size: 24px;
}
#map > div.leaflet-pane.leaflet-map-pane > div.leaflet-pane.leaflet-overlay-pane > svg > g > path.leaflet-interactive {
  text-align: center;

}
#map > div.leaflet-pane.leaflet-map-pane > div.leaflet-pane.leaflet-overlay-pane > svg > g > path.leaflet-interactive:hover {
  fill:#FFF200;
}
#map .state-marker .abbrev {
    color: white;
}
#map .state-marker-outside .abbrev {
    background-color: #0079c2;
    padding: 2px;
    color: white;
    border-radius: 4px;
    font-size: 14px;
}
*/
</style>

<script>

var states = <?php echo json_encode($states) ?>;

(function(L, $, global, undefined)
{

  /** Configuration **/
  var MAX_WIDTH = 1500;
  var MIN_WIDTH = 768;
  var mapOptions = {
    dragging: false,
    scrollWheelZoom: false,
    touchZoom: false,
    doubleClickZoom: false,
    boxZoom: false,
    zoomControl: false,
    attributionControl: false,
    zoomDelta: 0.1,
    zoomSnap: 0,
    tap: false
  };
  var statePreviewOptions = {
      dragging: false,
      scrollWheelZoom: false,
      touchZoom: false,
      doubleClickZoom: false,
      boxZoom: false,
      zoomControl: false,
      attributionControl: false,
      tap: false
  };
  var mapBoundsNoInfo = {
    paddingTopLeft: [0, 35]
  };
  var mapBoundsInfo = {
    paddingTopLeft: [380, 35]
  };
  var viewCenter = [36, -96];
  var viewZoom = 4.9;
  var stateMarkerOptions = {
    keyboard: false
  };
  var stateStyle = {
    weight: 1,
    opacity: 1,
    color: '#ffffff',
    fillOpacity: 1.0,
    fillColor: '#00b1e3'
  };
  var stateHighlightStyle = {
    fillOpacity: 0.95
  };
  var stateOtherStyle = {
    fillColor: '#fff200',
    color: '#ffffff'
  };
  var layerOptions = {
    click: function(e) {
        var layer = e.target;
        var stateInfo = layer.feature.properties;
        var stateName = stateInfo.name;
        var stateData = stateMap[ stateName ];

        if (stateData) {
            showModal(stateData);
            currentState = layer;
            currentState.setStyle( stateOtherStyle );

/*
            statePreviewLayer.clearLayers();
            var copy = {
                type: 'FeatureCollection',
                features: [layer.toGeoJSON()]
            };
            var copyJson = L.geoJson( copy );
            copyJson.setStyle({
                color: 'rgba(255,242,0,0.5)',
                weight: 7,
                opacity: 1,
                fillOpacity: 1,
                fillColor: '#ffffff'
            });
            copyJson.addTo( statePreviewLayer );

            statePreview.setZoom(0);

            modal.one('shown.bs.modal', function() {
                statePreview.fitBounds( copyJson.getBounds(), {
                    animate: false
                });
            });
*/


            /*
        statePreviewLayer.clearLayers();
        var copy = {
            type: 'FeatureCollection',
            features: [layer.toGeoJSON()]
        };
        var copyJson = L.geoJson( copy );
        copyJson.addTo( statePreviewLayer );
        var copyBounds = copyJson.getBounds();
        statePreview.setView(
            copyBounds.getCenter(),
            statePreview.getBoundsZoom( copyBounds )
        );*/



        } else {
            alert('The content for ' + stateName + ' has not been created yet!');
        }
    }
  };
  var geojsonOptions = {
    style: getFeatureStyle,
    onEachFeature: onEachFeature
  };
  var outsideStateMarkerStart = [-70.22119882610032, 39.84277287021827];
  var outsideStateMarkerJump = [0, -1.8];
  var outsideStateMarkerOptions = {
    keyboard: false
  };
  var outsideStateIconOptions = {
    className: 'state-marker-outside',
    iconSize: [28, 28]
  };
  var stateIconOptions = {
    className: 'state-marker',
    iconSize: [20, 20]
  };

  /** State **/
  var map, stateLayer, resizeTimeout, adjustmentMap, stateMap, geojson, zoomed,
    stateMarkerOutsideLayer, stateMarkerLayer, modal, currentState, statePreview,
    resizeTimeout;

  /** Initialization **/
  $(function()
  {
      map = L.map( 'map', mapOptions ).setView( viewCenter, viewZoom );
      /*
      statePreview = L.map( 'statePreview', statePreviewOptions );
      statePreviewLayer = L.layerGroup();
      */
      stateLayer = L.layerGroup();
      stateMarkerLayer = L.layerGroup();
      stateMarkerOutsideLayer = L.layerGroup();
      resizeTimeout = false;
      adjustmentMap = {};
      stateMap = {};
      zoomed = false;

      initModal();
      listenToMap();
      makeAdjustments();
      addStateMarkers();
      populateStateMap();

      geojson = L.geoJson( statesData, geojsonOptions ).addTo( map );

      stateMarkerLayer.addTo( map );
      stateMarkerOutsideLayer.addTo( map );
      stateLayer.addTo( map );
      /*
      statePreviewLayer.addTo( statePreview );
      */
      listenForResize();
      autoOpen();

      /** Export **/
      global.map = map;
      global.geojson = geojson;
      /*
      global.statePreview = statePreview;
      */
  });

  /** Functions **/
  function autoOpen()
  {
      var hash = global.location.hash;
      var title = hash ? hash.substring(1) : null;
      var state = stateMap[ title ];

      if (state)
      {
          var feature = getFeatureByState( title );

          if (feature)
          {
              var layer = getLayerByFeature( feature.id );

              if (layer)
              {
                  layerOptions.click({target: layer});
              }
          }
      }
  }

  function getFeatureStyle(feature)
  {
    return stateStyle;
  }

  function listenForResize()
  {
    $( window ).on( 'resize', tryResize );

    handleResize();
    
    setTimeout( handleResize, 1000 );
  }

  function tryResize()
  {
    if ( resizeTimeout )
    {
      clearTimeout( resizeTimeout );
    }

    resizeTimeout = setTimeout( handleResize, 500 );
  }

  function populateStateMap()
  {
      $.each( global.states, function(i, s)
      {
         stateMap[ s.title ] = s;
      });
  }

  function highlightFeature(e)
  {
    var layer = e.target;

    layer.setStyle( stateHighlightStyle );
  }

  function resetHighlight(e)
  {
    var layer = e.target;

    geojson.resetStyle( layer );
  }

  function resetStyles()
  {
    $.each( geojson._layers, function(i, layer)
    {
      geojson.resetStyle( layer );
    });
  }

  function setStylesExcept(thisLayer, style)
  {
    $.each( geojson._layers, function(i, layer)
    {
      if ( layer !== thisLayer )
      {
        layer.setStyle( style );
      }
    });
  }

  function tryAutoPopup(item, mark)
  {
    if ( nextPopupItem === item )
    {
      setTimeout(function()
      {
        mark.openPopup();

      }, 500 );

      nextPopupItem = false;
    }
  }

  function placeMap(events)
  {
    var map = {};

    $.each( events, function(i, e)
    {
      var place = e.location || e.place;

      if ( place && e.latlng && !e.last )
      {
        ( map[ place ] = map[ place ] || [] ).push( e );
      }
    });

    return map;
  }

  function onEachFeature(feature, layer)
  {
    layer.on( layerOptions );
  }

  function getFeatureByState(name)
  {
    var chosen = null;

    $.each( global.statesData.features, function(i, feature)
    {
      if ( feature.properties.name === name )
      {
        chosen = feature;
      }
    });

    return chosen;
  }

  function getLayerByState(name)
  {
    var chosen = null;

    $.each( geojson._layers, function(i, layer)
    {
      if ( layer.feature.properties.name === name )
      {
        chosen = layer;
      }
    });

    return chosen;
  }

  function isPoint(arr)
  {
    return arr.length === 2 && typeof arr[0] === 'number' && typeof arr[1] === 'number';
  }

  function getPoints(points, func)
  {
    $.each( points, function(j, point)
    {
      if ( isPoint( point ) )
      {
        func( point );
      }
      else
      {
        getPoints( point, func );
      }
    });
  }

  function getBounds(points)
  {
    var minX = Number.POSITIVE_INFINITY;
    var minY = Number.POSITIVE_INFINITY;
    var maxX = Number.NEGATIVE_INFINITY;
    var maxY = Number.NEGATIVE_INFINITY;

    function accumulate(pt)
    {
      minX = Math.min( minX, pt[0] );
      maxX = Math.max( maxX, pt[0] );
      minY = Math.min( minY, pt[1] );
      maxY = Math.max( maxY, pt[1] );
    }

    getPoints( points, accumulate );

    return {
      minX: minX, minY: minY, maxX: maxX, maxY: maxY
    };
  }

  function getCenterOfGravity(points)
  {
    var bounds = getBounds( points );
    var cx = (bounds.minX + bounds.maxX) * 0.5;
    var cy = (bounds.minY + bounds.maxY) * 0.5;
    var twicearea = 0;
    var x = 0;
    var y = 0;
    var p1, p2, f;

    function accumulate(pt)
    {
      p2 = pt;
      if (p1)
      {
        f = (p1[0] - cx) * (p2[1] - cy) - (p2[0] - cx) * (p1[1] - cy);
        twicearea += f;
        x += (p1[0] + p2[0] - 2 * cx) * f;
        y += (p1[1] + p2[1] - 2 * cy) * f;
      }
      p1 = p2;
    }

    getPoints( points, accumulate );

    f = twicearea * 3;

    return [
      x / f + cx,
      y / f + cy
    ];
  }

  function makeAdjustments()
  {
    $.each( global.stateAdjustments, function(i, adj)
    {
      var state = getFeatureByState( adj.state );

      if ( !state )
      {
        return;
      }

      var points = state.geometry.coordinates;
      var info = state.properties;

      adj.adjuster = buildAdjustPoint( points, adj );

      getPoints( points, adj.adjuster );

      adjustmentMap[ info.abbrev.toLowerCase() ] = adj;
      adjustmentMap[ info.name.toLowerCase() ] = adj;
    });
  }

  function buildAdjustPoint(points, adj)
  {
    var bounds = getBounds( points );

    var cx = (bounds.minX + bounds.maxX) * 0.5;
    var cy = (bounds.minY + bounds.maxY) * 0.5;
    var acx = adj.center[0];
    var acy = adj.center[1];
    var dx = acx - cx;
    var dy = acy - cy;

    return function adjustPoint(pt)
    {
      pt[0] += dx;
      pt[1] += dy;

      if ( adj.scale )
      {
        pt[0] = (pt[0] - acx) * adj.scale[0] + acx;
        pt[1] = (pt[1] - acy) * adj.scale[1] + acy;
      }

      if ( adj.rotate )
      {
        var ox = pt[0] - acx;
        var oy = pt[1] - acy;
        var cos = adj.rotate[0];
        var sin = adj.rotate[1];
        pt[0] = (cos * ox - sin * oy) + acx;
        pt[1] = (sin * ox + cos * oy) + acy;
      }
    };
  }

  function transformPoint(places, latlng)
  {
    var state = deduceState( places );
    var adjustment = state ? adjustmentMap[ state.toLowerCase() ] : false;

    if ( adjustment && adjustment.adjuster )
    {
      var transformed = [latlng[1], latlng[0]];

      adjustment.adjuster( transformed );

      latlng = [transformed[1], [transformed[0]]];
    }

    return latlng;
  }

  function onMarkerClick(e)
  {
      var feature = getLayerByFeature( e.target.options.featureId );

      layerOptions.click({target: feature});
  }

  function addStateMarkers()
  {
    $.each( global.statesData.features, function(i, feature)
    {
      var state = feature.properties;

      var abbrevHTML = '<div class="abbrev">' + state.abbrev + '</div>';
      var iconHTML = abbrevHTML;
      var marker = null;

      var cog = state.center || getCenterOfGravity( feature.geometry.coordinates );

      var iconOptions = {
        html: iconHTML
      };
      var markerOptions = {
        alt: state.name,
        featureId: feature.id,
        icon: L.divIcon( $.extend( iconOptions, stateIconOptions ) )
      };
      var place = [cog[1], cog[0]];

      marker = addMarker( place, $.extend( markerOptions, stateMarkerOptions ) );
      if ( state.on < 0 )
      {
        marker.addTo( stateMarkerLayer );
      }
      marker.on( 'click', onMarkerClick );

      if ( state.on >= 0 && !state.hide )
      {
        var cog = state.center || getCenterOfGravity( feature.geometry.coordinates );

        var iconOptions = {
          html: iconHTML
        };
        var markerOptions = {
          title: state.name,
          alt: state.name,
          featureId: feature.id,
          icon: L.divIcon( $.extend( iconOptions, outsideStateIconOptions ) )
        };
        var place = [ // state.marker
          outsideStateMarkerStart[1] + (outsideStateMarkerJump[1] * state.on),
          outsideStateMarkerStart[0] + (outsideStateMarkerJump[0] * state.on)
        ];

        marker = addMarker( place, $.extend( markerOptions, outsideStateMarkerOptions ) );
        marker.addTo( stateMarkerOutsideLayer );
        marker.on( 'click', onMarkerClick );

        /*
        var line = L.polyline([
          [place[0], place[1] - 1.2],
          [cog[1], cog[0]]
        ], {
          color: '#333333',
          weight: 1,
          opacity: 0.5
        }).addTo( stateMarkerOutsideLayer );
        */
      }
    });
  }


  function getLayerByFeature(id)
  {
    var chosen = null;

    $.each( geojson._layers, function(layerId, layer)
    {
      if ( layer.feature.id === id )
      {
        chosen = layer;
      }
    });

    return chosen;
    }

function removeHash () {
    var scrollV, scrollH, loc = global.location;
    if ("pushState" in history)
        history.pushState("", document.title, loc.pathname + loc.search);
    else {
        // Prevent scrolling by storing the page's current scroll offset
        scrollV = document.body.scrollTop;
        scrollH = document.body.scrollLeft;

        loc.hash = "";

        // Restore the scroll offset, should be flicker free
        document.body.scrollTop = scrollV;
        document.body.scrollLeft = scrollH;
    }
}


  function initModal()
  {
    modal = $('#mapmodal');
    modal.modal({
        show: false
    });

    modal.on('hidden.bs.modal', function() {
        if (currentState) {
            geojson.resetStyle( currentState );
            currentState = null;
            removeHash();
        }
    });

    modal.find('.btn-print').click(function() {
        var content = modal.clone( true );
        content.find('.modal-footer').remove();
        content.find('.section-border-container').remove();
        content.find('*').removeAttr('id');
        content.find('path.leaflet-interactive[stroke="rgba(255,242,0,0.5)"]').attr('stroke', 'black');
        content.find('.modal-title img.web-only').hide();
        content.find('.modal-title img.print-only').show();

        var css = [
            '<style>',
            '.state-name { ',
            '  text-align: center;',
            '  font-size: 2em;',
            '}',
            '.print-invert {',
            '  -webkit-filter: invert(100%);',
            '  filter: invert(100%);',
            '}',
            '.print-gray {',
            '  -webkit-filter: grayscale(100%);',
            '  filter: grayscale(100%);',
            '}',
            '.print-invert.print-gray {',
            '  -webkit-filter: grayscale(100%) invert(100%);',
            '  filter: grayscale(100%) invert(100%);',
            '}',
            '.map-stats {',
            '   width: 60%;',
            '   margin-left: 20%;',
            '}',
            '.map-stats .lbl {',
            '   font-weight: bold;',
            '   padding: 5px 10px;',
            '}',
            '.map-stats .val { ',
            '   padding-left: 20px;',
            '}',
            '.map-stats tr td {',
            '   padding: 5px;',
            '   vertical-align: middle;',
            '   border: none;',
            '}',
            '.state-reading-not-level { font-weight: bold; font-size: 1.7em; padding: 20px }',
            'img.hilo { height: 1em; }',
            '.state-preview, .state-reading-not-level, .state-reading-not-level-lbl { text-align: center; }',
            '.state-reading-not-level-lbl { padding-bottom: 1em; width: 300px; margin: 0 auto; }',
            'button.close { display: none; }',
            '.addthis_inline_share_toolbox { display: none; }',
            '</style>'
        ];

        $('<iframe>', {
                name: 'printFrame',
                class: 'printFrame hidden'
            })
            .appendTo('body')
            .contents()
            .find('body')
            .append(content)
            .append(css.join('\n'))
        ;

        var frame = window.frames['printFrame'];

        try {
          frame.document.execCommand('print', false, null);
        } catch(e) {
          frame.print();
        }

        $(".printFrame").remove();
    });
  }

  function showModal(state)
  {
      var hilo = (state.average_hilo + '').toLowerCase();
      var hiloHTML = {
          higher: '<img class="print-gray hilo" src="/sites/all/themes/custom/rif2018/build/img/score-higher.png" alt="Higher">',
          lower: '<img class="print-gray hilo" src="/sites/all/themes/custom/rif2018/build/img/score-lower.png" alt="Lower">',
          same: '<img class="print-gray hilo" src="/sites/all/themes/custom/rif2018/build/img/score-average.png" alt="Same">'
      };

      modal.find('.state-name').html( state.title );
      modal.find('.state-body').html( state.body );
      modal.find('.state-average-hilo').html( hiloHTML[ hilo ] || hilo );
      modal.find('.state-average-score').html( state.average_score );
      modal.find('.state-reading-advanced').html( state.reading_advanced + '<span>%</span>'  );
      modal.find('.state-reading-at-basic').html( state.reading_at_basic + '<span>%</span>'  );
      modal.find('.state-reading-below-basic').html( state.reading_below_basic + '<span>%</span>'  );
      modal.find('.state-reading-not-level').html( state.reading_not_level + '<span>%</span>'  );
      modal.find('.state-reading-proficient').html( state.reading_proficient + '<span>%</span>'  );
      modal.modal('show');

      global.location.hash = state.title;
  }

  function listenToMap()
  {
    /*
    map.on('click', function(e)
    {
      if ( window.console )
      {
        console.log( e );
      }
    });
    */
  }

  function isMobile()
  {
    return $( window ).width() < 1024;
  }

  function addMarker(latlng, options)
  {
    var marker = L.marker( latlng, options );

    marker.on( 'popupclose', function()
    {
      if ( zoomed )
      {
        var state = zoomed.feature.properties;
        var info = getStateInfo( state.name );

        map.fitBounds( zoomed.getBounds(), info ? mapBoundsInfo : mapBoundsNoInfo );
      }
    });

    return marker;
  }

  function tryResize()
  {
    if ( resizeTimeout )
    {
      clearTimeout( resizeTimeout );
    }

    resizeTimeout = setTimeout( handleResize, 500 );
  }

  function handleResize()
  {
    var $map = $('#map');

    viewZoom = ($map.width() - MIN_WIDTH) / (MAX_WIDTH - MIN_WIDTH) + 3.85;
    viewZoom = Math.floor( viewZoom * 1000 ) * 0.001;
    viewZoom += Math.random() * 0.000001;

    map.setView( viewCenter, viewZoom );

    resizeTimeout = false;
  }

  function zoomToFeature(e)
  {
      map.setView( viewCenter, viewZoom );
  }

  function fadeOut(e)
  {
    if ( !e.hasClass('hidden') )
    {
      e.fadeOut(function()
      {
        e.addClass('hidden')
      });
    }
  }

  function fadeIn(e)
  {
    if ( e.hasClass('hidden') )
    {
      e.removeClass('hidden');
      e.fadeIn();
    }
  }





})( L, jQuery, this );

</script>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <div id="mapcontainer">

        <h2><?php echo $title ?></h2>

        <div class="container">
            <div class="row">
                <div class="col-sm-12">

                    <?php print($body_text) ?>
                    <div class="addthis_inline_share_toolbox"></div>

                    <div id="map"></div>

                    <p><cite>For additional information please visit the <a href="https://nces.ed.gov/nationsreportcard/">NAEP</a> website.</cite></p>

                </div>
            </div>
        </div>

    </div>

    <div class="modal fade" tabindex="-1" role="dialog" id="mapmodal">
      <div class="modal-dialog modal-lg" role="document">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <h4 class="modal-title">
                <img class="web-only" src="/sites/all/themes/custom/rif2018/build/img/logo-rif.png">
                <img class="print-only" src="/sites/all/themes/custom/rif2018/build/img/logo-rif.png" style="display:none;">
            </h4>
          </div>
          <div class="modal-body">
              <div class="state-name"></div>
              <!-- <div id="statePreview" class="state-preview"></div> -->
              <div class="state-reading-not-level"></div>
              <div class="state-reading-not-level-lbl">
                  Percentage of 4th Grade Students NOT READING AT THE PROFICIENT LEVEL
              </div>
              <table class="map-stats">
                  <tbody>
                      <tr>
                          <td><div class="lbl single-line">State average score</div></td>
                          <td><div class="val state-average-score"></div></td>
                      </tr>
                      <tr>
                          <td><div class="lbl single-line">Higher, lower or at national average of 221</div></td>
                          <td><div class="val state-average-hilo"></div></td>
                      </tr>
                      <tr>
                          <td><div class="lbl">Percentage of students who performed at the BELOW BASIC reading level</div></td>
                          <td><div class="val state-reading-below-basic"></div></td>
                      </tr>
                      <tr>
                          <td><div class="lbl">Percentage of students who performed at the BASIC reading level</div></td>
                          <td><div class="val state-reading-at-basic"></div></td>
                      </tr>
                      <tr>
                          <td><div class="lbl">Percentage of students who performed at the PROFICIENT reading level</div></td>
                          <td><div class="val state-reading-proficient"></div></td>
                      </tr>
                      <tr>
                          <td><div class="lbl">Percentage of students who performed at the ADVANCED reading level</div></td>
                          <td><div class="val state-reading-advanced"></div></td>
                      </tr>
                  </tbody>
              </table>
              <h3>Student Score Gaps:</h3>
              <div class="state-body"></div>
              <p><cite>Information from the <a href="https://nces.ed.gov/nationsreportcard/pubs/stt2015/20160084.aspx">NAEP</a> website for 4th grade reading scores.</cite></p>
              <div class="addthis_inline_share_toolbox"></div>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-blue btn-print btn-success">Print</button>
            <button type="button" class="btn btn-blue btn-warning" data-dismiss="modal">Close</button>
          </div>
        </div><!-- /.modal-content -->
      </div><!-- /.modal-dialog -->
    </div><!-- /.modal -->

</div>
