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

# - Try to find Xerces-C on Windows
#
# This is a proxy module that calls the FindXercesC.cmake module. Before
# doing that, we try to guess where XercesC might be on the user's machine.
# The user should provide ZORBA_THIRD_PARTY_REQUIREMENTS which is a path where
# the XercesC directory can be found. The XercesC directory must have "xerces"
# (case insensitive) in its name.
#
# This module helps the Windows user to avoid providing the following two
# variables when building Zorba:
# -D XERCESC_INCLUDE="path_to_3rd_party_dir\*xerces*\include"
# -D XERCESC_LIBRARY="path_to_3rd_party_dir\*xerces*\lib\xerces-c_3.lib"
#
# See the FindXercesC.cmake module shipped with Zorba for more information.

FIND_PACKAGE_WIN32(XercesC XERCESC_FOUND xerces)

IF (XERCESC_FOUND)

  # find the needed DLL's
  FIND_PACKAGE_DLLS_WIN32 (${FOUND_LOCATION} xerces-c_3_1.dll)

  # Try to find zlib1.dll somewhere
  IF (ZLIB1_DLL AND NOT EXISTS ${ZLIB1_DLL})
    SET (ZLIB1_DLL ZLIB1_DLL-NOTFOUND CACHE FILEPATH "Path to a file." FORCE)
  ENDIF (ZLIB1_DLL AND NOT EXISTS ${ZLIB1_DLL})

  FIND_FILE (
    ZLIB1_DLL
    zlib1.dll
    PATHS
      ${ZORBA_THIRD_PARTY_REQUIREMENTS}
  )

  # TODO: add more logic where to find such
  # external DLL's that libraries don't ship

  IF (ZLIB1_DLL)
    MESSAGE (STATUS "Found zlib1.dll")
    LIST (APPEND ZORBA_REQUIRED_DLLS "${ZLIB1_DLL}")
    STRING (REPLACE "/zlib1.dll" "" PATH "${ZLIB1_DLL}")
    FILE(TO_NATIVE_PATH ${PATH} NATIVE_PATH)
    LIST (APPEND ZORBA_REQUIRED_DLL_PATHS "${NATIVE_PATH}")
    MESSAGE (STATUS "Added dll to ZORBA_REQUIRED_DLLS: ${ZLIB1_DLL}")
  ELSE (ZLIB1_DLL)
    MESSAGE (STATUS "Did not find zlib1.dll")
    MESSAGE (WARNING "You will not be able to run zorba unless you have zlib1.dll in your path.")
  ENDIF (ZLIB1_DLL)

ENDIF (XERCESC_FOUND)
