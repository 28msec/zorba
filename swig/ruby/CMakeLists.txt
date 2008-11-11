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

CMAKE_FIND_FRAMEWORKS ( Ruby )
FIND_PACKAGE(Ruby)

MESSAGE("Libary: " ${RUBY_LIBRARY}) 
MESSAGE("Include: " ${RUBY_INCLUDE_PATH}) 

STRING(COMPARE EQUAL ${RUBY_LIBRARY} "RUBY_LIBRARY-NOTFOUND" RUBY_LIBS_NOT_FOUND)
STRING(COMPARE EQUAL ${RUBY_INCLUDE_PATH} "RUBY_INCLUDE_PATH-NOTFOUND" RUBY_INCL_NOT_FOUND) 

IF(${RUBY_LIBS_NOT_FOUND} OR ${RUBY_INCL_NOT_FOUND})
  MESSAGE(STATUS "Ruby binding not generated because library and include file not installed.")
ELSE(${RUBY_LIBS_NOT_FOUND} OR ${RUBY_INCL_NOT_FOUND})
  MESSAGE(STATUS "Generating Ruby API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES(${RUBY_INCLUDE_PATH})
  SWIG_ADD_MODULE(zorba_api ruby zorba_api.i)
  SWIG_LINK_LIBRARIES(zorba_api zorba simplestore ${RUBY_LIBRARY})
  IF ( APPLE )
    set_target_properties( zorba_api PROPERTIES SUFFIX .bundle )
  ENDIF ( APPLE )
  EXECUTE_PROCESS(COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print Config::CONFIG['sitearchdir']"
48 	  OUTPUT_VARIABLE RUBY_SITEARCH_DIR)
  STRING(REPLACE "/usr/" "" RUBY_SITEARCH_DIR "${RUBY_SITEARCH_DIR}" )
  IF ( APPLE )
    INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.bundle
	  DESTINATION ${RUBY_SITEARCH_DIR} )
  ELSE ( APPLE )
    INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.so
	  DESTINATION ${RUBY_SITEARCH_DIR} )
  ENDIF ( APPLE )
ENDIF(${RUBY_LIBS_NOT_FOUND} OR ${RUBY_INCL_NOT_FOUND})
