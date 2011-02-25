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

#IF (NOT WIN32 OR UNIX)

MESSAGE (STATUS "Adding iterator plan tests")
FILE (GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.iter)

# tests need to be registered for each store
FOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})
  SET(SUFFIX)
  IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
    SET(SUFFIX "_${ZORBA_STORE_NAME}")
  ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")

  # compute path to apitest
  IF (WIN32)
    IF (ZORBA_WIN_PUT_ALL_BINARIES_IN_SAME_DIR)
      SET(APITEST_PATH ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/apitest${SUFFIX}.exe)
    ELSEIF(MSVC_IDE)
      SET(APITEST_PATH ${CMAKE_BINARY_DIR}/test/${CMAKE_BUILD_TYPE}/apitest${SUFFIX}.bat)
    ELSE()
      SET(APITEST_PATH ${CMAKE_BINARY_DIR}/test/apitest${SUFFIX}.bat)
    ENDIF()
  ELSE()
    SET(APITEST_PATH ${CMAKE_BINARY_DIR}/test/apitest${SUFFIX})
  ENDIF()

  # disabled those test that are failing in the remote queue
  # remove after bug #3192214 is fixed
  SET (TESTFILES "")

  FOREACH (TESTFILE ${TESTFILES})
    STRING (REPLACE w3c_testsuite official_ts TESTNAME "${TESTFILE}")
    ADD_TEST (
      "iterplans/${TESTNAME}" 
      "${ZORBA_EXE_SCRIPT}" 
      -q "${CMAKE_BINARY_DIR}/test/rbkt/itertest.xq" -f 
      -e "testfile:=${TESTFILE}" 
      -e "apitest-path:=${APITEST_PATH}" 
      -z "method=text")
    SET_TESTS_PROPERTIES("iterplans/${TESTNAME}" 
      PROPERTIES PASS_REGULAR_EXPRESSION "Passed! *")
  ENDFOREACH(TESTFILE)
ENDFOREACH(ZORBA_STORE_NAME ${ZORBA_STORE_NAMES})

#ENDIF (NOT WIN32 OR UNIX)

