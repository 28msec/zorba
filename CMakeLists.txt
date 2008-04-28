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

# options that are used when typing make install
# rpath handling
# skip the full RPATH for the build tree
# SET(CMAKE_SKIP_BUILD_RPATH  TRUE)

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
SET(requiredlibs)
SET(DEFINITIONS)

##################################################### Setup Compiler Options
INCLUDE(CMakeCompiler.txt)


################################################################################
# Used libraries

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

#####################################################  ICU
INCLUDE(cmake_modules/FindICU.cmake)
IF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
	MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")
ELSE (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
    SET(requiredlibs ${requiredlibs} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES} ${ICU_DATA_LIBRARIES})
    INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})
ENDIF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)

#####################################################  LibXml2
FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})
ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2 library is required in order to build Zorba.")
ENDIF(LIBXML2_FOUND)

#####################################################  cURL    
FIND_PACKAGE(CURL)
IF(CURL_FOUND)
  MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
  SET(requiredlibs ${requiredlibs} ${CURL_LIBRARIES})  
  INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIRS})
ELSE(CURL_FOUND)
  MESSAGE(STATUS "The cURL library was not found.")
ENDIF(CURL_FOUND)

#####################################################  Iconv
INCLUDE(cmake_modules/FindIconv.cmake)
FIND_PACKAGE(Iconv)
IF (Iconv_FOUND)
    INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${ICONV_LIBRARY})
ENDIF (Iconv_FOUND)

#####################################################  Xerces-C
INCLUDE(cmake_modules/FindXercesC.cmake)
IF (XERCESC_FOUND)
	INCLUDE_DIRECTORIES(${XERCESC_INCLUDE})
	SET(requiredlibs ${requiredlibs} ${XERCESC_LIBRARY})
ENDIF (XERCESC_FOUND)

#####################################################  Boost
FIND_PACKAGE(Boost)
IF(Boost_FOUND AND EXISTS ${Boost_INCLUDE_DIRS}/boost/lexical_cast.hpp)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    IF (NOT WIN32)
        IF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
            SET(requiredlibs ${requiredlibs} boost_program_options-mt)
            SET(requiredlibs ${requiredlibs} boost_date_time-mt)
            SET(requiredlibs ${requiredlibs} boost_filesystem-mt)
        ELSE (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
            SET(requiredlibs ${requiredlibs} boost_program_options)
            SET(requiredlibs ${requiredlibs} boost_date_time)
            SET(requiredlibs ${requiredlibs} boost_filesystem)
        ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
    ELSE (NOT WIN32)
        IF (CYGWIN)
            SET(CMAKE_INCLUDE_PATH)            
            SET(requiredlibs ${requiredlibs} boost_program_options-gcc-mt)
            SET(requiredlibs ${requiredlibs} boost_date_time-gcc-mt)
            SET(requiredlibs ${requiredlibs} boost_filesystem-gcc-mt)
        ENDIF (CYGWIN)
    ENDIF (NOT WIN32)
    MESSAGE(STATUS "Found Boost: ${Boost_INCLUDE_DIRS}")
    MESSAGE(STATUS "      Boost: ${Boost_LIBRARY_DIRS}")
ELSE(Boost_FOUND AND EXISTS ${Boost_INCLUDE_DIRS}/boost/lexical_cast.hpp)
    MESSAGE(FATAL_ERROR "The boost library is required in order to build Zorba.")
ENDIF(Boost_FOUND AND EXISTS ${Boost_INCLUDE_DIRS}/boost/lexical_cast.hpp)

IF (HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)
  SET(requiredlibs ${requiredlibs} pthread)
ENDIF (HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)
################################################################################
# Custom user-defined settings

INCLUDE ("CMakeUser.txt" OPTIONAL)


################################################################################
# Compiler setup

MESSAGE(STATUS "Build type -- " ${CMAKE_BUILD_TYPE})

# add the include dir (i.e. the library) to the include path
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add cmake configuration (zorba options, etc.)
INCLUDE(CMakeConfiguration.txt)

# zorba versioning
SET(ZORBA_MAJOR_NUMBER "0")
SET(ZORBA_MINOR_NUMBER "9")
SET(ZORBA_PATCH_NUMBER)
FILE(READ ${CMAKE_CURRENT_SOURCE_DIR}/svn_rev.txt ZORBA_PATCH_NUMBER)
STRING(REGEX REPLACE "[^0-9]*([0-9]*)..*" "\\1" ZORBA_PATCH_NUMBER ${ZORBA_PATCH_NUMBER})
MESSAGE(STATUS "Zorba version number: " ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

# add compiler vvariables
ADD_DEFINITIONS(${DEFINITIONS})


################################################################################
# Subfolders inclusion

# Tell CMake to process the sub-directories
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(bin)
ADD_SUBDIRECTORY(doc)

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
