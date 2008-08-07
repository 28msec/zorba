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

FIND_PACKAGE(PHP5)

IF(PHP5_FOUND)
  SET(phpPath ${CMAKE_CURRENT_SOURCE_DIR})
  SET(phpExtensionPath ${CMAKE_CURRENT_BINARY_DIR})
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/zorba_api.php.in ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.php)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/simple.php.in ${CMAKE_CURRENT_BINARY_DIR}/simple.php)
  ADD_TEST("php" ${PHP5_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/simple.php)
  INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/simple.php
          DESTINATION
          share/doc/zorba-${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER}/php/examples)
ENDIF(PHP5_FOUND)
