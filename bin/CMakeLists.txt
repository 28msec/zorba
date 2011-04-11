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

SET(SRCS
  zorbacmd.cpp
  zorbacmdproperties.cpp
  error_printer.cpp
  util.cpp
  module_path.cpp
  debugger_handler.cpp
  debugger_server_runnable.cpp
)
INCLUDE("${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateStoreSpecificExes.cmake")
ZORBA_GENERATE_STORE_SPECIFIC_EXES("zorbacmd" "${SRCS}" "" "zorba" "bin")


IF(UNIX)
  ADD_CUSTOM_TARGET(zorbacmd_man help2man -N -s1 -n Zorba -S "FLWOR Foundation" ./zorba > "${PROJECT_BINARY_DIR}/doc/zorba.1")
  ADD_DEPENDENCIES(zorbacmd_man zorbacmd)
ENDIF(UNIX)

INCLUDE(${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaAddTest.cmake)


# test the basic features of the command line tool
ZORBA_ADD_TEST_ALLSTORES(bin/zorba1 zorbacmd --omit-xml-declaration -q "1+1")
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba1 PASS_REGULAR_EXPRESSION "2")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba2 zorbacmd --serialize-html -q "1+1")
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba2 PASS_REGULAR_EXPRESSION "2")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba3 zorbacmd -m 0 -q "1+1")
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba3 PASS_REGULAR_EXPRESSION "")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba4 zorbacmd --context-item=${CMAKE_CURRENT_SOURCE_DIR}/test.xml  -m 3 -q "./test/child[1]")
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba4 PASS_REGULAR_EXPRESSION "(.*<child>child1</child>)*")

# test basic json and jsonml serialization features
ZORBA_ADD_TEST_ALLSTORES(bin/zorba_jsonml1 zorbacmd -q "<ul>1</ul>" -z method=jsonml)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_jsonml1 PASS_REGULAR_EXPRESSION "ul.*1")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba_json1 zorbacmd -q "<ul>1</ul>" -z method=json)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_json1 PASS_REGULAR_EXPRESSION ".*ZAPI0061.*")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba_jsonml2 zorbacmd -q "(<!--comment-->)" -z method=jsonml)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_jsonml2 PASS_REGULAR_EXPRESSION ".*ZAPI0065.*")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba_jsonml3 zorbacmd -q "(<ul>1</ul>,<ul>2</ul>)" -z method=jsonml)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_jsonml3 PASS_REGULAR_EXPRESSION ".*ZAPI0066.*")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba5 zorbacmd -q -f blub.xq)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba5 PASS_REGULAR_EXPRESSION ".*Extra arguments found on command line.*")

# test the compile-only option of the command line tool which is used for semantic checking in eclipse
ZORBA_ADD_TEST_ALLSTORES(bin/zorba_compilechk1 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_compilechk1 PASS_REGULAR_EXPRESSION ".*mymod.xq>:6,8:.*:XPST0008.*")

ZORBA_ADD_TEST_ALLSTORES(bin/zorba_compilechk2 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l -x)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_compilechk2 PASS_REGULAR_EXPRESSION ".*XPST0008.*mymod.xq' line='6' column='8'.*")

# test compile checking to work with library modules that have an invalid target namespace uri
# test for bug #2934414
ZORBA_ADD_TEST_ALLSTORES(bin/zorba_compilechk3 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod2.xq" -f -l -x)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_compilechk3 PASS_REGULAR_EXPRESSION ".*XQST0046.*mymod2.xq' line='1' column='1'.*")

# check error message for sequential expressions used in a wrong location
ZORBA_ADD_TEST_ALLSTORES(bin/zorba_sequential_err_msg zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/sequential_expr_err.xq" -f -l -x)
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_sequential_err_msg PASS_REGULAR_EXPRESSION ".*XUST0001.*line='6' column='7'.*>.*")

# test the --option option to set an option in the static context
ZORBA_ADD_TEST_ALLSTORES(bin/zorba_option zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/option.xq" -f --option "{http://www.zorba-xquery.com}option=value")
ZORBA_SET_TEST_PROPERTY_ALLSTORES(bin/zorba_option PASS_REGULAR_EXPRESSION "value")
