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

SET(ZORBA_TEST_PLAN_SERIALIZATION OFF CACHE BOOL "Activate testing of plan serialization")
MESSAGE(STATUS "ZORBA_TEST_PLAN_SERIALIZATION:                " ${ZORBA_TEST_PLAN_SERIALIZATION})

SET(ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY OFF CACHE BOOL "Test only the load and execution of serialized plan")
MESSAGE(STATUS "ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY: " ${ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY})

SET(ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY OFF CACHE BOOL "Test only compiling the xquery")
MESSAGE(STATUS "ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY:   " ${ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY})

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/test)
INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateExe.cmake)

ADD_SUBDIRECTORY(api)
ADD_SUBDIRECTORY(rbkt)
ADD_SUBDIRECTORY(extern)

ADD_SUBDIRECTORY(unit)
ADD_SUBDIRECTORY(parser)
ADD_SUBDIRECTORY(update)
ADD_SUBDIRECTORY(sax2)

SET (TEST_PLAN_SERIALIZER_SRCS
    test_plan_serializer.cpp
    timer.cpp)

#
# apitest
#
ZORBA_GENERATE_EXE("apitest" "apitest.cpp" "" "" "")

ZORBA_GENERATE_EXE("test_plan_serializer" "${TEST_PLAN_SERIALIZER_SRCS}" "" "" "")
  
ZORBA_GENERATE_EXE("path_test" "path_test.cpp" "" "" "")
  
ZORBA_ADD_TEST (test/fspathbranch1 path_test --branch-path /d1/d2/../d3/.)
ZORBA_SET_TEST_PROPERTY (test/fspathbranch1 PASS_REGULAR_EXPRESSION /d1)
  
ZORBA_ADD_TEST (test/fspathbranch2 path_test --branch-path /dir)
ZORBA_SET_TEST_PROPERTY (test/fspathbranch2 PASS_REGULAR_EXPRESSION /)
  
ZORBA_ADD_TEST (test/fspath1 path_test --path /../d1/./././././././../..)
ZORBA_SET_TEST_PROPERTY (test/fspath1 PASS_REGULAR_EXPRESSION /)
  
ZORBA_ADD_TEST (test/fspath2 path_test --path d1/d2/../../../../d3//)
ZORBA_SET_TEST_PROPERTY (test/fspath2 PASS_REGULAR_EXPRESSION ../../d3)

# External testsuites
ADD_SUBDIRECTORY(testsuites)
