#!/usr/bin/python

# @author Jeremy Cerda
# @version $Id: mniblogpub-import.py 2337 2011-07-08 15:25:32Z jcerda $

mniblog_home = "/usr/local/mniblog"
sys.path.append(mniblog_home)

import sys
import os
import ConfigParser
import subprocess
import string

cfg = None

# Shortcut function for grabbing properties. Makes code cleaner to read.
def cfgGet(prop):
    return cfg.get("mniblogpub.py", prop)

# Main
# arg 1 - configuration file
def main(argv):
    if(len(argv) < 2):
        print "Usage: mniblogpub.py <config file>"
        sys.exit(1)

    # Parse cfg files
    global cfg
    cfg = ConfigParser.ConfigParser()
    cfg.read(argv[1])

    bloghome = cfg.get("mniblogpub.shared", "bloghome")

    # Build basic command
    cmd = cfgGet("php.cmd") + " " + bloghome +"/mniblogpub.php " + \
        bloghome + "/" + cfgGet("php.config")

    l = list()
    ls = list()
    mylen = 0
    # Main loop
#
    l = os.listdir(bloghome + "/delivery")
    l.sort()

    while (True):
	if len(l) == 0:
		break

  	ls = l[0:1500]
	l = l[1500:]



    #while (True):

        #if(mylen  < 1):
        #        # Grab file list
        #        l = os.listdir(bloghome + "/delivery")
        #        l.sort()

        #mylen = len(l)
        #if(mylen < 1):
        #    continue
        #elif(mylen > 1500):
        #        ls = l[:1500]
        #        l = l[1500:]
        #else:
        #        ls = l
        #        mylen = 0


        ls = [x.strip() for x in ls]
        c = cmd

        # Build string w/ all files
        for f in ls:
            c = c + " " + f

        # Call it!
        r = subprocess.call(c, shell=True)

        # Did it work? Or kind of work?
        if (r == 0 or r == 5):
            #for f in ls:
                #if(os.path.exists(bloghome+"/archive/"+f)):
                #    print "PUBLISHED: " + f
                #else:
                #    print "ERROR: Publishing file " + f + " - Code: " + str(r)
            print(len(l))
            print(l)
        else:
            print "ERROR: Publishing files " + string.replace(c, cmd, "") + \
                " - Code: " + str(r)

if __name__=='__main__':
        sys.exit(main(sys.argv))
