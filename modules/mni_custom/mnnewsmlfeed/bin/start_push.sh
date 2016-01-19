#!/bin/bash

# @author Jeremy Cerda
# @version $Id: start_push.sh 2649 2011-09-20 21:18:02Z jcerda $

SCRIPT_NAME=`basename $0`
DIRNAME=$(cd `dirname $0` && pwd)
PROG_HOME=${DIRNAME/\/bin/}
source $PROG_HOME/conf/runconfig.sh
USER=`id|cut -d"(" -f2|cut -d")" -f1`

if [ ${USER} != ${PROCESSUSER} ] && [ ${USER} != "root" ]; then
	echo "ERROR: Must be run as root or ${PROCESSUSER}"
	exit 2
fi

CMD="/usr/bin/python ${MOD_HOME}/pushfiles.py ${MOD_HOME}/conf/pushConfig.cfg >> ${MOD_HOME}/pushlog.log 2>&1 &"

case "${USER}" in
${PROCESSUSER})
	${CMD} &
	;;
root)
	/bin/su -c "${CMD}" ${PROCESSUSER}
	;;
*)
	echo "ERROR: Must be run as root or ${PROCESSUSER}"
	exit 2
esac
