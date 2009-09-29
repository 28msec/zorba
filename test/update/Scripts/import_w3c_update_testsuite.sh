#!/bin/bash

die() {
  echo
  echo 'Arguments: [--workdir <workdir>] [--builddir <builddir>] <zorba_repository>'
  echo '<zorba_repository> is the top-level SVN working copy'
  echo '<workdir> is a temp directory to download and unzip XQUTS (default: /tmp)'
  echo '<builddir> is the directory Zorba has been built in'
  echo '           (default: <zorba_repository>/build)'
  exit 1
}

WORK=/tmp
while [ $# -gt 1 ]
do
  # --workdir to specify a working directory to download/unzip XQUTS
  test "$1" = "--workdir" && { WORK="$2"; shift; shift; }

  # --builddir to specify Zorba build directory (default: srcdir/build)
  test "$1" = "--builddir" && { BUILD="$2"; shift; shift; }
done

SRC="$1"
if [ -z "$BUILD" ]; then
  BUILD="$SRC/build"
fi

if test ! -d "$SRC/test/update"; then
  echo "Invalid zorba repository $SRC"
  die
fi

if test ! -d "$BUILD"; then
  echo "Invalid build directory $BUILD"
  echo "Be sure to finish building Zorba before running this script"
  die
  exit 1
fi

ZIP=/tmp/XQUTS.zip
echo Downloading test suite to zip $ZIP ...
wget -c -O $ZIP http://dev.w3.org/2007/xquery-update-10-test-suite/Archive/XQUTS_1_0_0.zip

orig_pwd=`pwd`

# Canonicalize SRC and BUILD
SRC=$(cd "$SRC" && pwd)
echo Repository is at $SRC
BUILD=$(cd "$BUILD" && pwd)
echo Build dir is at $BUILD

echo Unzipping test suite...
unzip_dir=`mktemp -d "$WORK/xquts.XXXXXX"`
cd "$unzip_dir"
unzip $ZIP &>/dev/null

echo Cleaning up previous data...
rm -rf "$SRC/test/update/Queries/w3c_update_testsuite" "$SRC/test/update/ExpectedTestResults/w3c_update_testsuite"

echo Importing XQUTS...
mv Queries "$SRC/test/update/Queries/w3c_update_testsuite"
mv ExpectedTestResults "$SRC/test/update/ExpectedTestResults/w3c_update_testsuite"
mv TestSources "$SRC/test/update/Queries/w3c_update_testsuite"


q=`mktemp "$WORK/xq.XXXXXX"`
cat >"$q" <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-update";
string-join (
  for $sch in //schema 
  return concat ($sch/@uri, "=", $sch/@FileName), "
")
EOF
echo 'Processing URI of catalog (schemas)...'
"$BUILD/bin/zorba" --context-item XQUTSCatalog.xml --omit-xml-declaration -o "$SRC/test/update/Queries/w3c_update_testsuite/TestSources/uri.txt" --as-files --query "$q"

echo "Adding xml.xsd entry to uri.txt ..."
echo >> "$SRC/test/update/Queries/w3c_update_testsuite/TestSources/uri.txt"
echo "http://www.w3.org/XML/1998/namespace=TestSources/xml.xsd" >> "$SRC/test/update/Queries/w3c_update_testsuite/TestSources/uri.txt"
cp "$SRC/test/update/xml.xsd" "$SRC/test/update/Queries/w3c_update_testsuite/TestSources"

cat >"$q" <<"EOF"
declare default element namespace "http://www.w3.org/2005/02/query-test-update";
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
concat("Args:", string-join(
  for $infile in $state/input-file 
  let $source := //source[@ID eq $infile/text()]
  return concat(" -x ", $infile/@variable,"=$UPDATE_SRC_DIR/Queries/w3c_update_testsuite/",$source/@FileName) ,"")  ,if ($state/query/@date) then concat(" -d ",$state/query/@date) else ()),
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
"$BUILD/bin/zorba" --context-item XQUTSCatalog.xml --omit-xml-declaration --as-files --query "$q" | tee /tmp/xq-res.txt | perl -e '
use strict;
use File::Copy;

my $suite=shift;

print "Creating spec files in $suite ...\n";
while (<>) 
{
  chomp;
  if (m/^%uri /) {
  }
  elsif (m/^%src /) {
  }
  elsif (m/^case=/) {
    my ($var, $name) = split(/=/);
    my $path = $suite . "/XQuery/" . "$name.spec";
    my $path_xqueryx =  $suite . "/XQueryX/" . "$name.spec";
    open (SPEC, ">$path");
    open (SPEC_XQUERYX, ">$path_xqueryx");
  }
  elsif (m/^end/) {
    close (SPEC);
    close (SPEC_XQUERYX);
  }
  else {
    print SPEC "$_\n"; 
    print SPEC_XQUERYX "$_\n"; 
  }
}

' "$SRC/test/update/Queries/w3c_update_testsuite"

rm -f "$q"

mv XQUTSCatalog.xml XQUTSCatalog.xsd "$SRC/test/update/Queries/w3c_update_testsuite"

echo "Cleaning up work directory...$orig_pwd $unzip_dir"

cd "$orig_pwd"
#rm -rf "$unzip_dir"

echo Done.

echo "Now re-run cmake in your build directory to add W3C update tests to CTest."
