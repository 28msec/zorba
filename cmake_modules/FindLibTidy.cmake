# Try to find the HTML Tidy lib
#
#  LIBTIDY_FOUND        - true if LIBTIDY was found
#  LIBTIDY_INCLUDE_DIR  - Directory to include to get LIBTIDY headers
#                         Note: always include LIBTIDY headers as e.g.,
#                         tidy/tidy.h
#  LIBTIDY_LIBRARIES    - Libraries to link against for the LIBTIDY
#


if (LIBTIDY_INCLUDE_DIR)
  set(LibTidy_FIND_QUIETLY TRUE)
endif (LIBTIDY_INCLUDE_DIR)

# Look for the header file.
FIND_PATH(LIBTIDY_INCLUDE_DIR tidy.h)

if( NOT LIBTIDY_INCLUDE_DIR )
  find_path(LIBTIDY_INCLUDE_DIR tidy.h PATH_SUFFIXES tidy)
  set(LIBTIDY_INCLUDE_DIR ${LIBTIDY_INCLUDE_DIR}/tidy CACHE PATH "Libtidy include directory")
endif( NOT LIBTIDY_INCLUDE_DIR )

# Look for the library.
FIND_LIBRARY(LIBTIDY_LIBRARIES NAMES tidy)

if (LIBTIDY_INCLUDE_DIR AND LIBTIDY_LIBRARIES)
  set(LIBTIDY_FOUND TRUE)
  MARK_AS_ADVANCED(LIBTIDY_INCLUDE_DIR LIBTIDY_LIBRARIES)
endif (LIBTIDY_INCLUDE_DIR AND LIBTIDY_LIBRARIES)
