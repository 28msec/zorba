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
