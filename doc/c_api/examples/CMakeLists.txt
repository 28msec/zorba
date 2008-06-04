
INCLUDE_DIRECTORIES(AFTER ${CMAKE_SOURCE_DIR}/src/)


SET (CAPI_EXAMPLES
	csimple.c
  ccontext.c
  cdatamanager.c
)

CREATE_TEST_SOURCELIST(cexamples
	cexamples.c
  ${CAPI_EXAMPLES}
)
 
# add the executable
ADD_EXECUTABLE(cexamples ${cexamples})
TARGET_LINK_LIBRARIES(cexamples zorba simplestore)

# remove the test driver source file
SET (TestsToRun ${cexamples})
REMOVE (TestsToRun cexamples.c)

# add all the ADD_TEST for each testing
FOREACH (test ${TestsToRun})
	GET_FILENAME_COMPONENT(TName ${test} NAME_WE)
	MESSAGE(STATUS ${TName})
	ADD_TEST(${TName} cexamples ${TName})
ENDFOREACH(test)
