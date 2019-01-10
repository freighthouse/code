function findOfficials(){

	var address=jQuery("#edit-address").val();
	var city=jQuery("#edit-city").val();
	var state=jQuery("#edit-state").val();
	var zip=jQuery("#edit-zip").val();
	var campaign_id=getQueryVariable("campaign_id");
	var error=false;

	if(address===""){
		jQuery("#edit-address").css("border","#B80003 1px solid");
		error=true;
	}
	if(city===""){
		jQuery("#edit-city").css("border","#B80003 1px solid");
		error=true;
	}

	if(zip===""){
		jQuery("#edit-zip").css("border","#B80003 1px solid");
		error=true;
	}

	if (!campaign_id) {error=true;}

	if(error){
		jQuery("#error_msg").html("*Please fill out all required fields.");
	}
	else
	{
		jQuery("#error_msg").html("");

		jQuery('div#tweeter_representatives').html("Please wait.<br /><img src='/sites/all/modules/custom/tweetrep/processing_bar.gif' />");
		jQuery('div#tweeter_representatives').show();

		var address_cp=address+city+state+zip;
		var data_add;

		if(address_cp !== ""){
			data_add = {
				address:address,
				city: city,
				state:state,
				zip:zip,
				campaign_id:campaign_id,
			};

			jQuery.ajax({
				url: '/tweet_API/tweetreps',
				type: 'GET',
				data: data_add,
				success: function(data) {

						address=data.address;
					city=data.city;
					state=data.state;
					zip=data.zip;
					us_government=data.us_government;
					state_government=data.state_government;
					var html_us_sen="";
					var html_us_rep="";
					var html_st_sen="";
					var html_st_del="";
					var html_st_rep="";
					var html_st_gov="";
					var html="";
					var notwetter='This elected official does not have an official Twitter account.';

					//US officials
					for (var i=0; i<us_government.length ;i++) {
						//if we have us officials
						if(typeof(us_government[i]!=="undefined")){
							//console.log(us_government[i]['type']);
							if(us_government[i]['type']==="US Senator"){
								if(html_us_sen===""){
									html_us_sen="<h3>Tweet Your U.S. Senator(s)</h3>";
								}
								html_us_sen+='<div class="official_twitter"><div class="preview"><span class="official_name">'+us_government[i]['name']+'</span>';
								if(us_government[i]['tweet']!=="No Twitter account available"){
									html_us_sen+='<textarea disabled="disabled">'+us_government[i]['tweet']+'</textarea></div><div class="link"><a class="official-social-twitter-link" href="http://twitter.com/intent/tweet?text='+encodeURIComponent(us_government[i]['tweet'])+'" target="_blank">Tweet This</a></div></div>';
								}else
								{
									html_us_sen+='<span class="notwitter">'+us_government[i]['tweet']+'</span></div></div>';
								}
							}


							if(us_government[i]['type']==="US Representative"){
								if(html_us_rep===""){
									html_us_rep+="<h3>Tweet Your U.S. Representative</h3>";
								}
								html_us_rep+='<div class="official_twitter"><div class="preview"><span class="official_name">'+us_government[i]['name']+'</span>';
								if(us_government[i]['tweet']!=="No Twitter account available"){
									html_us_rep+='<textarea disabled="disabled">'+us_government[i]['tweet']+'</textarea></div><div class="link"><a class="official-social-twitter-link" href="http://twitter.com/intent/tweet?text='+encodeURIComponent(us_government[i]['tweet'])+'" target="_blank">Tweet This</a></div></div>';
								}else
								{
									html_us_rep+='<span class="notwitter">'+us_government[i]['tweet']+'</span></div>';
								}
							}
						}
					}

					for (var i=0; i< state_government.length ;i++) {
						if(typeof(state_government[i]!=="undefined")){
							//console.log(state_government[i]);
							if(state_government[i]['type']==="State Senator"){

								//console.log(html_st_sen);
								html_st_sen+='<div class="official_twitter"><div class="preview"><span class="official_name">'+state_government[i]['name']+'</span>';
								if(state_government[i]['tweet']!=="No Twitter account available"){
									html_st_sen+='<textarea disabled="disabled">'+state_government[i]['tweet']+'</textarea></div><div class="link"><a class="official-social-twitter-link" href="http://twitter.com/intent/tweet?text='+encodeURIComponent(state_government[i]['tweet'])+'" target="_blank">Tweet This</a></div></div>';
								}else
								{
									html_st_sen+='<span class="notwitter">'+notwetter+'</span></div></div>';
								}


							}
							if(state_government[i]['type']==="State Delegate"){
								html_st_del+='<div class="official_twitter"><div class="preview"><span class="official_name">'+state_government[i]['name']+'</span>';

								if(state_government[i]['tweet']!=="No Twitter account available"){
									html_st_del+='<textarea disabled="disabled">'+state_government[i]['tweet']+'</textarea></div><div class="link"><a class="official-social-twitter-link" href="http://twitter.com/intent/tweet?text='+encodeURIComponent(state_government[i]['tweet'])+'" target="_blank">Tweet This</a></div></div>';
								}else
								{
									html_st_del+='<span class="notwitter">'+notwetter+'</span></div></div>';
								}
								/*<textarea disabled="disabled">'+state_government[i]['tweet']+'</textarea></div><div class="link"><a id="post-to-twitter" class="representative" href="http://twitter.com/intent/tweet?text='+encodeURIComponent(state_government[i]['tweet'])+'" target="_blank">Tweet This</a></div>';*/
							}

							if(state_government[i]['type']==="State Representative"){
								html_st_rep+='<div class="official_twitter"><div class="preview"><span class="official_name">'+state_government[i]['name']+'</span>';


								if(state_government[i]['tweet']!=="No Twitter account available"){
									html_st_rep+='<textarea disabled="disabled">'+state_government[i]['tweet']+'</textarea></div><div class="link"><a class="official-social-twitter-link" href="http://twitter.com/intent/tweet?text='+encodeURIComponent(state_government[i]['tweet'])+'" target="_blank">Tweet This</a></div></div>';
								}else
								{
									html_st_rep+='<span class="notwitter">'+notwetter+'</span></div></div>';
								}
							}



							if(state_government[i]['type']==="Governor"){

								html_st_gov+='<div class="official_twitter"><div class="preview"><span class="official_name">'+state_government[i]['name']+'</span>';


								if(state_government[i]['tweet']!=="No Twitter account available"){
									html_st_gov+='<textarea disabled="disabled">'+state_government[i]['tweet']+'</textarea></div><div class="link"><a class="official-social-twitter-link" href="http://twitter.com/intent/tweet?text='+encodeURIComponent(state_government[i]['tweet'])+'" target="_blank">Tweet This</a></div></div>';
								}else
								{
									html_st_gov+='<span class="notwitter">'+notwetter+'	</span></div></div>';
								}
							}
						}
					}

					if(html_us_sen!==""){html_us_sen="<div class='group'>"+html_us_sen+"</div>";}

					if(html_us_rep!==""){html_us_rep="<div class='group'>"+html_us_rep+"</div>";}
					if(html_st_sen!==""){html_st_sen="<div class='group'><h3>Tweet Your State Senator(s)</h3>"+html_st_sen+"</div>";}
					if(html_st_del!==""){html_st_del="<div class='group'><h3>Tweet Your State Delegate(s)</h3>"+html_st_del+"</div>";}
					if(html_st_rep!==""){html_st_rep="<div class='group'><h3>Tweet Your State Representative(s)</h3>"+html_st_rep+"</div>";}
					if(html_st_gov!==""){html_st_gov="<div class='group'><h3>Tweet Your State Governor</h3>"+html_st_gov+"</div>";}

					html=html_us_sen+html_us_rep+html_st_gov+html_st_sen+html_st_rep+html_st_del;

					//console.log(html);
					if(html===""){html="No records found";}
					jQuery('div#tweeter_representatives').slideUp(0);
					jQuery('div#tweeter_representatives').html(html);
					jQuery('div#tweeter_representatives').slideDown(500);

					jQuery(document).scrollTop( jQuery("#tweeter_representatives").offset().top + 250 );

				},
				error: function(error) {
					console.log(error);
					return false;
				}
			});
		}
	}
}

function getQueryVariable(variable){
	var query = window.location.search.substring(1);
	var vars = query.split("&");
	for (var i=0;i<vars.length;i++) {
			var pair = vars[i].split("=");
			if(pair[0] == variable){return pair[1];}
	}
	return(false);
}