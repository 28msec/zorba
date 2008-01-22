# create the testing file and list of tests
CREATE_TEST_SOURCELIST(UnitTests
	UnitTests.cpp
	usecase1.cpp
	usecase2.cpp
	usecase3.cpp
	usecase4.cpp
	usecase5.cpp
	usecase6.cpp
	usecase7.cpp
)
 
# add the executable
ADD_EXECUTABLE(UnitTests ${UnitTests})
TARGET_LINK_LIBRARIES(UnitTests zorba)
# remove the test driver source file
SET (TestsToRun ${UnitTests})
REMOVE (TestsToRun UnitTests.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
	ADD_TEST(${TName} UnitTests ${TName})
ENDFOREACH(test)
