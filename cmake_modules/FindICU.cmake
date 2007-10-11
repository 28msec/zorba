# Finds the International Components for Unicode (ICU) Library
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

# Look for the header file.
find_path(
	ICU_INCLUDE_DIR
	NAMES unicode/utypes.h
	PATHS ${CMAKE_SOURCE_DIR}/include/icu include/icu
	DOC "Include directory for the ICU library")
mark_as_advanced(ICU_INCLUDE_DIR)

# Look for the library.
find_library(
	ICU_LIBRARY
	NAMES icuuc cygicuuc cygicuuc32 cygicuuc38
	PATHS ${CMAKE_SOURCE_DIR}/lib
	DOC "Libraries to link against for the common parts of ICU")
mark_as_advanced(ICU_LIBRARY)

if (ICU_LIBRARY)
	MESSAGE("-- Found ICU library -- " ${ICU_LIBRARY})
else (ICU_LIBRARY)
	MESSAGE("-- Could not find ICU library")
endif (ICU_LIBRARY)


# Copy the results to the output variables.
if(ICU_INCLUDE_DIR AND ICU_LIBRARY)
	set(ICU_FOUND 1)
	set(ICU_LIBRARIES ${ICU_LIBRARY})
	set(ICU_INCLUDE_DIRS ${ICU_INCLUDE_DIR})

	# Look for the ICU internationalization libraries
	find_library(
		ICU_I18N_LIBRARY
		NAMES icuin icui18n cygicuin cygicuin32 cygicuin38
		PATHS ${CMAKE_SOURCE_DIR}/lib
		DOC "Libraries to link against for ICU internationalization")
	mark_as_advanced(ICU_I18N_LIBRARY)
	if (ICU_I18N_LIBRARY)
		MESSAGE("-- Found ICU internationalization library -- " ${ICU_I18N_LIBRARY})
		set(ICU_I18N_FOUND 1)
		set(ICU_I18N_LIBRARIES ${ICU_I18N_LIBRARY})
	else (ICU_I18N_LIBRARY)
		MESSAGE("-- Could not find ICU internationalization library")
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
		PATHS ${CMAKE_SOURCE_DIR}/lib
		DOC "icudata library")
	mark_as_advanced(ICU_DATA_LIBRARY)
	if (ICU_DATA_LIBRARY)
		MESSAGE("-- Found ICU data library -- " ${ICU_DATA_LIBRARY})
		SET(ICU_DATA_FOUND 1)
		SET(ICU_DATA_LIBRARIES ${ICU_DATA_LIBRARY})
	else (ICU_DATA_LIBRARY)
		MESSAGE("-- Could not find ICU data library")
		SET(ICU_DATA_FOUND 0)
		SET(ICU_DATA_LIBRARIES)
	endif (ICU_DATA_LIBRARY)
	
else(ICU_INCLUDE_DIR AND ICU_LIBRARY)
  set(ICU_FOUND 0)
  set(ICU_I18N_FOUND 0)
  set(ICU_DATA_FOUND 0)
  set(ICU_LIBRARIES)
  set(ICU_I18N_LIBRARIES)
  set(ICU_DATA_LIBRARIES)
  set(ICU_INCLUDE_DIRS)
endif(ICU_INCLUDE_DIR AND ICU_LIBRARY)
