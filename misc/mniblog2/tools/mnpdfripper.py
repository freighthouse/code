#!/usr/bin/python

# @author Jeremy Cerda
# @version $Id: mnpdfripper.py 2337 2011-07-08 15:25:32Z jcerda $

import os
import sys
#import xml.sax.handler.*
from xml.sax.handler import ContentHandler
import xml.sax
import uu

class PDFRipperHandler(ContentHandler):

        def __init__(self, f):
                self.filename = f
                self.isContent = None
                self.tmpfile = None

        def startElement(self, name, attrs):
                self.isContent = (name == "Content")


        def characters(self, ch):
                if self.isContent:
                        try:
                                if self.tmpfile == None:
                                        self.tmpfile = open('rich_tmp', 'a')
                                self.tmpfile.write(ch)
                        except:
                                self.tmpfile.close()

        def endElement(self, name):
                if self.isContent:
                        self.tmpfile.close()
                        if os.path.isfile('rich_tmp'):
                                uu.decode('rich_tmp', self.filename, None, True)
                                os.remove('rich_tmp')


# For testing
def main(args):
        if(len(sys.argv) < 2):
                print "Error no file given"
                sys.exit(1)

        parser = xml.sax.make_parser()
        ripper = PDFRipperHandler("test.pdf")
        parser.setContentHandler(ripper)
        parser.parse(sys.argv[1])
        pass

if __name__=='__main__':
        sys.exit(main(sys.argv))
