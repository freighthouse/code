function getCookie(c_name){
    var i,x,y,ARRcookies=document.cookie.split(";");
    for (i=0;i<ARRcookies.length;i++){
        x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
        y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
        x=x.replace(/^\s+|\s+$/g,"");
        if (x==c_name) {
            return unescape(y);
        }
    }
    return "";
}

function set_form_cookie(cookie, field_name){
    var cur_cookie_field = document.forms["eloqua_form"].elements["submitted["+field_name+"]"];
    if(cur_cookie_field) {
        cur_cookie_field.value = getCookie(cookie);
    }else{
        var cur_cookie_field = document.forms["eloqua_form"].elements[field_name];
        if(cur_cookie_field) {
            cur_cookie_field.value = getCookie(cookie);
        }
    }
}

jQuery(document).ready(
    function(){
        var cookie_fields = {cmpid: 's_campaign', retouchcmpid: 's_ev2', turnuserid: 'uid'};
        for(i in cookie_fields){
            set_form_cookie(cookie_fields[i], i);
        }
    }
);