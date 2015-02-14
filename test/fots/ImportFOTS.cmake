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
#
# Downloads the latest FOTS archive and prepares for CTest integration.
# Required argument: BUILDDIR (should be ${PROJECT_BINARY_DIR})
# Required argument: ZORBA (full path to Zorba command-line executable)


# Change this to publish updated FOTS archives

#this is the official QT 1.0 release from 21st June 2013
#SET (FOTS_ARCHIVE "QT3_1_0.tgz")

#this is the QT CVS trunk version as from 5th August 2013
SET (FOTS_ARCHIVE "QT_050813.tgz")

# Change this to modify which elements in FOTS driver results are output
# as CDATA
SET (FOTS_CDATA_ELEMENTS "fots:query fots:result test assert-xml")

# Download and unpack pre-created archive
SET (_outdir "${BUILDDIR}/test/fots")
IF(EXISTS "${_outdir}/${FOTS_ARCHIVE}")
  MESSAGE (STATUS "FOTS archive '${FOTS_ARCHIVE}' already downloaded.")
ELSE(EXISTS "${_outdir}/${FOTS_ARCHIVE}")
  MESSAGE (STATUS "Downloading FOTS archive '${FOTS_ARCHIVE}'...")
  FILE (DOWNLOAD http://w3c-tests.s3.amazonaws.com/${FOTS_ARCHIVE}
    "${_outdir}/${FOTS_ARCHIVE}" STATUS _dlstat SHOW_PROGRESS)
  LIST (GET _dlstat 0 _dlcode)
  IF (NOT _dlcode EQUAL 0)
    LIST (GET _dlstat 1 _dlmsg)
    MESSAGE (FATAL_ERROR "Error downloading FOTS archive http://w3c-tests.s3.amazonaws.com/${FOTS_ARCHIVE}: ${_dlmsg}")
  ENDIF (NOT _dlcode EQUAL 0)
ENDIF(EXISTS "${_outdir}/${FOTS_ARCHIVE}")

# Remove old version of the FOTS testsuite (if it exists)
MESSAGE (STATUS "Remove old version of the FOTS testsuite (if it exists)...")
EXECUTE_PROCESS (COMMAND "${CMAKE_COMMAND}" -E remove_directory "${_outdir}/2011"
  RESULT_VARIABLE _remove)

MESSAGE (STATUS "Unpacking FOTS archive...")
EXECUTE_PROCESS (COMMAND "${CMAKE_COMMAND}" -E tar xf ${FOTS_ARCHIVE}
  WORKING_DIRECTORY "${_outdir}" RESULT_VARIABLE _unpackstat)
IF (NOT _unpackstat EQUAL 0)
  MESSAGE (FATAL_ERROR "Error unpackaging FOTS archive: ${_unpackstat}")
ENDIF (NOT _unpackstat EQUAL 0)

# Scan FOTS catalogs and create ADD_TEST scripts. First, create a list
# of test sets. We assume that the FOTS driver is in a sibling directory
# named fots_driver.
MESSAGE (STATUS "Creating CTest scripts...")
EXECUTE_PROCESS (COMMAND "${BUILDDIR}/bin/zorba" --omit-xml-declaration -f -q
  "${CMAKE_CURRENT_LIST_DIR}/../fots_driver/cli.xq"
  -e "fotsPath:=${_outdir}/2011/QT3-test-suite/catalog.xml"
  -e mode:=list-test-sets
  OUTPUT_VARIABLE _testsetsstring RESULT_VARIABLE _zstat)
IF (NOT _zstat EQUAL 0)
  MESSAGE (FATAL_ERROR "Zorba failed with message: ${_zstat}\n"
    "(perhaps you haven't built Zorba yet?)")
ENDIF (NOT _zstat EQUAL 0)
STRING (REGEX REPLACE "[\n\r]+" ";" _testsets ${_testsetsstring})

SET (_setscript "${_outdir}/FOTSSetTests.cmake")
SET (_casescript "${_outdir}/FOTSCaseTests.cmake")
FILE (REMOVE "${_setscript}")
FILE (REMOVE "${_casescript}")

# Iterate through all test sets.
FOREACH (_testset ${_testsets})
  # Add a test for the whole test set.
  FILE (APPEND "${_setscript}"
    "ZORBA_ADD_TEST (FOTS/${_testset} zorbacmd -f -q "
    "${CMAKE_CURRENT_LIST_DIR}/../fots_driver/cli.xq "
    "-e fotsPath:=${_outdir}/2011/QT3-test-suite/catalog.xml "
    "-e mode:=run-test-set -e testSetName:=${_testset} "
    "-e expectedFailuresPath:=${BUILDDIR}/FOTSExpectedFailures.xml "
    "-e verbose:=true "
    "-e ctestMode:=true "
    "-e usePlanSerializer:=true "
    "--disable-http-resolution --indent "
    "-z \"cdata-section-elements=${FOTS_CDATA_ELEMENTS}\")\n"
    "ZORBA_SET_TEST_PROPERTY (FOTS/${_testset} "
    "FAIL_REGULAR_EXPRESSION \"result=\\\"fail\\\"\")\n")

  # Iterate through the test cases for this test set.
#  EXECUTE_PROCESS (COMMAND "${ZORBA}" --omit-xml-declaration -f -q
#    "${CMAKE_CURRENT_LIST_DIR}/../fots_driver/cli.xq"
#    -e "fotsPath:=${_outdir}/2011/QT3-test-suite/catalog.xml"
#    -e mode:=list-test-cases -e testSetPrefixes:=${_testset}
#    OUTPUT_VARIABLE _testcasesstring)
#  STRING (REGEX REPLACE "[\n\r]+" ";" _testcases ${_testcasesstring})
  EXECUTE_PROCESS (COMMAND "${ZORBA}" --omit-xml-declaration -f -q
    "${CMAKE_CURRENT_LIST_DIR}/get-tests.xq"
    --base-uri "${_outdir}/2011/QT3-test-suite/catalog.xml"
    -e testSet:=${_testset}
    OUTPUT_VARIABLE _testcases)
  FOREACH (_testcase ${_testcases})
    # Add a test for the test case.
    FILE (APPEND "${_casescript}"
      "ZORBA_ADD_TEST (FOTS/${_testset}/${_testcase} zorbacmd -f -q "
      "${CMAKE_CURRENT_LIST_DIR}/../fots_driver/cli.xq "
      "-e fotsPath:=${_outdir}/2011/QT3-test-suite/catalog.xml "
      "-e mode:=run-test-case "
      "-e testSetName:=${_testset} -e testCaseName:=${_testcase} "
      "-e expectedFailuresPath:=${BUILDDIR}/FOTSExpectedFailures.xml "
      "-e verbose:=true "
      "-e ctestMode:=true "
      "-e usePlanSerializer:=true "
      "--disable-http-resolution --indent "
      "-z \"cdata-section-elements=${FOTS_CDATA_ELEMENTS}\")\n"
      "ZORBA_SET_TEST_PROPERTY (FOTS/${_testset}/${_testcase} "
      "PASS_REGULAR_EXPRESSION \"name=\\\"${_testcase}\\\" result=\\\"pass\\\"\")\n")
  ENDFOREACH (_testcase)
ENDFOREACH (_testset)
