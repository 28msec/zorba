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

echo Cleaning up previous data...
rm -rf "$SRC/test/rbkt/Queries/w3c_testsuite" "$SRC/test/rbkt/ExpQueryResults/w3c_testsuite"
rm -rf "$SRC/test/rbkt/Queries/w3c_testsuite/InputQueries"
rm -Rf "$SRC/test/rbkt/Queries/w3c_testsuite/TestSources"

mkdir -p "$SRC/test/rbkt/Queries/w3c_testsuite/TestSources/"

uq=`mktemp /tmp/rwts.XXXXXX`
cat >$uq <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
declare option saxon:output "omit-xml-declaration=yes";
for $sch in //schema 
return string-join( concat ($sch/@uri, "=", $sch/@FileName), "
")
EOF
echo Processing URI of catalog...
$SRC/test/zorbatest/xquery -s XQTSCatalog.xml -o:$SRC/test/rbkt/Queries/w3c_testsuite/TestSources/uri.txt $uq 


mq=`mktemp /tmp/rwts.XXXXXX`
cat >$mq <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
declare option saxon:output "omit-xml-declaration=yes";
for $t in //module/@namespace
for $l in fn:distinct-values($t/../text()) 
for $m in //module[@ID = $l]
return string-join( concat ($t, "=", $m/@FileName), "
")
EOF
echo Processing URI of catalog...
$SRC/test/zorbatest/xquery -s XQTSCatalog.xml -o:$SRC/test/rbkt/Queries/w3c_testsuite/TestSources/module.txt $mq 

mq=`mktemp /tmp/rwts.XXXXXX`
cat >$mq <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
declare option saxon:output "omit-xml-declaration=yes";
for $t in //collection
return concat ($t/@ID, "=", string-join( for $x in $t/input-document return fn:concat( "$RBKT_SRC_DIR/Queries/w3c_testsuite/TestSources/", $x, ".xml"), ";" ), "
")
EOF
echo Processing URI of catalog...
$SRC/test/zorbatest/xquery -s XQTSCatalog.xml -o:$SRC/test/rbkt/Queries/w3c_testsuite/TestSources/collection.txt $mq 


q=`mktemp /tmp/rwts.XXXXXX`
cat >$q <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
declare option saxon:output "omit-xml-declaration=yes";
string-join ((
for $sch in //schema return concat ("%uri ", $sch/@uri, " ", $sch/@FileName), 
for $src in //source return concat ("%src ", $src/@ID, " ", $src/@FileName),
for $tc in //test-case
let $out := $tc/output-file[1]/text()
let $cmp := $tc/output-file[1]/@compare
let $ctx := $tc/contextItem
let $dc  := $tc/defaultCollection
(: assuming only one input-query and x is variable name :)
let $inq := $tc/input-query/@name
return string-join ((
$tc/@name, $tc/@FilePath, $tc/query/@name,
if ($tc/input-file) then string-join (for $i in $tc/input-file return concat (data ($i/@variable), "=", $i/text ()), ";") else "noinlist",
if ($tc/input-URI) then 
    string-join (
      for $i in $tc/input-URI 
      let $fulluri := /test-suite/sources/source[@ID = $i/text()]
      return 
        if ($fulluri) then
          concat (data ($i/@variable), "=$RBKT_SRC_DIR/Queries/w3c_testsuite/", data($fulluri/@FileName))
        else
          concat (data ($i/@variable), "=", $i/text ()), ";")
else "nourilist",
if ($inq) then $inq else "noquery",
if ($cmp) then $cmp else "nocomparison",
if ($ctx) then $ctx else "nocontext",
if ($dc) then $dc else "nodefaultcollection",
if ($out) then $out else "",
string-join ($tc/expected-error/text(), ";")
), " ")),
"
")
EOF

echo Processing catalog...
$SRC/test/zorbatest/xquery -s XQTSCatalog.xml $q | tee /tmp/xq-res.txt | perl -e '
use strict;
use File::Copy;

my $repo=shift;
my %sources;
my $test_src_path = "$repo/test/rbkt/Queries/w3c_testsuite";
my $test_uris = "$test_src_path/TestSources/uri.txt\n";
open (URIS, ">> $test_uris" );
while (<>) {
chomp;
if (m/^%uri /) {
  my ( $info, $uri, $file) = split (/ /);
  print URIS " $uri=$file\n";
  next;
}
if (m/^%src /) {
  my ($info, $id, $path) = split (/ /);
  $sources {$id} = $path;
  next;
}

my ($name, $path, $query, $inlist, $urilist, $inpq, $cmp, $ctx, $dc, $out, $errlist) = split (/ /);
my @inbnd = split (/;/, $inlist);
my @uribnd = split (/;/, $urilist);
my @errs = split (/;/, $errlist);
my $inpath = "Queries/XQuery/$path";
my $inxqueryxpath = "Queries/XQueryX/$path";
my $dstqpath="$repo/test/rbkt/Queries/w3c_testsuite/XQuery/$path";
my $dstxqueryxqpath="$repo/test/rbkt/Queries/w3c_testsuite/XQueryX/$path";
my $inpqpath="$repo/test/rbkt/Queries/w3c_testsuite/InputQueries";
my $dstrespath = "$repo/test/rbkt/ExpQueryResults/w3c_testsuite/$path";
my $fullout = "$dstrespath/$name.xml.res";
my $specfile = "$dstqpath/$name.spec";
my $xqueryxspecfile = "$dstxqueryxqpath/$name.spec";
`mkdir -p $dstqpath`; `mkdir -p $dstxqueryxqpath`; `mkdir -p $dstrespath`; `mkdir -p $inpqpath`;
 
copy ("$inpath/$query.xq", "$dstqpath/$name.xq");
copy ("$inxqueryxpath/$query.xqx", "$dstxqueryxqpath/$name.xqx");
if ($out) {
  copy ("ExpectedTestResults/$path/$out", $fullout);
}

if ( $inlist ne "noinlist" || $urilist ne "nourilist" || $ctx ne "nocontext" ) {
  open (SPEC, ">>$specfile");
  open (SPECX, ">>$xqueryxspecfile");

  print SPEC "Args:";
  print SPECX "Args:";

  if ( $inlist ne "noinlist" ) {
    foreach (@inbnd) {
      my ($var, $srcid) = split /=/;
      print SPEC " -x $var=$test_src_path/" . $sources {$srcid};
      print SPECX " -x $var=$test_src_path/" . $sources {$srcid};
    }
  }

  if ( $urilist ne "nourilist" ) {
    foreach (@uribnd) {
      my ($var, $srcid) = split /=/;
      print SPEC " -x $var:=" . $srcid;
      print SPECX " -x $var:=" . $srcid;
    }
  }

  if ( $ctx ne "nocontext" ) {
    print SPEC " -x .=$test_src_path/" . $sources {$ctx};
    print SPECX " -x .=$test_src_path/" . $sources {$ctx};
  }
  print SPEC "\n";
  print SPECX "\n";
  close (SPEC);
  close (SPECX);
}

if ( $cmp ne "nocomparison" ) {
   open (SPEC, ">>$specfile");
   open (SPECX, ">>$xqueryxspecfile");
   print SPEC "Comparison: " . $cmp . "\n";
   print SPECX "Comparison: " . $cmp . "\n";
}

if ( $inpq ne "noquery" ) {
   open (SPEC, ">>$specfile");
   open (SPECX, ">>$xqueryxspecfile");
   print SPEC "InputQuery: " . $inpqpath . "/" . $inpq . ".ixq" . "\n";
   print SPECX "InputQuery: " . $inpqpath . "/" . $inpq . ".ixq" . "\n";
   copy ( "$inpath/$inpq.xq", "$inpqpath/$inpq.ixq" );
   copy ( "$inxqueryxpath/$inpq.xq", "$inpqpath/$inpq.ixqx" );
}

if ( $dc ne "nodefaultcollection" ) {
   open (SPEC, ">>$specfile");
   open (SPECX, ">>$xqueryxspecfile");
   print SPEC "DefaultCollection: " . $dc . "\n";
   print SPECX "DefaultCollection: " . $dc . "\n";
}

if (@errs) {
  open (SPEC, ">>$specfile");
  open (SPECX, ">>$xqueryxspecfile");
  foreach (@errs) {
    print SPEC "Error:$_\n";
    print SPECX "Error:$_\n";
  }
  close (SPEC);
  close (SPECX);
}

}
close (URIS);' $SRC
rm -f $q

echo "Importing test sources..."
mv XQTSCatalog.xml $SRC/test/rbkt/Queries/w3c_testsuite/
#mv TestSources/* $SRC/test/rbkt/Queries/w3c_testsuite/TestSources/
# Need the modules which have .xq suffix; rename them to .xqi files because we do not want to test them (ctest would find those also)
find "TestSources" -name '*.xq' -exec mv "{}" "$SRC/test/rbkt/Queries/w3c_testsuite/{}i" \;
find "TestSources" -type f -exec mv "{}" "$SRC/test/rbkt/Queries/w3c_testsuite/{}" \;

echo "Cleaning up work directory...$d0 $d"

cd $d0; rm -rf "$d"

echo Done.
