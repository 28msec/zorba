# Copyright 2006-2008 The FLWOR Foundation.n
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

FIND_PACKAGE ( Java )
INCLUDE ( ${CMAKE_SOURCE_DIR}/cmake_modules/FindJNI.cmake )

STRING ( COMPARE NOTEQUAL ${JAVA_INCLUDE_PATH} "JAVA_INCLUDE_PATH-NOTFOUND" JNI_FOUND )

IF (JAVA_INCLUDE_PATH)
  include (CMakeJavaInformation )
  MESSAGE(STATUS "SWIG Java: generating Java API")

  EXECUTE_PROCESS( COMMAND ${JAVA_RUNTIME} -version OUTPUT_VARIABLE JAVA_VERSION )
  MESSAGE(STATUS "SWIG Java: JNI found at: " ${JAVA_INCLUDE_PATH} )

  SET_SOURCE_FILES_PROPERTIES( zorba_api.i PROPERTIES CPLUSPLUS ON )
  INCLUDE_DIRECTORIES( ${JAVA_INCLUDE_PATH} )

  # Apple put jni_md.h at same level as jni.h
  IF ( NOT APPLE )
    # Following for jni_md.h
    INCLUDE_DIRECTORIES( ${JAVA_INCLUDE_PATH2} )
  ENDIF ( NOT APPLE )

  SET( CMAKE_SWIG_FLAGS -package org.zorbaxquery.api)

  SWIG_ADD_MODULE( libzorba_api java zorba_api.i )
  SWIG_LINK_LIBRARIES( libzorba_api zorba_simplestore ${JAVA_LIBRARY} )
  SET_PROPERTY( TARGET libzorba_api PROPERTY PROJECT_LABEL "Api_Java" )
  IF(WIN32)
    set_target_properties( libzorba_api PROPERTIES OUTPUT_NAME "zorba_api" )
  ENDIF(WIN32)
  IF ( APPLE )
    set_target_properties( libzorba_api PROPERTIES SUFFIX .jnilib )
  ENDIF ( APPLE )

  # The following fix was added because of the changes in CMake 2.8, which have the
  # result of naming the java binding library "liblibzorba_api.so" instead of "libzorba_api.so"
  IF ( LINUX OR CYGWIN )
    SET_TARGET_PROPERTIES( ${SWIG_MODULE_libzorba_api_REAL_NAME} PROPERTIES PREFIX "" )
  ENDIF ( LINUX OR CYGWIN )

  IF (${CMAKE_INSTALL_PREFIX} EQUAL "/usr/local")
    SET (JAVA_SITEARCH_DIR "/usr/share/java")
  ELSE (${CMAKE_INSTALL_PREFIX} EQUAL "/usr/local")
    SET (JAVA_SITEARCH_DIR ${CMAKE_INSTALL_PREFIX}/share/java)
  ENDIF (${CMAKE_INSTALL_PREFIX} EQUAL "/usr/local")

  MESSAGE(STATUS "Java module install path: " ${JAVA_SITEARCH_DIR})

  FILE(GLOB JAVA_SWIG_FILES "${CMAKE_CURRENT_BINARY_DIR}/*.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../StaticContext.h" "${CMAKE_CURRENT_BINARY_DIR}/StaticContext.h")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../ItemFactory.h" "${CMAKE_CURRENT_BINARY_DIR}/ItemFactory.h")

  IF ( APPLE )
    INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_SWIG_LIB_PREFIX}libzorba_api.jnilib DESTINATION ${JAVA_SITEARCH_DIR})
		INSTALL(FILES ${JAVA_SWIG_FILES} DESTINATION ${JAVA_SITEARCH_DIR})
  ELSE ( APPLE )
		IF(NOT WIN32)
      INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/libzorba_api.so DESTINATION ${JAVA_SITEARCH_DIR})
		  INSTALL(FILES ${JAVA_SWIG_FILES} DESTINATION ${JAVA_SITEARCH_DIR})
		ELSE(NOT WIN32)
      IF (MSVC_IDE)
        INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/zorba_api.dll 
        DESTINATION share/java
        COMPONENT "java_swig")
        INSTALL(FILES ${JAVA_SWIG_FILES} 
        DESTINATION share/java
        COMPONENT "java_swig")
      ELSE (MSVC_IDE)
        INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.dll 
        DESTINATION share/java
        COMPONENT "java_swig")
        INSTALL(FILES ${JAVA_SWIG_FILES} 
        DESTINATION share/java
        COMPONENT "java_swig")
      ENDIF (MSVC_IDE)
		ENDIF(NOT WIN32)
  ENDIF ( APPLE )

EXECUTE_PROCESS( COMMAND ${JAVA_RUNTIME} -version OUTPUT_VARIABLE JAVA_VERSION )
# todo cezar compile and jar it up

ELSE (JAVA_INCLUDE_PATH)
  MESSAGE ( STATUS "SWIG Java: not generating JAVA API because jni headers not found.")
ENDIF (JAVA_INCLUDE_PATH)
