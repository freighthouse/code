<?php
$i = 1; while ($i <= 100) {
  if (!($i%3))
    print "Fizz";
  if (!($i%5))
    print "Buzz";
  if ($i%3 && $i%5)
    print $i;

  print "\n";
  $i++;
}
