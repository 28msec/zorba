#
# Project name
#
PROJECT(zorba)

# prohibit in-source-builds
IF (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    MESSAGE(STATUS "In-source-builds are not allowed")
    MESSAGE(STATUS "Clean your source directory (e.g. delete the CMakeCache.txt file)")
    MESSAGE(FATAL_ERROR "Please create a separate build directory and call CMake again")
ENDIF (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})

# set the default build type to debug
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

INCLUDE(cmake_modules/FindICU.cmake)

# some compiler flags that should always be used in order to force a good programming style
ADD_DEFINITIONS(-Wall -Wno-uninitialized -W -Wno-unused -Wpointer-arith -Woverloaded-virtual -Winline)

##############################################################################################################
# do platform checks
IF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
	MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")
ENDIF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)

INCLUDE (CheckIncludeFiles)
CHECK_INCLUDE_FILES ("sys/param.h;sys/mount.h;unicode/utypes.h;unicode/coll.h;unicode/ustring.h" HAVE_SYS_MOUNT_H)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# for the moment, we include everything
# however, we should move the headers (at least the library headers) into a separate directory
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${ICU_INCLUDE_DIR})

# Tell CMake to process the sub-directories
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(test)
