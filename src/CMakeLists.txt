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

INCLUDE(AddSrcSubfolder)

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
# the current binary dir must be before the current source dir in the list of included directories.
# Otherwise, the parser doesn't work correclty. Files like xquery_driver.cpp must depend on the 
# generated files if they exist!
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_BINARY_DIR})

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaRuntimeGenerator.cmake)

# Look for all spec files and generate the header and cpp files if out
# of date.  The cpp files and the according _impl.cpp files are added
# to the RUNTIME_SRCS list.
SET(SPEC_DIR "${CMAKE_SOURCE_DIR}/src/runtime/spec")
FILE(GLOB_RECURSE SPEC_FILES RELATIVE "${SPEC_DIR}" "${SPEC_DIR}/*.xml")

# remove the debug iterator if the debugger is not built
IF(NOT ZORBA_WITH_DEBUGGER)
  LIST(REMOVE_ITEM SPEC_FILES "debug/zorba_debug_iterator.xml")
ENDIF(NOT ZORBA_WITH_DEBUGGER)

# mappings.xml is only a helper xml file => don't generate any code for it
LIST(REMOVE_ITEM SPEC_FILES "mappings.xml")
LIST(REMOVE_ITEM SPEC_FILES "mappings-no-jsoniq.xml")

# sort the list such that all generated files are equal on all systems
LIST(SORT SPEC_FILES)

# Create generated file directories
SET(SPEC_BINARY_DIR "${CMAKE_BINARY_DIR}/src/runtime")
FOREACH (SPEC_FILE ${SPEC_FILES})
  GET_FILENAME_COMPONENT(DIR ${SPEC_FILE} PATH)
  SET(FULL_DIR "${SPEC_BINARY_DIR}/${DIR}")
  IF (NOT EXISTS "${FULL_DIR}")
    FILE(MAKE_DIRECTORY ${FULL_DIR})
    MESSAGE(STATUS "created directory ${FULL_DIR}")
  ENDIF (NOT EXISTS "${FULL_DIR}")
ENDFOREACH(SPEC_FILE)

################################################################################
#                                                                              #
# Build the zorba library                                                      #
#                                                                              #
################################################################################

#
# Next, add the files to be compiled into the library
#

SET(ZORBA_PRECOMPILED_HEADERS OFF CACHE BOOL "Activate Zorba precompiled headers.")

SET(ZORBA_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS api API_SRCS)

FOREACH (SRCS ${API_BUILD_SRCS})
  LIST(APPEND ZORBA_SRCS ${SRCS})
ENDFOREACH (SRCS)

ADD_SRC_SUBFOLDER(ZORBA_SRCS capi CAPI_SRCS )
ADD_SRC_SUBFOLDER(ZORBA_SRCS compiler COMPILER_SRCS)

FOREACH (SRCS ${COMPILER_BUILD_SRCS})
  LIST(APPEND ZORBA_SRCS ${SRCS})
ENDFOREACH (SRCS)

ADD_SRC_SUBFOLDER(ZORBA_SRCS system SYSTEM_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS context CONTEXT_SRCS)

FOREACH (SRCS ${CONTEXT_BUILD_SRCS})
  LIST(APPEND ZORBA_SRCS ${SRCS})
ENDFOREACH (SRCS)

ADD_SRC_SUBFOLDER(ZORBA_SRCS diagnostics DIAGNOSTICS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS functions FUNCTIONS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS annotations ANNOTATIONS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS runtime RUNTIME_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS types TYPES_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS util UTIL_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbaserialization ZORBASERIALIZATION_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbatypes ZORBATYPES_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbautils ZORBAUTILS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS store STORE_SRCS)
IF(ZORBA_WITH_DEBUGGER)
  ADD_SRC_SUBFOLDER(ZORBA_SRCS debugger DEBUGGER_SRCS)
ENDIF(ZORBA_WITH_DEBUGGER)
IF(ZORBA_WITH_UNIT_TESTS)
  ADD_SRC_SUBFOLDER(ZORBA_SRCS unit_tests UNIT_TEST_SRCS)
ENDIF(ZORBA_WITH_UNIT_TESTS)

MESSAGE(STATUS  "PRECOMPILED HEADERS: " ${ZORBA_PRECOMPILED_HEADERS})
IF(ZORBA_PRECOMPILED_HEADERS)
  ADD_SRC_SUBFOLDER(ZORBA_SRCS precompiled ZORBAMISC_SRCS)
  INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src/precompiled")
ELSE(ZORBA_PRECOMPILED_HEADERS)
  ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbamisc ZORBAMISC_SRCS)
  INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src/zorbamisc")
ENDIF(ZORBA_PRECOMPILED_HEADERS)

SET(ZORBA_LIBRARY_INSTALL_LIST)

# The standard uri resolver must know the store suffix that is added to the dynamically loaded
# module libs. This is done with the helper header file src/context/get_current_lib_suffix.h.in.
# This file contains the function get_current_lib_suffix. Its body is filed by the following cmake code:
SET(GET_CURRENT_LIB_SUFFIX_CODE "")
SET(EOL)
IF (WIN32)
  SET(EOL "\r\n")
ELSE (WIN32)
  SET(EOL "\n")
ENDIF (WIN32)
# adding an ifdef zorba_*_EXPRTS for each registered store
IF (${ZORBA_STORE_NAME} STREQUAL "simplestore")
  SET(GET_CURRENT_LIB_SUFFIX_CODE 
        "${GET_CURRENT_LIB_SUFFIX_CODE}\#ifdef zorba_${ZORBA_STORE_NAME}_EXPORTS${EOL}#define CURRENT_LIB_SUFFIX \"\";${EOL}\#endif${EOL}")
ELSE (${ZORBA_STORE_NAME} STREQUAL "simplestore")
  SET(GET_CURRENT_LIB_SUFFIX_CODE 
        "${GET_CURRENT_LIB_SUFFIX_CODE}\#ifdef zorba_${ZORBA_STORE_NAME}_EXPORTS${EOL}#define CURRENT_LIB_SUFFIX \"_${ZORBA_STORE_NAME}\";${EOL}\#endif${EOL}")
ENDIF (${ZORBA_STORE_NAME} STREQUAL "simplestore")


CONFIGURE_FILE(
  ${CMAKE_CURRENT_SOURCE_DIR}/context/get_current_lib_suffix.h.in 
  ${CMAKE_CURRENT_BINARY_DIR}/context/get_current_lib_suffix.h 
  @ONLY
)

SET(ZORBA_FAST_BUILD OFF CACHE BOOL "Activate Zorba fast build.")
IF(ZORBA_FAST_BUILD)
#construct one big cpp containing all zorba cpps
SET(BIG_ZORBA_CPP_CONTENT)
SET(BIG_ZORBA_CPP_CONTENT_RUNTIME)
SET(ZORBA_NEW_SRCS)
FOREACH(ZORBA_SRC ${ZORBA_SRCS})
  GET_FILENAME_COMPONENT(ZORBA_SRC_ABSOLUTE_PATH ${ZORBA_SRC} ABSOLUTE)
  IF(NOT EXISTS ${ZORBA_SRC_ABSOLUTE_PATH})
    SET(ZORBA_SRC_ABSOLUTE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_SRC}")
  ENDIF(NOT EXISTS ${ZORBA_SRC_ABSOLUTE_PATH})
  IF(${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "compiler/parser" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "[.]c$" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "debugger")
    LIST(APPEND ZORBA_NEW_SRCS ${ZORBA_SRC})
  ELSE(${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "compiler/parser" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "[.]c$" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "debugger")
    IF(NOT ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "[.]h")
      IF(${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/functions" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/runtime" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/context")
        SET(BIG_ZORBA_CPP_CONTENT_RUNTIME "${BIG_ZORBA_CPP_CONTENT_RUNTIME}#line 1 \"${ZORBA_SRC_ABSOLUTE_PATH}\";\n#include \"${ZORBA_SRC_ABSOLUTE_PATH}\";\n")
      ELSE(${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/functions" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/runtime" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/context")
        SET(BIG_ZORBA_CPP_CONTENT "${BIG_ZORBA_CPP_CONTENT}#line 1 \"${ZORBA_SRC_ABSOLUTE_PATH}\";\n#include \"${ZORBA_SRC_ABSOLUTE_PATH}\";\n")
      ENDIF(${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/functions" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/runtime" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "src/context")
    ENDIF(NOT ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "[.]h")
  ENDIF(${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "compiler/parser" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "[.]c$" OR ${ZORBA_SRC_ABSOLUTE_PATH} MATCHES "debugger")
ENDFOREACH(ZORBA_SRC ${ZORBA_SRCS})
SET(ZORBA_SRCS ${ZORBA_NEW_SRCS})
SET(BIG_ZORBA_CPP "${CMAKE_CURRENT_BINARY_DIR}/zorba_all1.cpp")
FILE(WRITE ${BIG_ZORBA_CPP} ${BIG_ZORBA_CPP_CONTENT})
IF(WIN32)
SET_SOURCE_FILES_PROPERTIES(${BIG_ZORBA_CPP} PROPERTIES COMPILE_FLAGS "/bigobj")
ENDIF(WIN32)
LIST(APPEND ZORBA_SRCS ${BIG_ZORBA_CPP})
SET(BIG_ZORBA_CPP "${CMAKE_CURRENT_BINARY_DIR}/zorba_all2.cpp")
FILE(WRITE ${BIG_ZORBA_CPP} ${BIG_ZORBA_CPP_CONTENT_RUNTIME})
IF(WIN32)
SET_SOURCE_FILES_PROPERTIES(${BIG_ZORBA_CPP} PROPERTIES COMPILE_FLAGS "/bigobj")
ENDIF(WIN32)
LIST(APPEND ZORBA_SRCS ${BIG_ZORBA_CPP})
ENDIF(ZORBA_FAST_BUILD)

########################
## PRECOMPILED HEADERS
########################
IF(WIN32 AND MSVC_IDE)
## SO FAR, ONLY TESTED ON WIN 32
IF(ZORBA_PRECOMPILED_HEADERS)

SET(BIG_ZORBA_H_CONTENT)
SET(BIG_ZORBA_H_CONTENT_RUNTIME)
SET(ZORBA_NEW_HEADERS)
ADD_DEFINITIONS("-DSTDAFX")
FOREACH(ZORBA_HEADER ${ZORBA_SRCS})
  GET_FILENAME_COMPONENT(ZORBA_HEADER_ABSOLUTE_PATH ${ZORBA_HEADER} ABSOLUTE)
  IF(NOT EXISTS ${ZORBA_HEADER_ABSOLUTE_PATH})
    SET(ZORBA_HEADER_ABSOLUTE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_HEADER}")
  ENDIF(NOT EXISTS ${ZORBA_HEADER_ABSOLUTE_PATH})

  IF(${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "[.]cpp")
    IF(${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "stdafx")
      SET_SOURCE_FILES_PROPERTIES(${ZORBA_HEADER_ABSOLUTE_PATH} PROPERTIES COMPILE_FLAGS "/Yc")
    ELSE(${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "stdafx")
      IF ((${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "socket.cpp") OR (${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "xquery_scanner.cpp") OR (${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "xquery_parser.cpp"))
      ELSE ((${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "socket.cpp") OR (${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "xquery_scanner.cpp") OR (${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "xquery_parser.cpp"))
        SET_SOURCE_FILES_PROPERTIES(${ZORBA_HEADER_ABSOLUTE_PATH} PROPERTIES COMPILE_FLAGS "/Yu")
      ENDIF ((${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "socket.cpp") OR (${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "xquery_scanner.cpp") OR (${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "xquery_parser.cpp"))
    ENDIF(${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "stdafx")
  ENDIF(${ZORBA_HEADER_ABSOLUTE_PATH} MATCHES "[.]cpp")
ENDFOREACH(ZORBA_HEADER ${ZORBA_HEADERS})

ENDIF(ZORBA_PRECOMPILED_HEADERS)
ENDIF(WIN32 AND MSVC_IDE)



MESSAGE(STATUS "processing store dir ${ZORBA_STORE_DIR} with name ${ZORBA_STORE_NAME}")

INCLUDE (${ZORBA_STORE_DIR}/CMakeLists.txt)     # side-effects!

SET(STORE_SRCS)
FOREACH (SRCS ${ZORBA_STORE_IMPL_SRCS})
  LIST(APPEND STORE_SRCS ${ZORBA_STORE_DIR}/${SRCS})
ENDFOREACH (SRCS ${ZORBA_STORE_IMPL_SRCS})

LIST(APPEND requiredlibs ${requiredlibs-store})
#
# Build the Zorba SHARED library
#
ADD_LIBRARY(zorba_${ZORBA_STORE_NAME} SHARED ${ZORBA_SRCS} ${STORE_SRCS})
LIST(APPEND ZORBA_LIBRARY_INSTALL_LIST zorba_${ZORBA_STORE_NAME})
TARGET_LINK_LIBRARIES(zorba_${ZORBA_STORE_NAME} ${requiredlibs})

SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_NAME} PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 0)
# INSTALL_NAME_DIR is a MacOS X-specific property that causes the
# "install_name" property of binaries to be corrected at "make install" time.
SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_NAME} PROPERTIES INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")

#
# Specify where the zorba libs are to be installed
# LIB_SUFFIX will be `64' on 64 bit processor
#
INSTALL(TARGETS ${ZORBA_LIBRARY_INSTALL_LIST}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib${LIB_SUFFIX}
  ARCHIVE DESTINATION lib
)

#
# Build the Zorba server
#
ADD_SUBDIRECTORY(server)