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

IF (NOT WIN32)
  MESSAGE (FATAL_ERROR "This module is intended only for Windows platforms.")
ENDIF (NOT WIN32)

MACRO (PRINT_FIND_TITLE MODULE_NAME)
  SET (STARS "****************************************")
  STRING (LENGTH "${STARS}" STARSLEN)
  STRING (LENGTH "Zorba Find${MODULE_NAME}" TITLELEN)
  MATH (EXPR LEN "(${STARSLEN} - ${TITLELEN} - 2) / 2")
  STRING (SUBSTRING ${STARS} 0 ${LEN} PRESTARS)
  SET (POSTSTARS ${PRESTARS})
  MATH (EXPR TOTALLEN "${TITLELEN} + (${LEN} * 2) + 2")
  IF (NOT(TOTALLEN EQUAL STARSLEN))
    SET (POSTSTARS "${PRESTARS}*")
  ENDIF (NOT(TOTALLEN EQUAL STARSLEN))

  MESSAGE (STATUS ${STARS})
  MESSAGE (STATUS "${PRESTARS} Zorba Find${MODULE_NAME} ${POSTSTARS}")
  MESSAGE (STATUS ${STARS})
ENDMACRO (PRINT_FIND_TITLE MODULE_NAME)


MACRO (FIND_PACKAGE_WIN32 MODULE_NAME SEARCH_NAMES)

  IF (NOT WIN32)
    MESSAGE(FATAL_ERROR "This module is intended only for Windows platforms.")
  ENDIF (NOT WIN32)

  PRINT_FIND_TITLE (${MODULE_NAME})

  # if not already provided add the program files directory
  SET (SEARCH_PATHS ${ZORBA_THIRD_PARTY_REQUIREMENTS})
  LIST (FIND SEARCH_PATHS "$ENV{ProgramFiles}" PRORAM_FILES_FOUND)
  IF (PRORAM_FILES_FOUND EQUAL -1)
    SET (SEARCH_PATHS "${SEARCH_PATHS}" "$ENV{ProgramFiles}")
  ENDIF (PRORAM_FILES_FOUND EQUAL -1)

  SET (PATH_REGEX)
  FOREACH (PATH ${SEARCH_PATHS})
    FILE (TO_CMAKE_PATH "${PATH}" PATH)
    FOREACH (NAME ${SEARCH_NAMES})
      SET (PATH_REGEX ${PATH_REGEX} "${PATH}/*${NAME}*")
    ENDFOREACH (NAME)
  ENDFOREACH (PATH)

  # search the SEARCH_PATHS for folders containing one of the names in SEARCH_NAMES
  FILE (GLOB MATCHED_DIRS ${PATH_REGEX})

  # the list of found directories will be added to the paths CMAKE_PREFIX_PATH and
  # thus will be used by the real Find${MODULE_NAME}.cmake module
  SET (CMAKE_PREFIX_PATH)
  FOREACH (DIR ${MATCHED_DIRS})
    MESSAGE (STATUS "${MODULE_NAME} will be searched for in: [ZORBA_THIRD_PARTY_REQUIREMENTS] ${DIR}")
    SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${DIR})
  ENDFOREACH (DIR)

  # add all the paths from the PATH environment variable that contain one of the names in SEARCH_NAMES
  FOREACH (PATH $ENV{PATH})
    FILE (TO_CMAKE_PATH "${PATH}" PATH)
    STRING (TOLOWER "${PATH}" LC_PATH)

    # now iterate over all the possible names
    FOREACH (NAME ${SEARCH_NAMES})
      STRING (TOLOWER "${NAME}" LC_NAME)
      IF ("${LC_PATH}" MATCHES ".*${LC_NAME}.*")
        IF (EXISTS "${PATH}/include")
          MESSAGE (STATUS "${MODULE_NAME} will be searched for in: [PATH environment variable] ${PATH}")
          SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${PATH})
        ELSEIF (EXISTS "${PATH}/../include")
          MESSAGE (STATUS "${MODULE_NAME} will be searched for in: [PATH environment variable] ${PATH}/..")
          SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${PATH}/..)
        ENDIF (EXISTS "${PATH}/include")
      ENDIF ("${LC_PATH}" MATCHES ".*${LC_NAME}.*")
    ENDFOREACH (NAME)
  ENDFOREACH (PATH)

  # print some help
  IF (NOT CMAKE_PREFIX_PATH)
    MESSAGE (STATUS "No candidate ${MODULE_NAME} directory was found in the paths: ${SEARCH_PATHS};%PATH%")
    MESSAGE (STATUS "You might wanna check:")
    MESSAGE (STATUS "  1. Did you set ZORBA_THIRD_PARTY_REQUIREMENTS properly?")
    MESSAGE (STATUS "  2. Is your ${MODULE_NAME} directory matching one of the search names: ${SEARCH_NAMES} ?")
    MESSAGE (STATUS "  3. Is ${MODULE_NAME} or its \"bin\" directory in the PATH environment variable?")
  ENDIF (NOT CMAKE_PREFIX_PATH)

  # remove the Windows module path (both from Zorba or the external modules)
  # to avoid an infinite recursion
  FOREACH (PATH ${CMAKE_MODULE_PATH})
    IF ("${PATH}" MATCHES ".*/cmake_modules/Windows")
      LIST (REMOVE_ITEM CMAKE_MODULE_PATH "${PATH}")
    ENDIF ("${PATH}" MATCHES ".*/cmake_modules/Windows")
  ENDFOREACH (PATH)

  # call the real Find${MODULE_NAME}.cmake module
  FIND_PACKAGE (${MODULE_NAME})

  # restore the module path
  SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/Windows ${CMAKE_MODULE_PATH})

ENDMACRO (FIND_PACKAGE_WIN32)


MACRO(FIND_PACKAGE_DLLS_WIN32 DLL_NAMES)

  IF (NOT WIN32)
    MESSAGE(FATAL_ERROR "This module is intended only for Windows platforms.")
  ENDIF (NOT WIN32)

  FOREACH (NAME ${DLL_NAMES})

    FIND_FILE (
      ${NAME}
      "${NAME}"
      PATHS "${CMAKE_PREFIX_PATH}"
      PATH_SUFFIXES "bin"
      NO_DEFAULT_PATH
    )
    SET(FOUND_DLL "${${NAME}}")
    
    IF (FOUND_DLL AND EXISTS ${FOUND_DLL})
      LIST (APPEND ZORBA_REQUIRED_DLLS "${FOUND_DLL}")
      MESSAGE(STATUS "Added dll to ZORBA_REQUIRED_DLLS: ${${NAME}}")
      STRING (REPLACE "/${NAME}" "" PATH "${FOUND_DLL}")
      FILE(TO_NATIVE_PATH ${PATH} NATIVE_PATH)
      LIST (APPEND ZORBA_REQUIRED_DLL_PATHS "${NATIVE_PATH}")
    ELSE (FOUND_DLL AND EXISTS ${FOUND_DLL})
      MESSAGE (WARNING "${NAME} was not found in: ${CMAKE_PREFIX_PATH}. Zorba will not run unless you have it in the path.")
    ENDIF (FOUND_DLL AND EXISTS ${FOUND_DLL})
    
  ENDFOREACH (NAME)

  LIST(REMOVE_DUPLICATES ZORBA_REQUIRED_DLL_PATHS)

ENDMACRO(FIND_PACKAGE_DLLS_WIN32)
