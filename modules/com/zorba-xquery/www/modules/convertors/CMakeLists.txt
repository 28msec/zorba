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

# libTidy is required
IF(ZORBA_SUPPRESS_LIBTIDY)
  MESSAGE(STATUS "ZORBA_SUPPRESS_LIBTIDY is true - not searching for libTidy.")
ELSE(ZORBA_SUPPRESS_LIBTIDY)
  INCLUDE (${CMAKE_SOURCE_DIR}/cmake_modules/FindLibTidy.cmake)

  IF(LIBTIDY_FOUND)
    SET(HTML_LINK_LIBRARIES ${LIBTIDY_LIBRARIES})

    SET(BUILD_MODULE 1)

    INCLUDE_DIRECTORIES(${LIBTIDY_INCLUDE_DIR})

    INCLUDE_DIRECTORIES("html.xq.src")

    IF (BUILD_MODULE)
      GENERATE_MODULE_LIBRARY(html "${LIBTIDY_LIBRARIES}")
    ENDIF (BUILD_MODULE)

  ELSE(LIBTIDY_FOUND)
    MESSAGE(STATUS "LibTidy library not found -- if you want to use HTML Tidy functionality please set LIBTIDY_INCLUDE_DIR and LIBTIDY_LIBRARIES cmake parameters.")
  ENDIF(LIBTIDY_FOUND)
ENDIF(ZORBA_SUPPRESS_LIBTIDY)

# Jansson is required
IF(ZORBA_SUPPRESS_JANSSON)
  MESSAGE(STATUS "ZORBA_SUPPRESS_JANSSON is true - not searching for Jansson.")
ELSE(ZORBA_SUPPRESS_JANSSON)
  INCLUDE (${CMAKE_SOURCE_DIR}/cmake_modules/FindJansson.cmake)

  IF(Jansson_FOUND)
    SET(JSON_LINK_LIBRARIES ${Jansson_LIBRARIES})

    SET(BUILD_MODULE 1)

    INCLUDE_DIRECTORIES(${Jansson_INCLUDE_DIRS})

    INCLUDE_DIRECTORIES("json.xq.src")

    IF (BUILD_MODULE)
      GENERATE_MODULE_LIBRARY(json "${Jansson_LIBRARIES}")
    ENDIF (BUILD_MODULE)

  ELSE(Jansson_FOUND)
    MESSAGE(STATUS "Jansson library not found -- if you want to use Json functionality please set Jansson_INCLUDE_DIRS and Jansson_LIBRARIES cmake parameters.")
  ENDIF(Jansson_FOUND)
ENDIF(ZORBA_SUPPRESS_JANSSON)