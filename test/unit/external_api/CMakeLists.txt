# create the testing file and list of tests
# CREATE_TEST_SOURCELIST(ExternalTests
#   ExternalTests.cpp
#  dctx_test.cpp
#  easy_test.cpp
#  easy_api_test.cpp
#  query_multithread_test.cpp
#  sctx_test.cpp
#  zorba_engine_test.cpp
#)
 
# add the executable
#ADD_EXECUTABLE(ExternalTests ${ExternalTests})
#TARGET_LINK_LIBRARIES(ExternalTests zorba)
# remove the test driver source file
# SET (TestsToRun ${ExternalTests})
# REMOVE (TestsToRun ExternalTests.cpp)
# 
# # add all the ADD_TEST for each testing
# FOREACH (test ${TestsToRun})
# 	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
# 	MESSAGE(STATUS ${TName})
# 	ADD_TEST(${TName} ExternalTests ${TName})
# ENDFOREACH(test)
