var turn_gpop_src;

function turn_gpop() {
    turn_gpop_src = jQuery(this).attr('href');
    turn_vcor = turn_gpop_src; //.substr(0, turn_gpop_src.indexOf('.html')) + '-' + turn_ww +'.html';
    //console.log('load '+ turn_vcor);
    if (( turn_ww == 320 ) || ( turn_ww == 480 ) ) {
        jQuery('#dialog-gpopup').addClass('popinline').append('<div class="pophd"><a href="#back" id="popback">Back</a></div>');
        jQuery("#popback").click(
            function() {
                jQuery('#dialog-gpopup').hide().empty();
                jQuery('#bg').show();
                return false;
            }
        );
        jQuery('<iframe />').attr('src', turn_vcor).attr('width',turn_ww).attr('height',800).attr('frameborder',0).appendTo('#dialog-gpopup');
        jQuery('#dialog-gpopup').show();
        jQuery('#bg').hide();
        jQuery(window).scrollTop(0);
        if (jQuery("#admin-menu").size() > 0) {
            jQuery('#dialog-gpopup').css('margin-top', jQuery('#admin-menu').height());
        }
    } else {
        jQuery("#dialog-gpopup").dialog("open");
    }
    return false;
}

jQuery(
    function(){
        //console.log('hiya');
        if (jQuery('a.gpop').size() > 0 ) {
            //  console.log('hiyo');

            if (jQuery('#dialog-gpopup').size() == 0 ) {
                jQuery('<div id="dialog-gpopup" />').appendTo('body');
            }

            jQuery('a.gpop').click(turn_gpop);

            if (turn_ww > 480 ) {
                jQuery("#dialog-gpopup").dialog(
                    {
                        height: 600,
                        width: 640,
                        modal: true,
                        autoOpen: false,
                        resizable: false
                    }
                );
                jQuery("#dialog-gpopup").bind(
                    "dialogbeforeclose", function(event, ui) {
                        jQuery('#dialog-gpopup').empty();
                        return true;
                    }
                );

                jQuery("#dialog-gpopup").bind(
                    "dialogopen", function(event, ui) {
                        var embed_html = '<iframe src="'+ turn_gpop_src +'" width="100%" height="600" frameborder="0" />';
                        jQuery('#dialog-gpopup').html(embed_html).css({'height':600,'overflow':'hidden'});
                        jQuery('#dialog-gpopup').parent().addClass('gpopd');
                    }
                );
            }
            var whash = ''+ window.location.hash;
            if (whash != '' ) {
                var whasha = whash+'a';
                if (jQuery(whasha).size() > 0 ) {
                    //console.log(whash+'a FOUND!');
                    jQuery(whasha).click();
                } else {
                    //console.log(whasha+' not found?');
                    var gnum = whash.substr(2);
                    //console.log('gnum = ' + gnum);
                    var gnumd = parseInt(gnum, 10);
                    //console.log('gnumd = ' + gnumd);
                    if (( '' + gnumd ) == gnum ) {
                        //console.log('load form for g/'+ gnum + ' ? ');
                        jQuery('<a />').attr('id',whasha.substr(1)).attr('href','g/'+gnum).addClass('gpop').hide().appendTo('body').click(turn_gpop).click();
                    } else {
                        //console.log(''+ gnumd + ' != ' + gnum + ' ? ');
                    }
                }
            }
        }
    }
);

function turn_gating_closepop() {
    jQuery('#dialog-gpopup').dialog('close');
    jQuery('#dialog-gpopup').hide();
}
