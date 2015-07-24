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
    ft_types.cpp
    symbol_table.cpp
    xquery_driver.cpp
    query_loc.cpp
    xqdoc_comment.cpp
    parser_helpers.cpp
    zorba_parser_error.cpp)

SET(PARSER_BUILD_SRCS)

###################################################################
# Bison checks 
SET (GENERATE_BISON_FILES TRUE)

MACRO(BISON_VERSION_GREATER a b)
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
ENDMACRO(BISON_VERSION_GREATER)

MACRO(BISON_VERSION_LESS a b)
  COMPARE_VERSION_STRINGS("${a}" "${b}" result)
    IF(result GREATER 0)
        SET (GENERATE_BISON_FILES FALSE)
        MESSAGE(STATUS "Bison: ${a} >  ${b}")
     ELSE(result GREATER 0)
       IF(result LESS 0)
         MESSAGE(STATUS "Bison: ${a} <  ${b}")
       ELSE(result LESS 0)
          MESSAGE(STATUS "Bison: ${a} == ${b}")
       ENDIF(result LESS 0)
     ENDIF(result GREATER 0)
ENDMACRO(BISON_VERSION_LESS)

# Bison lowest and highest supported versions
BISON_VERSION_GREATER("${BISON_VERSION_FULL}" "2.6")
BISON_VERSION_LESS("${BISON_VERSION_FULL}" "3.0")

# Bison 3.0 removed yylval, yyla.value should be used instead
IF(BISON_MAJOR_VERSION GREATER 2)
  SET (YYLVAL_DEFINE "-Dyylval=yyla.value")
ELSE(BISON_MAJOR_VERSION GREATER 2)
  SET (YYLVAL_DEFINE "")
ENDIF(BISON_MAJOR_VERSION GREATER 2)

MACRO(GENERATE_GRAMMAR_FILE PARSER_TYPE)
  SET(TARGET_PATH "${CMAKE_CURRENT_BINARY_DIR}/compiler/parser")
  SET_SOURCE_FILES_PROPERTIES(${TARGET_PATH}/${PARSER_TYPE}.y PROPERTIES GENERATED TRUE)
  STRING(TOUPPER ${PARSER_TYPE} PARSER_DEFINE)
  ADD_CUSTOM_COMMAND(
      OUTPUT ${TARGET_PATH}/${PARSER_TYPE}.y
      COMMAND "printf"
      ARGS "\"%%{\\n#define" "${PARSER_DEFINE}\\n%%}\\n\">${TARGET_PATH}/${PARSER_TYPE}.y"
      COMMAND "cat"
      ARGS "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/parser_y_includes.h" 
            ">>"
           "${TARGET_PATH}/${PARSER_TYPE}.y"
      COMMAND ${CMAKE_CXX_COMPILER} 
      ARGS "-xc++" "-P" "-D${PARSER_DEFINE}" "${YYLVAL_DEFINE}"
           "-E" "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/parser.y"
           ">>" "${TARGET_PATH}/${PARSER_TYPE}.y"
      DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/parser.y" "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/parser_y_includes.h"
    )
  
  BISON_FILE(${TARGET_PATH}/${PARSER_TYPE}.y)
  LIST(APPEND PARSER_BUILD_SRCS ${TARGET_PATH}/${PARSER_TYPE}.cpp)
ENDMACRO(GENERATE_GRAMMAR_FILE PARSER_TYPE)

# Bison setup for the parser
IF (GENERATE_BISON_FILES)
    SET(BISON_GENERATE_DEFINES TRUE)
    IF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compiler/parser")
      FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/compiler/parser")
    ENDIF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compiler/parser")
    
    GENERATE_GRAMMAR_FILE(xquery_parser)
    GENERATE_GRAMMAR_FILE(jsoniq_parser)
    
ELSE (GENERATE_BISON_FILES)
    IF (BISON_EXECUTABLE)
        MESSAGE(STATUS "         GNU Bison's version " ${BISON_VERSION_FULL} " is less than required (2.4) -- the parser will not be regenerated")
    ELSE (BISON_EXECUTABLE)
        MESSAGE(STATUS "         GNU Bison is not available -- the parser will not be regenerated")
    ENDIF (BISON_EXECUTABLE)
    MESSAGE(STATUS "         Using repository files " ${CMAKE_CURRENT_SOURCE_DIR}/xquery_parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/jsoniq_parser.cpp)
    LIST(APPEND PARSER_SRCS xquery_parser.cpp jsoniq_parser.cpp)
ENDIF (GENERATE_BISON_FILES)

###################################################################
# Flex checks 

SET (GENERATE_FLEX_FILES TRUE)

MACRO(COMPARE_FLEX_VERSION a b)
  COMPARE_VERSION_STRINGS("${a}" "${b}" result)
    IF(result LESS 0)
        SET(GENERATE_FLEX_FILES FALSE)
        MESSAGE(STATUS "Flex: ${a} <  ${b}")
     ELSE(result LESS 0)
       IF(result GREATER 0)
         MESSAGE(STATUS "Flex: ${a} >  ${b}")
       ELSE(result GREATER 0)
          MESSAGE(STATUS "Flex: ${a} == ${b}")
       ENDIF(result GREATER 0)
     ENDIF(result LESS 0)
ENDMACRO(COMPARE_FLEX_VERSION)

COMPARE_FLEX_VERSION("${FLEX_VERSION_FULL}" "2.5.35")

MACRO(GENERATE_FLEX_FILE SCANNER_TYPE)
  SET(TARGET_PATH ${CMAKE_CURRENT_BINARY_DIR}/compiler/parser)  
  SET_SOURCE_FILES_PROPERTIES(${TARGET_PATH}/${SCANNER_TYPE}.l PROPERTIES GENERATED TRUE)
  STRING(TOUPPER ${SCANNER_TYPE} SCANNER_DEFINE)
  
  ADD_CUSTOM_COMMAND(
      OUTPUT ${TARGET_PATH}/${SCANNER_TYPE}.l
      COMMAND "printf"
      ARGS "\"%%{\\n#define" "${SCANNER_DEFINE}\\n%%}\\n\">${TARGET_PATH}/${SCANNER_TYPE}.l"
      COMMAND "cat"
      ARGS "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/scanner_l_includes.h" 
            ">>"
           "${TARGET_PATH}/${SCANNER_TYPE}.l"
      COMMAND ${CMAKE_CXX_COMPILER} 
      ARGS "-xc++" "-P" "-D${SCANNER_DEFINE}"
           "-E" "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/scanner.l"
           ">>" "${TARGET_PATH}/${SCANNER_TYPE}.l"
      DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/scanner.l" "${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/scanner_l_includes.h"
    )
    
  FLEX_FILE(${TARGET_PATH}/${SCANNER_TYPE}.l)  
  LIST(APPEND PARSER_BUILD_SRCS ${CMAKE_BINARY_DIR}/src/compiler/parser/${SCANNER_TYPE}.cpp)
ENDMACRO(GENERATE_FLEX_FILE SCANNER_TYPE)


# Flex setup for the scanner
IF (GENERATE_FLEX_FILES AND ZORBA_HAVE_FLEXLEXER_H)
    IF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compiler/parser")
      FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/compiler/parser")
    ENDIF(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compiler/parser")
              
    SET(FLEX_PREFIX_OUTPUTS TRUE)
    ADD_DEFINITIONS(-DFLEX_FILES_REGENERATED)
    
    GENERATE_FLEX_FILE(xquery_scanner)
    GENERATE_FLEX_FILE(jsoniq_scanner)
        
ELSE (GENERATE_FLEX_FILES AND ZORBA_HAVE_FLEXLEXER_H)
    IF (NOT ZORBA_HAVE_FLEXLEXER_H)
        MESSAGE(STATUS "         FlexLexer.h has not been found -- the lexer will not be regenerated")
    ELSE (NOT ZORBA_HAVE_FLEXLEXER_H)
        IF (FLEX_EXECUTABLE)
            MESSAGE(STATUS "         GNU Flex version " ${FLEX_VERSION_FULL} " is less than required (2.5.35) -- the lexer will not be regenerated")
        ELSE (FLEX_EXECUTABLE)
            MESSAGE(STATUS "         GNU Flex is not available -- the lexer will not be regenerated")
        ENDIF (FLEX_EXECUTABLE)
    ENDIF (NOT ZORBA_HAVE_FLEXLEXER_H)
    MESSAGE(STATUS "         Using repository file " ${CMAKE_CURRENT_SOURCE_DIR}/xquery_scanner.cpp ${CMAKE_CURRENT_SOURCE_DIR}/jsoniq_scanner.cpp)
    LIST(APPEND PARSER_SRCS xquery_scanner.cpp jsoniq_scanner.cpp)
ENDIF (GENERATE_FLEX_FILES AND ZORBA_HAVE_FLEXLEXER_H)

# generate a script that copies the generated parser and scanner files from the build
# directory into the source directory
# this script should be used before commiting if one modified the parser/scanner
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/copyparser.sh.cmake ${CMAKE_BINARY_DIR}/copyparser.sh)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/copyparser.sh.cmake -->${CMAKE_BINARY_DIR}/copyparser.sh")
