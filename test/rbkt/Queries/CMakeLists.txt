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

# Compute results directory for testdriver
SET (_results_dir "${CMAKE_CURRENT_BINARY_DIR}/../QueryResults")

FILE(GLOB_RECURSE TESTFILES FOLLOW_SYMLINKS
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.xq" "*.jq")
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

  LIST(SORT CHAINED_TESTFILES)

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

    # Create directory for output, if it doesn't exit
    IF (NOT EXISTS "${_results_dir}/${CT}")
      FILE (MAKE_DIRECTORY "${_results_dir}/${CT}")
    ENDIF (NOT EXISTS "${_results_dir}/${CT}")

    # clear the list of testfiles, args and also the name of the test
    SET(CHAINED_TESTS_FILES)
    SET(ARGS)
    SET(TEST_NAME)
  ENDFOREACH(CT)
ENDIF(${cxqNO} STRGREATER "0")

# Flag to remember whether we found the XQTS here or not
SET(FOUND_XQTS 0)

# Flag to remember whether we found the XQFTTS here or not
SET(FOUND_XQFTTS 0)

# QQQ It's ugly that we have to re-run FIND_PACKAGE here (and hence
# have to re-check for ZORBA_SUPPRESS_XXX here). There should be some
# way to do the lookup just once - ideally by moving those tests which
# depend on module features into the modules themselves.

IF(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "ZORBA_SUPPRESS_CURL is true - not searching for cURL library")
ELSE(ZORBA_SUPPRESS_CURL)
  MESSAGE(STATUS "Looking for cURL")
  FIND_PACKAGE(CURL)
ENDIF(ZORBA_SUPPRESS_CURL)

# Set a flag if testdriver_mt was built
IF (TARGET testdriver_mt)
  SET (_testdriver_mt_available 1)
ELSE (TARGET testdriver_mt)
  SET (_testdriver_mt_available 0)
ENDIF (TARGET testdriver_mt)

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
    IF (_testdriver_mt_available AND ZORBATEST_USE_MT_XQTS)
      # If this is an XQTS test and we want to use testdriver_mt instead,
      # don't add the traditional testdriver version, but remember that
      # we found some
      SET (SKIP_TEST 1)
    ELSE (_testdriver_mt_available AND ZORBATEST_USE_MT_XQTS)
      SET (FOUND_XQTS 1)
    ENDIF (_testdriver_mt_available AND ZORBATEST_USE_MT_XQTS)
  ENDIF (TESTNAME MATCHES "^test/rbkt/w3c_testsuite")
  IF (ZORBA_NO_FULL_TEXT)
    STRING(REGEX MATCH "fulltext/" NEEDS_FULL_TEXT "${TESTNAME}")
    IF (NEEDS_FULL_TEXT)
      SET (SKIP_TEST 1)
    ENDIF (NEEDS_FULL_TEXT)
  ELSE (ZORBA_NO_FULL_TEXT)
    IF (TESTNAME MATCHES "^test/rbkt/w3c_full_text_testsuite")
      SET (FOUND_XQFTTS 1)
    ENDIF(TESTNAME MATCHES "^test/rbkt/w3c_full_text_testsuite")
  ENDIF (ZORBA_NO_FULL_TEXT)
  IF(TESTNAME MATCHES "w3c_testsuite/TestSources/")
    SET (SKIP_TEST 1)
  ENDIF(TESTNAME MATCHES "w3c_testsuite/TestSources/")
  IF(WIN32)
    #this test fails on Windows because cannot find ourlib.dll
    #bug 908062
    IF(${TESTNAME} MATCHES "test/rbkt/zorba/versioning/link1")
      SET(SKIP_TEST 1)
    ENDIF(${TESTNAME} MATCHES "test/rbkt/zorba/versioning/link1")
  ENDIF(WIN32)

  # If WordNet thesaurus not found, skip ft-thesaurus-true tests
  IF (NOT ZORBA_WITH_THESAURUS)
    STRING(REGEX MATCH "zorba/fulltext/ft-thesaurus-true" NEEDS_WORDNET
      "${TESTNAME}")
    IF (NEEDS_WORDNET)
      SET (SKIP_TEST 1)
    ENDIF (NEEDS_WORDNET)
  ENDIF (NOT ZORBA_WITH_THESAURUS)

  IF(NOT SKIP_TEST)

    ZORBA_ADD_TEST("${TESTNAME}" testdriver ${TESTFILE})

    # Create directory for output, if it doesn't exist
    GET_FILENAME_COMPONENT(_bucket_path ${TESTFILE} PATH)
    IF (NOT EXISTS "${_results_dir}/${_bucket_path}")
      FILE (MAKE_DIRECTORY "${_results_dir}/${_bucket_path}")
    ENDIF (NOT EXISTS "${_results_dir}/${_bucket_path}")

    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
    IF (${TESTMOD})
      MESSAGE(STATUS "Adding another 1000 Tests")
      SET(TESTCOUNTER 0)
    ENDIF (${TESTMOD})

  ENDIF(NOT SKIP_TEST)

ENDFOREACH(TESTFILE)

IF (_testdriver_mt_available AND ZORBATEST_USE_MT_XQTS AND
    IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/w3c_testsuite")
  MESSAGE (STATUS "Adding multi-threaded XQTS test")
  ZORBA_ADD_TEST(xqts-xquery testdriver_mt -q -b w3c_testsuite/XQuery
    -k "${CMAKE_CURRENT_SOURCE_DIR}/w3c_known_failures.txt")
  IF (ZORBA_TEST_XQUERYX)
    MESSAGE (STATUS "Adding multi-threaded XQTS-XQueryX test")
    ZORBA_ADD_TEST(xqts-xqx testdriver_mt -q -b w3c_testsuite/XQueryX
      -k "${CMAKE_CURRENT_SOURCE_DIR}/w3c_known_failures_XQueryX.txt")
  ENDIF (ZORBA_TEST_XQUERYX)
ENDIF (_testdriver_mt_available AND ZORBATEST_USE_MT_XQTS AND
  IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/w3c_testsuite")

SET(ZORBA_TEST_W3C_TO_SUBMIT_RESULTS OFF CACHE BOOL "Bool var that says if w3c testing results are to be submitted to w3c, or just for internal testing. If they are for internal testing then we can mark some failing tests as expected results.")
MARK_AS_ADVANCED(ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)

####
#### LibXML2 failures
####
EXPECTED_FAILURE (test/rbkt/zorba/flwor/flwor24 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/flwor/flwor25 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/flwor/flwor27 libxml2)	
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-01 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-02 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-03 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-04 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-05 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-06 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-09 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-10 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-11 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-13 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/fn-parse-xml-fragment-14 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-01 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-02 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-03 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-04 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-05 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-06 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-07 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-08 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-doctype-11 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-01 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-02 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-03 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-04 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-05 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-06 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-07 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-08 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-09 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-10 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-11 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-12 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-13 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-14 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-15 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-16 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-17 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-18 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-19 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-20 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-21 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-22 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-23 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-24 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-25 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-26 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-27 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-28 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-29 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-30 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-31 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-32 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-33 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-34 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-35 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-36 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-37 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-38 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-39 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-40 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-41 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-42 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-43 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-44 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-45 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-46 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-51 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-52 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-53 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-54 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-55 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-56 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-fragment-skip-root-57 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-03 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-04 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-05 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-12 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-13 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-14 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-15 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-20 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-31 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-32 libxml2)
EXPECTED_FAILURE (test/rbkt/zorba/parsing_and_serializing/parse-xml-fragment-33 libxml2)

####
#### Place any known W3C failures here, to be sure that they are picked
#### up correctly but do not mess up our submissions to the W3C:
####
IF (FOUND_XQTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)

  EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Functions/QNameFunc/NamespaceURIForPrefixFunc/K2-NamespaceURIForPrefixFunc-2 872732)

  # HoF incorrect results. Bug report is here -- https://www.w3.org/Bugs/Public/show_bug.cgi?id=12661
  EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Functions/HigherOrder/FoldRight/fold-right-006 12661)
  EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Functions/HigherOrder/FoldRight/fold-right-007 12661)

  # Incorrect expected error in HoF tests. W3C bug report -- https://www.w3.org/Bugs/Public/show_bug.cgi?id=12637
  EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Expressions/HigherOrder/hof-915 12637)
  EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Expressions/HigherOrder/hof-916 12637)  

  IF (NOT ZORBA_WITH_BIG_INTEGER)
    # These test will never pass without big integers beause the integers used
    # in the queries exceed a 63-bit signed integer.
    #EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/exprSeqTypes/SeqExprCast/K2-SeqExprCast-22 867059)
    #EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericLT/K2-NumericLT-1 867059)
    #EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericLT/K2-NumericLT-2 867059)
    #EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericGT/K2-NumericGT-1 867059)
    #EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQuery/Operators/CompExpr/ValComp/NumericComp/NumericGT/K2-NumericGT-2 867059)
  ENDIF (NOT ZORBA_WITH_BIG_INTEGER)

  # These tests fail because of the JSONiq extension which has array constructors.
  #EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Expressions/SeqExpr/FilterExpr/K-FilterExpr-4 3141592)
  #EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Expressions/SeqExpr/FilterExpr/K-FilterExpr-5 3141592)

  IF (ZORBA_TEST_XQUERYX)

    #EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQueryX/PathExpr/Steps/Steps-leading-lone-slash-8a 3408285)
    EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQueryX/Construct/DirectConElem/DirectConElemContent/K2-DirectConElemContent-27 909303)
    EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQueryX/Construct/DirectConElem/DirectConElemWhitespace/K2-DirectConElemWhitespace-25 909303)

    #w3c bug
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes011 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes012 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes013 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes014 3355019)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/StaticTyping/STPathExpr/STSteps/STAxes/ST-Axes015 3355019)

    # HoF incorrect results. Bug report is here -- https://www.w3.org/Bugs/Public/show_bug.cgi?id=12661
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/Functions/HigherOrder/FoldRight/fold-right-006 12661)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/Functions/HigherOrder/FoldRight/fold-right-007 12661)

    # Incorrect expected error in HoF tests. W3C bug report -- https://www.w3.org/Bugs/Public/show_bug.cgi?id=12637
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/Expressions/HigherOrder/hof-915 12637)
    EXPECTED_FAILURE (test/rbkt/w3c_testsuite/XQueryX/Expressions/HigherOrder/hof-916 12637)  

  ENDIF (ZORBA_TEST_XQUERYX)

ENDIF (FOUND_XQTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)


IF (FOUND_XQFTTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-SCORE/score-queries-results-q2 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-SCORE/score-queries-results-q6 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-SCORE/score-queries-results-q5 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-SCORE/score-queries-results-q4 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-SCORE/score-queries-results-q1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-SCORE/score-queries-results-q3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-SCORE/score-queries-results-q3b 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-FULL-TEXT-COMPOSABILITY/full-text-composability-queries-results-q1 987632)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-FULL-TEXT-COMPOSABILITY/full-text-composability-queries-results-q4 866926)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-XQUERY-XPATH-COMPOSABILITY/xquery-xpath-composability-queries-results-q9 866926)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-XQUERY-XPATH-COMPOSABILITY/xquery-xpath-composability-queries-results-q9b 866926)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-IGNORE/ignore-queries-results-q1 866924)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-IGNORE/ignore-queries-results-q4 866924)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-IGNORE/ignore-queries-results-q1b 866924)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/3.2-SearchTokensAndPhrases/ft-3.2-examples-q5 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/2.3.1-UsingWeightsWithinAScoredFTContainsExpr/examples-231-q1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/2.3-ScoreVariables/examples-23-q4 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/2.3-ScoreVariables/examples-23-q3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/2.3-ScoreVariables/examples-23-q2 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/2.3-ScoreVariables/examples-23-q5 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/2.3-ScoreVariables/examples-23-q1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/3.6.2-WindowSelection/unconstrained-examples-362-5 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Examples/3.6.2-WindowSelection/examples-362-5 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-Var2 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-Var1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-BadVar2 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-4 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-6 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-Var3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-6 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-Var2 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-2 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-BadVar1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-Var3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-5 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-5 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-Var1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-4 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-2 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-unconstrained-1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-4 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-unconstrained-3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-unconstrained-4 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-1 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-08 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-03 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-04 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-05 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-12 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-10 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-09 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-13 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-11 866907)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/FTWords/FTWordsValue-IntegerLiteral 866911)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/FTWords/FTWordsValue-DecimalLiteral 866911)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1d 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1g 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1h 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1e 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1g 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q2a 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1c 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1e 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1d 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1a 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1b 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1f 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1f 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q2b 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q3 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1h 866923)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTThesaurus/ft-3.4.3-expressions-q4 909375)

  #the bug #11950 is a W3C bug, http://www.w3.org/Bugs/Public/show_bug.cgi?id=11950
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-ACROSS/across-queries-results-q2 11950)
  EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQuery/UseCase/UseCase-ACROSS/across-queries-results-q2b 11950)
  
  IF(ZORBA_TEST_XQUERYX)
    #XQueryX failures
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-SCORE/score-queries-results-q2 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-SCORE/score-queries-results-q6 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-SCORE/score-queries-results-q5 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-SCORE/score-queries-results-q4 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-SCORE/score-queries-results-q1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-SCORE/score-queries-results-q3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-SCORE/score-queries-results-q3b 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-FULL-TEXT-COMPOSABILITY/full-text-composability-queries-results-q1 987632)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-FULL-TEXT-COMPOSABILITY/full-text-composability-queries-results-q4 866926)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-XQUERY-XPATH-COMPOSABILITY/xquery-xpath-composability-queries-results-q9 866926)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-XQUERY-XPATH-COMPOSABILITY/xquery-xpath-composability-queries-results-q9b 866926)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-IGNORE/ignore-queries-results-q1 866924)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-IGNORE/ignore-queries-results-q4 866924)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-IGNORE/ignore-queries-results-q1b 866924)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.2-SearchTokensAndPhrases/ft-3.2-examples-q5 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/2.3.1-UsingWeightsWithinAScoredFTContainsExpr/examples-231-q1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/2.3-ScoreVariables/examples-23-q4 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/2.3-ScoreVariables/examples-23-q3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/2.3-ScoreVariables/examples-23-q2 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/2.3-ScoreVariables/examples-23-q5 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/2.3-ScoreVariables/examples-23-q1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.6.2-WindowSelection/unconstrained-examples-362-5 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.6.2-WindowSelection/examples-362-5 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-Var2 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-Var1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-BadVar2 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-4 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-6 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-Var3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-6 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-Var2 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-2 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-BadVar1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-Var3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-5 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-5 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-unconstrained-Var1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-4 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-2 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/ForScoreExpr/ForScoreExpr-1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-unconstrained-1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-4 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-unconstrained-3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-unconstrained-4 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/FLWORExpr/LetScoreExpr/LetScoreExpr-1 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-08 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-03 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-04 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-05 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-12 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-10 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-09 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-13 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/PositionalFilters/FTScope/different-sentence-11 866907)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1d 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1g 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1h 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1e 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1g 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q2a 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1c 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1e 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1d 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1a 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1b 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1f 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q1f 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q2b 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-q3 866923)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/Weight/FTSelection-Weight-unconstrained-q1h 866923)

    #the bug #11950 is a W3C bug, http://www.w3.org/Bugs/Public/show_bug.cgi?id=11950
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-ACROSS/across-queries-results-q2 11950)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-ACROSS/across-queries-results-q2b 11950)

    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-STOP-WORD/stop-word-queries-results-q1b 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-STOP-WORD/stop-word-queries-results-q1 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-STOP-WORD/stop-word-queries-results-q3b 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-STOP-WORD/stop-word-queries-results-q3 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.4.7-StopWordOption/ft-5.2.11-examples-q5 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.4.7-StopWordOption/ft-5.2.11-examples-q4 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.4.3-ThesaurusOption/ft-3.4.3-examples-q1 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.4.3-ThesaurusOption/ft-3.4.3-examples-q2 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Examples/3.4.3-ThesaurusOption/ft-3.4.3-examples-q3 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/ftmatchoptions-q1 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/ftmatchoptions-q2 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-3.4.7-expressions-q5 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-5.2.11-expressions-q8 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-5.2.11-expressions-q7 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-3.4.7-expressions-q4 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-5.2.11-expressions-q4 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-5.2.11-expressions-q9 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-3.4.7-expressions-q9 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-3.4.7-expressions-q6 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-5.2.11-expressions-q2 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-3.4.7-expressions-q8 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-5.2.11-expressions-q6 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTStopWord/ft-5.2.11-expressions-q5 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTThesaurus/ft-3.4.3-expressions-q3 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTThesaurus/ft-3.4.3-expressions-q5 909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/Expressions/Operators/CompExpr/FTContainsExpr/FTSelection/MatchOptions/FTThesaurus/ft-3.4.3-expressions-q6 909375)

    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-FULL-TEXT-COMPOSABILITY/full-text-composability-queries-results-q3  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-FULL-TEXT-COMPOSABILITY/full-text-composability-queries-results-q3b  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q4  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q2  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q4b  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q1b  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q5  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q3b  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q2b  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q6  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q3  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q1  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q5b  909375)
    EXPECTED_FAILURE(test/rbkt/w3c_full_text_testsuite/XQueryX/UseCase/UseCase-THESAURUS/thesaurus-queries-results-q6b  909375)
  ENDIF(ZORBA_TEST_XQUERYX)

ENDIF (FOUND_XQFTTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)

# test that must fail to pass, to check testdriver BOM bug that gives false positives
EXPECTED_FAILURE (test/rbkt/zorba/testdriver/bom_bug 3381121)

# Bug 921624. If this test takes more than a couple seconds, it must be
# hitting w3.org for the DTD, which is bad.
SET_TESTS_PROPERTIES(test/rbkt/zorba/schemas/local-xhtml
  PROPERTIES TIMEOUT 10)
# Bug 867363. These should fail or pass quickly because HTTP download
# is disabled.
SET_TESTS_PROPERTIES(test/rbkt/zorba/uris/disable-http
  PROPERTIES TIMEOUT 10)
SET_TESTS_PROPERTIES(test/rbkt/zorba/uris/disable-http-2
  PROPERTIES TIMEOUT 10)


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
  EXPECTED_FAILURE(test/rbkt/zorba/file/createWriteReadDeleteSeries 866969)
  EXPECTED_FAILURE(test/rbkt/zorba/file/dirname_basename-03 1201635)
ENDIF(WIN32)

EXPECTED_FAILURE(test/rbkt/zorba/modules/schema 3131554)

EXPECTED_FAILURE(test/rbkt/zorba/xqddf/ic-uniqueKey-err2 2935047)

EXPECTED_FAILURE(test/rbkt/zorba/aleXis/q11 3103700)

EXPECTED_FAILURE(test/rbkt/zorba/xmlid/valid-ncname 1010728)

# Failing test due to the new scripting spec. The test should be
# removed as it does not make sense any longer
EXPECTED_FAILURE(test/rbkt/zorba/scripting/exit4 666)

EXPECTED_FAILURE(test/rbkt/zorba/versioning/import-chain2 3312333)
EXPECTED_FAILURE(test/rbkt/zorba/versioning/import-chain3 3312333)
EXPECTED_FAILURE(test/rbkt/zorba/versioning/import-chain4 3312333)

IF(NOT ZORBA_NO_ICU)
  IF ( ${ICU_VERSION} VERSION_LESS 4.0.0 )
    EXPECTED_FAILURE(test/rbkt/zorba/string/Regex/regex_m11 866874)
    EXPECTED_FAILURE(test/rbkt/zorba/string/Regex/regex_m40 866874)
    EXPECTED_FAILURE(test/rbkt/zorba/string/Regex/regex_m41 866874)
  ELSE ( ${ICU_VERSION} VERSION_LESS 4.0.0 )
    EXPECTED_FAILURE(test/rbkt/zorba/string/Regex/regex_err10 994610)
    EXPECTED_FAILURE(test/rbkt/zorba/string/Regex/regex_err15 866874)
  ENDIF ( ${ICU_VERSION} VERSION_LESS 4.0.0 )
ENDIF(NOT ZORBA_NO_ICU)

IF(ZORBA_NO_ICU)
  SET_TESTS_PROPERTIES(
                      test/rbkt/zorba/string/CodepointToStringFunc/UnicodeNormalization1
                      PROPERTIES WILL_FAIL TRUE)
ENDIF(ZORBA_NO_ICU)


# external variable default expected failures
EXPECTED_FAILURE(test/rbkt/zorba/ext_var/w3c/extvardef-014 923672) # not possible to set context item for rbkt tests
EXPECTED_FAILURE(test/rbkt/zorba/ext_var/w3c/extvardef-016 923686)

EXPECTED_FAILURE(test/rbkt/zorba/jsoniq/comment_01.jq 1067028)
EXPECTED_FAILURE(test/rbkt/zorba/jsoniq/comment_02.jq 1067028)
EXPECTED_FAILURE(test/rbkt/zorba/jsoniq/comment_03.jq 1067028)
EXPECTED_FAILURE(test/rbkt/zorba/jsoniq/comment_04.jq 1067028)
EXPECTED_FAILURE(test/rbkt/zorba/jsoniq/comment_05.jq 1067028)

EXPECTED_FAILURE(test/rbkt/zorba/json/json-invalid-option-parameter 1200089)

IF (NOT ZORBA_WITH_DEBUGGER)    
  SET_TESTS_PROPERTIES(test/rbkt/zorba/debugger/dmh/break_response_no_info                      
                      PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES(test/rbkt/zorba/debugger/dmh/break_response                      
                      PROPERTIES WILL_FAIL TRUE)
ENDIF (NOT ZORBA_WITH_DEBUGGER)