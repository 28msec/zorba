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
# - Look for GNU flex, the lexer generator.
# Defines the following:
#  FLEX_EXECUTABLE - path to the flex executable
#  FLEX_FILE - parse a file with flex
#  FLEX_PREFIX_OUTPUTS - Set to true to make FLEX_FILE produce outputs of
#                        ${filename}.cpp, not lex.yy.c . Passes -P to flex.
#  FLEX_MAJOR_VERSION  
#  FLEX_MINOR_VERSION
#  FLEX_REVISION_VERSION - Return the flex version
#

IF(NOT DEFINED FLEX_PREFIX_OUTPUTS)
  SET(FLEX_PREFIX_OUTPUTS FALSE)
ENDIF(NOT DEFINED FLEX_PREFIX_OUTPUTS)

IF(NOT FLEX_EXECUTABLE)
  MESSAGE(STATUS "Looking for flex")
  FIND_PROGRAM(FLEX_EXECUTABLE flex)
  IF(FLEX_EXECUTABLE)
    EXEC_PROGRAM(
            ${FLEX_EXECUTABLE}
            ARGS --version
            OUTPUT_VARIABLE FLEX_VERSION)

    # Extract major and minor versions
    STRING (REGEX REPLACE "[^0-9]*([0-9]+)..*" "\\1" FLEX_MAJOR_VERSION_TMP ${FLEX_VERSION})
    STRING (REGEX REPLACE "[^0-9]*[0-9]+\\.([0-9]+).*" "\\1" FLEX_MINOR_VERSION_TMP ${FLEX_VERSION})
    STRING (REGEX REPLACE "[^0-9]*[0-9]+\\.[0-9]+\\.([0-9]+[a-z]*).*" "\\1" FLEX_REVISION_VERSION_TMP ${FLEX_VERSION})
    MESSAGE(STATUS "Found flex -- ${FLEX_EXECUTABLE}, version: " ${FLEX_MAJOR_VERSION_TMP} "." ${FLEX_MINOR_VERSION_TMP} "." ${FLEX_REVISION_VERSION_TMP})
    SET (FLEX_MAJOR_VERSION ${FLEX_MAJOR_VERSION_TMP} CACHE STRING "The flex major version" FORCE)
    SET (FLEX_MINOR_VERSION ${FLEX_MINOR_VERSION_TMP} CACHE STRING "The flex minor version" FORCE)
    SET (FLEX_REVISION_VERSION ${FLEX_REVISION_VERSION_TMP} CACHE STRING "The flex revision version" FORCE)

    # Find the FlexLexer.h header. Try our best to find the one associated
    # with the flex binary we're actually using.
    GET_FILENAME_COMPONENT(_flex_path "${FLEX_EXECUTABLE}" PATH)
    GET_FILENAME_COMPONENT(_flex_hint "${_flex_path}/../include" ABSOLUTE)
    FIND_PATH(FLEX_INCLUDE_DIR FlexLexer.h HINTS "${_flex_hint}")

  ELSE (FLEX_EXECUTABLE)
    SET (FLEX_MAJOR_VERSION "0")
    SET (FLEX_MINOR_VERSION "0")
    SET (FLEX_REVISION_VERSION "0")
  ENDIF(FLEX_EXECUTABLE)
  SET (FLEX_VERSION_FULL ${FLEX_MAJOR_VERSION}.${FLEX_MINOR_VERSION}.${FLEX_REVISION_VERSION} CACHE STRING "The Flex version" FORCE)
ENDIF(NOT FLEX_EXECUTABLE)

IF(FLEX_EXECUTABLE)
  MACRO(FLEX_FILE FILENAME)
    GET_FILENAME_COMPONENT(PATH "${FILENAME}" PATH)
    IF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${PATH}")
      FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${PATH}")
    ENDIF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${PATH}")
    IF(FLEX_PREFIX_OUTPUTS)
      GET_FILENAME_COMPONENT(PREFIX "${FILENAME}" NAME_WE)
    ELSE(FLEX_PREFIX_OUTPUTS)
      SET(PREFIX "yy")
    ENDIF(FLEX_PREFIX_OUTPUTS)
    # If we regenerate the scanner, be sure to copy the corresponding
    # FlexLexer.h as well. Put it in the top-level src/ directory since
    # that path is on the include-directories list; also, that way
    # multiple flex'd files will all share the include file.
    SET(FLEXLEXERH "${CMAKE_CURRENT_BINARY_DIR}/FlexLexer.h")
    ADD_CUSTOM_COMMAND(
      OUTPUT "${FLEXLEXERH}"
      COMMAND "${CMAKE_COMMAND}"
      ARGS -E copy_if_different
         "${FLEX_INCLUDE_DIR}/FlexLexer.h"
         "${FLEXLEXERH}")
    SET(OUTFILE "${PATH}/${PREFIX}.cpp")
    ADD_CUSTOM_COMMAND(
      OUTPUT "${OUTFILE}"
      COMMAND "${FLEX_EXECUTABLE}"
      ARGS -t --debug "${FILENAME}"
      # flex's --outfile doesn't seem to work right, so redirect stdout
          > "${OUTFILE}"
      DEPENDS "${FILENAME}"
         "${FLEXLEXERH}")
    SET_SOURCE_FILES_PROPERTIES("${OUTFILE}" PROPERTIES GENERATED TRUE)
  ENDMACRO(FLEX_FILE)
ENDIF(FLEX_EXECUTABLE)
