#!/usr/bin/python

# @author: Jeremy Cerda
# @version: $Id: mnadapt.py 2644 2011-09-20 16:15:38Z jcerda $

import sys
import socket
import mniser
import mnifhandler
import mnimsg
import re
import mniprod
import mniblogxml
import time
import os
import ConfigParser
from datetime import datetime

headstrip = '[.]*>\s*'
headstripregex = re.compile(headstrip)

cfg = None

class timeseq:
	t = None
	seq = 0

	def __init__(self):
		pass

	def getnameseq(self):
		nt = int(time.time())

		if nt == self.t:
			self.seq = self.seq + 1
		else:
			self.seq = 0

		self.t = nt

		return (time.strftime('%Y%m%dT%H%M%S', time.localtime(nt)), \
			self.seq)


class myhandler(mnifhandler.mnifhandler):
	#mp = mniprod.mniprod(mproddata)
	mp = None
	ts = timeseq()
	dirDelivery = "/usr/local/mniblog2/delivery"
	dirEmbargo = "/usr/local/mniblog2/queue"
	name = "default"
	log = False
	year = -1

	def __init__(self, proddata=None, feedName="default", \
	delivery="/usr/local/mniblog2/delivery", \
	embargo="/usr/local/mniblog2/queue", shouldLog=False, year=-1):
		self.mp = mniprod.mniprod(proddata)
		self.dirDelivery = delivery
		self.dirEmbargo = embargo
		self.name = feedName
		self.log = shouldLog
		self.year = year
		self.shouldLog = shouldLog
		if(self.shouldLog):
			print timeLog() + "DELIVERY - " + self.dirDelivery

	def receivedNews(self, msg):
		#print >>sys.stderr, timeLog() + "NEWS"
		m = mnimsg.mnimsg(msg)

		time = 0
		embargo = 0
		death = 0
		price = 0
		if cfgGet("cfg.advanced"):
			(embargo, death, price, tops) = \
				self.mp.gettopicdata(m.getselectors() + \
						m.gettopics())
		else:
			(time, tops) = \
				self.mp.gettimetopics(m.getselectors() + \
						m.gettopics())


		print >>sys.stderr, self.name+" "+str(m.getselectors() + m.gettopics())+" "+str(time)+" "+str(tops)

		if time < 0 or embargo < 0 or len(tops) == 0:
			return
		elif time == 0:
			mydir = self.dirDelivery
		else:
			mydir = self.dirEmbargo

		xts = self.ts.getnameseq()

		myname = xts[0]+repr(xts[1])+'.xml'

		try:
			myfile = os.path.join(mydir, myname)

			fmyfile = open(myfile, 'wb')

			if(self.shouldLog):
				print timeLog() + "NEWS - " + self.name + \
					" - " + myname + " - " + \
					stripHeadline(m.getheadline())
				logData()
			if cfgGet("cfg.advanced"):
				mx = mniblogxml.mniblogxml(m,tops,self.year,\
							embargo,death,price)
			else:
				mx = mniblogxml.mniblogxml(m,tops,self.year)
			fmyfile.write(mx.toxml())
			fmyfile.close()
		except Exception, e:
			print timeLog() + "EXCEPTION IS " + repr(e)

		sys.stdout.flush()
		pass

	def receivedJunk(self, msg):
		if self.log:
			print >>sys.stderr, timeLog() + "JUNK"
		pass

	def receivedHeartbeat(self, msg):
		if self.log:
			print timeLog() + "HEARTBEAT"
			sys.stdout.flush()
			logData()
		pass

	def receivedDownload(self, msg):
		if self.log:
			print >>sys.stderr, timeLog() + "DOWNLOAD"
		pass

# Shortcut function for grabbing properties. Makes code cleaner to read.
def cfgGet(prop):
	try:
		return cfg.get("mnadapt.py", prop)
	except Exception, e:
		return False
def timeLog():
	return datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ": "

def logData():
	global cfg
	filename = cfgGet("log.data")
	if filename:
		bloghome = cfg.get("mniblogpub.shared", "bloghome")
		filename = bloghome + "/" + filename
		logfile = open(filename, 'a+')
		logfile.write(timeLog() + "DATA" + "\n")
		logfile.flush()
		logfile.close()

def stripHeadline(s):
	s = headstripregex.sub('', s)
	return s

def newHandler(cfgfilename, feedName="default",
deliveryDir="/usr/local/mniblog2/delivery", pShouldLog=False, year=-1):
	mpf = file(cfgfilename)
	proddata = mpf.read()
	mpf.close()
	return myhandler(proddata, feedName=feedName, delivery=deliveryDir, \
					shouldLog=pShouldLog, year=year)

def printUsage():
	print "USAGE: mnadapt.py [<production.cfg> <pub.production.cfg> |" + \
		" -m <multipub.cfg>] [-i [year]]"

	print

	print "Normal usage is to specify a production and pub.production " + \
		"for normal operation to marketnews, imarketnews, or mni6."
	print "The -m option will provide the mutli-feed option, which is " + \
		"used with mninews. See below for all options."

	print

	print "-m      Signifies mutli-feed publication mode. To be used " + \
		"with a multipub config file."
	print "-i      Signifies data will be read from stdin. Optional " + \
		"year can be specified for data."
	sys.exit(0)

def main(args):
	global cfg
	global data_log_file

	if(len(args) < 2):
		printUsage()

	year = -1
	readStdin = ("-i" in args)
	if readStdin and args[len(args)-1] != "-i":
		year = int(args[len(args)-1])
	ms = mniser.mniser()

	if(args[1] == "-m"):
		cfg = ConfigParser.ConfigParser()
		cfg.read(args[2])
		bloghome = cfg.get("mniblogpub.shared", "bloghome")
		feeds = [f for f in cfg.sections() if f.startswith('feed.')]
		i = 0
		for f in feeds:
			deliveryDir = cfg.get(f, "delivery")
			if(deliveryDir[0] != '/'):
				deliveryDir = bloghome +'/'+ deliveryDir
			prodcfg = cfg.get(f,"production.cfg")
			if(prodcfg[0] != '/'):
				prodcfg = bloghome +'/'+ prodcfg
			feedname = cfg.get(f, "name")
			ms.addhandler(newHandler(prodcfg, \
						feedname, \
						deliveryDir,(i == 0), \
						year=year))
			i += 1
	else:
		cfg = ConfigParser.ConfigParser()
		cfg.read(args[2])
		bloghome = cfg.get("mniblogpub.shared", "bloghome")
		deliveryDir = cfg.get("mniblogpub.shared", "delivery")
		if(deliveryDir[0] != '/'):
			deliveryDir = bloghome +'/'+ deliveryDir
		ms.addhandler(newHandler(sys.argv[1], \
					deliveryDir=deliveryDir, \
					pShouldLog=True, \
					year=year))

	jms_host = cfgGet("ser.host")
	jms_port = int(cfgGet("ser.port"))

	while not readStdin:
		print timeLog() + "mniblog2 - mnadapt.py - " \
        	+ "V: $Id: mnadapt.py 2644 2011-09-20 16:15:38Z jcerda $"
		print timeLog() + "CONNECTING TO " + \
			str(jms_host)+":"+str(jms_port) + "..."
		sys.stdout.flush()
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s.settimeout(60)

		#print timeLog() + "CONNECT"

		try:
			s.connect( (jms_host, jms_port))
			print timeLog() + "CONNECTED!"
			sys.stdout.flush()
		except:
			try:
				s.close()
			except:
				pass
			time.sleep(float(cfgGet("loopdelay")))
			continue

		try:
			ms.parse(s.recv)
		except:
			#pass
			s.close()

	if readStdin:
		#mfh = myhandler()
		#ms = mniser.mniser()
		#ms.addhandler(mfh)
		ms.parse(sys.stdin.read)

	return 0

if __name__=='__main__':
	sys.exit(main(sys.argv))
