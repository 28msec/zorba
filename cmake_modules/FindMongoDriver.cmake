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
# - Try to find the C++ mongodriver (legacy branch)
#
# Once done this will define
#
#  MONGODRIVER_FOUND - system has C++ mongo driver
#  MONGODRIVER_INCLUDE_DIR - the C++ mongo driver include directory
#  MONGODRIVER_LIBRARY - Link this to use the C++ mongo driver
#

IF (MONGODRIVER_INCLUDE_DIR AND MONGODRIVER_LIBRARY)
   # in cache already
   SET (MONGODRIVER_FIND_QUIETLY TRUE)
ENDIF (MONGODRIVER_INCLUDE_DIR AND MONGODRIVER_LIBRARY)

FIND_PATH(MONGODRIVER_INCLUDE_DIR mongo/client/dbclient.h
  /opt/local/include
  /usr/local/include
  /usr/include
)

FIND_LIBRARY(MONGODRIVER_LIBRARY
  NAMES mongoclient
  PATHS /usr/lib 
        /usr/local/lib
        /opt/local/lib
)

IF (MONGODRIVER_INCLUDE_DIR AND MONGODRIVER_LIBRARY)
  SET (MONGODRIVER_FOUND TRUE)
ELSE (MONGODRIVER_INCLUDE_DIR AND MONGODRIVER_LIBRARY)
  SET (MONGODRIVER_FOUND FALSE)
  SET (MONGODRIVER_LIBRARY)
ENDIF (MONGODRIVER_INCLUDE_DIR AND MONGODRIVER_LIBRARY)

IF (MONGODRIVER_FOUND)
  IF (NOT MONGODRIVER_FIND_QUIETLY)
    MESSAGE(STATUS "Found Mongodriver: ${MONGODRIVER_LIBRARY}")
  ENDIF (NOT MONGODRIVER_FIND_QUIETLY)
ELSE (MONGODRIVER_FOUND)
  MESSAGE(STATUS "Could not find mongodriver.")
  IF (MONGODRIVER_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could NOT find MONGO library")
  ENDIF (MONGODRIVER_FIND_REQUIRED)
ENDIF (MONGODRIVER_FOUND)

MARK_AS_ADVANCED(MONGODRIVER_INCLUDE_DIR MONGODRIVER_LIBRARY)
