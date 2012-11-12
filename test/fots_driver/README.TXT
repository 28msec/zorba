Information about the W3C XQuery/XPath/XSLT 3.* Test Suite can be found here: http://dev.w3.org/2011/QT3-test-suite.

In order to use the Zorba FOTS driver (written in XQuery) one has to follow these steps:

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

Always try to run the CLI and output the result back to an XML file with nice indentation.
./zorba -f
        -q ../../test/fots_driver/cli.xq
        -e SET_CLI_OPTIONS_HERE
        -o output.xml
        --indent
 This way you will see trace information in the CLI window and detailed results of the tests in the 'output.xml'.

zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e fotsZorbaManifestPath:=/path/to/Zorba_manifest.xml -e mode:=list-test-sets
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets -e verbose:=true
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-sets -e testSetPrefixes:=prod,app
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-test-cases -e testSetPrefixes:=prod-Literal
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=list-matching-test-cases -e pattern:=catch
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod-Literal -o result.xml --indent
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-sets -e testSetPrefixes:=prod-Literal -e verbose:=false -o result.xml --indent
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-cases -e testSetPrefixes:=prod-Literal -e testCasePrefixes:=Literal -o result.xml --indent
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-cases -e assertType:=assert-count -e testSetPrefixes:=fn-innermost -o result.xml --indent
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-test-cases -e assertType:=assert-count -o result.xml --indent
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=run-and-report -o report.xml --indent
zorba -f -q /path/to/cli.xq -e fotsPath:=/path/to/QT3-test-suite/catalog.xml -e mode:=report -e failuresFilePath:=failures.xml -e verbose:=false -o report.xml --indent