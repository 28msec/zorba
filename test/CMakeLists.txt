ADD_SUBDIRECTORY(rbkt)
ADD_SUBDIRECTORY(unit)

SET(API_TEST_SRCS
    timer.cpp
    error_display.cpp 
    apitest.cpp)

ADD_EXECUTABLE(apitest ${API_TEST_SRCS})

TARGET_LINK_LIBRARIES(apitest zorba)


SET(TEST_STORE_SRCS
    timer.cpp 
    error_display.cpp
    test_store.cpp)

ADD_EXECUTABLE(test_store ${TEST_STORE_SRCS})

TARGET_LINK_LIBRARIES(test_store zorba)
