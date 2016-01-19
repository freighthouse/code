#!/usr/bin/python

# @author: Jeremy Cerda
# @version: $Id: mnirsspub.py 3345 2012-03-16 19:53:24Z jcerda $

import os
import sys
import grp
import ConfigParser
import subprocess
import string
import time
import shutil
import tempfile
import mninewsmlmsg
from mninewsmlmsg import tzISO8601Offset, tzGMT
from datetime import datetime
from xml.dom.minidom import parse, parseString
from xml.sax.saxutils import escape

cfg = None

# Shortcut function for grabbing properties. Makes code cleaner to read.
def cfgGet(prop):
    try:
        return cfg.get("mnirsspub.py", prop)
    except Exception, e:
        return False
def timeLog():
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ": "

def itemString(filename):
    if (os.path.islink(filename) and not isValidLink(filename)) or \
    (not os.path.isfile(filename)):
        return ""

    msg = mninewsmlmsg.mninewsmlmsg(parse(open(filename)))

    if(msg.isEmbargoed() and not msg.isEmbargoPassed()):
        return ""

    nid = msg.getNID()
    msgContent = msg.getContent()
    if(cfgGet("rss.html.include")):
        msgContent = "<pre>" + msgContent + "</pre>"

    itemString = \
        "<item>" + "\n" + \
            "<title>" + \
                escape(msg.getTitle()) + \
            "</title>" + "\n" + \
            "<link>" + msg.getLink() + "</link>" + "\n" + \
            "<description>" + \
                escape(msgContent) + \
            "</description>" + "\n" + \
            "<pubDate>" + \
                mniTimeToRssTime(msg.getPubTime()) + \
            "</pubDate>"  + "\n" + \
            ("<guid>" + nid + "</guid>" + "\n" if nid != None else "") + \
        "</item>"
    return itemString


def mniTimeToRssTime(inputDate):
    date = mninewsmlmsg.mniISO8601ToDate(inputDate)
    return date.strftime("%a, %d %b %Y %H:%M:%S %Z").strip()

def isValidLink(filename):
    if not os.path.islink(filename):
        return False
    try:
        os.stat(filename)
    except os.error:
        return False
    return True

def archiveAndLinkFile(filename, dirArchive):
    try:
        archiveFile = dirArchive + "/" + os.path.basename(filename)
        shutil.move(filename, archiveFile)
        os.symlink(archiveFile, filename)
    except:
        print timeLog() + "ERROR: Could not archive and link file. - " + \
            filename

def archiveAndMove(filenames, dirDelivery, dirArchive, dirLive):
    for f in filenames:
        fullname = dirDelivery + "/" + f

        if not os.path.islink(fullname):
            archiveAndLinkFile(fullname, dirArchive)
        else:
            try:
                arcLink = os.readlink(fullname)
                os.symlink(arcLink, dirArchive + "/" + f)
            except:
                print timeLog() + "WARN: RSS Archive link " + \
                    "failed to create. - " + dirArchive + "/" + f

        liveFile = dirLive + "/" + f

        if isValidLink(fullname):
            try:
                shutil.move(fullname, liveFile)
            except:
                print timeLog() + "ERROR: Could not move link into " + \
                    "live dir. - SRC: " + fullname + " - DEST: " + liveFile

def rebuildRssFile(rssfilename, filenames):
    tmpfilename = os.path.dirname(rssfilename) + "/." + \
        os.path.basename(rssfilename) + ".tmp"
    tmpfile = open(tmpfilename, 'w')

    managingEditor = cfgGet('rss.managingEditor')
    webMaster = cfgGet('rss.webMaster')
    atomLink = cfgGet('rss.atomlink')
    lastPub = datetime.utcnow().replace(tzinfo=tzGMT())

    tmpfile.write(
        '<?xml version="1.0"?>' + "\n" +
        '<rss version="2.0" xmlns:atom="http://www.w3.org/2005/Atom">' + "\n" +
            '<channel>' + "\n" +
                '<atom:link href="' + atomLink + '" ' +
                    'rel="self" type="application/rss+xml" />' + "\n" +
                '<title>Market News International - Free</title>' + "\n" +
                '<link>' +
                    'https://mninews.deutsche-boerse.com/' +
                '</link>' + "\n" +
                '<description>' +
                    'Market News International is the leading ' +
                    'real-time news agency dedicated to the global ' +
                    'fixed-income and foreign exchange markets, and ' +
                    'provides information that is also relevant to ' +
                    'the equity markets.'
                '</description>' + "\n" +
                '<language>en-us</language>' + "\n" +
                '<managingEditor>' +
                    managingEditor + " (" + managingEditor.split("@")[0] + ")" +
                '</managingEditor>' + "\n" +
                '<webMaster>' +
                    webMaster + " (" + webMaster.split("@")[0] + ")" +
                '</webMaster>' + "\n" +
                '<lastBuildDate>' +
                    lastPub.strftime("%a, %d %b %Y %H:%M:%S %Z").strip() +
                '</lastBuildDate>' + "\n"
    )

    for f in filenames:
        tmpfile.write(itemString(f))

    tmpfile.write(
            '</channel>' + "\n" +
        '</rss>' + "\n"
    )

    tmpfile.flush()
    tmpfile.close()
    return tmpfilename

def moveAndPerm(tmpfilename, rssfilename):
    try:
        #perms = cfgGet("rss.file.perms")
        #if perms == None:
        #    perms = 0640
        perms = 0640
        os.chmod(tmpfilename, perms)

        #group = cfgGet("rss.file.group")
        #if group == None:
        #    group = "www-data"
        #group = grp.getgrnam(group).gr_gid
        #os.chown(tmpfilename, -1, group)

        shutil.move(tmpfilename, rssfilename)
    except:
        print timeLog() + "ERROR: Could not move and / or permission " + \
            "files. - SRC: " + tmpfilename + " - DEST: " + rssfilename

# Main
# arg 1 - configuration file
def main(argv):
    if(len(argv) < 2):
        print "Usage: mnirsspub.py <config file>"
        sys.exit(1)

    # Parse cfg files
    global cfg
    cfg = ConfigParser.ConfigParser()
    cfg.read(argv[1])

    bloghome = cfg.get("mniblogpub.shared", "bloghome")

    dirDelivery = "/usr/local/mniblog2/delivery"
    try: dirDelivery = cfg.get("mnirsspub.py", "rss.dir.delivery")
    except Exception, e: pass
    if(dirDelivery[0] != '/'):
        dirDelivery = bloghome +'/'+ dirDelivery

    dirArchive = "/usr/local/mniblog2/archive"
    try: dirArchive = cfg.get("mnirsspub.py", "rss.dir.archive")
    except Exception, e: pass
    if(dirArchive[0] != '/'):
        dirArchive = bloghome +'/'+ dirArchive

    dirLive = "/usr/local/mniblog2/rss/live"
    try: dirLive = cfg.get("mnirsspub.py", "rss.dir.live")
    except Exception, e: pass
    if(dirLive[0] != '/'):
        dirLive = bloghome +'/'+ dirLive

    looplimit = int(cfgGet("looplimit"));
    if not looplimit:
        looplimit = 100

    print timeLog() + "mniblog2 - mnirsspub.py - " \
        + "V: $Id: mnirsspub.py 3345 2012-03-16 19:53:24Z jcerda $"
    print timeLog() + "DELIVERY - " + dirDelivery
    print timeLog() + "ARCHIVE  - " + dirArchive
    print timeLog() + "LIVE     - " + dirLive

    rssfilename = cfgGet("rss.file")
    print timeLog() + "RSS FILE - " + rssfilename

    liveList = os.listdir(dirLive)
    liveList = [dirLive + "/" + x.strip() for x in liveList
                if not os.path.isdir(dirLive + "/" + x.strip())]

    tmpfilename = rebuildRssFile(rssfilename, liveList)
    moveAndPerm(tmpfilename, rssfilename)

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

                l = [x.strip() for x in l if not os.path.isdir( \
                        dirDelivery + "/" + x)]
                if(len(l) < 1):
                    continue

                archiveAndMove(l, dirDelivery, dirArchive, dirLive)

                liveList = os.listdir(dirLive)
                liveList = [dirLive + "/" + x.strip() for x in liveList
                            if not os.path.isdir(dirLive + "/" + x.strip())]

                tmpfilename = rebuildRssFile(rssfilename, liveList)
                moveAndPerm(tmpfilename, rssfilename)

                for f in l:
                    print timeLog() + "PUBLISHED: " + f

if __name__=='__main__':
        sys.exit(main(sys.argv))
