
# @author: Jeremy Cerda
# @version: $Id: mnimsg.py 2337 2011-07-08 15:25:32Z jcerda $

import re
import time

escpat = re.compile('\033.')
toppat = re.compile('[ ,:\n\r\[\]]*')

# FORGOT TOPICS!

class newsmnimsg:
	msg = ''

	def __init__(self, msg):
		self.msg = msg

	def getbytes(self):
		return self.msg

	def getselectors(self):
		sel = self.msg[5:self.msg.index(chr(2),5)].replace(chr(10),'')

		sels = [sel[x:x+8] for x in range(0, len(sel), 8)]

		return sels

	def getdestination(self):
		start = self.msg.index(chr(19))

		end = self.msg.index(chr(17), start)

		return self.msg[start+1:end]

	def gettimestamp(self):
		start = self.msg.index(chr(17))

		return self.msg[start+1:start+16]

	def getiso8601timestamp(self, year=-1):
		ts = self.gettimestamp()
		tz = ts[6:9]

		# Safety checks for implied year data
		if(year < 0):
			year = int(time.strftime('%Y'))
		pmonth = int(ts[-5:-3])
		cmonth = int(time.strftime('%m'))
		if((cmonth == 12) and (pmonth == 1)):
			year = year + 1
		elif((cmonth == 1) and (pmonth == 12)):
			year = year - 1

		ts = str(year)+ts[-5:-3]+ts[-2:]+'T'+ts[:2] \
			+ts[3:5]+"00"
		if(tz == "EST"):
			tz = "-0500"
		elif(tz == "EDT"):
			tz = "-0400"
		else:
			tz = ""
		return ts+tz

	def getheadline(self):
		start = self.msg.index(chr(31))

		end = self.msg.index(chr(30), start)

		return self.msg[start+1:end]

	def getstory(self):
		start = self.msg.index(chr(30))

		end = self.msg.index(chr(30), start+1)

		story = self.msg[start+1:end]

		story = escpat.sub('', story)

		return story

	def getchecksum(self):
		start = self.msg.index(chr(4))

		return self.msg[start + 1:start + 1 + 4]

	def gettopics(self):
		r = list()
		s = self.getstory()

		start = s.find('[TOPICS:')
		end = s.find(']', start)

		if start > -1 and end > -1:
			toptext = s[start:end]

			r = [t for t in toppat.split(toptext) if len(t) > 0 and not t == 'TOPICS']

		return r


class heartbeatmnimsg:
	msg = ''

	def __init__(self, msg):
		self.msg = msg

	def getbytes(self):
		return self.msg

	def getbeat(self):
		return self.msg[15]

class downloadmnimsg:
	msg = ''

	def __init__(self, msg):
		self.msg = msg

	def getbytes(self):
		return self.msg

	def getserial(self):
		return self.msg[5:13]

	def getselectors(self):
		return self.msg[14:].replace(chr(2),'')


# I SHOULD HAVE ALREADY VALIDATED..
def mnimsg(msg):
	if msg.startswith(chr(22)+chr(22)+chr(1)+'D'):
		return downloadmnimsg(msg)
	elif msg.startswith(chr(22)+chr(22)+chr(1)+'n '+'........'+\
                            chr(10)+chr(2)+chr(16)+chr(0)):
		return heartbeatmnimsg(msg)
	elif msg.startswith(chr(22)+chr(22)+chr(1)+'n '+'........'+\
                            chr(10)+chr(2)+chr(19)+chr(0)):
		return heartbeatmnimsg(msg)
	else:
		return newsmnimsg(msg)

# [22, 22, 1, 110, 32, 46, 46, 46, 46, 46, 46, 46, 46, 10, 2, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3]
