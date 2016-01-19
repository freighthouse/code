
# @author: Jeremy Cerda
# @version: $Id: MNIPush.py 2710 2011-09-29 18:02:35Z jcerda $

import sys
import os
import socket
import paramiko
from MNIUtil import MNIUtil

class MNIPush:

    def pushFile(self, src, dst, host, user, key=""):
        return 0

class MNIPushSFTP(MNIPush):

    def pushFile(self, src, dst, host, user, key=""):
        finalDst = src.split('/')[-1]
        if[dst != ""]:
            finalDst = dst+"/"+finalDst

        try:
            ssh = paramiko.SSHClient()
            ssh.load_system_host_keys()
            ssh.connect(host, username=user, password=key)
            ftp = ssh.open_sftp()
            ftp.put(src, finalDst)
            ftp.close()
            ssh.close()
            return 1
        except Exception, e:
            print MNIUtil.timeLog()+"ERROR: Could not push file " + src + \
                " to host " +host + " - ", e
            #if ftp != None:
            #        ftp.close()
            #if ssh != None:
            #        ssh.close()
            return 0

class MNIPushSCPLocal(MNIPush):

    def pushFile(self, src, dst, host, user, key=""):
        finalDst = src.split('/')[-1]
        if[dst != ""]:
            finalDst = dst+"/"+finalDst

        try:
            c = "scp "

            if(not os.path.isfile(key)):
                keyfile = os.path.expanduser('~') + "/.ssh/id_dsa"

            c += "-i "+keyfile+" "
            c += src+" "+user+"@"+host+":"+finalDst

            ret = os.system(c)
            if(not ret == 0):
                raise Exception("scp returned "+str(ret))

            return 1
        except Exception, e:
            print MNIUtil.timeLog() + "ERROR: Could not push file " + src + \
                " to host " + host + " - ", e
            print MNIUtil.timeLog() + "INFO: Failed command was " + c
            sys.stdout.flush()
            return 0

class MNIPushSCP(MNIPush):

    def pushFile(self, src, dst, host, user, key=""):
        finalDst = src.split('/')[-1]
        if[dst != ""]:
            finalDst = dst+"/"+finalDst

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
                chan.setblocking(120)
                f = file(src, 'rb')
                chan.exec_command('scp -q -t '+finalDst)

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
                    print MNIUtil.timeLog() + "WARN: No success response on "+\
                        src + " to host " + host
                    #raise Exception("Invalid response (non NULL over scp)")

                f.close()
                chan.close();
                trans.close();
                sock.close();
                return 1
        except Exception, e:
                print MNIUtil.timeLog() + "ERROR: Could not push file " + \
                    src + " to host " + host + " - ", e
                return 0
