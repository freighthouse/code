#!/usr/bin/awk

BEGIN { FS = "\t"; print "var priorities = new Object();" } 
NF = 2 {gsub(/[ \t]+$/, "", $1);  printf("priorities['%s'] = '%s';\n", $1, $2)}
