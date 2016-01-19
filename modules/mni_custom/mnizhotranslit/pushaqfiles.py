#!/usr/bin/python

# @author Jeremy Cerda
# @version $Id: pushaqfiles.py 2693 2011-09-27 15:09:19Z jcerda $

import os
import sys
import re
import ConfigParser
import socket
import paramiko
import shutil
import time
from datetime import datetime

cfg = None

# Archives given file, complete with error checking
# Returns 1 for success, 2 for error but renamed, and 0 for failure
def archiveFile(srcDir, dstDir, filename):
        try:
                shutil.move(srcDir+filename, dstDir+filename)
                return 1
        except:
                print timeLog() + "ERROR: Error archiving " + filename
                if(not os.path.exists(dstDir + filename)):
                        try:
                                # Try renaming first
                                shutil.move(srcDir + filename, srcDir + \
                                            filename + ".archive.err")
                                return 2
                        except:
                                print timeLog() + "FATAL: Could not clear " +\
                                    "out pushed story "+ filename
                                return 0

def pushFileSCPLocal(src, dst, host, user, pwd=""):
        try:
                c = "scp "

                if(not os.path.isfile(pwd)):
                    keyfile = os.path.expanduser('~') + "/.ssh/id_dsa"

                c += "-i "+keyfile+" "
                c += src+" "+user+"@"+host+":"+dst

                ret = os.system(c)
                if(not ret == 0):
                    raise Exception("scp returned "+str(ret))

                return 1
        except Exception, e:
                print timeLog() + "ERROR: Could not push file " + src + \
                        " to host " + host + " - ", e
                print timeLog() + "INFO: Failed command was "+c
                sys.stdout.flush()
                return 0

def pushFileSCP(src, dst, host, user, key=""):

        try:
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                sock.connect((host, 22))
                trans = paramiko.Transport(sock)
                trans.start_client()

                if(isinstance(key, paramiko.PKey)):
                        key = key
                elif((isinstance(key, str)) and key != ""):
                        # Password Auth
                        trans.auth_password(user, key)
                else:
                        # Key Auth
                        p = os.path.expanduser('~') + "/.ssh/id_dsa"
                        key = paramiko.DSSKey.from_private_key_file(p)
                        trans.auth_publickey(user, key)

                chan = trans.open_session()
                chan.get_pty()
                chan.setblocking(float(cfgGet("push.timeout")))
                f = file(src, 'rb')
                chan.exec_command('scp -q -t '+dst+"\n")

                # Send data
                dl = int(os.stat(src)[6])
                head = 'C' + oct(os.stat(src).st_mode)[-4:] +\
                        ' ' + str(dl) + \
                        ' ' + src.split('/')[-1] + '\n'
                data = f.read()
                chan.send(head)
                chan.sendall(data)

                dl += len(head) + 3 + data.count('\n')
                rl = 0

                # Seek to the end of stdin
                while(rl < dl):
                    msg = chan.recv(1)
                    rl += len(msg)

                # Check for success code
                if(msg[-1] == '\x00'):
                    print timeLog() + "WARN: No success response on " + src +\
                        " to host " + host
                    sys.stdout.flush()
                    #raise Exception("Invalid response (non NULL over scp)")

                f.close()
                chan.close();
                trans.close();
                sock.close();
                return 1
        except Exception, e:
                print timeLog() + "ERROR: Could not push file " + src + \
                        " to host " + host + " - ", e
                sys.stdout.flush()
                return 0

# Pushes a single file to specified host
def pushFileSFTP(src, dst, host, user, pswd):
        try:
                ssh = paramiko.SSHClient()
                ssh.load_system_host_keys()
                ssh.connect(host, username=user, password=pswd)
                ftp = ssh.open_sftp()
                ftp.put(src, dst+src.split('/')[-1])
                ftp.close()
                ssh.close()
                return 1
        except Exception, e:
                print timeLog() + "ERROR: Could not push file " + src + \
                        " to host " + host + " - ", e
                sys.stdout.flush()
                #if ftp != None:
                #        ftp.close()
                #if ssh != None:
                #        ssh.close()
                return 0

def parseHosts(hostCfgFile):
        hosts = list()
        d = open(hostCfgFile, 'r').readlines()
        for l in d:
                if (l.strip() != '' and l.strip()[0] != '#'):
                        ld = l.split("\t")
                        ld = [x.strip() for x in ld]
                        hosts.append(ld)

        return hosts

# Shortcut function for grabbing properties. Makes code cleaner to read.
def cfgGet(prop):
        return cfg.get("pushaqfiles.py", prop)

def timeLog():
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S") + ": "

# Main
# arg 1 - configuration file
def main(argv):
        if(len(argv) < 2):
                print "Usage: pushaqfiles.py <config file>"
                sys.exit(1)

        # Parse cfg files
        global cfg
        cfg = ConfigParser.ConfigParser()
        cfg.read(argv[1])

        trans_home = cfgGet('translit.home')

        paramiko.util.log_to_file(trans_home+'/paramiko_debug.log')

        hosts = parseHosts(trans_home+cfgGet('hosts.file'))

        # Grab and cleanup directories
        xml_dir = cfgGet('xml.dir')
        arc_dir = cfgGet('archive.dir')
        zho_dir = cfgGet('zho.archive.dir');
        use_pass = (cfgGet('push.usepass').lower().strip() in
                    ['true', '1', 't', 'y', 'yes'])
        push_method = cfgGet('push.method').lower().strip();

        print timeLog() + "pushaqfiles - " \
            + "V: $Id: pushaqfiles.py 2693 2011-09-27 15:09:19Z jcerda $"
        print timeLog()+"DATA:    "+xml_dir
        print timeLog()+"ARCHIVE: "+arc_dir
        sys.stdout.flush()

        if (push_method != "scp" and push_method != "sftp" and
        push_method != "scplocal"):
                print timeLog() + "WARN: Invalid push method in config. " +\
                    "Defaulting to SCP."
                sys.stdout.flush()
                push_method = "scplocal"

        if (xml_dir.split('/')[-1] != ''):
                xml_dir = xml_dir+'/'
        if (arc_dir.split('/')[-1] != ''):
                arc_dir = arc_dir+'/'

        r = re.compile("^n[0-9]+_[a-z]+_[a-z0-9]+.xml$", re.IGNORECASE)

        # Main loop
        while (True):
                allfails = 0

                # Grab file list
                l = os.listdir(xml_dir)
                l.sort()
                mylen = len(l)
                if(mylen > 0):
                        if(mylen > 1500):
                                l = l[:1500]

                        # Filter out non-xml and template
                        l = [x.strip() for x in l]
                        l = filter(r.search,l)


                        # Push and move files to archive
                        # If push fails, break. Order matters.
                        for f in l:
                                check = False
                                for h in hosts:
                                        pwd = h[2]
                                        if(not use_pass):
                                                pwd = ""
                                        bcheck = False

                                        if(push_method == "scplocal"):
                                                bcheck = pushFileSCPLocal(
                                                        xml_dir+f, h[3], h[0],
                                                        h[1], pwd)
                                        elif(push_method == "scp"):
                                                bcheck = pushFileSCP(xml_dir+f,
                                                        h[3], h[0], h[1], pwd)

                                        elif(push_method == "sftp"):
                                                bcheck = pushFileSFTP(xml_dir+f,
                                                        h[3], h[0], h[1], pwd)

                                        check = (check or bcheck)
                                if(not check):
                                        allfails += 1
                                        break
                                allfails = 0

                                print timeLog() + "PUSHED "+f
                                sys.stdout.flush()

                                if(not archiveFile(xml_dir, arc_dir, f)):
                                        print  timeLog() + "FATAL: Exiting " +\
                                            "to avoid double publishing."
                                        sys.exit(2)

                                # And make sure we clear out double archives
                                try:
                                        if(os.path.exists(arc_dir+f)):
                                                if(os.path.exists(zho_dir+f)):
                                                        os.remove(zho_dir+f)
                                                elif(os.path.exists(zho_dir+f+\
                                                ".NR")):
                                                        os.remove(zho_dir+f+\
                                                        ".NR")
                                except:
                                        print timeLog() + "WARN: Could not " +\
                                            "clear out old archives for " + f

                # Sleep so we don't make our server or aquire's server cry
		        sys.stdout.flush()
                if allfails > 4:
                        time.sleep(5)
                else:
                        time.sleep(0.5)

if __name__=='__main__':
        sys.exit(main(sys.argv))
