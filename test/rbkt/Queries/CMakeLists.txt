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
INCLUDE(ZorbaAddTest)

FILE(GLOB_RECURSE TESTFILES FOLLOW_SYMLINKS 
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.xq")
IF(ZORBA_TEST_XQUERYX)
  FILE(GLOB_RECURSE TESTFILES_XQX FOLLOW_SYMLINKS 
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS "*.xqx")
  IF (TESTFILES_XQX)
    LIST(APPEND TESTFILES ${TESTFILES_XQX})
  ENDIF (TESTFILES_XQX)
ENDIF(ZORBA_TEST_XQUERYX)

LIST(REMOVE_ITEM TESTFILES
# Remove when bug #3071699 is fixed
  zorba/HigherOrder/hof-101.xq

# Remove when bug #3276383 is fixed
  zorba/converters/html/tidy_1.xq
  zorba/converters/html/tidy_2.xq
  zorba/converters/html/tidy_3.xq
  zorba/converters/html/tidy_4.xq
  zorba/converters/html/tidy_5_wrong_options.xq
  zorba/converters/html/tidy_6_wrong_options.xq
  zorba/http_client/http-head.xq
  zorba/http_client/http-options.xq
  zorba/http_client/http-read-html-tidy2.xq
  zorba/http_client/http1-read.xq
  zorba/http_client/http1-redirect.xq
  zorba/http_client/http1.xq
  zorba/http_client/http2-read-base64.xq
  zorba/http_client/http2-read-html-tidy.xq
  zorba/http_client/http2-read-html.xq
  zorba/http_client/http2-read-override.xq
  zorba/http_client/http2-read-status-only.xq
  zorba/http_client/http2-read-svg.xq
  zorba/http_client/http3-multipart.xq
  zorba/http_client/http3-post.xq
  zorba/http_client/http3-simple.xq
  zorba/http_client/http4_tidy_applied.xq
  zorba/http_client/http_error_hc001.xq
  zorba/http_client/http_error_hc002.xq
  zorba/http_client/http_error_hc004.xq
  zorba/http_client/http_error_hc005.xq
  zorba/http_client/http_tidy1.xq
  zorba/http_client/http_tidy2.xq
  zorba/spec/xquery_1_0.xq
  zorba/webservices/google/book-search-xml.xq
  zorba/webservices/google/directions-xml.xq
  zorba/webservices/google/directions.xq
  zorba/webservices/google/isbn.xq
  zorba/webservices/google/youtube-category-search-xml.xq
  zorba/webservices/google/youtube-category-search.xq
  zorba/webservices/google/youtube-search-xml.xq
  zorba/webservices/google/youtube-search.xq
  zorba/webservices/mailchimp/login.xq
  zorba/webservices/mailchimp/subscribe.xq
  zorba/webservices/yahoo/geocode-xml.xq
  zorba/webservices/yahoo/location-xml.xq
  zorba/webservices/yahoo/longitude-latitude.xq
  zorba/webservices/yahoo/map-xml.xq
  zorba/webservices/yahoo/map.xq
  zorba/webservices/yahoo/spelling-xml.xq
  zorba/webservices/yahoo/spelling.xq
  zorba/webservices/yahoo/traffic-report-xml.xq
  zorba/webservices/yahoo/traffic-report.xq
  zorba/webservices/yahoo/weather-xml.xq
  zorba/webservices/yahoo/weather.xq
  zorba/webservices/yahoo/woeid-xml.xq
  zorba/webservices/yahoo/woeid.xq
  zorba/xmlrpc/advogato.xq

# Remove when bug #3276383 and #3152386 are BOTH fixed
  zorba/http_client/external_variable.xq

# Remove when bug #3276383 and #3106635 are BOTH fixed
  zorba/spec/xquery_1_1.xq
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
    ZORBA_ADD_TEST_ALLSTORES("${TEST_NAME}" testdriver ${CHAINED_TESTS_FILES})


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

# TODO : this has to be removed after the converters modules are taken outside Zorba
INCLUDE (${CMAKE_SOURCE_DIR}/cmake_modules/FindJansson.cmake)

FOREACH(TESTFILE ${TESTFILES})
  # All testfile paths end in .xq or .xqx. Strip that part off to form
  # the test name.
  STRING(REGEX REPLACE "\\.[xq]*$" "" TESTNAME "${TESTFILE}")
  SET(TESTNAME "test/rbkt/${TESTNAME}")

  # Skip tests that we don't have the pre-requisites for.
  # This seems like an error-prone manual way to do this...
  SET(SKIP_TEST 0)
  IF(NOT ZORBA_WITH_REST)
    # These tests require rest 
    STRING(REGEX MATCH "aleXis/q(10|8)" NEEDS_TIDY_AND_REST "${TESTNAME}")
    STRING(REGEX MATCH "http_client" HTTP_CLIENT "${TESTNAME}")
    IF(NEEDS_REST OR NEEDS_TIDY_AND_REST OR HTTP_CLIENT)
      SET(SKIP_TEST 1)
    ENDIF(NEEDS_REST OR NEEDS_TIDY_AND_REST OR HTTP_CLIENT)
  ENDIF(NOT ZORBA_WITH_REST)
  #at the moment we do not check for ZORBA_WITH_REST cmake param
  #also we check for libtidy also because is it is not present HTTP module is not build
  IF (NOT CURL_FOUND)
    STRING(REGEX MATCH "http_client|oauth|webservices" HTTP_CLIENT "${TESTNAME}")
    IF(HTTP_CLIENT)
      SET(SKIP_TEST 1)
    ENDIF(HTTP_CLIENT)
  ENDIF(NOT CURL_FOUND)
  
  IF(NOT Jansson_FOUND)
    STRING(REGEX MATCH "jansson" JANSSON "${TESTNAME}")
    IF(JANSSON)
      SET(SKIP_TEST 1)
    ENDIF(JANSSON)
  ENDIF(NOT Jansson_FOUND)

  IF(NOT ZORBA_WITH_FILE_ACCESS)
    #these tests require the file module
    STRING(REGEX MATCH "file/" NEEDS_FILE "${TESTNAME}")
    IF(NEEDS_FILE)
      SET(SKIP_TEST 1)
    ENDIF(NEEDS_FILE)
  ENDIF(NOT ZORBA_WITH_FILE_ACCESS)
  IF (TESTNAME MATCHES "^test/rbkt/w3c_testsuite")
    SET (FOUND_XQTS 1)
    IF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)
      # If this is an XQTS test and we want to use testdriver_mt instead,
      # don't add the traditional testdriver version, but remember that
      # we found some
      SET (SKIP_TEST 1)
    ENDIF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)
  ENDIF (TESTNAME MATCHES "^test/rbkt/w3c_testsuite")
  IF (ZORBA_NO_FULL_TEXT)
    STRING(REGEX MATCH "fulltext/" NEEDS_FULL_TEXT "${TESTNAME}")
    IF (NEEDS_FULL_TEXT)
      SET (SKIP_TEST 1)
    ENDIF (NEEDS_FULL_TEXT)
  ENDIF (ZORBA_NO_FULL_TEXT)
  # Check if ImageMagick libraries are found, if not then skip tests
  IF (NOT ImageMagick_Magick++_FOUND OR
      NOT ImageMagick_MagickCore_FOUND OR
      NOT ImageMagick_MagickWand_FOUND)
    STRING(REGEX MATCH "image/" NEEDS_MAGICK "${TESTNAME}")
    IF (NEEDS_MAGICK)
      SET (SKIP_TEST 1)
    ENDIF (NEEDS_MAGICK)
  ENDIF (NOT ImageMagick_Magick++_FOUND OR
         NOT ImageMagick_MagickCore_FOUND OR
         NOT ImageMagick_MagickWand_FOUND)

  # If WordNet thesaurus not found, skip ft-thesaurus-true tests
  IF (NOT ZORBA_WORDNET_FOUND)
    STRING(REGEX MATCH "zorba/fulltext/ft-thesaurus-true" NEEDS_WORDNET
      "${TESTNAME}")
    IF (NEEDS_WORDNET)
      SET (SKIP_TEST 1)
    ENDIF (NEEDS_WORDNET)
  ENDIF (NOT ZORBA_WORDNET_FOUND)

  IF(NOT SKIP_TEST)

    ZORBA_ADD_TEST_ALLSTORES("${TESTNAME}" testdriver ${TESTFILE})

    MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
    MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
    IF (${TESTMOD})
      MESSAGE(STATUS "Adding another 1000 Tests")
      SET(TESTCOUNTER 0)
    ENDIF (${TESTMOD})

  ENDIF(NOT SKIP_TEST)

ENDFOREACH(TESTFILE)

SET(ZORBA_TEST_W3C_TO_SUBMIT_RESULTS ON CACHE BOOL "Bool var that says if w3c testing results are to be submited to w3c, or just for internal testing. If they are for internal testing then we can mark some failing tests as expected results.")
MARK_AS_ADVANCED(ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)

IF (FOUND_XQTS)

  IF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)

    MESSAGE (STATUS "Adding multi-threaded XQTS test")
    ZORBA_ADD_TEST_SIMPLE(xqts testdriver_mt -q -b w3c_testsuite
      -k "${CMAKE_CURRENT_SOURCE_DIR}/w3c_known_failures.txt")

  ELSE (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)
    
    IF(ZORBA_TEST_XQUERYX)
      IF(NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)
        #double utf-8 encoding in the xml xqueryx
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/EncodeURIfunc/K-EncodeURIfunc-4 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/EscapeHTMLURIFunc/K-EscapeHTMLURIFunc-5 PROPERTIES WILL_FAIL TRUE)

        #difference in dealing whitespaces: new line in xml xqueryx is converted to &#xA;
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/Construct/DirectConElem/DirectConElemAttr/Constr-attr-ws-1 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/Construct/DirectConElem/DirectConElemAttr/Constr-attr-ws-2 PROPERTIES WILL_FAIL TRUE)
    
        #test seems to be correct, only that it slightly differs from the original xquery test
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/Operators/CompExpr/ValComp/DurationDateTimeOp/gYearEQ/op-gYear-equal-2 PROPERTIES WILL_FAIL TRUE)
    
        #test seems to be correct, only that it slightly differs from the original xquery test
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/BaseURIProlog/base-URI-13 PROPERTIES WILL_FAIL TRUE)

        #test seems to be correct, only that it slightly differs from the original xquery test (empty least instead of empty greatest)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-10 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-11 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-12 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-13 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-2 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-24 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-25 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-26 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-27 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-3 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-4 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/EmptyOrderProlog/emptyorderdecl-5 PROPERTIES WILL_FAIL TRUE)
    
        #test result is correct; version encoding is specified in a comment and ignored
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/VersionProlog/K-VersionProlog-3 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/VersionProlog/K-VersionProlog-4 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/PrologExpr/VersionProlog/version_declaration-010 PROPERTIES WILL_FAIL TRUE)

        #test seems to be correct, only that it slightly differs from the original xquery test
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/seqExprTypes/SeqExprCast/K2-SeqExprCast-2 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/seqExprTypes/SeqExprCastable/K-SeqExprCastable-21 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Expressions/seqExprTypes/SeqExprCastable/K-SeqExprCastable-36 PROPERTIES WILL_FAIL TRUE)
  
        #double utf-8 encoding in the xml xqueryx
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Functions/AllStringFunc/AssDisassStringFunc/StringToCodepointFunc/fn-string-to-codepoints1args-4 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Functions/AllStringFunc/EscapingFuncs/EncodeURIfunc/fn-encode-for-uri1args-2 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Functions/AllStringFunc/EscapingFuncs/EscapeHTMLURIFunc/fn-escape-html-uri1args-2 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/Functions/AllStringFunc/EscapingFuncs/IRIToURIfunc/fn-iri-to-uri1args-2 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/StringToCodepointFunc/K-StringToCodepointFunc-12 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/StringToCodepointFunc/K-StringToCodepointFunc-19 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/StringToCodepointFunc/K-StringToCodepointFunc-20 PROPERTIES WILL_FAIL TRUE)
        SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/XQueryX/StringToCodepointFunc/K-StringToCodepointFunc-21 PROPERTIES WILL_FAIL TRUE)

      ENDIF(NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)
    ENDIF(ZORBA_TEST_XQUERYX)

    EXPECTED_FAILURE(test/rbkt/w3c_testsuite/XQuery/Optional/Serialization/K2-Serialization-7 3145280)

  ENDIF (ZORBATEST_TESTDRIVER_MT_AVAILABLE AND ZORBATEST_USE_MT_XQTS)

ENDIF (FOUND_XQTS)


# --------------------------------------------------------------------------
# the list of tests that are failing but can be accepted by the commit queue
# !!! do not abuse this list or you will be prosecuted !!!

# This is not a bug, this is working per spec
# The ##other means any other namespace but it MUST have a namespace
# todo: comment next lines after remote queue fixed
IF(NOT WIN32)
  EXPECTED_FAILURE(test/rbkt/zorba/schemas/any 3137594)
ENDIF(NOT WIN32)

EXPECTED_FAILURE(test/rbkt/zorba/modules/schema 3131554)

EXPECTED_FAILURE(test/rbkt/zorba/xqddf/admin 2935047)
EXPECTED_FAILURE(test/rbkt/zorba/xqddf/ic-uniqueKey-err2 2935047)

# removed temporarely
#IF(WIN32)
#  EXPECTED_FAILURE(test/rbkt/zorba/converters/json/json_parse7 3193250)
#ENDIF(WIN32)

EXPECTED_FAILURE(test/rbkt/zorba/aleXis/q11 3103700)

EXPECTED_FAILURE(test/rbkt/zorba/eval/eval_schema2 00001)

