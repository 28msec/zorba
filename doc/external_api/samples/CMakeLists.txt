# create the testing file and list of tests
CREATE_TEST_SOURCELIST(APISamples
	APISamples.cpp
	uc1a_simpleQueryOneStep.cpp
	uc1b_simpleQueryThreeSteps.cpp
	uc1c_simpleQueryPlanPrint.cpp
	uc1d_simpleQueryResultIterator.cpp
	uc1f_simpleQueryResultSAX.cpp
	uc2_simpleQueryWithErrorCheck.cpp
	uc3a_externalVar.cpp
	uc3b_contextItem.cpp
#	uc3c_contextItem.cpp
	uc3d_currentTime.cpp
	uc4_chainXQuery.cpp
	uc5a_errorManager.cpp
	uc5b_errorCallback.cpp
	uc5c_errorList.cpp
#	uc6a_staticContext.cpp
#	uc6b_defaultCollation.cpp
#	uc6c_baseUri.cpp
#	uc7_multithread.cpp
#	uc8a_loadDocument.cpp
)
 
# add the executable
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
