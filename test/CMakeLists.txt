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

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/zorba_test_setting.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/zorba_test_setting.h)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/zorba_test_setting.h.cmake -->${CMAKE_CURRENT_BINARY_DIR}/zorba_test_setting.h")

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/test)
INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

ADD_SUBDIRECTORY(rbkt)
ADD_SUBDIRECTORY(unit)
ADD_SUBDIRECTORY(parser)
ADD_SUBDIRECTORY(update)
ADD_SUBDIRECTORY(sax2)
#IF(ZORBA_DEBUGGER)
#  ADD_SUBDIRECTORY(debugger)
#ENDIF(ZORBA_DEBUGGER)
IF(ZORBA_USE_SEPARATE_WINCE_SVN)
  ADD_SUBDIRECTORY(w3c_testsuite)
ENDIF(ZORBA_USE_SEPARATE_WINCE_SVN)
  

#
# apitest
#
SET(API_TEST_SRCS
    apitest.cpp)

SET(requiredlibs-apitest-shared ${requiredlibs-apitest} zorba ${STORE_LIB})

ADD_EXECUTABLE(apitest ${API_TEST_SRCS})

TARGET_LINK_LIBRARIES(apitest ${requiredlibs-apitest-shared})

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(apitest_static ${API_TEST_SRCS})
  TARGET_LINK_LIBRARIES(apitest_static ${requiredlibs-apitest} zorba_static
  ${STORE_LIB})
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

IF(NOT ZORBA_MINIMAL_STORE)
#
# test_store
#
SET(TEST_STORE_SRCS
    timer.cpp
    test_store.cpp)

SET(requiredlibs-teststore ${requiredlibs-teststore} ${STORE_LIB})

ADD_EXECUTABLE(test_store ${TEST_STORE_SRCS})

TARGET_LINK_LIBRARIES(test_store ${requiredlibs-teststore})

ENDIF(NOT ZORBA_MINIMAL_STORE)

IF(NOT ZORBA_MINIMAL_STORE)
#
# test_ordpath
#
SET(TEST_ORDPATH_SRCS
    test_ordpath.cpp)

SET(requiredlibs-testordpath ${requiredlibs-testordpath} ${STORE_LIB})

#ADD_EXECUTABLE(test_ordpath ${TEST_ORDPATH_SRCS})

#TARGET_LINK_LIBRARIES(test_ordpath ${requiredlibs-testordpath})

ENDIF(NOT ZORBA_MINIMAL_STORE)
