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

# Imports Zorba's build settings
INCLUDE(CMakeImportBuildSettings)
CMAKE_IMPORT_BUILD_SETTINGS(${Zorba_BUILD_SETTINGS_FILE})

# Tell the compiler where to find Zorba's header files.
INCLUDE_DIRECTORIES(${Zorba_INCLUDE_DIRS})

# Tell the linker where to find Zorba's libraries
LINK_DIRECTORIES(${Zorba_LIBRARY_DIRS})
