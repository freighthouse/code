#!/bin/bash 

AWK=/usr/bin/awk
ATRADER_AWK="atrader.awk"

ATRADER_CFG="atrader.cfg"
ATRADER_JS="js/atrader.js"

${AWK} -f ${ATRADER_AWK} ${ATRADER_CFG} > ${ATRADER_JS}
