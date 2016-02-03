<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; 
} ?><?php if (!$status) { print ' node-unpublished'; 
} ?>">

    <?php print $picture ?>

    <?php if ($page == 0) : ?>
	<h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php 
    endif; ?>

	<div class="content">
    <?php 
    if(mni_misc_functions_node_is_txttbl($node) && $node->type != 'alacarte_article') {
        print("<pre>".str_replace("<br />", "", $content)."</pre>");
    
    } else {
         print($content);
    
    }
    ?>
	</div>

	
<?php 
if(arg(0)!='archive') { //a more generic test for non-page views of the node would be better, but right now i'm just trying to get the week module to display these in a decent way
    if ($taxonomy) { 
    ?>
   <div class="meta">
   <h2 class="nodesection">See Related Headlines:</h2>
    <?php 
     $links=MNI_taxonomy_link($node);
     print theme('links', $links);
    ?>
   </div>
    <?php 
    }
    if($node->type =='free_article' && !mni_misc_functions_user_is_logged_in()) {
        print("<h2>Please <a href='/user'>log in</a> to read and leave comments</h2>");
    
    }

}
?>
</div>
