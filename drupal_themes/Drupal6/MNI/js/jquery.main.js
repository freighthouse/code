jQuery.noConflict(true);

jQuery(
    function(){

        jQuery(".login-box #edit-name-wrapper,.login-box #edit-pass-wrapper").wrapAll('<div class="form-row" />');
        jQuery(".login-box .item-list,.login-box #edit-submit").wrapAll('<div class="form-row" />');
        /*	jQuery("#fbconnect_button-wrapper").wrap('<div class="login-facebook"><div class="holder"></div></div>');*/
        /*	jQuery("#fbconnect_button-wrapper .description").html( 'Or log in to MNI with Facebook' );*/

        initTabs();
        jQuery('ul.accordion').acc(
            {
                speed: 400,
                active: 'selected',
                list: '.children()',
                opener: 'a.opener',
                slide: '.slide'
            }
        );
        jQuery('.navigation').crawlLine(
            {
                crawElement:'ul',
                textElement:'li'
            }
        );
        jQuery('a.win-close').click(
            function(){
                self.close();
                return false;
            }
        );
        jQuery('a.win-print').click(
            function(){
                window.print();
                return false;
            }
        );

    }
);

$(document).ready(
    function() {
        /* load fb activity feed asynch to speed rest of page */
        $('#fb_activity_feed_iframe').attr('src', "https://www.facebook.com/plugins/activity.php?site=mninews.deutsche-boerse.com&amp;width=295&amp;height=239&amp;header=true&amp;colorscheme=light&amp;font&amp;border_color&amp;recommendations=true"); 
    }
);


function initTabs() {
    jQuery('ul.tabset').each(
        function(){
            var _list = jQuery(this);
            var _links = _list.find('a.tab');

            _links.each(
                function() {
                    var _link = jQuery(this);
                    var _href = _link.attr('href');
                    var _tab = jQuery(_href);
                    var _tab_stories = jQuery('#tab_stories_'.concat(_href.charAt(4)));

                    if(_link.hasClass('active')) {
                        _tab.show();
                        _tab_stories.show();
                    }else{
                        _tab.hide();
                        _tab_stories.hide();
                    }

                    _link.click(
                        function(){
                            _links.filter('.active').each(
                                function(){
                                    jQuery(jQuery(this).removeClass('active').attr('href')).hide();
                                }
                            );
                            _link.addClass('active');
                            _tab.show();
                            _all_story_blocks=jQuery('.hp_story_block');
                            _all_story_blocks.hide();
                            _tab_stories.show();
                            return false;
                        }
                    );
                }
            );
        }
    );
}

jQuery.fn.acc = function(_options){
    var _options = jQuery.extend(
        {
            speed: 400,
            active: 'active',
            list: '.children()',
            opener: 'a.opener',
            slide: 'div.slide'
        }, _options
    );
    
    return this.each(
        function(){
            var _list = eval('jQuery(this)' + _options.list);
            var _active = _options.active;
            var _speed = _options.speed;
            var _a = _list.index(_list.filter('.' + _active + ':eq(0)'));
            if(_a != -1) { _list.removeClass(_active).eq(_a).addClass(_active); }
            for(var i = 0; i < _list.length; i++){
                _list.eq(i).data('btn', _list.eq(i).children(_options.opener).eq(0));
                _list.eq(i).data('box', _list.eq(i).children(_options.slide).eq(0));
                if(i == _a) { _list.eq(i).data('box').css('display', 'block'); }
                else { _list.eq(i).data('box').css('display', 'none'); }
                _list.eq(i).data('btn').data('ind', i);
                _list.eq(i).data('btn').click(
                    function(){
                        if (_list.eq(jQuery(this).data('ind')).data('box').length != 0) {
                            changeEl(jQuery(this).data('ind'));
                            return false;
                        }
                    }
                );
            }
            var anim_f = true;
            var a_h, ind_h, _k;
            function changeEl(_ind){
                if(anim_f) {
                    anim_f = false;
                    if(_a == _ind) {
                        _list.eq(_a).removeClass(_active).data('box').animate(
                            {height: 0}, {
                                duration: _speed,
                                complete: function(){
                                    jQuery(this).css({display:'none', height:'auto'});
                                    _a = -1;
                                    anim_f = true;
                                }
                            }
                        );
                    }
                    else{
                        _list.eq(_ind).data('box').css('display', 'block');
                        ind_h = _list.eq(_ind).data('box').outerHeight();
                        _list.eq(_ind).data('box').height(0);
                        if(_a != -1) {
                            a_h = _list.eq(_a).removeClass(_active).data('box').outerHeight();
                            _k = a_h/ind_h;
                        }
                        _list.eq(_ind).addClass(_active).data('box').animate(
                            {height: ind_h}, {
                                duration: _speed,
                                step: function(t_h){
                                    if(_a != -1) { _list.eq(_a).data('box').height(a_h - t_h*_k); }
                                },
                                complete: function(){
                                    _list.eq(_ind).data('box').height('auto');
                                    if(_a != -1) _list.eq(_a).data('box').css({display:'none', height: 'auto'});
                                    _a = _ind;
                                    anim_f = true;
                                }
                            }
                        );
                    }
                }
            }
        }
    );
}

/*******************************************************************************************/
// jquery.event.wheel.js - rev 1
// Copyright (c) 2008, Three Dub Media (http://threedubmedia.com)
// Liscensed under the MIT License (MIT-LICENSE.txt)
// http://www.opensource.org/licenses/mit-license.php
// Created: 2008-07-01 | Updated: 2008-07-14
// jQuery(body).bind('wheel',function(event,delta){    alert( delta>0 ? "up" : "down" );    });
/*******************************************************************************************/
;(function($){jQuery.fn.wheel=function(a){return this[a?"bind":"trigger"]("wheel",a)};jQuery.event.special.wheel={setup:function(){jQuery.event.add(this,b,wheelHandler,{})},teardown:function(){jQuery.event.remove(this,b,wheelHandler)}};var b=!jQuery.browser.mozilla?"mousewheel":"DOMMouseScroll"+(jQuery.browser.version<"1.9"?" mousemove":"");function wheelHandler(a){switch(a.type){case"mousemove":return jQuery.extend(a.data,{clientX:a.clientX,clientY:a.clientY,pageX:a.pageX,pageY:a.pageY});case"DOMMouseScroll":jQuery.extend(a,a.data);a.delta=-a.detail/3;break;case"mousewheel":a.delta=a.wheelDelta/120;if(jQuery.browser.opera) { a.delta*=-1; }break}a.type="wheel";return jQuery.event.handle.call(this,a,a.delta)}})(jQuery);

jQuery.fn.crawlLine = function(_options){
    // defaults options
    var _options = jQuery.extend(
        {
            speed:2,
            crawElement:'div',
            textElement:'p',
            hoverClass:'viewText'
        },_options
    );
    
    return this.each(
        function(){
            var _THIS = jQuery(this);
            var _el = jQuery(_options.crawElement, _THIS).css('position','relative');
            var _text = jQuery(_options.textElement, _THIS);
            var _clone = _text.css('whiteSpace','nowrap').clone();
            var _elWidth = 0;
            var _k = 1;
        
            // set parametrs *******************************************************
            var _textWidth = 0;
            _text.each(
                function(){
                    _textWidth += jQuery(this).outerWidth(true);
                }
            );
            var _duration = _textWidth*50 / _options.speed;
            _el.append(_clone);
            _el.css('width',_textWidth*2);
        
            var animate = function() {
                _el.animate(
                    {left:-_textWidth}, {queue:false, duration:_duration*_k, easing:'linear', complete:function(){
                        _el.css('left','0');
                        _k=1;
                        animate();
                    }}
                )
            }
            animate();
        
            _THIS.hover(
                function() {
                    _el.stop();
                    _THIS.addClass(_options.hoverClass);
                }, function(){
                    _THIS.removeClass(_options.hoverClass);
                    _k = (_textWidth + parseInt(_el.css('left')))/_textWidth;
                    animate();
                }
            )
            _THIS.bind(
                'wheel',function(event,delta){
                    var _marginScroll;
                    if (delta<0) {
                        _marginScroll = parseInt(_el.css('left')) - 20;
                        _el.animate(
                            {left:_marginScroll}, {queue:false, duration:100, easing:'linear', complete:function(){
                                _k = (_textWidth + parseInt(_el.css('left')))/_textWidth;
                            }}
                        );
                    } else {
                        _marginScroll = parseInt(_el.css('left')) + 20;
                        if (_marginScroll > 0) { _marginScroll = 0; }
                        _el.animate(
                            {left:_marginScroll}, {queue:false, duration:100, easing:'linear', complete:function(){
                                _k = (_textWidth + parseInt(_el.css('left')))/_textWidth;
                            }}
                        );
                    }
                    return false;
                }
            );
        }
    );
}


/* regular js scripts */
function openpopup(url,w,h) 
{
    //var left   = (screen.width  - width)/2;
    //var top    = (screen.height - height)/2;
    var params = 'width='+w+', height='+h;
    //params += ', top='+top+', left='+left;
    params += ', directories=no';
    params += ', location=no';
    params += ', menubar=no';
    params += ', resizable=yes';
    params += ', scrollbars=yes';
    params += ', status=no';
    params += ', toolbar=no';
    newwin=window.open(url,'', params);
    if (window.focus && newwin) {newwin.focus()}
    return newwin?false:true; // if popup blocker, use default link
}


