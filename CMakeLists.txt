#
# Project name
#
PROJECT(zorba)
ENABLE_TESTING()
INCLUDE(CTest)

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
SET(BUILD_STATIC_LIBRARY 0)
SET(ZORBA_INCLUDES)
SET(APPLICATION_INCLUDES)


##############################################################################################################
# Used libraries
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

#############################################  ICU
INCLUDE(cmake_modules/FindICU.cmake)
SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${ICU_INCLUDE_DIRS}")

#############################################  LibXml2
FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)
	SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${LIBXML2_INCLUDE_DIR}")
    SET(requiredlibs ${requiredlibs} ${LIBXML2_LIBRARIES})
	SET(DEFINITIONS ${DEFINITIONS} ${LIBXML2_DEFINITONS})
    # SET(CXXFLAGS ${CXXFLAGS} )
ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2  library is required in order to build Zorba.")
ENDIF(LIBXML2_FOUND)

#############################################  cURL
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

############################################# Iconv
INCLUDE(cmake_modules/FindIconv.cmake)
FIND_PACKAGE(Iconv)
IF (Iconv_FOUND)
	SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${ICONV_INCLUDE_DIR}")
    SET(requiredlibs ${requiredlibs} ${ICONV_LIBRARY})
ENDIF (Iconv_FOUND)

#############################################  Xerces-C
INCLUDE(cmake_modules/FindXercesC.cmake)
IF (XERCESC_FOUND)
	SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${XERCESC_INCLUDE}")
	SET(requiredlibs ${requiredlibs} ${XERCESC_LIBRARY})
ENDIF (XERCESC_FOUND)

#############################################  Boost
FIND_PACKAGE(Boost)
IF(Boost_FOUND AND EXISTS ${Boost_INCLUDE_DIRS}/boost/lexical_cast.hpp)
	SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${Boost_INCLUDE_DIRS}")
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
    IF (NOT WIN32)
        IF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
            SET(requiredlibs ${requiredlibs} boost_program_options-mt)
            SET(requiredlibs ${requiredlibs} boost_date_time-mt)
            SET(requiredlibs ${requiredlibs} boost_filesystem-mt)
        ELSE (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
            SET(requiredlibs ${requiredlibs} boost_program_options)
            SET(requiredlibs ${requiredlibs} boost_date_time)
            SET(requiredlibs ${requiredlibs} boost_filesystem)
        ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
    ELSE (NOT WIN32)
        IF (CYGWIN)
            SET(CMAKE_INCLUDE_PATH)            
            SET(requiredlibs ${requiredlibs} boost_program_options-gcc-mt)
            SET(requiredlibs ${requiredlibs} boost_date_time-gcc-mt)
            SET(requiredlibs ${requiredlibs} boost_filesystem-gcc-mt)
        ENDIF (CYGWIN)
    ENDIF (NOT WIN32)
ELSE(Boost_FOUND AND EXISTS ${Boost_INCLUDE_DIRS}/boost/lexical_cast.hpp)
    MESSAGE(FATAL_ERROR "The boost library is required in order to build Zorba.")
ENDIF(Boost_FOUND AND EXISTS ${Boost_INCLUDE_DIRS}/boost/lexical_cast.hpp)


##############################################################################################################
# do platform checks

IF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
	MESSAGE(FATAL_ERROR "The ICU library is required in order to build Zorba.")
ELSE (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)
    SET(requiredlibs ${requiredlibs} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES} ${ICU_DATA_LIBRARIES})
ENDIF (NOT ICU_FOUND OR NOT ICU_I18N_FOUND OR NOT ICU_DATA_FOUND)

IF (NOT MSVC)
    SET(requiredlibs ${requiredlibs} pthread)
ENDIF (NOT MSVC)

# is located in external/mapm
SET(requiredlibs ${requiredlibs} mapm)  

##############################################################################################################
# Custom user-defined settings

INCLUDE ("CMakeUser.txt" OPTIONAL)


##############################################################################################################
# Compiler setup

MESSAGE(STATUS "Build type -- " ${CMAKE_BUILD_TYPE})

IF(${CMAKE_BUILD_TYPE} STREQUAL "Release")
ENDIF(${CMAKE_BUILD_TYPE} STREQUAL "Release")

SET(ZORBA_INCLUDES "-I${CMAKE_CURRENT_SOURCE_DIR}/src" ${ZORBA_INCLUDES})             # include BEFORE
SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/include")
SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/include/zorba")
SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${CMAKE_CURRENT_BINARY_DIR}/include")
SET(ZORBA_INCLUDES ${ZORBA_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/external")


SET(APPLICATION_INCLUDES ${APPLICATION_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/include")
SET(APPLICATION_INCLUDES ${APPLICATION_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/include/zorba")
SET(APPLICATION_INCLUDES ${APPLICATION_INCLUDES} "-I${CMAKE_CURRENT_BINARY_DIR}/include")
SET(APPLICATION_INCLUDES ${APPLICATION_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/external")

INCLUDE(CMakeConfiguration.txt)

# for the moment, we include everything
# however, we should move the headers (at least the library headers) into a separate directory

# Tell CMake to process the sub-directories
ADD_SUBDIRECTORY(external)
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
#ADD_SUBDIRECTORY(bin)
