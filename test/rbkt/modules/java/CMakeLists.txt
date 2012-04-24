# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License")
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

# For now we only test building a .jar that we want Zorba to make available
# on the JVM claspath. This test scenario should be extended to include a
# Zorba module using the .jar, etc.
# We make use of the much-improved Java support added in CMake 2.8.6.
COMPARE_VERSION_STRINGS (${CMAKE_VERSION} "2.8.6" RESULT)
IF (${RESULT} GREATER -1)
  FIND_PACKAGE (Java COMPONENTS Development)
  IF (Java_Development_FOUND)
    INCLUDE (UseJava)

    # Declare two "different" jars, for testing
    ADD_JAR (JavaTest Test.java)
    ADD_JAR (JavaTest2 Test.java)

    # Tell Zorba about the jars
    GET_PROPERTY (JavaTest_JAR_FILE TARGET JavaTest PROPERTY JAR_FILE)
    GET_PROPERTY (JavaTest2_JAR_FILE TARGET JavaTest2 PROPERTY JAR_FILE)
    DECLARE_ZORBA_JAR(FILE ${JavaTest_JAR_FILE} TARGET JavaTest TEST_ONLY)
    DECLARE_ZORBA_JAR(FILE ${JavaTest2_JAR_FILE} TARGET JavaTest2 TEST_ONLY)

    # Pretend to tell Zorba about some system jars
    DECLARE_ZORBA_JAR(EXTERNAL FILE
      "${PROJECT_SOURCE_DIR}/MyJar.jar" "${PROJECT_SOURCE_DIR}/MyJar2.jar")

  ENDIF (Java_Development_FOUND)
ENDIF (${RESULT} GREATER -1)
