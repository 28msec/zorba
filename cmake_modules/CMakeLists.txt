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

INSTALL(FILES ZorbaModule.cmake DESTINATION "${ZORBA_CMAKE_DIR}")

# Install Windows/ProxyFindModule.cmake for use of Module
IF(WIN32)
  INSTALL(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/Windows/ProxyFindModule.cmake" 
    DESTINATION "${ZORBA_CMAKE_DIR}/Windows")
ENDIF(WIN32)

#creates file used for configuration of CPACK for external modules.
FILE(WRITE ${CMAKE_BINARY_DIR}/CMakeCPackModules.cmake)