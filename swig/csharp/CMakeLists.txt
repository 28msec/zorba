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

IF (WIN32)
  MESSAGE(STATUS "SWIG C#: generating C# API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
  #INCLUDE_DIRECTORIES(${CSHARP_INCLUDE_PATH})
  SWIG_ADD_MODULE(zorba_api_csharp csharp zorba_api.i)
  SWIG_LINK_LIBRARIES(zorba_api_csharp zorba_simplestore )
  SET_TARGET_PROPERTIES (zorba_api_csharp PROPERTIES OUTPUT_NAME "zorba_api")
  SET_TARGET_PROPERTIES( zorba_api_csharp PROPERTIES PROJECT_LABEL "Api_CSharp" )
  
  #EXECUTE_PROCESS(COMMAND ${CSHARP_EXECUTABLE} -V:sitelib OUTPUT_VARIABLE CSHARP_SITEARCH_DIR)
  #STRING(REPLACE "sitelib='" "" CSHARP_SITEARCH_DIR "${CSHARP_SITEARCH_DIR}" )
  #STRING(REPLACE "'" "" CSHARP_SITEARCH_DIR "${CSHARP_SITEARCH_DIR}" )
  #MESSAGE (STATUS "CSHARP_SITEARCH_DIR  : " ${CSHARP_SITEARCH_DIR})
  
  #INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.dll DESTINATION ${CSHARP_SITEARCH_DIR} )
ELSEIF (WIN32)
  MESSAGE(STATUS "SWIG C#: binding not generated because library and include files are not installed.")
ENDIF (WIN32)
