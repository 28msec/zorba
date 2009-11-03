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

# macro which should be used for generating module libraries
# this macro will create a shared library in the (build) directory
# from which the macro was invoked. Also, it will generate
# an install command which installs the library in the corresponding
# module directory of the installation directory
MACRO(GENERATE_MODULE_LIBRARY MODULE_NAME FILES LINK_LIBRARIES)
  ADD_LIBRARY(${MODULE_NAME} SHARED ${FILES})
  TARGET_LINK_LIBRARIES(${MODULE_NAME} zorba_simplestore ${LINK_LIBRARIES})
  SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                        ${CMAKE_CURRENT_BINARY_DIR})
  SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES VERSION
                        ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
  SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 0)
  
  # install to include/zorba/modules/com/zorba-xquery/www/modules
  # the include/zorba/modules directory needs to belong to the set of Zorba Module Paths
  FILE(RELATIVE_PATH RELATIVE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules"
        "${CMAKE_CURRENT_SOURCE_DIR}")
  INSTALL(TARGETS ${MODULE_NAME} DESTINATION
           "include/zorba/modules/${RELATIVE_MODULE_PATH}")
ENDMACRO(GENERATE_MODULE_LIBRARY)

# all external module libraries are generated in the directory
# of the corresponding .xq file
ADD_SUBDIRECTORY(com)
ADD_SUBDIRECTORY(org)

IF (CMAKE_MINOR_VERSION STREQUAL "4")
  INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          DESTINATION include/zorba
          PATTERN "*.svn" EXCLUDE
          PATTERN "*.xq")
ELSE (CMAKE_MINOR_VERSION STREQUAL "4")
  INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          DESTINATION include/zorba
          FILES_MATCHING
          PATTERN "*.svn" EXCLUDE
          PATTERN "*.xq")
ENDIF (CMAKE_MINOR_VERSION STREQUAL "4")
