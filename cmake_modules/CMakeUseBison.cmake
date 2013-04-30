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
# - Look for GNU Bison, the parser generator
# Defines the following:
#  BISON_EXECUTABLE - path to the bison executable
#  BISON_FILE - parse a file with bison
#  BISON_PREFIX_OUTPUTS - Set to true to make BISON_FILE produce prefixed
#                         symbols in the generated output based on filename.
#                         So for ${filename}.y, you'll get ${filename}parse(), etc.
#                         instead of yyparse().
#  BISON_GENERATE_DEFINES - Set to true to make BISON_FILE output the matching
#                           .h file for a .c file. You want this if you're using
#                           flex.
#  BISON_VERSION          - Returns the Bison version
#  BISON_MAJOR_VERSION    - Returns the Bison major version
#  BISON_MINOR_VERSION    - Returns the Bison minor version 
#


IF(NOT DEFINED BISON_PREFIX_OUTPUTS)
  SET(BISON_PREFIX_OUTPUTS FALSE)
ENDIF(NOT DEFINED BISON_PREFIX_OUTPUTS)

IF(NOT DEFINED BISON_GENERATE_DEFINES)
  SET(BISON_GENERATE_DEFINES FALSE)
ENDIF(NOT DEFINED BISON_GENERATE_DEFINES)

IF(NOT BISON_EXECUTABLE)
  MESSAGE(STATUS "Looking for bison")
  FIND_PROGRAM(BISON_EXECUTABLE bison)
  IF(BISON_EXECUTABLE)
    EXEC_PROGRAM(
	    	${BISON_EXECUTABLE}  
        	ARGS --version
        	OUTPUT_VARIABLE BISON_VERSION)

		# Extract major and minor versions
        STRING (REGEX REPLACE "[^0-9]*([0-9]+)..*" "\\1" BISON_MAJOR_VERSION_TMP ${BISON_VERSION})
		    STRING (REGEX REPLACE "[^0-9]*[0-9]+\\.([0-9]+).*" "\\1" BISON_MINOR_VERSION_TMP ${BISON_VERSION})
        MESSAGE(STATUS "Found bison -- ${BISON_EXECUTABLE}, version: " ${BISON_MAJOR_VERSION_TMP} "." ${BISON_MINOR_VERSION_TMP})
        SET (BISON_MAJOR_VERSION ${BISON_MAJOR_VERSION_TMP} CACHE STRING "The Bison major version" FORCE)
        SET (BISON_MINOR_VERSION ${BISON_MINOR_VERSION_TMP} CACHE STRING "The Bison minor version" FORCE)
  ELSE (BISON_EXECUTABLE)
  	SET (BISON_MAJOR_VERSION "0")
	SET (BISON_MINOR_VERSION "0")
  ENDIF(BISON_EXECUTABLE)
  SET (BISON_VERSION_FULL ${BISON_MAJOR_VERSION}.${BISON_MINOR_VERSION} CACHE STRING "The Bison version"  FORCE)
ENDIF(NOT BISON_EXECUTABLE)

IF(BISON_EXECUTABLE)
  MACRO(BISON_FILE FILENAME)
    GET_FILENAME_COMPONENT(PATH "${FILENAME}" PATH)
    GET_FILENAME_COMPONENT(HEAD "${FILENAME}" NAME_WE)
    IF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${PATH}")
      FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${PATH}")
    ENDIF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${PATH}")
    IF(BISON_PREFIX_OUTPUTS)
      SET(PREFIX "${HEAD}")
    ELSE(BISON_PREFIX_OUTPUTS)
      SET(PREFIX "yy")
    ENDIF(BISON_PREFIX_OUTPUTS)
    SET(OUTFILE "${PATH}/${HEAD}.cpp")
    IF(BISON_GENERATE_DEFINES)
      SET(HEADER "${PATH}/${HEAD}.hpp")
      SET(LOCATION "${PATH}/location.hh")
      SET(POSITION "${PATH}/position.hh")
      SET(STACK "${PATH}/stack.hh")
	  
      ADD_CUSTOM_COMMAND(
        OUTPUT "${OUTFILE}" "${HEADER}" "${LOCATION}" "${POSITION}" "${STACK}"
        COMMAND "${BISON_EXECUTABLE}"
        ARGS "--name-prefix=${PREFIX}"
        "--defines"
        "-t"
        "-rall"
        "--locations"
        "--output-file=${OUTFILE}"
        "${FILENAME}"
        DEPENDS "${FILENAME}")
      SET_SOURCE_FILES_PROPERTIES("${OUTFILE}" "${HEADER}" "${LOCATION}" "${POSITION}" "${STACK}" PROPERTIES GENERATED TRUE)
      SET_SOURCE_FILES_PROPERTIES("${HEADER}" "${LOCATION}" "${POSITION}" "${STACK}" PROPERTIES HEADER_FILE_ONLY TRUE)
    ELSE(BISON_GENERATE_DEFINES)
      ADD_CUSTOM_COMMAND(
        OUTPUT "${OUTFILE}"
        COMMAND "${BISON_EXECUTABLE}"
        ARGS "--name-prefix=${PREFIX}"
        "--output-file=${OUTFILE}"
        "${FILENAME}"
        DEPENDS "${FILENAME}")
      SET_SOURCE_FILES_PROPERTIES("${OUTFILE}" PROPERTIES GENERATED TRUE)
    ENDIF(BISON_GENERATE_DEFINES)
  ENDMACRO(BISON_FILE)
ENDIF(BISON_EXECUTABLE)
