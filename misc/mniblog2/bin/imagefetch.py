#!/usr/bin/python

# @version $Id: imagefetch.py 2337 2011-07-08 15:25:32Z jcerda $

import datetime
import hashlib
import PIL
import ConfigParser
import Image
import os
import urllib
import StringIO
import string
import sys

# Do we want to use a flatfile to signify which chart is currently live?
# current-chart which can be checked?

bloghome = "/usr/local/mniblog2"
# Format: Tuple of name, remote location, title.  Title should be
# human-readable and suitable for the frontpage as a bolded
# "this is what this is."
chartList = [("eurodollar", "http://marketnews.m.xtenit.com/files" +
	      "/1/marketnews/300/pa/euro.gif", "EURO-DOLLAR")]
imageDirectory = "/var/www/apache2-default/sites/all/themes/mni/images/cod"
currentChartTypeFile = imageDirectory + "/currentcharttype.txt"
loglocation = imageDirectory + "/chartfetch.log"
updateCommand = bloghome + "/bin/chartupdate.php"
updateCfg = None

tooSmallThreshold = (175, 150) #.6
thumbMax = (350, 300)
minAspectRatio = .66 #200 x 300
maxAspectRatio = 2

def main(args):
	global updateCommand

	if (len(args) > 1):
		loadCfgParams(args[1])
		#print "Usage: imagefetch.py <config file>"
		#sys.exit(1)

	opener = urllib.FancyURLopener()
	updated = []
	for chart in chartList:
		f1 = opener.open(chart[1])
		remoteImage = f1.read()
		m1, m2 = hashlib.md5(), hashlib.md5()
		try:
			f2 = file(imageDirectory + chart[0] + "-current.gif",
				  'rb')
			localImage = f2.read()
		except:
			localImage = ""
			logfile = file(loglocation, 'a')
			logfile.write("Can't read the current file!\n")
		m1.update(remoteImage)
		m2.update(localImage)
		if cmp(m1.digest(), m2.digest()) == 0:
			continue
		# Change!
		ri = Image.open(StringIO.StringIO(remoteImage))
		#ri = Image.frombuffer("RGBA", (1000,1000), remoteImage, "raw",
		#	"RGBA", 0, 1)
		mt = string.maketrans('','')
		timeString = datetime.datetime.now().isoformat().translate(mt,
			"-:T")[:-7]
		newImageString = chart[0] + "-" + timeString + ".gif"
		savedImage = file(imageDirectory + newImageString, 'wb')
		savedImage.write(remoteImage)
		savedImage.flush()
		f3 = file(imageDirectory + chart[0] + "-current.gif", 'wb')
		f3.write(remoteImage) #Or use cp?  Don't think that would help.
		f3.flush()
		assessment = assessImage(ri)
		if assessment[0] == 'e':
			logfile = file(loglocation, 'a')
			logfile.write("Ignoring new image " +
				"(though updating current) due to size " +
				"concerns: was " + str(ri.size) + " problem: "+
				assessment[1:] + "\n")
			continue
		thumb = createThumb(ri, int(assessment[0]))
		thumbImageString = newImageString[:-4] + "thumb.gif"
		thumb.save(imageDirectory + thumbImageString)
		# Tell drupal about new image.
		curImageText = file(imageDirectory + "current-" + chart[0] +
			".txt", 'w')
		curImageText.write(newImageString + "\n")
		curImageText.write(thumbImageString + "\n")
		curImageText.flush()
		updated.append(chart[0])

		#Schedule a block update?
		# Check the current contents of a block, see if different,
		# update if so?
	# Check current?
	cchart = file(currentChartTypeFile, 'r')
	ctype = cchart.readline().strip()
	if ctype in updated:
		#Drupal update - no args necessary, should read from file itself.
		# Not true anymore, we want the configuration options now - Greg
		print "UPDATE ME!"

		if updateCfg != None:
			eargs = [updateCommand, updateCfg]
		else:
			eargs = [updateCommand]

		print eargs
		os.execv(updateCommand, eargs)


def loadCfgParams(fname):
	# Parse cfg files
	global chartList, imageDirectory, currentChartTypeFile, loglocation
	global updateCommand, tooSmallThreshold, thumbMax, minAspectRatio
	global maxAspectRatio, bloghome, updateCfg, chartUpdateLog
	cfg = ConfigParser.ConfigParser()
	cfg.read(fname)

	bloghome = cfg.get("mniblogpub.shared", "bloghome")
	imageDirectory = cfg.get("imagefetch.py", "dir.images")

	currentChartTypeFile = imageDirectory + "/" + \
		cfg.get("imagefetch.py", "chart.typefile")
	loglocation = imageDirectory + "/" + \
		cfg.get("imagefetch.py", "log.file")
	updateCommand = bloghome + "/" + \
		cfg.get("imagefetch.py", "chart.cmdfile")
	updateCfg = bloghome + "/" + cfg.get("imagefetch.py", "chart.cfgfile")

	tooSmallThreshold = (int(cfg.get("imagefetch.py", "thumb.min.x")),
		int(cfg.get("imagefetch.py", "thumb.min.y")))
	thumbMax = (int(cfg.get("imagefetch.py", "thumb.max.x")),
		int(cfg.get("imagefetch.py", "thumb.max.y")))
	minAspectRatio = float(cfg.get("imagefetch.py", "thumb.min.aspect"))
	maxAspectRatio = float(cfg.get("imagefetch.py", "thumb.max.aspect"))

	clname = cfg.get("imagefetch.py", "chartlist.name")
	clloc = cfg.get("imagefetch.py", "chartlist.location")
	cltitle = cfg.get("imagefetch.py", "chartlist.title")

	chartList = [(clname, clloc, cltitle)]

# Buncha cases, alas.  Ah well.	 Considered making the valid items ints and
# using something like type or a cast to determine success or failure, but
# that'd be failtastic.
def assessImage(remoteImage):
	size = remoteImage.size
	ar = (size[0] + 0.0) / size[1]
	if ar < minAspectRatio or ar > maxAspectRatio:
		return "easpectratiodistorted"
	if size[0] < tooSmallThreshold[0] or size[1] < tooSmallThreshold[1]:
		return "etoosmall"
	elif size[0] < thumbMax[0] and size[1] < thumbMax[1]:
		return "1xnormal"
	elif size[0] < (thumbMax[0] * 2) and size[1] < (thumbMax[1] * 2):
		return "2xthumb"
	elif size[0] > (thumbMax[0] * 4) or size[1] > (thumbMax[1] * 4):
		return "etoobig"
	elif size[0] < (thumbMax[0] * 3) or size[1] < (thumbMax[1] * 3):
		return "e3xthumb"
	else:
		return "4xthumb"


def createThumb(im, scale):
	if scale == 1:
		return im
	# Old division should guarantee ints - in new version of python,
	# you have to use rounding afterward in case you got a rational number.
	nwidth, nheight = im.size[0] / scale, im.size[1] / scale
	return im.resize((nwidth, nheight), Image.ANTIALIAS)

if __name__=='__main__':
	sys.exit(main(sys.argv))

'''
When Euro-Dollar tech comes in:
TOPIC: (Everything after Commentary.)
Write this to a file with something like topic-datetime as well as
topic-current.txt .  ("Topic" to change to eurodollar, bundtechs, etc.)

Every minute:
Check image locations.
Save in a temp file.
Diff with topic-current.gif
If the same, do nothing.
If different, overwrite topic-current.gif (and update block?).


Have our own separate static feed reader for this, or work into current mniblog?

Another idea: Use the most recent chart?

Separate block for thumb: Fine.
Other charts: Hmm.

Caption: Huh.
'''
