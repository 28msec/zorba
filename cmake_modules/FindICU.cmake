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

# - Find the International Components for Unicode (ICU) Library
#
# Once done this will define
#
#  ICU_FOUND          - True if ICU found.
#  ICU_I18N_FOUND     - True if ICU's internationalization library found.
#  ICU_DATA_FOUND     - True if ICU data library found.
#
#  ICU_INCLUDE_DIRS   - Directory to include to get ICU headers
#                       Note: always include ICU headers as, e.g., 
#                       unicode/utypes.h
#  ICU_LIBRARIES      - Libraries to link against for the common ICU
#  ICU_I18N_LIBRARIES - Libraries to link against for ICU internationaliation
#                       (note: in addition to ICU_LIBRARIES)
#  ICU_DATA_LIBRARIES - Libraries to link against for ICU data
#
#  ICU_VERSION        - ICU's version number.
#

# Look for the header file.
find_path(
  ICU_INCLUDE
  NAMES unicode/utypes.h
  PATHS ${ICU_INCLUDE_DIR}
  DOC "Include directory for the ICU library")
mark_as_advanced(ICU_INCLUDE)

# Look for the library.
find_library(
  ICU_LIBRARY
  NAMES icuuc cygicuuc cygicuuc32 cygicuuc38
  PATHS ${ICU_LIBRARY_DIR}
  DOC "Libraries to link against for the common parts of ICU (icuuc, cygicuuc, cygicuuc32 or cygicuuc38)")
mark_as_advanced(ICU_LIBRARY)

if (ICU_LIBRARY)
  MESSAGE(STATUS "Found ICU library -- " ${ICU_LIBRARY})
else (ICU_LIBRARY)
  MESSAGE(STATUS "Could not find ICU library")
endif (ICU_LIBRARY)

# Discover the version.
IF (NOT ICU_INCLUDE STREQUAL "")
  # ICU 3.x has the relevant #defines in uversion.h; 4.x uses uvernum.h.
  FIND_PATH(ICUVERHPPPATH NAMES unicode/uvernum.h unicode/uversion.h
    PATHS ${ICU_INCLUDE} NO_DEFAULT_PATH)

  IF ( ${ICUVERHPPPATH} STREQUAL ICUVERHPPPATH-NOTFOUND )
    SET(ICU_VERSION "0")
    MESSAGE(STATUS "Found ICU but unable to determine version - assuming version 0")
  ELSE( ${ICUVERHPPPATH} STREQUAL ICUVERHPPPATH-NOTFOUND )
    SET (ICUVERHPP)
    # One of these files has to exist, or else ICUVERHPPPATH wouldn't be set.
    # If uvernum.h exists, it has the data we want; otherwise, that data is
    # in uversion.h.
    FOREACH (header uvernum.h uversion.h)
      SET (headerfile "${ICUVERHPPPATH}/unicode/${header}")
      IF (EXISTS "${headerfile}")
	FILE(READ "${headerfile}" ICUVERHPP)
	BREAK()
      ENDIF (EXISTS "${headerfile}")
    ENDFOREACH (header)

    STRING(REGEX MATCH "\n *#define U_ICU_VERSION_MAJOR_NUM +[0-9]+" ICUVERMAJ 
      ${ICUVERHPP}) 
    STRING(REGEX MATCH "\n *#define U_ICU_VERSION_MINOR_NUM +[0-9]+" ICUVERMIN 
      ${ICUVERHPP})
    STRING(REGEX
      MATCH "\n *#define U_ICU_VERSION_PATCHLEVEL_NUM +[0-9]+" ICUVERPATCH 
      ${ICUVERHPP})
  
    STRING(REGEX REPLACE "\n *#define U_ICU_VERSION_MAJOR_NUM +" "" 
      ICUVERMAJ ${ICUVERMAJ})
    STRING(REGEX REPLACE "\n *#define U_ICU_VERSION_MINOR_NUM +" "" 
      ICUVERMIN ${ICUVERMIN})
    STRING(REGEX REPLACE "\n *#define U_ICU_VERSION_PATCHLEVEL_NUM +" "" 
      ICUVERPATCH ${ICUVERPATCH})
  
    SET(ICU_VERSION ${ICUVERMAJ}.${ICUVERMIN}.${ICUVERPATCH})
    MESSAGE(STATUS "ICU Version: ${ICU_VERSION}")
  
  ENDIF ( ${ICUVERHPPPATH} STREQUAL ICUVERHPPPATH-NOTFOUND )
ENDIF (NOT ICU_INCLUDE STREQUAL "")


# Copy the results to the output variables.
if(ICU_INCLUDE AND ICU_LIBRARY)
  set(ICU_FOUND 1)
  set(ICU_LIBRARIES ${ICU_LIBRARY})
  set(ICU_INCLUDE_DIRS ${ICU_INCLUDE})

  # Look for the ICU internationalization libraries
  find_library(
    ICU_I18N_LIBRARY
    NAMES icuin icui18n cygicuin cygicuin32 cygicuin38
    PATHS ${ICU_LIBRARY_DIR}
    DOC "Libraries to link against for ICU internationalization (icuin, icui18n, cygicuin, cygicuin32 or cygicuin38)")
  mark_as_advanced(ICU_I18N_LIBRARY)
  if (ICU_I18N_LIBRARY)
    MESSAGE(STATUS "Found ICU internationalization library -- " ${ICU_I18N_LIBRARY})
    set(ICU_I18N_FOUND 1)
    set(ICU_I18N_LIBRARIES ${ICU_I18N_LIBRARY})
  else (ICU_I18N_LIBRARY)
    MESSAGE(STATUS "Could not find ICU internationalization library")
    set(ICU_I18N_FOUND 0)
    set(ICU_I18N_LIBRARIES)
  endif (ICU_I18N_LIBRARY)

  # On cygwin, the data library is called icudt
  if (CYGWIN OR MSVC)
    SET (ICU_DATA_NAMES icudt cygicudt cygicudt38)
  else (CYGWIN OR MSVC)
    SET (ICU_DATA_NAMES icudata)
  endif (CYGWIN OR MSVC)

  # Look for ICU data library
  find_library(
    ICU_DATA_LIBRARY
    NAMES ${ICU_DATA_NAMES}
    PATHS ${ICU_LIBRARY_DIR}
    DOC "icudata library (icudt, cygicudt or cygicudt38)")
  mark_as_advanced(ICU_DATA_LIBRARY)
  if (ICU_DATA_LIBRARY)
    MESSAGE(STATUS "Found ICU data library -- " ${ICU_DATA_LIBRARY})
    SET(ICU_DATA_FOUND 1)
    SET(ICU_DATA_LIBRARIES ${ICU_DATA_LIBRARY})
  else (ICU_DATA_LIBRARY)
    MESSAGE(STATUS "Could not find ICU data library")
    SET(ICU_DATA_FOUND 0)
    SET(ICU_DATA_LIBRARIES)
  endif (ICU_DATA_LIBRARY)
  
else(ICU_INCLUDE AND ICU_LIBRARY)
  set(ICU_FOUND 0)
  set(ICU_I18N_FOUND 0)
  set(ICU_DATA_FOUND 0)
  set(ICU_LIBRARIES)
  set(ICU_I18N_LIBRARIES)
  set(ICU_DATA_LIBRARIES)
  set(ICU_INCLUDE_DIRS)
  set(ICU_VERSION 0)
endif(ICU_INCLUDE AND ICU_LIBRARY)
