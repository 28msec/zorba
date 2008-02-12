# temporary include; the tests should probably go in the according src dir
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_SOURCE_DIR}/src)

ADD_SUBDIRECTORY(rbkt)
ADD_SUBDIRECTORY(unit)
ADD_SUBDIRECTORY(samples)

SET(API_TEST_SRCS
    timer.cpp
    apitest.cpp)

ADD_EXECUTABLE(apitest ${API_TEST_SRCS})
TARGET_LINK_LIBRARIES(apitest zorba)


SET(TEST_STORE_SRCS
    timer.cpp 
    test_store.cpp)

ADD_EXECUTABLE(test_store ${TEST_STORE_SRCS})
TARGET_LINK_LIBRARIES(test_store zorba)
