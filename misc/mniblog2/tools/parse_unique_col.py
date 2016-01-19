#!/usr/local/bin/python

# @author Jeremy Cerda
# @version $Id: parse_unique_col.py 2337 2011-07-08 15:25:32Z jcerda $

import os
import sys

def getFileData(filename):
	f = open(filename)
	ret = f.read()
	f.close()
	return ret

def main(argv):
	if(len(argv) < 2):
		print "Usage: parse_unique_col.py <filename> [column]"
		sys.exit(1)

	cfgFile = getFileData(argv[1]).split('\n')
	if (len(argv) > 2):
		col = int(argv[2])
	else:
		col = 3

	tax = set()
	for line in cfgFile:
		if len(line) > 0:
			tax = tax | set(line.split('\t')[col].split(' '))

	for term in tax:
		print term

if __name__=='__main__':
	sys.exit(main(sys.argv))
