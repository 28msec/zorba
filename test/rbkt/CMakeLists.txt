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

SET (TESTDRIVER_SRCS
  testdriver.cpp
  testdriver_common.cpp
  testuriresolver.cpp
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

#SET(ZORBA_BUILD_MT_TESTDRIVER 1)

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
  testuriresolver.cpp
  )

ADD_EXECUTABLE(testdriver_mt ${TESTDRIVER_MT_SRCS})

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


# Option to build test driver to use Saxon to compare results
#SET ( ZORBA_BUILD_SAXON_TESTDRIVER 1)	   
If ( ZORBA_BUILD_SAXON_TESTDRIVER )
   add_definitions ( -DENABLE_SAXON_COMPARE )
Endif ( ZORBA_BUILD_SAXON_TESTDRIVER )

#
#
#
MESSAGE(STATUS "Adding tests for CTest")

IF(NOT ZORBA_XQUERYX)
  SET(QueriesDir "Queries")
  SET(TestExtensions "*.xq")
  SET(TestPrefix "")
ELSE(NOT ZORBA_XQUERYX)
  #SET(QueriesDir "XQueryX")
  SET(QueriesDir "Queries")
  SET(TestExtensions "*.xqx")
  SET(TestPrefix "XQueryX/")
ENDIF(NOT ZORBA_XQUERYX)

# collect all queries (suffix .xq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/${QueriesDir}/ ${TestExtensions})

# collect all chained test queries (suffix .cxq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE CHAINED_TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/${QueriesDir}/ *.cxq)

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
		  LIST(APPEND CHAINED_TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${QueriesDir}/${CHAINED_TESTFILE})
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

  IF(ZORBA_USE_SEPARATE_WINCE_SVN)
    ADD_TEST(${TESTNAME} ${TESTDRIVER_EXE_PATH} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${QueriesDir}/${TESTFILE})
  ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
    ADD_TEST(${TESTNAME} ${TESTDRIVER_EXE_PATH} ${TESTFILE})
  ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)

  SET_TESTS_PROPERTIES (${TESTNAME} PROPERTIES TIMEOUT ${NORMAL_TIMEOUT_VALUE})

  MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
  MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
  IF (${TESTMOD})
    MESSAGE(STATUS "Adding another 1000 Tests")
    SET(TESTCOUNTER 0)
  ENDIF (${TESTMOD})

ENDFOREACH(TESTFILE)

IF(NOT ZORBA_XQUERYX)
SET_TESTS_PROPERTIES (test/rbkt/dblp/q0 PROPERTIES TIMEOUT "200")
SET_TESTS_PROPERTIES (test/rbkt/dblp/q1 PROPERTIES TIMEOUT "200")

SET_TESTS_PROPERTIES (test/rbkt/paths/path17 PROPERTIES TIMEOUT "200")

IF(ZORBA_NO_BIGNUMBERS)
  SET_TESTS_PROPERTIES (test/rbkt/Operations/ArithExpr/DurationArith/DayTimeDurationDivideDTD/DayTimeDurationDivideDTD1 PROPERTIES WILL_FAIL TRUE)
ENDIF(ZORBA_NO_BIGNUMBERS)

IF(ZORBA_NO_XMLSCHEMA)
  SET_TESTS_PROPERTIES (test/rbkt/schemas/userDefinedAtomicType01 PROPERTIES WILL_FAIL TRUE)
ENDIF(ZORBA_NO_XMLSCHEMA)

IF(ZORBA_NO_UNICODE)
  SET_TESTS_PROPERTIES (test/rbkt/string/CodepointToStringFunc/CodepointToStringFunc1 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/string/CompareFunc/CompareFunc3 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/string/StringToCodepointFunc/StringToCodepointFunc1 PROPERTIES WILL_FAIL TRUE)
ENDIF(ZORBA_NO_UNICODE)
ENDIF(NOT ZORBA_XQUERYX)

IF (EXISTS test/rbkt/w3c_testsuite)
  #these tests fail due to floating-point precision problems, see KNOWN_ISSUES.txt
  #2210842 (https://sourceforge.net/tracker/index.php?func=detail&aid=2210842&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Expressions/Operators/ArithExpr/NumericOpr/NumericAdd/K-NumericAdd-5 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Expressions/Operators/ArithExpr/NumericOpr/NumericAdd/K-NumericAdd-6 PROPERTIES WILL_FAIL TRUE)

  #2210787 (https://sourceforge.net/tracker/index.php?func=detail&aid=2210787&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeFunc/NodeNumberFunc/fn-numberulng1args-2 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeFunc/NodeNumberFunc/fn-numberulng1args-3 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeFunc/NodeNumberFunc/fn-numberflt1args-1 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeFunc/NodeNumberFunc/fn-numberflt1args-3 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeFunc/NodeNumberFunc/fn-numberlng1args-1 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeFunc/NodeNumberFunc/fn-numberlng1args-3 PROPERTIES WILL_FAIL TRUE)

  #2210779 (https://sourceforge.net/tracker/index.php?func=detail&aid=2210779&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/SeqFunc/AggregateSeqFunc/SeqAVGFunc/fn-avg-mix-args-013 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/SeqFunc/AggregateSeqFunc/SeqAVGFunc/fn-avg-mix-args-014 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/SeqFunc/AggregateSeqFunc/SeqAVGFunc/fn-avg-mix-args-015 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/SeqFunc/AggregateSeqFunc/SeqAVGFunc/fn-avg-mix-args-020 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/SeqFunc/AggregateSeqFunc/SeqAVGFunc/fn-avg-mix-args-022 PROPERTIES WILL_FAIL TRUE)

  #2204089 (https://sourceforge.net/tracker/index.php?func=detail&aid=2204089&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/SeqExprCastSI/casthcds9 PROPERTIES WILL_FAIL TRUE)

  #2210786 (https://sourceforge.net/tracker/index.php?func=detail&aid=2210786&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/SeqFunc/SeqDeepEqualFunc/fn-deep-equal-mix-args-019 PROPERTIES WILL_FAIL TRUE)

  #2205034 (https://sourceforge.net/tracker2/?func=detail&aid=2205034&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/SchemaImportProlog/schema-import-13 PROPERTIES WILL_FAIL TRUE)

  #2210851 (https://sourceforge.net/tracker2/?func=detail&aid=2210851&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Expressions/exprSeqTypes/SeqExprCast/CastFOCA0001-1 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Expressions/exprSeqTypes/SeqExprCast/CastFOCA0003-1 PROPERTIES WILL_FAIL TRUE)

  #these tests fail due ICU regullar expression use
  #2210801 (https://sourceforge.net/tracker/index.php?func=detail&aid=2210801&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/AllStringFunc/MatchStringFunc/MatchesFunc/caselessmatch08 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/AllStringFunc/MatchStringFunc/MatchesFunc/caselessmatch09 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/AllStringFunc/MatchStringFunc/MatchesFunc/caselessmatch10 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/AllStringFunc/MatchStringFunc/MatchesFunc/caselessmatch11 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/AllStringFunc/MatchStringFunc/MatchesFunc/caselessmatch14 PROPERTIES WILL_FAIL TRUE)

  #these test are failing due to ID/IDREF is not implemented
  #2210815 (https://sourceforge.net/tracker2/?func=detail&aid=2210815&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Expressions/Construct/ComputeCon/ConDocNode/Constr-docnode-constrmod-2 PROPERTIES WILL_FAIL TRUE)

  #2210823 (https://sourceforge.net/tracker2/?func=detail&aid=2210823&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Expressions/Construct/DirectConElem/DirectConElemContent/Constr-cont-constrmod-2 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Expressions/Construct/DirectConElem/DirectConElemContent/Constr-cont-constrmod-6 PROPERTIES WILL_FAIL TRUE)

  #2210813 (https://sourceforge.net/tracker2/?func=detail&aid=2210813&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-5 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-7 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-8 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-9 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-12 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-13 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-14 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-15 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-16 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-17 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-18 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-19 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-20 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-21 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-23 PROPERTIES WILL_FAIL TRUE)

  #2210809 (https://sourceforge.net/tracker2/?func=detail&aid=2210809&group_id=226244&atid=1067586)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-5 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-7 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-8 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-9 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-12 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-13 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-15 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-16 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-17 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-18 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-19 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-20 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-21 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-23 PROPERTIES WILL_FAIL TRUE)

  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-12 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-13 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-14 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-15 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-16 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-17 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-18 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-19 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-20 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-21 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-23 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-5 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-7 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-8 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-idref-9 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-5 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-7 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-8 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-9 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-12 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-13 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-14 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-15 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-16 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-17 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-18 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-19 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-20 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-21 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDREFFunc/fn-idref-dtd-23 PROPERTIES WILL_FAIL TRUE)

  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-12 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-13 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-15 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-16 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-17 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-18 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-19 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-20 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-21 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-23 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-5 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-7 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-8 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/MiscFunctions/fn-id-9 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-5 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-7 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-8 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-9 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-12 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-13 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-15 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-16 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-17 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-18 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-19 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-20 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-21 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/Functions/NodeSeqFunc/SeqIDFunc/fn-id-dtd-23 PROPERTIES WILL_FAIL TRUE)

  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/ConstructSI/Constr-compelem-constrmod-2 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (test/rbkt/w3c_testsuite/SchemaImport/ConstructSI/Constr-compelem-constrmod-6 PROPERTIES WILL_FAIL TRUE)

ENDIF (EXISTS test/rbkt/w3c_testsuite)
