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

# create the testing file and list of tests
CREATE_TEST_SOURCELIST(DebuggerTests
    DebuggerTests.cpp
    test_debugger_protocol.cpp
    test_debugger_endianness.cpp
    test_debugger_server.cpp
)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/bin)
 
SET(DEBUGGER_TEST_SRCS ${DebuggerTests} DebuggerTestClient.cpp DebuggerTestHandler.cpp ${CMAKE_SOURCE_DIR}/bin/debugger_server_runnable.cpp ${CMAKE_SOURCE_DIR}/bin/error_printer.cpp)
ZORBA_GENERATE_STORE_SPECIFIC_EXES(DebuggerTests "${DEBUGGER_TEST_SRCS}" "" "" "")

SET (TestsToRun ${DebuggerTests})
REMOVE (TestsToRun DebuggerTests.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
  	SET (TestName "test/unit/debugger/${TName}")
        ZORBA_ADD_TEST_ALLSTORES("${TestName}" DebuggerTests ${TName})
ENDFOREACH(test)

