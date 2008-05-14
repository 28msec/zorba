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

CHECK_INCLUDE_FILES ("sys/param.h;sys/mount.h"      HAVE_SYS_MOUNT_H)
CHECK_INCLUDE_FILES ("unicode/utypes.h"             HAVE_UTYPES_H)
CHECK_INCLUDE_FILES ("unicode/coll.h"               HAVE_COLL_H)
CHECK_INCLUDE_FILES ("unicode/ustring.h"            HAVE_USTRING_H)
CHECK_INCLUDE_FILES ("inttypes.h"                   HAVE_INTTYPES_H)
CHECK_INCLUDE_FILES ("stdint.h"                     HAVE_STDINT_H)
CHECK_INCLUDE_FILES ("stdlib.h"                     HAVE_STDLIB_H)
CHECK_INCLUDE_FILES ("limits.h"                     HAVE_LIMITS_H)
CHECK_INCLUDE_FILES ("sys/types.h"                  HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES ("iconv.h"                      HAVE_ICONV_H)
CHECK_INCLUDE_FILES ("execinfo.h"                   HAVE_EXECINFO_H)
CHECK_INCLUDE_FILES ("curl/curl.h"                  HAVE_CURL_H)
CHECK_INCLUDE_FILE_CXX ("FlexLexer.h"               HAVE_FLEXLEXER_H)

CHECK_FUNCTION_EXISTS (strtof                     HAVE_STRTOF_FUNCTION)
CHECK_FUNCTION_EXISTS (_stricmp                   HAVE_STRICMP_FUNCTION)
CHECK_FUNCTION_EXISTS (strcasecmp                 HAVE_STRCASECMP_FUNCTION)
CHECK_FUNCTION_EXISTS (strcat_s                   HAVE_STRCAT_S_FUNCTION)
CHECK_FUNCTION_EXISTS (strcpy_s                   HAVE_STRCPY_S_FUNCTION)

SET(CMAKE_REQUIRED_LIBRARIES pthread)
CHECK_INCLUDE_FILES (pthread.h                    HAVE_PTHREAD_H)
CHECK_FUNCTION_EXISTS(pthread_spin_init           HAVE_PTHREAD_SPINLOCK)
CHECK_FUNCTION_EXISTS(pthread_mutex_init          HAVE_PTHREAD_MUTEX)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/zorba/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/zorba/config.h)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/zorba/config.h.cmake -->${CMAKE_CURRENT_BINARY_DIR}/zorba/config.h")

INSTALL(DIRECTORY zorba DESTINATION include
 PATTERN "*.svn" EXCLUDE
 PATTERN "*.txt" EXCLUDE)
