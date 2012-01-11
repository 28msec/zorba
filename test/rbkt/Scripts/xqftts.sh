#!/bin/bash

# This shell script checks out a fresh XQFTTS from W3C and creates a new XQFTTS_current.zip
# W3C provides an ANT script for all their tesuites (XQTS, XQUTS, XQFTTS)

xqfttsDir=XQFTTS/2007/xpath-full-text-10-test-suite

export CVSROOT=":pserver:anonymous@dev.w3.org:/sources/public"
cvs login

#echo: checking out the Full test test suite (XQFTTS)
#cd $xqfttsDir/../
#cvs get2007/xpath-full-text-10-test-suite xpath-full-text-10-test-suite

echo get updates (the password is anonymous)
cd $xqfttsDir
cvs update

echo create new XQFTTS_development.zip archive
echo NOTE: Ant (the build generator for Java) is a requirement for this
cd $xqfttsDir/Tools/ZipXQTS
ant -buildfile Build.xml

echo copy the new XQFTTS_development.zip archive to /tmp/XQFTTS_current.zip
echo Note: the name of the .ZIP in /tmp folder has to match the name in the import_w3c_full_text_testsuite.sh
echo       for the ZIP variable at line 58
cp $xqfttsDir/PublicPagesStagingArea/XQFTTS_development.zip /tmp/XQFTTS_current.zip

echo now, if you comment the lines that download the .ZIP from W3C (lines 59 and 60) 
echo and run the import_w3c_full_text_testsuite.sh you are all set !