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
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/create-doc-tar.sh.in ${CMAKE_CURRENT_BINARY_DIR}/create-doc-tar.sh)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/create-doc-tar.sh.in -> ${CMAKE_CURRENT_BINARY_DIR}/create-doc-tar.sh") 

IF (WIN32)
  SET (MSVC_PATH_SUFFIX)
  IF (MSVC_IDE)
    SET (MSVC_IDE_PATH_SUFFIX "\\${CMAKE_BUILD_TYPE}")
  ENDIF (MSVC_IDE)
  FILE(TO_NATIVE_PATH "${CMAKE_BINARY_DIR}" WIN_CMAKE_BINARY_DIR)
  
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/win_exec.bat.in ${CMAKE_BINARY_DIR}/win_exec.bat @only)
  MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/win_exec.bat.in -> ${CMAKE_BINARY_DIR}/win_exec.bat") 
  
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/win_exec_cmake.bat.in ${CMAKE_CURRENT_BINARY_DIR}/win_exec_cmake.bat @only)
  MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/win_exec_cmake.bat.in -> ${CMAKE_CURRENT_BINARY_DIR}/win_exec_cmake.bat") 

  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/zorba_cmake.bat.in ${CMAKE_CURRENT_BINARY_DIR}/zorba_cmake.bat @only)
  MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/zorba_cmake.bat.in -> ${CMAKE_BINARY_DIR}/zorba_cmake.bat") 
ENDIF(WIN32)
