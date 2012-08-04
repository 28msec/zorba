# Copyright 2006-2010 The FLWOR Foundation.
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

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT (zorba_oauth_module)
ENABLE_TESTING ()
INCLUDE (CTest)

LIST (APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules")

FIND_PACKAGE (Zorba REQUIRED HINTS "${ZORBA_BUILD_DIR}")
INCLUDE ("${Zorba_USE_FILE}")

# The _SUPPRESS variables are a work-around for the Ubuntu packaging process.
IF (NOT SUPPRESS_HTML_MODULE_FIND_PACKAGE)
  FIND_PACKAGE(zorba_html_module
    HINTS ${HTML_BUILD_DIR})
ELSE (NOT SUPPRESS_HTML_MODULE_FIND_PACKAGE)
  SET (zorba_html_module_FOUND 1)
ENDIF (NOT SUPPRESS_HTML_MODULE_FIND_PACKAGE)

IF (NOT SUPPRESS_SECURITY_MODULE_FIND_PACKAGE)
  FIND_PACKAGE(zorba_security_module
    HINTS ${SECURITY_BUILD_DIR})
ELSE (NOT SUPPRESS_SECURITY_MODULE_FIND_PACKAGE)
  SET (zorba_security_module_FOUND 1)
ENDIF (NOT SUPPRESS_SECURITY_MODULE_FIND_PACKAGE)

IF (zorba_html_module_FOUND AND zorba_security_module_FOUND)
  ADD_TEST_DIRECTORY("${PROJECT_SOURCE_DIR}/test")
  ADD_SUBDIRECTORY("src")
ELSE ( zorba_html_module_FOUND AND zorba_security_module_FOUND)
  MESSAGE (STATUS "Didn't find Zorba's HTML and Security modules - skipping OAuth module")
ENDIF ( zorba_html_module_FOUND AND zorba_security_module_FOUND)

DONE_DECLARING_ZORBA_URIS()
