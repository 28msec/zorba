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

# - Try to find Xerces-C
#
# Once done this will define:
#  XERCESC_FOUND - system has Xerces-C
#  XERCESC_INCLUDE - the Xerces-C include directory
#  XERCESC_LIBRARY - Link these to use Xerces-C
#  XERCESC_VERSION - Xerces-C found version

IF (XERCESC_INCLUDE AND XERCESC_LIBRARY)
  # in cache already
  SET(XERCESC_FIND_QUIETLY TRUE)
ENDIF (XERCESC_INCLUDE AND XERCESC_LIBRARY)

FIND_PATH(
  XERCESC_INCLUDE 
  NAMES xercesc/util/XercesVersion.hpp
  PATHS c:/Libs/xerces-c_2_8_0 ${XERCES_INCLUDE_DIR} 
  PATH_SUFFIXES xercesc)

FIND_LIBRARY(
	XERCESC_LIBRARY 
	NAMES xerces-c xerces-c_2 xerces-c_3
	PATHS ${XERCES_LIBRARY_DIR})

IF (XERCESC_INCLUDE AND XERCESC_LIBRARY)
   SET(XERCESC_FOUND TRUE)
ELSE (XERCESC_INCLUDE AND XERCESC_LIBRARY)
   SET(XERCESC_FOUND FALSE)
ENDIF (XERCESC_INCLUDE AND XERCESC_LIBRARY)

IF(XERCESC_FOUND)
  IF(NOT XERCESC_FIND_QUIETLY)
    MESSAGE(STATUS "Found Xerces-C: ${XERCESC_LIBRARY}")
    MESSAGE(STATUS "              : ${XERCESC_INCLUDE}")
  ENDIF(NOT XERCESC_FIND_QUIETLY)
ELSE(XERCESC_FOUND)
  MESSAGE(STATUS "Could not find Xerces-C in default locations!")
ENDIF(XERCESC_FOUND)

MARK_AS_ADVANCED(XERCESC_INCLUDE XERCESC_LIBRARY)
