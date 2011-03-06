# Copyright 2010 The FLWOR Foundation.
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

IF(NOT WIN32)
  MESSAGE(FATAL_ERROR "This module is intended only for Windows platforms.")
ENDIF(NOT WIN32)

MACRO(PRINT_FIND_TITLE MODULE_NAME)
  SET(STARS "****************************************")
  STRING(LENGTH "${STARS}" STARSLEN)
  STRING(LENGTH "Zorba Find${MODULE_NAME}" TITLELEN)
  MATH(EXPR LEN "(${STARSLEN} - ${TITLELEN} - 2) / 2")
  STRING(SUBSTRING ${STARS} 0 ${LEN} PRESTARS)
  SET(POSTSTARS ${PRESTARS})
  MATH(EXPR TOTALLEN "${TITLELEN} + (${LEN} * 2) + 2")
  IF(NOT(TOTALLEN EQUAL STARSLEN))
    SET(POSTSTARS "${PRESTARS}*")
  ENDIF(NOT(TOTALLEN EQUAL STARSLEN))

  MESSAGE (STATUS ${STARS})
  MESSAGE (STATUS "${PRESTARS} Zorba Find${MODULE_NAME} ${POSTSTARS}")
  MESSAGE (STATUS ${STARS})
ENDMACRO(PRINT_FIND_TITLE MODULE_NAME)


MACRO(FIND_PACKAGE_WIN32 MODULE_NAME SEARCH_NAME)

  IF(NOT WIN32)
    MESSAGE(FATAL_ERROR "This module is intended only for Windows platforms.")
  ENDIF(NOT WIN32)

  PRINT_FIND_TITLE(${MODULE_NAME})

  IF(NOT ZORBA_THIRD_PARTY_REQUIREMENTS)
    MESSAGE (STATUS "ZORBA_THIRD_PARTY_REQUIREMENTS variable is not available. I will try to find ${MODULE_NAME} in: $ENV{ProgramFiles}")
    SET(ZORBA_THIRD_PARTY_REQUIREMENTS $ENV{ProgramFiles})
  ENDIF(NOT ZORBA_THIRD_PARTY_REQUIREMENTS)

  # search for a folder containing SEARCH_NAME in the name in the ZORBA_THIRD_PARTY_REQUIREMENTS path
  FILE(GLOB MATCHED_DIRS "${ZORBA_THIRD_PARTY_REQUIREMENTS}/*${SEARCH_NAME}*")

  # the list of found directories will be added to the paths CMAKE_PREFIX_PATH and
  # thus will be used by the real Find${MODULE_NAME}.cmake module
  SET(CMAKE_PREFIX_PATH)
  FOREACH(DIR ${MATCHED_DIRS})
    MESSAGE (STATUS "${MODULE_NAME} will be searched for in: ${DIR}")
    SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${DIR})
  ENDFOREACH(DIR)

  IF(NOT CMAKE_PREFIX_PATH)
    MESSAGE (STATUS "No candidate ${MODULE_NAME} directory was found in ZORBA_THIRD_PARTY_REQUIREMENTS (${ZORBA_THIRD_PARTY_REQUIREMENTS})")
  ENDIF(NOT CMAKE_PREFIX_PATH)


  # remove the Windows module path to avoid infinite recursion
  LIST(REMOVE_ITEM CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/Windows)

  # call the real Find${MODULE_NAME}.cmake module
  FIND_PACKAGE(${MODULE_NAME})

  # restore the module path
  SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/Windows ${CMAKE_MODULE_PATH})

ENDMACRO(FIND_PACKAGE_WIN32)
