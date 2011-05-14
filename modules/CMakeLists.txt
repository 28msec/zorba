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

MESSAGE(STATUS "Add com")
ADD_SUBDIRECTORY(com)
MESSAGE(STATUS "Add org")
ADD_SUBDIRECTORY(org)

# Add external module projects - any subdirectories of a directory
# named "zorba_modules" as a sibling to the main Zorba source
# directory.

# First, configure the moduleConfig.cmake file for each module
# project. We must do this "manually" before doing any
# ADD_SUBDIRECTORY()s, so that all the config files are built and
# ready for other modules' FIND_PACKAGE() calls. We also add all
# module build dirs to CMAKE_PREFIX_PATH for the same reason.
SET (modules_dir "${CMAKE_SOURCE_DIR}/../zorba_modules")
FILE (GLOB modules RELATIVE "${modules_dir}" "${modules_dir}/*")
LIST (REVERSE modules)
FOREACH (module ${modules})
  SET (module_builddir "${modules_dir}/${module}/build")
  FILE (MAKE_DIRECTORY "${module_builddir}")
  # This is duplicating the code in ZorbaModule's
  # SET_EXTERNAL_MODULE_CONFIG macro
  CONFIGURE_FILE("${CMAKE_SOURCE_DIR}/config/ExternalModuleConfig.cmake.in"
    "${module_builddir}/${module}Config.cmake")
  LIST(APPEND CMAKE_PREFIX_PATH "${module_builddir}")
ENDFOREACH (module)

# Each of these projects will also want to be able to
# FIND_PACKAGE(Zorba), so add our own build dir to the CMake module
# path
LIST(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")

# Now, iterate through all the module projects again and actually add
# them to this Zorba project. Create a binary directory for them
# inside our own.
FOREACH (module ${modules})
  ADD_SUBDIRECTORY("${modules_dir}/${module}"
    "${CMAKE_BINARY_DIR}/zorba_modules/${module}")
ENDFOREACH (module)

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
