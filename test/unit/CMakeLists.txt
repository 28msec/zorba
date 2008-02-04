# create the testing file and list of tests
CREATE_TEST_SOURCELIST(UnitTests
  UnitTests.cpp
  typesystem_isSubtype.cpp
  typesystem_atomicStringCast.cpp
)

ADD_SUBDIRECTORY(external_api)

# add the executable
COMPILER_SETUP(ZORBA_INCLUDES)
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