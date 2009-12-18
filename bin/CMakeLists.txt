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
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_SOURCE_DIR})

SET( SRCS
  zorbacmdproperties.cpp error_printer.cpp util.cpp module_path.cpp
  debugger_handler.cpp debugger_server_runnable.cpp
)

ZORBA_GENERATE_STORE_SPECIFIC_EXES("zorbacmd" "${SRCS}" "" "zorba")


IF(UNIX)
  ADD_CUSTOM_TARGET(zorbacmd_man help2man -N -s1 -n Zorba -S "FLWOR Foundation" ./zorba > "${PROJECT_BINARY_DIR}/doc/zorba.1")
  ADD_DEPENDENCIES(zorbacmd_man zorbacmd)
ENDIF(UNIX)

IF (BUILDING_SIMPLESTORE)
  INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaAddTest.cmake)


  # test the basic features of the command line tool
  ZORBA_ADD_TEST_SIMPLE(bin/zorba1 zorbacmd --omit-xml-declaration -q "1+1")
  SET_TESTS_PROPERTIES(bin/zorba1 PROPERTIES PASS_REGULAR_EXPRESSION "2")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba2 zorbacmd --serialize-html -q "1+1")
  SET_TESTS_PROPERTIES(bin/zorba2 PROPERTIES PASS_REGULAR_EXPRESSION "2")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba3 zorbacmd -m 0 -q "1+1")
  SET_TESTS_PROPERTIES(bin/zorba3 PROPERTIES PASS_REGULAR_EXPRESSION "")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba4 zorbacmd --context-item=${CMAKE_CURRENT_SOURCE_DIR}/test.xml  -m 3 -q "./test/child[1]")
  SET_TESTS_PROPERTIES(bin/zorba4 PROPERTIES PASS_REGULAR_EXPRESSION "(.*<child>child1</child>)*")
  
  # test basic json and jsonml serialization features
  ZORBA_ADD_TEST_SIMPLE(bin/zorba_jsonml1 zorbacmd -q "<ul>1</ul>" -z method=jsonml)
  SET_TESTS_PROPERTIES(bin/zorba_jsonml1 PROPERTIES PASS_REGULAR_EXPRESSION "ul.*1")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba_json1 zorbacmd -q "<ul>1</ul>" -z method=json)
  SET_TESTS_PROPERTIES(bin/zorba_json1 PROPERTIES PASS_REGULAR_EXPRESSION ".*API0061.* Could not serialize the element with string representation .*1.*")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba_jsonml2 zorbacmd -q "(<!--comment-->)" -z method=jsonml)
  SET_TESTS_PROPERTIES(bin/zorba_jsonml2 PROPERTIES PASS_REGULAR_EXPRESSION ".*API0065.* Parameter with string representation .*comment.* is not an element node.")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba_jsonml3 zorbacmd -q "(<ul>1</ul>,<ul>2</ul>)" -z method=jsonml)
  SET_TESTS_PROPERTIES(bin/zorba_jsonml3 PROPERTIES PASS_REGULAR_EXPRESSION ".*API0066.*")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba5 zorbacmd -q -f blub.xq)
  SET_TESTS_PROPERTIES(bin/zorba5 PROPERTIES PASS_REGULAR_EXPRESSION ".*Extra arguments found on command line.*")
  
  # test the compile-only option of the command line tool which is used for semantic checking in eclipse
  ZORBA_ADD_TEST_SIMPLE(bin/zorba_compilechk1 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l)
  SET_TESTS_PROPERTIES(bin/zorba_compilechk1 PROPERTIES PASS_REGULAR_EXPRESSION ".*mymod.xq.*line 6, column 8:.*XPST0008.*")
  
  ZORBA_ADD_TEST_SIMPLE(bin/zorba_compilechk2 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l -x)
  SET_TESTS_PROPERTIES(bin/zorba_compilechk2 PROPERTIES PASS_REGULAR_EXPRESSION ".*XPST0008.*mymod.xq' lineStart='6' columnStart='8' lineEnd='6' columnEnd='8'.*")
ENDIF(BUILDING_SIMPLESTORE)
