<div class="container panel-push-down">
	<div class="row">
		<div class="col-sm-12">
			<div class="panel panel-default">
				<div class="panel-heading">
					<h2>You have completed the Challenge!</h2>
				</div>
				<div class="panel-body">

                    <div class="row">

                        <div class="col-md-3">
                            <p><strong>Reading Passage:</strong></p>
                        </div>
                        <div class="col-md-9">
                            <?php $reading_passage_title = $_SESSION['passage_title']; ?>
                            <p><?php print $reading_passage_title; ?></p>
                        </div>

                    </div>

                    <div class="row">

                        <div class="col-md-3">
                            <p><strong>Total Words:</strong></p>
                        </div>
                        <div class="col-md-9">
                            <p><?php print $total_words; ?></p>
                        </div>

                    </div>

                    <div class="row">

                        <div class="col-md-3">
                            <p><strong>Words Selected:</strong></p>
                        </div>
                        <div class="col-md-9">
                            <p><?php print $clicked_words; ?></p>
                        </div>

                    </div>

                    <div class="row">

                        <div class="col-md-3">
                            <p><strong>Time Taken:</strong></p>
                        </div>
                        <div class="col-md-9">
                            <p><?php print $minutes.'m '.$seconds.'s'; ?></p>
                        </div>

                    </div>

                    <div class="text-center">
                        <a class="btn btn-blue-dark launch-btn" href="/literacy-tracker/student/dashboard">Back to Dashboard</a>
                        <a class="btn btn-blue launch-btn" href="/literacy-tracker/student/reading-challenge">New Reading Challenge</a>
                    </div>

				</div>
			</div>
		</div>
	</div>
</div>

<?php
/*<div class="modal show" role="dialog" id="modal-challenge">
	<div class="modal-dialog modal-lg" role="document">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
				<h4 class="modal-title">
					<img src="/sites/all/themes/rif/public/assets/images/rif-logo-lg.png" />
				</h4>
			</div>
			<div class="modal-body">
				Test Modal popup
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->*/
?>
