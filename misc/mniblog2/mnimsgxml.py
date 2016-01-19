
# @author: Jeremy Cerda
# @version: $Id: mnimsgxml.py 2337 2011-07-08 15:25:32Z jcerda $

import time
import ConfigParser
from xml.dom.minidom import parse, parseString

class mnimsgxml:
	#self.dom = None
	#type = None
	#topics = None
	#story = None

	def __init__(self, msg):
		if isinstance(msg, str):
			self.dom = parseString(msg)
		else:
			self.dom = msg
		type = self.dom.getElementsByTagName('ContentType')[0] \
			.childNodes[0].nodeValue

	def getxml(self):
		return self.dom.toxml()

	def getcontenttype(self):
		return self.dom.getElementsByTagName('ContentType')[0] \
			.childNodes[0].nodeValue

	def getbytes(self):
		return bytearray(self.getxml())

	def getMsgType(self):
		return type

	def gettimestamp(self):
		return self.dom.getElementsByTagName('LegacyTimestamp')[0] \
			.childNodes[0].nodeValue

	def getiso8601timestamp(self, year=-1):
		return self.dom.getElementsByTagName('PublicationTime')[0] \
			.childNodes[0].nodeValue

	def getheadline(self):
		return self.dom.getElementsByTagName('Title')[0] \
			.childNodes[0].nodeValue

	def getstory(self):
		return self.dom.getElementsByTagName('Content')[0] \
			.childNodes[0].nodeValue

	def getselectors(self):
		s = list()


	def gettopics(self):
		t = [n.childNodes[0].nodeValue for n in
		     self.dom.getElementsByTagName('Product')
		     if int(n.childNodes[0].nodeValue) > 39999 and
		     int(n.childNodes[0].nodeValue) < 50000]
		return t

	def getselectors(self):
		t = self.gettopics()
		s = [n.childNodes[0].nodeValue for n in
		     self.dom.getElementsByTagName('Product')
		     if not n.childNodes[0].nodeValue in t]
		return s

	def gettaxonomies(self):
		return [n.childNodes[0].nodeValue for n in
		     self.dom.getElementsByTagName('Product')]

def mnimsgfromfile(filename):
	dom = parse(open(filename))
	return mnimsgxml(dom)
