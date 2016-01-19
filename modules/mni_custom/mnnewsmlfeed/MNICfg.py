
# @author: Jeremy Cerda
# @version: $Id: MNICfg.py 2696 2011-09-27 19:03:48Z jcerda $

import ConfigParser

class MNICfg:
    cfgFile = ""
    cfg = None

    def __init__(self,cfgFile,defaultSection=''):
        self.cfgFile = cfgFile
        self._defaultSection = defaultSection

        self.cfg = ConfigParser.ConfigParser()
        self.cfg.read(self.cfgFile)

    # Shortcut function for grabbing properties. Defaults to default section
    def cfgGet(self, prop, default='', section=''):
        if(section == ''):
            section = self._defaultSection
        try:
            return self.cfg.get(section, prop)
        except ConfigParser.NoOptionError:
            return default

    def get_default_section(self):
        return self.__defaultSection


    def set_default_section(self, value):
        self.__defaultSection = value

    defaultSection = property(get_default_section, set_default_section)
