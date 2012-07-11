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

SET (JAVA_SRCS Test_Zorba.java)

FIND_PACKAGE (Java)

IF (JAVA_RUNTIME)
  SET (Java_Load_Path ${CMAKE_BINARY_DIR}/swig/java)
  SET (Java_Source_Path ${CMAKE_BINARY_DIR}/swig/java)
  MESSAGE (STATUS "Seting path for java tests ${Java_Load_Path}")
  CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/Test_Zorba.java ${CMAKE_CURRENT_BINARY_DIR}/Test_Zorba.java COPYONLY)
  IF (WIN32)
    IF (MSVC_IDE)
      SET (Java_Load_Path ${CMAKE_BINARY_DIR}/swig/java/${CMAKE_BUILD_TYPE})
    ENDIF (MSVC_IDE)
    CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/java_test.bat.in ${CMAKE_CURRENT_BINARY_DIR}/java_test.bat)
    ADD_TEST ("java" java_test.bat Test_Zorba)
  ELSEIF (WIN32)
    CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/java_test.sh.in ${CMAKE_CURRENT_BINARY_DIR}/java_test.sh)
    ADD_TEST ("java" java_test.sh Test_Zorba)
  ENDIF (WIN32)
ENDIF (JAVA_RUNTIME)
