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

FIND_PACKAGE(Lua51)

IF (LUA51_FOUND)
  MESSAGE(STATUS "SWIG LUA: generating LUA API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})
  SWIG_ADD_MODULE(zorba_api_lua lua zorba_api.i)
  SWIG_LINK_LIBRARIES(zorba_api_lua zorba_simplestore ${LUA_LIBRARIES})
  SET_TARGET_PROPERTIES (zorba_api_lua PROPERTIES OUTPUT_NAME "zorba_api")
  SET_TARGET_PROPERTIES( zorba_api_lua PROPERTIES PROJECT_LABEL "Api_LUA" )
  
  #EXECUTE_PROCESS(COMMAND ${LUA_EXECUTABLE} -V:sitelib OUTPUT_VARIABLE LUA_SITEARCH_DIR)
  #STRING(REPLACE "sitelib='" "" LUA_SITEARCH_DIR "${LUA_SITEARCH_DIR}" )
  #STRING(REPLACE "'" "" LUA_SITEARCH_DIR "${LUA_SITEARCH_DIR}" )
  #MESSAGE (STATUS "LUA_SITEARCH_DIR  : " ${LUA_SITEARCH_DIR})
  
  #INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.dll DESTINATION ${LUA_SITEARCH_DIR} )
ELSEIF (LUA51_FOUND)
  MESSAGE(STATUS "SWIG LUA: binding not generated because library and include files are not installed.")
ENDIF (LUA51_FOUND)
