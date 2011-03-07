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

# - Find the C-CLIENT library that is part of the UW IMAP toolkit
#
# Once done this will define
#
#  CCLIENT_FOUND        - True if C-CLIENT library found.
#  CCLIENT_INCLUDE_DIRS - Directory to include to get C-CLIENT headers
#  CCLIENT_LIBRARIES    - Libraries to link against for the C-CLIENT library
#

IF(CCLIENT_INCLUDE_DIRS AND CCLIENT_LIBRARIES)
  # Already in cache, be silent
  SET(CCLIENT_FIND_QUIETLY TRUE)
ENDIF(CCLIENT_INCLUDE_DIRS AND CCLIENT_LIBRARIES)

# Look for the headers.
FIND_PATH(
  CCLIENT_INCLUDE
  NAMES c-client.h c-client/c-client.h
  PATHS ${CCLIENT_INCLUDE_DIR} /usr/include/imap /usr/include/c-client /opt/local/include/c-client
  DOC "Include directory for the CCLient library headers (the path to 'c-client.h' file)")

IF(CCLIENT_INCLUDE)
  IF(WIN32)
    IF(EXISTS "${CCLIENT_INCLUDE}/c-client/c-client.h")
      SET(CCLIENT_INCLUDE "${CCLIENT_INCLUDE}/c-client" CACHE PATH "Path to a file." FORCE)
    ENDIF(EXISTS "${CCLIENT_INCLUDE}/c-client/c-client.h")  
  ENDIF(WIN32)
  MESSAGE(STATUS "Found CCLIENT include directory -- " ${CCLIENT_INCLUDE})
ELSE(CCLIENT_INCLUDE)
  MESSAGE(STATUS "Could not find CCLIENT include directory")
ENDIF(CCLIENT_INCLUDE)

# only for GUI purposes
MARK_AS_ADVANCED(CCLIENT_INCLUDE)

# Look for the library.
FIND_LIBRARY(
  CCLIENT_LIBRARY
  NAMES c-client c-client4 cclient.lib c-client/cclient.lib c-client/Release/cclient.lib
  PATHS ${CCLIENT_LIBRARY_DIR} /opt/local/lib /usr/lib
  DOC "Library to link against for the email support (c-client, libc-client or cclient.lib)")

IF(CCLIENT_LIBRARY)
  MESSAGE(STATUS "Found CCLIENT library -- " ${CCLIENT_LIBRARY})
ELSE(CCLIENT_LIBRARY)
  MESSAGE(STATUS "Could not find CCLIENT library")
ENDIF(CCLIENT_LIBRARY)

# Copy the results to the output variables.
IF(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
  SET(CCLIENT_FOUND 1)
  SET(CCLIENT_LIBRARIES ${CCLIENT_LIBRARY})
  SET(CCLIENT_INCLUDE_DIRS ${CCLIENT_INCLUDE})

  # Do not treat the operator name keywords and, bitand, bitor, compl, not, or and xor
  # as synonyms as keywords. Needed in order to include C-CLIENT library
  IF(CMAKE_COMPILER_IS_GNUCXX)
    IF(NOT CMAKE_CXX_FLAGS MATCHES "-fno-operator-names")
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-operator-names")
    ENDIF(NOT CMAKE_CXX_FLAGS MATCHES "-fno-operator-names")
  ENDIF(CMAKE_COMPILER_IS_GNUCXX)
ELSE(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
  SET(CCLIENT_FOUND 0)
  SET(CCLIENT_LIBRARIES)
  SET(CCLIENT_INCLUDE_DIRS)
ENDIF(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
