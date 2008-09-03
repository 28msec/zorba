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
INCLUDE(CheckIncludeFiles)
INCLUDE(CheckSymbolExists)
INCLUDE(CheckFunctionExists)
INCLUDE(CheckVariableExists)
INCLUDE(CheckIncludeFileCXX)

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
IF (NOT APPLE)
  # execinfo is found by this macro when cross compiling for Mac OS X 10.4. although it shouldn't be found for this platform
  CHECK_INCLUDE_FILES ("execinfo.h"                   ZORBA_HAVE_EXECINFO_H)
ENDIF (NOT APPLE)
CHECK_INCLUDE_FILES ("curl/curl.h"                  ZORBA_HAVE_CURL_H)
CHECK_INCLUDE_FILE_CXX ("FlexLexer.h"               ZORBA_HAVE_FLEXLEXER_H)

CHECK_FUNCTION_EXISTS (strtof                     ZORBA_HAVE_STRTOF_FUNCTION)
CHECK_FUNCTION_EXISTS (_stricmp                   ZORBA_HAVE_STRICMP_FUNCTION)
CHECK_FUNCTION_EXISTS (strcasecmp                 ZORBA_HAVE_STRCASECMP_FUNCTION)
CHECK_FUNCTION_EXISTS (strcat_s                   ZORBA_HAVE_STRCAT_S_FUNCTION)
CHECK_FUNCTION_EXISTS (strcpy_s                   ZORBA_HAVE_STRCPY_S_FUNCTION)

SET(CMAKE_REQUIRED_LIBRARIES pthread)
CHECK_INCLUDE_FILES (pthread.h                    ZORBA_HAVE_PTHREAD_H)
CHECK_FUNCTION_EXISTS(pthread_spin_init           ZORBA_HAVE_PTHREAD_SPINLOCK)
CHECK_FUNCTION_EXISTS(pthread_mutex_init          ZORBA_HAVE_PTHREAD_MUTEX)

CHECK_INCLUDE_FILES ("sys/time.h;sys/resource.h"  ZORBA_HAVE_RUSAGE_INCLUDES)
CHECK_FUNCTION_EXISTS (getrusage                  ZORBA_HAVE_RUSAGE_FUNCTION)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/zorba/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/zorba/config.h)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/zorba/config.h.cmake -->${CMAKE_CURRENT_BINARY_DIR}/zorba/config.h")

IF(ZORBA_DEBUGGER)
INSTALL(DIRECTORY zorba DESTINATION include/zorba
 PATTERN "*.svn" EXCLUDE
 PATTERN "*.txt" EXCLUDE
 PATTERN "*.cmake" EXCLUDE)
ELSE(ZORBA_DEBUGGER)
INSTALL(DIRECTORY zorba DESTINATION include/zorba
 PATTERN "debugger*.h" EXCLUDE
 PATTERN "*.svn" EXCLUDE
 PATTERN "*.txt" EXCLUDE
 PATTERN "*.cmake" EXCLUDE)
ENDIF(ZORBA_DEBUGGER)

INSTALL(DIRECTORY simplestore DESTINATION include/zorba
 PATTERN "*.svn" EXCLUDE
 PATTERN "*.txt" EXCLUDE)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba/config.h DESTINATION
include/zorba/zorba)
