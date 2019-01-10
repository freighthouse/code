<?php

$jsonurl = "http://trust.turn.com/status.json";
$json = file_get_contents($jsonurl, 0, null, null);
echo $json;


?>
