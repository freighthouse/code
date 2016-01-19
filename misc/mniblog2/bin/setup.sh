#!/bin/bash

# @author Jeremy Cerda
# @version $Id: setup.sh 2647 2011-09-20 16:55:39Z jcerda $

SCRIPT_NAME=`basename $0`
DIRNAME=$(cd `dirname $0` && pwd)
PROG_HOME=${DIRNAME/\/bin/}
source ${PROG_HOME}/conf/runconfig.sh
USER=`id|cut -d"(" -f2|cut -d")" -f1`

if [ ${USER} != ${PROCESSUSER} ] && [ ${USER} != "root" ]; then
	echo "ERROR: Must be run as root or ${PROCESSUSER}"
	exit 2
fi

if [ $# -eq 0 ]; then
	echo "USAGE: setup.sh [OPTION] <mninews | mni6 | marketnews | imarketnews | rss | none>"
	echo ""
	echo "Options:"
	echo "    -l [en | zho | ar]"
	echo "        specify site language"
	echo "    -p"
	echo "        bypass prepperm call"
	exit 2
fi

###############################################################################
# Grab Variables
###############################################################################

PERM=1
LANG=""
while getopts ":pl:" opt; do
	case ${opt} in
		l)
			LANG="${OPTARG}"
			case ${LANG} in
				'ar' | 'zho' | 'en')
					LANG="-${LANG}"
				;;
				*)
					echo "INVALID OPTION FOR -l: ${LANG}"
					echo "Valid options include: en, zho, ar"
					exit 1
				;;
			esac
		;;
		p)
			PERM=0
		;;
		\?)
			echo "INVALID OPTION: ${OPTARG}"
			echo "Valid options include: -l"
			exit 1
		;;
	esac
done
shift $(($OPTIND - 1))

VAR_1="${1}"
if [ "${VAR_1}" == "" ]; then
	VAR_1='marketnews'
fi

VAR_2="${2}"
if [ "${VAR_2}" == "" ]; then
	VAR_2=''
fi

###############################################################################
# Configs
###############################################################################
cd ${PROG_HOME}/conf
rm multipub.cfg &> /dev/null
rm production.cfg &> /dev/null
rm pub.production.cfg &> /dev/null
rm rich.production.cfg &> /dev/null
rm scriptconfig.sh &> /dev/null
case ${VAR_1} in
'marketnews' | 'imarketnews' | 'mni6' | 'mainsite' | 'rss' | 'none')
    VAR_1_LOCAL=${VAR_1}
    if [ "${VAR_1_LOCAL}" == 'mainsite' ]; then
        VAR_1_LOCAL='marketnews'
    fi

    if [ ! -f "./sites/${VAR_1_LOCAL}/production.cfg-${VAR_1_LOCAL}${LANG}" ]; then
    	LANG=""
    fi

	ln -s ./sites/${VAR_1_LOCAL}/production.cfg-${VAR_1_LOCAL}${LANG} production.cfg
	ln -s ./sites/${VAR_1_LOCAL}/pub.production.cfg-${VAR_1_LOCAL} pub.production.cfg
	ln -s ./sites/${VAR_1_LOCAL}/rich.production.cfg-${VAR_1_LOCAL} rich.production.cfg
;;
'mninews')
	ln -s ./sites/mninews/multipub.cfg multipub.cfg
	ln -s ./sites/mninews/scriptconfig.sh-mninews scriptconfig.sh
;;
*)
	echo "INVALID SITE: ${VAR_1}"
	echo "Valid sites include: marketnews, imarketnews, mni6, and mninews"
	exit 1
esac

###############################################################################
# Executables
###############################################################################
cd ${PROG_HOME}/bin
rm startblog.sh &> /dev/null
rm stopblog.sh &> /dev/null
rm newsmap.sh &> /dev/null
case ${VAR_1} in
'mninews')
	ln -s ./sites/mninews/startblog.sh-mninews startblog.sh
	ln -s ./sites/mninews/stopblog.sh-mninews stopblog.sh
	ln -s ./sites/mninews/newsmap.sh-mninews newsmap.sh
;;
'imarketnews')
	ln -s ./sites/marketnews/startblog.sh-marketnews startblog.sh
	ln -s ./sites/marketnews/stopblog.sh-marketnews stopblog.sh
	ln -s ./sites/imarketnews/newsmap.sh-imarketnews newsmap.sh
;;
'none')
	ln -s ./sites/none/startblog.sh-none startblog.sh
	ln -s ./sites/none/stopblog.sh-none stopblog.sh
;;
'rss')
	ln -s ./sites/rss/startblog.sh-rss startblog.sh
	ln -s ./sites/rss/stopblog.sh-rss stopblog.sh
;;
*)
	ln -s ./sites/marketnews/startblog.sh-marketnews startblog.sh
	ln -s ./sites/marketnews/stopblog.sh-marketnews stopblog.sh
;;
esac

###############################################################################
# Directories
###############################################################################
if [ "${VAR_1}" == "mninews" ]; then
	mkdir ${PROG_HOME}/delivery &> /dev/null
	mkdir ${PROG_HOME}/delivery/free &> /dev/null
	mkdir ${PROG_HOME}/delivery/subscription &> /dev/null
	mkdir ${PROG_HOME}/delivery/alacarte &> /dev/null

	mkdir ${PROG_HOME}/archive &> /dev/null
	mkdir ${PROG_HOME}/archive/free &> /dev/null
	mkdir ${PROG_HOME}/archive/subscription &> /dev/null
	mkdir ${PROG_HOME}/archive/alacarte &> /dev/null

	mkdir ${PROG_HOME}/failure &> /dev/null
	mkdir ${PROG_HOME}/failure/free &> /dev/null
	mkdir ${PROG_HOME}/failure/subscription &> /dev/null
	mkdir ${PROG_HOME}/failure/alacarte &> /dev/null

	mkdir ${PROG_HOME}/rss &> /dev/null
	mkdir ${PROG_HOME}/rss/live &> /dev/null
	mkdir ${PROG_HOME}/rss/delivery &> /dev/null
	mkdir ${PROG_HOME}/rss/archive &> /dev/null

elif [ "${VAR_1}" == "rss" ]; then
	mkdir ${PROG_HOME}/rss &> /dev/null
	mkdir ${PROG_HOME}/rss/live &> /dev/null

fi
#TODO - richpdf direcotries, etc

###############################################################################
# Misc
###############################################################################
if [ "${PERM}" == "1" ] && [ ! "${VAR_2}" == "-p" ]; then
	cd ${PROG_HOME}
	case ${VAR_1} in
	'marketnews')
		./bin/makelinks.sh /var/www/marketnews.com
		./bin/prepperm.sh /var/www/marketnews.com
	;;
	'imarketnews')
		./bin/makelinks.sh /var/www/imarketnews
		./bin/prepperm.sh /var/www/imarketnews
		# UNFINISHED - newsmap, etc
	;;
	'none' | 'rss')
		./bin/prepperm.sh /dev/null
	;;
	*)
		./bin/makelinks.sh /var/www/${VAR_1}
		./bin/prepperm.sh /var/www/${VAR_1}
	;;
	esac
fi
