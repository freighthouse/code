#!/usr/bin/python

# @version $Id: mnemb.py 2643 2011-09-20 15:20:06Z jcerda $

# YOUR JOB IS TO GRAB STUFF FROM QUEUE DIRECTORY, MOVE TO DELIVERY, BASED ON CODES IN IT..
# PARSING XML..

import sys
import mniprod
import time
import os
import xml.dom.minidom
import shutil
from datetime import datetime

print "EMB-PRE-START"

mpf = file(sys.argv[1], 'r')
mproddata = mpf.read()
mpf.close()

def timeLog():
	return datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ": "

def main(args):
	mp = mniprod.mniprod(mproddata)

	print timeLog() + "mniblog2 - mnemb.py - " \
        	+ "V: $Id: mnemb.py 2643 2011-09-20 15:20:06Z jcerda $"

	while 1:
		x = os.walk('queue')

		y = None

		for xx in x:
			y = xx[2]
			break

		if y is None:
			y = list()

		for xy in y:
			print repr(xy)

			mypath = os.path.join('queue', xy)

			fxy = file(mypath)

			dfxy =	xml.dom.minidom.parse(fxy)

			prefix = 'MKTNEWS_:Special Code='

			mytags = [q[0].nodeValue[len(prefix):].split('/')[1].replace('-','=') for q in [z.childNodes for z in dfxy.getElementsByTagName('xn:vendorData')] if q[0].nodeValue.startswith(prefix)]

			(thetime, tops) = mp.gettimetopics(mytags)

			if thetime < 0:
				print "This should never happen."
			else:
				mypathtime = os.path.getctime(mypath)

				# THIS NEW PUBTIME CODE IS UNTESTED
				mypubtime = dfxy.getElementsByTagName('xn:publicationTime')[0].childNodes[0].nodeValue
				tz = mypubtime[-5:]
				if(tz == "-0500"):
					mypubtime = mypubtime[:-5] + " EST"
				elif(tz == "-0400"):
					mypubtime = mypubtime[:-5] + " EDT"
				mypubtime = time.mktime(time.strptime(mypubtime, "%Y%m%dT%H%M%S %Z"))
				# THIS NEW PUBTIME CODE IS UNTESTED

				#if mypathtime + thetime <= time.time():
				if mypubtime + thetime <= time.time():
					deliverypath = os.path.join('delivery', xy)

					shutil.move(mypath, deliverypath)

					print "I MOVE "+mypath
				else:
					print "NOT TIME TO MOVE "+mypath+" YET."
				print "PUBTIME : " + str(mypubtime)
				print "PATHTIME: " + str(mypathtime)

			fxy.close()

		sys.stdout.flush()
		time.sleep(10)

        return 0

if __name__=='__main__':
        sys.exit(main(sys.argv))
