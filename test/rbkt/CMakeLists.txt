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

ADD_SUBDIRECTORY(Scripts)
ADD_SUBDIRECTORY(ExpCompilerResults)

# create the result directory for all tests
IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)

# configure the testdriver
CONFIGURE_FILE(testdriverconfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/testdriverconfig.h)

#
# Compile and build the testdriver executable
#
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/test/commons)

SET (TESTDRIVER_SRCS
  testdriver.cpp
  testdriver_common.cpp
  ${CMAKE_SOURCE_DIR}/test/commons/testdriver_comparator.cpp
  ${CMAKE_SOURCE_DIR}/test/commons/testuriresolver.cpp
  )

ADD_EXECUTABLE(testdriver ${TESTDRIVER_SRCS})
TARGET_LINK_LIBRARIES(testdriver zorba_${ZORBA_STORE_LIB_EXTENSION})

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(testdriver_static ${TESTDRIVER_SRCS})
  SET_TARGET_PROPERTIES(testdriver_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
  TARGET_LINK_LIBRARIES(testdriver_static zorba_${ZORBA_STORE_LIB_EXTENSION}_static)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

IF(WIN32)
#for Windows and Cygwin
  SET(TESTDRIVER_EXE_PATH   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testdriver)
ELSE(WIN32)
  SET(TESTDRIVER_EXE_PATH   testdriver)
ENDIF(WIN32)


#
# Compile and build the multi-threaded testdriver executable
#

SET(ZORBA_BUILD_MT_TESTDRIVER 1)

IF (ZORBA_BUILD_MT_TESTDRIVER)

INCLUDE(${CMAKE_MODULE_PATH}/FindBoost.cmake)

SET (REQUIRED_BOOST_PACKAGES filesystem)

FIND_PACKAGE(Boost REQUIRED COMPONENTS ${REQUIRED_BOOST_PACKAGES})

IF (NOT Boost_FOUND)
  MESSAGE(FATAL "Boost not found")
ELSE (NOT Boost_FOUND)
  MESSAGE(STATUS "Found Boost: ${Boost_INCLUDE_DIRS}")
  MESSAGE(STATUS "      Boost: ${Boost_LIBRARY_DIRS}")

  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF (NOT Boost_FOUND)

SET (TESTDRIVER_MT_SRCS
  testdriver_mt.cpp
  testdriver_common.cpp
  ${CMAKE_SOURCE_DIR}/test/commons/testdriver_comparator.cpp
  ${CMAKE_SOURCE_DIR}/test/commons/testuriresolver.cpp
  )

#ADD_EXECUTABLE(testdriver_mt ${TESTDRIVER_MT_SRCS})

TARGET_LINK_LIBRARIES(testdriver_mt
                      zorba_${ZORBA_STORE_LIB_EXTENSION}
                      boost_filesystem-mt)

IF (ZORBA_BUILD_STATIC_LIBRARY)

  ADD_EXECUTABLE(testdriver_mt_static testdriver_mt.cpp)

  SET_TARGET_PROPERTIES(testdriver_mt_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)

  TARGET_LINK_LIBRARIES(testdriver_mt_static
                        zorba_${ZORBA_STORE_LIB_EXTENSION}_static
                        boost_filesystem-mt)

ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

ENDIF(ZORBA_BUILD_MT_TESTDRIVER)


#
#
#
MESSAGE(STATUS "Adding tests for CTest")

FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries FOLLOW_SYMLINKS "*.xq")
IF(ZORBA_TEST_XQUERYX)
  FILE(GLOB_RECURSE TESTFILES_XQX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries FOLLOW_SYMLINKS "*.xqx")
  IF (TESTFILES_XQX)
    LIST(APPEND TESTFILES ${TESTFILES_XQX})
  ENDIF (TESTFILES_XQX)
ENDIF(ZORBA_TEST_XQUERYX)

# collect all chained test queries (suffix .cxq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE CHAINED_TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ FOLLOW_SYMLINKS *.cxq)

SET(TESTCOUNTER 0)
SET(NORMAL_TIMEOUT_VALUE  30)   #let's say 30 seconds for test timeout

LIST(LENGTH CHAINED_TESTFILES cxqNO)

# if we have .cxq files
IF(${cxqNO} STRGREATER "0")

  SET(PARAM 0)

  #create a list with the folders containg *.cxq files
  FOREACH(CHAINED_TESTFILE ${CHAINED_TESTFILES})
    GET_FILENAME_COMPONENT(TF_PATH ${CHAINED_TESTFILE} PATH)
    IF(NOT ${PARAM} STREQUAL ${TF_PATH})
      LIST(APPEND CHAINED_TESTS_LIST ${TF_PATH})
    ENDIF(NOT ${PARAM} STREQUAL ${TF_PATH})
    SET(PARAM ${TF_PATH})
  ENDFOREACH(CHAINED_TESTFILE)

  #foreach chained test create a list with all the test files and sort it alphabetically
  FOREACH(CT ${CHAINED_TESTS_LIST})

    #create the name of the test and put it in TEST_NAME variable
    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    GET_FILENAME_COMPONENT(TF_DIR ${CT} NAME)
    SET(TEST_NAME "${TESTCOUNTER}_${TF_DIR}")

    #create the list of tests to be passed to the testdriver call
    FOREACH(CHAINED_TESTFILE ${CHAINED_TESTFILES})
      GET_FILENAME_COMPONENT(TF_PATH ${CHAINED_TESTFILE} PATH)
      IF(TF_PATH STREQUAL CT)
        IF(ZORBA_USE_SEPARATE_WINCE_SVN)
          LIST(APPEND CHAINED_TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Queries/${CHAINED_TESTFILE})
        ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
          GET_FILENAME_COMPONENT(TF_NAME ${CHAINED_TESTFILE} NAME)
          LIST(APPEND CHAINED_TESTS_FILES ${CHAINED_TESTFILE})
        ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)
      ENDIF(TF_PATH STREQUAL CT)
    ENDFOREACH(CHAINED_TESTFILE)

    #sort the list of test files alphabetically
    LIST(SORT  CHAINED_TESTS_FILES)

  SET(TEST_NAME "test/rbkt/${TEST_NAME}")
  #finally add the test
  IF(ZORBA_USE_SEPARATE_WINCE_SVN)
    ADD_TEST(${TEST_NAME} ${TESTDRIVER_EXE_PATH} ${CMAKE_CURRENT_BINARY_DIR} ${CHAINED_TESTS_FILES})
  ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
    ADD_TEST(${TEST_NAME} ${TESTDRIVER_EXE_PATH} ${CHAINED_TESTS_FILES})
  ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)

    SET_TESTS_PROPERTIES (${TEST_NAME} PROPERTIES TIMEOUT ${NORMAL_TIMEOUT_VALUE})

    #clear the list of testfiles, args and also the name of the test
    SET(CHAINED_TESTS_FILES)
    SET(ARGS)
    SET(TEST_NAME)
  ENDFOREACH(CT)
ENDIF(${cxqNO} STRGREATER "0")

FOREACH(TESTFILE ${TESTFILES})

  STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
  MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-3' )
  STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)
  SET(TESTNAME "test/rbkt/${TESTNAME}")

  # Skip tests that we don't have the pre-requisites for.
  # This seems like an error-prone manual way to do this...
  SET(SKIP_TEST 0)
  IF(NOT ZORBA_WITH_TIDY)
    # These tests require only tidy
    STRING(REGEX MATCH "aleXis/q(10|5|6|8|9)" NEEDS_TIDY "${TESTNAME}")
    # These tests require tidy and rest
    STRING(REGEX MATCH "rest/rest.*tidy" NEEDS_TIDY_AND_REST "${TESTNAME}")
    IF(NEEDS_TIDY OR NEEDS_TIDY_AND_REST)
      SET(SKIP_TEST 1)
    ENDIF()
  ENDIF(NOT ZORBA_WITH_TIDY)
  IF(NOT ZORBA_WITH_REST)
    # These tests require rest 
    STRING(REGEX MATCH "rest/" NEEDS_REST "${TESTNAME}")
    IF(NEEDS_REST)
      SET(SKIP_TEST 1)
    ENDIF()
  ENDIF(NOT ZORBA_WITH_REST)

  IF(NOT SKIP_TEST)

    IF(ZORBA_USE_SEPARATE_WINCE_SVN)
      ADD_TEST(${TESTNAME} ${TESTDRIVER_EXE_PATH} ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Queries/${TESTFILE})
    ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
      ADD_TEST(${TESTNAME} ${TESTDRIVER_EXE_PATH} ${TESTFILE})
    ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)
    SET_TESTS_PROPERTIES (${TESTNAME} PROPERTIES
      TIMEOUT ${NORMAL_TIMEOUT_VALUE})
    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
    IF (${TESTMOD})
      MESSAGE(STATUS "Adding another 1000 Tests")
      SET(TESTCOUNTER 0)
    ENDIF (${TESTMOD})

  ENDIF(NOT SKIP_TEST)


ENDFOREACH(TESTFILE)

# Current rbkt expected failures
# QQQ file real Sourceforge bugs for these
expected_failure ("test/rbkt/zorba/index/auctions1" 9999999)
expected_failure ("test/rbkt/zorba/index/auctions1u" 9999999)
expected_failure ("test/rbkt/zorba/index/available" 9999999)
expected_failure ("test/rbkt/zorba/index/declared" 9999999)
expected_failure ("test/rbkt/zorba/collections/declare_1" 9999999)
expected_failure ("test/rbkt/zorba/collections/import_2" 9999999)
