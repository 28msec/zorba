Information about the W3C XQuery/XPath/XSLT 3.* Test Suite can be found at:
  http://dev.w3.org/2011/QT3-test-suite.

In order to use the Zorba FOTS driver (written in XQuery) one has to follow
these steps:

0)  Build Zorba with  ZORBA_WITH_BIG_INTEGER flag set to ON.

    For example with CMake:
      cmake -DZORBA_WITH_BIG_INTEGER=ON ..
      make

1)  Download the FOTS testsuite from W3C
    Since currently there is no official release, a simple "cvs get" will do:

      $ export CVSROOT=":pserver:anonymous@dev.w3.org:/sources/public"
      $ cvs login
        (Logging in to anonymous@dev.w3.org)
        CVS password: anonymous
      $ cvs get 2011/QT3-test-suite

3)  run
    ./zorba -f
            -q ../../test/fots_driver/cli.xq

Zorba FOTS driver usage examples:
If you run Zorba from a checkout of the trunk and the build/bin folder,
- /path/to/cli.xq can be set to ../../test/fots_driver/cli.xq

'fotsPath' is set by default to the location where 'make fots-import' added the FOTS snapshot.
Currently this location is ZORBA_BUILD_FOLDER/test/fots/2011/QT3-test-suite/catalog.xml.
If you want to use other location please set 'fotsPath'.

Always try to output the result back to an XML file with nice indentation:
./zorba -f -q ../../test/fots_driver/cli.xq -e SET_CLI_OPTIONS_HERE -o output.xml --indent

 This way you will see trace information in the CLI window and detailed
 results of the test cases in the 'output.xml'.

 Please note that when Verbose is set to true the query that is executed
 is written down into a query_TESTCASENAME.xq file, where TESTCASENAME is
 the test case name.

zorba -f -q /path/to/cli.xq -e fotsZorbaManifestPath:=/path/to/Zorba_manifest.xml -e mode:=list-test-sets
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets
zorba -f -q /path/to/cli.xq -e mode:=list-test-sets -e testSetPrefixes:=prod,app
zorba -f -q /path/to/cli.xq -e mode:=list-test-cases -e testSetPrefixes:=prod-Literal
zorba -f -q /path/to/cli.xq -e mode:=list-test-cases -e dependency:=higherOrderFunctions
zorba -f -q /path/to/cli.xq -e mode:=list-test-cases -e dependency:=higherOrderFunctions -e assertions:=assert-count
zorba -f -q /path/to/cli.xq -e mode:=list-matching-test-cases -e pattern:=catch
zorba -f -q /path/to/cli.xq -e mode:=run-test-sets -e testSetPrefixes:=prod -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-test-sets -e testSetPrefixes:=prod -e expectedFailuresPath:=ExpectedFailures.xml -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-test-sets -e testSetPrefixes:=prod -e dependency:=higherOrderFunctions_false -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-test-sets -e testSetPrefixes:=prod -e assertions:=assert-count -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-test-sets -e testSetPrefixes:=prod-Literal -e verbose:=true -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-test-set  -e testSetName:=fn-matches -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-test-set  -e testSetName:=fn-matches -e usePlanSerializer:=true -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-test-case -e testSetName:=prod-Literal -e testCaseName:=Literals001 -o result.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=run-and-report -e XQueryVersion:=XQ30 -o results_Zorba_XQ30.xml --indent --disable-http-resolution
zorba -f -q /path/to/cli.xq -e mode:=run-and-report -e XQueryVersion:=XQ10 -o results_Zorba_XQ10.xml --indent --disable-http-resolution
zorba -f -q /path/to/cli.xq -e mode:=report -e resultsFilePath:=results.xml -e XQueryVersion:=XQ30 -o results_Zorba_XQ30.xml --indent
zorba -f -q /path/to/cli.xq -e mode:=report -e resultsFilePath:=results.xml -e XQueryVersion:=XQ10 -o results_Zorba_XQ10.xml --indent

