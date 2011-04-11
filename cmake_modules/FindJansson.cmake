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
# - Find Jansson
#
# Once done this will define
#
#  Jansson_FOUND        - System has Jansson
#  Jansson_INCLUDE_DIRS - The Jansson include directories
#  Jansson_LIBRARIES    - The libraries needed to use Jansson

IF (Jansson_INCLUDE AND Jansson_LIBRARY)
   # in cache already
   SET(Jansson_FIND_QUIETLY TRUE)
ENDIF (Jansson_INCLUDE AND Jansson_LIBRARY)

SET(LIBRARY_NAMES jansson jansson.lib Release/jansson.lib bin/jansson.lib bin/Release/jansson.lib)
FIND_LIBRARY(
  Jansson_LIBRARY
  NAMES ${LIBRARY_NAMES}
  PATHS /usr/lib /usr/local/lib /opt/local/lib ${Jansson_LIBRARIES})

FIND_PATH(
  Jansson_INCLUDE
  NAMES jansson.h
  PATH_SUFFIXES jansson src
  PATHS ${Jansson_INCLUDE_DIRS})

IF(Jansson_LIBRARY AND Jansson_INCLUDE)
  SET(Jansson_FOUND TRUE)
  SET(Jansson_LIBRARIES ${Jansson_LIBRARY})
  SET(Jansson_INCLUDE_DIRS ${Jansson_INCLUDE})
ELSE(Jansson_LIBRARY AND Jansson_INCLUDE)
  IF(NOT Jansson_LIBRARY)
    MESSAGE(STATUS "Jansson static library could not be found matching one of: ${LIBRARY_NAMES}")
  ENDIF(NOT Jansson_LIBRARY)
  IF(NOT Jansson_INCLUDE)
    MESSAGE(STATUS "Jansson source directory could not be found.")
  ENDIF(NOT Jansson_INCLUDE)

  SET(Jansson_FOUND FALSE)
  SET(Jansson_LIBRARIES)
  SET(Jansson_INCLUDE)
ENDIF (Jansson_LIBRARY AND Jansson_INCLUDE)

IF(Jansson_FOUND)
  IF(NOT Jansson_FIND_QUIETLY)
    MESSAGE(STATUS "Found Jansson              : ${Jansson_LIBRARY}")
    MESSAGE(STATUS "Found Jansson include path : ${Jansson_INCLUDE_DIRS}")
  ENDIF(NOT Jansson_FIND_QUIETLY)
ELSE(Jansson_FOUND)
  MESSAGE(STATUS "Could not find Jansson library.")
ENDIF(Jansson_FOUND)
