#!/usr/bin/python

# @author: Jeremy Cerda
# @version: $Id: mnrichwatch.py 2337 2011-07-08 15:25:32Z jcerda $

import sys
#import socket
#import mniser
import mnifhandler
#import mnimsg
from mnimsgxml import mnimsgxml
from xml.dom.minidom import parse, parseString
import re
import mniprod
import mniblogxml
import time
import os
import ConfigParser
import shutil
import uu
import mnimsg
from datetime import datetime

headstrip = '[.]*>\s*'
headstripregex = re.compile(headstrip)

cfg = None

# Shortcut function for grabbing properties. Makes code cleaner to read.
def cfgGet(prop):
    try:
        return cfg.get("mnrichwatch.py", prop)
    except Exception, e:
        return False
def timeLog():
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ": "

def stripHeadline(s):
        s = headstripregex.sub('', s)
        return s

class timeseq:
        t = None
        seq = 0

        def __init__(self):
                pass

        def getnameseq(self):
                nt = int(time.time())

                #print "OT "+repr(self.t)+", NT "+repr(nt)+", SEQ: " + \
                #        repr(self.seq)

                if nt == self.t:
                        self.seq = self.seq + 1
                else:
                        self.seq = 0

                #print "NT "+repr(nt)+", SEQ: "+repr(self.seq)

                self.t = nt

                return (time.strftime('%Y%m%dT%H%M%S', time.localtime(nt)),
                        self.seq)

def seperateAndArchive(filename, delivery, archive):
        # Filenames
        scpdel = delivery
        scparc = archive
        #scpdel = cfgGet("dir.scp.delivery")
        #scparc = cfgGet("dir.scp.archive")
        tmpfn = scparc + '/rich_tmp'
        xmlfn = scpdel + "/" + filename
        pdffn = 'pdfs/' + filename[:-4]+".pdf"

        # Read xml
        try:
                dom = parse(open(xmlfn))
        except:
                print timeLog() + "ERROR: Invalid file. Error parsing." \
                        +" Archiving and removing."
                shutil.copy(xmlfn, scparc + "/" + filename)
                os.remove(xmlfn)
                return None

        # Grab data
        ctype = dom.getElementsByTagName('ContentType')[0].childNodes[0] \
                        .nodeValue
        content = dom.getElementsByTagName('Content')[0].childNodes[0] \
                        .nodeValue

        if ctype == "UUSTORY":
                if content.rstrip()[:5] == "begin" and \
                content.rstrip()[-3:] == "end":
                        # First time seeing, archive and rip out pdf
                        archFile = scparc + "/" + filename
                        shutil.copy(xmlfn, archFile)
                        print timeLog() + "ARCHIVED: " + archFile
                        tmpfile = open(tmpfn, 'w')
                        tmpfile.write(content)
                        tmpfile.close()
                        uu.decode(tmpfn, pdffn, None, True)
                        os.remove(tmpfn)
                        dom.getElementsByTagName('Content')[0].childNodes[0] \
                                .nodeValue = filename[:-4]+".pdf"
                        f = open(xmlfn, 'w')
                        f.write(dom.toxml())
                        f.close()
                elif content.rstrip()[-3:] != "pdf":
                        # Don't know what you're doing here, but get out
                        print timeLog() + "ERROR: Invalid content. No UU " \
                                + "Data or pdf name found with UUSTORY. " \
                                + "Archiving and removing."
                        os.remove(xmlfn)
                        return None

        return mnimsgxml(dom)

def handle(msg, mp, ts, delivery="delivery", embargo="queue", name="default"):

        time = 0
        embargo = 0
        death = 0
        price = 0
        if cfgGet("cfg.advanced"):
            (embargo, death, price, tops) = mp.gettopicdata( \
                                                msg.getselectors() + \
                                                msg.gettopics())
        else:
            (time, tops) = mp.gettimetopics(msg.getselectors() + \
                                                 msg.gettopics())

        if time < 0 or embargo < 0 or len(tops) == 0:
                return True
        elif time == 0:
                mydir = delivery
        else:
                mydir = embargo
        xts = ts.getnameseq()
        myname = xts[0]+repr(xts[1])+'.xml'
        try:
                myfile = os.path.join(mydir, myname)

                fmyfile = open(myfile, 'wb')

                print timeLog() + "NEWS - " + name + " - " + myname + \
                    " - " +  stripHeadline(m.getheadline())
                #print "I'LL PUBLISH "+msg.gettimestamp()+" " \
                #        +stripHeadline(msg.getheadline())+" to " \
                #        +repr(tops)+" in "+repr(time)+" seconds to " \
                #        +repr(myfile)
                mx = mniblogxml.mniblogxml(msg,tops)

                # Add our Content type, probably should be in
                # mniblogxml to begin with, but I'm probably rewriting
                # that in mniblog3 anyway, so this will do for now.
                # - Gerg 4/14/11
                mxml = mx.toxml()
                s = mxml.find("<xn:vendorData>MKTNEWS_:")
                mxml = mxml[:s] + "<xn:vendorData>MKTNEWS_:ContentType=" \
                        + msg.getcontenttype() + "</xn:vendorData>" + '\n' \
                        + "    " + mxml[s:]

                fmyfile.write(mxml)
                fmyfile.close()
        except Exception, e:
                print timeLog() + "EXCEPTION IS "+repr(e)
                return False
        return True

def getProdData(filename):
    mpf = file(filename, 'r')
    pd = mpf.read()
    mpf.close()
    return pd

def main(args):
    # Parse cfg files
    global cfg

    if(args[1] == "-m"):
        cfg = ConfigParser.ConfigParser()
        cfg.read(args[2])
        feeds = [f for f in cfg.sections() if f.startswith('feed.')]
        feeddata = list()
        for f in feeds:
            d = dict()
            d["delivery"] = cfg.get(f, "delivery")
            d["prodcfg"] = mniprod.mniprod(getProdData(
                            cfg.get(f,"production.cfg")))
            d["feedname"] = cfg.get(f, "name")
            feeddata.append(d)
    else:
        cfg = ConfigParser.ConfigParser()
        cfg.read(args[2])
        mp = mniprod.mniprod(getProdData(args[1]))

    bloghome = cfg.get("mniblogpub.shared", "bloghome")
    scpDelivery = cfgGet("dir.scp.delivery")

    ts = timeseq()

    while(True):
        l = os.listdir(scpDelivery)
        l = [x.strip() for x in l]
        l.remove(".svn")
        l.sort()

        for x in l:
            # Separate pdf and xml
            m = seperateAndArchive(x)
            #m = mnimsgxml.mnimsgfromfile(x)

            # Multi Feed
            if(args[1] == "-m"):
                anySuccess = False
                for d in feeddata:
                    r = handle(m, d["prodcfg"], ts, d["delivery"], d["feedname"])
                    if not r:
                        print timeLog() + "ERROR - " + d["feedname"] + \
                            " - Error in xml generation."
                    anySuccess = (anySuccess or r)
                if anySuccess:
                    os.remove(scpDelivery + "/" + x)

            # Single Feed
            else:
                if handle(m, mp, ts):
                    os.remove(scpDelivery + "/" + x)

        sys.stdout.flush()
        time.sleep(float(cfgGet("loopdelay")))

    return 0

if __name__=='__main__':
        sys.exit(main(sys.argv))
