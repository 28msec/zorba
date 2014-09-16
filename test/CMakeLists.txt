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
INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateExe.cmake)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/driver)
ADD_SUBDIRECTORY(driver)
ADD_SUBDIRECTORY(api)
ADD_SUBDIRECTORY(iterators)
ADD_SUBDIRECTORY(rbkt)

IF(ZORBA_WITH_UNIT_TESTS)
  ADD_SUBDIRECTORY(extern)
ENDIF(ZORBA_WITH_UNIT_TESTS)

ADD_SUBDIRECTORY(unit)
ADD_SUBDIRECTORY(update)
ADD_SUBDIRECTORY(sax2)

ADD_SUBDIRECTORY(fots)

INSTALL(DIRECTORY fots_driver
        DESTINATION share/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

#ZORBA_GENERATE_EXE("ordpath_test" "test_ordpath.cpp" "" "" "")
