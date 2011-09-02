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

INCLUDE (FindR.cmake)

IF (R_LIBRARIES)
  MESSAGE(STATUS "SWIG R: generating R API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES(${R_INCLUDE_DIR})
  SWIG_ADD_MODULE(zorba_api_r r zorba_api.i)
  SWIG_LINK_LIBRARIES(zorba_api_r zorba_simplestore ${R_LIBRARIES})
  SET_TARGET_PROPERTIES (zorba_api_r PROPERTIES OUTPUT_NAME "zorba_api")
  SET_TARGET_PROPERTIES( zorba_api_r PROPERTIES PROJECT_LABEL "Api_R" )
  
  #EXECUTE_PROCESS(COMMAND ${R_EXECUTABLE} -V:sitelib OUTPUT_VARIABLE R_SITEARCH_DIR)
  #STRING(REPLACE "sitelib='" "" R_SITEARCH_DIR "${R_SITEARCH_DIR}" )
  #STRING(REPLACE "'" "" R_SITEARCH_DIR "${R_SITEARCH_DIR}" )
  #MESSAGE (STATUS "R_SITEARCH_DIR  : " ${R_SITEARCH_DIR})
  
  #INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.dll DESTINATION ${R_SITEARCH_DIR} )
ELSEIF (R_LIBRARIES)
  MESSAGE(STATUS "SWIG R: binding not generated because library and include files are not installed.")
ENDIF (R_LIBRARIES)
