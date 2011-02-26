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
# install path determined from where Python lives 

SET(JAVA_SRCS
  Test_Zorba.java)

FIND_PACKAGE(Java)

STRING(COMPARE NOTEQUAL ${JAVA_RUNTIME} "JAVA_RUNTIME-NOTFOUND" JAVA_FOUND) 
IF(JAVA_FOUND)
  SET(Java_Load_Path ${CMAKE_BINARY_DIR}/swig/java)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/java_test.sh.in ${CMAKE_CURRENT_BINARY_DIR}/java_test.sh)
  MESSAGE(STATUS "Seting path for java tests ${Java_Load_Path}")
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/Test_Zorba.java ${CMAKE_CURRENT_BINARY_DIR}/Test_Zorba.java COPYONLY)

  ADD_TEST("java" java_test.sh Test_Zorba)
ENDIF(JAVA_FOUND)
