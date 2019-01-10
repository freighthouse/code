<?php

	require_once('helper.php');
	$lookup = $_REQUEST["international-lookup"];

	$url = "http://www.callfire.com/dialer/action/service/rates.do?resp=json&type=getRates&query=" . str_replace(" ", "+", $lookup);
	$results = curlRequest($url);
	setlocale(LC_MONETARY, 'en_US.UTF-8');
    if (!empty($results)) { 	
	    $lowestrate = array("rate"=>null, "country"=>"", "flag" => "", "mobilerate"=>null, "mobilecountry"=>"", "mobileflag" => "");
	    $masterlist = array();
	    $mobile = $inbound = $tollfree = $lowest = false;

	    if(!empty($lookup)) {
		    foreach($results[data] as $data => $country) {
		    	$rate = $country[rate];
		    	$name = $country[description];
		    	$flag = $country[flag];

		    	if(isset($masterlist[strval($rate)]) || array_key_exists($rate, $masterlist)) {
		    		array_push($masterlist[strval($rate)], $name);
		    	}
		    	else {
		    		$masterlist[strval($rate)] = array($name);
		    	}
		    	if ($lowestrate[rate] > $rate || !isset($lowestrate[rate])) {
		    		$lowestrate[rate] = $rate;
		    		$lowestrate[country] = $name;
		    		$lowestrate[flag] = $flag;
		    		$lowest = true;
		    	}
		    	if (strpos(strtolower($name), "mobile") !== false) {
			    	if ($lowestrate[mobilerate] > $rate || !isset($lowestrate[mobilerate])) {
			    		$lowestrate[mobilerate] = $rate;
			    		$lowestrate[mobilecountry] = $name;
			    		$lowestrate[mobileflag] = $flag;
		    			$mobile = true;
		    		}
		    	}
		    }
		    if (is_int(stripos($lookup, "united states")) || is_int(stripos($lookup, "canada"))) {
		    	$inbound = true;
		    	$tollfree = true;
		    }
		    echo "<div class='span span-" . strval($lowest + $mobile + $inbound + $tollfree) . " clearfix'>";
			    echo "<div class='landline pricing-group'>";
				    echo "<h4 class='category'>";
						echo "<span class='icon-small-landline-phone'>&nbsp;</span>";
					    echo "Landlines";
				    echo "</h4>";
				    echo "<div class='price-display'>";
					    echo "Starting at"; 
					    echo "<span class='price'>";
					    	if($lowestrate[rate] < 1) {
							    echo money_format('%!.3i',$lowestrate[rate])*100;
							    echo "<span class='money-symbol'>¢</span>";
					    	}
					    	else {
							    echo "<span class='money-symbol'>$</span>";
							    echo $lowestrate[rate];	
					    	}
					    echo "</span>";
					    echo "per minute";
				    echo "</div>";
			    echo "</div>";
			    if ($mobile) {	
				    echo "<div class='mobile pricing-group'>";
		   			    echo "<h4 class='category'>";
						    /*
						    	echo str_replace(", ", ",<br>", $lowestrate[mobilecountry]
						    	);
						    	*/
							echo "<span class='icon-small-phone'/>";
							echo "Mobile Phones";
					    echo "</h4>";
					    echo "<div class='price-display'>";
						    echo "Starting at"; 
						    echo "<span class='price'>";
						    	if($lowestrate[mobilerate] < 1) {
							    	echo money_format('%!.3i',$lowestrate[mobilerate])*100;
								    echo "<span class='money-symbol'>¢</span>";
						    	}
						    	else {
								    echo "<span class='money-symbol'>$</span>";
								    echo $lowestrate[mobilerate];	
						    	}
						    echo "</span>";
						    echo "per minute";
					    echo "</div>";
				    echo "</div>";
			    }
			    if ($inbound && $tollfree) {
			    	echo "<div class='inbound pricing-group'>";
		   			    echo "<h4 class='category'>";
    						echo "<span class='icon-small-download'>&nbsp;</span>";
							echo "Inbound";
					    echo "</h4>";
					    echo "<div class='price-display'>";
						    echo "Starting at"; 
						    echo "<span class='price'>";
						    	echo "5<span class='money-symbol'>¢</span>";
						    echo "</span>";
						    echo "per minute<br>($1 per month)";
					    echo "</div>";
				    echo "</div>";
	    	    	echo "<div class='tollfree pricing-group'>";
		   			    echo "<h4 class='category'>";
							echo "<span class='icon-small-globe'/>";
							echo "Toll Free";
					    echo "</h4>";
					    echo "<div class='price-display'>";
						    echo "Starting at"; 
						    echo "<span class='price'>";
						    	echo "5<span class='money-symbol'>¢</span>";
						    echo "</span>";
						    echo "per minute<br>($2 per month)";
					    echo "</div>";
				    echo "</div>";
			    }
			echo "</div>";
			echo '<a id="rates-toggle" href="#">View all rates</a>';
			if (is_int(stripos($lookup, "united states"))) {
				echo '<span class="rates-notice">*Does not include Alaska & Hawaii.</span>';
		    }
		    echo '<div id="rates-overview" class="rates-overlay">';
		    echo '<div class="rates-overlay-inner"><div class="large-arrow"></div><a href="#" class="rates-close">close</a>';
			    echo "<table><thead><tr><th>Rate</th><th>Location/Provider</th></tr></thead>";
			    echo "<tbody>";
			    ksort($masterlist);
			    foreach($masterlist as $rate => $countries) {
			    	echo "<tr>";
			    	echo "<td>". money_format('%!.3i',floatval($rate)) . "</td><td>";
			    	foreach ($countries as $key => $country) {
			    		if ($key===0) 
			    			echo strstr_after($country, $lookup.", ", true);
			    		else echo ", ". strstr_after($country, $lookup.", ", true);
			    	}
			    	echo "</td></tr>";
			    }
		    echo "</tbody></table></div></div>";
	    }
	    else {
	    	foreach($results['data'] as $data => $country) {
			    echo "<div class='pricing-group'>";
				    echo "<h4 class='country'>";
		    			/*$search = array(', ', ' and ');
		    			$replace = array(',<br>', '<br>');
					    echo str_replace($search, $replace, $country['description']);
					    */
					    echo $country['description'];
				    echo "</h4>";
				    echo "<div class='price-display'>";
					    echo "<span class='price'>";
					    	if($country['rate'] < 1) {
							    echo $country['rate'] * 100;
							    echo "<span class='money-symbol'>¢</span>";
					    	}
					    	else {
							    echo "<span class='money-symbol'>$</span>";
							    echo $country['rate'];	
					    	}
					    echo "</span>";
					    echo "per minute";
				    echo "</div>";
			    echo "</div>";
	    	}
	    }
    }
?>