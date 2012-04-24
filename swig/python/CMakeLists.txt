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
  
  IF (MSVC_IDE)
    SET_PROPERTY( TARGET _zorba_api_python PROPERTY PROJECT_LABEL "Api_Python" )
    SET_PROPERTY( TARGET _zorba_api_python PROPERTY LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/swig/python )
    SET_PROPERTY( TARGET _zorba_api_python PROPERTY LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/swig/python )
  ENDIF (MSVC_IDE)
  
  EXECUTE_PROCESS (
    COMMAND ${PYTHON_EXECUTABLE} -c "from distutils import sysconfig;print sysconfig.get_python_lib(0)"
    OUTPUT_VARIABLE PYTHON_INSTALL_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
   
  SET (PYTHON_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/python")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../StaticContext.h" "${CMAKE_CURRENT_BINARY_DIR}/StaticContext.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../ItemFactory.h" "${CMAKE_CURRENT_BINARY_DIR}/ItemFactory.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Item.h" "${CMAKE_CURRENT_BINARY_DIR}/Item.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Iterator.h" "${CMAKE_CURRENT_BINARY_DIR}/Iterator.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../XQuery.h" "${CMAKE_CURRENT_BINARY_DIR}/XQuery.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../DynamicContext.h" "${CMAKE_CURRENT_BINARY_DIR}/DynamicContext.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../XmlDataManager.h" "${CMAKE_CURRENT_BINARY_DIR}/XmlDataManager.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../TypeIdentifier.h" "${CMAKE_CURRENT_BINARY_DIR}/TypeIdentifier.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../SerializationOptions.h" "${CMAKE_CURRENT_BINARY_DIR}/SerializationOptions.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Collection.h" "${CMAKE_CURRENT_BINARY_DIR}/Collection.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../CollectionManager.h" "${CMAKE_CURRENT_BINARY_DIR}/CollectionManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../StaticCollectionManager.h" "${CMAKE_CURRENT_BINARY_DIR}/StaticCollectionManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../DocumentManager.h" "${CMAKE_CURRENT_BINARY_DIR}/DocumentManager.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../ItemSequence.h" "${CMAKE_CURRENT_BINARY_DIR}/ItemSequence.h" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../Zorba.h" "${CMAKE_CURRENT_BINARY_DIR}/Zorba.h" COPYONLY)

  MESSAGE (STATUS "SWIG Python: Python module install path: " ${PYTHON_INSTALL_PATH})

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
  MESSAGE (STATUS "SWIG Python: binding not generated because library and include files are not installed.")
ENDIF (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)
