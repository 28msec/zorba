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
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeUseBison.cmake)
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeUseFlex.cmake)
INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeCompareVersionStrings.cmake)

SET(PARSER_SRCS
    symbol_table.cpp
    xquery_driver.cpp
    query_loc.cpp
    util.cpp)
    
SET(PARSER_BUILD_SRCS)

###################################################################
# Bison checks 
SET (GENERATE_BISON_FILES TRUE)

MACRO(COMPARE_BISON_VERSION a b)
  COMPARE_VERSION_STRINGS("${a}" "${b}" result)
    IF(result LESS 0)
	    SET (GENERATE_BISON_FILES FALSE)
        MESSAGE(STATUS "Bison: ${a} <  ${b}")
     ELSE(result LESS 0)
       IF(result GREATER 0)
         MESSAGE(STATUS "Bison: ${a} >  ${b}")
       ELSE(result GREATER 0)
          MESSAGE(STATUS "Bison: ${a} == ${b}")
       ENDIF(result GREATER 0)
     ENDIF(result LESS 0)
ENDMACRO(COMPARE_BISON_VERSION)

COMPARE_BISON_VERSION("${BISON_VERSION_FULL}" "2.3")

# Bison setup for the parser
IF (GENERATE_BISON_FILES)
	SET(BISON_GENERATE_DEFINES TRUE)
	BISON_FILE(compiler/parser/xquery_parser.y)
	LIST(APPEND PARSER_BUILD_SRCS ${CMAKE_BINARY_DIR}/src/compiler/parser/xquery_parser.cpp)
	INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)
ELSE (GENERATE_BISON_FILES)
	IF (BISON_EXECUTABLE)
		MESSAGE(STATUS "Warning: GNU Bison's version " ${BISON_VERSION_FULL} "is less than required (2.3) -- the parser will not be regenerated")
		MESSAGE(STATUS "Warning: using repository files " ${CMAKE_CURRENT_SOURCE_DIR}/xquery_parser.cpp)
	ELSE (BISON_EXECUTABLE)
		MESSAGE("-- Warning: GNU Bison not available -- the parser will not be regenerated")
	ENDIF (BISON_EXECUTABLE)
	LIST(APPEND PARSER_SRCS xquery_parser.cpp)
ENDIF (GENERATE_BISON_FILES)

###################################################################
# Flex checks 

SET (GENERATE_FLEX_FILES TRUE)

MACRO(COMPARE_FLEX_VERSION a b)
  COMPARE_VERSION_STRINGS("${a}" "${b}" result)
    IF(result LESS 0)
	      SET (GENERATE_FLEX_FILES FALSE)
        MESSAGE(STATUS "Flex: ${a} <  ${b}")
     ELSE(result LESS 0)
       IF(result GREATER 0)
         MESSAGE(STATUS "Flex: ${a} >  ${b}")
       ELSE(result GREATER 0)
          MESSAGE(STATUS "Flex: ${a} == ${b}")
       ENDIF(result GREATER 0)
     ENDIF(result LESS 0)
ENDMACRO(COMPARE_FLEX_VERSION)

COMPARE_FLEX_VERSION("${FLEX_VERSION_FULL}" "2.5.33")

# Flex setup for the scanner
IF (GENERATE_FLEX_FILES AND ZORBA_HAVE_FLEXLEXER_H)
	SET(FLEX_PREFIX_OUTPUTS TRUE)
	FLEX_FILE(compiler/parser/xquery_scanner.l)
	ADD_DEFINITIONS(-DFLEX_FILES_REGENERATED)
	LIST(APPEND PARSER_BUILD_SRCS ${CMAKE_BINARY_DIR}/src/compiler/parser/xquery_scanner.cpp)
ELSE (GENERATE_FLEX_FILES AND ZORBA_HAVE_FLEXLEXER_H)
	IF (NOT ZORBA_HAVE_FLEXLEXER_H)
    	MESSAGE(STATUS "Warning: FlexLexer.h has not been found -- the lexer will not be regenerated")
    ELSE (NOT ZORBA_HAVE_FLEXLEXER_H)
		IF (FLEX_EXECUTABLE)
			MESSAGE(STATUS "Warning: GNU Flex's version " ${FLEX_VERSION_FULL} " is less than required (2.5.33) -- the lexer will not be regenerated")
    	ELSE (FLEX_EXECUTABLE)
    	    MESSAGE("-- Warning: GNU Flex not available -- the lexer will not be regenerated")
    	ENDIF (FLEX_EXECUTABLE)
    ENDIF (NOT ZORBA_HAVE_FLEXLEXER_H)
    MESSAGE(STATUS "Warning: using repository file " ${CMAKE_CURRENT_SOURCE_DIR}/xquery_scanner.cpp)
	LIST(APPEND PARSER_SRCS xquery_scanner.cpp)
	INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)
ENDIF (GENERATE_FLEX_FILES AND ZORBA_HAVE_FLEXLEXER_H)

# generate a script that copies the generated parser and scanner files from the build
# directory into the source directory
# this script should be used before commiting if one modified the parser/scanner
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/copyparser.sh.cmake ${CMAKE_BINARY_DIR}/copyparser.sh)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/copyparser.sh.cmake -->${CMAKE_BINARY_DIR}/copyparser.sh")
