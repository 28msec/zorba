To generate a report for submitting to the W3C:

1. Import XQUTS.

2. Run a CTest dashboard from your build directory:

  ctest -T test -R w3c_update_testsuite

3. From this directory (test/update/Scripts), run

  cmake -P Submit.cmake

   Note that this assumes your build directory is ../../../build. If
   that is not true, specify the path to your build directory:

  cmake -D ZORBA_BUILD_DIR=/path/to/build -P Submit.cmake

   The script depends on the XQUTS schema being located in

  w3c_update_reportingresults/XQTSResult.xsd

   The XQUTS import script puts this in place appropriately. If you do
   not run the import script, just copy the "ReportingResults"
   directory from the XQUTS download to w3c_update_reportingresults.
