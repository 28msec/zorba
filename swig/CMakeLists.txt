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

IF (SWIG_FOUND)
  IF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-strict-aliasing")
    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
  ENDIF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)

  INCLUDE (${SWIG_USE_FILE})

  # Adding all *.i files of the current directory to swig dependencies
  # Important: This can done here for all modules because all modules have the same name (zorba_api or libzorba_api)
  FILE (GLOB SWIG_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.i")
  SET (SWIG_MODULE_zorba_api_EXTRA_DEPS ${SWIG_FILES})
  SET (SWIG_MODULE_libzorba_api_EXTRA_DEPS ${SWIG_FILES})

  # on apple and cmake 2.8, the generated swig libraries are prefixed with "lib"
  SET (ZORBA_SWIG_LIB_PREFIX)
  IF (APPLE AND CMAKE_MINOR_VERSION GREATER 6)
    SET (ZORBA_SWIG_LIB_PREFIX "lib")
  ENDIF (APPLE AND CMAKE_MINOR_VERSION GREATER 6)

  ADD_SUBDIRECTORY (python)
  ADD_SUBDIRECTORY (php)
  ADD_SUBDIRECTORY (java)

  IF (APPLE AND UNIVERSAL)
    MESSAGE (STATUS "Ruby module can't be built Universal")
  ELSE(APPLE AND UNIVERSAL)
    MESSAGE (STATUS "Ruby module being built non-Universal")
    ADD_SUBDIRECTORY (ruby)
  ENDIF (APPLE AND UNIVERSAL)

ENDIF (SWIG_FOUND)
