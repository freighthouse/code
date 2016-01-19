#!/usr/bin/python

# @author: Jeremy Cerda
# @version: $Id: mniser.py 2337 2011-07-08 15:25:32Z jcerda $

#import mnifhandler

# REWORK THIS SO IT USES EXCEPTIONS AND NOT EXPLICIT ARRAY LENGTH CHECKS..

class mniser:
        CHR_ETX = chr(3)
        CHR_STX = chr(2)
        CHR_SYN = chr(22)
        CHR_SOH = chr(1)
	CHR_DLE = chr(16)
	CHR_DC1 = chr(17)
	CHR_DC3 = chr(19)
	CHR_NUL = chr(0)
	CHR_ESC = chr(27)
	CHR_LF = chr(10)
	CHR_RS = chr(30)
	CHR_US = chr(31)
	CHR_EOT = chr(4)

	selectorchars = ['A','B','C','D','E','F','G','H','I','J',\
                         'K','L','M','N','O','P','Q','R','S','T',\
			 'U','V','W','X','Y','Z','=','0','1','2',\
                         '3','4','5','6','7','8','9','.']

	checksumchars = ['0','1','2','3','4','5','6','7','8','9',\
			 'A','B','C','D','E','F']

	handlers = list()


	def __init__(self):
		pass

	def addhandler(self, h):
		self.handlers.append(h)

	def removehandler(self, h):
		self.handlers.remove(h)


	def parse(self, func):
		buf = ''

		while 1:
			data = func(1024)

			buf = buf + data

			if len(data) == 0:
				break


			while 1:
				# EMPTY BUFFER
				if len(buf) == 0:
					break

				# NO FRAME START BYTE, LOOK FOR ONE
				if not buf[0] == self.CHR_SYN:
					q = buf.find(self.CHR_SYN, 1)

					if q == -1:
						q = len(buf)

					self.__firejunk(buf, q)

					print "Skipping over "+repr(q)+" bytes."

					# !!! HERE I NEED TO HANDLE JUNK!

					buf = buf[q:]
					continue

				# CHECK FOR COMPLETE TRANSMISSION, HAVING FOUND FRAME START..

				q = buf.find(self.CHR_ETX)

				if q == -1:
					break

				# NOW WE SHOULD HAVE A FRAME START AND FRAME END
				msg = buf[0: q+1]
				buf = buf[q+1:]

				i = 0
				f = self.__consumeSYNSYNSOH

				while 1:
					try:
						(i, f) = f(msg, i)
					except Exception, e:
						print e
						self.__firejunk(msg, len(msg))
						break

					if f is None:
						break

#   		  	        	print "XX:"+repr(i)+" of "+repr(len(msg))+" -- " + repr(f)


	def __consumeSYNSYNSOH(self, msg, i):
        	if msg[i] == self.CHR_SYN:
                	if msg[i+1] == self.CHR_SYN:
                       		if msg[i+2] == self.CHR_SOH:
                                	return (i+3, self.__consumeNewsOrDownload)

		raise(self)

	def __consumeNewsOrDownload(self, msg, i):
        	if msg[i] == 'n':
                	return (i+1, self.__nconsumeSP)
        	elif msg[i] == 'D':
                	return (i+1, self.__dconsumeSP)
        	else:
			raise(self)

	def __nconsumeSP(self, msg, i):
        	if msg[i] == ' ':
                	return (i+1, self.__nconsumeSelector)
        	else:
                	raise(self)

	def __dconsumeSP(self, msg, i):
        	if msg[i] == ' ':
                	return (i+1, self.__dconsumeSerial)
        	else:
                	raise(self)

	def __nconsumeSelector(self, msg, i):
		for n in range(0,8):
			if self.selectorchars.count(msg[i+n]) == 0:
				raise(self)

		return (i+8, self.__nconsumeCondLF)


	def __dconsumeSerial(self, msg, i):
		for n in range(0,8):
			if self.selectorchars.count(msg[i+n]) == 0:
				raise(self)

		return (i+8, self.__dconsumeSTX)

	def __nconsumeCondLF(self, msg, i):
		if msg[i] == '\n':
			return (i+1, self.__nconsumeCondSTX)

		return (i, self.__nconsumeCondSTX)

	def __nconsumeCondSTX(self, msg, i):
		if msg[i] == self.CHR_STX:
			return (i+1, self.__consumeNewsOrHeartbeat)
		else:
			return (i, self.__nconsumeSelector)


	def __dconsumeSTX(self, msg, i):
		if msg[i] == self.CHR_STX:
			return (i+1, self.__dconsumeSelector)
		else:
			raise(self)

	def __dconsumeSelector(self, msg, i):
		for n in range(0,8):
			if self.selectorchars.count(msg[i+n]) == 0:
				raise(self)

		return (i+8, self.__dconsumeCondLF)


	def __dconsumeCondLF(self, msg, i):
		if msg[i] == '\n':
			return (i+1, self.__dconsumeCondETX)

		return (i, self.__dconsumeCondETX)

	def __dconsumeCondETX(self, msg, i):
		if msg[i] == self.CHR_ETX:
			return (i+1, self.__firedownload)

		return (i, self.__dconsumeSelector)

	def __consumeNewsOrHeartbeat(self, msg, i):
		if msg[i] == self.CHR_DLE:
                	if msg[i+1] == self.CHR_SOH:
                       		if msg[i+2] == self.CHR_DC3:
                                	return (i+3, self.__nconsumeDestination)

		if msg[i] == self.CHR_DLE:
                	if msg[i+1] == self.CHR_NUL:
                       		if msg[i+2] == self.CHR_NUL:
                                	return (i+3, self.__hconsumeNulls)

		if msg[i] == self.CHR_DC3:
                	if msg[i+1] == self.CHR_NUL:
                       		if msg[i+2] == self.CHR_NUL:
                                	return (i+3, self.__hconsumeNulls)

		return (-1, None)

	def __nconsumeDestination(self, msg, i):
		if i + 8 > len(msg):
			raise(self)

		return (i+8, self.__nconsumeDC1)

	def __nconsumeDC1(self, msg, i):
		if msg[i] == self.CHR_DC1:
			return (i+1, self.__nconsumeTimestamp)

		raise(self)

	def __nconsumeTimestamp(self, msg, i):
		if msg[i+15] == self.CHR_LF:
			if msg[i+16] == self.CHR_US:
				return (i+17, self.__nconsumeHeadline)

		raise(self)

	def __nconsumeHeadline(self, msg, i):
		q =  msg.index(self.CHR_RS, i)

		for r in range(i, q):
			if ord(msg[r]) < 32:
				if ord(msg[r]) > 127:
					raise(self)

		return (q+1, self.__nconsumeStory)

	def __nconsumeStory(self, msg, i):
		q = msg.index(self.CHR_RS, i)

		if q + 3 > len(msg):
			raise(self)

		if not msg[q+1] == self.CHR_DC3:
			raise(self)

		if not msg[q+2] == self.CHR_EOT:
			raise(self)

# PASS 1, printable or escape character
		for r in range(i, q):
			if msg[r] == self.CHR_ESC:
				if ord(msg[r]) < 32:
					if ord(msg[r]) > 127:
						raise(self)

# PASS 2, make sure any escape is followed by a T, D, I or C.
		lastchar = ''

		for r in range(i, q):
			if lastchar == self.CHR_ESC:
				if not msg[r] == 'T' and \
			           not msg[r] == 'D' and \
	         		   not msg[r] == 'I' and \
				   not msg[r] == 'C':
					raise(self)

			lastchar = msg[r]


		if lastchar == self.CHR_ESC:
			raise(self)

		return (q+3, self.__nconsumeChecksum)


	def __nconsumeChecksum(self, msg, i):
		for r in range(0,4):
			if self.checksumchars.count(msg[i+r]) == 0:
				raise(self)

		return (i + 4, self.__nconsumeETX)

	def __nconsumeETX(self, msg, i):
		if msg[i] == self.CHR_ETX:
			return (i+1, self.__firenews)

		raise(self)

	def __hconsumeNulls(self, msg, i):
		if i + 8 > len(msg):
			raise(self)

		return (i+8, self.__hconsumeETX)

	def __hconsumeETX(self, msg, i):
		if msg[i] == self.CHR_ETX:
			return (i+1, self.__fireheartbeat)

		raise(self)

	def __fireheartbeat(self, msg, i):
		for xl in self.handlers:
			xl.receivedHeartbeat(msg)

		return (i, None)

	def __firenews(self, msg, i):
		for xl in self.handlers:
			xl.receivedNews(msg)

		return (i, None)

	def __firedownload(self, msg, i):
		for xl in self.handlers:
			xl.receivedDownload(msg)

		return (i, None)

	def __firejunk(self, msg, i):
		for xl in self.handlers:
			xl.receivedJunk(msg)

		return (i, None)



