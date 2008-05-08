# create the testing file and list of tests
CREATE_TEST_SOURCELIST(DebuggerTests
    DebuggerTests.cpp
    test_debugger_socket.cpp
    test_debugger_protocol.cpp
)
 
ADD_EXECUTABLE(DebuggerTests ${DebuggerTests})
TARGET_LINK_LIBRARIES(DebuggerTests zorba)

SET (TestsToRun ${DebuggerTests})
REMOVE (TestsToRun DebuggerTests.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${DebuggerTests})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
	ADD_TEST(${TName} DebuggerTests ${TName})
ENDFOREACH(test)
