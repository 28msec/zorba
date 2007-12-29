#!/bin/bash

if test $# != 1 -o ! -d $1/test/zorbatest; then
 echo 'Arguments: zorba_repository'
 echo 'where zorba_repository is the top-level SVN working copy'
 exit 1
fi

SRC=$1
ZIP=/tmp/XQTS_1_0_2.zip
echo Downloading test suite to zip $ZIP ...
wget -c -O $ZIP http://www.w3.org/XML/Query/test-suite/XQTS_1_0_2.zip

d0=`pwd`

cd `dirname $SRC`
SRC=`pwd`/`basename $SRC`
echo Repository is at $SRC

d="/tmp/rwts.$$"
mkdir "$d"
cd "$d"

echo Unzipping test suite...
unzip $ZIP &>/dev/null

q=`mktemp /tmp/rwts.XXXXXX`
cat >$q <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
declare option saxon:output "omit-xml-declaration=yes";
string-join ((
for $src in //source return concat ("%src ", $src/@ID, " ", $src/@FileName),
for $tc in //test-case
let $out := $tc/output-file[1]/text()
return string-join ((
$tc/@name, $tc/@FilePath, $tc/query/@name,
string-join (for $i in $tc/input-file return concat (data ($i/@variable), "=", $i/text ()), ":"),
string-join (for $i in $tc/input-URI return concat (data ($i/@variable), "=", $i/text ()), ":"),
if ($out) then $out else "",
string-join ($tc/expected-error/text(), ":")
), " ")),
"
")
EOF

echo Cleaning up previous data...
rm -rf $SRC/test/rbkt/Queries/w3c_testsuite $SRC/test/rbkt/ExpQueryResults/w3c_testsuite $SRC/test/rbkt/TestSources

echo Processing catalog...
$SRC/test/zorbatest/xquery -s XQTSCatalog.xml $q | tee /tmp/xq-res.txt | perl -e '
use strict;
use File::Copy;

my $repo=shift;
my %sources;
while (<>) {
chomp;
if (m/^%src /) {
  my ($info, $id, $path) = split (/ /);
  $sources {$id} = $path;
  next;
}

my ($name, $path, $query, $inlist, $urilist, $out, $errlist) = split (/ /);
my @inbnd = split (/:/, $inlist);
my @uribnd = split (/:/, $urilist);
my @errs = split (/:/, $errlist);
my $test_src_path = "$repo/test/rbkt/Queries/w3c_testsuite";
my $inpath = "Queries/XQuery/$path";
my $dstqpath="$repo/test/rbkt/Queries/w3c_testsuite/$path";
my $dstrespath = "$repo/test/rbkt/ExpQueryResults/w3c_testsuite/$path";
my $fullout = "$dstrespath/$name.xml.res";
my $specfile = "$dstqpath/$name.spec";
`mkdir -p $dstqpath`; `mkdir -p $dstrespath`;

copy ("$inpath/$query.xq", "$dstqpath/$name.xq");
if ($out) {
  copy ("ExpectedTestResults/$path/$out", $fullout);
}

if (@inbnd || @uribnd) {
  open (SPEC, ">>$specfile");
  print SPEC "Args:";
  foreach (@inbnd) {
    my ($var, $srcid) = split /=/;
    print SPEC " -x $var=$test_src_path/" . $sources {$srcid};
  }
  foreach (@uribnd) {
    my ($var, $srcid) = split /=/;
    print SPEC " -x $var:=$test_src_path/" . $sources {$srcid};
  }
  print SPEC "\n";
  close (SPEC);
}

if (@errs) {
  open (SPEC, ">>$specfile");
  foreach (@errs) {
    print SPEC "Error:$_\n";
  }
  close (SPEC);
}
}
' $SRC
rm -f $q

echo "Importing test sources..."
mv XQTSCatalog.xml $SRC/test/rbkt/Queries/w3c_testsuite/
find TestSources  -name '*.xq' -exec rm {} \;
mv TestSources $SRC/test/rbkt/Queries/w3c_testsuite/

echo "Cleaning up work directory..."
cd $d0; rm -rf "$d"

echo Done.
