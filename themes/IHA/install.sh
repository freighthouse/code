#!/bin/bash

SCRIPT_NAME=`basename $0`
DIRNAME=$(cd `dirname $0` && pwd)
PROG_HOME=${DIRNAME/}
source ${PROG_HOME}/.runconfig.sh

cd ${SITEROOT}

# Clone project files
#git clone https://slsapp.com/git/project6/svcf-charity.git

#Move to project directory
#cd svcf-charity

# Checkout jcerda branch
#git checkout jcerda

# Install Bower Components
bower install

# Install Mods
npm install

# Start server and open app in brower
#grunt serve