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

# Add a target to import FOTS
ADD_CUSTOM_TARGET(fots-import
  COMMAND "${CMAKE_COMMAND}" 
  -D "ZORBA=${ZORBA_EXE}"
  -D "BUILDDIR=${PROJECT_BINARY_DIR}"
  -P "${CMAKE_CURRENT_SOURCE_DIR}/ImportFOTS.cmake")

# Create cached version of activate setting
SET (ZORBA_FOTS_ACTIVATE inactive CACHE STRING "Which FOTS tests to activate")
MARK_AS_ADVANCED (ZORBA_FOTS_ACTIVATE)

# Add targets to set activate flag
ADD_CUSTOM_TARGET(fots-activate-sets
  COMMAND "${CMAKE_COMMAND}"
  -D "ZORBA_FOTS_ACTIVATE=sets" "${PROJECT_SOURCE_DIR}"
  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")
ADD_CUSTOM_TARGET(fots-activate-cases
  COMMAND "${CMAKE_COMMAND}"
  -D "ZORBA_FOTS_ACTIVATE=cases" "${PROJECT_SOURCE_DIR}"
  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")
ADD_CUSTOM_TARGET(fots-deactivate
  COMMAND "${CMAKE_COMMAND}"
  -D "ZORBA_FOTS_ACTIVATE=inactive" "${PROJECT_SOURCE_DIR}"
  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")

# Load FOTS test scripts (if they exist) depending on flag
IF ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "sets")
  MESSAGE (STATUS "Adding FOTS test-set tests")
  SET (_fotsscript "${CMAKE_CURRENT_BINARY_DIR}/FOTSSetTests.cmake")
ELSEIF ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "cases")
  MESSAGE (STATUS "Adding FOTS test-case tests (may take a while...)")
  SET (_fotsscript "${CMAKE_CURRENT_BINARY_DIR}/FOTSCaseTests.cmake")
ELSE ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "sets")
  SET (_fotsscript "")
ENDIF ("${ZORBA_FOTS_ACTIVATE}" STREQUAL "sets")
IF (NOT _fotsscript STREQUAL "")
  IF (EXISTS "${_fotsscript}")
    INCLUDE ("${_fotsscript}")
  ELSE (EXISTS "${_fotsscript}")
    MESSAGE (WARNING "...${_fotsscript} does not exist, not adding FOTS tests "
      "after all (did you forget to run the 'fots-import' target?)")
  ENDIF (EXISTS "${_fotsscript}")
ENDIF (NOT _fotsscript STREQUAL "")
