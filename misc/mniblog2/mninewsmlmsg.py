#!/usr/bin/python

# @author: Jeremy Cerda
# @version: $Id$

import math
import string
from datetime import datetime, time, tzinfo, timedelta
from xml.dom.minidom import parse, parseString

class mninewsmlmsg:
    def __init__(self, msg):
        if isinstance(msg, str):
            self.dom = parseString(msg)
        else:
            self.dom = msg

    def getPubTime(self):
        return self.dom.getElementsByTagName("xn:publicationTime")[0] \
            .childNodes[0].nodeValue

    def getPubDate(self):
        pubTime = self.getPubTime()
        return mniISO8601ToDate(pubTime)

    def getTitle(self):
        return self.dom.getElementsByTagName("xn:title")[0] \
            .childNodes[0].nodeValue

    def getContent(self):
        return self.dom.getElementsByTagName("pre")[0].childNodes[0].nodeValue

    def getLink(self):
        nid_list = self._findInVendorDataTag("link")
        if(len(nid_list) > 0):
            return nid_list[0]
        return "https://mninews.deutsche-boerse.com/"

    def getNID(self):
        nid_list = self._findInVendorDataTag("nid")
        if(len(nid_list) > 0):
            return nid_list[0]
        return None

    def getSpecialCodes(self):
        return self._findInVendorDataTag("Special Code")

    def getBlogTags(self):
        return self._findInVendorDataTag("Blog Tag")

    def getLegacyDate(self):
        vd_legacydate = self._findInVendorDataTag("Legacy Date")
        if len(vd_legacydate) > 0:
            return vd_legacydate[0]
        date = self.getPubDate()
        return date.strftime("%H:%M %Z %m/%d")

    def getEmbargoDate(self):
        pubDate = self.getPubDate()
        vd_mnembargo = self._findInVendorDataTag("mnembargo")
        if len(vd_mnembargo) <= 0:
            return pubDate
        return pubDate + timedelta(seconds=int(vd_mnembargo[0]))

    def isEmbargoPassed(self):
        rightnow = datetime.utcnow()
        rightnow = rightnow.replace(tzinfo=tzISO8601Offset(0))
        return self.getEmbargoDate() < rightnow

    def isEmbargoed(self):
        return (len(self._findInVendorDataTag("mnembargo")) > 0)

    def _findInVendorDataTag(self, tagName):
        elements = self.dom.getElementsByTagName("xn:vendorData")
        ret = list()
        for e in elements:
            nv = e.childNodes[0].nodeValue.split("=")
            if nv[0] == "MKTNEWS_:" + tagName:
                ret.append(nv[1])
        return ret

class tzISO8601Offset(tzinfo):

    def __init__(self, offset_seconds):
        offsec = math.fabs(offset_seconds)
        m = int(offsec) / 60
        self.fulloffset_seconds = offsec
        self.seconds = offsec % 60
        self.hours = m / 60
        self.minutes = m % 60

    def utcoffset(self, dt):
        return timedelta(hours=self.hours, minutes=self.minutes)

    def dst(self, dt):
        return None

    def tzname(self, dt):
        return (("-" if self.fulloffset_seconds < 0 else "+") +
            "%02d%02d" % (self.hours, self.minutes))

class tzGMT(tzinfo):

    def utcoffset(self, dt):
        return timedelta(0)

    def dst(self, dt):
        return None

    def tzname(self, dt):
        return "GMT"

def mniISO8601ToDate(dateString):
    date = datetime.strptime(dateString[:-5], "%Y%m%dT%H%M%S")
    offset = (int(dateString[-4:-2]) * 60 * 60) + (int(dateString[-2:]) * 60)
    if dateString[-5] == '-':
        offset *= -1
    date = date.replace(tzinfo=tzISO8601Offset(offset))
    return date
