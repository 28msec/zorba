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


# Subdir of the installed "share" directory for CMake files, relative
# to CMAKE_INSTALL_PREFIX.
IF (WIN32)
  SET(ZORBA_CMAKE_DIR "cmake")
ELSE (WIN32)
  SET(ZORBA_CMAKE_DIR "share/zorba-${ZORBA_VERSION}/cmake")
ENDIF (WIN32)

# Create ZorbaConfig.cmake file for projects that wish to build
# against the installed Zorba project
SET(Zorba_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include")
SET(Zorba_LIBRARY_DIRS "${CMAKE_INSTALL_PREFIX}/lib")
SET(Zorba_USE_FILE "${CMAKE_INSTALL_PREFIX}/${ZORBA_CMAKE_DIR}/ZorbaUse.cmake")
SET(Zorba_CMAKE_MODULES_DIR "${CMAKE_INSTALL_PREFIX}/${ZORBA_CMAKE_DIR}")
SET(Zorba_TESTDRIVER "${CMAKE_INSTALL_PREFIX}/bin/testdriver")
SET(Zorba_EXTERNALMODULECONFIG_FILE
  "${CMAKE_INSTALL_PREFIX}/${ZORBA_CMAKE_DIR}/ExternalModuleConfig.cmake.in")
  
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
# Note: We also set this one into the parent's scope, so that it is
# available for modules/CMakeLists.txt.
SET(Zorba_EXTERNALMODULECONFIG_FILE
  "${CMAKE_CURRENT_SOURCE_DIR}/ExternalModuleConfig.cmake.in"
  PARENT_SCOPE)
SET(Zorba_EXTERNALMODULECONFIG_FILE
  "${CMAKE_CURRENT_SOURCE_DIR}/ExternalModuleConfig.cmake.in")
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
