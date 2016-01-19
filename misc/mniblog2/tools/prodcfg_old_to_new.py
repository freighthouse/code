#!/usr/bin/python

# @author Jeremy Cerda
# @version $Id: prodcfg_old_to_new.py 2337 2011-07-08 15:25:32Z jcerda $

import sys

f = open(sys.argv[1])
lines = f.readlines()

for l in lines:
	t = l.split('\t')
	if len(t) < 3:
		print l.rstrip()
	else:
		print t[0] + '\t' + t[1] + '\t' + t[2] + '\t' + str(0) + '\t' + str(0.00) + '\t' + t[3].rstrip()
