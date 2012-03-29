# Copyright 2006-2012 The FLWOR Foundation.
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

IF (NOT PHP5_FOUND)
  MESSAGE (STATUS "SWIG PHP: PHP5 binding not generated because library and include file not installed.")
ELSE (NOT PHP5_FOUND)
  MESSAGE (STATUS "SWIG PHP: Generating PHP5 API")

  SET_SOURCE_FILES_PROPERTIES (zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES (${PHP5_INCLUDES})
  IF (WIN32)
    INCLUDE_DIRECTORIES(${PHP5_MAIN_INCLUDE_DIR})
    INCLUDE_DIRECTORIES(${PHP5_TSRM_INCLUDE_DIR})
    INCLUDE_DIRECTORIES(${PHP5_ZEND_INCLUDE_DIR})
    ADD_DEFINITIONS(-DZEND_WIN32 -DPHP_WIN32 -DZEND_INCLUDE_FULL_WINDOWS_HEADERS -DZEND_DEBUG=0 -DZTS=1)
  ENDIF (WIN32)

  SWIG_ADD_MODULE (zorba_api php5 zorba_api.i)

  IF (APPLE)
    SWIG_LINK_LIBRARIES (zorba_api zorba_simplestore ${CMAKE_SHARED_MODULE_CREATE_C_FLAGS})
  ELSE (APPLE)
    SWIG_LINK_LIBRARIES (zorba_api zorba_simplestore)
  ENDIF (APPLE)

  IF (WIN32)
    STRING(REGEX REPLACE "\\\\" "/" PHP5_LIBRARY "${PHP5_LIBRARY}")
    MESSAGE (STATUS "SWIG PHP: Link library: " ${PHP5_LIBRARY})
    SWIG_LINK_LIBRARIES (zorba_api ${PHP5_LIBRARY})
  ENDIF (WIN32)

  #Copy test to the build folder
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/test.xq" "${CMAKE_CURRENT_BINARY_DIR}/test.xq" COPYONLY)
  
  #Copy
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQueryProcessor.php" "${CMAKE_CURRENT_BINARY_DIR}/Zorba/XQueryProcessor.php" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/zorba_api_wrapper.php" "${CMAKE_CURRENT_BINARY_DIR}/Zorba/zorba_api_wrapper.php" COPYONLY)

  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../StaticContext.h" "${CMAKE_CURRENT_BINARY_DIR}/StaticContext.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../ItemFactory.h" "${CMAKE_CURRENT_BINARY_DIR}/ItemFactory.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Item.h" "${CMAKE_CURRENT_BINARY_DIR}/Item.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Iterator.h" "${CMAKE_CURRENT_BINARY_DIR}/Iterator.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../XQuery.h" "${CMAKE_CURRENT_BINARY_DIR}/XQuery.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../DynamicContext.h" "${CMAKE_CURRENT_BINARY_DIR}/DynamicContext.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../XmlDataManager.h" "${CMAKE_CURRENT_BINARY_DIR}/XmlDataManager.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../TypeIdentifier.h" "${CMAKE_CURRENT_BINARY_DIR}/TypeIdentifier.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../SerializationOptions.h" "${CMAKE_CURRENT_BINARY_DIR}/SerializationOptions.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Collection.h" "${CMAKE_CURRENT_BINARY_DIR}/Collection.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../CollectionManager.h" "${CMAKE_CURRENT_BINARY_DIR}/CollectionManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../DocumentManager.h" "${CMAKE_CURRENT_BINARY_DIR}/DocumentManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../ItemSequence.h" "${CMAKE_CURRENT_BINARY_DIR}/ItemSequence.h" COPYONLY)

  # The following fix was added because of the changes in CMake 2.8, which have the
  # result of naming the java binding library "liblibzorba_api.so" instead of "libzorba_api.so"
  SET_TARGET_PROPERTIES( ${SWIG_MODULE_zorba_api_REAL_NAME} PROPERTIES PROJECT_LABEL "Api_PHP" )
  IF (LINUX OR CYGWIN)
    SET_TARGET_PROPERTIES (${SWIG_MODULE_zorba_api_REAL_NAME} PROPERTIES PREFIX "")
  ENDIF (LINUX OR CYGWIN)

  IF (NOT WIN32 OR CYGWIN)
    STRING (REPLACE ${CMAKE_INSTALL_PREFIX} "" PHP5_INSTALL_PATH ${PHP5_EXTENSION_DIR})
    SET (PHP5_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/php5")
    MESSAGE (STATUS "SWIG PHP: PHP module install path: " ${PHP5_INSTALL_PATH})

    INSTALL (
      FILES
        ${CMAKE_CURRENT_BINARY_DIR}/Zorba/XQueryProcessor.php
        ${CMAKE_CURRENT_BINARY_DIR}/Zorba/zorba_api_wrapper.php
        ${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_SWIG_LIB_PREFIX}zorba_api.so
      DESTINATION ${PHP5_INSTALL_PATH}
    )
	ELSE (NOT WIN32 OR CYGWIN)
    IF (MSVC_IDE)
      INSTALL ( FILES 
        ${CMAKE_CURRENT_BINARY_DIR}/Zorba/XQueryProcessor.php
        ${CMAKE_CURRENT_BINARY_DIR}/Zorba/zorba_api_wrapper.php
        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/zorba_api.dll
        COMPONENT "php_swig"
        DESTINATION share/php )
    ELSE (MSVC_IDE)
      INSTALL ( FILES 
        ${CMAKE_CURRENT_BINARY_DIR}/Zorba/XQueryProcessor.php
        ${CMAKE_CURRENT_BINARY_DIR}/Zorba/zorba_api_wrapper.php
        ${CMAKE_CURRENT_BINARY_DIR}/php_zorba_api.dll
        COMPONENT "php_swig"
        DESTINATION share/php )
    ENDIF (MSVC_IDE)
  ENDIF (NOT WIN32 OR CYGWIN)
  ADD_SUBDIRECTORY (tests) 
ENDIF (NOT PHP5_FOUND)
