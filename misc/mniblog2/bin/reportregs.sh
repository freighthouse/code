#!/bin/bash

PYTHON="/usr/bin/python"
GREP="/bin/grep"
SED="/bin/sed"
MYSQL="/usr/bin/mysql"
TR="/usr/bin/tr"
UUENCODE="/usr/bin/uuencode"
MAIL="/usr/bin/mail"
CAT="/bin/cat"
MKTEMP="/bin/mktemp"

if [ $# -lt 1 ]; then
	echo "USAGE: reportregs.sh [OPTIONS] <emails>"
	echo ""
	echo "Emails should be space delimited"
	echo "Options are the same as options for the mail command"
	echo ""
	exit 2
fi

DRUPAL_SETTINGS="/var/www/mninews/sites/default/settings.php"
THEURL=`${GREP} "^[$]db_url" "${DRUPAL_SETTINGS}" | ${TR} -d "'"`
THEUSER=`echo "${THEURL}" | ${SED} 's/[^:]*:\/\/\([^:]*\).*/\1/g'`
THEHOST=`echo "${THEURL}" | ${SED} 's/[^@]*@\([^/]*\).*/\1/g'`
THEDB=`echo "${THEURL}" | ${SED} 's/[^/]*\/\/[^/]*\/\([^;]*\);/\1/g'`
THEPASS=`echo "${THEURL}" | ${SED} 's/[^:]*:[^:]*:\([^@]*\)@.*/\1/g'`
THEPASS="`${PYTHON} -c 'import urllib; print urllib.unquote_plus("'"${THEPASS}"'");'`"

echo '
SELECT rpad(users.name, 15, " ") AS name, rpad(users.mail, 35, " ") AS mail,
    from_unixtime(users.created) AS created, profile_values.value AS Company 
FROM profile_values, profile_fields, users 
LEFT JOIN authmap ON users.uid = authmap.uid 
WHERE authmap.uid IS NULL 
AND users.uid > 0
AND users.created > UNIX_TIMESTAMP("2011-07-20 00:00:00") 
AND profile_values.uid = users.uid 
AND profile_values.fid = profile_fields.fid 
AND profile_fields.title in ("Company") 
ORDER BY users.created, profile_fields.fid
'| ${MYSQL} -u ${THEUSER} --password=${THEPASS} -h ${THEHOST} ${THEDB} | ${MAIL} -s'A la carte user report' $@