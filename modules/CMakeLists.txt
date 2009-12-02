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
MACRO(GENERATE_MODULE_LIBRARY MODULE_NAME LINK_LIBRARIES)

  # all the cpp files found in the ${MODULE_NAME}.xq.src
  # directory are added to the sources list
  FILE(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}.xq.src/*.cpp")

  MESSAGE(STATUS "Add library " ${MODULE_NAME})
  ADD_LIBRARY(${MODULE_NAME} SHARED ${SRC_FILES})
  TARGET_LINK_LIBRARIES(${MODULE_NAME} zorba_simplestore ${LINK_LIBRARIES})
  # the shared libraries are considered RUNTIME on WIN32 platforms
  # and LIBRARY on UNIX-based platforms
  IF (WIN32)
    SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                        ${CMAKE_CURRENT_BINARY_DIR})
    # in VS, the dll's are generated in the $(ConfigurationName) directory,
    # so we have to copy these dll's one level up in the ${CMAKE_CURRENT_BINARY_DIR}
    # the commands below use VS macro expansions $(...)
    IF (MSVC_IDE)
      # if we change something in the project generating this target, make
      # sure we don't have a zombie DLL hanging around from an older build
      ADD_CUSTOM_COMMAND(TARGET ${MODULE_NAME} PRE_BUILD COMMAND
          if exist "\"$(ProjectDir)\\$(TargetFileName)\"" del "\"$(ProjectDir)\\$(TargetFileName)\"")
      ADD_CUSTOM_COMMAND(TARGET ${MODULE_NAME} POST_BUILD COMMAND
          copy "\"$(TargetPath)\"" "\"$(ProjectDir)\"")
    ENDIF (MSVC_IDE)
  ELSE (WIN32)
    SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                        ${CMAKE_CURRENT_BINARY_DIR})
  ENDIF (WIN32)
  SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES VERSION
                        ${ZORBA_MAJOR_NUMBER}.${ZORBA_MINOR_NUMBER}.${ZORBA_PATCH_NUMBER})  
  SET_TARGET_PROPERTIES(${MODULE_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 0)

  # install to include/zorba/modules/com/zorba-xquery/www/modules
  # the include/zorba/modules directory needs to belong to the set of Zorba Module Paths
  FILE(RELATIVE_PATH RELATIVE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" "${CMAKE_CURRENT_SOURCE_DIR}")
  IF (WIN32)
    INSTALL(TARGETS ${MODULE_NAME}
            RUNTIME
            DESTINATION "include/zorba/modules/${RELATIVE_MODULE_PATH}")
  ELSE (WIN32)
    INSTALL(TARGETS ${MODULE_NAME}
            LIBRARY
            DESTINATION "include/zorba/modules/${RELATIVE_MODULE_PATH}")
  ENDIF (WIN32)
ENDMACRO(GENERATE_MODULE_LIBRARY)

# all external module libraries are generated in the directory
# of the corresponding .xq file
MESSAGE(STATUS "Add com")
ADD_SUBDIRECTORY(com)
MESSAGE(STATUS "Add org")
ADD_SUBDIRECTORY(org)

IF (CMAKE_MINOR_VERSION STREQUAL "4")
  INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          DESTINATION include/zorba
          PATTERN "*.svn" EXCLUDE
          PATTERN "*.xq.src" EXCLUDE
          PATTERN "*.xq")
ELSE (CMAKE_MINOR_VERSION STREQUAL "4")
  INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          DESTINATION include/zorba
          FILES_MATCHING
          PATTERN "*.svn" EXCLUDE
          PATTERN "*.xq.src" EXCLUDE
          PATTERN "*.xq")
ENDIF (CMAKE_MINOR_VERSION STREQUAL "4")

MESSAGE(STATUS "End modules")
