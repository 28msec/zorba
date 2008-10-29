# - Find Google Perf Tools
#
# GooglePerfTools_LIBRARIES - List of libraries when using Google Perf tools.
# GooglePerfTools_FOUND - True if Google Perf tools found.
 
 
SET(GooglePerfTools_NAMES profiler)
FIND_LIBRARY(GooglePerfTools_LIBRARY
  NAMES ${GooglePerfTools_NAMES}
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)
 
IF (GooglePerfTools_LIBRARY)
   SET(GooglePerfTools_FOUND TRUE)
   SET( GooglePerfTools_LIBRARIES ${GooglePerfTools_LIBRARY} )
ELSE (GooglePerfTools_LIBRARY)
   SET(GooglePerfTools_FOUND FALSE)
   SET( GooglePerfTools_LIBRARIES )
ENDIF (GooglePerfTools_LIBRARY)
 
IF (GooglePerfTools_FOUND)
      MESSAGE(STATUS "Found GooglePerfTools: ${GooglePerfTools_LIBRARY}")
ELSE (GooglePerfTools_FOUND)
      MESSAGE(STATUS "Not Found GooglePerfTools: ${GooglePerfTools_LIBRARY}")
ENDIF (GooglePerfTools_FOUND)
 
MARK_AS_ADVANCED(
  GooglePerfTools_LIBRARY
)
 
