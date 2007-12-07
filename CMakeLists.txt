#
# Project name
#
PROJECT(zorba)
ENABLE_TESTING()


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

##############################################################################################################
# Variables
SET(requiredlibs)
SET(DEFINITIONS)


##############################################################################################################
# Used libraries
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

INCLUDE(cmake_modules/FindICU.cmake)

FIND_PACKAGE(LibXml2)

IF(WITH_CURL)
  FIND_PACKAGE(CURL)
  IF(CURL_FOUND)
    MESSAGE(STATUS "Found cURL library -- " ${CURL_LIBRARIES})
    SET(requiredlibs ${requiredlibs} ${CURL_LIBRARIES})  
	SET(DEFINITIONS ${DEFINITIONS} "-D WITH_CURL ")
  ELSE(CURL_FOUND)
    MESSAGE(FATAL_ERROR "The cURL library was requested, but it could not be found.")
  ENDIF(CURL_FOUND)
ENDIF(WITH_CURL)

INCLUDE(cmake_modules/FindIconv.cmake)
FIND_PACKAGE(Iconv)
IF (Iconv_FOUND)
    INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${ICONV_LIBRARY})
ENDIF (Iconv_FOUND)



##############################################################################################################
# do platform checks

IF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
	MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")
ELSE (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
    SET(requiredlibs ${requiredlibs} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES} ${ICU_DATA_LIBRARIES})
ENDIF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)

IF(LIBXML2_FOUND)
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})
ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2  library is required in order to build Zorba.")
ENDIF(LIBXML2_FOUND)


FIND_PACKAGE(Boost)
IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    IF (NOT WIN32)
	    SET(requiredlibs ${requiredlibs} boost_program_options)
    ELSE (NOT WIN32)
        IF (CYGWIN)
            SET(CMAKE_INCLUDE_PATH)
            SET(requiredlibs ${requiredlibs} boost_program_options-gcc-mt) 
        ENDIF (CYGWIN)
    ENDIF (NOT WIN32)
ELSE(Boost_FOUND)
    MESSAGE(FATAL_ERROR "The boost library is required in order to build Zorba.")
ENDIF(Boost_FOUND)

IF (NOT MSVC)
    SET(requiredlibs ${requiredlibs} pthread)
ENDIF (NOT MSVC)


##############################################################################################################
# Compiler setup

MESSAGE(STATUS "Build type -- " ${CMAKE_BUILD_TYPE})

IF(${CMAKE_BUILD_TYPE} STREQUAL "Release")
ENDIF(${CMAKE_BUILD_TYPE} STREQUAL "Release")

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_BINARY_DIR}/include)

# some compiler flags that should always be used in order to force a good programming style
IF (MSVC)
	ADD_DEFINITIONS(${DEFINITIONS})
ELSE (MSVC)
	ADD_DEFINITIONS(-Wall -Wno-unused -Wpointer-arith -Woverloaded-virtual  ${DEFINITIONS})
ENDIF (MSVC)


INCLUDE(CMakeConfiguration.txt)


# for the moment, we include everything
# however, we should move the headers (at least the library headers) into a separate directory
INCLUDE_DIRECTORIES(${ICU_INCLUDE_DIRS})

# Tell CMake to process the sub-directories
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
#ADD_SUBDIRECTORY(bin)