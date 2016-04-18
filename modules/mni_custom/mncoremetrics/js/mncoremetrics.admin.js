// @author: Jeremy Cerda
// @version: $Id: mncoremetrics.admin.js 2697 2011-09-28 14:10:16Z jcerda $

function mncoremetrics_admin_flipdisabled(to) {
    $("form#mncoremetrics-admin-main-form input")
    .each(
        function(){
            if($(this).attr("type") != "hidden" 
                && $(this).attr("id") != "edit-submit" 
                && $(this).attr("id") != "edit-config-load"
            ) {
                if(to) {
                    $(this).attr('disabled', 'true');
                } else {
                    $(this).removeAttr('disabled');
                }
            }
        }
    )

    if(to) {
        $("form#mncoremetrics-admin-main-form input#edit-submit")
        .attr("value", "Reload");
    } else {
        $("form#mncoremetrics-admin-main-form input#edit-submit")
        .attr("value", "Save");
    }
}

function mncoremetrics_admin_config_load_click() {
    mncoremetrics_admin_flipdisabled($("input#edit-config-load").attr('checked'));
}

jQuery(document).ready(
    function(){
        if($("input#edit-config-load").attr('checked')) {
            mncoremetrics_admin_flipdisabled(true);
        }
    }
);
