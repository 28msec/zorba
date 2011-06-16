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
# to CMAKE_INSTALL_PREFIX. QQQ probably should be set in top-level
# CMakeLists.
SET(CURRENCY_SYMBOL "$")

SET(ZORBA_SHARE_DIR "share/zorba-${ZORBA_VERSION}/cmake")


# Create ZorbaConfig.cmake file for projects that wish to build
# against the installed Zorba project

 
SET(Zorba_INCLUDE_DIRS "${CURRENCY_SYMBOL}{Zorba_DIR}/include")
SET(Zorba_LIBRARY_DIRS "${CURRENCY_SYMBOL}{Zorba_DIR}/lib")
SET(Zorba_USE_FILE "${CURRENCY_SYMBOL}{Zorba_DIR}/${ZORBA_SHARE_DIR}/ZorbaUse.cmake")
SET(Zorba_CMAKE_MODULES_DIR "${CURRENCY_SYMBOL}{Zorba_DIR}/${ZORBA_SHARE_DIR}")
SET(Zorba_TESTDRIVER "${CURRENCY_SYMBOL}{Zorba_DIR}/bin/testdriver")
SET(Zorba_EXTERNALMODULECONFIG_FILE
  "${CURRENCY_SYMBOL}{Zorba_DIR}/${ZORBA_SHARE_DIR}/ExternalModuleConfig.cmake.in")
  
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/ZorbaConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/ZorbaConfig.cmake" @ONLY)
INSTALL(FILES "${CMAKE_CURRENT_BINARY_DIR}/ZorbaConfig.cmake" DESTINATION .)

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
  DESTINATION ${ZORBA_SHARE_DIR})


# Install ZorbaUse.cmake file for sharing build settings and macros
# with dependent projects.
INSTALL(FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/ZorbaUse.cmake"
  DESTINATION ${ZORBA_SHARE_DIR})


# Install ExternalModuleConfig.cmake.in as-is (will be configured by
# the modules themselves)
INSTALL(FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/ExternalModuleConfig.cmake.in"
  DESTINATION ${ZORBA_SHARE_DIR})


ADD_SUBDIRECTORY(fedora)
ADD_SUBDIRECTORY(debian)
