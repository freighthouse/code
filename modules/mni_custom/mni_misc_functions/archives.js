// JavaScript Document

$(document).ready(function() {
	$('ul.archivemonth').hide();
	$("ul.archivemonth:first").show();
	$("ul.archive > li").click(function(){
//	$("ul.archivemonth").hide();
//	$(this).next().show("slow");
//	});
//});
	$('ul.archivemonth').slideUp('normal');
		if($(this).next().is(':hidden') == true) {  
		$(this).next().slideDown('normal');
	 } 
	 });
});

