# Finds the C-CLIENT library that is part of the UW IMAP toolkit
#
#  CCLIENT_FOUND        - True if C-CLIENT library found.
#  CCLIENT_INCLUDE_DIRS - Directory to include to get C-CLIENT headers
#  CCLIENT_LIBRARIES    - Libraries to link against for the C-CLIENT library
#

if (CCLIENT_INCLUDE_DIRS AND CCLIENT_LIBRARIES)
  # Already in cache, be silent
 set(CCLIENT_FIND_QUIETLY TRUE)
endif (CCLIENT_INCLUDE_DIRS AND CCLIENT_LIBRARIES)

find_path(
  CCLIENT_INCLUDE
  NAMES linkage.h
  PATHS ${CCLIENT_INCLUDE_DIRS}
  PATH_SUFFIXES c-client
  DOC "Include directory for the CCLient library linkage")
mark_as_advanced(CCLIENT_INCLUDE)

# Look for the library.
find_file(
  CCLIENT_LIBRARY
  NAMES libc-client.a libc-client4.a
  PATHS ${CCLIENT_LIBRARY_DIRS} /opt/local/lib
  DOC "Library to link against for the email support")

if (CCLIENT_LIBRARY)
  MESSAGE("-- Found CCLIENT library -- " ${CCLIENT_LIBRARY})
else (CCLIENT_LIBRARY)
  MESSAGE("-- Could not find CCLIENT library")
endif (CCLIENT_LIBRARY)

# Copy the results to the output variables.
if(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
  set(CCLIENT_FOUND 1)
  set(CCLIENT_LIBRARIES ${CCLIENT_LIBRARY})
  set(CCLIENT_INCLUDE_DIRS ${CCLIENT_INCLUDE_DIRS} ${CCLIENT_INCLUDE})

  # Do not treat the operator name keywords and, bitand, bitor, compl, not, or and xor
  # as synonyms as keywords. Needed in order to include C-CLIENT library
  IF(NOT CMAKE_CXX_FLAGS MATCHES "-fno-operator-names")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-operator-names")
  ENDIF(NOT CMAKE_CXX_FLAGS MATCHES "-fno-operator-names")

else(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
  set(CCLIENT_FOUND 0)
  set(CCLIENT_LIBRARIES)
  set(CCLIENT_INCLUDE_DIRS)
endif(CCLIENT_INCLUDE AND CCLIENT_LIBRARY)
