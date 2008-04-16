# create the testing file and list of tests
CREATE_TEST_SOURCELIST(examples
	examples.cpp
	simple.cpp
  simple_sax.cpp
  errors.cpp
  context.cpp
  serialization.cpp
  chaining.cpp
  external_functions.cpp
  datamanager.cpp
)
 
# add the executable
ADD_EXECUTABLE(examples ${examples})
TARGET_LINK_LIBRARIES(examples zorba)

# remove the test driver source file
SET (TestsToRun ${examples})
REMOVE (TestsToRun examples.cpp)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
	ADD_TEST(${TName} examples ${TName})
ENDFOREACH(test)
