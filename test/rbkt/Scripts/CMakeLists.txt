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
SET(zorbaRepos ${CMAKE_SOURCE_DIR})
SET(zorbaExecDir ${CMAKE_BINARY_DIR}/test)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/rbkt.sh.in ${CMAKE_CURRENT_BINARY_DIR}/rbkt.sh @ONLY)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/lbkt.sh.in ${CMAKE_CURRENT_BINARY_DIR}/lbkt.sh @ONLY)
