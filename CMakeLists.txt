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
  cmake_policy(SET CMP0002 OLD)
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
# Various cmake macros

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)


#################################################################################
#                                                                               #
# Search for all the external libraries that any library or executable under    #
#  this CMake depends on.                                                       #
#                                                                               #
#################################################################################

SET(commonlibs)

#
# TcMalloc support
#
IF (ZORBA_USE_TCMALLOC)
    MESSAGE (STATUS "Looking for TcMalloc")

    FIND_PACKAGE(TcMalloc)
    IF (Tcmalloc_FOUND)
        SET(commonlibs ${commonlibs} ${Tcmalloc_LIBRARIES})
    ELSE (Tcmalloc_FOUND)
        MESSAGE (FATAL_ERROR "TcMalloc not found")
    ENDIF (Tcmalloc_FOUND)

ENDIF (ZORBA_USE_TCMALLOC)

#
# GooglePerfTools support
#
IF (ZORBA_WITH_CPU_PROFILE)
    MESSAGE (STATUS "Looking for GooglePerfTools")

    FIND_PACKAGE(GooglePerfTools)
    IF (GooglePerfTools_FOUND)
        SET(commonlibs ${commonlibs} ${GooglePerfTools_LIBRARIES})
    ELSE (GooglePerfTools_FOUND)
        MESSAGE(FATAL_ERROR "GooglePerfTools not found. Cannot build with CPU
        profiling")
    ENDIF (GooglePerfTools_FOUND)
ENDIF (ZORBA_WITH_CPU_PROFILE)

SET(requiredlibs-zorbautils ${commonlibs})
SET(requiredlibs-zorbatypes ${commonlibs})
SET(requiredlibs-zorbaerrors ${commonlibs})
SET(requiredlibs-simplestore ${commonlibs})
SET(requiredlibs-zorba ${commonlibs})
SET(requiredlibs-apitest ${commonlibs})
SET(requiredlibs-teststore ${commonlibs})
SET(requiredlibs-testordpath ${commonlibs})
SET(requiredlibs-testdriver ${commonlibs})
SET(requiredlibs-zorbacmd ${commonlibs})


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
  SET(ZORBA_WITH_REST ON)
  
ELSE(CURL_FOUND)
  MESSAGE(STATUS "The cURL library was not found.")
ENDIF(CURL_FOUND)

#
# LibTidy
#
INCLUDE(${CMAKE_MODULE_PATH}/FindLibTidy.cmake)
FIND_PACKAGE(LibTidy)

IF(LIBTIDY_FOUND)
  MESSAGE(STATUS "Found LibTidy library -- " ${LIBTIDY_LIBRARIES})
  INCLUDE_DIRECTORIES(${LIBTIDY_INCLUDE_DIR})

  SET(requiredlibs-zorba ${requiredlibs-zorba} ${LIBTIDY_LIBRARIES})

ELSE(LIBTIDY_FOUND)
  MESSAGE(STATUS "The LibTidy library was not found.")
ENDIF(LIBTIDY_FOUND)

#
# Iconv
#
IF (WIN32)
    INCLUDE(${CMAKE_MODULE_PATH}/FindIconv.cmake)
    FIND_PACKAGE(Iconv REQUIRED)

    IF (Iconv_FOUND)

      MESSAGE(STATUS "Found Iconv library -- " ${ICONV_LIBRARIES})
      INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})

      SET(requiredlibs-zorba ${requiredlibs-zorba} ${ICONV_LIBRARY})

    ELSE(Iconv_FOUND)
      MESSAGE(STATUS "The Iconv library was not found.")
    ENDIF (Iconv_FOUND)
ENDIF (WIN32)

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

IF (NOT ZORBA_NO_XMLSCHEMA)
  #
  # Xerces-C
  #
  INCLUDE(${CMAKE_MODULE_PATH}/FindXercesC.cmake)
  IF (XERCESC_FOUND)
    
    INCLUDE_DIRECTORIES(${XERCESC_INCLUDE})
    
    SET(requiredlibs-zorbatypes ${requiredlibs-zorbatypes} ${XERCESC_LIBRARY})
    SET(requiredlibs-zorba ${requiredlibs-zorba} ${XERCESC_LIBRARY})
    
  ENDIF (XERCESC_FOUND)
ENDIF (NOT ZORBA_NO_XMLSCHEMA)

################################################################################
# Setup Compiler Options
# Note that this needs to be done after all packages are found because
# it sets variables based on whether packages have been found or not.
# Also, it needs to be done before the first variable (e.g. ZORBA_DEBUGGER) 
# is used.
INCLUDE(CMakeConfiguration.txt)
INCLUDE(CMakeCompiler.txt)

#
# Debugger
#
IF (ZORBA_DEBUGGER)
  SET(requiredlibs-zorba ${requiredlibs-zorba} json)
  IF(WIN32)
    SET(requiredlibs-zorba ${requiredlibs-zorba} wsock32) 
  ENDIF(WIN32)
ENDIF (ZORBA_DEBUGGER)

###############################################################################
# Debian package dependencies
SET(debian-required-packages "libxml2,libicu38,libxerces28")
IF(CURL_FOUND)
  SET(debian-required-packages "${debian-required-packages},libcurl3")
ENDIF(CURL_FOUND)
IF(LIBTIDY_FOUND)
  SET(debian-required-packages "${debian-required-packages},tidy")
ENDIF(LIBTIDY_FOUND)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ZorbaDebianDependencies.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/ZorbaDebianDependencies.cmake)

################################################################################
# Variables
SET(DEFINITIONS)

################################################################################
# Custom user-defined settings
INCLUDE ("CMakeUser.txt" OPTIONAL)


################################################################################
# Compiler setup

MESSAGE(STATUS "Build type -- " ${CMAKE_BUILD_TYPE})

# add the include dir (i.e. the library) to the include path
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_BINARY_DIR}/include)

# zorba versioning
SET(ZORBA_MAJOR_NUMBER "0")
SET(ZORBA_MINOR_NUMBER "9")
SET(ZORBA_PATCH_NUMBER "4")
SET(ZORBA_SVN_NUMER)

CONFIGURE_FILE ( "${CMAKE_SOURCE_DIR}/zorba.spec.in"
                 "${CMAKE_BINARY_DIR}/zorba.spec" @ONLY )

FILE(READ ${CMAKE_CURRENT_SOURCE_DIR}/svn_rev.txt ZORBA_SVN_NUMBER)
STRING(REGEX REPLACE "[^0-9]*([0-9]*)..*" "\\1" ZORBA_SVN_NUMBER ${ZORBA_SVN_NUMBER})
MESSAGE(STATUS "Zorba version number: " ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}-${ZORBA_SVN_NUMBER})

# add compiler variables
ADD_DEFINITIONS(${DEFINITIONS})


################################################################################
# find all dylib files (i.e. transitive closure of the library files that are linked)
IF (APPLE )
  EXECUTE_PROCESS(COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${ICU_LIBRARIES}
                    OUTPUT_VARIABLE Zorba_ICUUC)
  EXECUTE_PROCESS(COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${ICU_I18N_LIBRARIES}
                    OUTPUT_VARIABLE Zorba_ICUI18N)
  EXECUTE_PROCESS(COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${ICU_DATA_LIBRARIES}
                    OUTPUT_VARIABLE Zorba_ICU_DATA)
  EXECUTE_PROCESS(COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${XERCESC_LIBRARY}
                    OUTPUT_VARIABLE Zorba_XERCESC)
  EXECUTE_PROCESS(COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${CURL_LIBRARIES}
                    OUTPUT_VARIABLE Zorba_CURL)
ENDIF (APPLE )


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

IF( APPLE AND UNIVERSAL )
  SET ( CMAKE_OSX_ARCHITECTURES "ppc;i386" CACHE STRING "archs" FORCE)
  SET ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -v" )
# The following is not the default when building universal
  INCLUDE_DIRECTORIES	 ( SYSTEM /usr/local/include )
  SET ( CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -v")
  MESSAGE( "Building Apple universal binaries" )
ENDIF( APPLE AND UNIVERSAL )


SET ( CMAKE_VERBOSE_MAKEFILE OFF )

# Create config (build settings, library dependencies, etc.) files that are needed by 
# cmake projects which extend the zorba project
INCLUDE(CMakeExportBuildSettings)
CMAKE_EXPORT_BUILD_SETTINGS(${CMAKE_BINARY_DIR}/ZorbaBuildSettings.cmake)
EXPORT_LIBRARY_DEPENDENCIES(${CMAKE_BINARY_DIR}/ZorbaLibraryDepends.cmake)
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/ZorbaConfig.cmake.in ${CMAKE_BINARY_DIR}/ZorbaConfig.cmake)
