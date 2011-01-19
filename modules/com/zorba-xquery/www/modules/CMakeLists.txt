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

ADD_SUBDIRECTORY(email)
ADD_SUBDIRECTORY(security)
ADD_SUBDIRECTORY(image)
 

IF(ZORBA_WITH_FILE_ACCESS)
  GENERATE_MODULE_LIBRARY(file "")
ENDIF(ZORBA_WITH_FILE_ACCESS)


IF(ZORBA_WITH_PROCESS_ACCESS)
  GENERATE_MODULE_LIBRARY(process "")
ENDIF(ZORBA_WITH_PROCESS_ACCESS)

IF(CURL_FOUND)
  GENERATE_MODULE_LIBRARY(http-client "")
ENDIF(CURL_FOUND)

# JNI
INCLUDE (${CMAKE_SOURCE_DIR}/cmake_modules/FindJNI.cmake)

# Java
FIND_PACKAGE(Java)

STRING (COMPARE NOTEQUAL ${JAVA_INCLUDE_PATH} "JAVA_INCLUDE_PATH-NOTFOUND" JNI_FOUND)

IF (JNI_FOUND)
  SET(ZORBA_WITH_FOP ON CACHE BOOL "Compile Zorba with XSL-FO support" FORCE)
  IF (ZORBA_WITH_FOP)
    INCLUDE (CMakeJavaInformation )
    MESSAGE(STATUS "Generating Java API")
    EXECUTE_PROCESS ( COMMAND ${JAVA_RUNTIME} -version OUTPUT_VARIABLE JAVA_VERSION )
    MESSAGE ( STATUS "JNI found at ${JAVA_INCLUDE_PATH}" )
    INCLUDE_DIRECTORIES ( ${JAVA_INCLUDE_PATH} ${JAVA_INCLUDE_PATH2} )
    MESSAGE ( STATUS "Java Library at ${JAVA_JVM_LIBRARY}" )
    MESSAGE(STATUS "Building Zorba with Apache-FOP.")

    INCLUDE_DIRECTORIES(${JAVA_INCLUDE_PATH})
    GENERATE_MODULE_LIBRARY(xsl-fo "${JAVA_JVM_LIBRARY}")
  ELSE ( JNI_FOUND )
    IF (ZORBA_WITH_FOP)
      MESSAGE(FATAL_ERROR "Could not find Java and JNI. Please install a JDK or compile zorba without fop support")
    ENDIF (ZORBA_WITH_FOP)
   MESSAGE ( STATUS "Not generating Apache-FOP jni headers not found")
  ENDIF()
ELSE ()
  SET(ZORBA_WITH_FOP OFF CACHE BOOL "Compile Zorba with XSL-FO support" FORCE)
  MESSAGE(STATUS "Compile Zorba without XSL-FO support")
ENDIF ()

GENERATE_MODULE_LIBRARY(serialize "")
GENERATE_MODULE_LIBRARY(datetime "")
GENERATE_MODULE_LIBRARY(os "")

GENERATE_MODULE_LIBRARY(csv "")

#add unit test for streambuf implementation in csv, related to streamable strings
CREATE_TEST_SOURCELIST(StreambufUnitTests StreambufUnitTests.cpp
						streambuftest.cpp
						)
ADD_EXECUTABLE("StreambufUnitTests" ${StreambufUnitTests} csv.xq.src/stringiterator_streambuf.cpp)
ADD_TEST("streamable_string_streambuf" StreambufUnitTests "streambuftest")
