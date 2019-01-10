<?php
	// TODO: Create Help Guide Modal
	// TODO: Create Add Group Modal use literacy-tracker.module to create the correct link to output here
	// TODO: Update the edit button to open a modal instead of taking the user to a new page
?>
<div class="container container-main panel-push-down">
	<div class="row">
		<div class="col-xs-12">
			<div class="panel panel-default panel-groups">
				<div class="row">
					<div class="col-xs-12 col-sm-6 col-sm-push-6 text-center">
						<button type="button" class="btn btn-help-guide" data-toggle="modal" data-target="#modal-help-guide">Help<i class="fa fa-question-circle" aria-hidden="true"></i></button>
					</div>
					<div class="col-xs-12 col-sm-6 col-sm-pull-6 text-center">
						<h2>Welcome, <?php echo $first_name; ?>!</h2>
					</div>
				</div>
				<div class="row">
					<div class="col-xs-12 col-sm-6 text-center">
						<?php if($table_output) : ?>
							<p><strong>Your Reading Groups</strong></p>
						<?php else: ?>
							<p>To get started create your first Reading Group.</p>
						<?php endif;?>
					</div>
					<div class="col-xs-12 col-sm-6 text-center">
						<!--<a class="btn btn-green" href="#">Add Group<i class="fa fa-users" aria-hidden="true"></i></a>-->
						<?php echo $add_group_button; ?>
					</div>
				</div>
				<?php if($table_output) : ?>
					<div class="row">
						<div class="col-xs-12">
							<div class="table-responsive table-groups">
								<?php print render($table_output); ?>
							</div>
						</div>
					</div>
				<?php else : ?>
					<div class="row">
						<div class="col-xs-12">
							<div class="no-groups-image">
								<img class="img-responsive" src="/sites/default/files/no-groups-image.png"  />
							</div>
						</div>
					</div>
					<div class="row">
						<div class="col-xs-12 text-center">
							<h3>Get Started by Adding Your First Group!</h3>
						</div>
					</div>
				<?php endif; ?>
			</div>
		</div>
	</div>
</div>
<div class="modal fade" tabindex="-1" role="dialog" id="modal-help-guide">
  <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">
          <img src="/sites/all/themes/custom/rif/public/assets/images/rif-logo-lg.png" />
        </h4>
      </div>
      <div class="modal-body help-guide ">
	  	<img class="img-responsive" src="/sites/default/files/groups-screen.png" />
			<h3>Reading Groups Screen</h3>
			<ol>
				<li>Use the Add Group button to create a new group.</li>
				<li>Use the Select Action button to View, Edit or Delete that group.</li>
			</ol>
			<img class="img-responsive" src="/sites/default/files/readers-screen.png" />
			<h3>Reading Group Reader Screen</h3>
			<ol>	
				<li>Use the Add User button to add readers to your group.</li>
				<li>Use the Print Invites button to print all of the login information for each reader.</li>
				<li>Use the Select Action button to Print Invite for, View the Histoty of, Edit or Delete that reader.</li>
			</ol>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->