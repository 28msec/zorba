# Copyright 2006-2013 The FLWOR Foundation.
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

# configure the testdrivers
IF (WIN32)
  SET(CMAKE_SOURCE_DIR_URI file:///${CMAKE_SOURCE_DIR})
  SET(CMAKE_BINARY_DIR_URI file:///${CMAKE_BINARY_DIR})
ELSE (WIN32)
  SET(CMAKE_SOURCE_DIR_URI file://${CMAKE_SOURCE_DIR})
  SET(CMAKE_BINARY_DIR_URI file://${CMAKE_BINARY_DIR})
ENDIF (WIN32)

CONFIGURE_FILE(testdriverconfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/testdriverconfig.h)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})


#
# Compile and build the testdriver executable
#
SET (TESTDRIVER_SRCS
  testdriver.cpp
  testdriver_common.cpp
  testdriver_comparator.cpp
  testuriresolver.cpp
  )

ZORBA_GENERATE_EXE("testdriver" "${TESTDRIVER_SRCS}" "" "" "bin")

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

  SET (TESTDRIVER_MT_SRCS
    testdriver_mt.cpp
    testdriver_common.cpp
    testdriver_comparator.cpp
    testuriresolver.cpp
    )
   
   SET (REQUIRED_LIBS ${Boost_LIBRARIES})
   
   IF(ZORBA_HAVE_PTHREAD_H AND Boost_SYSTEM_FOUND)
     SET(REQUIRED_LIBS ${REQUIRED_LIBS} pthread)
   ENDIF(ZORBA_HAVE_PTHREAD_H AND Boost_SYSTEM_FOUND)
    
  ZORBA_GENERATE_EXE(
    "testdriver_mt" "${TESTDRIVER_MT_SRCS}" "${REQUIRED_LIBS}" "" "")

  SET (ZORBATEST_USE_MT_XQTS NO CACHE BOOLEAN
    "If true, use testdriver_mt (when available) for running XQTS")
  MARK_AS_ADVANCED (ZORBATEST_USE_MT_XQTS)

ENDIF (ZORBATEST_TESTDRIVER_MT_AVAILABLE)

# Compile and build the update testdriver executable
SET(UPDTESTDRIVER_SRCS
    updtestdriver.cpp
    testdriver_comparator.cpp
    testuriresolver.cpp)
ZORBA_GENERATE_EXE("updtestdriver" "${UPDTESTDRIVER_SRCS}" "" "" "")

# Compile and build the SAX2 test driver executable
SET (SAX2_TESTDRIVER_SRCS
  sax2testdriver.cpp
  ${CMAKE_SOURCE_DIR}/test/driver/testdriver_comparator.cpp
  )

ZORBA_GENERATE_EXE(sax2testdriver "${SAX2_TESTDRIVER_SRCS}" "" "" "")
