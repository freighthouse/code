#!/bin/bash

# Install Grunt
npm install -g grunt-cli

# Install Bower globally
npm install -g bower

# Go to your local project directory
cd /[PROJECT_DIR]

# Clone project files
git clone https://slsapp.com/git/project6/svcf-charity.git

# Checkout jcerda branch
git checkout jcerda

# Install Bower Components
bower install

# Install Mods
npm install

# Start server and open app in brower
grunt serve