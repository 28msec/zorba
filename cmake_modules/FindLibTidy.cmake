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

# - Try to find the HTML Tidy lib
#
#  LIBTIDY_FOUND        - true if LIBTIDY was found
#  LIBTIDY_INCLUDE_DIRS - Directory to include to get LIBTIDY headers
#                         Note: always include LIBTIDY headers as e.g.,
#                         tidy/tidy.h
#  LIBTIDY_LIBRARIES    - Libraries to link against for the LIBTIDY
#


IF (LIBTIDY_INCLUDE_DIR)
  SET(LibTidy_FIND_QUIETLY TRUE)
ENDIF (LIBTIDY_INCLUDE_DIR)

# Look for the header file.
FIND_PATH(LIBTIDY_INCLUDE_DIR tidy.h PATH_SUFFIXES tidy)
MARK_AS_ADVANCED(LIBTIDY_INCLUDE_DIR)

# Look for the library.
# FIND_LIBRARY(LIBTIDY_LIBRARY NAMES tidy PATHS ${LIBTIDY_LIBRARIES})
FIND_LIBRARY(LIBTIDY_LIBRARY NAMES tidy)
MARK_AS_ADVANCED(LIBTIDY_LIBRARY)

# INCLUDE(FindPackageHandleStandardArgs)
# only available in cmake > 2.6
# FIND_PACKAGE_HANDLE_STANDARD_ARGS(LIBTIDY DEFAULT_MSG LIBTIDY_INCLUDE_DIR LIBTIDY_LIBRARY)
#IF (LIBTIDY_FOUND)
#  SET(LIBTIDY_LIBRARIES ${LIBTIDY_LIBRARY})
#  SET(LIBTIDY_INCLUDE_DIRS ${LIBTIDY_INCLUDE_DIR})
#ELSE (LIBTIDY_FOUND)
#  SET(LIBTIDY_LIBRARIES)
#  SET(LIBTIDY_INCLUDE_DIRS)
#ENDIF (LIBTIDY_FOUND)
IF (LIBTIDY_INCLUDE_DIR AND LIBTIDY_LIBRARY)
  SET(LIBTIDY_FOUND 1)
  SET(LIBTIDY_LIBRARIES ${LIBTIDY_LIBRARY})
  SET(LIBTIDY_INCLUDE_DIRS ${LIBTIDY_INCLUDE_DIR})
  IF(NOT LibTidy_FIND_QUIETLY)
    MESSAGE(STATUS "Found libtidy library      : " ${LIBTIDY_LIBRARY})
    MESSAGE(STATUS "Found libtidy include path : " ${LIBTIDY_INCLUDE_DIR})
  ENDIF(NOT LibTidy_FIND_QUIETLY)
ELSE (LIBTIDY_INCLUDE_DIR AND LIBTIDY_LIBRARY)
  SET(LIBTIDY_FOUND 0)
  SET(LIBTIDY_LIBRARIES)
  SET(LIBTIDY_INCLUDE_DIRS)
ENDIF (LIBTIDY_INCLUDE_DIR AND LIBTIDY_LIBRARY)
