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
include ( FindJNI )

STRING ( COMPARE NOTEQUAL ${JAVA_INCLUDE_PATH} "JAVA_INCLUDE_PATH-NOTFOUND" JNI_FOUND )

IF ( JNI_FOUND )
include (CMakeJavaInformation )
MESSAGE(STATUS "Generating Java API")
EXECUTE_PROCESS ( COMMAND ${JAVA_RUNTIME} -version 
   OUTPUT_VARIABLE JAVA_VERSION )
MESSAGE ( STATUS "JNI found at ${JNI_INCLUDE_PATH}" )
SET_SOURCE_FILES_PROPERTIES(zorba_api.i PROPERTIES CPLUSPLUS ON)
INCLUDE_DIRECTORIES ( ${JAVA_INCLUDE_PATH} )

# Apple put jni_md.h at same level as jni.h
IF ( NOT APPLE )
# Following for jni_md.h
INCLUDE_DIRECTORIES ( ${JAVA_INCLUDE_PATH2} )
ENDIF ( NOT APPLE )

SWIG_ADD_MODULE ( libzorba_api java zorba_api.i)
  SWIG_LINK_LIBRARIES(libzorba_api zorba_simplestore ${JAVA_LIBRARY})
  IF ( APPLE )
    set_target_properties( libzorba_api PROPERTIES SUFFIX .jnilib )
  ENDIF ( APPLE )
SET ( JAVA_SITEARCH_DIR "/usr/share/java" )
  IF ( APPLE )
    INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/libzorba_api.jnilib
	  DESTINATION ${JAVA_SITEARCH_DIR} )
  ELSE ( APPLE )
    INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/libzorba_api.so
	  DESTINATION ${JAVA_SITEARCH_DIR} )
  ENDIF ( APPLE )

ELSE ( JNI_FOUND )
    MESSAGE ( STATUS "Not generating JAVA API because jni headers not found")
ENDIF ( JNI_FOUND )
