# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
To generate a report for submitting to the W3C:

0.  For submitting reports to W3C one should compile Zorba with ZORBA_WITH_BIG_INTEGER=ON. 
    In order to generate the report for XQueryX compile Zorba by setting:
    ZORBA_XQUERYX=ON and ZORBA_TEST_XQUERYX=ON. These options are set to OFF by default.

1.  Import XQTS/XQFTTS.

2.  Run a CTest dashboard from your build directory:

    ctest -T test -R w3c_testsuite/XQuery 
    ctest -T test -R w3c_testsuite/XQueryX
    ctest -T test -R w3c_full_text_testsuite/XQuery
    ctest -T test -R w3c_full_text_testsuite/XQueryX

3.  From this directory (test/rbkt/Scripts/w3c), modify
    generate-submission-xqts.xq/generate-submission-xqftts.xq to reflect:

    - the node 'implementation', attribute 'version' - the version of Zorba and the svn revision tested
    - node 'syntax' - either XQuery or XQueryX
    - node 'test-run', attribute 'date-run' - the date run
    - node 'test-suite', attribute 'version' - the test suite version (for example '1.0.2' or 'current')

4.  From this directory (test/rbkt/Scripts/w3c), run

    cmake -P Submit_xqts.cmake > zorba-xqts-submission.xml
    cmake -P Submit_xqftts.cmake > zorba-xqftts-submission.xml

    Note that this assumes your build directory is ../../../../build. If
    that is not true, specify the path to your build directory:

    cmake -D ZORBA_BUILD_DIR=/path/to/build -P Submit_xqts.cmake > zorba-xqts-submission.xml
    cmake -D ZORBA_BUILD_DIR=/path/to/build -P Submit_xqftts.cmake > zorba-xqftts-submission.xml

    The script depends on the XQTS/XQFTTS schema being located in

    w3c_reportingresults/XQTSResult.xsd
    w3c_full_text_reportingresults/XQFTTSResult.xsd

    The XQTS/XQFTTS import script puts this in place appropriately. If you do
    not run the import script, just copy the "ReportingResults"
    directory from the XQTS/XQFTTS download to w3c_reportingresults/w3c_full_text_reportingresults.

    In order to generate the HTML versions of the reports:
    - either (XQTSReport.html and XQTSReportSimple.html)
    - or (XQFTTSReport.html and XQFTTSReportSimple.html) these are the additional steps that have to be followed:

5.  Go to the /tmp folder and unzip the XQTS/XQFTTS version you used to generate the report(s). Let's assume it is XQTS_current.zip.

6.  Copy the XML(s) into the /tmp/XQTS_current/ReportingResults folder

7.  Modify /tmp/XQTS_current/ReportingResults/Results.xml by adding a result node for every report you copied at step 5.

8.  From /tmp/XQTS_current/ReportingResults/ run 'ant -buildfile Build.xml' in order to generate XQTSReport.html and XQTSReportSimple.html
