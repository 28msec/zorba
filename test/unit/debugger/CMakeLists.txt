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
 
ADD_EXECUTABLE(DebuggerTests ${DebuggerTests} DebuggerTestClient.cpp DebuggerTestHandler.cpp)
TARGET_LINK_LIBRARIES(DebuggerTests zorba_simplestore)

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(DebuggerTests_static ${DebuggerTests})
  SET_TARGET_PROPERTIES(DebuggerTests_static PROPERTIES COMPILE_DEFINITIONS BUILDING_ZORBA_STATIC)
  TARGET_LINK_LIBRARIES(DebuggerTests_static zorba_simplestore_static)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)

IF(WIN32)
SET(DebuggerTests_EXE_PATH    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/DebuggerTests)
ELSE(WIN32)
SET(DebuggerTests_EXE_PATH    DebuggerTests)
ENDIF(WIN32)

SET (TestsToRun ${DebuggerTests})
REMOVE (TestsToRun DebuggerTests.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
  	SET (TestName "test/unit/debugger/${TName}")
	ADD_TEST(${TestName} ${DebuggerTests_EXE_PATH} ${TName})
ENDFOREACH(test)
