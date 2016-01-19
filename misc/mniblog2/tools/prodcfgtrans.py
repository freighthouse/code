#!/usr/bin/python

# @author Jeremy Cerda
# @version $Id: prodcfgtrans.py 2337 2011-07-08 15:25:32Z jcerda $

import sys
import os

def main(args):
        if(len(sys.argv) < 3):
                print "No files given. <map> <data>"
                sys.exit(1)

        d = dict()
        map = open(args[1])
        for l in map:
                cols = l.split(',')
                d[cols[4].replace('"','')] = cols[0]

        cfg = open(args[2])
        for l in cfg:
                if l.strip() == "" or l.strip()[0] == '#':
                        print l
                        continue
                ocode = l.split('\t')[1].strip()
                mcode = ocode
                if not mcode in d:
                        mcode = mcode.replace('-', '=')
                if mcode in d:
                        l = l.replace(ocode, d[mcode])
                print l.rstrip()


if __name__=='__main__':
        sys.exit(main(sys.argv))
