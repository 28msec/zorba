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
# Finds the C-CLIENT library that is part of the UW IMAP toolkit
#
#  CCLIENT_FOUND        - True if C-CLIENT library found.
#  CCLIENT_INCLUDE      - Directory to include to get C-CLIENT headers
#  CCLIENT_LIBRARY      - Libraries to link against for the C-CLIENT library
#

if (CCLIENT_INCLUDE_DIRS AND CCLIENT_LIBRARIES)
  # Already in cache, be silent
 set(CCLIENT_FIND_QUIETLY TRUE)
endif (CCLIENT_INCLUDE_DIRS AND CCLIENT_LIBRARIES)

find_path(
  CCLIENT_INCLUDE
  NAMES linkage.c
  PATHS ${CCLIENT_LIBRARY_DIRS} /usr/include/imap
  DOC "Include directory for the CCLient library linkage (the path to 'linkage.c' file)")
mark_as_advanced(CCLIENT_INCLUDE)

# Look for the library.
find_file(
  CCLIENT_LIBRARY
  NAMES libc-client.a libc-client4.a
  PATHS ${CCLIENT_LIBRARY_DIRS} /opt/local/lib /usr/lib
  DOC "Library to link against for the email support (libc-client.a, libc-client4.a or cclient.lib)")

if (CCLIENT_LIBRARY)
  MESSAGE(STATUS "Found CCLIENT library -- " ${CCLIENT_LIBRARY})
else (CCLIENT_LIBRARY)
  MESSAGE(STATUS "Could not find CCLIENT library")
endif (CCLIENT_LIBRARY)

# Copy the results to the output variables.
if(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
  set(CCLIENT_FOUND 1)

  # Do not treat the operator name keywords and, bitand, bitor, compl, not, or and xor
  # as synonyms as keywords. Needed in order to include C-CLIENT library
  IF (CMAKE_COMPILER_IS_GNUCXX)
    IF(NOT CMAKE_CXX_FLAGS MATCHES "-fno-operator-names")
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-operator-names")
    ENDIF(NOT CMAKE_CXX_FLAGS MATCHES "-fno-operator-names")
  ENDIF (CMAKE_COMPILER_IS_GNUCXX)

else(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
  set(CCLIENT_FOUND 0)
  set(CCLIENT_LIBRARY)
  set(CCLIENT_INCLUDE)
endif(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
