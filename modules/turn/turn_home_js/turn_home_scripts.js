(function($) { 
    $(function() {
        $('.greypurple').hover(
            function () {
                $(this).removeClass("greypurple");
                $(this).addClass("darkgrey");
            }, 
            function () {
                $(this).removeClass("darkgrey");
                $(this).addClass("greypurple");

            });
        $('.locationlink').hover(
            function () {
                $(this).removeClass("ltteal");
                $(this).addClass("darkgrey");
            },
            function () {
                $(this).removeClass("darkgrey");
                $(this).addClass("ltteal");

            });

        $('.locationlink ').click(function () { 
            window.location.href = '/locations/';
        });  

        $('#baplink ').click(function () {
            window.location.href = '/become-a-partner/';
        });

        $('#bigrightfeature').hover(
            function () {
  	
                $('#campaigndatatext').show();
                $(this).find('.half_first').dequeue();
                $('#campaigndatacontent').dequeue();
                $('#campaigndatacontent').animate({
                    marginTop: 100
                }, 500, function() {    
    		
                    });

                $(this).find('.half_first').animate({
                    height: '0%'
                }, 500, function() {    
    		
                    });
                $(this).find('.half_second').dequeue();
                $(this).find('.half_second').animate({
                    height: '100%'
                }, 500, function() {    
    		
                    });
            }, 
            function () { 
                $('#campaigndatatext').hide();	
                $('#campaigndatacontent').dequeue();
                $('#campaigndatacontent').animate({
                    marginTop: 10
                }, 500, function() {    
    		
                    });

                $(this).find('.half_first').dequeue();
                $(this).find('.half_first').animate({
                    height: '58%'
                }, 500, function() {    
    		
                    });
                $(this).find('.half_second').dequeue();
                $(this).find('.half_second').animate({
                    height: '42%'
                }, 500, function() {    
    		
                    });
        });

        $('#homeFeatureJobs').hover(
            function () {
                $('#homeFeatureJobsText').hide();
  	
                $(this).find('.slide').dequeue();
                $(this).find('.slide').animate({
                    width: '100%',
                    borderTopRightRadius: 8,
                    borderBottomRightRadius: 8
                }, 500, function() {    
    		
                    });
                $('#homeFeatureJobsText').dequeue();	
                $('#homeFeatureJobsText').delay(300).fadeIn(200);
            }, 
            function () { 	
                $('#homeFeatureJobsText').dequeue();
                $('#homeFeatureJobsText').hide();
                $(this).find('.slide')

  	
                $(this).find('.slide').animate({
                    width: '53%',
                    borderTopRightRadius: 0,
                    borderBottomRightRadius: 0
                }, 500, function() {
    		
		
                    });
  	


            });

        $('.hiddenArrow').hide();
        $('.hoverblock').delay(800).fadeTo('slow', 0.5, function() {
            // Animation complete.
            });
        $('.bioItem').click(function () {
            window.location.href = $(this).attr('data-path');
        });
    
        $('.bioItem').hover(
            function(){
                $(this).children('.hoverblock').dequeue().fadeTo('fast', 1.0, function() {
                    // Animation complete.
                    });
                $(this).children('.hoverblocktext').find('.nameText').css("color","lightblue");
                $(this).children('.hoverblocktext').find('.hiddenArrow').show();
            },
            function(){
                $(this).children('.hoverblock').dequeue().fadeTo('slow', 0.5, function() {
                    // Animation complete.
                    });
                $(this).children('.hoverblocktext').find('.nameText').css("color","white");
                $(this).children('.hoverblocktext').find('.hiddenArrow').hide();
            });


        $( "#dialog-video" ).dialog({
            height: 421,
            width: 674,
            modal: true,
            autoOpen: false,
            resizable: false,
        }).bind( "dialogopen", function(event, ui) {
			$('#dialog-video').css({'height':373,'overflow':'hidden'}).html('<iframe frameborder="0" height="370" src="/sites/all/themes/turn/video_meet_turn_home.html" width="650"></iframe>');
		}).bind("dialogclose", function(event,ui) {
			$('#dialog-video').empty();
		});
		
        $('#mainfeature').click(function () {
			$( "#dialog-video" ).dialog( "open" );
		});
		
        $('.tabitem').click(function () {
            $('.tabitem').removeClass('orangetab_btn');
            $('.tabitem').addClass('greytab_btn');
            $(this).removeClass('greytab_btn');
            $(this).addClass('orangetab_btn');

            var childitem = $(this).attr('href');
            $('#subsections').children().hide();
            $(childitem).show();
            console.log($(childitem));
            return false;

        });

        $('#subsections').children().hide();
        $('#subsections').children(':first').show();

        /* Replace with live url on launch
     * http://console.turn.com/jax/cloudmetrics/qps
     * wp-content/themes/turn/qps.txt
     */

   
        if ($('#rtqps').length){ 
            getqps();
            setInterval(function(){
                getqps();
            }, 2000);
        }
        function getqps() {
        
            $.getJSON('/sites/all/modules/turn_home_js/qps.php', function(data) {
                var items = [];

                $.each(data, function(key, val) {
                    var adustedval = addCommas(Math.round(val));
                    items.push("" + adustedval);
                });

                $('#rtqps').html(items[0]);
            });
        
        }

    

        $('.partnerbox').hide();
        $('.partneritem').mouseenter(
            function(e) {
                $(this).mousemove(function(e){
                    $(this).children('.partnerbox').css({
                        'postion':'absolute',
                        'top': e.pageY+10, 
                        'left': e.pageX+10
                    });    
                });
                $(this).children('.partnerbox').show();
            });

        $('.partneritem').mouseleave(function(e) {
            $(this).children('.partnerbox').hide();
        });

        function addCommas(nStr)
        {
            nStr += '';
            x = nStr.split('.');
            x1 = x[0];
            x2 = x.length > 1 ? '.' + x[1] : '';
            var rgx = /(\d+)(\d{3})/;
            while (rgx.test(x1)) {
                x1 = x1.replace(rgx, '$1' + ',' + '$2');
            }
            return x1 + x2;
        }

        function trace(s) {
            try {
                console.log(s)
            } catch (e) {
                var error =s;
            }
        };

    
     
    });

})(jQuery);
