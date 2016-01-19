// JavaScript Document
var colors = new Object();

colors['1'] = "url('sites/all/modules/mnipriority/images/connect_red.png') 50% 4px no-repeat"
colors['2'] = "url('sites/all/modules/mnipriority/images/connect_yellow.png') 50% 4px no-repeat"
colors['3'] = "url('sites/all/modules/mnipriority/images/connect_green.png') 50% 4px no-repeat"
colors['4'] = '';

	function priorityfunc() {
		if ($("th.priority").size() == 0)
		{
		$("table.views-table thead tr th.views-field-phpcode-1").prev().before("<th class='priority'>P</th>");
		$("table.views-table tbody tr td.views-field-phpcode-1").each( function(index, element) {
			var fractions = $(element).text().split(":");

			priority = 4;

			if (fractions.length > 2) 
 			{
				boilerplate = fractions[0];
				boilerplate = boilerplate.replace(/^\s+/g,"");

				if (boilerplate == "BULLET" )
				{
					prefix = fractions[1].replace(/^\s+/g,"");
				
					priority = 3;

					if (prefix in priorities)
					{
						priority = priorities[prefix];
					}	
				} 
			} 
		
			$(element).prev().before("<td class='priority'>"+"</td>");

			if (priority != 4) 
			{
			 	$(element).prev().prev().css('background', colors[priority]);
			}
		});
		}
	}
	
	$(function() {
		priorityfunc();
	});
	
// This will reload the .tbody element every x number of seconds
	
	$(function(){
	
	var refreshId = setInterval(function() { 
		$('body').prepend('<div style="display:none"><div id="hiddendragon"></div></div>');
		$('#hiddendragon').load(window.location.href+" tbody", priorityfunc);
		}, 50000);
	});
		
	function dragonfunc() {
		$('table.views-table tbody').replaceWith(
		$('#hiddendragon tbody'));
	}