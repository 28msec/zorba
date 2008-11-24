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
# configure and compile the testdriver
CONFIGURE_FILE(parsertestdriverconfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/parsertestdriverconfig.h)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ADD_EXECUTABLE(parsertestdriver parsertestdriver.cpp)
TARGET_LINK_LIBRARIES(parsertestdriver zorba_simplestore)

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(parsertestdriver_static parsertestdriver.cpp)
  TARGET_LINK_LIBRARIES(parsertestdriver_static zorba_simplestore_static)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

IF(WIN32)
SET(PARSERTESTDRIVER_EXE_PATH    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/parsertestdriver)
ELSE(WIN32)
SET(PARSERTESTDRIVER_EXE_PATH    parsertestdriver)
ENDIF(WIN32)

# collect all queries (suffix .xq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ *.xq)

MESSAGE(STATUS "Adding parser tests for CTest")

FOREACH(TESTFILE ${TESTFILES})
 STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
 MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-3' )
 STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

 ADD_TEST(${TESTNAME} ${PARSERTESTDRIVER_EXE_PATH} ${TESTFILE})

 IF (${TESTFILE} MATCHES "fail")
  SET_TESTS_PROPERTIES (${TESTNAME} PROPERTIES
    TIMEOUT "10"
    WILL_FAIL TRUE
  )
 ELSE (${TESTFILE} MATCHES "fail")
  SET_TESTS_PROPERTIES (${TESTNAME} PROPERTIES
    TIMEOUT "10"
    FAIL_REGULAR_EXPRESSION "no parsenode root generated"
  )
 ENDIF (${TESTFILE} MATCHES "fail")

ENDFOREACH(TESTFILE)
