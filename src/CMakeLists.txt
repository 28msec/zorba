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
# First, collect all the libraries that zorba lib depends on
#

SET(requiredlibs-zorba)

#
# cURL
#    
FIND_PACKAGE(CURL)
IF(CURL_FOUND)
  MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
  SET(requiredlibs-zorba ${requiredlibs-zorba} ${CURL_LIBRARIES})  
  INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIRS})
ELSE(CURL_FOUND)
  MESSAGE(STATUS "The cURL library was not found.")
ENDIF(CURL_FOUND)

#
# Iconv
#
INCLUDE(${CMAKE_MODULE_PATH}/FindIconv.cmake)
FIND_PACKAGE(Iconv)
IF (Iconv_FOUND)
    INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})
    SET(requiredlibs-zorba ${requiredlibs-zorba} ${ICONV_LIBRARY})
ENDIF (Iconv_FOUND)

#
# Xerces-C
#
INCLUDE(${CMAKE_MODULE_PATH}/FindXercesC.cmake)
IF (XERCESC_FOUND)
	INCLUDE_DIRECTORIES(${XERCESC_INCLUDE})
	SET(requiredlibs-zorba ${requiredlibs-zorba} ${XERCESC_LIBRARY})
ENDIF (XERCESC_FOUND)

#
# Json
#
IF (ZORBA_DEBUGGER)
  SET(requiredlibs-zorba ${requiredlibs-zorba} json)
ENDIF (ZORBA_DEBUGGER)

#
# Boost
#
SET(BOOST_CHECK_LIBRARIES ON CACHE BOOL "enable or disable automatic search of boost libraries")
MESSAGE(STATUS "BOOST_CHECK_LIBRARIES:     " ${BOOST_CHECK_LIBRARIES})

IF (BOOST_CHECK_LIBRARIES)

INCLUDE(${CMAKE_MODULE_PATH}/FindBoost.cmake)
SET (REQUIRED_BOOST_PACKAGES date_time filesystem program_options)
IF (ZORBA_DEBUGGER)
  SET(REQUIRED_BOOST_PACKAGES ${REQUIRED_BOOST_PACKAGES} boost_thread)
ENDIF (ZORBA_DEBUGGER)

FIND_PACKAGE(Boost REQUIRED COMPONENTS
  date_time
  filesystem
  program_options)

IF (NOT Boost_FOUND)
  MESSAGE(FATAL "Boost not found")
ELSE (NOT Boost_FOUND)
  MESSAGE(STATUS "Found Boost: ${Boost_INCLUDE_DIRS}")
  MESSAGE(STATUS "      Boost: ${Boost_LIBRARY_DIRS}")

  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
  IF (NOT WIN32)
      IF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
          SET(BOOST_PROGRAM_OPTIONS   boost_program_options-mt)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_program_options-mt)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_date_time-mt)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_filesystem-mt)
          IF (34 LESS ${Boost_MINOR_VERSION})
            MESSAGE(STATUS "Boost minor version is greater than 34")
            SET(requiredlibs-zorba ${requiredlibs-zorba} boost_system-mt)
          ENDIF (34 LESS ${Boost_MINOR_VERSION})
      ELSE (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
          SET(BOOST_PROGRAM_OPTIONS   boost_program_options)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_program_options)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_date_time)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_filesystem)
          IF (34 LESS ${Boost_MINOR_VERSION})
            MESSAGE(STATUS "Boost minor version is greater than 34")
            SET(requiredlibs-zorba ${requiredlibs-zorba} boost_system)
          ENDIF (34 LESS ${Boost_MINOR_VERSION})
          IF(ZORBA_DEBUGGER)
            SET(requiredlibs-zorba ${requiredlibs-zorba} boost_thread)
          ENDIF(ZORBA_DEBUGGER)
      ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  ELSE (NOT WIN32)
      IF (CYGWIN)
          SET(CMAKE_INCLUDE_PATH)            
          SET(BOOST_PROGRAM_OPTIONS   boost_program_options-gcc-mt)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_program_options-gcc-mt)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_date_time-gcc-mt)
          SET(requiredlibs-zorba ${requiredlibs-zorba} boost_filesystem-gcc-mt)
          IF (34 LESS ${Boost_MINOR_VERSION})
            MESSAGE(STATUS "Boost minor version is greater than 34")
            SET(requiredlibs-zorba ${requiredlibs-zorba} boost_system-gcc-mt)
          ENDIF (34 LESS ${Boost_MINOR_VERSION})
      ELSE (CYGWIN)
          IF(ZORBA_DEBUGGER)
	          SET(requiredlibs-zorba ${requiredlibs-zorba} WSock32)
          ENDIF(ZORBA_DEBUGGER)
  	  ENDIF (CYGWIN)
  ENDIF (NOT WIN32)
ENDIF (NOT Boost_FOUND)

ENDIF (BOOST_CHECK_LIBRARIES)

#
# Pthreads
#
IF (HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)
  SET(requiredlibs-zorba ${requiredlibs-zorba} pthread)
ENDIF (HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)


#
# Internal common libraries
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
IF (MSVC)
  ADD_LIBRARY(zorba ${ZORBA_SRCS})
ELSE (MSVC)
  ADD_LIBRARY(zorba SHARED ${ZORBA_SRCS})
ENDIF (MSVC)

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
