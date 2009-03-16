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

SET(requiredlibs)
SET(requiredlibs-store)

#
# TcMalloc support
#
IF (ZORBA_USE_TCMALLOC)
    MESSAGE (STATUS "Looking for TcMalloc")

    FIND_PACKAGE(TcMalloc)
    IF (Tcmalloc_FOUND)
        SET(requiredlibs ${requiredlibs} ${Tcmalloc_LIBRARIES})
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
        SET(requiredlibs ${requiredlibs} ${GooglePerfTools_LIBRARIES})
    ELSE (GooglePerfTools_FOUND)
        MESSAGE(FATAL_ERROR "GooglePerfTools not found. Cannot build with CPU
        profiling")
    ENDIF (GooglePerfTools_FOUND)
ENDIF (ZORBA_WITH_CPU_PROFILE)


#
#  LibXml2
#
FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)

    MESSAGE(STATUS "Found  LIBXML2 library -- " ${LIBXML2_LIBRARIES})
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

    SET(requiredlibs-store ${requiredlibs-store} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})

ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2 library and headers are required in order to build simple store.")
ENDIF(LIBXML2_FOUND)

#
#  LibXslt
#
IF(ZORBA_XQUERYX)
FIND_PACKAGE(LibXslt)
IF(LIBXSLT_FOUND)

    MESSAGE(STATUS "Found  LIBXSLT library -- " ${LIBXSLT_LIBRARIES})
    INCLUDE_DIRECTORIES(${LIBXSLT_INCLUDE_DIR})

    SET(requiredlibs-store ${requiredlibs-store} ${LIBXSLT_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXSLT_DEFINITONS})

ELSE(LIBXSLT_FOUND)
    MESSAGE(FATAL_ERROR "The libslt library is required in order to build zorba with xqueryx capabilities.")
ENDIF(LIBXSLT_FOUND)
ENDIF(ZORBA_XQUERYX)

#
# Pthreads
#
IF (ZORBA_HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)
  SET(requiredlibs ${requiredlibs} pthread)
ENDIF (ZORBA_HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)

#
# cURL
#
FIND_PACKAGE(CURL)
IF(CURL_FOUND)
  MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
  INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})

  SET(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${CURL_INCLUDE_DIR})

  SET(requiredlibs ${requiredlibs} ${CURL_LIBRARIES})
  SET(ZORBA_WITH_REST ON)

ELSE(CURL_FOUND)
  MESSAGE(STATUS "The cURL library was not found.")
ENDIF(CURL_FOUND)

#
# LibTidy
#
FIND_PACKAGE(LibTidy)

IF(LIBTIDY_FOUND)
  MESSAGE(STATUS "Found LibTidy library -- " ${LIBTIDY_LIBRARIES})
  INCLUDE_DIRECTORIES(${LIBTIDY_INCLUDE_DIR})

  SET(requiredlibs ${requiredlibs} ${LIBTIDY_LIBRARIES})

ELSE(LIBTIDY_FOUND)
  MESSAGE(STATUS "The LibTidy library was not found.")
ENDIF(LIBTIDY_FOUND)

#
# CClient library part of the UW IMAP toolkit required by the email functionality
#
FIND_PACKAGE(CClient)
IF (CCLIENT_FOUND)
IF( NOT WIN32 AND NOT CYGWIN)
  FIND_PACKAGE(PAM)
    IF(PAM_FOUND)
      INCLUDE_DIRECTORIES(${PAM_INCLUDE_DIR})
      SET(requiredlibs ${requiredlibs} ${PAM_LIBRARIES})
      INCLUDE_DIRECTORIES(${CCLIENT_INCLUDE_DIRS})
      SET(requiredlibs ${requiredlibs} ${CCLIENT_LIBRARIES})
    ELSE(PAM_FOUND)
      MESSAGE(STATUS "The PAM library needed by CClient library was not found hence email functionality is not available.")
    ENDIF(PAM_FOUND)
ELSE( NOT WIN32 AND NOT CYGWIN)
    INCLUDE_DIRECTORIES(${CCLIENT_INCLUDE_DIRS})
    SET(requiredlibs ${requiredlibs} ${CCLIENT_LIBRARIES})
    SET(requiredlibs ${requiredlibs} secur32.lib crypt32.lib winmm.lib ws2_32.lib)
ENDIF( NOT WIN32 AND NOT CYGWIN)
ELSE (CCLIENT_FOUND)
  MESSAGE(STATUS "The CClient library was not found hence email functionality is not available.")
ENDIF (CCLIENT_FOUND)

#
# Iconv
#
IF (WIN32)
    #INCLUDE(${CMAKE_MODULE_PATH}/FindIconv.cmake)
    FIND_PACKAGE(Iconv REQUIRED)

    IF (Iconv_FOUND)

      MESSAGE(STATUS "Found Iconv library -- " ${ICONV_LIBRARY})
      INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})

      SET(requiredlibs ${requiredlibs} ${ICONV_LIBRARY})

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

  SET(requiredlibs ${requiredlibs} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES} ${ICU_DATA_LIBRARIES}) 

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
    
    SET(requiredlibs ${requiredlibs} ${XERCESC_LIBRARY})
    
  ENDIF (XERCESC_FOUND)
ENDIF (NOT ZORBA_NO_XMLSCHEMA)

LIST(APPEND requiredlibs ${requiredlibs-store})

################################################################################
# Setup Compiler Options
# Note that this needs to be done after all packages are found because
# it sets variables based on whether packages have been found or not.
# Also, it needs to be done before the first variable (e.g. ZORBA_DEBUGGER) 
# is used.
INCLUDE(CMakeConfiguration.txt)
INCLUDE(CMakeCompiler.txt)

#
# JSON
#
SET(requiredlibs ${requiredlibs} json)

#
# Debugger
#
IF(ZORBA_DEBUGGER AND WIN32)
  SET(requiredlibs ${requiredlibs} wsock32)
ENDIF(ZORBA_DEBUGGER AND WIN32)

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
SET(ZORBA_PATCH_NUMBER "6")
SET(ZORBA_SVN_NUMER)

CONFIGURE_FILE ( "${CMAKE_SOURCE_DIR}/zorba.spec.in"
                 "${CMAKE_BINARY_DIR}/zorba.spec" @ONLY )

MESSAGE(STATUS "Zorba version number: " ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

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
  EXECUTE_PROCESS(COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${LIBXML2_LIBRARIES}
                    OUTPUT_VARIABLE Zorba_XML2)
ENDIF (APPLE )


################################################################################
#                                                                              #
# Tell CMake to process the sub-directories                                    #
#                                                                              #
################################################################################

# we can only build the command line client, apitests, and other if we build the simplestore
SET (BUILDING_SIMPLESTORE)
IF (ZORBA_STORE_DIRS MATCHES "src/store/naive")
  SET(BUILDING_SIMPLESTORE "ON")
ELSE (ZORBA_STORE_DIRS MATCHES "src/store/naive")
  SET(BUILDING_SIMPLESTORE "OFF")
ENDIF (ZORBA_STORE_DIRS MATCHES "src/store/naive")

IF(ZORBA_DEBUGGER)
  INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/external)
  ADD_SUBDIRECTORY(external)
ENDIF(ZORBA_DEBUGGER)

ADD_SUBDIRECTORY(include)

ADD_DEFINITIONS(-Dzorba_EXPORTS)
ADD_SUBDIRECTORY(src)
REMOVE_DEFINITIONS(-Dzorba_EXPORTS)

IF(ZORBA_USE_SWIG AND BUILDING_SIMPLESTORE)
  ADD_SUBDIRECTORY(swig)
ENDIF(ZORBA_USE_SWIG AND BUILDING_SIMPLESTORE)

ADD_SUBDIRECTORY(test)

IF (BUILDING_SIMPLESTORE)
  ADD_SUBDIRECTORY(bin)
ENDIF (BUILDING_SIMPLESTORE)

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

IF( APPLE AND UNIVERSAL )
  SET ( CMAKE_OSX_ARCHITECTURES "ppc;i386" CACHE STRING "archs" FORCE)
  SET ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -v" )
# The following is not the default when building universal
  INCLUDE_DIRECTORIES	 ( SYSTEM /usr/local/include )
  SET ( CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -v")
  MESSAGE( "Building Apple universal binaries" )
ENDIF( APPLE AND UNIVERSAL )

# Create config (build settings, library dependencies, etc.) files that are needed by 
# cmake projects which extend the zorba project
INCLUDE(CMakeExportBuildSettings)
CMAKE_EXPORT_BUILD_SETTINGS(${CMAKE_BINARY_DIR}/ZorbaBuildSettings.cmake)
EXPORT_LIBRARY_DEPENDENCIES(${CMAKE_BINARY_DIR}/ZorbaLibraryDepends.cmake)
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/ZorbaConfig.cmake.in ${CMAKE_BINARY_DIR}/ZorbaConfig.cmake)

INCLUDE( ${CMAKE_SOURCE_DIR}/cmake_modules/CMakeUseDoxygen.cmake)

IF (DOXYGEN_FOUND)

CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/doc/style/rtab_b.gif
${CMAKE_CURRENT_BINARY_DIR}/html/rtab_b.gif COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/doc/style/rtab_r.gif
${CMAKE_CURRENT_BINARY_DIR}/html/rtab_r.gif COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/doc/style/rtab_l.gif
${CMAKE_CURRENT_BINARY_DIR}/html/rtab_l.gif COPYONLY)

ENDIF (DOXYGEN_FOUND)
