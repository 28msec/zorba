# create the testing file and list of tests
CREATE_TEST_SOURCELIST(ExternalFunctionTests
  ExternalFunctionTests.cpp
  simple_function_test.cpp
)
 
# add the executable
ADD_EXECUTABLE(ExternalFunctionTests ${ExternalFunctionTests})
TARGET_LINK_LIBRARIES(ExternalFunctionTests zorba)

# remove the test driver source file
SET (TestsToRun ${ExternalFunctionTests})
REMOVE (TestsToRun ExternalFunctionTests.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
	ADD_TEST(${TName} ExternalFunctionTests ${TName})
ENDFOREACH(test)
