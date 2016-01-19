#!/usr/bin/python

# @author: Jeremy Cerda
# @version: $Id: mniblogpub.py 2643 2011-09-20 15:20:06Z jcerda $

import os
import sys
import ConfigParser
import subprocess
import string
import time
from datetime import datetime

cfg = None

# Shortcut function for grabbing properties. Makes code cleaner to read.
def cfgGet(prop):
    try:
        return cfg.get("mniblogpub.py", prop)
    except Exception, e:
        print "DEBUG: CFG GET FAIL"
        return False
def timeLog():
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ": "

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

    dirDelivery = "/usr/local/mniblog2/delivery"
    try: dirDelivery = cfg.get("mniblogpub.shared", "delivery")
    except Exception, e: pass
    if(dirDelivery[0] != '/'):
        dirDelivery = bloghome +'/'+ dirDelivery

    dirArchive = "/usr/local/mniblog2/archive"
    try: dirArchive = cfg.get("mniblogpub.shared", "archive")
    except Exception, e: pass
    if(dirArchive[0] != '/'):
        dirArchive = bloghome +'/'+ dirArchive

    looplimit = int(cfgGet("looplimit"));
    if not looplimit:
        looplimit = 100

    isRss = cfgGet("rss")
    rssDelivery = cfgGet("rss.delivery")

    phpcfg = cfgGet("php.config")
    if not phpcfg:
        phpcfg = argv[1]
    if(phpcfg[0] != '/'):
        phpcfg = bloghome +'/'+ phpcfg

    phpfile = cfgGet("php.file")
    if(phpfile[0] != '/'):
        phpfile = bloghome +'/'+ phpfile

    print timeLog() + "mniblog2 - mniblogpub.py - " \
        + "V: $Id: mniblogpub.py 2643 2011-09-20 15:20:06Z jcerda $"
    print timeLog() + "DELIVERY - " + dirDelivery
    print timeLog() + "ARCHIVE  - " + dirArchive
    if isRss:
        print timeLog() + "RSS DELIVERY - " + rssDelivery

    # Build basic command
    cmd = "cd " + bloghome + "; " + cfgGet("php.cmd") + " " + phpfile + \
        " " + phpcfg
    #print cfgGet("php.config")

    # Main loop
    while (True):
        sys.stdout.flush()
        time.sleep(float(cfgGet("loopdelay")))

        # Grab file list
        l = os.listdir(dirDelivery)
        l.sort()
        mylen = len(l)
        if(mylen > 0):

                if(mylen > looplimit):
                        l = l[:looplimit]

                l = [x.strip() for x in l if not os.path.isdir(
                    dirDelivery + "/" + x)]
                if(len(l) < 1):
                    continue

                c = cmd

                # Build string w/ all files
                for f in l:
                    if f != ".svn":
                        c = c + " " + f

                #print timeLog() + "DEBUG: CMD - " + str(c)
                #sys.exit(0)

                # Call it!
                r = subprocess.call(c, shell=True)

                # Did it work? Or kind of work?
                if (r == 0 or r == 5):
                    for f in l:
                        if f != ".svn":
                                if(os.path.exists(dirArchive+"/"+f)):
                                    print timeLog() + "PUBLISHED: " + f
                                    if isRss:
                                        try:
                                            os.symlink(dirArchive+"/"+f,
                                                       rssDelivery+"/"+f)
                                        except:
                                            print timeLog() + "WARN: Unable "+ \
                                                "to create link for rss feed."
                                else:
                                    print timeLog() + "ERROR: Publishing " + \
                                        "file " + f + " - Code: " + str(r)
                else:
                    print timeLog() + "ERROR: Publishing files " + \
                        string.replace(c, cmd, "") + " - Code: " + str(r)

if __name__=='__main__':
        sys.exit(main(sys.argv))
