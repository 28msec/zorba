# Copyright 2006-2013 The FLWOR Foundation.
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

SET(phpPath ${CMAKE_BINARY_DIR}/swig/php)
IF (MSVC_IDE)
  SET(phpExtensionPath ${CMAKE_BINARY_DIR}/swig/php/@CMAKE_BUILD_TYPE@)
ELSE (MSVC_IDE)
  SET(phpExtensionPath ${CMAKE_BINARY_DIR}/swig/php)
ENDIF (MSVC_IDE)
SET(phpIncludePath ${CMAKE_BINARY_DIR}/swig/php/Zorba)

IF (WIN32)
  STRING(REGEX REPLACE "/" "\\\\" phpExtensionPath "${phpExtensionPath}")
  STRING(REGEX REPLACE "/" "\\\\" phpPath "${phpPath}")
  STRING(REGEX REPLACE "/" "\\\\" phpIncludePath "${phpIncludePath}")
ENDIF (WIN32)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/php.ini.in ${CMAKE_CURRENT_BINARY_DIR}/php.ini)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/books.xml ${CMAKE_CURRENT_BINARY_DIR}/books.xml COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/satellites.json ${CMAKE_CURRENT_BINARY_DIR}/satellites.json COPYONLY)

#copy tests
FILE(GLOB ZORBA_PHP_TESTS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_CURRENT_SOURCE_DIR}/*.php")
FOREACH(ZORBA_PHP_TEST ${ZORBA_PHP_TESTS})
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/${ZORBA_PHP_TEST}"  "${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_PHP_TEST}")
  STRING(REGEX REPLACE ".php" "" ZORBA_PHP_TEST_NAME "${ZORBA_PHP_TEST}")
  ADD_TEST("php_${ZORBA_PHP_TEST_NAME}" ${PHP5_EXECUTABLE} -c ${CMAKE_CURRENT_BINARY_DIR} ${ZORBA_PHP_TEST})
  SET_TESTS_PROPERTIES("php_${ZORBA_PHP_TEST_NAME}" PROPERTIES PASS_REGULAR_EXPRESSION "Success")
ENDFOREACH(ZORBA_PHP_TEST ${ZORBA_PHP_TESTS})

#copy additional .xq files
FILE(GLOB ZORBA_PHP_XQS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_CURRENT_SOURCE_DIR}/*.xq")
FOREACH(ZORBA_PHP_XQ ${ZORBA_PHP_XQS})
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/${ZORBA_PHP_XQ}"  "${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_PHP_XQ}" COPYONLY)
ENDFOREACH(ZORBA_PHP_XQ ${ZORBA_PHP_XQS})
