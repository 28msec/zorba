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
  MESSAGE (STATUS "SWIG: Generating Python API")

  SET_SOURCE_FILES_PROPERTIES (zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES (${PYTHON_INCLUDE_PATH})
  SWIG_ADD_MODULE (zorba_api_python python zorba_api.i)
  SWIG_LINK_LIBRARIES (zorba_api_python zorba_simplestore ${PYTHON_LIBRARIES})
  SET_TARGET_PROPERTIES (_zorba_api_python PROPERTIES OUTPUT_NAME "_zorba_api")
  
  IF (MSVC_IDE)
    SET_PROPERTY( TARGET _zorba_api_python PROPERTY PROJECT_LABEL "Python")
    SET_PROPERTY( TARGET _zorba_api_python PROPERTY FOLDER "APIs")
    SET_PROPERTY( TARGET _zorba_api_python PROPERTY LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/swig/python )
    SET_PROPERTY( TARGET _zorba_api_python PROPERTY LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/swig/python )
  ENDIF (MSVC_IDE)

  # FIX FOR PYTHON_D.LIB ERROR ON WINDOWS
  IF (WIN32)
    CONFIGURE_FILE(${PYTHON_DEBUG_LIBRARIES}  ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
  ENDIF (WIN32)
  
  EXECUTE_PROCESS (
    COMMAND ${PYTHON_EXECUTABLE} -c "from distutils import sysconfig;print sysconfig.get_python_lib(0)"
    OUTPUT_VARIABLE PYTHON_INSTALL_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
   
  FILE(GLOB ZORBA_API_HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/../" "${CMAKE_CURRENT_SOURCE_DIR}/../*.h")
  FOREACH(ZORBA_API_HEADER ${ZORBA_API_HEADERS})
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../${ZORBA_API_HEADER}"  "${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_API_HEADER}")
  ENDFOREACH(ZORBA_API_HEADER ${ZORBA_API_HEADERS})

  SET (PYTHON_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/python")

  IF (NOT WIN32)   
    INSTALL (
      FILES
        ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.py
        ${CMAKE_CURRENT_BINARY_DIR}/_zorba_api.so
      DESTINATION ${PYTHON_INSTALL_PATH}
    )
  ELSE(NOT WIN32)
      INSTALL ( FILES 
      ${CMAKE_CURRENT_BINARY_DIR}/_zorba_api.pyd
      DESTINATION share/python
      COMPONENT "python_swig" )
  ENDIF(NOT WIN32)
  
  ADD_SUBDIRECTORY (tests)
  
ELSE (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)
  MESSAGE (STATUS "SWIG: Python binding not generated because library and include files are not installed.")
ENDIF (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)
