
# @author: Jeremy Cerda
# @version: $Id: MNIArchiver.py 2696 2011-09-27 19:03:48Z jcerda $

import sys
import os
import shutil
from MNIUtil import MNIUtil

class MNIArchiver:
    dst = None

    def __init__(self,dst):
        self.dst = dst

    def get_dst(self):
        return self.__dst


    def clearFile(self, srcDir, filename):
        try:
            os.remove(srcDir + "/" + filename)
            return 1
        except:
            print MNIUtil.timeLog() + "ERROR: Error clearing " + filename
            return 0

    # Archives given file, complete with error checking
    # Returns 1 for success, 2 for error but renamed, and 0 for failure
    def archiveFile(self, srcDir, filename, subdir=""):
        d = self.dst
        if(subdir != ""):
            d += "/"+subdir

        try:
            shutil.copy2(srcDir+"/"+filename, d+"/"+filename)
            return 1
        except:
            print MNIUtil.timeLog() + "ERROR: Error archiving " + filename

            if(testArchiving(subdir)):
                return archiveFile(srcDir, filename, subdir)
            else:
                print MNIUtil.timeLog() + "ERROR: Attempt to fix " + \
                    "archiving has failed. Please diagnose and restart."
                return 0

    def testArchiving(self, subdir=""):
        d = self.dst
        if(subdir != ""):
            d += "/"+subdir

        # Check archive dir
        if(not os.path.isdir(self.dst)):
            os.mkdir(self.dst)
        if(os.path.isdir(self.dst)):

            # Check full dir
            fullDir = d
            if(not os.path.isdir(fullDir)):
                os.mkdir(fullDir)
            if(os.path.isdir(fullDir)):

                # Check file writing
                f = open(fullDir+"/test.txt",'w')
                f.write('gerg')
                f.close()
                if(os.path.isfile(fullDir+"/test.txt")):
                    os.remove(fullDir+"/test.txt")
                    return 1
        return 0

    dst = property(get_dst, None, None, None)
