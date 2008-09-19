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

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/external) 

#
# only platform headers and configuration stuff is in there
#
ADD_SUBDIRECTORY(common)
ADD_SUBDIRECTORY(zorbamisc)



################################################################################
#                                                                              #
# Build the common libraries, i.e., the ones required by both the query        #
# processor and the store: zorbatypes, zorbaerrors, and zorbautils.            #
#                                                                              #
################################################################################

ADD_SUBDIRECTORY(zorbautils)

ADD_SUBDIRECTORY(zorbatypes)

ADD_SUBDIRECTORY(zorbaerrors)


################################################################################
#                                                                              #
# Build the store library (or libraries)                                       #
#                                                                              #
################################################################################

ADD_SUBDIRECTORY(store)


################################################################################
#                                                                              #
# Build the zorba library                                                      #
#                                                                              #
################################################################################

#
# Get all libraries that libzorba depends on
#
SET(requiredlibs-zorba ${requiredlibs-zorba} zorbautils)
SET(requiredlibs-zorba ${requiredlibs-zorba} zorbatypes)
SET(requiredlibs-zorba ${requiredlibs-zorba} zorbaerrors)


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
ADD_SRC_SUBFOLDER(ZORBA_SRCS errors	ERRORS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS functions FUNCTIONS_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS runtime RUNTIME_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS types TYPES_SRCS)
ADD_SRC_SUBFOLDER(ZORBA_SRCS util UTIL_SRCS)

IF (ZORBA_DEBUGGER)
  ADD_SRC_SUBFOLDER(ZORBA_SRCS debugger DEBUGGER_SRCS)
ENDIF (ZORBA_DEBUGGER)


SET(ZORBA_LIBRARY_INSTALL_LIST)

#
# Build the Zorba SHARED library
#
ADD_LIBRARY(zorba SHARED ${ZORBA_SRCS})

TARGET_LINK_LIBRARIES(zorba ${requiredlibs-zorba})

SET_TARGET_PROPERTIES(zorba PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

SET_TARGET_PROPERTIES(zorba PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET(ZORBA_LIBRARY_INSTALL_LIST ${ZORBA_LIBRARY_INSTALL_LIST} zorba)

#
# Build the Zorba STATIC library
#
IF (ZORBA_BUILD_STATIC_LIBRARY)

  ADD_LIBRARY(zorba_static STATIC ${ZORBA_SRCS})

  TARGET_LINK_LIBRARIES(zorba_static ${requiredlibs-zorba})

  SET_TARGET_PROPERTIES(zorba_static PROPERTIES OUTPUT_NAME "zorba")  

  SET_TARGET_PROPERTIES(zorba_static PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  

  SET_TARGET_PROPERTIES(zorba_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)  

  SET(ZORBA_LIBRARY_INSTALL_LIST ${ZORBA_LIBRARY_INSTALL_LIST} zorba_static)

ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

#
# Specify where the zorba libs are to be installed
#
INSTALL(TARGETS ${ZORBA_LIBRARY_INSTALL_LIST}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

#install external packages in Mac OS X package
IF ( APPLE )
  FOREACH(LIB ${Zorba_ICUUC} ${Zorba_ICUI18N} ${Zorba_ICU_DATA} ${Zorba_XERCESC})
    STRING(STRIP ${LIB} LIBNAME)
    MESSAGE(STATUS "installing ${LIBNAME}")
    INSTALL(FILES ${LIBNAME} DESTINATION lib)
  ENDFOREACH(LIB)
ENDIF ( APPLE )
