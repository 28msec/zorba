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

# - Find the International Components for Unicode (ICU) Library on Windows
#
# This is a proxy module that calls the FindICU.cmake module. Before
# doing that, we try to guess where ICU might be on the user's machine.
# The user should provide ZORBA_THIRD_PARTY_REQUIREMENTS which is a path where
# a the ICU directory can be found. The ICU directory must have "icu"
# (case insensitive) in its name.
#
# This module helps the Windows user to avoid providing the following two
# variables when building Zorba:
# -D ICU_LIBRARY="path_to_3rd_party_dir\*icu*\lib\icuuc.lib"
# -D ICU_DATA_LIBRARY="path_to_3rd_party_dir\*icu*\lib\icudt.lib"
# -D ICU_I18N_LIBRARY="path_to_3rd_party_dir\*icu*\lib\icuin.lib"
# -D ICU_INCLUDE="path_to_3rd_party_dir\*icu*\include"
#
# See the FindICU.cmake module shipped with Zorba for more information.

FIND_PACKAGE_WIN32 (NAME ICU FOUND_VAR ICU_FOUND SEARCH_NAMES icu)

IF (ICU_FOUND)

  # first delete the cache entry for DLL to make sure the correct one is chosen
  UNSET (ICU_INFO_EXE CACHE)

  # find ICU version
  FIND_PATH (
    ICU_INFO_EXE_PATH
    icuinfo.exe
    PATHS "${FOUND_LOCATION}"
    # add more suffixes if necessary
    PATH_SUFFIXES "bin" "bin/Release"
    NO_DEFAULT_PATH
  )

  IF (NOT ICU_INFO_EXE_PATH)

    MESSAGE (WARNING "icuinfo.exe was not found in: ${FOUND_LOCATION}. This is needed in order to retrieve the ICU version and to find the ICU DLLs. Zorba will not run unless you have the ICU DLLs in the path.")

  ELSE (NOT ICU_INFO_EXE_PATH)

    EXECUTE_PROCESS (COMMAND "${ICU_INFO_EXE_PATH}/icuinfo.exe" OUTPUT_VARIABLE INFO)
    STRING (REGEX REPLACE "\n" ";" LINES ${INFO})
    FOREACH (LINE ${LINES})
      IF (LINE MATCHES "Runtime-Version: ")
        STRING (REPLACE "Runtime-Version: " "" VERSION ${LINE})		
      ENDIF (LINE MATCHES "Runtime-Version: ")	  
    ENDFOREACH (LINE)
	
	FOREACH (LINE ${LINES})
      IF (LINE MATCHES "<param name=\"version\">[\\.0-9]*</param>")
        STRING (REGEX REPLACE " *<param name=\"version\">([\\.0-9]*)</param> *" "\\1" VERSION ${LINE})
	  ENDIF (LINE MATCHES "<param name=\"version\">[\\.0-9]*</param>")	  
    ENDFOREACH (LINE)
	
	IF (NOT VERSION)
	  MESSAGE(FATAL_ERROR "Cannot parse output of icuinfo.exe") 
	ENDIF (NOT VERSION)
  
    STRING (REPLACE "." ";" PARTS ${VERSION})
  
    LIST (GET PARTS 0 MAJOR_VERSION)
    #LIST (GET PARTS 1 MINOR_VERSION)
    #SET (DLL_VERSION "${MAJOR_VERSION}${MINOR_VERSION}")
	SET (DLL_VERSION "${MAJOR_VERSION}")
  
    SET (DLL_NAMES
      "icudt${DLL_VERSION}.dll"
      "icuin${DLL_VERSION}.dll"
      "icuuc${DLL_VERSION}.dll"
    )
  
    # find the needed DLL's
    FIND_PACKAGE_DLLS_WIN32 (${ICU_INFO_EXE_PATH} "${DLL_NAMES}")

  ENDIF (NOT ICU_INFO_EXE_PATH)

ENDIF (ICU_FOUND)
