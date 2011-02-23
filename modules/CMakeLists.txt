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

INCLUDE (ZorbaModule)

# all external module libraries are generated in the directory
# of the corresponding .xq file
MESSAGE(STATUS "Add com")
ADD_SUBDIRECTORY(com)
MESSAGE(STATUS "Add org")
ADD_SUBDIRECTORY(org)

# QQQ This install logic should be part of a more fully-feature macro
# that is used for ALL modules (whether or not they have C++ code);
# merge with GENERATE_MODULE_LIBRARY()
IF (CMAKE_MINOR_VERSION STREQUAL "4")
  INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          DESTINATION include/zorba
          PATTERN "*.svn" EXCLUDE
          PATTERN "*.xq.src" EXCLUDE
          PATTERN "*.xsd"
          PATTERN "*.xq")
ELSE (CMAKE_MINOR_VERSION STREQUAL "4")
  INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          DESTINATION include/zorba
          FILES_MATCHING
          PATTERN "*.svn" EXCLUDE
          PATTERN "*.xq.src" EXCLUDE
          PATTERN "*.xsd"
          PATTERN "*.xq")
ENDIF (CMAKE_MINOR_VERSION STREQUAL "4")

MESSAGE(STATUS "End modules")
