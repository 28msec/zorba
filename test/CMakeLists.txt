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
MESSAGE(STATUS "ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY:                " ${ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY})

SET(ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY OFF CACHE BOOL "Test only compiling the xquery")
MESSAGE(STATUS "ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY:                " ${ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY})

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/zorba_test_setting.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/zorba_test_setting.h)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/zorba_test_setting.h.cmake -->${CMAKE_CURRENT_BINARY_DIR}/zorba_test_setting.h")

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/test)
INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

ADD_SUBDIRECTORY(rbkt)
#ADD_SUBDIRECTORY(new_tests)
IF (BUILDING_SIMPLESTORE)
  ADD_SUBDIRECTORY(unit)
  ADD_SUBDIRECTORY(parser)
  ADD_SUBDIRECTORY(update)
  ADD_SUBDIRECTORY(sax2)
ENDIF (BUILDING_SIMPLESTORE)

IF(ZORBA_USE_SEPARATE_WINCE_SVN)
  ADD_SUBDIRECTORY(w3c_testsuite)
#  ADD_SUBDIRECTORY(w3c_update_testsuite)
ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)
  

#
# apitest
#
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateStoreSpecificExes.cmake)
ZORBA_GENERATE_STORE_SPECIFIC_EXES("apitest" "" "" "")


IF (BUILDING_SIMPLESTORE)
  ADD_EXECUTABLE(path_test path_test.cpp)
  TARGET_LINK_LIBRARIES(path_test zorba_simplestore)
  
  IF (ZORBA_BUILD_STATIC_LIBRARY)
    ADD_EXECUTABLE(path_test_static path_test.cpp)
    SET_TARGET_PROPERTIES(path_test_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
    TARGET_LINK_LIBRARIES(path_test_static zorba_simplestore_static)
  ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

  INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaAddTest.cmake)
  
  ZORBA_ADD_TEST_SIMPLE (test/fspathbranch1 path_test --branch-path /d1/d2/../d3/.)
  SET_TESTS_PROPERTIES (test/fspathbranch1 PROPERTIES PASS_REGULAR_EXPRESSION /d1)
  
  ZORBA_ADD_TEST_SIMPLE (test/fspathbranch2 path_test --branch-path /dir)
  SET_TESTS_PROPERTIES (test/fspathbranch2 PROPERTIES PASS_REGULAR_EXPRESSION /)
  
  ZORBA_ADD_TEST_SIMPLE (test/fspath1 path_test --path /../d1/./././././././../..)
  SET_TESTS_PROPERTIES (test/fspath1 PROPERTIES PASS_REGULAR_EXPRESSION /)
  
  ZORBA_ADD_TEST_SIMPLE (test/fspath2 path_test --path d1/d2/../../../../d3//)
  SET_TESTS_PROPERTIES (test/fspath2 PROPERTIES PASS_REGULAR_EXPRESSION ../../d3)
  
ENDIF (BUILDING_SIMPLESTORE)

IF(NOT ZORBA_MINIMAL_STORE)
# 
# # test_store
# 
#  SET(TEST_STORE_SRCS
#      timer.cpp
#      test_store.cpp)
#  
#  ADD_EXECUTABLE(test_store ${TEST_STORE_SRCS})
#  
#  TARGET_LINK_LIBRARIES(test_store zorba_simplestore)
#  

# # test_index
# 
#  SET(TEST_INDEX_SRCS
#      test_index.cpp)
#  
#  ADD_EXECUTABLE(test_index ${TEST_INDEX_SRCS})
#  
#  TARGET_LINK_LIBRARIES(test_index zorba_simplestore)
  

#  # test_ordpath
#
#  SET(TEST_ORDPATH_SRCS
#      test_ordpath.cpp)
#  
#  SET(requiredlibs-testordpath ${requiredlibs-testordpath})
#  
#  ADD_EXECUTABLE(test_ordpath ${TEST_ORDPATH_SRCS})
#  
#  TARGET_LINK_LIBRARIES(test_ordpath zorba)
#  
ENDIF(NOT ZORBA_MINIMAL_STORE)
  
