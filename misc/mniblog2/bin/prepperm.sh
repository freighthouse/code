#!/bin/bash

# @author Jeremy Cerda
# @version $Id: prepperm.sh 2644 2011-09-20 16:15:38Z jcerda $

# The script will reset permissions for all mniblog files

SCRIPT_NAME=`basename $0`
DIRNAME=$(cd `dirname $0` && pwd)
PROG_HOME=${DIRNAME/\/bin/}
source ${PROG_HOME}/conf/runconfig.sh
USER=`id|cut -d"(" -f2|cut -d")" -f1`

MKDIR="/usr/bin/env mkdir"
CHGRP="/usr/bin/env chgrp"
CHOWN="/usr/bin/env chown"
CHMOD="/usr/bin/env chmod"
TOUCH="/usr/bin/env touch"
FIND="/usr/bin/env find"
GREP="/usr/bin/env grep"
XARGS="/usr/bin/env xargs"

if [ ! "$UID" -eq "0" ]; then
        printf "You must be root to execute this script.\n"
        exit
fi

if [ $# -lt 1 ]; then
	echo "Usage: prepperm <site root>"
	exit
fi

if [ ! -d $1 ] && [ "$1" != "/dev/null" ]; then
	echo "Invalid directory"
	exit
fi

#${FIND} ${BLOGDIR}/ -not \( -path '*archive*' \) -print0 | ${XARGS} -0 ${CHOWN} -R ${PROCESSUSER}
#${FIND} ${BLOGDIR}/ -not \( -path '*archive*' \) -print0 | ${XARGS} -0 ${CHGRP} -R ${PROCESSUSER}
${CHOWN} -R ${PROCESSUSER} ${BLOGDIR}
${CHGRP} -R ${PROCESSUSER} ${BLOGDIR}
${FIND} ${BLOGDIR}/ -type d -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 2755
${FIND} ${BLOGDIR}/ -type f -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 644

#${FIND} ${1}/sites/default/files -type d -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 2775
#${FIND} ${1}/sites/default/files -type f -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 664

# Handles directories for imarketnews
if [ -n "${IMG_DIR}" ] && [ -d ${IMG_DIR} ] ; then
	${FIND} ${IMG_DIR}/ -type d -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 2775
	${FIND} ${IMG_DIR}/ -type f -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 664
	${CHMOD} g+w ${1}
	${CHMOD} g+w ${1}/sitemap-news.xml 2> /dev/null
fi

BINS=`$FIND ${BLOGDIR} -type d -name "bin"`
for i in ${BINS}; do
	${FIND} ${i}/ -type f -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 774
done

# Custom perms
if [ -d ${1}/sites/default/files/mni_pdfs ]; then
	${MKDIR} ${1}/sites/default/files/mni_pdfs &> /dev/null
	${CHOWN} -R www-data ${1}/sites/default/files/mni_pdfs
	${CHGRP} -R www-data ${1}/sites/default/files/mni_pdfs
	${FIND} ${1}/sites/default/files/mni_pdfs/ -type d -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 2775
	${FIND} ${1}/sites/default/files/mni_pdfs/ -type f -not \( -path '*/.svn*' \) -print0 | ${XARGS} -0 ${CHMOD} 664 2> /dev/null
fi
