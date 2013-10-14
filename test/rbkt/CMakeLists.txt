# Copyright 2006-2013 The FLWOR Foundation.
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

# The NO_CTEST variable can be set to 1 so that CMake does not search
# for and add most of the Zorba tests, to speed up building and
# compiling the project.
IF (NOT NO_CTEST)
  ADD_SUBDIRECTORY(Queries)
  ADD_SUBDIRECTORY(modules)
  ADD_SUBDIRECTORY(jsound)
ENDIF (NOT NO_CTEST)
