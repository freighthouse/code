<?php
/**
 * @file dashboard_product.tpl.php
 *
 * Variables available:
 * 
 *      $launch_url
 * 			$product_name
 * 			$product_url_name
 * 			$tabs[] //array of tabs and menus
 *				for each tab in tabs:
 *					tab_name
 *					tab_machine_name
 *					tab_item_count
 *					menu_links[]
 *						for each menu in menus:
 *							menu_links html 
 */
?>
							<div class="buttons-area">
								<?php /*<a class="btn link-window" href="<?php print $launch_url; ?>">Launch <?php print $product_name; ?></a>*/ ?>
								<a class="btn" href="<?php print $launch_url; ?>" onclick="<?php print $launch_js; ?>">Launch <?php print $product_name; ?></a>
							</div>
<?php
if(count($tabs)){
?>
							<div class="dashboard">
								<div class="block">
									<h3>Available Content</h3>
									<div class="area">
										<div class="frame">
<?php
	foreach ($tabs as $tab): 
?>
											<ul id="tab_<?php print $tab['tab_machine_name']; ?>">
<?php
		foreach ($tab['menu_links'] as $menu){
			echo ($menu); 
		}
?>
											</ul> 
<?php
	endforeach;
?>
										</div>
									</div>
									<ul class="list tabset">
<?php
	$i=0;
	foreach ($tabs as $tab): 
		$i++;
?>
										<li><a href="#tab_<?php print $tab['tab_machine_name']; ?>" class="tab<?php if($i==1){ print ' active'; }?>"><?php print $tab['tab_name']; ?> (<?php print $tab['tab_item_count']; ?>)</a></li>
<?php
	endforeach;
?>
									</ul>
								</div>
								<h3><strong><?php print $product_name; ?> :</strong> Last Viewed</h3>
								<?php echo(mni_dashboard_display_last_viewed($product_url_name)); ?>
							</div>

<?php
}
?>
