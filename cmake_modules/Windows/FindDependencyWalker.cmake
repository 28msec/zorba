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

# - Try to find Dependency Walker on Windows
#
# This searches for a directory containing "depend" (case insensitive) in its
# name. The search is performed in ZORBA_THIRD_PARTY_REQUIREMENTS. If this is
# not provided, the program files directory on this system will be searched.
#
# This module helps the Windows user to avoid providing the following variable
# when building Zorba:
# -D DEPENDS_EXE="path_to_3rd_party_dir\*depend*\depends.exe"
#
# Once done this will define
#
#  DEPENDS_EXE - The path to depends.exe
#

IF(NOT WIN32)
  MESSAGE(FATAL_ERROR "This module is intended only for Windows platforms.")
ENDIF(NOT WIN32)

PRINT_FIND_TITLE(DependencyWalker)

SET(SEARCH_PATHS ${ZORBA_THIRD_PARTY_REQUIREMENTS})
LIST(FIND SEARCH_PATHS "$ENV{ProgramFiles}" PRORAM_FILES_FOUND)
IF(PRORAM_FILES_FOUND EQUAL -1)
  SET(SEARCH_PATHS ${SEARCH_PATHS} $ENV{ProgramFiles})
ENDIF(PRORAM_FILES_FOUND EQUAL -1)

SET(PATH_REGEX)
FOREACH(PATH ${SEARCH_PATHS})
  FILE(TO_CMAKE_PATH ${PATH} CMPATH)
  SET(PATH_REGEX ${PATH_REGEX} "${CMPATH}/*depend*")
ENDFOREACH(PATH)

# search for folders containing "depend" in the name in the SEARCH_PATHS paths
FILE(GLOB MATCHED_DIRS ${PATH_REGEX})

FOREACH(DIR ${MATCHED_DIRS})
  MESSAGE (STATUS "Dependency Walker will be searched for in: [ZORBA_THIRD_PARTY_REQUIREMENTS] ${DIR}")
ENDFOREACH(DIR)

# try to find depends.exe; this will also search in the PATH environment variable
FIND_PROGRAM(DEPENDS_EXE depends PATHS ${MATCHED_DIRS})
MESSAGE(STATUS "Found DependencyWalker: ${DEPENDS_EXE}")
MESSAGE(STATUS "Found DependencyWalker executable -- ${DEPENDS_EXE}")

# print some help
IF(NOT DEPENDS_EXE)
  MESSAGE (STATUS "Dependency Walker directory was not found in the paths: ${SEARCH_PATHS};%PATH%")
  MESSAGE (STATUS "You might wanna check:")
  MESSAGE (STATUS "  1. Did you set ZORBA_THIRD_PARTY_REQUIREMENTS properly?")
  MESSAGE (STATUS "  2. Is the Dependency Walker directory in the PATH environment variable?")
ENDIF(NOT DEPENDS_EXE)
