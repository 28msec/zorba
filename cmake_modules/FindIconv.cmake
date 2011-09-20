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

# - Try to find Iconv
#
# Once done this will define
#
#  ICONV_FOUND - system has Iconv
#  ICONV_INCLUDE_DIR - the Iconv include directory
#  ICONV_LIBRARY - Link these to use Iconv
#  ICONV_LIBRARY_DIR - the directory in which iconv is searched
#


IF (ICONV_INCLUDE_DIR AND ICONV_LIBRARY)
   # in cache already
   SET(Iconv_FIND_QUIETLY TRUE)
ENDIF (ICONV_INCLUDE_DIR AND ICONV_LIBRARY)

FIND_PATH(ICONV_INCLUDE_DIR iconv.h
  HINTS ${ICONV_INCLUDE_HINT}
  /usr/include
  /usr/local/include
  DOC "Include directory for the Iconv library linkage (the path to iconv.h file)"
)

FIND_LIBRARY(ICONV_LIBRARY NAMES iconv
  HINTS ${ICONV_LIBRARY_HINT}
  PATHS
  /usr/${LIB_DESTINATION}
  /usr/local/${LIB_DESTINATION}
  DOC "Iconv library that used by Libxml2 (iconv)"
)

IF (ICONV_INCLUDE_DIR AND ICONV_LIBRARY)
   SET(ICONV_FOUND TRUE)
ELSE (ICONV_INCLUDE_DIR AND ICONV_LIBRARY)
   SET(ICONV_FOUND FALSE)
ENDIF (ICONV_INCLUDE_DIR AND ICONV_LIBRARY)

IF(ICONV_FOUND)
  IF(NOT Iconv_FIND_QUIETLY)
    MESSAGE(STATUS "Found Iconv: ${ICONV_LIBRARY}")
  ENDIF(NOT Iconv_FIND_QUIETLY)
ELSE(ICONV_FOUND)
  IF(Iconv_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find Iconv")
  ENDIF(Iconv_FIND_REQUIRED)
ENDIF(ICONV_FOUND)

MARK_AS_ADVANCED(ICONV_INCLUDE_DIR ICONV_LIBRARY)
