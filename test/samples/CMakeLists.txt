# create the testing file and list of tests
CREATE_TEST_SOURCELIST(APISamples
	APISamples.cpp
	usecase1.cpp
	usecase2.cpp
	usecase3.cpp
	usecase4.cpp
	usecase5.cpp
	usecase6.cpp
	usecase7.cpp
)
 
# add the executable
COMPILER_SETUP(APPLICATION_INCLUDES)
ADD_EXECUTABLE(APISamples ${APISamples})
TARGET_LINK_LIBRARIES(APISamples zorba)

# remove the test driver source file
SET (TestsToRun ${APISamples})
REMOVE (TestsToRun APISamples.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
	ADD_TEST(${TName} APISamples ${TName})
ENDFOREACH(test)
