<?php
global $language;
//print_r($language->language);die();
//print "<pre>";
//print_r($language);
//print "</pre>";

if($language->language == 'fr') {
$dates = explode(" ",$output);
  $month = $dates[1];
  //print "<pre>";
//print_r($dates);
  switch ($month) {
  	case 'January':
  		$dates[1] = 'janvier';
  		break;
  		 	case 'February':
  		$dates[1] = 'février';
  		break;
  		 	case 'March':
  		$dates[1] = 'mars';
  		break;
  		 	case 'April':
  		$dates[1] = 'avril';
  		break;
  			case 'May':
  		$dates[1] = 'mai';
  		break;
  		case 'June':
  		$dates[1] = 'juin';
  		break;
  		case 'July':
  		$dates[1] = 'juillet';
  		break;
  		case 'August':
  		$dates[1] = 'août';
  		break;
  		case 'September':
  		$dates[1] = 'septembre';
  		break;
  		case 'October':
  		$dates[1] = 'octobre';
  		break;
  		case 'November':
  		$dates[1] = 'novembre';
  		break;
  		case 'December':
  		$dates[1] = 'décembre';
  		break;

  	
  	default:
  		# code...
  		break;
  }
$output = implode(" ", $dates);
print $output;
}else{
	print $output;
}
//print "<pre>";
//print_r($output);die();

?>