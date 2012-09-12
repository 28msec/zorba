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

# create the result directory for all tests
IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)

# configure the testdriver
CONFIGURE_FILE(testdriverconfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/testdriverconfig.h)

# Compile and build the testdriver executable
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/test/commons)

SET(UPDTESTDRIVER_SRCS
    updtestdriver.cpp
    ${CMAKE_SOURCE_DIR}/test/commons/testdriver_comparator.cpp
    ${CMAKE_SOURCE_DIR}/test/commons/testuriresolver.cpp)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateExe.cmake)
ZORBA_GENERATE_EXE("updtestdriver" "${UPDTESTDRIVER_SRCS}" "" "" "")

# collect all spec files (suffix .spec) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ FOLLOW_SYMLINKS "*.spec")

MESSAGE(STATUS "Adding update tests for CTest")
SET(TESTCOUNTER 0)

FOREACH(TESTFILE ${TESTFILES})

 STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
 MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-5' )
 STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

 IF (TESTNAME MATCHES "^w3c_update_testsuite")
   SET (FOUND_XQUTS 1)
 ENDIF (TESTNAME MATCHES "^w3c_update_testsuite")

 IF (NOT TESTFILE MATCHES ".*XQueryX.*" OR ZORBA_TEST_XQUERYX )

   SET(TESTNAME "test/update/${TESTNAME}")

   ZORBA_ADD_TEST("${TESTNAME}" updtestdriver ${TESTFILE})

   MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
   MATH(EXPR TESTMOD "${TESTCOUNTER}/100")
   IF (${TESTMOD})
     MESSAGE(STATUS "Adding another 100 update tests")
     SET(TESTCOUNTER 0)
   ENDIF (${TESTMOD})

 ENDIF (NOT TESTFILE MATCHES ".*XQueryX.*" OR ZORBA_TEST_XQUERYX )
                
ENDFOREACH(TESTFILE)

IF(ZORBA_NO_FULL_TEXT)
  SET_TESTS_PROPERTIES(
                      test/update/zorba/store/sc1
                      test/update/zorba/store/sc2_ex
                      PROPERTIES WILL_FAIL TRUE)
ENDIF(ZORBA_NO_FULL_TEXT)



IF (FOUND_XQUTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)
  # We "don't care" that these fail
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/Put/fn-put-005 3354993)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/Put/fn-put-004-fail 3354993)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/Put/fn-put-003-fail 3354993)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/Put/fn-put-006-fail 3354993)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/Prolog/RevalidationDeclaration/revalidation-declaration-01-fail 3354993)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/Prolog/RevalidationDeclaration/revalidation-declaration-03-fail 3354993)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/Prolog/RevalidationDeclaration/revalidation-declaration-05-fail 3354993)

  # We don't support the Update Static Typing feature
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-node-04 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-node-06 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-into-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-value-of-node-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-01 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-node-07 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-node-05 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-node-03 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-transform-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-into-04 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-delete-01 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-node-01 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-rename-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-transform-01 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-rename-03 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-rename-01 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-delete-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-value-of-node-01 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-after-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-after-03 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-replace-node-02 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-after-01 3354995)
  EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQuery/StaticTypingFeature/stf-insert-into-01 3354995)

  IF(ZORBA_TEST_XQUERYX)

    #copied from above, the expected failures for XQuery Update
    # We "don't care" that these fail
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/Put/fn-put-005 3354993)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/Put/fn-put-004-fail 3354993)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/Put/fn-put-003-fail 3354993)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/Put/fn-put-006-fail 3354993)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/Prolog/RevalidationDeclaration/revalidation-declaration-01-fail 3354993)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/Prolog/RevalidationDeclaration/revalidation-declaration-03-fail 3354993)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/Prolog/RevalidationDeclaration/revalidation-declaration-05-fail 3354993)

    # We don't support the Update Static Typing feature
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-node-04 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-node-06 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-into-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-value-of-node-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-01 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-node-07 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-node-05 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-node-03 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-transform-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-into-04 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-delete-01 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-node-01 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-rename-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-transform-01 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-rename-03 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-rename-01 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-delete-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-value-of-node-01 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-after-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-after-03 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-replace-node-02 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-after-01 3354995)
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/StaticTypingFeature/stf-insert-into-01 3354995)

    # W3C bug http://www.w3.org/Bugs/Public/show_bug.cgi?id=13259
    EXPECTED_FAILURE(test/update/w3c_update_testsuite/XQueryX/ValTrans/revalidate-valtrans-ins-003  0)
  ENDIF(ZORBA_TEST_XQUERYX)

ENDIF (FOUND_XQUTS AND NOT ZORBA_TEST_W3C_TO_SUBMIT_RESULTS)
