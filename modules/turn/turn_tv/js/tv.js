var tv_statflipper, tv_stattime = 4000, tv_statreload = 300000, tv_twflipper, tv_twtime = 5000, tv_twmax = 20, tv_twi, tv_twreload = 10800000; // yea 3 hours

var turntvon = 0;
var turntvids = ['N0ODdnNDoLVdY39hxYTwlEwhOt3sWT4T','R0dXVtNTpSer4tu3M_-QpvFv6pFOE_tt','1ia25nODrlYyEEitOsMCCoKOHv_bCKOz'];
var turntvplayer;

OO.ready(
    function() {
        turntvplayer = OO.Player.create(
            'tvid', turntvids[turntvon], {
                width: 1376,
                height: 774,
                wmode: 'opaque',
                onCreate: function(player) {
                    //console.log('player created 1 2 3');
                    /*
                    player.mb.subscribe('*', 'turntv', function(eventName) {
                    if ( eventName != 'playheadTimeChanged' ) console.log('** named '+ eventName +' **');
                    });
                    */
                    player.mb.subscribe(
                        'played', 'turntv', function() {
                            //jQuery('#tvtemp').fadeIn(200);
                            turntvon++;
                            if (turntvon >= turntvids.length ) { turntvon = 0; }
                            //console.log('ttt setting embed code to vid #'+ turntvon);
                            turntvplayer.setEmbedCode(turntvids[turntvon]);
                            //console.log('ttt set?');
                        }
                    );
                
                    player.mb.subscribe(
                        'playbackReady', 'turntv', function() {
                            turntvplayer.play();
                            //console.log('ttt playing...');
                        }
                    );
                    /*
                    player.mb.subscribe('playing', 'turntv', function() {
                    jQuery('#tvtemp').fadeOut(600);
                    });
                    */                
                }
            }
        );
    }
);

function tv_qps() {
    jQuery.getJSON(
        '/sites/all/modules/turn_home_js/qps.php', function(data) {
            var items = [];

            jQuery.each(
                data, function(key, val) {
                    var adustedval = tv_addCommas(Math.round(val));
                    items.push("" + adustedval);
                }
            );

            jQuery('#rtqps').html(items[0]).shuffleLetters(
                {
                    step: 5
                }
            );
        }
    );
}

function tv_addCommas(nStr) {
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

function tv_stat() {
    clearTimeout(tv_statflipper);
    jQuery.getJSON(
        '/sites/all/modules/turn_tv/stats.php', function(data) {
            var tvc = ['America','Asia','Europe'];
            var tvr = ['AdServer','Presentation','Datamine','ConsoleLatency'];
            var oot = '';
            for ( var j in tvc ) {
                var rname = tvc[j];
                if (rname == 'America' ) { rname += 's'; }
                oot += '<div class="stats"><div class="region">'+ rname +'</div>';
                for ( var i in tvr ) {
                    var cname = tvr[i];
                    switch ( tvr[i] ) {
                    case 'AdServer':
                        cname = 'Ad Servers';
                      break;
                    case 'Presentation':
                        cname = 'Data Collection';
                      break;
                    case 'ConsoleLatency':
                        cname = 'Application Latency';
                      break;
                    }
                    oot += '<div class="row"><div class="name">'+ cname + '</div><div class="icon ';
                    var icnclass = 'err';
                    if(jQuery.type(data[tvr[i]][tvc[j]]) == 'object' ) {
                        icnclass = data[tvr[i]][tvc[j]]['Status'];
                    }
                    oot += icnclass +'"></div></div>';
                }
                oot += '</div>';
            }
            jQuery('#tvstats').empty().html(oot);
            // and then?
            jQuery("#tvstats .stats:first").addClass('onn');
        
            tv_statflipper = setTimeout(tv_statflip, tv_stattime);
        }
    );
}

function tv_statflip() {
    clearTimeout(tv_statflipper);
    var onn = jQuery('#tvstats .onn');    
    var nex = onn.next();
    if (nex.size() == 0 ) { nex = onn.parent().children(':first-child'); }
    
    onn.find('.icon').fadeOut(300);
    //setTimeout( function() {
    onn.find('.region').animate(
        {
            opacity: 0,
            right: 0
        }, 400, function() {
            nex.find('.region').css({'opacity':0,'right':'17px'});
            nex.find('.icon').fadeOut(10);
            nex.show();
            onn.hide().removeClass('onn');
            nex.addClass('onn').find('.region').animate(
                {
                    opacity: 1,
                    right: '7px'
                }, 400, function() {
                    nex.children('.row:eq(0)').children('.icon').fadeIn(300);
                    setTimeout(
                        function() {
                            nex.children('.row:eq(1)').children('.icon').fadeIn(300);
                        }, 200
                    );
                    setTimeout(
                        function() {
                            nex.children('.row:eq(2)').children('.icon').fadeIn(300);
                        }, 400
                    );
                    setTimeout(
                        function() {
                            nex.children('.row:eq(3)').children('.icon').fadeIn(300);
                        }, 600
                    );
                    tv_statflipper = setTimeout(tv_statflip, tv_stattime);
                }
            );
        }
    );
    //}, 300);
    
}

function tv_tweets() {
    clearTimeout(tv_twflipper);
    jQuery('#tweetshere').load(
        '/tweets .view-content', function() {
            tv_twi = -1;
            tv_twflip();
        }
    );
}

function tv_twflip() {
    clearTimeout(tv_twflipper);
    
    tv_twi++;
    if (tv_twi >= tv_twmax ) { tv_twi = 0; }
    
    var curr = jQuery('#twqr').siblings('.text');
    if (curr.size() > 0 ) {
        curr.animate(
            {
                opacity: 0,
                left: '25px'
            }, 200, function() {
                jQuery(this).remove();
            }
        );
    }
    setTimeout(
        function() {
            jQuery('#tweetshere .views-row:eq('+tv_twi+') .text').clone().css({'opacity':0,'left':'-25px'}).insertAfter('#twqr').animate(
                {
                    opacity: 1,
                    left: 0
                }, 400, function() {
                    tv_twflipper = setTimeout(tv_twflip, tv_twtime);
                }
            );
        }, 200
    );
}

function tv_tix() {
    jQuery.getJSON(
        '/sites/all/modules/turn_tv/js/tick-sample.json', function(data) {
            var ticks = data['ticks'];
            var oot = '';
            for ( var i in ticks ) {
                if (i < 7 ) {
                    oot += '<div class="tick"><span class="n">'+ ticks[i]['name'] + '</span><span class="p">'+ ticks[i]['price']+'</span></div>';
                }
            }
            jQuery('#tix').empty().html(oot);
        }
    );
}

jQuery(
    function($) {
        if ($('#ttv').size() > 0 ) {
        
            if ($('#rtqps').length) { 
                tv_qps();
                setInterval(
                    function(){
                        tv_qps();
                    }, 2000
                );
            }
        
            if ($('#tvstats').length) { 
                tv_stat();
                setInterval(
                    function(){
                        tv_stat();
                    }, tv_statreload
                );
            }
        
            if ($('#tweetshere').length) { 
                tv_tweets();
                setInterval(
                    function(){
                        tv_tweets();
                    }, tv_twreload
                );
            }
        
            if ($('#tix').length) { 
                tv_tix();
                setInterval(
                    function(){
                        tv_tix();
                    }, tv_statreload
                );
            }
        }
    }
);
