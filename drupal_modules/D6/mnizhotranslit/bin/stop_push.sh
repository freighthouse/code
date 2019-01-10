#!/bin/bash

# @author Jeremy Cerda
# @version $Id: stop_push.sh 2383 2011-07-28 16:23:02Z jcerda $

DRUPAL_HOME=/var/www/mni6
PROCESSUSER=aqrpush
MOD_HOME=${DRUPAL_HOME}/sites/all/modules/mnizhotranslit

if [ ${USER} != ${PROCESSUSER} ] && [ ${USER} != "root" ]; then
	echo "ERROR: Must be run as root or ${PROCESSUSER}"
	exit 2
fi

pkill -f ${BLOGDIR}/pushaqfiles.py
