#!/bin/bash

# @author Jeremy Cerda
# @version $Id: start_push.sh 2689 2011-09-27 13:00:02Z jcerda $

DRUPAL_HOME=/var/www/mni6
PROCESSUSER=aqrpush
MOD_HOME=${DRUPAL_HOME}/sites/all/modules/mnizhotranslit

if [ ${USER} != ${PROCESSUSER} ] && [ ${USER} != "root" ]; then
	echo "ERROR: Must be run as root or ${PROCESSUSER}"
	exit 2
fi

CMD="/usr/bin/python ${MOD_HOME}/pushaqfiles.py ${MOD_HOME}/pushConfig.cfg >> ${MOD_HOME}/pushlog.log 2>&1 &"

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
