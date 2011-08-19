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

IF (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)
  MESSAGE (STATUS "SWIG Python: generating Python API")

  SET_SOURCE_FILES_PROPERTIES (zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES (${PYTHON_INCLUDE_PATH})
  SWIG_ADD_MODULE (zorba_api_python python zorba_api.i)
  SWIG_LINK_LIBRARIES (zorba_api_python zorba_simplestore ${PYTHON_LIBRARIES})
  SET_TARGET_PROPERTIES (_zorba_api_python PROPERTIES OUTPUT_NAME "_zorba_api")

  EXECUTE_PROCESS (
    COMMAND ${PYTHON_EXECUTABLE} -c "from distutils import sysconfig;print sysconfig.get_python_lib(0)"
    OUTPUT_VARIABLE PYTHON_INSTALL_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
   
  SET (PYTHON_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/python")
  MESSAGE (STATUS "SWIG Python: Python module install path: " ${PYTHON_INSTALL_PATH})

  IF (NOT WIN32)   
    INSTALL (
      FILES
        ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.py
        ${CMAKE_CURRENT_BINARY_DIR}/_zorba_api.so
      DESTINATION ${PYTHON_INSTALL_PATH}
    )
  ELSE(NOT WIN32)
    INSTALL (
      FILES
        ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.py
        ${CMAKE_CURRENT_BINARY_DIR}/_zorba_api.pyd
      DESTINATION bin/python
      COMPONENT "python_swig"
    )
  ENDIF(NOT WIN32)
  
  ADD_SUBDIRECTORY (tests)
  
ELSE (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)
  MESSAGE (STATUS "SWIG Python: binding not generated because library and include files are not installed.")
ENDIF (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)
