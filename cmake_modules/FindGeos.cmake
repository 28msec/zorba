#* Copyright 2006-2008 The FLWOR Foundation.
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

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeCompareVersionStrings.cmake)

IF (GEOS_INCLUDE_DIR)
  SET(GEOS_FIND_QUIETLY TRUE)
ENDIF (GEOS_INCLUDE_DIR)

# Look for the header file.
FIND_PATH(GEOS_INCLUDE_DIR geos.h PATHS "/usr/local/include/geos/") 
MARK_AS_ADVANCED(GEOS_INCLUDE_DIR)

# Look for the library.
# FIND_LIBRARY(GEOS_LIBRARY NAMES geos PATHS ${GEOS_LIBRARIES})
FIND_LIBRARY(GEOS_LIBRARY NAMES geos PATHS "/usr/local/lib/")
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

SET(GEOS_FOUND 0)
SET(GEOS_LIBRARIES)
SET(GEOS_INCLUDE_DIRS)
IF (GEOS_INCLUDE_DIR AND GEOS_LIBRARY)

  FIND_FILE(GEOS_VERSION_H version.h
    PATHS "${GEOS_INCLUDE_DIR}" "${GEOS_INCLUDE_DIR}/geos" NO_DEFAULT_PATH)
  IF(GEOS_VERSION_H AND EXISTS ${GEOS_VERSION_H})
    FILE(READ ${GEOS_VERSION_H} GEOS_VERSION_CONTENT)

    STRING(REGEX MATCH "#define GEOS_VERSION_MAJOR [0-9]+" GEOVERMAJ 
      ${GEOS_VERSION_CONTENT}) 
    STRING(REGEX MATCH "#define GEOS_VERSION_MINOR [0-9]+" GEOVERMIN 
      ${GEOS_VERSION_CONTENT})
    STRING(REGEX MATCH "#define GEOS_VERSION_PATCH [0-9]+" GEOVERREV 
      ${GEOS_VERSION_CONTENT})
    
    STRING(REGEX REPLACE "#define GEOS_VERSION_MAJOR " "" 
      GEOVERMAJ ${GEOVERMAJ})
    STRING(REGEX REPLACE "#define GEOS_VERSION_MINOR " "" 
      GEOVERMIN ${GEOVERMIN})
    STRING(REGEX REPLACE "#define GEOS_VERSION_PATCH " "" 
      GEOVERREV ${GEOVERREV})
    
    MESSAGE(STATUS "Found GEOS library ${GEOVERMAJ}.${GEOVERMIN}.${GEOVERREV} -- " ${GEOS_LIBRARY})
    MESSAGE(STATUS "Found GEOS include path -- " ${GEOS_INCLUDE_DIR})
    
    COMPARE_VERSION_STRINGS("${GEOVERMAJ}.${GEOVERMIN}.${GEOVERREV}" "3.2.2" GEOVERSIONCOMP)
    IF(${GEOVERSIONCOMP} LESS 0)
      
      MESSAGE(STATUS "GEOS library ${GEOVERMAJ}.${GEOVERMIN}.${GEOVERREV} is too old. Version 3.2.2 or better 3.3.0 or up is needed. Building Geo module is now disabled.")
      SET(GEOS_INCLUDE_DIR)
      SET(GEOS_LIBRARY)
    ELSE(${GEOVERSIONCOMP} LESS 0)
      
      SET(GEOS_FOUND 1)
      SET(GEOS_LIBRARIES ${GEOS_LIBRARY})
      SET(GEOS_INCLUDE_DIRS ${GEOS_INCLUDE_DIR})  
    ENDIF(${GEOVERSIONCOMP} LESS 0)
  ENDIF(GEOS_VERSION_H AND EXISTS ${GEOS_VERSION_H})
  
ENDIF (GEOS_INCLUDE_DIR AND GEOS_LIBRARY)
