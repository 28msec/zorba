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

IF(PHP5_FOUND)

  MESSAGE(STATUS "PHP Found, installing examples...")
  
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
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/simple.php.in ${CMAKE_CURRENT_BINARY_DIR}/simple.php)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/test.php.in ${CMAKE_CURRENT_BINARY_DIR}/test.php)
  
  IF (NOT WIN32)  #Disabled, on windows there is a bug in php - Segfault within Try..Catch
    ADD_TEST("php1" ${PHP5_EXECUTABLE} -c ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/simple.php)
  ENDIF (NOT WIN32)
    
  ADD_TEST("php2" ${PHP5_EXECUTABLE} -c ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/test.php)
  
  INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/simple.php ${CMAKE_CURRENT_BINARY_DIR}/test.php
          COMPONENT "php_examples"
          DESTINATION
          share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/php/examples)
ENDIF(PHP5_FOUND)
