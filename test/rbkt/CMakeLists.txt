ADD_SUBDIRECTORY(Scripts)

# create the result directory for all tests
IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)
ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/)


# collect all queries (suffix .xq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ *.xq)

#MESSAGE(STATUS "testfiles " ${TESTFILES})

MESSAGE(STATUS "Adding tests for CTest")
SET(TESTCOUNTER 0)

# add a test for this query
FOREACH(TESTFILE ${TESTFILES})

  MATH(EXPR TESTCOUNTER ${TESTCOUNTER}+1)
  MATH(EXPR TESTMOD "${TESTCOUNTER}/1000")
  IF (${TESTMOD})
    MESSAGE(STATUS "Adding another 1000 Tests")
    SET(TESTCOUNTER 0)
  ENDIF (${TESTMOD})


  GET_FILENAME_COMPONENT(BUCKETNAME ${TESTFILE} PATH)

  # this is executed to often
  FILE(GLOB XMLFILES ${CMAKE_CURRENT_SOURCE_DIR}/Queries/${BUCKETNAME}/*.xml)
  FOREACH(XMLFILE ${XMLFILES})
    CONFIGURE_FILE(${XMLFILE} ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
  ENDFOREACH(XMLFILE)  

  # MESSAGE(STATUS "bucketname " ${BUCKETNAME})
  # MESSAGE(STATUS "testname " ${TESTNAME})
  
  # create result directory if it doesn't exist
  IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${BUCKETNAME})
      FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${BUCKETNAME})
  ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${BUCKETNAME})

  IF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/ExpQueryResults/${BUCKETNAME})
      FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ExpQueryResults/${BUCKETNAME})
  ENDIF (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/ExpQueryResults/${BUCKETNAME})


  STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
  MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-3' )
  STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

  # now, add two texts, one for xml output and one for text output
  # the tests are called queryfilename_xml or queryfilename_text, respectively.
  # the result is stored in queryfilename_xml.res or queryfilename_text.res, respectively
  ADD_TEST(${TESTNAME}_xml 
                ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/ctestruntest 
                ${CMAKE_BINARY_DIR}
                ${CMAKE_CURRENT_BINARY_DIR}/QueryResults/${TESTNAME}.xml.res 
                ${CMAKE_CURRENT_SOURCE_DIR}/Queries/${TESTFILE} 
                ${CMAKE_CURRENT_SOURCE_DIR}
                ExpQueryResults/${TESTNAME}.xml.res)
                
#  ADD_TEST(${TESTNAME}_xml_diff diff ${TESTRESULT}_xml.res 
#                                     ${CMAKE_CURRENT_SOURCE_DIR}/ExpQueryResults/${BUCKETDIR}_xml/${TESTNAME}.res)
#  ADD_TEST(${TESTNAME}_text_diff diff ${TESTRESULT}_text.res 
#                                     ${CMAKE_CURRENT_SOURCE_DIR}/ExpQueryResults/${BUCKETDIR}_text/${TESTNAME}.res)

ENDFOREACH(TESTFILE)