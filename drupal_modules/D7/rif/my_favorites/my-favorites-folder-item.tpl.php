<div class="favorites-table-item">
	<div class="row">
		<div class="col-xs-4 col-sm-3 col-md-3 col-lg-2">
			<a href="<?php print $node_url; ?>">
				<div class="image-container">
					<?php print $bookCover ?>
				</div>
			</a>
		</div>

		<div class="col-xs-8 col-sm-9 col-md-9 col-lg-10">
			<?php if($has_children): ?>
			<a class="pull-right collapsed toggle" data-toggle="collapse" href="#collapseExample<?= $container_id; ?>" aria-expanded="false" aria-controls="collapseExample<?= $container_id; ?>">
				<i class="fa fa-chevron-down"></i>
				<i class="fa fa-chevron-up"></i>
			</a>
			<?php endif; ?>

			<h2 class="hidden-xs"><?php print $title; ?></h2>
			<h3 class="hidden-xs"><?php print $contributors; ?></h3>
		</div>

	</div>
	<?php if($has_children): ?>
	<div class="row collapse" id="collapseExample<?= $container_id; ?>" aria-expanded="false" style="height: 0px;">

		<div class="col-md-12">

			<div class="favorites-table-item-list">
				<div class="well">

					<div class="support-materials">

						<div class="panel panel-default panel-support-materials">
							<div class="panel-body">

								<?php print render($support_materials); ?>

							</div>
						</div>

					</div>

				</div>
			</div>

		</div>

	</div>
	<?php endif; ?>
</div>
