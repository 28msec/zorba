# configure and compile the testdriver
CONFIGURE_FILE(parsertestdriverconfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/parsertestdriverconfig.h)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ADD_EXECUTABLE(parsertestdriver parsertestdriver.cpp)
TARGET_LINK_LIBRARIES(parsertestdriver ${requiredlibs} zorba)

# collect all queries (suffix .xq) in all subdirectories of the Queries dir
FILE(GLOB_RECURSE TESTFILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Queries/ *.xq)

MESSAGE(STATUS "Adding parser tests for CTest")

FOREACH(TESTFILE ${TESTFILES})
 STRING(LENGTH ${TESTFILE} TESTFILELENGTH)
 MATH(EXPR TESTLENGTH '${TESTFILELENGTH}-3' )
 STRING(SUBSTRING ${TESTFILE} 0 ${TESTLENGTH} TESTNAME)

 ADD_TEST(${TESTNAME} parsertestdriver ${TESTFILE})

 IF (${TESTFILE} MATCHES "fail")
  SET_TESTS_PROPERTIES (${TESTNAME} PROPERTIES
    TIMEOUT "10"
    WILL_FAIL TRUE
  )
 ELSE (${TESTFILE} MATCHES "fail")
  SET_TESTS_PROPERTIES (${TESTNAME} PROPERTIES
    TIMEOUT "10"
    FAIL_REGULAR_EXPRESSION "no parsenode root generated"
  )
 ENDIF (${TESTFILE} MATCHES "fail")

ENDFOREACH(TESTFILE)
