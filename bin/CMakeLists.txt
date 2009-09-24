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

SET(ZORBA_CMD_SRCS zorbacmd.cpp zorbacmdproperties.cpp error_printer.cpp)

SET(ZORBA_CMD_SRCS ${ZORBA_CMD_SRCS} debugger_handler.cpp debugger_server_runnable.cpp)

ADD_EXECUTABLE(zorbacmd ${ZORBA_CMD_SRCS})

TARGET_LINK_LIBRARIES(zorbacmd zorba_${ZORBA_STORE_LIB_EXTENSION})
SET_TARGET_PROPERTIES(zorbacmd PROPERTIES OUTPUT_NAME "zorba") # cmake way to rename the file
INSTALL(TARGETS zorbacmd DESTINATION bin)

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(zorbacmd_static ${ZORBA_CMD_SRCS})
  TARGET_LINK_LIBRARIES(zorbacmd_static zorba_${ZORBA_STORE_LIB_EXTENSION}_static)
  SET_TARGET_PROPERTIES(zorbacmd_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
  SET_TARGET_PROPERTIES(zorbacmd_static PROPERTIES OUTPUT_NAME "zorba_static") # cmake way to rename the file
  INSTALL(TARGETS zorbacmd_static DESTINATION bin)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

IF(UNIX)
  ADD_CUSTOM_TARGET(zorbacmd_man help2man -N -s1 -n Zorba -S "FLWOR Foundation" ./zorba > "${PROJECT_BINARY_DIR}/doc/zorba.1")
  ADD_DEPENDENCIES(zorbacmd_man zorbacmd)
ENDIF(UNIX)

IF(WIN32)
SET(ZORBA_EXE_PATH    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zorba)
ELSE(WIN32)
SET(ZORBA_EXE_PATH    zorba)
ENDIF(WIN32)


# test the basic features of the command line tool
ADD_TEST(bin/zorba1 ${ZORBA_EXE_PATH} --omit-xml-declaration -q "1+1")
SET_TESTS_PROPERTIES(bin/zorba1 PROPERTIES PASS_REGULAR_EXPRESSION "2")

ADD_TEST(bin/zorba2 ${ZORBA_EXE_PATH} --serialize-html -q "1+1")
SET_TESTS_PROPERTIES(bin/zorba2 PROPERTIES PASS_REGULAR_EXPRESSION "2")

ADD_TEST(bin/zorba3 ${ZORBA_EXE_PATH} -m 0 -q "1+1")
SET_TESTS_PROPERTIES(bin/zorba3 PROPERTIES PASS_REGULAR_EXPRESSION "")

ADD_TEST(bin/zorba4 ${ZORBA_EXE_PATH} --context-item=${CMAKE_CURRENT_SOURCE_DIR}/test.xml  -m 3 -q "./test/child[1]")
SET_TESTS_PROPERTIES(bin/zorba4 PROPERTIES PASS_REGULAR_EXPRESSION "(.*<child>child1</child>)*")

# test basic json and jsonml serialization features
ADD_TEST(bin/zorba_jsonml1 ${ZORBA_EXE_PATH} -q "<ul>1</ul>" -z method=jsonml)
SET_TESTS_PROPERTIES(bin/zorba_jsonml1 PROPERTIES PASS_REGULAR_EXPRESSION "ul.*1")

ADD_TEST(bin/zorba_json1 ${ZORBA_EXE_PATH} -q "<ul>1</ul>" -z method=json)
SET_TESTS_PROPERTIES(bin/zorba_json1 PROPERTIES PASS_REGULAR_EXPRESSION ".*API0061.* Could not serialize the element with string representation .*1.*")

ADD_TEST(bin/zorba_jsonml2 ${ZORBA_EXE_PATH} -q "(<!--comment-->)" -z method=jsonml)
SET_TESTS_PROPERTIES(bin/zorba_jsonml2 PROPERTIES PASS_REGULAR_EXPRESSION ".*API0065.* Parameter with string representation .*comment.* is not an element node.")

ADD_TEST(bin/zorba_jsonml3 ${ZORBA_EXE_PATH} -q "(<ul>1</ul>,<ul>2</ul>)" -z method=jsonml)
SET_TESTS_PROPERTIES(bin/zorba_jsonml3 PROPERTIES PASS_REGULAR_EXPRESSION ".*API0066.*")

ADD_TEST(bin/zorba5 ${ZORBA_EXE_PATH} -q -f blub.xq)
SET_TESTS_PROPERTIES(bin/zorba5 PROPERTIES PASS_REGULAR_EXPRESSION ".*Extra arguments found on command line.*")
IF (CMAKE_MINOR_VERSION STREQUAL "4")
  SET_TESTS_PROPERTIES(bin/zorba5 PROPERTIES WILL_FAIL TRUE)
ENDIF (CMAKE_MINOR_VERSION STREQUAL "4")

# test the compile-only option of the command line tool which is used for semantic checking in eclipse
ADD_TEST(bin/zorba_compilechk1 ${ZORBA_EXE_PATH} -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l)
SET_TESTS_PROPERTIES(bin/zorba_compilechk1 PROPERTIES PASS_REGULAR_EXPRESSION ".*mymod.xq.*line 6, column 8:.*XPST0008.*")

ADD_TEST(bin/zorba_compilechk2 ${ZORBA_EXE_PATH} -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l -x)
SET_TESTS_PROPERTIES(bin/zorba_compilechk2 PROPERTIES PASS_REGULAR_EXPRESSION ".*XPST0008.*mymod.xq' lineStart='6' columnStart='8' lineEnd='6' columnEnd='8'.*")
