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

INCLUDE(${CMAKE_MODULE_PATH}/AddSrcSubfolder.cmake)

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/external) 

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaRuntimeGenerator.cmake)

# look for all spec files and generate the header and cpp files if out of date
# the cpp files and the according _impl.cpp files are added to the RUNTIME_SRCS list
FILE(GLOB_RECURSE SPEC_FILES RELATIVE ${CMAKE_SOURCE_DIR}/src/runtime/spec "${CMAKE_SOURCE_DIR}/src/runtime/spec/*.xml")

# mappings.xml is only a helper xml file => don't generate any code for it
LIST(REMOVE_ITEM SPEC_FILES "mappings.xml")

# sort the list such that all generated files are equal on all systems
LIST(SORT SPEC_FILES)
SET(ABSOLUTE_SPEC_FILES)

# create the corresponding directories in the src/runtime/ build directory
IF (NOT EXISTS "${CMAKE_BINARY_DIR}/src/runtime/visitors")
  FILE(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/src/runtime/visitors")
  MESSAGE(STATUS "created directory ${CMAKE_BINARY_DIR}/src/runtime/visitors")
ENDIF (NOT EXISTS "${CMAKE_BINARY_DIR}/src/runtime/visitors")

IF (NOT EXISTS "${CMAKE_BINARY_DIR}/src/functions")
  FILE(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/src/functions")
  MESSAGE(STATUS "created directory ${CMAKE_BINARY_DIR}/src/functions")
ENDIF (NOT EXISTS "${CMAKE_BINARY_DIR}/src/functions")

FOREACH (SPEC_FILE ${SPEC_FILES})
  LIST(APPEND ABSOLUTE_SPEC_FILES "${CMAKE_SOURCE_DIR}/src/runtime/spec/${SPEC_FILE}")
  GET_FILENAME_COMPONENT(DIR ${SPEC_FILE} PATH)
  SET(FULL_DIR "${CMAKE_BINARY_DIR}/src/runtime/${DIR}")
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
SET(ZORBA_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS api API_SRCS )

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

ADD_SRC_SUBFOLDER(ZORBA_SRCS errors	ERRORS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS functions FUNCTIONS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS runtime RUNTIME_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS types TYPES_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS util UTIL_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbaserialization ZORBASERIALIZATION_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbatypes ZORBATYPES_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbaerrors ZORBAERRORS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS zorbautils ZORBAUTILS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS store STORE_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS debugger DEBUGGER_SRCS)

SET(ZORBA_LIBRARY_INSTALL_LIST)

# if you want a cross-platform approach to compile all zorba sources only once 
# you could extract the locations of previously built object files and insert them directly into
# the libraries that need them. This is documented in CMake Feature Request #5155:
# standard way to locate object files
FOREACH(ZORBA_STORE_DIR ${ZORBA_STORE_DIRS})
  MESSAGE(STATUS "processing store dir ${ZORBA_STORE_DIR}")

  INCLUDE (${ZORBA_STORE_DIR}/CMakeLists.txt) 		# side-effects!

  SET(STORE_SRCS)
  FOREACH (SRCS ${ZORBA_STORE_IMPL_SRCS})
    LIST(APPEND STORE_SRCS ${ZORBA_STORE_DIR}/${SRCS})
  ENDFOREACH (SRCS ${ZORBA_STORE_IMPL_SRCS})


  #
  # Build the Zorba SHARED library
  #
  ADD_LIBRARY(zorba_${ZORBA_STORE_LIB_EXTENSION} SHARED ${ZORBA_SRCS} ${STORE_SRCS})
  LIST(APPEND ZORBA_LIBRARY_INSTALL_LIST zorba_${ZORBA_STORE_LIB_EXTENSION})
  TARGET_LINK_LIBRARIES(zorba_${ZORBA_STORE_LIB_EXTENSION} ${requiredlibs})

  SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_LIB_EXTENSION} PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
  SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_LIB_EXTENSION} PROPERTIES CLEAN_DIRECT_OUTPUT 0)

  #
  # Build the Zorba STATIC library
  #
  IF (ZORBA_BUILD_STATIC_LIBRARY)

    ADD_LIBRARY(zorba_${ZORBA_STORE_LIB_EXTENSION}_static STATIC ${ZORBA_SRCS} ${STORE_SRCS})
    LIST(APPEND ZORBA_LIBRARY_INSTALL_LIST zorba_${ZORBA_STORE_LIB_EXTENSION}_static)
    SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_LIB_EXTENSION}_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
    SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_LIB_EXTENSION}_static PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
    SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_LIB_EXTENSION}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)  
    TARGET_LINK_LIBRARIES(zorba_${ZORBA_STORE_LIB_EXTENSION}_static ${requiredlibs})

    # on windows, the static lib needs a different name because .lib is already generated when creating the .dll 
    # on unix, the static library can have the same name because it uses a different file suffix (e.g. .a)
    IF (UNIX)
      SET_TARGET_PROPERTIES(zorba_${ZORBA_STORE_LIB_EXTENSION}_static PROPERTIES OUTPUT_NAME "zorba_${ZORBA_STORE_LIB_EXTENSION}")  
    ENDIF (UNIX)
  ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

ENDFOREACH(ZORBA_STORE_DIR ${ZORBA_STORE_DIRS})


#
# Specify where the zorba libs are to be installed
# LIB_SUFFIX will be `64' on 64 bit processor
#
INSTALL(TARGETS ${ZORBA_LIBRARY_INSTALL_LIST}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib${LIB_SUFFIX}
  ARCHIVE DESTINATION lib
)

#install external packages in Mac OS X package
IF ( APPLE )
  FOREACH(LIB ${Zorba_ICUUC} ${Zorba_ICUI18N} ${Zorba_ICU_DATA} ${Zorba_XERCESC} ${Zorba_XML2} )
    STRING(STRIP ${LIB} LIBNAME)
    MESSAGE(STATUS "Will install ${LIBNAME}")
    INSTALL(FILES ${LIBNAME} DESTINATION lib)
  ENDFOREACH(LIB)
ENDIF ( APPLE )
