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

CMAKE_FIND_FRAMEWORKS(Perl)
FIND_PACKAGE(Perl)
FIND_PACKAGE(PerlLibs)

IF (PERL_LIBRARY AND PERL_INCLUDE_PATH)
  MESSAGE(STATUS "SWIG Perl: generating Perl API")
  SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
  INCLUDE_DIRECTORIES(${PERL_INCLUDE_PATH})
  SWIG_ADD_MODULE(zorba_api_perl perl zorba_api.i)
  SWIG_LINK_LIBRARIES(zorba_api_perl zorba_simplestore ${PERL_LIBRARY})
  SET_TARGET_PROPERTIES (zorba_api_perl PROPERTIES OUTPUT_NAME "zorba_api")
  #SET_PROPERTY( TARGET zorba_api_perl PROPERTY PROJECT_LABEL "Api_Perl" )
  SET_TARGET_PROPERTIES( zorba_api_perl PROPERTIES PROJECT_LABEL "Api_Perl" )
  
  IF ( APPLE )
    SET_TARGET_PROPERTIES( zorba_api_perl PROPERTIES SUFFIX .bundle )
  ENDIF ( APPLE )

  # The following fix was added because of the changes in CMake 2.8, which have the
  # result of naming the java binding library "liblibzorba_api.so" instead of "libzorba_api.so"
  IF ( LINUX OR CYGWIN )
    SET_TARGET_PROPERTIES( ${SWIG_MODULE_zorba_api_REAL_NAME} PROPERTIES PREFIX "" )
  ENDIF ( LINUX OR CYGWIN )

  EXECUTE_PROCESS(COMMAND ${PERL_EXECUTABLE} -V:sitelib OUTPUT_VARIABLE PERL_SITEARCH_DIR)
  STRING(REPLACE "sitelib='" "" PERL_SITEARCH_DIR "${PERL_SITEARCH_DIR}" )
  STRING(REPLACE "'" "" PERL_SITEARCH_DIR "${PERL_SITEARCH_DIR}" )
  MESSAGE (STATUS "PERL_SITEARCH_DIR  : " ${PERL_SITEARCH_DIR})
  
  IF ( APPLE )
    INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_SWIG_LIB_PREFIX}zorba_api.bundle
    DESTINATION ${PERL_SITEARCH_DIR} )
  ELSE ( APPLE )
    IF (WIN32)
      #INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.dll DESTINATION ${PERL_SITEARCH_DIR} )
    ELSEIF (WIN32)
      INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.so
      DESTINATION ${PERL_SITEARCH_DIR} )
    ENDIF (WIN32)
  ENDIF ( APPLE )
ELSE (PERL_LIBRARY AND PERL_INCLUDE_PATH)
  MESSAGE(STATUS "SWIG Perl: binding not generated because library and include files are not installed.")
ENDIF (PERL_LIBRARY AND PERL_INCLUDE_PATH)
