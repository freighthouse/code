#!/usr/bin/python

# @author Jeremy Cerda
# @version $Id: pushfiles.py 2712 2011-09-29 18:27:12Z jcerda $

import os
import sys
import re
import socket
import paramiko
import shutil
import time
from datetime    import datetime
from MNICfg      import MNICfg
from MNIUtil     import MNIUtil
from MNIArchiver import MNIArchiver
from MNIPush     import MNIPush, MNIPushSCP, MNIPushSCPLocal, MNIPushSFTP

cfg      = None
archiver = None
pusher   = None

# Load pusher
def getPusher():
    pm = cfg.cfgGet('push.method').strip()
    if(not issubclass(eval(pm), MNIPush)):
        print MNIUtil.timeLog()+"FATAL: Invalid push method - " + pm
        sys.exit(4)
    return eval(pm+"()")

# Grab and Test Host Info
def getHosts(trans_home, ):
    hf = cfg.cfgGet('hosts.file')
    if hf[0] == '/':
        hf = trans_home+hf

    hosts = parseHosts(hf)
    for h in hosts:
        if(not archiver.testArchiving(h[0])):
            print MNIUtil.timeLog()+"FATAL: Error archiving to " +\
                archiver.dst+"/"+h[0]
            sys.exit(2)
        print MNIUtil.timeLog()+"HOST:    "+h[0]+" - "+h[2]+"@"+\
            h[1]+":"+h[4]
    return hosts

# Push a single file
def pushFile(xml_dir, file, host):
    use_pass = (cfg.cfgGet('push.usepass').lower().strip() in
                ['true', '1', 't', 'y', 'yes'])
    pwd = host[3]
    if(not use_pass):
        pwd = ""

    # Push
    if(pusher.pushFile(xml_dir+"/"+file, host[4], host[1], host[2], pwd)):
        # Archive
        archiver.archiveFile(xml_dir, file)
        print MNIUtil.timeLog()+"PUSHED     "+file+" to host " + host[0]
        sys.stdout.flush()
        return 1
    else:
        print MNIUtil.timeLog()+"FAILED PUSH " + file + \
            " to host " + host[0] + ". Retrying in " + \
            cfg.cfgGet("push.faildelay", 5) + " seconds"
        sys.stdout.flush()
        return 0

# Parse hosts file
def parseHosts(hostCfgFile):
    hosts = list()
    d = open(hostCfgFile, 'r').readlines()
    for l in d:
        if (l.strip() != '' and l.strip()[0] != '#'):
            ld = l.split("\t")
            ld = [x.strip() for x in ld]
            hosts.append(ld)

    return hosts

# Main
# arg 1 - configuration file
def main(argv):
    if(len(argv) < 2):
        print "Usage: pushfiles.py <config file>"
        sys.exit(1)

    # Parse cfg files
    global cfg, archiver, pusher
    cfg = MNICfg(argv[1], "pushfiles.py")

    # Grab and cleanup directories
    trans_home = cfg.cfgGet('module.home')
    xml_dir    = cfg.cfgGet('data.dir')
    arc_dir    = cfg.cfgGet('archive.dir')

    if (xml_dir.split('/')[-1] != ''):
        xml_dir = xml_dir+'/'
    if (arc_dir.split('/')[-1] != ''):
        arc_dir = arc_dir+'/'
    if (trans_home.split('/')[-1] != ''):
        trans_home = trans_home+'/'

    paramiko.util.log_to_file(trans_home+'/paramiko_debug.log')
    r = re.compile("^n[0-9]+_[a-z]+_[a-z0-9]+.xml$", re.IGNORECASE)
    archiver = MNIArchiver(arc_dir)
    pusher = getPusher()

    # Version and startup logging
    print MNIUtil.timeLog()+"mnnewsmlfeed - " + \
        "V: $Id: pushfiles.py 2712 2011-09-29 18:27:12Z jcerda $"
    print MNIUtil.timeLog()+"HOME       "+trans_home
    print MNIUtil.timeLog()+"DATA       "+xml_dir
    print MNIUtil.timeLog()+"ARCHIVE    "+arc_dir
    print MNIUtil.timeLog()+"PUSHER     "+cfg.cfgGet('push.method').strip()
    sys.stdout.flush()

    hosts = getHosts(trans_home)

    # Main loop
    while (True):
        # Grab file list
        l = os.listdir(xml_dir)
        l.sort()
        mylen = len(l)

        if(mylen > 0):
            if(mylen > 1500):
                l = l[:1500]

            # Filter out non-xml and template
            l = [x.strip() for x in l]
            l = filter(r.search,l)

            # Push and move files to archive
            # If push fails, break. Order matters.
            for f in l:
                print MNIUtil.timeLog()+"STARTING   "+f

                for h in hosts:
                    if (len(h) < 4):
                        print MNIUtil.timeLog()+"WARN: One invalid host " +\
                            "line. Skipping"
                        continue

                    while(not pushFile(xml_dir, f, h)):
                        # Sleep a little so we don't kill servers
                        time.sleep(float(cfg.cfgGet("push.faildelay", 5)))

                # Move file
                if(not archiver.clearFile(xml_dir, f)):
                    print MNIUtil.timeLog()+"FATAL: Fatal error. " +\
                        "Could not move " + f + ". Exiting to avoid " +\
                        "double publishing."
                    sys.exit(3)

                print MNIUtil.timeLog()+"FINISHED   "+f
                sys.stdout.flush()

                # Sleep a little so we don't kill server
                time.sleep(float(cfg.cfgGet("push.delay", 0.5)))

if __name__=='__main__':
        sys.exit(main(sys.argv))
