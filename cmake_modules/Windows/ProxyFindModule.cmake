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


MACRO (GET_STARS VAR_NAME)
  SET (${VAR_NAME} "****************************************")
ENDMACRO (GET_STARS)


MACRO (PRINT_FIND_END_TITLE MODULE_NAME LOCATION_VAR)
  IF (${LOCATION_VAR})
    MESSAGE (STATUS "************* DONE (found) *************")
    MESSAGE (STATUS "Using ${MODULE_NAME} from: ${${LOCATION_VAR}}")
  ELSE (${LOCATION_VAR})
    MESSAGE (STATUS "*********** DONE (not found) ***********")
  ENDIF (${LOCATION_VAR})
ENDMACRO (PRINT_FIND_END_TITLE)


MACRO (PRINT_FIND_END_TITLE_SYSTEM MODULE_NAME FOUND)
  IF (${FOUND})
    MESSAGE (STATUS "************* DONE (found) *************")
  ELSE (${FOUND})
    MESSAGE (STATUS "*********** DONE (not found) ***********")
  ENDIF (${FOUND})
ENDMACRO (PRINT_FIND_END_TITLE_SYSTEM)


MACRO (INSTALL_DLL DLL_PATH)
  IF (${PROJECT_NAME} STREQUAL "zorba")
    # for zorba core requirements, install this DLL
    INSTALL (PROGRAMS ${DLL_PATH} DESTINATION bin)
  ELSE (${PROJECT_NAME} STREQUAL "zorba")
    # for zorba non-core requirements, install this DLL only if the component is spcified
    STRING (REPLACE "-" "_"  component_name ${PROJECT_NAME})
    INSTALL (PROGRAMS ${DLL_PATH} DESTINATION bin COMPONENT ${component_name})
  ENDIF (${PROJECT_NAME} STREQUAL "zorba")
ENDMACRO (INSTALL_DLL)


MACRO (PRINT_FIND_TITLE MODULE_NAME)
  GET_STARS ("STARS")
  STRING (LENGTH "${STARS}" STARSLEN)
  STRING (LENGTH "Zorba Find${MODULE_NAME}" TITLELEN)
  MATH (EXPR LEN "(${STARSLEN} - ${TITLELEN} - 2) / 2")
  STRING (SUBSTRING ${STARS} 0 ${LEN} PRESTARS)
  SET (POSTSTARS ${PRESTARS})
  MATH (EXPR TOTALLEN "${TITLELEN} + (${LEN} * 2) + 2")
  IF (NOT(TOTALLEN EQUAL STARSLEN))
    SET (POSTSTARS "${PRESTARS}*")
  ENDIF (NOT(TOTALLEN EQUAL STARSLEN))

  MESSAGE (STATUS "${STARS}")
  MESSAGE (STATUS "${PRESTARS} Zorba Find${MODULE_NAME} ${POSTSTARS}")
  MESSAGE (STATUS "${STARS}")
ENDMACRO (PRINT_FIND_TITLE MODULE_NAME)


# This macro will try to find a third party library on Windows.
# The parameters must be given the arguments using the following pattern:
#   PARAM_NAME1 param_value1 PARAM_NAME2 param_value1 param_value2 ...
# This macro will further call PARSE_ARGUMENTS to parse it's arguments.
# In the patter above, PARAM_NAME1 will go in the single value parameter pool
# while PARAM_NAME2 will go in the multiple value parameter pool.
#
# Therefore the following parameter names must be provided to this macro:
# Parameters:
#   NAME
#     - mandatory, single value
#     - the value following it will be used to build the CMake module file name.
#     - e.g.: providing NAME "ICU" as parameters, FindICU.cmake will be used for the search.
#   FOUND_VAR
#     - mandatory, single value
#     - the variable that the FindXXX.cmake module sets if the library is found
#     - e.g.: FOUND_VAR "XERCESC_FOUND" when trying to find XercesC
#   SEARCH_NAMES
#     - mandatory, multiple value
#     - the possible directory name fragments that this library can have
#     - e.g.: SEARCH_NAMES "icu" "i_c_u" "uci"
#   COMPONENTS
#     - optional, multiple value
#
# Once done this will define:
#   FOUND_LOCATION - The directory where the library was found
#
MACRO (FIND_PACKAGE_WIN32)

  IF (NOT WIN32)
    MESSAGE (FATAL_ERROR "This macro is intended only for Windows platforms.")
  ENDIF (NOT WIN32)

  PARSE_ARGUMENTS(MODULE "SEARCH_NAMES;COMPONENTS" "NAME;FOUND_VAR" "" ${ARGN})
  
  IF(NOT MODULE_NAME)
    MESSAGE (FATAL_ERROR "'NAME' argument is required")
  ENDIF(NOT MODULE_NAME)
  IF(NOT MODULE_FOUND_VAR)
    MESSAGE (FATAL_ERROR "'FOUND_VAR' argument is required")
  ENDIF(NOT MODULE_FOUND_VAR)
  IF(NOT MODULE_SEARCH_NAMES)
    MESSAGE (FATAL_ERROR "'SEARCH_NAMES' argument is required")
  ENDIF(NOT MODULE_SEARCH_NAMES)
  
  PRINT_FIND_TITLE (${MODULE_NAME})
  
  # reset the output variable where the target library is found
  SET (FOUND_LOCATION)

  # if not already provided add the program files directory
  SET (SEARCH_PATHS ${ZORBA_THIRD_PARTY_REQUIREMENTS})

  STRING (REGEX MATCHALL "machine:x64" MACHINE_X64_FOUND "${CMAKE_EXE_LINKER_FLAGS}")
  IF(MACHINE_X64_FOUND)
    LIST (FIND SEARCH_PATHS "C:/Program Files" PRORAM_FILES_FOUND)
    IF (PRORAM_FILES_FOUND EQUAL -1)
      SET (SEARCH_PATHS "${SEARCH_PATHS}" "C:/Program Files")
    ENDIF (PRORAM_FILES_FOUND EQUAL -1)
  ELSE(MACHINE_X64_FOUND)
    LIST (FIND SEARCH_PATHS "$ENV{ProgramFiles}" PRORAM_FILES_FOUND)
    IF (PRORAM_FILES_FOUND EQUAL -1)
      SET (SEARCH_PATHS "${SEARCH_PATHS}" "$ENV{ProgramFiles}")
    ENDIF (PRORAM_FILES_FOUND EQUAL -1)
  ENDIF(MACHINE_X64_FOUND)
  
  
  LIST (FIND SEARCH_PATHS "$ENV{ProgramFiles}" PRORAM_FILES_FOUND)
  IF (PRORAM_FILES_FOUND EQUAL -1)
    SET (SEARCH_PATHS "${SEARCH_PATHS}" "$ENV{ProgramFiles}")
  ENDIF (PRORAM_FILES_FOUND EQUAL -1)

  SET (PATH_REGEX)
  FOREACH (PATH ${SEARCH_PATHS})
    FILE (TO_CMAKE_PATH "${PATH}" PATH)
    FOREACH (NAME ${MODULE_SEARCH_NAMES})
      SET (PATH_REGEX ${PATH_REGEX} "${PATH}/*${NAME}*")
    ENDFOREACH (NAME)
  ENDFOREACH (PATH)

  # search the SEARCH_PATHS for folders containing one of the names in SEARCH_NAMES
  FILE (GLOB MATCHED_DIRS ${PATH_REGEX})

  # the list to gather all the prefix paths to be searched
  SET (LIST_CMAKE_PREFIX_PATH)

  # the list of found directories will be added to the paths LIST_CMAKE_PREFIX_PATH and
  # thus will be used by the real Find${MODULE_NAME}.cmake module
  FOREACH (DIR ${MATCHED_DIRS})
    MESSAGE (STATUS "${MODULE_NAME} will be searched for in: [ZORBA_THIRD_PARTY_REQUIREMENTS] ${DIR}")
    SET (LIST_CMAKE_PREFIX_PATH ${LIST_CMAKE_PREFIX_PATH} ${DIR})
  ENDFOREACH (DIR)

  # add all the paths from the PATH environment variable that contain one of the names in SEARCH_NAMES
  FOREACH (PATH $ENV{PATH})
    FILE (TO_CMAKE_PATH "${PATH}" PATH)
    STRING (TOLOWER "${PATH}" LC_PATH)

    # now iterate over all the possible names
    FOREACH (NAME ${MODULE_SEARCH_NAMES})
      STRING (TOLOWER "${NAME}" LC_NAME)
      IF ("${LC_PATH}" MATCHES ".*${LC_NAME}.*")
        IF (EXISTS "${PATH}/include")
          MESSAGE (STATUS "${MODULE_NAME} will be searched for in: [PATH environment variable] ${PATH}")
          SET (LIST_CMAKE_PREFIX_PATH ${LIST_CMAKE_PREFIX_PATH} ${PATH})
        ELSEIF (EXISTS "${PATH}/../include")
          MESSAGE (STATUS "${MODULE_NAME} will be searched for in: [PATH environment variable] ${PATH}/..")
          SET (LIST_CMAKE_PREFIX_PATH ${LIST_CMAKE_PREFIX_PATH} ${PATH}/..)
        ENDIF (EXISTS "${PATH}/include")
      ENDIF ("${LC_PATH}" MATCHES ".*${LC_NAME}.*")
    ENDFOREACH (NAME)
  ENDFOREACH (PATH)

  # print some help
  IF (NOT LIST_CMAKE_PREFIX_PATH)
    MESSAGE (STATUS "No candidate ${MODULE_NAME} directory was found in the paths: ${SEARCH_PATHS};%PATH%")
    MESSAGE (STATUS "You might want to check the following:")
    MESSAGE (STATUS "  1. Did you set ZORBA_THIRD_PARTY_REQUIREMENTS properly?")
    MESSAGE (STATUS "  2. Is your ${MODULE_NAME} directory matching one of the search names: ${SEARCH_NAMES} ?")
    MESSAGE (STATUS "  3. Is ${MODULE_NAME} or its \"bin\" directory in the PATH environment variable?")
  ENDIF (NOT LIST_CMAKE_PREFIX_PATH)

  # remove the Windows module path (both from Zorba or the external modules)
  # to avoid an infinite recursion
  FOREACH (PATH ${CMAKE_MODULE_PATH})
    IF ("${PATH}" MATCHES ".*/cmake_modules/Windows")
      LIST (REMOVE_ITEM CMAKE_MODULE_PATH "${PATH}")
    ENDIF ("${PATH}" MATCHES ".*/cmake_modules/Windows")
  ENDFOREACH (PATH)

  # before we start searching, we save the old CMAKE_PREFIX_PATH
  SET (OLD_CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})
  
  # now try to find the module for each path in LIST_CMAKE_PREFIX_PATH
  FOREACH(PATH ${LIST_CMAKE_PREFIX_PATH})
    # set the CMAKE_PREFIX_PATH to the probed path
    SET (CMAKE_PREFIX_PATH ${PATH})

    # call the real Find${MODULE_NAME}.cmake module
    IF(NOT MODULE_COMPONENTS)
      FIND_PACKAGE (${MODULE_NAME})
    ELSE(NOT MODULE_COMPONENTS)
      FIND_PACKAGE (${MODULE_NAME} COMPONENTS ${MODULE_COMPONENTS})
    ENDIF(NOT MODULE_COMPONENTS)
    
    IF (${MODULE_FOUND_VAR})
      SET (FOUND_LOCATION ${CMAKE_PREFIX_PATH})
      BREAK ()
    ENDIF (${MODULE_FOUND_VAR})
  ENDFOREACH(PATH)

  PRINT_FIND_END_TITLE (${MODULE_NAME} FOUND_LOCATION)

  # restore the module path
  SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/Windows ${CMAKE_MODULE_PATH})
  # restore the prefix path
  SET (CMAKE_PREFIX_PATH ${OLD_CMAKE_PREFIX_PATH})

  SET(MODULE_NAME)
  SET(MODULE_FOUND_VAR)
  SET(MODULE_SEARCH_NAMES)
  SET(MODULE_COMPONENT)

ENDMACRO (FIND_PACKAGE_WIN32)


# This macro will just perform a normal library search without trying to guess
# locations. This should be used for searching libraries that can be found on
# Windows using other means like registry entries (ImageMagick) or special
# environment variables (Java or JNI)
MACRO (FIND_PACKAGE_WIN32_NO_PROXY MODULE_NAME FOUND_VAR)

  PRINT_FIND_TITLE (${MODULE_NAME})

  # remove the Windows module path (both from Zorba or the external modules)
  # to avoid an infinite recursion
  FOREACH (PATH ${CMAKE_MODULE_PATH})
    IF ("${PATH}" MATCHES ".*/cmake_modules/Windows")
      LIST (REMOVE_ITEM CMAKE_MODULE_PATH "${PATH}")
    ENDIF ("${PATH}" MATCHES ".*/cmake_modules/Windows")
  ENDFOREACH (PATH)

  FIND_PACKAGE (${MODULE_NAME})

  # restore the module path
  SET (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/Windows ${CMAKE_MODULE_PATH})
  # restore the prefix path
  SET (CMAKE_PREFIX_PATH ${OLD_CMAKE_PREFIX_PATH})

  PRINT_FIND_END_TITLE_SYSTEM (${MODULE_NAME} ${FOUND_VAR})

ENDMACRO (FIND_PACKAGE_WIN32_NO_PROXY)


# This macro will search for a DLL in the given library location using extra
# arguments as alternative names of the DLL. The first DLL found with that name
# is considered. This is useful for some libraries that come with different DLL
# names depending on the library version. For example, cURL library might
# distribute it's main DLL with two different names: "libcurl.dll" or "curllib.dll"
#
# If the DLL is found it's full path will be added to ZORBA_REQUIRED_DLLS and
# it's location to the ZORBA_REQUIRED_DLL_PATHS variable. These will be later
# used when installing zorba.
#
MACRO (FIND_PACKAGE_DLL_WIN32 LIBRARY_LOCATION)

  IF (NOT WIN32)
    MESSAGE (FATAL_ERROR "This macro is intended only for Windows platforms.")
  ENDIF (NOT WIN32)
  
  PARSE_ARGUMENTS(ARG "" "" "SKIP_INSTALL" ${ARGN})
  PARSE_ARGUMENTS(ARG "" "" "OPTIONAL" ${ARGN})
  
  # get the current DLLs and their paths
  SET (dlls "${ZORBA_REQUIRED_DLLS}")
  SET (paths "${ZORBA_REQUIRED_DLL_PATHS}")
  
  FOREACH (NAME ${ARG_DEFAULT_ARGS})
  
    # first delete the cache entry used during FIND_FILE to make sure the correct file is chosen
    UNSET (TMP_DLL_VAR CACHE)

    # find now the DLL
    FIND_FILE (
      TMP_DLL_VAR
      "${NAME}.dll"
      PATHS "${LIBRARY_LOCATION}"
      PATH_SUFFIXES "bin" "bin/Release" "lib" "dlls"
      NO_DEFAULT_PATH
    )

    IF (TMP_DLL_VAR)

      LIST (APPEND dlls "${TMP_DLL_VAR}")
      STRING (REPLACE "/${NAME}.dll" "" PATH "${TMP_DLL_VAR}")
      FILE (TO_NATIVE_PATH ${PATH} NATIVE_PATH)
      LIST (APPEND paths "${NATIVE_PATH}")
      MESSAGE (STATUS "Added dll to ZORBA_REQUIRED_DLLS cache variable: ${TMP_DLL_VAR}")
      
      IF(ARG_SKIP_INSTALL)
        MESSAGE(STATUS "Skip installation of ${NAME}.dll")
      ELSE (ARG_SKIP_INSTALL)
        INSTALL_DLL (${TMP_DLL_VAR})
      ENDIF(ARG_SKIP_INSTALL)
      
      # we break the loop if we found one DLL
      BREAK ()

    ENDIF (TMP_DLL_VAR)

  ENDFOREACH (NAME)

  # we report a warning if the DLL could not be found
  IF (NOT TMP_DLL_VAR)
    IF (NOT ARG_OPTIONAL)
      MESSAGE (WARNING "None of the names provided (${ARG_DEFAULT_ARGS}) points to a DLL in: ${LIBRARY_LOCATION}. Zorba will not run properly unless you have it in the path.")
	ELSE (NOT ARG_OPTIONAL)
	  MESSAGE (STATUS "None of the names provided (${ARG_DEFAULT_ARGS}) points to a DLL in: ${LIBRARY_LOCATION}. Skipping library.")
	ENDIF (NOT ARG_OPTIONAL)
  ENDIF (NOT TMP_DLL_VAR)

  # make sure we don't leave garbage in the cache and don't influence other logic with this
  UNSET (TMP_DLL_VAR CACHE)

  # remove duplicates from the path list
  LIST (LENGTH paths LEN)
  IF (${LEN} GREATER 0)
    LIST (REMOVE_DUPLICATES paths)
  ENDIF (${LEN} GREATER 0)

  # set the current DLLs and their paths in a variable
  SET (ZORBA_REQUIRED_DLLS "${dlls}"
    CACHE STRING "List of DLLs that must be installed" FORCE
  )
  SET (ZORBA_REQUIRED_DLL_PATHS "${paths}"
    CACHE STRING "List of paths executable require in order to find the required DLLs" FORCE
  )

ENDMACRO (FIND_PACKAGE_DLL_WIN32)


MACRO (FIND_PACKAGE_DLLS_WIN32 LIBRARY_LOCATION DLL_NAMES)

  IF (NOT WIN32)
    MESSAGE (FATAL_ERROR "This macro is intended only for Windows platforms.")
  ENDIF (NOT WIN32)

  # get the current DLLs and their paths
  SET (dlls "${ZORBA_REQUIRED_DLLS}")
  SET (paths "${ZORBA_REQUIRED_DLL_PATHS}")

  FOREACH (NAME ${DLL_NAMES})

    # first delete the cache entry used during FIND_FILE to make sure the correct file is chosen
    UNSET (TMP_DLL_VAR CACHE)

    # find now the DLL
    FIND_FILE (
      TMP_DLL_VAR
      "${NAME}"
      PATHS "${LIBRARY_LOCATION}"
      PATH_SUFFIXES "bin" "bin/Release" "lib"
      NO_DEFAULT_PATH
    )

    IF (TMP_DLL_VAR)
      LIST (APPEND dlls "${TMP_DLL_VAR}")
      STRING (REPLACE "/${NAME}" "" PATH "${TMP_DLL_VAR}")
      FILE (TO_NATIVE_PATH ${PATH} NATIVE_PATH)
      LIST (APPEND paths "${NATIVE_PATH}")
      MESSAGE (STATUS "Added dll to ZORBA_REQUIRED_DLLS cache variable: ${TMP_DLL_VAR}")
      INSTALL_DLL (${TMP_DLL_VAR})
    ELSE (TMP_DLL_VAR)
      MESSAGE (WARNING "${NAME} was not found in: ${LIBRARY_LOCATION}. Zorba will not run properly unless you have it in the path.")
    ENDIF (TMP_DLL_VAR)

  ENDFOREACH (NAME)

  # make sure we don't leave garbage in the cache and don't influence other logic with this
  UNSET (TMP_DLL_VAR CACHE)

  # remove duplicates from the path list
  LIST (LENGTH paths LEN)
  IF (${LEN} GREATER 0)
    LIST (REMOVE_DUPLICATES paths)
  ENDIF (${LEN} GREATER 0)

  # set the current DLLs and their paths in a variable
  SET (ZORBA_REQUIRED_DLLS "${dlls}"
    CACHE STRING "List of DLLs that must be installed" FORCE
  )
  SET (ZORBA_REQUIRED_DLL_PATHS "${paths}"
    CACHE STRING "List of paths executable require in order to find the required DLLs" FORCE
  )

ENDMACRO (FIND_PACKAGE_DLLS_WIN32)


MACRO (FIND_DLL_WIN32 DLL_NAME)

  IF (NOT WIN32)
    MESSAGE(FATAL_ERROR "This macro is intended only for Windows platforms.")
  ENDIF (NOT WIN32)

  # get the current DLLs and their paths
  SET (dlls "${ZORBA_REQUIRED_DLLS}")
  SET (paths "${ZORBA_REQUIRED_DLL_PATHS}")

  # first delete the cache entry for DLL to make sure the correct one is chosen
  UNSET (TMP_DLL_VAR CACHE)

  # try to find ${DLL_NAME} somewhere
  # the search order is:
  #   1. all the paths of the DLL's tools Zorba uses (ZORBA_REQUIRED_DLL_PATHS)
  #.  2. all the third paty library directory hints (ZORBA_THIRD_PARTY_REQUIREMENTS)
  #.  3. the paths in the PATH environment variable (ENV{PATH})
  FIND_FILE (
    TMP_DLL_VAR
    ${DLL_NAME}
    PATHS
      ${paths}
      ${ZORBA_THIRD_PARTY_REQUIREMENTS}
      $ENV{PATH}
    NO_DEFAULT_PATH
  )

  IF (TMP_DLL_VAR)
    LIST (APPEND dlls "${TMP_DLL_VAR}")
    STRING (REPLACE "/${DLL_NAME}" "" PATH "${TMP_DLL_VAR}")
    FILE(TO_NATIVE_PATH ${PATH} NATIVE_PATH)
    LIST (APPEND paths "${NATIVE_PATH}")
    MESSAGE (STATUS "Added dll to ZORBA_REQUIRED_DLLS cache variable: ${TMP_DLL_VAR}")
    INSTALL_DLL (${TMP_DLL_VAR})
  ELSE (TMP_DLL_VAR)
    MESSAGE (STATUS "Did not find ${DLL_NAME}")
    MESSAGE (WARNING "You will not be able to run zorba unless you have ${DLL_NAME} in your path.")
  ENDIF (TMP_DLL_VAR)

  # make sure we don't leave garbage in the cache and don't influence other logic with this
  UNSET (TMP_DLL_VAR CACHE)

  # remove duplicates from the path list
  LIST (LENGTH paths LEN)
  IF (${LEN} GREATER 0)
    LIST (REMOVE_DUPLICATES paths)
  ENDIF (${LEN} GREATER 0)

  # set the current DLLs and their paths in a variable
  SET (ZORBA_REQUIRED_DLLS "${dlls}"
    CACHE STRING "List of DLLs that must be installed" FORCE
  )
  SET (ZORBA_REQUIRED_DLL_PATHS "${paths}"
    CACHE STRING "List of paths executable require in order to find the required DLLs" FORCE
  )

ENDMACRO (FIND_DLL_WIN32)


MACRO (ADD_DLL_WIN32 DLL_PATH DLL_NAME)

  IF (NOT WIN32)
    MESSAGE (FATAL_ERROR "This macro is intended only for Windows platforms.")
  ENDIF (NOT WIN32)

  # get the current DLLs and their paths
  SET (dlls "${ZORBA_REQUIRED_DLLS}")
  SET (paths "${ZORBA_REQUIRED_DLL_PATHS}")

  SET (DLL_FULL_PATH ${DLL_PATH}/${DLL_NAME})
  LIST (APPEND dlls "${DLL_FULL_PATH}")
  FILE(TO_NATIVE_PATH ${DLL_PATH} NATIVE_PATH)
  LIST (APPEND paths "${NATIVE_PATH}")
  MESSAGE (STATUS "Added dll to ZORBA_REQUIRED_DLLS cache variable: ${DLL_FULL_PATH}")
  INSTALL_DLL (${DLL_FULL_PATH})

  # set the current DLLs and their paths in a variable
  SET (ZORBA_REQUIRED_DLLS "${dlls}"
    CACHE STRING "List of DLLs that must be installed" FORCE
  )
  SET (ZORBA_REQUIRED_DLL_PATHS "${paths}"
    CACHE STRING "List of paths executable require in order to find the required DLLs" FORCE
  )

ENDMACRO (ADD_DLL_WIN32)
