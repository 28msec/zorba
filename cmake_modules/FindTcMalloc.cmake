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
# - Find Tcmalloc
# Find the native Tcmalloc includes and library
#
# Tcmalloc_INCLUDE_DIR - where to find Tcmalloc.h, etc.
# Tcmalloc_LIBRARIES - List of libraries when using Tcmalloc.
# Tcmalloc_FOUND - True if Tcmalloc found.
 
 
IF (Tcmalloc_INCLUDE_DIR)
  # Already in cache, be silent
  SET(Tcmalloc_FIND_QUIETLY TRUE)
ENDIF (Tcmalloc_INCLUDE_DIR)
 
FIND_PATH(Tcmalloc_INCLUDE_DIR google/heap-checker.h
  /opt/local/include
  /usr/local/include
  /usr/include
)
 
SET(Tcmalloc_NAMES tcmalloc)
FIND_LIBRARY(Tcmalloc_LIBRARY
  NAMES ${Tcmalloc_NAMES}
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)
 
IF (Tcmalloc_INCLUDE_DIR AND Tcmalloc_LIBRARY)
   SET(Tcmalloc_FOUND TRUE)
    SET( Tcmalloc_LIBRARIES ${Tcmalloc_LIBRARY} )
ELSE (Tcmalloc_INCLUDE_DIR AND Tcmalloc_LIBRARY)
   SET(Tcmalloc_FOUND FALSE)
   SET( Tcmalloc_LIBRARIES )
ENDIF (Tcmalloc_INCLUDE_DIR AND Tcmalloc_LIBRARY)
 
IF (Tcmalloc_FOUND)
   IF (NOT Tcmalloc_FIND_QUIETLY)
      MESSAGE(STATUS "Found Tcmalloc: ${Tcmalloc_LIBRARY}")
   ENDIF (NOT Tcmalloc_FIND_QUIETLY)
ELSE (Tcmalloc_FOUND)
      MESSAGE(STATUS "Not Found Tcmalloc: ${Tcmalloc_LIBRARY}")
   IF (Tcmalloc_FIND_REQUIRED)
      MESSAGE(STATUS "Looked for Tcmalloc libraries named ${TcmallocS_NAMES}.")
      MESSAGE(FATAL_ERROR "Could NOT find Tcmalloc library")
   ENDIF (Tcmalloc_FIND_REQUIRED)
ENDIF (Tcmalloc_FOUND)
 
MARK_AS_ADVANCED(
  Tcmalloc_LIBRARY
  Tcmalloc_INCLUDE_DIR
  )
 
