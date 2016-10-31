#!/usr/bin/perl

 for (1..100) {
	my $fizz = ($_ % 3 == 0) ? "Fizz" : "";
	my $buzz = ($_ % 5 == 0) ? "Buzz" : "";
	($fizz ne "" || $buzz ne "") ? print "$fizz$buzz\n" : print "$_\n";
 }

