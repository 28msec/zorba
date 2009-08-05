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

ADD_EXECUTABLE(updtestdriver ${UPDTESTDRIVER_SRCS})
TARGET_LINK_LIBRARIES(updtestdriver zorba_simplestore)

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(updtestdriver_static ${UPDTESTDRIVER_SRCS})
  SET_TARGET_PROPERTIES(updtestdriver_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
  TARGET_LINK_LIBRARIES(updtestdriver_static zorba_simplestore_static)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

IF(WIN32)
SET(updtestdriver_EXE_PATH    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/updtestdriver)
ELSE(WIN32)
SET(updtestdriver_EXE_PATH    updtestdriver)
ENDIF(WIN32)

# collect all spec files (suffix .spec) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ FOLLOW_SYMLINKS "*.spec")

MESSAGE(STATUS "Adding update tests for CTest $TESTFILES")
SET(TESTCOUNTER 0)

FOREACH(TESTFILE ${TESTFILES})

 STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
 MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-5' )
 STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

 IF (NOT TESTFILE MATCHES ".*XQueryX.*" OR ZORBA_TEST_XQUERYX )

   #add prefix if xqueryx test
   IF (TESTFILE MATCHES ".*XQueryX.*")
     SET(TESTNAME "xqueryx_test/update/${TESTNAME}")
   ELSE (TESTFILE MATCHES ".*XQueryX.*")
     SET(TESTNAME "test/update/${TESTNAME}")
   ENDIF (TESTFILE MATCHES ".*XQueryX.*")

   ADD_TEST("${TESTNAME}" ${updtestdriver_EXE_PATH} ${TESTFILE})
   SET_TESTS_PROPERTIES ("${TESTNAME}" PROPERTIES TIMEOUT "5")

   MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
   MATH(EXPR TESTMOD "${TESTCOUNTER}/100")
   IF (${TESTMOD})
     MESSAGE(STATUS "Adding another 100 update tests")
     SET(TESTCOUNTER 0)
   ENDIF (${TESTMOD})

 ENDIF (NOT TESTFILE MATCHES ".*XQueryX.*" OR ZORBA_TEST_XQUERYX )
                
ENDFOREACH(TESTFILE)
