// JavaScript Document

$(document).ready(
    function(){
        
        // 0 Main Wire
        // 1 MNI Bullets
        // 2 MNI FI
        // 3 MNI FX
        // 4 MNI Credit
        // 5 MNI Monitor


        $("ul#nav div.drop:eq(0)  li:gt(0):lt(4)").wrapAll('<div class="products"/>');
        //$("div.products li:eq(0) a").removeAttr('href');
        $("ul#nav div.drop:eq(0)  li:gt(1):lt(3)").hide();
        $("div.products").hover(
            function() {
                $("ul#nav div.drop:eq(0) li:gt(1):lt(3)").show();
            },
            function() {
                $("ul#nav div.drop:eq(0)  li:gt(1):lt(3)").hide();
            }
        );
    }
);