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
# First, collect all the libraries that simplestore lib depends on
#

#
#  LibXml2
#
FIND_PACKAGE(LibXml2)
IF(LIBXML2_FOUND)
    MESSAGE(STATUS "Found  LIBXML2 library -- " ${LIBXML2_LIBRARIES})
    INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
    SET(requiredlibs-simplestore ${requiredlibs-simplestore} ${LIBXML2_LIBRARIES})
    SET(CXXFLAGS ${CXXFLAGS} ${LIBXML2_DEFINITONS})
ELSE(LIBXML2_FOUND)
    MESSAGE(FATAL_ERROR "The libxml2 library is required in order to build simple store.")
ENDIF(LIBXML2_FOUND)

IF (XERCESC_FOUND)
	INCLUDE_DIRECTORIES(${XERCESC_INCLUDE})
	SET(requiredlibs-simplestore ${requiredlibs-simplestore} ${XERCESC_LIBRARY})
ENDIF (XERCESC_FOUND)

#
# Boost
#
IF (BOOST_CHECK_LIBRARIES)

INCLUDE(${CMAKE_MODULE_PATH}/FindBoost.cmake)
SET (REQUIRED_BOOST_PACKAGES program_options)

FIND_PACKAGE(Boost REQUIRED COMPONENTS program_options)

IF (NOT Boost_FOUND)
  MESSAGE(FATAL "Boost not found")
ELSE (NOT Boost_FOUND)
  MESSAGE(STATUS "Found Boost: ${Boost_INCLUDE_DIRS}")
  MESSAGE(STATUS "      Boost: ${Boost_LIBRARY_DIRS}")

  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
  IF (NOT WIN32)
      IF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
          SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_program_options-mt)
          IF (34 LESS ${Boost_MINOR_VERSION})
            MESSAGE(STATUS "Boost minor version is greater than 34")
            SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_system-mt)
          ENDIF (34 LESS ${Boost_MINOR_VERSION})
      ELSE (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
          SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_program_options)
          IF (34 LESS ${Boost_MINOR_VERSION})
            MESSAGE(STATUS "Boost minor version is greater than 34")
            SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_system)
          ENDIF (34 LESS ${Boost_MINOR_VERSION})
      ENDIF (${CMAKE_SYSTEM_NAME} MATCHES "NetBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  ELSE (NOT WIN32)
      IF (CYGWIN)
          SET(CMAKE_INCLUDE_PATH)            
          SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_program_options-gcc-mt)
          IF (34 LESS ${Boost_MINOR_VERSION})
            MESSAGE(STATUS "Boost minor version is greater than 34")
            SET(requiredlibs-simplestore ${requiredlibs-simplestore} boost_system-gcc-mt)
          ENDIF (34 LESS ${Boost_MINOR_VERSION})
  	  ENDIF (CYGWIN)
  ENDIF (NOT WIN32)
ENDIF (NOT Boost_FOUND)

ENDIF (BOOST_CHECK_LIBRARIES)


#
# Internal common libraries
#
SET(requiredlibs-simplestore ${requiredlibs-simplestore} zorbautils)
SET(requiredlibs-simplestore ${requiredlibs-simplestore} zorbatypes)
SET(requiredlibs-simplestore ${requiredlibs-simplestore} zorbaerrors)


#
# Source Files
#
SET(SIMPLE_STORE_SRCS
    basic_item_factory.cpp
    simple_collection.cpp
    simple_temp_seq.cpp
    atomic_items.cpp
    item.cpp
    node_items.cpp
    node_vector.cpp
    node_updates.cpp
    node_iterators.cpp
    qname_pool.cpp
    simple_store.cpp
    simple_storec.cpp
    simple_loader.cpp
    simple_pul.cpp
    ordpath.cpp
    nsbindings.cpp
    item_iterator.cpp
    query_context.cpp
    string_pool.cpp
    properties.cpp
    )

SET(SIMPLESTORE_INSTALL_LIST)

IF (ZORBA_BUILD_STATIC_LIBRARY)

  ADD_LIBRARY(simplestore_static ${SIMPLE_STORE_SRCS})
  TARGET_LINK_LIBRARIES(simplestore_static ${requiredlibs-simplestore})

  SET_TARGET_PROPERTIES(simplestore_static PROPERTIES OUTPUT_NAME "simplestore")  
  SET_TARGET_PROPERTIES(simplestore_static PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
  SET_TARGET_PROPERTIES(simplestore_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

  SET(SIMPLESTORE_INSTALL_LIST ${SIMPLESTORE_INSTALL_LIST} simplestore_static)

ENDIF (ZORBA_BUILD_STATIC_LIBRARY)


IF (MSVC)
  ADD_LIBRARY(simplestore ${SIMPLE_STORE_SRCS})
ELSE (MSVC)
  ADD_LIBRARY(simplestore SHARED ${SIMPLE_STORE_SRCS})
ENDIF (MSVC)

TARGET_LINK_LIBRARIES(simplestore ${requiredlibs-simplestore})

SET_TARGET_PROPERTIES(simplestore PROPERTIES VERSION ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})

SET_TARGET_PROPERTIES(simplestore PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET(SIMPLESTORE_INSTALL_LIST ${SIMPLESTORE_INSTALL_LIST} simplestore)

INSTALL(TARGETS ${SIMPLESTORE_INSTALL_LIST}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
