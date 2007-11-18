#
# Project name
#
PROJECT(zorba)

# Uncomment the next line to output make commands
# SET(CMAKE_VERBOSE_MAKEFILE ON)

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
IF (MSVC)
ELSE (MSVC)
	ADD_DEFINITIONS(-Wall -Wno-uninitialized -W -Wno-unused -Wpointer-arith -Woverloaded-virtual -DZORBA_USE_PTHREAD_LIBRARY -D_DEBUG)
ENDIF (MSVC)


INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_BINARY_DIR}/include)


##############################################################################################################
# do platform checks
IF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
	MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")
ENDIF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)


SET(requiredlibs)

FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})
ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2  library is required in order to build Zorba.")
ENDIF(LIBXML2_FOUND)


# for the moment, we include everything
# however, we should move the headers (at least the library headers) into a separate directory
INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})

# Tell CMake to process the sub-directories
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
