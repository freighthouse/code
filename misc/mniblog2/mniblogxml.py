
# @author: Jeremy Cerda
# @version: $Id: mniblogxml.py 2337 2011-07-08 15:25:32Z jcerda $

import re
import mnimsg
import string
import time

# FORGOT TOPICS!

headstrip = '[.]*>\s*'
headstripregex = re.compile(headstrip)

def stripHeadline(s):
        s = headstripregex.sub('', s)
        return s

def escapexml(s):
	return s.replace('&','&amp;').replace('>','&gt;').replace('<','&lt;').replace('"','&quot;').replace("'",'&apos;')

class mniblogxml:
	n = None
	year = -1
	tags = list()
	embargo = -1
	death = -1
	price = -1


	def __init__(self, mnimsg, tags=list(), year=-1, embargo=-1, death=-1, price=-1):
		self.n = mnimsg
		self.tags = tags
		self.year = year
		self.embargo = embargo
		self.death = death
		self.price = price

	def __givemekey(self):
		return '0'

	def __givemetime(self):
                ts = repr(self.year)
                if(self.year < 0):
                        ts = time.strftime('%Y')
		ts = ts+time.strftime('%m%d')+"T"+time.strftime('%H%M%S')
		tz = time.strftime('%Z')
		if(tz == "EST"):
			tz = "-0500"
		elif(tz == "EDT"):
			tz = "-0400"
		else:
			tz = ""
		return ts+tz

	def toxml(self):
		s = ''
		s = s + '<?xml version="1.0" ?>' + '\n'
		s = s + '<document>' + '\n'
		s = s + '  <nitf>' + '\n'
		s = s + '    <head>' + '\n'
		s = s + '      <title>' + escapexml(stripHeadline(self.n.getheadline())) + '</title>' + '\n'
		s = s + '    </head>' + '\n'
		s = s + '    <body>' + '\n'
		s = s + '      <body.head>' + '\n'
		s = s + '        <hedline>' + '\n'
		s = s + '          <hl1>' + escapexml(stripHeadline(self.n.getheadline())) + '</hl1>'
		s = s + '        </hedline>' + '\n'
		s = s + '        <distributor>Market News International</distributor>' + '\n'
		s = s + '      </body.head>' + '\n'
		s = s + '      <body.content>' + '\n'
		s = s + '        <pre>'+escapexml(self.n.getstory())+'</pre>' + '\n'
		s = s + '      </body.content>' + '\n'
		s = s + '    </body>' + '\n'
                s = s + '  </nitf>' + '\n'
		s = s + '  <xn:Resource xmlns:xn="http://www.xmlnews.org/namespaces/meta#">' + '\n'
		s = s + '    <xn:providerName>Market News International</xn:providerName>' + '\n'
		s = s + '    <xn:providerCode>1</xn:providerCode>' + '\n'
		s = s + '    <xn:serviceName>Blogs</xn:serviceName>' + '\n'
		s = s + '    <xn:serviceCode>1</xn:serviceCode>' + '\n'

# THESE ARE MESSED UP CALLS, the KEY calls..

		s = s + '    <xn:resourceID>'+self.__givemekey()+'</xn:resourceID>' + '\n'
		#s = s + '    <xn:publicationTime>'+self.__givemetime()+'</xn:publicationTime>' + '\n'
		s = s + '    <xn:publicationTime>'+escapexml(self.n.getiso8601timestamp(self.year))+'</xn:publicationTime>' + '\n'
		s = s + '    <xn:receivedTime>'+escapexml(self.__givemetime())+'</xn:receivedTime>' + '\n'


		s = s + '    <xn:title>'+escapexml(stripHeadline(self.n.getheadline()))+'</xn:title>' + '\n'
		s = s + '    <xn:rendition>'+self.__givemekey()+'</xn:rendition>' + '\n'

		for xs in self.n.getselectors() + self.n.gettopics():
			xs = escapexml(xs.replace('=','-'))
			if xs.startswith('P'):
				s = s + '    <xn:vendorData>MKTNEWS_:Special Code=PS/'+xs+'</xn:vendorData>' + '\n'
			else:
				s = s + '    <xn:vendorData>MKTNEWS_:Special Code=SU/'+xs+'</xn:vendorData>' + '\n'

		for xtags in self.tags:
			s = s + '    <xn:vendorData>MKTNEWS_:Blog Tag='+xtags+'</xn:vendorData>' + '\n'
		s = s + '    <xn:vendorData>MKTNEWS_:Legacy Date='+escapexml(self.n.gettimestamp())+'</xn:vendorData>' + '\n'
		if(self.embargo != -1):
			s = s + '    <xn:vendorData>MKTNEWS_:mnembargo='+escapexml(str(self.embargo))+'</xn:vendorData>' + '\n'
		if(self.death != -1):
			s = s + '    <xn:vendorData>MKTNEWS_:mnexpire='+escapexml(str(self.death))+'</xn:vendorData>' + '\n'
		if(self.price != -1):
			s = s + '    <xn:vendorData>MKTNEWS_:ucprice='+escapexml(str(self.price))+'</xn:vendorData>' + '\n'
		s = s + '  </xn:Resource>' + '\n'
		s = s + '</document>' + '\n'
		return s

