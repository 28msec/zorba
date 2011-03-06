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

PRINT_FIND_TITLE(FindDependencyWalker)

IF(NOT ZORBA_THIRD_PARTY_REQUIREMENTS)
  MESSAGE (STATUS "ZORBA_THIRD_PARTY_REQUIREMENTS variable is not available. I will try to find Depenmdency Walker in: $ENV{ProgramFiles}")
  SET(ZORBA_THIRD_PARTY_REQUIREMENTS $ENV{ProgramFiles})
ENDIF(NOT ZORBA_THIRD_PARTY_REQUIREMENTS)

# search for a folders containing "depend" in the name in the ZORBA_THIRD_PARTY_REQUIREMENTS path
FILE(GLOB MATCHED_DIRS "${ZORBA_THIRD_PARTY_REQUIREMENTS}/*depend*")

IF(NOT MATCHED_DIRS)
  MESSAGE (STATUS "No candidate Dependency Walker directory was found in ZORBA_THIRD_PARTY_REQUIREMENTS (${ZORBA_THIRD_PARTY_REQUIREMENTS})")
ENDIF(NOT MATCHED_DIRS)

FOREACH(DIR ${MATCHED_DIRS})
  MESSAGE (STATUS "DependencyWalker will be searched for in: ${DIR}")
ENDFOREACH(DIR)

FIND_PROGRAM(DEPENDS_EXE depends PATHS ${MATCHED_DIRS})
MESSAGE(STATUS "Found DependencyWalker: ${DEPENDS_EXE}")
MESSAGE(STATUS "Found DependencyWalker executable -- ${DEPENDS_EXE}")
