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
  INCLUDE (CMakeJavaInformation )
  MESSAGE(STATUS "SWIG Java: Generating XQJ API")

  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQConnection.java" "${CMAKE_CURRENT_BINARY_DIR}/XQConnection.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQDataSource.java" "${CMAKE_CURRENT_BINARY_DIR}/XQDataSource.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQExpression.java" "${CMAKE_CURRENT_BINARY_DIR}/XQExpression.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQItem.java" "${CMAKE_CURRENT_BINARY_DIR}/XQItem.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQItemType.java" "${CMAKE_CURRENT_BINARY_DIR}/XQItemType.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQMetaData.java" "${CMAKE_CURRENT_BINARY_DIR}/XQMetaData.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQPreparedExpression.java" "${CMAKE_CURRENT_BINARY_DIR}/XQPreparedExpression.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQResultItem.java" "${CMAKE_CURRENT_BINARY_DIR}/XQResultItem.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQResultSequence.java" "${CMAKE_CURRENT_BINARY_DIR}/XQResultSequence.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQResultSequenceScrollable.java" "${CMAKE_CURRENT_BINARY_DIR}/XQResultSequenceScrollable.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQSequence.java" "${CMAKE_CURRENT_BINARY_DIR}/XQSequence.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQSequenceType.java" "${CMAKE_CURRENT_BINARY_DIR}/XQSequenceType.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQStaticContext.java" "${CMAKE_CURRENT_BINARY_DIR}/XQStaticContext.java")

  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQCollection.java" "${CMAKE_CURRENT_BINARY_DIR}/XQCollection.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQCollectionManager.java" "${CMAKE_CURRENT_BINARY_DIR}/XQCollectionManager.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQStaticCollectionManager.java" "${CMAKE_CURRENT_BINARY_DIR}/XQStaticCollectionManager.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQDocumentManager.java" "${CMAKE_CURRENT_BINARY_DIR}/XQDocumentManager.java")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/XQXmlDataManager.java" "${CMAKE_CURRENT_BINARY_DIR}/XQXmlDataManager.java")

  MESSAGE(STATUS "SWIG Java: Generating XQJ TCK Tests")
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/tck/junit-4.9.jar" "${CMAKE_CURRENT_BINARY_DIR}/tck/junit-4.9.jar" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/tck/xqjapi.jar" "${CMAKE_CURRENT_BINARY_DIR}/tck/xqjapi.jar" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/tck/xqjtck.jar" "${CMAKE_CURRENT_BINARY_DIR}/tck/xqjtck.jar" COPYONLY)
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/tck/zorba.properties" "${CMAKE_CURRENT_BINARY_DIR}/tck/zorba.properties" COPYONLY)

  SET (XQJ_LOAD_PATH "${CMAKE_BINARY_DIR}/swig/xqj")
  SET (JAVA_LOAD_PATH "${CMAKE_BINARY_DIR}/swig/java")

  MESSAGE (STATUS "Path for XQJ tests ${XQJ_LOAD_PATH}/tck")
  IF(WIN32)
    #Convert to backslashes for windows
    STRING(REGEX REPLACE "/" "\\\\" XQJ_LOAD_PATH ${XQJ_LOAD_PATH}) 
    STRING(REGEX REPLACE "/" "\\\\" JAVA_LOAD_PATH ${JAVA_LOAD_PATH}) 
    MESSAGE (STATUS "Copying tck batch...")
    CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/tck/xqj_test.bat.in ${CMAKE_CURRENT_BINARY_DIR}/xqj_test.bat)
    ADD_TEST ("swig_xqj" xqj_test.bat)
    SET_TESTS_PROPERTIES("swig_xqj" PROPERTIES PASS_REGULAR_EXPRESSION "254 tests")
  ELSE(WIN32)
    MESSAGE (STATUS "Copying tck batch...")
    IF (NOT DEFINED Java_JAVA_EXECUTABLE)
      SET(Java_JAVA_EXECUTABLE ${JAVA_RUNTIME})
      SET(Java_JAR_EXECUTABLE ${JAVA_ARCHIVE})
      SET(Java_JAVAC_EXECUTABLE ${JAVA_COMPILE})
    ENDIF (NOT DEFINED Java_JAVA_EXECUTABLE)
    CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/tck/xqj_test.sh.in ${CMAKE_CURRENT_BINARY_DIR}/xqj_test.sh)  
    EXECUTE_PROCESS(COMMAND chmod +x "${CMAKE_CURRENT_BINARY_DIR}/xqj_test.sh")
    EXECUTE_PROCESS(COMMAND chmod +x "${CMAKE_CURRENT_BINARY_DIR}/tck/junit-4.9.jar")
    EXECUTE_PROCESS(COMMAND chmod +x "${CMAKE_CURRENT_BINARY_DIR}/tck/xqjapi.jar")
    EXECUTE_PROCESS(COMMAND chmod +x "${CMAKE_CURRENT_BINARY_DIR}/tck/xqjtck.jar")
    EXECUTE_PROCESS(COMMAND chmod +x "${CMAKE_CURRENT_BINARY_DIR}/tck/zorba.properties")
    ADD_TEST ("swig_xqj" xqj_test.sh)
    SET_TESTS_PROPERTIES("swig_xqj" PROPERTIES PASS_REGULAR_EXPRESSION "254 tests")
  ENDIF(WIN32)


ELSE (JAVA_INCLUDE_PATH)
  MESSAGE ( STATUS "SWIG Java: Not generating XQJ API because JNI headers not found.")
ENDIF (JAVA_INCLUDE_PATH)