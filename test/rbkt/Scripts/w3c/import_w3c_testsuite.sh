#!/bin/bash

WORK_DEFAULT=/tmp
XQTSURL_DEFAULT=http://zorbatest.lambda.nu:8080/~spungi/XQTS_090512.zip

die() {
  echo
  echo 'Arguments: [--workdir <workdir>] [--builddir <builddir>] [--xqtsurl <xqtsurl>] <zorba_repository>'
  echo '<zorba_repository> is the top-level SVN working copy'
  echo "<workdir> is a temp directory to download and unzip XQTS (default: $WORK_DEFAULT)"
  echo '<builddir> is the directory Zorba has been built in'
  echo '           (default: <zorba_repository>/build)'
  echo '<xqtsurl> is the URL where the XQTS archived version can be found'
  echo "          (default: $XQTSURL_DEFAULT)"
  echo '          (you can use for instance http://dev.w3.org/2006/xquery-test-suite/PublicPagesStagingArea/XQTS_1_0_3.zip)'
  exit 1
}

WORK=$WORK_DEFAULT
XQTSURL=$XQTSURL_DEFAULT
while [ $# -gt 1 ]
do
  # --workdir to specify a working directory to download/unzip XQTS
  test "$1" = "--workdir" && { WORK="$2"; shift; shift; }

  # --builddir to specify Zorba build directory (default: srcdir/build)
  test "$1" = "--builddir" && { BUILD="$2"; shift; shift; }

  # xqtsurl to specify the URL where XQTS can be found
  test "$1" = "--xqtsurl" && { XQTSURL="$2"; shift; shift; }
done


SRC="$1"
echo "XXXXXXXXXX ${SRC}"
if [ -z "$BUILD" ]; then
  BUILD="$SRC/build"
fi

if test ! -d "$SRC/test/rbkt"; then
  echo "Invalid zorba repository $SRC"
  die
  exit 1
fi

if test ! -d "$BUILD"; then
  echo "Invalid build directory $BUILD"
  echo "Be sure to finish building Zorba before running this script"
  die
  exit 1
fi

zipname=`basename $XQTSURL`
ZIP="$WORK/$zipname"
echo Downloading test suite to zip $ZIP ...
wget -c -O $ZIP $XQTSURL

orig_pwd=`pwd`

# Canonicalize SRC and BUILD
SRC=$(cd "$SRC" && pwd)
echo Repository is at $SRC
BUILD=$(cd "$BUILD" && pwd)
echo Build dir is at $BUILD

echo Unzipping test suite...
unzip_dir=`mktemp -d "$WORK/$zipfile.XXXXXX"`
cd "$unzip_dir"
unzip $ZIP &>/dev/null

echo Cleaning up previous data...
rm -rf "$SRC/test/rbkt/Queries/w3c_testsuite" "$SRC/test/rbkt/ExpQueryResults/w3c_testsuite" "$SRC/test/rbkt/Scripts/w3c/w3c_reportingresults"

mkdir -p "$SRC/test/rbkt/Queries/w3c_testsuite/TestSources"
mkdir -p "$SRC/test/rbkt/Queries/w3c_testsuite/cat"

echo Importing $zipfile ...
q=`mktemp "$WORK/xq.XXXXXX"`
cat >"$q" <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
string-join (
  for $sch in //schema
  return concat ($sch/@uri, "=", $sch/@FileName), "
")
EOF
echo 'Processing URI of catalog (schemas)...'
"$BUILD/bin/zorba" --context-item XQTSCatalog.xml --omit-xml-declaration -o "$SRC/test/rbkt/Queries/w3c_testsuite/TestSources/uri.txt" --as-files --query "$q"


cat >"$q" <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
string-join (distinct-values (
  for $mod in //sources/module
  for $tmod in //test-case/module [text () = $mod/@ID]
  let $tc := $tmod/..
  return concat ($tc/@FilePath, $tc/@name, ":", $tmod/@namespace, "=", $mod/@FileName)), "
")
EOF
echo 'Processing URI of catalog (modules)...'
"$BUILD/bin/zorba" --context-item XQTSCatalog.xml --omit-xml-declaration -o "$SRC/test/rbkt/Queries/w3c_testsuite/TestSources/module.txt" --as-files --query "$q"


cat >"$q" <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
for $t in //collection
return concat ($t/@ID, "=", string-join( for $x in $t/input-document return fn:concat( "$RBKT_SRC_DIR/Queries/w3c_testsuite/TestSources/", $x, ".xml"), ";" ), "
")
EOF
echo 'Processing URI of catalog (collections)...'
"$BUILD/bin/zorba" --context-item XQTSCatalog.xml --omit-xml-declaration -o "$SRC/test/rbkt/Queries/w3c_testsuite/TestSources/collection.txt" --as-files --query "$q"


cat >"$q" <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-XQTSCatalog";
string-join ((
for $sch in //schema return concat ("%uri ", $sch/@uri, " ", $sch/@FileName), 
for $src in //source return concat ("%src ", $src/@ID, " ", $src/@FileName),
for $tc in //test-case
let $out := $tc//output-file
let $cmp := $tc/output-file[1]/@compare (: assuming that all output-files have to be compared using the same comparison method :)
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
if ($out) then string-join($out/text(), ";") else "",
string-join ($tc/expected-error/text(), ";")
), " ")),
"
")
EOF

echo 'Processing catalog...'
"$BUILD/bin/zorba" --context-item XQTSCatalog.xml --omit-xml-declaration --as-files --query "$q" | tee "$WORK/xq-res.txt" | perl -e '
use strict;
use File::Copy;

my $repo=shift;
my %sources;
my $test_src_path = "\$RBKT_SRC_DIR/Queries/w3c_testsuite";
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
my @outfiles = split (/;/, $out);
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

sub change_doc {
  my ($filename, $varname) = @_;
  open (FILE, $filename);
  open (OUT, ">$filename.new");
  while (<FILE>) {
    s/declare variable \$$varname external/declare variable \$$varname as document-node() external/;
    print OUT;
  }
  close FILE;
  close OUT;
  move ("$filename.new", $filename);
}

copy ("$inpath/$query.xq", "$dstqpath/$name.xq");
copy ("$inxqueryxpath/$query.xqx", "$dstxqueryxqpath/$name.xqx");

if (@outfiles) {

  if (@outfiles >= 1) {
    open (SPEC, ">>$specfile");
    open (SPECX, ">>$xqueryxspecfile");
    print SPEC "Result: ";
    print SPECX "Result: ";
  }

  foreach (@outfiles) {
    my $txtfile = "$_";
    $txtfile =~ 's/[.]txt$/.xml.res/';
    if (@outfiles == 1) {
      $txtfile =~ 's/[.]xml$/.xml.res/';
    } else {
      # avoid possible conflict with alternate .txt result
      $txtfile =~ 's/[.]xml$/-X.xml.res/';
    }
    copy ("ExpectedTestResults/$path/$_", "$dstrespath/$txtfile");
    if (@outfiles >= 1) {
      print SPEC " \$RBKT_SRC_DIR/ExpQueryResults/w3c_testsuite/$path/$txtfile";
      print SPECX "\$RBKT_SRC_DIR/ExpQueryResults/w3c_testsuite/$path/$txtfile";
    }
  }

  if (@outfiles >= 1) {
    print SPEC "\n";
    print SPECX "\n";
    close (SPEC);
    close (SPECX);
  }
}

if ( $inlist ne "noinlist" || $urilist ne "nourilist" || $ctx ne "nocontext" ) {
  open (SPEC, ">>$specfile");
  open (SPECX, ">>$xqueryxspecfile");

  print SPEC "Args:\n";
  print SPECX "Args:\n";

  # enable Dtd loader for tests using Dtd
  if ( $name=~/^fn-id-dtd-/ ||
       $name=~/^fn-idref-dtd-/ ||
       $name=~/^functx-functx-id-from-element-1/
     )
  {
    print SPEC  "--enable-dtd \n";
    print SPECX "--enable-dtd \n";
  }

  if ( $inlist ne "noinlist" ) {
    foreach (@inbnd) {
      my ($var, $srcid) = split /=/;
      print SPEC "-x \n$var=$test_src_path/" . $sources {$srcid} . "\n";
      print SPECX "-x \n$var=$test_src_path/" . $sources {$srcid} . "\n";
      # Rather ugly query post-processing; see bug 2788838
      if (grep $_ eq "XPST0005", @errs) {
        change_doc("$dstqpath/$name.xq", $var);
      }
    }
  }

  if ( $urilist ne "nourilist" ) {
    foreach (@uribnd) {
      my ($var, $srcid) = split /=/;
      print SPEC "-x \n$var:=" . $srcid ."\n";
      print SPECX "-x \n$var:=" . $srcid ."\n";
    }
  }

  if ( $ctx ne "nocontext" ) {
    print SPEC "-x \n.=$test_src_path/" . $sources {$ctx} ."\n";
    print SPECX "-x \n.=$test_src_path/" . $sources {$ctx} ."\n";
  }
  #print SPEC "\n";
  #print SPECX "\n";
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
   print SPEC "InputQuery: \$RBKT_SRC_DIR/Queries/w3c_testsuite/InputQueries/" . $inpq . ".ixq" . "\n";
   print SPECX "InputQuery: \$RBKT_SRC_DIR/Queries/w3c_testsuite/InputQueries/" . $inpq . ".ixq" . "\n";
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
    my ($qname) = /^\*$/ ? "*" : "http://www.w3.org/2005/xqt-errors:$_\n";
    print SPEC "Error: $qname\n";
    print SPECX "Error: $qname\n";
  }
  close (SPEC);
  close (SPECX);
}

}
close (URIS);' "$SRC"
rm -f "$q"

echo "Importing test sources..."
mv XQTSCatalog.xml "$SRC/test/rbkt/Queries/w3c_testsuite/"
# Need the modules which have .xq suffix; rename them to .xqi files because we do not want to test them (ctest would find those also)
find "TestSources" -name '*.xq' -exec mv "{}" "$SRC/test/rbkt/Queries/w3c_testsuite/{}i" \;
find "TestSources" -type f -exec mv "{}" "$SRC/test/rbkt/Queries/w3c_testsuite/{}" \;
mv "XQTSCatalog.xsd" "$SRC/test/rbkt/Queries/w3c_testsuite/"
mv "ReportingResults" "$SRC/test/rbkt/Scripts/w3c/w3c_reportingresults"
find "cat" -type f -exec mv "{}" "$SRC/test/rbkt/Queries/w3c_testsuite/{}" \; 

echo "Cleaning up work directory...$orig_pwd $unzip_dir"

cd "$orig_pwd"
rm -rf "$unzip_dir"
rm -rf "$WORK/xq-res.txt"

echo Done.

echo "Now re-run cmake in your build directory to add W3C tests to CTest."
