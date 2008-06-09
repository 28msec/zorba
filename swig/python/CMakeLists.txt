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

FIND_PACKAGE(PythonLibs)
STRING(COMPARE EQUAL ${PYTHON_LIBRARIES} "PYTHON_LIBRARY-NOTFOUND" PYTHON_LIBS_NOT_FOUND)
STRING(COMPARE EQUAL ${PYTHON_INCLUDE_PATH} "PYTHON_INCLUDE_PATH-NOTFOUND" PYTHON_INCL_NOT_FOUND) 

IF(${PYTHON_LIBS_NOT_FOUND} OR ${PYTHON_INCL_NOT_FOUND})
  MESSAGE(STATUS "Python binding not generated because library and include file not installed.")
ELSE(${PYTHON_LIBS_NOT_FOUND} OR ${PYTHON_INCL_NOT_FOUND})
  MESSAGE(STATUS "Generating Python API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})
  SWIG_ADD_MODULE(zorba_api python zorba_api.i)
  SWIG_LINK_LIBRARIES(zorba_api zorba simplestore ${PYTHON_LIBRARIES})
ENDIF(${PYTHON_LIBS_NOT_FOUND} OR ${PYTHON_INCL_NOT_FOUND})
