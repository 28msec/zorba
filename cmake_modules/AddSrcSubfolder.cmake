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
# Adds source files from a subfolder to a list of sources. Works 
# recursively. It will also create source groups with files and headers
# for use with MSVC.
#
# Syntax:
#
#  ADD_SRC_SUBFOLDER(DESTINATION_SRCS SUBFOLDER SOURCES_LIST1 SOURCES_LIST2 ...)
#
#    DESTINATION_SRCS - the list to which the sources in the subfolder will be added to
#    SUBFOLDER - the name of the subfolder
#    SOURCES_LISTx - the name of the list that contains the sources in the subfolder
#


MACRO (ADD_SRC_SUBFOLDER DESTINATION_SRCS SUBFOLDER ...)
	GET_PATHS(${SUBFOLDER})

    INCLUDE (${REL_PATH}/CMakeLists.txt) 		# side-effects!
	
	GET_PATHS(${SUBFOLDER})
		
	FILE (GLOB HEADER_FILES RELATIVE ${ABS_PATH}/${SUBFOLDER} ${REL_PATH}/*.h)
	IF (NOT HEADER_FILES STREQUAL "")
		SOURCE_GROUP (${SUBFOLDER} FILES ${SUBFOLDER}/${HEADER_FILES})	
		LIST (APPEND ${ARGV2} ${HEADER_FILES})
	ENDIF (NOT HEADER_FILES STREQUAL "")
    

	SET(SUB_SRCS_LIST ${ARGV2} ${ARGN})

	FOREACH (SUB_SRCS ${SUB_SRCS_LIST})
		FOREACH (SRCS ${${SUB_SRCS}})
			SOURCE_GROUP (${SUBFOLDER} FILES ${SUBFOLDER}/${SRCS})
			LIST(APPEND ${DESTINATION_SRCS} ${SUBFOLDER}/${SRCS})
		ENDFOREACH (SRCS ${${SUB_SRCS}})
	ENDFOREACH (SUB_SRCS ${SUB_SRCS_LIST})
ENDMACRO (ADD_SRC_SUBFOLDER DESTINATION_SRCS SUBFOLDER ...)


# Macro that sets the ABS_PATH and REL_PATH *globals* 
MACRO (GET_PATHS SUBFOLDER)
	FILE(RELATIVE_PATH REL_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_LIST_FILE})
	GET_FILENAME_COMPONENT(REL_PATH ${REL_PATH} PATH)
	GET_FILENAME_COMPONENT(ABS_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)

	IF (REL_PATH STREQUAL "")
		SET(REL_PATH ${SUBFOLDER})
	ELSE (REL_PATH STREQUAL "")
		SET(REL_PATH ${REL_PATH}/${SUBFOLDER})
	ENDIF (REL_PATH STREQUAL "")
ENDMACRO (GET_PATHS SUBFOLDER)


# Prints out a CMake list
MACRO(PRINT_LIST LIST)
	FOREACH (ITEM ${${LIST}})
		MESSAGE(${LIST} ": " ${ITEM})
	ENDFOREACH (ITEM ${${LIST}})
ENDMACRO(PRINT_LIST LIST)


# Adds header files from the given subfolder to a SOURCE_GROUP, for use with MSVC
MACRO (HEADER_GROUP_SUBFOLDER DESTINATION_SRCS SUBFOLDER)
	GET_PATHS(${SUBFOLDER})
	FILE (GLOB HEADER_FILES RELATIVE ${ABS_PATH} ${REL_PATH}/*.h)

	IF (NOT HEADER_FILES STREQUAL "")
		SOURCE_GROUP (${SUBFOLDER} FILES ${SUBFOLDER}/${HEADER_FILES})	
		LIST (APPEND ${DESTINATION_SRCS} ${HEADER_FILES})
	ENDIF (NOT HEADER_FILES STREQUAL "")
ENDMACRO (HEADER_GROUP_SUBFOLDER SUBFOLDER)
