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

# configure itertest/profiletest
CONFIGURE_FILE(itertest.xq.in ${CMAKE_CURRENT_BINARY_DIR}/itertest.xq)
CONFIGURE_FILE(profiletest.xq.in ${CMAKE_CURRENT_BINARY_DIR}/profiletest.xq)

# apitest
SET(APITEST_SRCS
  apitest_args.cpp
  apitest_props.cpp
  apitest.cpp
)
ZORBA_GENERATE_EXE("apitest" "${APITEST_SRCS}" "" "" "")

MESSAGE (STATUS "Adding iterator plan tests")
FILE (GLOB_RECURSE ITERTESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.iter)
MESSAGE (STATUS "Adding profile tests")
FILE (GLOB_RECURSE PROFILETESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.profile)

# compute path to apitest
SET(SUFFIX)
IF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
  SET(SUFFIX "_${ZORBA_STORE_NAME}")
ENDIF (NOT ${ZORBA_STORE_NAME} STREQUAL "simplestore")
IF (WIN32)
  SET(APITEST_PATH ${CMAKE_CURRENT_BINARY_DIR}/apitest${SUFFIX}.bat)
ELSE()
  SET(APITEST_PATH ${CMAKE_CURRENT_BINARY_DIR}/apitest${SUFFIX})
ENDIF()

FOREACH (TESTFILE ${ITERTESTFILES})
  STRING (REPLACE w3c_testsuite official_ts TESTNAME "${TESTFILE}")
   
  ADD_TEST(
    "iterators/${TESTNAME}" 
    "${CMAKE_COMMAND}"
    -D "TESTFILE=${TESTFILE}"
    -D "CMAKE_ZORBA_BINARY_DIR=${CMAKE_BINARY_DIR}"
    -D "ZORBA_EXE=${ZORBA_EXE}"
    -D "CMAKE_ZORBA_SOURCE_DIR=${CMAKE_SOURCE_DIR}"
    -D "APITEST_PATH=${APITEST_PATH}"
    -P "${CMAKE_CURRENT_SOURCE_DIR}/iterscript.cmake")
     
  SET_TESTS_PROPERTIES("iterators/${TESTNAME}" 
    PROPERTIES PASS_REGULAR_EXPRESSION "Passed! *")
ENDFOREACH(TESTFILE)

FOREACH (TESTFILE ${PROFILETESTFILES})
  STRING (REPLACE w3c_testsuite official_ts TESTNAME "${TESTFILE}")
   
  ADD_TEST(
    "iterators/${TESTNAME}" 
    "${CMAKE_COMMAND}"
    -D "TESTFILE=${TESTFILE}"
    -D "CMAKE_ZORBA_BINARY_DIR=${CMAKE_BINARY_DIR}"
    -D "ZORBA_EXE=${ZORBA_EXE}"
    -D "CMAKE_ZORBA_SOURCE_DIR=${CMAKE_SOURCE_DIR}"
    -D "APITEST_PATH=${APITEST_PATH}"
    -P "${CMAKE_CURRENT_SOURCE_DIR}/profilescript.cmake")
     
  SET_TESTS_PROPERTIES("iterators/${TESTNAME}" 
    PROPERTIES PASS_REGULAR_EXPRESSION "Passed! *")
ENDFOREACH(TESTFILE)


# vim:set et sw=2 ts=2:
