#!/bin/bash

###
#  Script for updating project.tgz for Coverity scan
###


echo "Must have cov-build installed."
echo "   See: http://scan.coverity.com/self-build/"

PATH=$PATH:~/dev/coverity/prevent-linux-2.4.6/bin

cov-configure -co /usr/bin/cc
#cov-configure -co /usr/bin/g++
cov-configure -co /usr/bin/c++

# cd to build dir
pushd .
cd ../../build

# Optional Run any build steps that you don't want to analyze i.e. ./configure
rm -R README emit output
make clean


cov-build -e emit -o output make -j4

# Create a README file with your name, email, and project's name
cat "Cezar Andrei, cezar.andrei@gmail.com, Zorba" > README

tar czvf project.tgz README emit output

# Upload the project.tgz to your server
mv project.tgz ../test/coverity

#rm -R README emit output
popd