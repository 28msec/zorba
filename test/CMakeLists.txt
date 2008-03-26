# temporary include; the tests should probably go in the according src dir
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_BINARY_DIR}/src)

ADD_SUBDIRECTORY(rbkt)
ADD_SUBDIRECTORY(unit)
ADD_SUBDIRECTORY(parser)

SET(API_TEST_SRCS
    apitest.cpp)

ADD_EXECUTABLE(apitest ${API_TEST_SRCS})
TARGET_LINK_LIBRARIES(apitest zorba)

IF (ZORBA_BUILD_STATIC_LIBRARY)
  ADD_EXECUTABLE(apitest_static ${API_TEST_SRCS})
  TARGET_LINK_LIBRARIES(apitest_static zorba_static)
ENDIF (ZORBA_BUILD_STATIC_LIBRARY)


SET(TEST_STORE_SRCS
    timer.cpp
    test_store.cpp)

ADD_EXECUTABLE(test_store ${TEST_STORE_SRCS})
TARGET_LINK_LIBRARIES(test_store zorba)


SET(TEST_ORDPATH_SRCS
    test_ordpath.cpp)

ADD_EXECUTABLE(test_ordpath ${TEST_ORDPATH_SRCS})
TARGET_LINK_LIBRARIES(test_ordpath zorba)
