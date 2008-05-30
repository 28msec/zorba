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

SET(PARSER_SRCS
    symbol_table.cpp
    xquery_driver.cpp
    query_loc.cpp
    util.cpp)
    
SET(PARSER_BUILD_SRCS)

###################################################################
# Flex and Bison requirements

SET (BISON_REQUIRED_MAJOR "2")
SET (BISON_REQUIRED_MINOR "3")

SET (FLEX_REQUIRED_MAJOR "2")
SET (FLEX_REQUIRED_MINOR "5")
SET (FLEX_REQUIRED_REVISION "33")


###################################################################
# Bison checks 
SET (GENERATE_BISON_FILES TRUE)


INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeCompareVersionStrings.cmake)

# a and b need to be passed in by value
MACRO(COMPARE_VERSION a b)
  COMPARE_VERSION_STRINGS(${a} ${b} result)
    IF(result LESS 0)
        MESSAGE("${a} <  ${b}")
     ELSE(result LESS 0)
       IF(result GREATER 0)
         MESSAGE("${a} >  ${b}")
       ELSE(result GREATER 0)
          MESSAGE("${a} == ${b}")
       ENDIF(result GREATER 0)
     ENDIF(result LESS 0)
ENDMACRO(COMPARE_VERSION)

MESSAGE(STATUS "bison ${BISON_VERSION_FULL}")

COMPARE_VERSION(${BISON_VERSION_FULL} "2.3")

IF (BISON_MAJOR_VERSION LESS ${BISON_REQUIRED_MAJOR})
	SET (GENERATE_BISON_FILES FALSE)
ELSE (BISON_MAJOR_VERSION LESS ${BISON_REQUIRED_MAJOR})
	IF (BISON_MAJOR_VERSION EQUAL ${BISON_REQUIRED_MAJOR})
		IF (BISON_MINOR_VERSION LESS ${BISON_REQUIRED_MINOR})
			SET (GENERATE_BISON_FILES FALSE)
		ENDIF (BISON_MINOR_VERSION LESS ${BISON_REQUIRED_MINOR})
	ENDIF (BISON_MAJOR_VERSION EQUAL ${BISON_REQUIRED_MAJOR})
ENDIF (BISON_MAJOR_VERSION LESS ${BISON_REQUIRED_MAJOR})

IF (NOT BISON_EXECUTABLE)
	SET (GENERATE_BISON_FILES FALSE)
ENDIF (NOT BISON_EXECUTABLE)


# Bison setup for the parser
IF (GENERATE_BISON_FILES)
	SET(BISON_GENERATE_DEFINES TRUE)
	BISON_FILE(compiler/parser/xquery_parser.y)
	LIST(APPEND PARSER_BUILD_SRCS ${CMAKE_BINARY_DIR}/src/compiler/parser/xquery_parser.cpp)
	INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)
ELSE (GENERATE_BISON_FILES)
	IF (BISON_EXECUTABLE)
		MESSAGE(STATUS "Warning: GNU Bison's version " ${BISON_MAJOR_VERSION} "." ${BISON_MINOR_VERSION} " is less than required (" ${BISON_REQUIRED_MAJOR} "." ${BISON_REQUIRED_MINOR} ") -- the parser will not be regenerated")
		MESSAGE(STATUS "Warning: using repository files " ${CMAKE_CURRENT_SOURCE_DIR}/xquery_parser.cpp)
	ELSE (BISON_EXECUTABLE)
		MESSAGE("-- Warning: GNU Bison not available -- the parser will not be regenerated")
	ENDIF (BISON_EXECUTABLE)
	LIST(APPEND PARSER_SRCS xquery_parser.cpp)
ENDIF (GENERATE_BISON_FILES)

###################################################################
# Flex checks 

SET (GENERATE_FLEX_FILES TRUE)

IF (FLEX_MAJOR_VERSION LESS ${FLEX_REQUIRED_MAJOR}) # major is smaller
	SET (GENERATE_FLEX_FILES FALSE)
ELSE (FLEX_MAJOR_VERSION LESS ${FLEX_REQUIRED_MAJOR})  # major is big enough
	IF (FLEX_MAJOR_VERSION EQUAL ${FLEX_REQUIRED_MAJOR})  # major is equal
		IF (FLEX_MINOR_VERSION LESS ${FLEX_REQUIRED_MINOR}) # minor too small
			SET (GENERATE_FLEX_FILES FALSE)
		ELSE (FLEX_MINOR_VERSION LESS ${FLEX_REQUIRED_MINOR}) # minor is at least equal
			IF (FLEX_MINOR_VERSION EQUAL ${FLEX_REQUIRED_MINOR})
				IF (FLEX_REVISION_VERSION LESS ${FLEX_REQUIRED_REVISION})
					SET (GENERATE_FLEX_FILES FALSE)
				ELSE (FLEX_REVISION_VERSION LESS ${FLEX_REQUIRED_REVISION}) # revision is at least equal
					SET (GENERATE_FLEX_FILES TRUE)
				ENDIF (FLEX_REVISION_VERSION LESS ${FLEX_REQUIRED_REVISION})
			ENDIF (FLEX_MINOR_VERSION EQUAL ${FLEX_REQUIRED_MINOR}) # minor is greater
		ENDIF (FLEX_MINOR_VERSION LESS ${FLEX_REQUIRED_MINOR})
	ELSE (FLEX_MAJOR_VERSION EQUAL ${FLEX_REQUIRED_MAJOR})  # major is bigger
  SET (GENERATE_FLEX_FILES TRUE)
	ENDIF (FLEX_MAJOR_VERSION EQUAL ${FLEX_REQUIRED_MAJOR})
ENDIF (FLEX_MAJOR_VERSION LESS ${FLEX_REQUIRED_MAJOR})

IF (NOT FLEX_EXECUTABLE)
	SET (GENERATE_FLEX_FILES FALSE)
ENDIF (NOT FLEX_EXECUTABLE)

# Flex setup for the scanner
IF (GENERATE_FLEX_FILES)
	SET(FLEX_PREFIX_OUTPUTS TRUE)
	FLEX_FILE(compiler/parser/xquery_scanner.l)
	ADD_DEFINITIONS(-DFLEX_FILES_REGENERATED)
	LIST(APPEND PARSER_BUILD_SRCS ${CMAKE_BINARY_DIR}/src/compiler/parser/xquery_scanner.cpp)
ELSE (GENERATE_FLEX_FILES)
   IF (FLEX_EXECUTABLE)
		MESSAGE(STATUS "Warning: GNU Flex's version " ${FLEX_MAJOR_VERSION} "." ${FLEX_MINOR_VERSION} "." ${FLEX_REVISION_VERSION} " is less than required (" ${FLEX_REQUIRED_MAJOR} "." ${FLEX_REQUIRED_MINOR} "." ${FLEX_REQUIRED_REVISION} ") -- the lexer will not be regenerated")
        MESSAGE(STATUS "Warning: using repository file " ${CMAKE_CURRENT_SOURCE_DIR}/xquery_scanner.cpp)
    ELSE (FLEX_EXECUTABLE)
        MESSAGE("-- Warning: GNU Flex not available -- the lexer will not be regenerated")
    ENDIF (FLEX_EXECUTABLE)
	LIST(APPEND PARSER_SRCS xquery_scanner.cpp)
	INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)
ENDIF (GENERATE_FLEX_FILES)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/copyparser.sh.cmake ${CMAKE_BINARY_DIR}/copyparser.sh)
MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/compiler/parser/copyparser.sh.cmake -->${CMAKE_BINARY_DIR}/copyparser.sh")
