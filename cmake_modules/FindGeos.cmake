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
# Try to find the GEOS lib
#
#  GEOS_FOUND        - true if GEOS was found
#  GEOS_INCLUDE_DIRS - Directory to include to get GEOS headers
#  GEOS_LIBRARIES    - Libraries to link against for the GEOS
#


IF (GEOS_INCLUDE_DIR)
  SET(GEOS_FIND_QUIETLY TRUE)
ENDIF (GEOS_INCLUDE_DIR)

# Look for the header file.
FIND_PATH(GEOS_INCLUDE_DIR geos.h) 
MARK_AS_ADVANCED(GEOS_INCLUDE_DIR)

# Look for the library.
# FIND_LIBRARY(GEOS_LIBRARY NAMES geos PATHS ${GEOS_LIBRARIES})
FIND_LIBRARY(GEOS_LIBRARY NAMES geos)
MARK_AS_ADVANCED(GEOS_LIBRARY)

# INCLUDE(FindPackageHandleStandardArgs)
# only available in cmake > 2.6
# FIND_PACKAGE_HANDLE_STANDARD_ARGS(GEOS DEFAULT_MSG GEOS_INCLUDE_DIR GEOS_LIBRARY)
#IF (GEOS_FOUND)
#  SET(GEOS_LIBRARIES ${GEOS_LIBRARY})
#  SET(GEOS_INCLUDE_DIRS ${GEOS_INCLUDE_DIR})
#ELSE (GEOS_FOUND)
#  SET(GEOS_LIBRARIES)
#  SET(GEOS_INCLUDE_DIRS)
#ENDIF (GEOS_FOUND)
IF (GEOS_INCLUDE_DIR AND GEOS_LIBRARY)
  SET(GEOS_FOUND 1)
  SET(GEOS_LIBRARIES ${GEOS_LIBRARY})
  SET(GEOS_INCLUDE_DIRS ${GEOS_INCLUDE_DIR})
  MESSAGE(STATUS "Found GEOS library -- " ${GEOS_LIBRARY})
  MESSAGE(STATUS "Found GEOS include path -- " ${GEOS_INCLUDE_DIR})
ELSE (GEOS_INCLUDE_DIR AND GEOS_LIBRARY)
  SET(GEOS_FOUND 0)
  SET(GEOS_LIBRARIES)
  SET(GEOS_INCLUDE_DIRS)
ENDIF (GEOS_INCLUDE_DIR AND GEOS_LIBRARY)
