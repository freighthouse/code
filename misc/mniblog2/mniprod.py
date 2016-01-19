
# @author: Jeremy Cerda
# @version: $Id: mniprod.py 2644 2011-09-20 16:15:38Z jcerda $

import sys
# NEED TO STRIP EVERY ELEMENT

class mniprod:
	data = list()

	def __init__(self, data):
		ldata = data.split('\n')
		ldata = [xl.split('\t') for xl in ldata if not xl.startswith('#') and not len(xl.strip()) == 0]


		l2data = [[xxl.strip() for xxl in xl] for xl in ldata]

		self.data = l2data

	def gettopicdata(self, fl):
		r = list()

		for xproddata in self.data:
			if len(xproddata) >= 2:
				sele = xproddata[1]

				if fl.count(sele.replace('-','=')) > 0:
					r.append(xproddata)

		slow = 1
		quick = 0
		topics = list()
		embargo = -1
		death = -1
		price = -1

		for xr in r:
			if len(xr) >= 4:
				topics = topics + xr[5].split(' ')

			if quick == 0:
				if len(xr) < 7 or xr[6] != 'SLOW':
					slow = 0
				if len(xr) >= 7 and xr[6] == 'QUICK':
					quick = 1
				if(int(xr[2]) > embargo):
					embargo = int(xr[2])
				if(int(xr[3]) > death):
					death = int(xr[3])
				if(float(xr[4]) > price):
					price = float(xr[4])

		if slow:
			embargo = -1
			death = -1

		topics = list(set(topics))

		topics = [xt for xt in topics if not xt == 'None']

		return (embargo, death, price, topics)

	def gettimetopics(self, fl):
		r = list()

		for xproddata in self.data:
			if len(xproddata) >= 2:
				sele = xproddata[1]

				if fl.count(sele.replace('-','=')) > 0:
					r.append( xproddata)


		# IF THERE ARE ANY QUICKS, THEN IT ANSWERS TIME..
		# IF NOT, LARGEST IS ANSWER
		# COMBiNE TOPICS, though..

		slow = 1
		topics = list()
		time = -1
		quick = 0

		for xr in r:
			if len(xr) >= 4:
				topics = topics + xr[3].split(' ')

			if quick == 0:
				if len(xr) < 5 or xr[4] != 'SLOW':
					slow = 0
				if len(xr) >= 5 and xr[4] == 'QUICK':
					quick = 1
				if(int(xr[2]) > time):
					time = int(xr[2])

		if slow:
			time = -1

		topics = list(set(topics))

		topics = [xt for xt in topics if not xt == 'None']

		return (time, topics)


	def getdata(self):
		return self.data


def main(args):
	f = file('production.cfg', 'r')
	xf = f.read()
	f.close()

	m = mniprod(xf)

	print m.getdata()

	pls = [ 'F=ETRENC' ]
	plt = [ 'MGQ$$$', 'M$$FX$']

	print m.gettimetopics(pls+plt)

if __name__=='__main__':
	sys.exit(main(sys.argv))
