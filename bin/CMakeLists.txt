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

INCLUDE_DIRECTORIES(AFTER ${CMAKE_SOURCE_DIR}/src/)

SET(ZORBA_CMD_SRCS zorbacmd.cpp zorbacmdproperties.cpp)

IF(ZORBA_DEBUGGER)
 SET(ZORBA_CMD_SRCS ${ZORBA_CMD_SRCS} debugcmd_client.cpp) 
ENDIF(ZORBA_DEBUGGER)

ADD_EXECUTABLE(zorbacmd ${ZORBA_CMD_SRCS})
TARGET_LINK_LIBRARIES(zorbacmd zorba simplestore)
SET_TARGET_PROPERTIES(zorbacmd PROPERTIES OUTPUT_NAME "zorba") # cmake way to rename the file

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(zorbacmd_static ${ZORBA_CMD_SRCS})
  TARGET_LINK_LIBRARIES(zorbacmd_static zorba_static simplestore)
  SET_TARGET_PROPERTIES(zorbacmd_static PROPERTIES OUTPUT_NAME "zorba_static") # cmake way to rename the file
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

IF(WIN32 AND NOT UNIX)
	INSTALL(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/zorba.exe DESTINATION bin)	
ELSE(WIN32 AND NOT UNIX)
	INSTALL(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/zorba DESTINATION bin)
ENDIF(WIN32 AND NOT UNIX)


# test the command line tool
ADD_TEST(bin/zorba1 zorba --omit-xml-declaration -i "1+1")
SET_TESTS_PROPERTIES(bin/zorba1 PROPERTIES PASS_REGULAR_EXPRESSION "2")

ADD_TEST(bin/zorba2 zorba --serialize-html -i "1+1")
SET_TESTS_PROPERTIES(bin/zorba2 PROPERTIES PASS_REGULAR_EXPRESSION "<html>2</html>")

ADD_TEST(bin/zorba3 zorba -m 0 -i "1+1")
SET_TESTS_PROPERTIES(bin/zorba3 PROPERTIES PASS_REGULAR_EXPRESSION "")

ADD_TEST(bin/zorba4 zorba --context-item=${CMAKE_CURRENT_SOURCE_DIR}/test.xml  -m 3 -i "./test/child[1]")
SET_TESTS_PROPERTIES(bin/zorba4 PROPERTIES PASS_REGULAR_EXPRESSION "(.*<child>child1</child>)*")

