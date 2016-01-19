//we need the cookie guid value (3rd party Eloqua cookie)
var elqTracker = new jQuery.elq(1852860672);
//1st, make standard tracking call
elqTracker.pageTrack({success: function() {
    //2nd, grab eloqua cookie value
    elqTracker.getGUID(function(guid) {
        //3rd, place eloqua cookie in 1st party cookie
        var exDate = new Date()
        exDate.setDate(exDate.getDate() + 365);
        document.cookie = "ELOQUA=" + guid + "; expires=" + exDate.toUTCString();
		
		jQuery("input[name*=elqcustomerguid]").val(guid);
    });				
}});