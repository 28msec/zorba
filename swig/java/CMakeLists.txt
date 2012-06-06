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
  MESSAGE(STATUS "SWIG: Generating Java API")

  SET_SOURCE_FILES_PROPERTIES( zorba_api.i PROPERTIES CPLUSPLUS ON )
  INCLUDE_DIRECTORIES( ${JAVA_INCLUDE_PATH} )

  # Apple put jni_md.h at same level as jni.h
  IF ( NOT APPLE )
    # Following for jni_md.h
    INCLUDE_DIRECTORIES( ${JAVA_INCLUDE_PATH2} )
  ENDIF ( NOT APPLE )

  SET( CMAKE_SWIG_FLAGS -package org.zorbaxquery.api)

  SWIG_ADD_MODULE( lib_zorba_java_api java zorba_api.i )
  SWIG_LINK_LIBRARIES( lib_zorba_java_api zorba_simplestore ${JAVA_LIBRARY} )
  SET_TARGET_PROPERTIES( lib_zorba_java_api PROPERTIES PROJECT_LABEL "Java" OUTPUT_NAME "zorba_api" FOLDER "APIs")
  IF ( APPLE )
    SET_TARGET_PROPERTIES( lib_zorba_java_api PROPERTIES SUFFIX .jnilib )
  ENDIF ( APPLE )

  # The following fix was added because of the changes in CMake 2.8, which have the
  # result of naming the java binding library "liblibzorba_api.so" instead of "libzorba_api.so"
  IF (LINUX OR CYGWIN OR APPLE)
    SET_TARGET_PROPERTIES( lib_zorba_java_api PROPERTIES PREFIX "" )
  ENDIF (LINUX OR CYGWIN OR APPLE)

  FILE(GLOB ZORBA_API_HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/../" "${CMAKE_CURRENT_SOURCE_DIR}/../*.h")
  FOREACH(ZORBA_API_HEADER ${ZORBA_API_HEADERS})
    CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/../${ZORBA_API_HEADER}"  "${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_API_HEADER}" COPYONLY)
  ENDFOREACH(ZORBA_API_HEADER ${ZORBA_API_HEADERS})
  
  ADD_CUSTOM_COMMAND(TARGET lib_zorba_java_api
                 POST_BUILD
                 COMMAND cmake -E echo "Compiling Java files..."
                 COMMAND ${Java_JAVAC_EXECUTABLE} *.java -d ${CMAKE_CURRENT_BINARY_DIR}
                 COMMAND cmake -E echo "Creating jar file..."
                 COMMAND ${Java_JAR_EXECUTABLE} cvf zorba_api.jar org
  )

  # ---  Install
  IF (${CMAKE_INSTALL_PREFIX} EQUAL "/usr/local")
    SET (JAVA_SITEARCH_DIR "/usr/share/java")
  ELSE (${CMAKE_INSTALL_PREFIX} EQUAL "/usr/local")
    SET (JAVA_SITEARCH_DIR ${CMAKE_INSTALL_PREFIX}/share/java)
  ENDIF (${CMAKE_INSTALL_PREFIX} EQUAL "/usr/local")

  FILE(GLOB JAVA_SWIG_FILES "${CMAKE_CURRENT_BINARY_DIR}/zorba_api.jar")
  SET(ZORBA_JAVA_JAR "${CMAKE_CURRENT_BINARY_DIR}/zorba_api.jar" PARENT_SCOPE )

  IF ( APPLE )
    INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${ZORBA_SWIG_LIB_PREFIX}libzorba_api.jnilib DESTINATION ${JAVA_SITEARCH_DIR})
		INSTALL(FILES ${JAVA_SWIG_FILES} DESTINATION ${JAVA_SITEARCH_DIR})
  ELSE ( APPLE )
		IF(NOT WIN32)
      INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/zorba_api.so DESTINATION ${JAVA_SITEARCH_DIR})
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

 
ELSE (JAVA_INCLUDE_PATH)
  MESSAGE ( STATUS "SWIG: Java binding not generated because JNI was not found.")
ENDIF (JAVA_INCLUDE_PATH)
