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

MESSAGE(STATUS "Adding tests for CTest")
INCLUDE(ZorbaAddTest)

FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/*.xq")
IF(ZORBA_TEST_XQUERYX)
  FILE(GLOB_RECURSE TESTFILES_XQX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/*.xqx")
  IF (TESTFILES_XQX)
    LIST(APPEND TESTFILES ${TESTFILES_XQX})
  ENDIF (TESTFILES_XQX)
ENDIF(ZORBA_TEST_XQUERYX)

# collect all chained test queries (suffix .cxq) in all subdirectories of this dir
FILE(GLOB_RECURSE CHAINED_TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/*.cxq")

SET(TESTCOUNTER 0)
SET(NORMAL_TIMEOUT_VALUE  60)   #let's say 60 seconds for test timeout

LIST(LENGTH CHAINED_TESTFILES cxqNO)

# if we have .cxq files
IF(${cxqNO} STRGREATER "0")

  SET(PARAM 0)

  # create a list with the folders containg *.cxq files
  FOREACH(CHAINED_TESTFILE ${CHAINED_TESTFILES})
    GET_FILENAME_COMPONENT(TF_PATH ${CHAINED_TESTFILE} PATH)
    IF(NOT ${PARAM} STREQUAL ${TF_PATH})
      LIST(APPEND CHAINED_TESTS_LIST ${TF_PATH})
    ENDIF(NOT ${PARAM} STREQUAL ${TF_PATH})
    SET(PARAM ${TF_PATH})
  ENDFOREACH(CHAINED_TESTFILE)

  # foreach chained test create a list with all the test files and sort it alphabetically
  FOREACH(CT ${CHAINED_TESTS_LIST})

    # create the name of the test and put it in TEST_NAME variable
    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    GET_FILENAME_COMPONENT(TF_DIR ${CT} NAME)
    SET(TEST_NAME "${TESTCOUNTER}_${TF_DIR}")

    #create the list of tests to be passed to the testdriver call
    FOREACH(CHAINED_TESTFILE ${CHAINED_TESTFILES})
      GET_FILENAME_COMPONENT(TF_PATH ${CHAINED_TESTFILE} PATH)
      IF(TF_PATH STREQUAL CT)
        IF(ZORBA_USE_SEPARATE_WINCE_SVN)
          LIST(APPEND CHAINED_TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${CHAINED_TESTFILE})
        ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
          GET_FILENAME_COMPONENT(TF_NAME ${CHAINED_TESTFILE} NAME)
          LIST(APPEND CHAINED_TESTS_FILES ${CHAINED_TESTFILE})
        ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)
      ENDIF(TF_PATH STREQUAL CT)
    ENDFOREACH(CHAINED_TESTFILE)

    # sort the list of test files alphabetically
    LIST(SORT CHAINED_TESTS_FILES)

    SET(TEST_NAME "test/rbkt/${TEST_NAME}")
    
    # finally add the test
    IF(ZORBA_USE_SEPARATE_WINCE_SVN)
      ADD_TEST(${TEST_NAME} ${TESTDRIVER_EXE_PATH} ${CMAKE_CURRENT_BINARY_DIR}/.. ${CHAINED_TESTS_FILES})
    ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
      ZORBA_ADD_TEST_ALLSTORES("${TEST_NAME}" testdriver ${CHAINED_TESTS_FILES})
    ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)


    # clear the list of testfiles, args and also the name of the test
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
    STRING(REGEX MATCH "aleXis/(q(10|5|6|8|9)|tidy_wrong_options)" NEEDS_TIDY "${TESTNAME}")
    # These tests require tidy and rest
    STRING(REGEX MATCH "rest/rest.*tidy" NEEDS_TIDY_AND_REST "${TESTNAME}")
    STRING(REGEX MATCH "http_client" HTTP_CLIENT "${TESTNAME}")
    IF(NEEDS_TIDY OR NEEDS_TIDY_AND_REST OR HTTP_CLIENT)
      SET(SKIP_TEST 1)
    ENDIF()
  ENDIF(NOT ZORBA_WITH_TIDY)
  IF(NOT ZORBA_WITH_REST)
    # These tests require rest 
    STRING(REGEX MATCH "rest/" NEEDS_REST "${TESTNAME}")
    STRING(REGEX MATCH "aleXis/q(10|8)" NEEDS_TIDY_AND_REST "${TESTNAME}")
    STRING(REGEX MATCH "http_client" HTTP_CLIENT "${TESTNAME}")
    IF(NEEDS_REST OR NEEDS_TIDY_AND_REST OR HTTP_CLIENT)
      SET(SKIP_TEST 1)
    ENDIF()
  ENDIF(NOT ZORBA_WITH_REST)

  IF(NOT SKIP_TEST)

    IF(ZORBA_USE_SEPARATE_WINCE_SVN)
      ADD_TEST(${TESTNAME} ${TESTDRIVER_EXE_PATH} ${CMAKE_CURRENT_BINARY_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/${TESTFILE})
    ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
      ZORBA_ADD_TEST_ALLSTORES("${TESTNAME}" testdriver ${TESTFILE})
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

# --------------------------------------------------------------------------
# the list of tests that are failing but can be accepted by the commit queue
# !!! do not abuse this list or you will be prosecuted !!!
EXPECTED_FAILURE(test/rbkt/zorba/xqddf/admin 2935047)
EXPECTED_FAILURE(test/rbkt/zorba/xqddf/ic-uniqueKey-err2 2935047)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_first/delete_nodes_collection_005 2945266)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_first/delete_nodes_collection_006 2945266)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_first/delete_nodes_collection_007 2945266)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_first/delete_nodes_collection_008 2945266)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_first/delete_nodes_collection_const_2 2945266)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_first/delete_nodes_collection_append_only_2 2945266)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_last/delete_nodes_collection_005 2945271)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_last/delete_nodes_collection_006 2945271)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_last/delete_nodes_collection_007 2945271)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_last/delete_nodes_collection_008 2945271)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_last/delete_nodes_collection_const_2 2945271)
EXPECTED_FAILURE(test/rbkt/zorba/collections/delete_nodes_last/delete_nodes_collection_append_only_2 2945271)

EXPECTED_FAILURE(test/rbkt/zorba/xqddf/daniel/i3 0)
EXPECTED_FAILURE(test/rbkt/zorba/xqddf/daniel/i4 0)
EXPECTED_FAILURE(test/rbkt/zorba/xqddf/daniel/i5 0)
EXPECTED_FAILURE(test/rbkt/zorba/xqddf/daniel/t5 0)
# --------------------------------------------------------------------------
