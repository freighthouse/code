#!/usr/bin/python

# @author Jeremy Cerda
# @version $Id: mngenerate.py 2337 2011-07-08 15:25:32Z jcerda $

import sys
import os

#mniblog_home = "/usr/local/mniblog"
sys.path.append("..")

import socket
import mniser
import mnifhandler
import mnimsg
import re
import mniprod
import mniblogxml
import time

mpf = file(sys.argv[1], 'r')
mproddata = mpf.read()
mpf.close()


headstrip = '[.]*>\s*'
headstripregex = re.compile(headstrip)

def stripHeadline(s):
	s = headstripregex.sub('', s)
	return s

class myhandler(mnifhandler.mnifhandler):
	mp = mniprod.mniprod(mproddata)
	t = None
	year = -1
	seq = 0

	def __init__(self, year=-1):
		self.year = year

	def receivedNews(self, msg):
		print >>sys.stderr, "NEWS"
		m = mnimsg.mnimsg(msg)

		(time, tops) = self.mp.gettimetopics(m.getselectors()+m.gettopics())

		if time < 0:
			return
		elif time == 0:
			mydir = '../delivery'
		else:
			mydir = '../queue'

		nt = m.getiso8601timestamp(self.year)
		nt = nt.split('-')[0]
		if nt == self.t:
			self.seq = self.seq + 1
		else:
			self.seq = 0
		self.t = nt

		myname = nt+repr(self.seq)+'.xml'

		try:
			myfile = os.path.join(mydir, myname)

			fmyfile = open(myfile, 'wb')

			print "I'LL PUBLISH "+m.gettimestamp()+" "+stripHeadline(m.getheadline())+" to "+repr(tops)+" in "+repr(time)+" seconds to "+repr(myfile)
			mx = mniblogxml.mniblogxml(m,tops, self.year)
			fmyfile.write(mx.toxml())
			fmyfile.close()
		except Exception, e:
			print "EXCEPTION IS "+repr(e)

#		m = mnimsg.mnimsg(msg)

#		print "SELECTORS:"+repr(m.getselectors())
#		print "TOPICS:"+repr(m.gettopics())
#		print "DESTINATION:"+m.getdestination()
#		print "TIMESTAMP:"+m.gettimestamp()
#		print "HEADLINE:"+stripHeadline(m.getheadline())
#		print "STORY:"+m.getstory()
#		print "CHECKSUM:"+m.getchecksum()

#		sys.stdout.write(msg)
		pass

	def receivedJunk(self, msg):
		print >>sys.stderr, "JUNK"
#		sys.stdout.write(msg)
		pass

	def receivedHeartbeat(self, msg):
		print >>sys.stderr, "HEARTBEAT"
#		m = mnimsg.mnimsg(msg)
#		sys.stdout.write(msg)
#		print "PARITY:"+repr(ord(m.getbeat()))
		pass

	def receivedDownload(self, msg):
		print >>sys.stderr, "DOWNLOAD"

#		m = mnimsg.mnimsg(msg)
#		print "SERIAL:"+m.getserial()
#		print "SELECTORS:"+repr(m.getselectors())
		pass




# arg 1 - config file
# arg 2 - year to append to data
def main(args):
	year = -1
	if(len(args) > 2):
		year = int(args[2])
	#ip = args[2].split(':')[0]
	#port = int(args[2].split(':')[1])

	#mfh = myhandler(year)
	#ms = mniser.mniser()
	#ms.addhandler(mfh)
	#
        #while 1:
	#	print "SEEKING CONNECT"
        #        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	#	s.settimeout(60)
	#
	#	print "CONNECT"
	#
	#	try:
        #       	s.connect( (ip, port))
	#	except:
	#		try:
	#			s.close()
	#		except:
	#			pass
	#
	#		continue
	#
	#	try:
	#		ms.parse(s.recv)
	#	except:
	#		pass
	#
        #       s.close()

	mfh = myhandler(year)
	ms = mniser.mniser()
	ms.addhandler(mfh)

	ms.parse(sys.stdin.read)

        return 0

if __name__=='__main__':
        sys.exit(main(sys.argv))
