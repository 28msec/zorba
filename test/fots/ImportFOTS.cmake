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
# Required argument: OUTDIR (should be ${CMAKE_CURRENT_BINARY_DIR})
# Required argument: ZORBA (full path to Zorba command-line executable)


# Change this to publish updated FOTS archives
SET (FOTS_ARCHIVE "FOTS_041212.tgz")


# Download and unpack pre-created archive
MESSAGE (STATUS "Downloading FOTS archive...")
FILE (DOWNLOAD http://zorbatest.lambda.nu:8080/~ceej/${FOTS_ARCHIVE}
  "${OUTDIR}/${FOTS_ARCHIVE}" STATUS _dlstat SHOW_PROGRESS)
LIST (GET _dlstat 0 _dlcode)
IF (NOT _dlcode EQUAL 0)
  LIST (GET _dlstat 1 _dlmsg)
  MESSAGE (FATAL_ERROR "Error downloading FOTS archive: ${_dlmsg}")
ENDIF (NOT _dlcode EQUAL 0)

MESSAGE (STATUS "Unpacking FOTS archive...")
EXECUTE_PROCESS (COMMAND "${CMAKE_COMMAND}" -E tar xf ${FOTS_ARCHIVE}
  WORKING_DIRECTORY "${OUTDIR}" RESULT_VARIABLE _unpackstat)
IF (NOT _unpackstat EQUAL 0)
  MESSAGE (FATAL_ERROR "Error unpackaging FOTS archive: ${_unpackstat}")
ENDIF (NOT _unpackstat EQUAL 0)

# Scan FOTS catalogs and create ADD_TEST scripts. First, create a list
# of test sets. We assume that the FOTS driver is in a sibling directory
# named fots_driver.
MESSAGE (STATUS "Creating CTest scripts...")
EXECUTE_PROCESS (COMMAND "${ZORBA}" --omit-xml-declaration -f -q
  "${CMAKE_CURRENT_SOURCE_DIR}/../fots_driver/cli.xq"
  -e "fotsPath:=${OUTDIR}/2011/QT3-test-suite/catalog.xml"
  -e mode:=list-test-sets
  OUTPUT_VARIABLE _testsetsstring)
STRING (REGEX REPLACE "[\n\r]+" ";" _testsets ${_testsetsstring})

# Create the ADD_TEST script based on test sets.
SET (_setscript "${OUTDIR}/FOTSSetTests.cmake")
FILE (REMOVE "${_setscript}")
FOREACH (_testset ${_testsets})
  FILE (APPEND "${_setscript}"
    "ZORBA_ADD_TEST (FOTS-set-${_testset} zorbacmd -f -q "
    "${CMAKE_CURRENT_SOURCE_DIR}/../fots_driver/cli.xq "
    "-e fotsPath:=${OUTDIR}/2011/QT3-test-suite/catalog.xml "
    "-e mode:=run-test-sets -e testSetPrefixes:=${_testset})\n")
ENDFOREACH (_testset)
