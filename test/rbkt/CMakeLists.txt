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

# configure itertest
CONFIGURE_FILE(itertest.xq.in ${CMAKE_CURRENT_BINARY_DIR}/itertest.xq)

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
INCLUDE(ZorbaGenerateExe)
ZORBA_GENERATE_EXE("testdriver" "${TESTDRIVER_SRCS}" "" "" "bin")
SET_TARGET_PROPERTIES(testdriver PROPERTIES OUTPUT_NAME zorba-testdriver)


#
# Compile and build the multi-threaded testdriver executable, if boost
# available
#

FIND_PACKAGE(Boost COMPONENTS filesystem)
IF (NOT Boost_FILESYSTEM_FOUND)
  MESSAGE(STATUS "Boost filesystem or system component not found - not building multithreaded test driver")
ELSE (NOT Boost_FILESYSTEM_FOUND)
  MESSAGE(STATUS "Found Boost v${Boost_LIB_VERSION}: ${Boost_INCLUDE_DIRS}")
  MESSAGE(STATUS "      Boost lib path: ${Boost_LIBRARY_DIRS}")

  # Assume this is OK for the moment...
  SET (ZORBATEST_TESTDRIVER_MT_AVAILABLE TRUE)

  IF (Boost_MAJOR_VERSION EQUAL 1 AND Boost_MINOR_VERSION GREATER 34)
    # Boost 1.35 and above included a separate "system" component. In
    # at least some versions, filesystem depends on system - and the
    # Mac linker apparently does not figure this out. Therefore we
    # need to link it explicitly, which means we need to find it
    # first.
    FIND_PACKAGE(Boost COMPONENTS system)
    IF (NOT Boost_SYSTEM_FOUND)
      MESSAGE(STATUS "Did NOT find Boost SYSTEM component - not building multithreaded test driver")
      SET (ZORBATEST_TESTDRIVER_MT_AVAILABLE FALSE)
    ELSE (NOT Boost_SYSTEM_FOUND)
      SET (Boost_system_lib "boost_system-mt")
    ENDIF (NOT Boost_SYSTEM_FOUND)
    
  ENDIF (Boost_MAJOR_VERSION EQUAL 1 AND Boost_MINOR_VERSION GREATER 34)

ENDIF (NOT Boost_FILESYSTEM_FOUND)

IF (ZORBATEST_TESTDRIVER_MT_AVAILABLE)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

  SET (TESTDRIVER_MT_SRCS
    testdriver_mt.cpp
    testdriver_common.cpp
    ${CMAKE_SOURCE_DIR}/test/commons/testdriver_comparator.cpp
    ${CMAKE_SOURCE_DIR}/test/commons/testuriresolver.cpp
    )

  ZORBA_GENERATE_EXE(
    "testdriver_mt" "${TESTDRIVER_MT_SRCS}" "${Boost_LIBRARIES}" "" "")

  SET (ZORBATEST_USE_MT_XQTS NO CACHE BOOLEAN
    "If true, use testdriver_mt (when available) for running XQTS")
  MARK_AS_ADVANCED (ZORBATEST_USE_MT_XQTS)

ENDIF (ZORBATEST_TESTDRIVER_MT_AVAILABLE)

# The NO_CTEST variable can be set to 1 so that CMake does not search
# for and add most of the Zorba tests, to speed up building and
# compiling the project.
IF (NOT NO_CTEST)
  ADD_SUBDIRECTORY(Queries)
  ADD_SUBDIRECTORY(modules)
ENDIF (NOT NO_CTEST)
