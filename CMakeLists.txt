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
#
# Project name
#
PROJECT(zorba)
ENABLE_TESTING()
INCLUDE(CTest)

cmake_minimum_required(VERSION 2.4)
IF(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)

IF("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
    SET(LINUX "${CMAKE_SYSTEM}")
ENDIF("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")

# custom ctest options
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/CTestCustom.cmake ${CMAKE_CURRENT_BINARY_DIR}/CTestCustom.cmake)

# prohibit in-source-builds
IF (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    MESSAGE(STATUS "In-source-builds are not allowed")
    MESSAGE(STATUS "Clean your source directory (e.g. delete the CMakeCache.txt file)")
    MESSAGE(FATAL_ERROR "Please create a separate build directory and call CMake again")
ENDIF (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})

# set the default build type to debug
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

################################################################################
# Variables

SET(DEFINITIONS)


################################################################################
# Setup Compiler Options

INCLUDE(CMakeCompiler.txt)


################################################################################
# Various cmake macros

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)


################################################################################
# Custom user-defined settings

INCLUDE ("CMakeUser.txt" OPTIONAL)


################################################################################
# Compiler setup

MESSAGE(STATUS "Build type -- " ${CMAKE_BUILD_TYPE})

# add the include dir (i.e. the library) to the include path
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_BINARY_DIR}/include)

# add cmake configuration (zorba options, etc.)
INCLUDE(CMakeConfiguration.txt)

# zorba versioning
SET(ZORBA_MAJOR_NUMBER "0")
SET(ZORBA_MINOR_NUMBER "9")
SET(ZORBA_PATCH_NUMBER "21")
SET(ZORBA_SVN_NUMER)
FILE(READ ${CMAKE_CURRENT_SOURCE_DIR}/svn_rev.txt ZORBA_SVN_NUMBER)
STRING(REGEX REPLACE "[^0-9]*([0-9]*)..*" "\\1" ZORBA_SVN_NUMBER ${ZORBA_SVN_NUMBER})
MESSAGE(STATUS "Zorba version number: " ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}-${ZORBA_SVN_NUMBER})

# add compiler vvariables
ADD_DEFINITIONS(${DEFINITIONS})


#################################################################################
#                                                                               #
# Search for all the external libraries that any library or executable under    #
#  this CMake depends on.                                                       #
#                                                                               #
#################################################################################


SET(requiredlibs-zorbautils)
SET(requiredlibs-zorbatypes)
SET(requiredlibs-zorbaerrors)
SET(requiredlibs-simplestore)
SET(requiredlibs-zorba)
SET(requiredlibs-apitest)
SET(requiredlibs-teststore)
SET(requiredlibs-testordpath)
SET(requiredlibs-testdriver)
SET(requiredlibs-zorbacmd)

#
#  LibXml2
#
FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)

    MESSAGE(STATUS "Found  LIBXML2 library -- " ${LIBXML2_LIBRARIES})
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

    SET(requiredlibs-simplestore ${requiredlibs-simplestore} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})

ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2 library is required in order to build simple store.")
ENDIF(LIBXML2_FOUND)


#
# Pthreads
#
IF (ZORBA_HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)
  SET(requiredlibs-zorbautils ${requiredlibs-zorbautils} pthread)
ENDIF (ZORBA_HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)


#
# cURL
#    
FIND_PACKAGE(CURL)
IF(CURL_FOUND)

  MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
  INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIRS})

  SET(requiredlibs-zorba ${requiredlibs-zorba} ${CURL_LIBRARIES})

ELSE(CURL_FOUND)
  MESSAGE(STATUS "The cURL library was not found.")
ENDIF(CURL_FOUND)


#
# Iconv
#
INCLUDE(${CMAKE_MODULE_PATH}/FindIconv.cmake)
FIND_PACKAGE(Iconv)

IF (Iconv_FOUND)

  MESSAGE(STATUS "Found Iconv library -- " ${ICONV_LIBRARIES})
  INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})

  SET(requiredlibs-zorba ${requiredlibs-zorba} ${ICONV_LIBRARY})

ELSE(Iconv_FOUND)
  MESSAGE(STATUS "The Iconv library was not found.")
ENDIF (Iconv_FOUND)


#
# ICU
#
INCLUDE(${CMAKE_MODULE_PATH}/FindICU.cmake)
  
IF (ICU_FOUND AND ICU_I18N_FOUND AND ICU_DATA_FOUND)

  INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})

  SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES} ${ICU_DATA_LIBRARIES}) 

ELSE (ICU_FOUND AND ICU_I18N_FOUND AND ICU_DATA_FOUND)
  MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")
ENDIF (ICU_FOUND AND ICU_I18N_FOUND AND ICU_DATA_FOUND)       


#
# Xerces-C
#
INCLUDE(${CMAKE_MODULE_PATH}/FindXercesC.cmake)
IF (XERCESC_FOUND)

	INCLUDE_DIRECTORIES(${XERCESC_INCLUDE})

  SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} ${XERCESC_LIBRARY})
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

      SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} boost_date_time-mt)
      SET(requiredlibs-zorba ${requiredlibs-zorba} boost_program_options-mt)
      SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_program_options-mt)
      SET(requiredlibs-apitest ${requiredlibs-apitest} boost_filesystem-mt)
      SET(requiredlibs-testordpath ${requiredlibs-testordpath} boost_filesystem-mt)
      SET(requiredlibs-testdriver ${requiredlibs-testdriver} boost_filesystem-mt)
      SET(requiredlibs-zorbacmd ${requiredlibs-zorbacmd} boost_filesystem-mt)

      IF (34 LESS ${Boost_MINOR_VERSION})
        MESSAGE(STATUS "Boost minor version is greater than 34")
        SET(requiredlibs-zorba ${requiredlibs-zorba} boost_system-mt)
      ENDIF (34 LESS ${Boost_MINOR_VERSION})

      IF(ZORBA_DEBUGGER)
        SET(requiredlibs-zorba ${requiredlibs-zorba} boost_thread-mt)
      ENDIF(ZORBA_DEBUGGER)

    ELSE (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

      SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} boost_date_time)
      SET(requiredlibs-zorba ${requiredlibs-zorba} boost_program_options)
      SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_program_options)
      SET(requiredlibs-apitest ${requiredlibs-apitest} boost_filesystem)
      SET(requiredlibs-testordpath ${requiredlibs-testordpath} boost_filesystem)
      SET(requiredlibs-testdriver ${requiredlibs-testdriver} boost_filesystem)
      SET(requiredlibs-zorbacmd ${requiredlibs-zorbacmd} boost_filesystem)

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
      SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} boost_date_time-gcc-mt)
      SET(requiredlibs-zorba ${requiredlibs-zorba} boost_program_options-gcc-mt)
      SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_program_options-gcc-mt)
      SET(requiredlibs-apitest ${requiredlibs-apitest} boost_filesystem-gcc-mt)
      SET(requiredlibs-testordpath ${requiredlibs-testordpath} boost_filesystem-gcc-mt)
      SET(requiredlibs-testdriver ${requiredlibs-testdriver} boost_filesystem-gcc-mt)
      SET(requiredlibs-zorbacmd ${requiredlibs-zorbacmd} boost_filesystem-gcc-mt)

      IF (34 LESS ${Boost_MINOR_VERSION})
        MESSAGE(STATUS "Boost minor version is greater than 34")
        SET(requiredlibs-zorba ${requiredlibs-zorba}  boost_system-gcc-mt)
      ENDIF (34 LESS ${Boost_MINOR_VERSION})

    ELSE (CYGWIN)

      IF(ZORBA_DEBUGGER)
	      SET(requiredlibs-zorba ${requiredlibs-zorba} WSock32)
      ENDIF(ZORBA_DEBUGGER)

  	ENDIF (CYGWIN)

  ENDIF (NOT WIN32)
ENDIF (NOT Boost_FOUND)

ENDIF (BOOST_CHECK_LIBRARIES)


################################################################################
#                                                                              #
# Tell CMake to process the sub-directories                                    #
#                                                                              #
################################################################################

IF(ZORBA_DEBUGGER)
  INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/external)
  ADD_SUBDIRECTORY(external)
ENDIF(ZORBA_DEBUGGER)

ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
IF(ZORBA_USE_SWIG)
  ADD_SUBDIRECTORY(swig)
ENDIF(ZORBA_USE_SWIG)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(bin)
ADD_SUBDIRECTORY(doc)
ADD_SUBDIRECTORY(scripts)

# add the uninstall support
CONFIGURE_FILE(
    "${CMAKE_CURRENT_SOURCE_DIR}/CMakeUninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeUninstall.cmake"
    @ONLY)
ADD_CUSTOM_TARGET(uninstall
    "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/CMakeUninstall.cmake")

INCLUDE(InstallRequiredSystemLibraries)

INCLUDE(CMakeCPack.cmake)
#CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/CPackSourceConfig.cmake.in 
#               ${CMAKE_BINARY_DIR}/CPackSourceConfig.cmake)

IF( APPLE )
  SET ( CMAKE_OSX_ARCHITECTURES "ppc;i386" CACHE STRING "archs" FORCE)
  SET ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -v" )
# The following is not the default when building universal
  INCLUDE_DIRECTORIES	 ( SYSTEM /usr/local/include )
  SET ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -v")
  SET ( CMAKE_SHARED_LINKER_FLAGS "-syslibroot ${CMAKE_OSX_SYSROOT} ${CMAKE_SHARED_LINKER_FLAGS}" )
  MESSAGE( "Building Apple universal binaries" )
ENDIF ( APPLE )

SET ( CMAKE_VERBOSE_MAKEFILE ON )

# Create config (build settings, library dependencies, etc.) files that are needed by 
# cmake projects which extend the zorba project
INCLUDE(CMakeExportBuildSettings)
CMAKE_EXPORT_BUILD_SETTINGS(${CMAKE_BINARY_DIR}/ZorbaBuildSettings.cmake)
EXPORT_LIBRARY_DEPENDENCIES(${CMAKE_BINARY_DIR}/ZorbaLibraryDepends.cmake)

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/ZorbaConfig.cmake.in ${CMAKE_BINARY_DIR}/ZorbaConfig.cmake)
