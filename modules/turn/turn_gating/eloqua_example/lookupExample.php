<?php
	include('class/class.eloquaLookup.php');
?>

<!DOCTYPE html>
<html>
	<head>
		<title>Turn</title>
	</head>

	<body>
		<p><a href="download.php?docid=123">CLICK HERE TO DOWNLOAD</a></p>

		<script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
		<script type="text/javascript" src="js/elq_tracking-1.0-min.js"></script>
		<script type="text/javascript">
			//we need the cookie guid value (3rd party Eloqua cookie)
			var elqTracker = new jQuery.elq(1852860672);
			//1st, make standard tracking call
			elqTracker.pageTrack({success: function() {
				//2nd, grab eloqua cookie value
				elqTracker.getGUID(function(guid) {
					//3rd, place eloqua cookie in 1st party cookie
					var exDate = new Date()
					exDate.setDate(exDate.getDate() + 365);
					document.cookie = "ELOQUA=" + guid + "; expires=" + exDate.toUTCString();
				});
			}});
		</script>
	</body>
</html>
