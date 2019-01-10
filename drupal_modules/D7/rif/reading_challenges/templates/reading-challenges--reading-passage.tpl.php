<div class="container panel-push-down">
	<div class="row">
		<div class="col-sm-12">
			<div class="panel panel-default">
				<div class="panel-heading">
                    <?php $_SESSION['passage_title'] = $reading_passage_title; ?>
					<h2><?php print $reading_passage_title; ?></h2>
				</div>
				<div class="panel-body">
					<?php print render($submit_form); ?>
				</div>
			</div>
		</div>
	</div>
</div>

<div class="modal" role="dialog" id="modal-that-was-fast">
	<div class="modal-dialog modal-lg" role="document">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
				<h4 class="modal-title">
					<img src="/sites/all/themes/custom/rif/public/assets/images/rif-logo-lg.png" />
				</h4>
			</div>
			<div class="modal-body">
				That was fast... are you sure you read the full passage?<br />
			</div>
			<div class="modal-footer">
				<a type="button" id="modal-confirm" class="btn btn-yellow-rif blue-border pull-right">Yes</a>
				<a type="button" id="modal-cancel" data-dismiss="modal" class="btn btn-yellow-rif blue-border pull-left">Try Again</a>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->