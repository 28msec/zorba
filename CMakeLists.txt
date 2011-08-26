# Copyright 2006-2010 The FLWOR Foundation.
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
PROJECT(zorba)
ENABLE_TESTING()
INCLUDE(CTest)


# overwriting the source and binary directories with the current zorba ones
# this is usefull for other projects reusing zorba as a subcomponent
SET(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeCompareVersionStrings.cmake)

cmake_minimum_required(VERSION 2.6)
IF(CMAKE_VERSION STREQUAL "2.6.3")
  MESSAGE(FATAL_ERROR "You are running a buggy CMake version (2.6.3). Please install a different CMake version and execute CMake again.")
ENDIF(CMAKE_VERSION STREQUAL "2.6.3")
IF(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
  cmake_policy(SET CMP0002 OLD)
  # We want CMake to correctly count empty list elements.
  cmake_policy(SET CMP0007 NEW)
ENDIF(COMMAND cmake_policy)

IF("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
  SET(LINUX "${CMAKE_SYSTEM}")
ENDIF("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")

# custom ctest options
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/CTestCustom.cmake ${CMAKE_CURRENT_BINARY_DIR}/CTestCustom.cmake)

# prohibit in-source-builds
IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  MESSAGE(STATUS "In-source-builds are not allowed")
  MESSAGE(STATUS "Clean your source directory (e.g. delete the CMakeCache.txt file)")
  MESSAGE(FATAL_ERROR "Please create a separate build directory and call CMake again")
ENDIF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})

# set the default build type to release
# NOTE: the "NMake Makefiles" generator will always set the default build type to "Debug"
IF (NOT CMAKE_BUILD_TYPE)
  SET (CMAKE_BUILD_TYPE Release CACHE STRING
       "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
       FORCE)
ENDIF (NOT CMAKE_BUILD_TYPE)

# set the default installation directory to "dist" in the build directory
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET (CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/dist CACHE STRING
       "Set the defalt installation directory to \"dist\" in the binary directory." FORCE)
ENDIF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# Enable RPaths in installed binaries
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# turn on the folder grouping used by IDEs (VS or XCode)
SET_PROPERTY (GLOBAL PROPERTY USE_FOLDERS ON)

###############################################################################
# Check for system include files, features, etc.
###############################################################################
INCLUDE(CheckIncludeFiles)
INCLUDE(CheckSymbolExists)
INCLUDE(CheckFunctionExists)
INCLUDE(CheckLibraryExists)
INCLUDE(CheckVariableExists)
INCLUDE(CheckIncludeFileCXX)
INCLUDE(CheckTypeSize)
INCLUDE(CheckCXXSourceCompiles)

CHECK_INCLUDE_FILES ("sys/param.h;sys/mount.h"      ZORBA_HAVE_SYS_MOUNT_H)
CHECK_INCLUDE_FILES ("unicode/utypes.h"             ZORBA_HAVE_UTYPES_H)
CHECK_INCLUDE_FILES ("unicode/coll.h"               ZORBA_HAVE_COLL_H)
CHECK_INCLUDE_FILES ("unicode/ustring.h"            ZORBA_HAVE_USTRING_H)
CHECK_INCLUDE_FILES ("inttypes.h"                   ZORBA_HAVE_INTTYPES_H)
CHECK_INCLUDE_FILES ("stdint.h"                     ZORBA_HAVE_STDINT_H)
CHECK_INCLUDE_FILES ("stdlib.h"                     ZORBA_HAVE_STDLIB_H)
CHECK_INCLUDE_FILES ("limits.h"                     ZORBA_HAVE_LIMITS_H)
CHECK_INCLUDE_FILES ("sys/types.h"                  ZORBA_HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES ("iconv.h"                      ZORBA_HAVE_ICONV_H)
IF (NOT APPLE OR ${CMAKE_SYSTEM_VERSION} VERSION_GREATER "10.4")
  # execinfo is found by this macro when cross compiling for Mac OS X 10.4
  # although it shouldn't be found for this platform
  CHECK_INCLUDE_FILES ("execinfo.h"                   ZORBA_HAVE_EXECINFO_H)
ENDIF (NOT APPLE OR ${CMAKE_SYSTEM_VERSION} VERSION_GREATER "10.4")
CHECK_INCLUDE_FILE_CXX ("FlexLexer.h"               ZORBA_HAVE_FLEXLEXER_H)

CHECK_FUNCTION_EXISTS (strtof                     ZORBA_HAVE_STRTOF_FUNCTION)
CHECK_FUNCTION_EXISTS (strtoll                    ZORBA_HAVE_STRTOLL_FUNCTION)
CHECK_FUNCTION_EXISTS (_stricmp                   ZORBA_HAVE_STRICMP_FUNCTION)
CHECK_FUNCTION_EXISTS (strcat_s                   ZORBA_HAVE_STRCAT_S_FUNCTION)
CHECK_FUNCTION_EXISTS (strcpy_s                   ZORBA_HAVE_STRCPY_S_FUNCTION)

SET(CMAKE_REQUIRED_LIBRARIES pthread)  
CHECK_INCLUDE_FILES (pthread.h                    ZORBA_HAVE_PTHREAD_H)
CHECK_FUNCTION_EXISTS(pthread_spin_init           ZORBA_HAVE_PTHREAD_SPINLOCK)
CHECK_FUNCTION_EXISTS(pthread_mutex_init          ZORBA_HAVE_PTHREAD_MUTEX)
SET(CMAKE_REQUIRED_LIBRARIES)  

CHECK_INCLUDE_FILES ("sys/time.h;sys/resource.h"  ZORBA_HAVE_RUSAGE_INCLUDES)
CHECK_FUNCTION_EXISTS (getrusage                  ZORBA_HAVE_RUSAGE_FUNCTION)

CHECK_TYPE_SIZE("int32_t" ZORBA_HAVE_INT32_T) 
CHECK_TYPE_SIZE("uint32_t" ZORBA_HAVE_UINT32_T) 
CHECK_TYPE_SIZE("unsigned __int32" ZORBA_HAVE_MS_UINT32) 
CHECK_TYPE_SIZE("__int32" ZORBA_HAVE_MS_INT32) 
CHECK_TYPE_SIZE("int64_t" ZORBA_HAVE_INT64_T) 

CHECK_CXX_SOURCE_COMPILES ("#include <type_traits>\nint main() { std::enable_if<true,int> x; }" ZORBA_CXX_ENABLE_IF)
CHECK_CXX_SOURCE_COMPILES ("int main() { int *p = nullptr; }" ZORBA_CXX_NULLPTR)
CHECK_CXX_SOURCE_COMPILES ("int main() { static_assert(1,\"\"); }" ZORBA_CXX_STATIC_ASSERT)
CHECK_CXX_SOURCE_COMPILES ("#include <memory>\nint main() { std::unique_ptr<int> p; }" ZORBA_CXX_UNIQUE_PTR)

################################################################################
# Various cmake macros

IF(WIN32)
  # On Windows we use proxy modules that try to guess first the location
  # of the required third party libraries. This will search in order in:
  # 1. the path pointed by ZORBA_THIRD_PARTY_REQUIREMENTS
  # 2. the Program Files directory available on the users computer
  # 3. the PATH environment variable
  # The logic is implemented by the macros in the ProxyFindModule.cmake module.
  LIST (APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules/Windows")
  INCLUDE(ProxyFindModule)
ENDIF(WIN32)
LIST (APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules")


################################################################################
# This section is used for batch script generation. Each executable
# on Windows needs a bat script in order to set the PATH to the required DLLs.
# For this we use CACHE variables to gather all the information generated
# throughout the cmake execution (required DLLs, list of scripts to generate).
# The generation occurs only at the end of CMake execution (through the macro
# ZORBA_GENERATE_EXE_SCRIPTS_WIN32) when ALL the requirements have been found.
# E.g. zorba.exe needs in PATH all the DLLs of all external modules, etc.
IF (WIN32)
  # Clear all the variables because they are used only for this build.
  SET (ZORBA_REQUIRED_DLLS ""
    CACHE STRING "List of DLLs that must be installed" FORCE
  )
  SET (ZORBA_REQUIRED_DLL_PATHS ""
    CACHE STRING "List of paths executable require in order to find the required DLLs" FORCE
  )
  SET (ZORBA_EXE_SCRIPT_LIST ""
    CACHE STRING "List of Windows batch scripts to be generated, one for each executable" FORCE
  )
  # Moreover, mark it as advanced since the CMake GUI user should not see this.
  MARK_AS_ADVANCED (FORCE ZORBA_REQUIRED_DLLS)
  MARK_AS_ADVANCED (FORCE ZORBA_REQUIRED_DLL_PATHS)
  MARK_AS_ADVANCED (FORCE ZORBA_EXE_SCRIPT_LIST)
ENDIF (WIN32)
################################################################################


# ZorbaModule includes a number of generally-useful utility functions,
# including expected_failure().  Include it now (very early) to ensure
# the "expected_failure()" function is available to anyone who might
# add tests.
INCLUDE(ZorbaModule)

################################################################################
#                                                                              #
# Search for all the external libraries that any library or executable under   #
# this CMake depends on.                                                       #
#                                                                              #
################################################################################

FOREACH(path "${CMAKE_PREFIX_PATH}")
  IF(EXISTS "${path}")
    MESSAGE("path entry: ${path}")
  ELSE(EXISTS "${path}")
    # Ignore non-existing paths
    #MESSAGE("Non-existing path!: ${path}")
  ENDIF(EXISTS "${path}")
ENDFOREACH(path)

SET(requiredlibs)
SET(requiredlibs-store)

# Check for POSIX high-resolution timers - might be in "rt" library
CHECK_LIBRARY_EXISTS(rt clock_gettime ""  _clock_gettime_in_rt)
IF(_clock_gettime_in_rt)
  SET(requiredlibs ${requiredlibs} rt)
  SET(ZORBA_HAVE_CLOCKGETTIME_FUNCTION YES CACHE BOOL "Platform has clock_gettime (in librt)")
ELSE(_clock_gettime_in_rt)
  CHECK_FUNCTION_EXISTS(clock_gettime   ZORBA_HAVE_CLOCKGETTIME_FUNCTION)
ENDIF(_clock_gettime_in_rt)

#
# TcMalloc support
#
IF(ZORBA_USE_TCMALLOC)
  MESSAGE (STATUS "Looking for TcMalloc")

  FIND_PACKAGE(TcMalloc)
  IF(Tcmalloc_FOUND)
    SET(requiredlibs ${requiredlibs} ${Tcmalloc_LIBRARIES})
  ELSE(Tcmalloc_FOUND)
    MESSAGE(FATAL_ERROR "TcMalloc not found")
  ENDIF(Tcmalloc_FOUND)
ENDIF(ZORBA_USE_TCMALLOC)

#
# GooglePerfTools support
#
IF(ZORBA_WITH_CPU_PROFILE)
  MESSAGE(STATUS "Looking for GooglePerfTools")

  FIND_PACKAGE(GooglePerfTools)
  IF(GooglePerfTools_FOUND)
    SET(requiredlibs ${requiredlibs} ${GooglePerfTools_LIBRARIES})
  ELSE(GooglePerfTools_FOUND)
    MESSAGE(FATAL_ERROR "GooglePerfTools not found. Cannot build with CPU profiling")
  ENDIF(GooglePerfTools_FOUND)
ENDIF(ZORBA_WITH_CPU_PROFILE)

#
#  LibXml2
#
MESSAGE(STATUS "Looking for LibXml2")
FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)
  MESSAGE(STATUS "Found LIBXML2 library -- " ${LIBXML2_LIBRARIES})
    
  INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
  SET(requiredlibs-store ${requiredlibs-store} ${LIBXML2_LIBRARIES})
  SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})
ELSE(LIBXML2_FOUND)
  MESSAGE(FATAL_ERROR "The libxml2 library and headers are required in order to build simple store.")
ENDIF(LIBXML2_FOUND)
MESSAGE(STATUS "")

#
# Pthreads
#
IF(ZORBA_HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)
  SET(requiredlibs ${requiredlibs} pthread)
ENDIF(ZORBA_HAVE_PTHREAD_H AND NOT ZORBA_FOR_ONE_THREAD_ONLY)

#
# Iconv
#
IF(WIN32)
  MESSAGE(STATUS "Looking for Iconv")
  FIND_PACKAGE(Iconv REQUIRED)

  IF(ICONV_FOUND)
    MESSAGE(STATUS "Found Iconv library -- " ${ICONV_LIBRARY})
    INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${ICONV_LIBRARY})
  ELSE(ICONV_FOUND)
    MESSAGE(STATUS "The Iconv library was not found.")
  ENDIF(ICONV_FOUND)
  MESSAGE(STATUS "")
ENDIF(WIN32)

#
# ICU
#
MESSAGE(STATUS "Looking for ICU")
FIND_PACKAGE(ICU)
  
IF(ICU_FOUND AND ICU_I18N_FOUND AND ICU_DATA_FOUND)
  MESSAGE(STATUS "Found ICU library -- " ${ICU_LIBRARIES})

  INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})
  SET(requiredlibs ${requiredlibs} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES} ${ICU_DATA_LIBRARIES}) 
ELSE(ICU_FOUND AND ICU_I18N_FOUND AND ICU_DATA_FOUND)
  MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")
ENDIF(ICU_FOUND AND ICU_I18N_FOUND AND ICU_DATA_FOUND)       
MESSAGE(STATUS "")

#
# Xerces-C part 1 - finding in default locations
#
MESSAGE (STATUS "Looking for Xerces-C")
FIND_PACKAGE (XercesC)
MESSAGE (STATUS "")

#
# SWIG
#
IF (NOT ZORBA_SUPPRESS_SWIG)
  FIND_PACKAGE (SWIG)

  COMPARE_VERSION_STRINGS("${SWIG_VERSION}" "1.3.40" result)
  IF(result LESS 0)
    MESSAGE(WARNING "You need at least SWIG version 1.3.40")
  ENDIF(result LESS 0)


  IF (SWIG_FOUND)
    # this will be used both in swig and doc sub-directories

    #
    # PHP5
    #
    FIND_PACKAGE (PHP5)

    #
    # Python
    #
    FIND_PACKAGE (PythonInterp)
    FIND_PACKAGE (PythonLibs)
    
  ELSE (SWIG_FOUND)
    MESSAGE (STATUS "SWIG not found => no language bindings are generated.")  
  ENDIF (SWIG_FOUND)
ELSE (NOT ZORBA_SUPPRESS_SWIG)
  MESSAGE (STATUS "SWIG is disabled => no language bindings are generated.")  
ENDIF (NOT ZORBA_SUPPRESS_SWIG)


LIST(APPEND requiredlibs ${requiredlibs-store})

################################################################################
# Setup Compiler Options
# Note that this needs to be done after all packages are found because
# it sets variables based on whether packages have been found or not.
INCLUDE(CMakeConfiguration.txt)
INCLUDE(CMakeCompiler.txt)

#
#  LibXslt
#
IF(ZORBA_XQUERYX)
  MESSAGE(STATUS "Looking for LibXslt")
  FIND_PACKAGE(LibXslt)
  IF(LIBXSLT_FOUND)
    MESSAGE(STATUS "Found LIBXSLT library -- " ${LIBXSLT_LIBRARIES})

    INCLUDE_DIRECTORIES(${LIBXSLT_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${LIBXSLT_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXSLT_DEFINITONS})
  ELSE(LIBXSLT_FOUND)
    MESSAGE(FATAL_ERROR "The libxslt library is required in order to build zorba with xqueryx capabilities.")
  ENDIF(LIBXSLT_FOUND)
  MESSAGE(STATUS "")
ENDIF(ZORBA_XQUERYX)


#
# Xerces-C part 2 - version verification
#
IF (NOT ZORBA_NO_XMLSCHEMA)
  # Find XercesC Version based on ${XERCESC_INCLUDE}
  FIND_PACKAGE(XercesCVersion)
  
  IF (XERCESC_FOUND)
    COMPARE_VERSION_STRINGS("${XERCESC_VERSION}" 2.8.0 result)

    IF (result LESS 0)
      MESSAGE(FATAL_ERROR "Xerces-C ${XERCESC_VERSION} not supported.
	Only 2.8.0, 3.0.1 and newer versions are supported
	or
	Use -D ZORBA_NO_XMLSCHEMA=ON option for building without XMLSchema support.")
    ELSE (result LESS 0)
      MESSAGE(STATUS "Found Xerces ${XERCESC_VERSION} -- " ${XERCESC_INCLUDE}  ${XERCESC_LIBRARY})
      INCLUDE_DIRECTORIES(${XERCESC_INCLUDE})
      SET(requiredlibs ${requiredlibs} ${XERCESC_LIBRARY})
    ENDIF (result LESS 0)
  ELSE  (XERCESC_FOUND)
    MESSAGE(FATAL_ERROR "Xerces-C not found.
	Make sure you have Xerces-C 2.8.0 or 3.0.1+ installed
	or
	Use -D ZORBA_NO_XMLSCHEMA=ON option for building without XMLSchema support.")    
  ENDIF (XERCESC_FOUND)
ELSE (NOT ZORBA_NO_XMLSCHEMA)
  MESSAGE(STATUS "ZORBA_NO_XMLSCHEMA: ${ZORBA_NO_XMLSCHEMA}"
    " - build without XMLSchema support")
ENDIF (NOT ZORBA_NO_XMLSCHEMA)

LIST(APPEND requiredlibs ${requiredlibs-store})


IF(WIN32)
  SET(requiredlibs ${requiredlibs} wsock32)
ENDIF(WIN32)

################################################################################
# Variables
SET(DEFINITIONS)

################################################################################
# Custom user-defined settings
INCLUDE ("CMakeUser.txt" OPTIONAL)


################################################################################
# Compiler setup

# add the include dir (i.e. the library) to the include path
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_BINARY_DIR}/include)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/include)

# zorba versioning
SET(ZORBA_MAJOR_NUMBER "2")
SET(ZORBA_MINOR_NUMBER "0")
SET(ZORBA_PATCH_NUMBER "0")
SET(ZORBA_VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
MESSAGE(STATUS "Zorba version number: ${ZORBA_VERSION}")
SET(ZORBA_MODULES_INSTALL_DIR "share/zorba-${ZORBA_VERSION}/modules"
  CACHE STRING "Path (relative to installdir) to modules" FORCE)
MARK_AS_ADVANCED(ZORBA_MODULES_INSTALL_DIR)

# add compiler variables
ADD_DEFINITIONS(${DEFINITIONS})


################################################################################
# find all dylib files (i.e. transitive closure of the library files
# that are linked)
IF(APPLE)
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${ICU_LIBRARIES}
    OUTPUT_VARIABLE Zorba_ICUUC)
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${ICU_I18N_LIBRARIES}
    OUTPUT_VARIABLE Zorba_ICUI18N)
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${ICU_DATA_LIBRARIES}
    OUTPUT_VARIABLE Zorba_ICU_DATA)
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${XERCESC_LIBRARY}
    OUTPUT_VARIABLE Zorba_XERCESC)
  EXECUTE_PROCESS(
    COMMAND ${CMAKE_SOURCE_DIR}/scripts/find_macosx_libraries.sh ${LIBXML2_LIBRARIES}
    OUTPUT_VARIABLE Zorba_XML2)
ENDIF(APPLE)


SET (ZORBA_MODULES_DIR "${CMAKE_SOURCE_DIR}/../zorba_modules"
  CACHE PATH "Path to directory (outside of Zorba svn root) containing external modules to add to the build")

# Subdir of the installation directory for CMake files, relative to
# CMAKE_INSTALL_PREFIX.
IF (WIN32)
  SET(ZORBA_CMAKE_DIR "cmake" CACHE STRING
    "Relative path to CMake files in Zorba installation")
ELSE (WIN32)
  SET(ZORBA_CMAKE_DIR "share/zorba-${ZORBA_VERSION}/cmake" CACHE STRING
    "Relative path to CMake files in Zorba installation")
ENDIF (WIN32)

################################################################################
#                                                                              #
# Tell CMake to process the sub-directories                                    #
#                                                                              #
################################################################################

ADD_SUBDIRECTORY(scripts)
ADD_SUBDIRECTORY(cmake_modules)

# Subdirectory ordering: We need to include "test" before "config" so
# ZorbaConfig knows about testdriver. We need to include "config"
# before "modules" so external modules will be able to find
# ZorbaConfig.cmake.

ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(config)
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(doc)
ADD_SUBDIRECTORY(schemas)
ADD_SUBDIRECTORY(modules)

ADD_DEFINITIONS(-Dzorba_EXPORTS)
ADD_SUBDIRECTORY(src)
REMOVE_DEFINITIONS(-Dzorba_EXPORTS)

IF (SWIG_FOUND)
  ADD_SUBDIRECTORY (swig)
ENDIF (SWIG_FOUND)

ADD_SUBDIRECTORY(bin)

# add the uninstall support
# QQQ move to config/
CONFIGURE_FILE(
    "${CMAKE_CURRENT_SOURCE_DIR}/CMakeUninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeUninstall.cmake"
    @ONLY)
ADD_CUSTOM_TARGET(uninstall
    "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/CMakeUninstall.cmake")

SET(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_NO_WARNINGS ON)
INCLUDE(InstallRequiredSystemLibraries)

IF (NOT ZORBA_SKIP_CPACK)
  # QQQ move to config/ ?
  INCLUDE(CMakeCPack.cmake)
ENDIF (NOT ZORBA_SKIP_CPACK)

IF (APPLE AND UNIVERSAL)
  SET (CMAKE_OSX_ARCHITECTURES "ppc;i386" CACHE STRING "archs" FORCE)
  SET (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -v" )
  # The following is not the default when building universal
  INCLUDE_DIRECTORIES	(SYSTEM /usr/local/include)
  SET (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -v")
  MESSAGE ("Building Apple universal binaries")
ENDIF (APPLE AND UNIVERSAL)

IF (WIN32)
  ZORBA_GENERATE_EXE_SCRIPTS_WIN32 ()
ENDIF (WIN32)

# This must be done last! Create the one top-level target which
# depends on all generated (copied) module/schema files.
DONE_DECLARING_ZORBA_URIS()

# This dependency makes sure that the error and warning definition
# modules are generated before trying to install them as zorba modules.
# This dependency is zorba-only related, which is why it's added here
# and not within zorba-modules, which is for general use in other
# non-zorba modules.
ADD_DEPENDENCIES(check_uris gen_diag_modules)
