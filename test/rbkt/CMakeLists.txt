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

SET(requiredlibs-testdriver ${requiredlibs-testdriver} zorba ${STORE_LIB})

ADD_EXECUTABLE(testdriver testdriver.cpp)

TARGET_LINK_LIBRARIES(testdriver ${requiredlibs-testdriver})

#
# Compile and build the multi-threaded testdriver executable
#
#ADD_EXECUTABLE(testdriver_mt testdriver_mt.cpp)

#TARGET_LINK_LIBRARIES(testdriver_mt ${requiredlibs-testdriver})


#
# collect all queries (suffix .xq) in all subdirectories of the Queries dir
#
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ *.xq)


MESSAGE(STATUS "Adding tests for CTest")
SET(TESTCOUNTER 0)

FOREACH(TESTFILE ${TESTFILES})

 STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
 MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-3' )
 STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

IF(ZORBA_USE_SEPARATE_WINCE_SVN)
 ADD_TEST(${TESTNAME} testdriver ${CMAKE_CURRENT_SOURCE_DIR}/Queries/${TESTFILE} ${CMAKE_CURRENT_BINARY_DIR})
ELSE(ZORBA_USE_SEPARATE_WINCE_SVN)
 ADD_TEST(${TESTNAME} testdriver ${TESTFILE})
ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)
 
 SET_TESTS_PROPERTIES (${TESTNAME} PROPERTIES TIMEOUT "10")

 MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
 MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
 IF (${TESTMOD})
   MESSAGE(STATUS "Adding another 1000 Tests")
   SET(TESTCOUNTER 0)
 ENDIF (${TESTMOD})
                
ENDFOREACH(TESTFILE)

SET_TESTS_PROPERTIES (dblp/q0 PROPERTIES TIMEOUT "200")
SET_TESTS_PROPERTIES (dblp/q1 PROPERTIES TIMEOUT "200")

IF(ZORBA_NO_BIGNUMBERS)
  SET_TESTS_PROPERTIES (Operations/ArithExpr/DurationArith/DayTimeDurationDivideDTD/DayTimeDurationDivideDTD1 PROPERTIES WILL_FAIL TRUE)
ENDIF(ZORBA_NO_BIGNUMBERS)

IF(ZORBA_NO_XMLSCHEMA)
  SET_TESTS_PROPERTIES (schemas/userDefinedAtomicType01 PROPERTIES WILL_FAIL TRUE)
ENDIFIF(ZORBA_NO_XMLSCHEMA)

IF(ZORBA_NO_UNICODE)
  SET_TESTS_PROPERTIES (string/CodepointToStringFunc/CodepointToStringFunc1 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (string/CompareFunc/CompareFunc3 PROPERTIES WILL_FAIL TRUE)
  SET_TESTS_PROPERTIES (string/StringToCodepointFunc/StringToCodepointFunc1 PROPERTIES WILL_FAIL TRUE)
ENDIFIF(ZORBA_NO_UNICODE)
