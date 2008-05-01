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
ADD_SUBDIRECTORY(examples)

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/CMakeUseDoxygen.cmake)
IF (DOXYGEN_FOUND)

CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/style/rtab_b.gif
${CMAKE_CURRENT_BINARY_DIR}/html/rtab_b.gif COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/style/rtab_r.gif
${CMAKE_CURRENT_BINARY_DIR}/html/rtab_r.gif COPYONLY)
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/style/rtab_l.gif
${CMAKE_CURRENT_BINARY_DIR}/html/rtab_l.gif COPYONLY)

ENDIF (DOXYGEN_FOUND)
