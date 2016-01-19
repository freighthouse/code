#!/bin/bash

# @author Jeremy Cerda
# @version $Id: makelinks.sh 2337 2011-07-08 15:25:32Z jcerda $

SCRIPT_NAME=`basename $0`
DIRNAME=$(cd `dirname $0` && pwd)
PROG_HOME=${DIRNAME/\/bin/}
source ${PROG_HOME}/conf/runconfig.sh
USER=`id|cut -d"(" -f2|cut -d")" -f1`

if [ ${USER} != ${PROCESSUSER} ] && [ ${USER} != "root" ]; then
	echo "ERROR: Must be run as root or ${PROCESSUSER}"
	exit 2
fi

if [ $# -lt 1 ]; then
	echo "Usage: makelinks <site root>"
	exit
fi

if [ ! -d $1 ]; then
	echo "Invalid directory"
	exit
fi

cd $BLOGDIR

rm includes 2> /dev/null
rm modules 2> /dev/null
rm themes 2> /dev/null
rm sites 2> /dev/null
rm CAS 2> /dev/null

ln -s $1/includes includes
ln -s $1/modules modules
ln -s $1/themes themes
ln -s $1/sites sites
ln -s $1/CAS CAS
