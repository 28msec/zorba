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

IF (ZORBA_WITH_DEBUGGER)
  SET (DEBUG_CLIENT_SRCS
    debugger/tuple.h
    debugger/command.h
    debugger/command_arg.h
    debugger/main.cpp
    debugger/command_prompt.cpp
    debugger/command_line_handler.cpp
    debugger/lock_free_queue.cpp
    debugger/event_handler.cpp
  )
  ZORBA_GENERATE_EXE ("debuggercmd" "${DEBUG_CLIENT_SRCS}" "" "debugger" "bin")
ENDIF (ZORBA_WITH_DEBUGGER)

SET(SRCS
  zorbacmd.cpp
  zorbacmdproperties.cpp
  error_printer.cpp
  util.cpp
  module_path.cpp
)

INCLUDE("${CMAKE_SOURCE_DIR}/cmake_modules/ZorbaGenerateExe.cmake")
ZORBA_GENERATE_EXE("zorbacmd" "${SRCS}" "" "zorba" "bin")


IF(UNIX)
  ADD_CUSTOM_TARGET(zorbacmd_man help2man -N -s1 -n Zorba -S "FLWOR Foundation" ./zorba > "${PROJECT_BINARY_DIR}/doc/zorba.1")
  ADD_DEPENDENCIES(zorbacmd_man zorbacmd)
ENDIF(UNIX)

# test the basic features of the command line tool
ZORBA_ADD_TEST(bin/zorba1 zorbacmd --omit-xml-declaration -q "1+1")
ZORBA_SET_TEST_PROPERTY(bin/zorba1 PASS_REGULAR_EXPRESSION "2")

ZORBA_ADD_TEST(bin/zorba2 zorbacmd --serialize-html -q "1+1")
ZORBA_SET_TEST_PROPERTY(bin/zorba2 PASS_REGULAR_EXPRESSION "2")

ZORBA_ADD_TEST(bin/zorba3 zorbacmd -m 0 -q "1+1")
ZORBA_SET_TEST_PROPERTY(bin/zorba3 PASS_REGULAR_EXPRESSION "")

ZORBA_ADD_TEST(bin/zorba4 zorbacmd --context-item=${CMAKE_CURRENT_SOURCE_DIR}/test.xml  -m 3 -q "./test/child[1]")
ZORBA_SET_TEST_PROPERTY(bin/zorba4 PASS_REGULAR_EXPRESSION "(.*<child>child1</child>)*")

ZORBA_ADD_TEST(bin/zorba5 zorbacmd -q -f blub.xq)
ZORBA_SET_TEST_PROPERTY(bin/zorba5 PASS_REGULAR_EXPRESSION ".*Extra arguments found on command line.*")

# test the compile-only option of the command line tool which is used for semantic checking in eclipse
ZORBA_ADD_TEST(bin/zorba_compilechk1 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l)
ZORBA_SET_TEST_PROPERTY(bin/zorba_compilechk1 PASS_REGULAR_EXPRESSION ".*mymod.xq>:22,8:.*:XPST0008.*")

ZORBA_ADD_TEST(bin/zorba_compilechk2 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod.xq" -f -l -x)
ZORBA_SET_TEST_PROPERTY(bin/zorba_compilechk2 PASS_REGULAR_EXPRESSION ".*XPST0008.*mymod.xq' lineStart='22' columnStart='8' lineEnd='22' columnEnd='10'.*")

# test compile checking to work with library modules that have an invalid target namespace uri
# test for bug #2934414
ZORBA_ADD_TEST(bin/zorba_compilechk3 zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/mymod2.xq" -f -l -x)
ZORBA_SET_TEST_PROPERTY(bin/zorba_compilechk3 PASS_REGULAR_EXPRESSION ".*XQST0046.*mymod2.xq' lineStart='17' columnStart='1' lineEnd='17' columnEnd='26'.*")

# test the --option option to set an option in the static context
ZORBA_ADD_TEST(bin/zorba_option zorbacmd -q "${CMAKE_CURRENT_SOURCE_DIR}/test/option.xq" -f --option "{http://www.zorba-xquery.com}option=value")
ZORBA_SET_TEST_PROPERTY(bin/zorba_option PASS_REGULAR_EXPRESSION "value")
