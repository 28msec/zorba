# Copyright 2015 Federico Cavalieri.
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
# - Find FCGI
# Find the native FCGI includes and library
#
# FCGI_INCLUDE_DIR - where to find FCGI.h, etc.
# FCGI_LIBRARIES - List of libraries when using FCGI.
# FCGI_FOUND - True if FCGI found.
 
 
IF (FCGI_INCLUDE_DIR)
  # Already in cache, be silent
  SET(FCGI_FIND_QUIETLY TRUE)
ENDIF (FCGI_INCLUDE_DIR)
 
FIND_PATH(FCGI_INCLUDE_DIR fastcgi.h
  /opt/local/include
  /usr/local/include
  /usr/include
)
 
FIND_LIBRARY(FCGI_LIBRARY
  NAMES fcgi
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)

FIND_LIBRARY(FCGIPP_LIBRARY
  NAMES fcgi++
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)
 
IF (FCGI_INCLUDE_DIR AND FCGI_LIBRARY AND FCGIPP_LIBRARY)
   SET(FCGI_FOUND TRUE)
    SET( FCGI_LIBRARIES ${FCGI_LIBRARY} ${FCGIPP_LIBRARY} )
ELSE (FCGI_INCLUDE_DIR AND FCGI_LIBRARY AND FCGIPP_LIBRARY)
   SET(FCGI_FOUND FALSE)
   SET( FCGI_LIBRARIES )
ENDIF (FCGI_INCLUDE_DIR AND FCGI_LIBRARY AND FCGIPP_LIBRARY)
 
IF (FCGI_FOUND)
   IF (NOT FCGI_FIND_QUIETLY)
      MESSAGE(STATUS "Found FCGI: ${FCGI_LIBRARY}")
   ENDIF (NOT FCGI_FIND_QUIETLY)
ELSE (FCGI_FOUND)
      MESSAGE(STATUS "Not Found FCGI: ${FCGI_LIBRARY}")
   IF (FCGI_FIND_REQUIRED)
      MESSAGE(STATUS "Looked for FCGI libraries named ${FCGIS_NAMES}.")
      MESSAGE(FATAL_ERROR "Could NOT find FCGI library")
   ENDIF (FCGI_FIND_REQUIRED)
ENDIF (FCGI_FOUND)
 
MARK_AS_ADVANCED(
  FCGI_LIBRARY
  FCGIPP_LIBRARY
  FCGI_INCLUDE_DIR
  )
 
