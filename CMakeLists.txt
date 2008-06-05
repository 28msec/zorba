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
SET(ZORBA_PATCH_NUMBER)
FILE(READ ${CMAKE_CURRENT_SOURCE_DIR}/svn_rev.txt ZORBA_PATCH_NUMBER)
STRING(REGEX REPLACE "[^0-9]*([0-9]*)..*" "\\1" ZORBA_PATCH_NUMBER ${ZORBA_PATCH_NUMBER})
MESSAGE(STATUS "Zorba version number: " ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

# add compiler vvariables
ADD_DEFINITIONS(${DEFINITIONS})



################################################################################
# Subfolders inclusion

# Tell CMake to process the sub-directories
IF(ZORBA_DEBUGGER)
  INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/external)
  ADD_SUBDIRECTORY(external)
ENDIF(ZORBA_DEBUGGER)
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(swig)
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

