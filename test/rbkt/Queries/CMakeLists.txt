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

IF(COMMAND cmake_policy AND POLICY CMP0009)
  CMAKE_POLICY(SET CMP0009 NEW)
ENDIF(COMMAND cmake_policy AND POLICY CMP0009)

MESSAGE(STATUS "Adding tests for CTest")

FILE(GLOB_RECURSE TESTFILES FOLLOW_SYMLINKS
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.xq")
IF(ZORBA_TEST_XQUERYX)
  FILE(GLOB_RECURSE TESTFILES_XQX FOLLOW_SYMLINKS
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS "*.xqx")
  IF (TESTFILES_XQX)
    LIST(APPEND TESTFILES ${TESTFILES_XQX})
  ENDIF (TESTFILES_XQX)
ENDIF(ZORBA_TEST_XQUERYX)

# Here we can remove some tests for which EXPECTED_FAILURE() is not
# appropriate. IF YOU THINK YOU WANT TO DO THIS, YOU ARE PROBABLY
# WRONG OR THERE IS A SERIOUS PROBLEM WITH THE BUILD SYSTEM.
# PLEASE DO NOT USE THIS MECHANISM IF AT ALL POSSIBLE.
# IF STILL NEEDED, GIVE THE CORRESPONDING BUG IMPORTANCE "CRITICAL"
# BECAUSE THIS HAS TO BE ADDRESSED ASAP.
LIST(REMOVE_ITEM TESTFILES

  # crashes on Windows: 866978, 866742 (fix 866978 before 866742)
  zorba/HigherOrder/hof-101.xq

  # fails because of the image external module's broken documentation
  # If you try to submit something else to the external module, it will
  # fail because of this test.
  # If you try and mark it as expected failure here, the "expected failure"
  # will fail because the image module will not be tested and therefore the
  # module documentation test will succeed.
  # Created bug 871335 for this.
  zorba/xqdoc/moduleDocumentation.xq
)

# collect all chained test queries (suffix .cxq) in all subdirectories
# of this dir
FILE(GLOB_RECURSE CHAINED_TESTFILES FOLLOW_SYMLINKS
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" FOLLOW_SYMLINKS "*.cxq")

SET(TESTCOUNTER 0)

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

  # foreach chained test create a list with all the test files and
  # sort it alphabetically
  FOREACH(CT ${CHAINED_TESTS_LIST})

    # create the name of the test and put it in TEST_NAME variable
    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    GET_FILENAME_COMPONENT(TF_DIR ${CT} NAME)
    SET(TEST_NAME "${TESTCOUNTER}_${TF_DIR}")

    #create the list of tests to be passed to the testdriver call
    FOREACH(CHAINED_TESTFILE ${CHAINED_TESTFILES})
      GET_FILENAME_COMPONENT(TF_PATH ${CHAINED_TESTFILE} PATH)
      IF(TF_PATH STREQUAL CT)
        GET_FILENAME_COMPONENT(TF_NAME ${CHAINED_TESTFILE} NAME)
        LIST(APPEND CHAINED_TESTS_FILES ${CHAINED_TESTFILE})
      ENDIF(TF_PATH STREQUAL CT)
    ENDFOREACH(CHAINED_TESTFILE)

    # sort the list of test files alphabetically
    LIST(SORT CHAINED_TESTS_FILES)

    SET(TEST_NAME "test/rbkt/${TEST_NAME}")

    # finally add the test
    ZORBA_ADD_TEST("${TEST_NAME}" testdriver ${CHAINED_TESTS_FILES})


    # clear the list of testfiles, args and also the name of the test
    SET(CHAINED_TESTS_FILES)
    SET(ARGS)
    SET(TEST_NAME)
  ENDFOREACH(CT)
ENDIF(${cxqNO} STRGREATER "0")

# Flag to remember whether we found the XQTS here or not
SET(FOUND_XQTS 0)

# QQQ It's ugly that we have to re-run FIND_PACKAGE here (and hence
# have to re-check for ZORBA_SUPPRESS_XXX here). There should be some
# way to do the lookup just once - ideally by moving those tests which
# depend on module features into the modules themselves.


# Check if WordNet thesaurus is installed in the location tests expect
IF(EXISTS "${CMAKE_BINARY_DIR}/test/rbkt/thesauri/wordnet-en.zth")
  SET(ZORBA_WORDNET_FOUND 1)
ENDIF(EXISTS "${CMAKE_BINARY_DIR}/test/rbkt/thesauri/wordnet-en.zth")

IF(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "ZORBA_SUPPRESS_CURL is true - not searching for cURL library")
ELSE(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "Looking for cURL")
  FIND_PACKAGE(CURL)
ENDIF(ZORBA_SUPPRESS_CURL)


FOREACH(TESTFILE ${TESTFILES})
  # All testfile paths end in .xq or .xqx. Strip that part off to form
  # the test name.
  STRING(REGEX REPLACE "\\.[xq]*$" "" TESTNAME "${TESTFILE}")
  SET(TESTNAME "test/rbkt/${TESTNAME}")

  # Skip tests that we don't have the pre-requisites for.
  # This seems like an error-prone manual way to do this...
  SET(SKIP_TEST 0)
  IF(NOT CURL_FOUND)
    STRING(REGEX MATCH "http_client|oauth" HTTP_CLIENT "${TESTNAME}")
    IF(HTTP_CLIENT)
      SET(SKIP_TEST 1)
    ENDIF(HTTP_CLIENT)
  ENDIF(NOT CURL_FOUND)

  IF(NOT ZORBA_WITH_FILE_ACCESS)
    #these tests require the file module
    STRING(REGEX MATCH "file/" NEEDS_FILE "${TESTNAME}")
    IF(NEEDS_FILE)
      SET(SKIP_TEST 1)
    ENDIF(NEEDS_FILE)
  ENDIF(NOT ZORBA_WITH_FILE_ACCESS)

  IF (TESTNAME MATCHES "^test/rbkt/w3c_testsuite")
    IF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)
      # If this is an XQTS test and we want to use testdriver_mt instead,
      # don't add the traditional testdriver version, but remember that
      # we found some
      SET (SKIP_TEST 1)
    ELSE (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)
      SET (FOUND_XQTS 1)
    ENDIF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)
  ENDIF (TESTNAME MATCHES "^test/rbkt/w3c_testsuite")
  IF (ZORBA_NO_FULL_TEXT)
    STRING(REGEX MATCH "fulltext/" NEEDS_FULL_TEXT "${TESTNAME}")
    IF (NEEDS_FULL_TEXT)
      SET (SKIP_TEST 1)
    ENDIF (NEEDS_FULL_TEXT)
  ENDIF (ZORBA_NO_FULL_TEXT)

  # If WordNet thesaurus not found, skip ft-thesaurus-true tests
  IF (NOT ZORBA_WORDNET_FOUND)
    STRING(REGEX MATCH "zorba/fulltext/ft-thesaurus-true" NEEDS_WORDNET
      "${TESTNAME}")
    IF (NEEDS_WORDNET)
      SET (SKIP_TEST 1)
    ENDIF (NEEDS_WORDNET)
  ENDIF (NOT ZORBA_WORDNET_FOUND)

  IF(NOT SKIP_TEST)

    ZORBA_ADD_TEST("${TESTNAME}" testdriver ${TESTFILE})

    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
    IF (${TESTMOD})
      MESSAGE(STATUS "Adding another 1000 Tests")
      SET(TESTCOUNTER 0)
    ENDIF (${TESTMOD})

  ENDIF(NOT SKIP_TEST)

ENDFOREACH(TESTFILE)

IF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS AND
    IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/w3c_testsuite")
  MESSAGE (STATUS "Adding multi-threaded XQTS test")
  ZORBA_ADD_TEST(xqts testdriver_mt -q -b w3c_testsuite
    -k "${CMAKE_CURRENT_SOURCE_DIR}/w3c_known_failures.txt")
ENDIF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS AND
  IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/w3c_testsuite")

SET(ZORBA_TEST_W3C_TO_SUBMIT_RESULTS OFF CACHE BOOL "Bool var that says if w3c testing results are to be submitted to w3c, or just for internal testing. If they are for internal testing then we can mark some failing tests as expected results.")
MARK_AS_ADVANCED(ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)

####
#### Place any known W3C failures here, to be sure that they are picked
#### up correctly but do not mess up our submissions to the W3C:
####
IF (FOUND_XQTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)

  EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/PathExpr/Steps/Steps-leading-lone-slash-8a 3408285)
  EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Functions/QNameFunc/NamespaceURIForPrefixFunc/K2-NamespaceURIForPrefixFunc-2 872732)

  IF(NOT ZORBA_WITH_BIG_INTEGER)
    # These tests fail due to integer overflow.
    EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericGT/K2-NumericGT-1 3323548)
    EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericGT/K2-NumericGT-2 3323548)
    EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericLT/K2-NumericLT-1 3323548)
    EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericLT/K2-NumericLT-2 3323548)
  ENDIF(NOT ZORBA_WITH_BIG_INTEGER)

  IF(ZORBA_TEST_XQUERYX)

    #w3c bug
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes011 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes012 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes013 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes014 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes015 3355019)
  ENDIF(ZORBA_TEST_XQUERYX)
  
  #this is marked as expected failure because the RQ uses XQTS_1_0_3. In that version the expected result is err:FODC0004 instead of err:FODC0002.
  #W3C has changed the expected result for this test in the meantime: please see http://www.w3.org/Bugs/Public/show_bug.cgi?id=12542
  EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Functions/NodeSeqFunc/SeqCollectionFunc/fn-collection-2 882002)

ENDIF (FOUND_XQTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)

# The dirname_basename test depends on the system module
#IF (NOT zorba_system_module_BINARY_DIR)
#  EXPECTED_FAILURE (test/rbkt/zorba/file/dirname_basename ????need bugnum???)
#ENDIF ()


# --------------------------------------------------------------------------
# the list of tests that are failing but can be accepted by the commit queue
# !!! do not abuse this list or you will be prosecuted !!!

# This test passes incorrectly with Xerces 2.8.0, so we have to mark
# them as expected_failures() in that case.  For now we assume that
# Xerces major version 2 doesn't work, and 3 does.  If we can
# determine more precisely when this bug was fixed, we should change
# this condition.
IF(XVERMAJ EQUAL 2)
  EXPECTED_FAILURE(test/rbkt/zorba/schemas/any 3137594)
  IF(NOT WIN32)
    EXPECTED_FAILURE(test/rbkt/zorba/eval/eval_schema2 3137594)
  ENDIF(NOT WIN32)
ENDIF(XVERMAJ EQUAL 2)

IF(WIN32)
  EXPECTED_FAILURE(test/rbkt/zorba/versioning/external1 870991)
  EXPECTED_FAILURE(test/rbkt/zorba/versioning/external2 870991)

  EXPECTED_FAILURE(test/rbkt/zorba/versioning/link1 871061)

  # this is still an expected failure but has been commented out since the
  # test is now completely disabled because of bug 871335
  #EXPECTED_FAILURE(test/rbkt/zorba/xqdoc/moduleDocumentation 871062)

  EXPECTED_FAILURE(test/rbkt/zorba/file/createWriteReadDeleteSeries 866969)
ENDIF(WIN32)


EXPECTED_FAILURE(test/rbkt/zorba/modules/schema 3131554)

EXPECTED_FAILURE(test/rbkt/zorba/xqddf/ic-uniqueKey-err2 2935047)

EXPECTED_FAILURE(test/rbkt/zorba/spec/xquery_1_1 3299356)

EXPECTED_FAILURE(test/rbkt/zorba/aleXis/q11 3103700)

# Failing test due to the new scripting spec. The test should be
# removed as it does not make sense any longer
EXPECTED_FAILURE(test/rbkt/zorba/scripting/exit4 666)

EXPECTED_FAILURE(test/rbkt/zorba/versioning/import-chain2 3312333)
EXPECTED_FAILURE(test/rbkt/zorba/versioning/import-chain3 3312333)
EXPECTED_FAILURE(test/rbkt/zorba/versioning/import-chain4 3312333)

EXPECTED_FAILURE(test/rbkt/zorba/http-client/put/put3_binary_element 3391756)
EXPECTED_FAILURE(test/rbkt/zorba/http-client/post/post3_binary_element 3391756)

EXPECTED_FAILURE(test/rbkt/zorba/reference/reference_5 868640)

IF (NOT ZORBA_NO_FULL_TEXT)
  EXPECTED_FAILURE(test/rbkt/zorba/fulltext/ft-same-sentence-true-4 900552)
ENDIF (NOT ZORBA_NO_FULL_TEXT)
