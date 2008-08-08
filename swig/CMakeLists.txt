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

FIND_PACKAGE(SWIG)
IF (SWIG_FOUND)
  INCLUDE(${SWIG_USE_FILE})
  ADD_SUBDIRECTORY(python)
  ADD_SUBDIRECTORY(php)

ADD_SUBDIRECTORY(php)
# ruby module on Mac OS doesn't link because cmake is generating
# -framework ruby instead of -framework Ruby
#IF ( NOT APPLE )
  ADD_SUBDIRECTORY(ruby)
#ENDIF ( NOT APPLE )
ELSE(SWIG_FOUND)
  MESSAGE(STATUS "SWIG not installed => no language bindings are generated.")
ENDIF(SWIG_FOUND)
