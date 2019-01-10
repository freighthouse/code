<script type="text/javascript">
(function( w ){
    // if the class is already set, we're good.
    if( w.document.documentElement.className.indexOf( "fonts-loaded" ) > -1 ){
        return;
    }
    var fontA = new w.FontFaceObserver( "Open Sans", {
        weight: 300
    });
    var fontB = new w.FontFaceObserver( "Open Sans", {
        weight: 500
    });
    var fontC = new w.FontFaceObserver( "Open Sans", {
        weight: 700
    });
    w.Promise
        .all([fontA.check(), fontB.check(), fontC.check()])
        .then(function(){
            w.document.documentElement.className += " fonts-loaded";
            w.document.cookie="_ez_fonts_loaded=true";
        });
}( this ));
</script>