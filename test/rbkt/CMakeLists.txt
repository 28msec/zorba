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
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/test/commons)

SET (TESTDRIVER_SRCS
  testdriver.cpp
  testdriver_common.cpp
  ${CMAKE_SOURCE_DIR}/test/commons/testdriver_comparator.cpp
  ${CMAKE_SOURCE_DIR}/test/commons/testuriresolver.cpp
  )

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateStoreSpecificExes.cmake)
ZORBA_GENERATE_STORE_SPECIFIC_EXES("testdriver" "${TESTDRIVER_SRCS}" "" "" "")


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
  ${CMAKE_SOURCE_DIR}/test/commons/testdriver_comparator.cpp
  ${CMAKE_SOURCE_DIR}/test/commons/testuriresolver.cpp
  )

ADD_EXECUTABLE(testdriver_mt ${TESTDRIVER_MT_SRCS})

TARGET_LINK_LIBRARIES(testdriver_mt
                      zorba_simplestore
                      boost_filesystem-mt)

IF (ZORBA_BUILD_STATIC_LIBRARY)

  ADD_EXECUTABLE(testdriver_mt_static testdriver_mt.cpp)

  SET_TARGET_PROPERTIES(testdriver_mt_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)

  TARGET_LINK_LIBRARIES(testdriver_mt_static
                        zorba_simplestore_static
                        boost_filesystem-mt)

ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

ENDIF(ZORBA_BUILD_MT_TESTDRIVER)


#
#
#
INCLUDE(ZorbaAddTest)
IF (NOT NO_CTEST)
  ADD_SUBDIRECTORY(Queries)
ENDIF (NOT NO_CTEST)
