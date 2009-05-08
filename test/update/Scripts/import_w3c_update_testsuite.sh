#!/bin/bash

# HOWTO 
# export update testsuite (http://dev.w3.org/2007/xquery-update-10-test-suite/)
#   export CVSROOT=":pserver:anonymous@dev.w3.org:/sources/public"
#   cvs login
#   (Logging in to anonymous@dev.w3.org)
#   CVS password: anonymous
#   cvs export -DNOW 2007/xquery-update-10-test-suite/
# move xquery-update-10-test-suite/ExpectedTestResults/* to xquery-update-10-test-suite/ExpectedTestResults/XQuery 
#   (not necessary as soon as the testdriver is adapted)
# mv xquery-update-10-test-suite/TestSources xquery-update-10-test-suite/Queries
# delete all spec files if already generated once (optional)
#   find . -name "*.spec" -exec rm {} \;
# ./import_w3c_update_testsuite.sh <testsuite-dir (xquery-update-10-test-suite)> <path to saxon*.jar (e.g. saxon9.jar)>
# ln -s xquery-update-10-test-suite/Queries/ zorba/test/update/Queries/xquery_update_testsuite
# ln -s xquery-update-10-test-suite/ExpectedTestResults/ zorba/test/update/ExpectedTestResults/w3c_update_testsuite
# commit xquery-update-10-test-suite/Queries/ and xquery-update-10-test-suite/ExpectedTestResults/ to https://fifthelement.inf.ethz.ch/zorba-repos/xqueryw3ctests/w3c_update_testsuite/ 

if test $# != 2 -o ! -d $1/Queries/XQuery/UpdatePrimitives/AttributeErrors
then
 echo 'Arguments: xquery_update_testsuite saxon.jar'
 echo 'where zorba_repository is the top-level SVN working copy'
 exit 1
fi

SUITE_SRC=$1
SAXON_PATH=$2

d0=`pwd`

uq=`mktemp /tmp/rwts.XXXXXX`
cat >$uq <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-update";
declare option saxon:output "omit-xml-declaration=yes";
for $sch in //schema 
return string-join( concat ($sch/@uri, "=", $sch/@FileName), "
")
EOF
echo Processing URI of catalog...
java -cp $SAXON_PATH net.sf.saxon.Query \
-s $SUITE_SRC/XQUTSCatalog.xml \
-o:$SUITE_SRC/Queries/TestSources/uri.txt \
$uq

# XQUTSCatalog does not contain module tags
#mq=`mktemp /tmp/rwts.XXXXXX`
#cat >$mq <<"EOF"
#declare default element namespace "http://www.w3.org/2005/02/query-test-update";
#declare option saxon:output "omit-xml-declaration=yes";
#for $t in //module/@namespace
#for $l in fn:distinct-values($t/../text()) 
#for $m in //module[@ID = $l]
#return string-join( concat ($t, "=", $m/@FileName), "
#")
#EOF
#echo Processing URI of catalog...
#$SRC/test/zorbatest/xquery -s XQTSCatalog.xml -o:$SRC/test/rbkt/Queries/module.txt $mq 


q=`mktemp /tmp/rwts.XXXXXX`
cat >$q <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-update";
declare option saxon:output "omit-xml-declaration=yes";
string-join ((
for $sch in //schema return concat ("%uri ", $sch/@uri, " ", $sch/@FileName), 
for $src in //source return concat ("%src ", $src/@ID, " ", $src/@FileName),
for $tc in //test-case
return 
(
concat("case=",$tc/@FilePath,$tc/@name),
for $state in $tc/state
return (
concat("State: ",$state/query/@name),
concat("Args:", string-join(for $infile in $state/input-file return concat(" -x ", $infile/@variable,"=$UPDATE_SRC_DIR/Queries/w3c_update_testsuite/TestSources/",$infile/text(),".xml") ,"")  ,if ($state/query/@date) then concat(" -d ",$state/query/@date) else ()),
for $outfile in $state/output-file
return concat("Compare: ", $outfile/text(), " ", $outfile/@compare),
for $error in $state/expected-error
return concat("Error: ", $error/text())
),
"end"
)
),
"
")
EOF

echo Processing catalog...
java -cp $SAXON_PATH net.sf.saxon.Query \
-s $SUITE_SRC/XQUTSCatalog.xml \
$q | tee /tmp/xq-res.txt | perl -e '
use strict;
use File::Copy;

my $suite=shift;

while (<>) {
chomp;
if (m/^%uri /) {
}
elsif (m/^%src /) {
}
elsif (m/^case=/) {
  my ($var, $name) = split /=/;
  my $path = $suite . "Queries/XQuery/" . "$name.spec";
  open (SPEC, ">>$path");
  print "START $path\n";
}
elsif (m/^end/) {
  close (SPEC);
  print "END\n";
}
else {
  print SPEC "$_\n"; 
  print "$_\n";
}
}
' $SUITE_SRC

echo Done.
