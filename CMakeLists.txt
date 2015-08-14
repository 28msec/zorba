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

INCLUDE(CheckCXXSourceCompiles)
INCLUDE(CheckFunctionExists)
INCLUDE(CheckLibraryExists)
INCLUDE(CheckIncludeFileCXX)
INCLUDE(CheckIncludeFiles)
INCLUDE(CheckStructHasMember)
INCLUDE(CheckTypeSize)

# overwriting the source and binary directories with the current zorba ones
# this is usefull for other projects reusing zorba as a subcomponent
SET(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeCompareVersionStrings.cmake)

cmake_minimum_required(VERSION 2.6.4)
IF(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
  cmake_policy(SET CMP0002 OLD)
  # We want CMake to correctly count empty list elements.
  cmake_policy(SET CMP0007 NEW)
  IF(CMAKE_VERSION VERSION_GREATER 3.0.0 OR CMAKE_VERSION VERSION_EQUAL 3.0.0)
    cmake_policy(SET CMP0026 OLD)
  ENDIF(CMAKE_VERSION VERSION_GREATER 3.0.0 OR CMAKE_VERSION VERSION_EQUAL 3.0.0)  
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
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# turn on the folder grouping used by IDEs (VS or XCode)
SET(ZORBA_USE_TARGET_FOLDERS ON CACHE BOOL "Activate use of target grouping into folders")
IF(ZORBA_USE_TARGET_FOLDERS)
  SET_PROPERTY (GLOBAL PROPERTY USE_FOLDERS ON)
ENDIF(ZORBA_USE_TARGET_FOLDERS)

###############################################################################
# Check for system include files, features, etc.
###############################################################################
INCLUDE(TestBigEndian)
TEST_BIG_ENDIAN( BIG_ENDIAN )
IF (${BIG_ENDIAN})
  SET( ZORBA_BIG_ENDIAN 1 )
ELSE (${BIG_ENDIAN})
  SET( ZORBA_LITTLE_ENDIAN 1 )
ENDIF (${BIG_ENDIAN})

CHECK_INCLUDE_FILES ("unicode/coll.h"               ZORBA_HAVE_COLL_H)
CHECK_INCLUDE_FILES ("iconv.h"                      ZORBA_HAVE_ICONV_H)
CHECK_INCLUDE_FILES ("inttypes.h"                   ZORBA_HAVE_INTTYPES_H)
CHECK_INCLUDE_FILES ("limits.h"                     ZORBA_HAVE_LIMITS_H)
CHECK_INCLUDE_FILES ("stdint.h"                     ZORBA_HAVE_STDINT_H)
CHECK_INCLUDE_FILES ("stdlib.h"                     ZORBA_HAVE_STDLIB_H)
CHECK_INCLUDE_FILES ("sys/param.h;sys/mount.h"      ZORBA_HAVE_SYS_MOUNT_H)
CHECK_INCLUDE_FILES ("sys/types.h"                  ZORBA_HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES ("tzfile.h"                     ZORBA_HAVE_TZFILE_H)
CHECK_INCLUDE_FILES ("unicode/ustring.h"            ZORBA_HAVE_USTRING_H)
CHECK_INCLUDE_FILES ("unicode/utypes.h"             ZORBA_HAVE_UTYPES_H)

IF (NOT APPLE OR ${CMAKE_SYSTEM_VERSION} VERSION_GREATER "10.4")
  # execinfo is found by this macro when cross compiling for Mac OS X 10.4
  # although it shouldn't be found for this platform
  CHECK_INCLUDE_FILES ("execinfo.h"                   ZORBA_HAVE_EXECINFO_H)
ENDIF (NOT APPLE OR ${CMAKE_SYSTEM_VERSION} VERSION_GREATER "10.4")
CHECK_INCLUDE_FILE_CXX ("FlexLexer.h"               ZORBA_HAVE_FLEXLEXER_H)
CHECK_INCLUDE_FILES ("uuid/uuid.h"                  ZORBA_HAVE_UUID_H)

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

CHECK_FUNCTION_EXISTS (getrusage                  ZORBA_HAVE_GETRUSAGE)

CHECK_TYPE_SIZE("int32_t" ZORBA_HAVE_INT32_T) 
CHECK_TYPE_SIZE("uint32_t" ZORBA_HAVE_UINT32_T) 
CHECK_TYPE_SIZE("unsigned __int32" ZORBA_HAVE_MS_UINT32) 
CHECK_TYPE_SIZE("__int32" ZORBA_HAVE_MS_INT32) 
CHECK_TYPE_SIZE("int64_t" ZORBA_HAVE_INT64_T) 

CHECK_STRUCT_HAS_MEMBER("struct tm" tm_gmtoff time.h 	ZORBA_HAVE_STRUCT_TM_TM_GMTOFF)
CHECK_STRUCT_HAS_MEMBER("struct tm" __tm_gmtoff time.h 	ZORBA_HAVE_STRUCT_TM___TM_GMTOFF)

# C++ built-in type sizes
CHECK_TYPE_SIZE("double" ZORBA_SIZEOF_DOUBLE BUILTIN_TYPES_ONLY) 
CHECK_TYPE_SIZE("float" ZORBA_SIZEOF_FLOAT BUILTIN_TYPES_ONLY) 
CHECK_TYPE_SIZE("int" ZORBA_SIZEOF_INT BUILTIN_TYPES_ONLY) 
CHECK_TYPE_SIZE("long" ZORBA_SIZEOF_LONG BUILTIN_TYPES_ONLY) 
CHECK_TYPE_SIZE("long long" ZORBA_SIZEOF_LONG_LONG BUILTIN_TYPES_ONLY) 
CHECK_TYPE_SIZE("void*" ZORBA_SIZEOF_POINTER BUILTIN_TYPES_ONLY) 
CHECK_TYPE_SIZE("short" ZORBA_SIZEOF_SHORT BUILTIN_TYPES_ONLY) 
CHECK_TYPE_SIZE("size_t" ZORBA_SIZEOF_SIZE_T) 
SET(CMAKE_EXTRA_INCLUDE_FILES wchar.h)
CHECK_TYPE_SIZE("wchar_t" ZORBA_SIZEOF_WCHAR_T)
SET(CMAKE_EXTRA_INCLUDE_FILES)

################################################################################
# Various cmake macros

SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules ${CMAKE_MODULE_PATH})
IF (WIN32)
  # On Windows we use proxy modules that try to guess first the location
  # of the required third party libraries. This will search in order in:
  # 1. the path pointed by ZORBA_THIRD_PARTY_REQUIREMENTS
  # 2. the Program Files directory available on the users computer
  # 3. the PATH environment variable
  # The logic is implemented by the macros in the ProxyFindModule.cmake module.
  SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/Windows ${CMAKE_MODULE_PATH})
  INCLUDE (ProxyFindModule)
ENDIF (WIN32)

################################################################################
# This section is used for batch script and Visual Studio Project file generation. 
# Each executable on Windows needs a bat script and in the Visual Studio build a \
# pre-generated Visual Studio Project file in order to set the PATH to the required DLLs.
# For this we use CACHE variables to gather all the information generated
# throughout the cmake execution (required DLLs, list of scripts to generate).
# The generation occurs only at the end of CMake execution (through the macro
# ZORBA_GENERATE_EXE_HELPERS_WIN32) when ALL the requirements have been found.
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
  IF (MSVC_IDE)
    SET (ZORBA_VC_PROJECT_FILE_LIST ""
      CACHE STRING "List of Visual Studio project files to be generated, one for each executable" FORCE
    )
  ENDIF(MSVC_IDE)

  # Moreover, mark it as advanced since the CMake GUI user should not see this.
  MARK_AS_ADVANCED (FORCE ZORBA_REQUIRED_DLLS)
  MARK_AS_ADVANCED (FORCE ZORBA_REQUIRED_DLL_PATHS)
  MARK_AS_ADVANCED (FORCE ZORBA_EXE_SCRIPT_LIST)
  IF (MSVC_IDE)
    MARK_AS_ADVANCED (FORCE ZORBA_VC_PROJECT_FILE_LIST)
  ENDIF(MSVC_IDE)
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
  SET(ZORBA_HAVE_CLOCKGETTIME YES CACHE BOOL "Platform has clock_gettime (in librt)")
ELSE(_clock_gettime_in_rt)
  CHECK_FUNCTION_EXISTS(clock_gettime ZORBA_HAVE_CLOCKGETTIME)
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
  # Now check LibXml2's version
  FILE(STRINGS ${LIBXML2_INCLUDE_DIR}/libxml/xmlversion.h LIBXML2_VERSION_TMP REGEX 
       "^#define[ \t]+LIBXML_DOTTED_VERSION[ \t]+\".*\"")
  STRING(REGEX REPLACE "^#define[ \t]+LIBXML_DOTTED_VERSION[ \t]+\"(.*)\"" "\\1" 
         LIBXML2_VERSION ${LIBXML2_VERSION_TMP})
         
  IF(LIBXML2_VERSION VERSION_EQUAL "2.7.0" OR LIBXML2_VERSION VERSION_GREATER "2.7.0")
    MESSAGE(STATUS "Found LIBXML2 library -- " ${LIBXML2_LIBRARIES})
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
    SET(requiredlibs-store ${requiredlibs-store} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})
  ELSE(LIBXML2_VERSION VERSION_EQUAL "2.7.0" OR LIBXML2_VERSION VERSION_GREATER "2.7.0")
    MESSAGE(FATAL_ERROR "The libxml2 library version 2.7.0 or higher is required in order to build Zorba.")
  ENDIF(LIBXML2_VERSION VERSION_EQUAL "2.7.0" OR LIBXML2_VERSION VERSION_GREATER "2.7.0")

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
# shlwapi
#
IF(WIN32)
    SET(requiredlibs ${requiredlibs} "shlwapi")
ENDIF(WIN32)

LIST(APPEND requiredlibs ${requiredlibs-store})

################################################################################
# Setup Compiler Options
# Note that this needs to be done after all packages are found because
# it sets variables based on whether packages have been found or not.
INCLUDE(CMakeConfiguration.txt)
INCLUDE(CMakeCompiler.txt)

###############################################################################

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

IF(WIN32)
  SET(requiredlibs ${requiredlibs} wsock32)
  
  # Clear those variables because this is used only for this build.
  # A cache variable is needed since this must be modified by subdirectories
  # and be visible at this level when ZORBA_GENERATE_EXE_HELPERS_WIN32 is called
  SET(ZORBA_EXE_SCRIPT_LIST "" CACHE STRING "List of bat scripts" FORCE)
  SET(ZORBA_VC_PROJECT_FILE_LIST "" CACHE STRING "List of VC project files" FORCE)
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
SET(ZORBA_MAJOR_NUMBER "3")
SET(ZORBA_MINOR_NUMBER "1")
SET(ZORBA_PATCH_NUMBER "0")
SET(ZORBA_VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})
MESSAGE(STATUS "Zorba version number: ${ZORBA_VERSION}")

SET(ZORBA_LIB_DIRNAME "lib" CACHE STRING
  "directory name for libs (may want to set to 'lib64' on 64-bit Linux platforms)")

# Directories for modules and schemas. "Core" are those which are
# shipped with Zorba and must be present for correct Zorba
# functionality. "Non-core" are developed independently of Zorba and
# have different version lifecycles.
#
# URI dir is for things resolved by URI - specifically modules (.xq
# files) and schemas (.xsd files) - which are platform-
# independent. Lib dir is for platform-specific files, specifically
# shared libraries for module external functions.
SET(ZORBA_NONCORE_URI_DIR "share/zorba/uris"
  CACHE STRING "Path (relative to installdir) to non-core modules/schemas")
MARK_AS_ADVANCED(ZORBA_NONCORE_URI_DIR)
SET(ZORBA_CORE_URI_DIR "${ZORBA_NONCORE_URI_DIR}/core/${ZORBA_VERSION}"
  CACHE STRING "Path (relative to installdir) to core modules/schemas")
MARK_AS_ADVANCED(ZORBA_CORE_URI_DIR)
SET(ZORBA_NONCORE_LIB_DIR "${ZORBA_LIB_DIRNAME}/zorba"
  CACHE STRING "Path (relative to installdir) to non-core libraries")
MARK_AS_ADVANCED(ZORBA_NONCORE_LIB_DIR)
SET(ZORBA_CORE_LIB_DIR "${ZORBA_NONCORE_LIB_DIR}/core/${ZORBA_VERSION}"
  CACHE STRING "Path (relative to installdir) to core libraries")
MARK_AS_ADVANCED(ZORBA_CORE_LIB_DIR)

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
  SET(ZORBA_CMAKE_DIR "share/cmake/zorba-${ZORBA_VERSION}" CACHE STRING
    "Relative path to CMake files in Zorba installation")
ENDIF (WIN32)

################################################################################

# C++11 TR1 header location & namespace
CHECK_CXX_SOURCE_COMPILES("
  #include <tr1/type_traits>
  int main() { }" ZORBA_TR1_IN_TR1_SUBDIRECTORY)
CHECK_CXX_SOURCE_COMPILES("
  #include <type_traits>
  int main() { std::tr1::is_convertible<int,int> x; }" ZORBA_TR1_1)
CHECK_CXX_SOURCE_COMPILES("
  #include <tr1/type_traits>
  int main() { std::tr1::is_convertible<int,int> x; }" ZORBA_TR1_2)

IF (ZORBA_TR1_1 OR ZORBA_TR1_2)
  SET (ZORBA_TR1_NS_IS_STD_TR1 1)
ENDIF (ZORBA_TR1_1 OR ZORBA_TR1_2)

# C++11 langauge features
CHECK_CXX_SOURCE_COMPILES("
  #include <cstddef>
  int main() { int *p = nullptr; }" ZORBA_CXX_NULLPTR)
CHECK_CXX_SOURCE_COMPILES(
  "int main() { static_assert(1,\"\"); }" ZORBA_CXX_STATIC_ASSERT)

# C++11 standard library types
CHECK_CXX_SOURCE_COMPILES("
  #include <type_traits>
  int main() { std::enable_if<true,int> x; }" ZORBA_HAVE_ENABLE_IF)
CHECK_CXX_SOURCE_COMPILES("
  #include <type_traits>
  int main() { std::is_same<int,int> x; }" ZORBA_HAVE_IS_SAME)
CHECK_CXX_SOURCE_COMPILES("
  #include <memory>
  int main() { std::unique_ptr<int> p; }" ZORBA_HAVE_UNIQUE_PTR)
CHECK_CXX_SOURCE_COMPILES("
  #include <unordered_map>
  int main() { std::unordered_map<int,int> m; }" ZORBA_HAVE_UNORDERED_MAP)
CHECK_CXX_SOURCE_COMPILES("
  #include <unordered_set>
  int main() { std::unordered_set<int> s; }" ZORBA_HAVE_UNORDERED_SET)

################################################################################
#                                                                              #
# Tell CMake to process the sub-directories                                    #
#                                                                              #
################################################################################

ADD_SUBDIRECTORY(scripts)
ADD_SUBDIRECTORY(cmake_modules)

# Subdirectory ordering: We need to include "bin" before "test" so
# that test/fots can add zorbacmd-based tests. We need to include
# "test" before "config" so ZorbaConfig knows about testdriver. We
# need to include "config" before "modules" so external modules will
# be able to find ZorbaConfig.cmake. We need to include "modules"
# before "include" so config.h can know eg. whether we found CURL. We
# need to include "modules" before "doc" so xqdoc can know what
# non-core modules are available.

ADD_SUBDIRECTORY(bin)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(config)
ADD_SUBDIRECTORY(schemas)
ADD_SUBDIRECTORY(modules)
ADD_SUBDIRECTORY(doc)
ADD_SUBDIRECTORY(include)

ADD_DEFINITIONS(-Dzorba_EXPORTS)
ADD_SUBDIRECTORY(src)
REMOVE_DEFINITIONS(-Dzorba_EXPORTS)

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
  ZORBA_GENERATE_EXE_HELPERS_WIN32 ()
ENDIF (WIN32)

# This must be done last! Create the one top-level target which
# depends on all generated (copied) module/schema files.
DONE_DECLARING_ZORBA_URIS()

# This dependency makes sure that the error and warning definition
# modules are generated before trying to install them as zorba modules.
# This dependency is zorba-only related, which is why it's added here
# and not within zorba-modules, which is for general use in other
# non-zorba modules.
ADD_DEPENDENCIES(check_core_uris gen_diag_modules)

# vim:set et sw=2 ts=2:
