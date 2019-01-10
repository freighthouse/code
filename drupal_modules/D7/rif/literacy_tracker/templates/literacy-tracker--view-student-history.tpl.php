<!--<p>Test Var: <?php /*print $test_var; */?></p>-->
<!--<p>Reading Challenges Taken: (TODO)</p>
<p>Average Time Taken: (TODO)</p>
<p>Average WCPM: (TODO)</p>-->
<div class="graph-container">
	<canvas id="myChart" width="400" height="100"></canvas>
	<script>
		var ctx = document.getElementById("myChart").getContext('2d');

		var data = <?php echo json_encode($data) ?>;
		var labels = <?php echo json_encode($labels) ?>;
		var background_colors = <?php echo json_encode($background_colors); ?>;
		var border_colors = <?php echo json_encode($border_colors); ?>;
		console.log(background_colors);
		var options = {
			scales: {
				yAxes: [{
					ticks: {
						beginAtZero: true
					}
				}]
			}
		};
		/*var myLineChart = new Chart(ctx, {
			type: 'line',
			label: 'Grade Level Progress',
			xAxisID: 'Reading Challenges',
			yAxisID: 'Estimated Grade Level',
			data: data
			//options: options
		});*/

		var myChart = new Chart(ctx, {
			type: 'bar',
			data: {
				labels: labels,
				datasets: [{
					label: 'Estimated Reading level',
					data: data,
					backgroundColor: background_colors,
					borderColor: border_colors,
					borderWidth: 2
				}]
			},
			options: {
				title: {
					text: "Esimated Reading level",
					display: true,
				},
				legend: {
					display: false,
				},
				responsive: true,
				scales: {
					yAxes: [{
						ticks: {
							beginAtZero:false,
							stepSize: 1,
						},
					}]
				}
			},

		});
	</script>
</div>
