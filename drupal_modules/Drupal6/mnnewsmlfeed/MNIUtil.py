
# @author: Jeremy Cerda
# @version: $Id: MNIUtil.py 2696 2011-09-27 19:03:48Z jcerda $

from datetime import datetime

class MNIUtil:

    @staticmethod
    def timeLog():
        return datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ": "
