ADD_SUBDIRECTORY(Scripts)

# create the result directory for all tests
IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)


# collect all queries (suffix .xq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ *.xq)

#MESSAGE(STATUS "testfiles " ${TESTFILES})

# add a test for this query
FOREACH(TESTFILE ${TESTFILES})

  GET_FILENAME_COMPONENT(BUCKETNAME ${TESTFILE} PATH)
  
  # MESSAGE(STATUS "bucketname " ${BUCKETNAME})
  # MESSAGE(STATUS "testname " ${TESTNAME})
  
  # create result directory if it doesn't exist
  IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${BUCKETNAME})
      FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${BUCKETNAME})
  ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${BUCKETNAME})

  STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
  MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-3' )
  STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

  SET(TESTFILE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/${TESTFILE})
  SET(TESTRESULT ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${TESTNAME})

  # now, add two texts, one for xml output and one for text output
  # the tests are called queryfilename_xml or queryfilename_text, respectively.
  # the result is stored in queryfilename_xml.res or queryfilename_text.res, respectively
  ADD_TEST(${TESTNAME}_xml ${CMAKE_BINARY_DIR}/test/apitest -r -o ${TESTRESULT}.xml.res ${TESTFILE})
  ADD_TEST(${TESTNAME}_text ${CMAKE_BINARY_DIR}/test/apitest -o ${TESTRESULT}.show.res ${TESTFILE})
#  ADD_TEST(${TESTNAME}_xml_diff diff ${TESTRESULT}_xml.res 
#                                     ${CMAKE_CURRENT_SOURCE_DIR}/ExpQueryResults/${BUCKETDIR}_xml/${TESTNAME}.res)
#  ADD_TEST(${TESTNAME}_text_diff diff ${TESTRESULT}_text.res 
#                                     ${CMAKE_CURRENT_SOURCE_DIR}/ExpQueryResults/${BUCKETDIR}_text/${TESTNAME}.res)

ENDFOREACH(TESTFILE)