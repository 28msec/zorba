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

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
STRING(COMPARE EQUAL ${PYTHON_LIBRARIES} "PYTHON_LIBRARY-NOTFOUND" PYTHON_LIBS_NOT_FOUND)
STRING(COMPARE EQUAL ${PYTHON_INCLUDE_PATH} "PYTHON_INCLUDE_PATH-NOTFOUND" PYTHON_INCL_NOT_FOUND) 

IF(${PYTHON_LIBS_NOT_FOUND} OR ${PYTHON_INCL_NOT_FOUND})
ELSE(${PYTHON_LIBS_NOT_FOUND} OR ${PYTHON_INCL_NOT_FOUND})
  STRING(COMPARE EQUAL ${PYTHONINTERP_FOUND} "ON" PYTHON_FOUND)
  IF(${PYTHON_FOUND})
    SET(pythonPath ${CMAKE_BINARY_DIR}/swig/python)
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/python_test.py.in ${CMAKE_CURRENT_BINARY_DIR}/python_test.py)
    ADD_TEST("python" ${PYTHON_EXECUTABLE} python_test.py)
  ELSE(${PYTHON_FOUND})
    MESSAGE(STATUS "Python test not added because Python Interpreter not found.")
  ENDIF(${PYTHON_FOUND})
ENDIF(${PYTHON_LIBS_NOT_FOUND} OR ${PYTHON_INCL_NOT_FOUND})
