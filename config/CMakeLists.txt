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


# Calculate ZORBA_ROOT, which is the base dir of the Zorba installation.
# Zorba_DIR will be set to the directory containing ZorbaConfig.cmake,
# which is in a different place on Windows than Unix, so work from there.
IF (WIN32)
  # ZORBA_ROOT/cmake/ZorbaConfig.cmake
  SET (ZORBA_ROOT "\${Zorba_DIR}/..")
ELSE (WIN32)
  # ZORBA_ROOT/share/zorba-VERSION/cmake/ZorbaConfig.cmake
  SET (ZORBA_ROOT "\${Zorba_DIR}/../../..")
ENDIF (WIN32)

# Create ZorbaConfig.cmake file for projects that wish to build
# against the installed Zorba project.
SET(Zorba_INCLUDE_DIRS "${ZORBA_ROOT}/include")
SET(Zorba_LIBRARY_DIRS "${ZORBA_ROOT}/lib")
SET(Zorba_USE_FILE "${ZORBA_ROOT}/${ZORBA_CMAKE_DIR}/ZorbaUse.cmake")
SET(Zorba_CMAKE_MODULES_DIR "${ZORBA_ROOT}/${ZORBA_CMAKE_DIR}")
SET(Zorba_TESTDRIVER "${ZORBA_ROOT}/bin/testdriver")
SET(Zorba_EXE_PATH "${ZORBA_ROOT}/bin/zorba")
SET(Zorba_EXTERNALMODULECONFIG_FILE
  "${ZORBA_ROOT}/${ZORBA_CMAKE_DIR}/ExternalModuleConfig.cmake.in")
SET(Zorba_MODULES_INSTALL_DIR "${ZORBA_ROOT}/${ZORBA_MODULES_INSTALL_DIR}")

CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/ZorbaConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/ZorbaConfig.cmake" @ONLY)
INSTALL(FILES "${CMAKE_CURRENT_BINARY_DIR}/ZorbaConfig.cmake"
 DESTINATION ${ZORBA_CMAKE_DIR})

# Create ZorbaConfig.cmake file for projects that wish to build
# against this Zorba source installation.
SET(Zorba_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include"
                       "${CMAKE_BINARY_DIR}/include"
)
SET(Zorba_LIBRARY_DIRS "${CMAKE_BINARY_DIR}/src")
SET(Zorba_CMAKE_MODULES_DIR "${CMAKE_SOURCE_DIR}/cmake_modules")
SET(Zorba_USE_FILE     "${CMAKE_CURRENT_SOURCE_DIR}/ZorbaUse.cmake")
GET_TARGET_PROPERTY(Zorba_TESTDRIVER testdriver LOCATION)

SET(Zorba_EXE_PATH     "${ZORBA_EXE}")
SET(Zorba_EXTERNALMODULECONFIG_FILE
  "${CMAKE_CURRENT_SOURCE_DIR}/ExternalModuleConfig.cmake.in")
# Note: We also set these two into the parent's scope, so that it is
# available for the rest of the build.
SET(Zorba_EXTERNALMODULECONFIG_FILE
  "${CMAKE_CURRENT_SOURCE_DIR}/ExternalModuleConfig.cmake.in"
  PARENT_SCOPE)
SET(Zorba_EXE "${ZORBA_EXE}" PARENT_SCOPE)

# Note: This value doesn't really make much sense, but neither does any
# other value
SET(Zorba_MODULES_INSTALL_DIR "${CMAKE_BINARY_DIR}/URI_PATH")
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/ZorbaConfig.cmake.in"
  "${CMAKE_BINARY_DIR}/ZorbaConfig.cmake" @ONLY)


# Create ZorbaConfigVersion.cmake file for automatic version checking.
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/ZorbaConfigVersion.cmake.in"
  "${CMAKE_BINARY_DIR}/ZorbaConfigVersion.cmake" @ONLY)
INSTALL(FILES
  "${CMAKE_BINARY_DIR}/ZorbaConfigVersion.cmake"
  DESTINATION ${ZORBA_CMAKE_DIR})


# Install ZorbaUse.cmake file for sharing build settings and macros
# with dependent projects.
INSTALL(FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/ZorbaUse.cmake"
  DESTINATION ${ZORBA_CMAKE_DIR})


# Install ExternalModuleConfig.cmake.in as-is (will be configured by
# the modules themselves)
INSTALL(FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/ExternalModuleConfig.cmake.in"
  DESTINATION ${ZORBA_CMAKE_DIR})


ADD_SUBDIRECTORY(fedora)
ADD_SUBDIRECTORY(debian)
