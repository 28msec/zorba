SET(API_TEST_SRCS timer.cpp 
    apitest.cpp)

ADD_EXECUTABLE(apitest ${API_TEST_SRCS})

TARGET_LINK_LIBRARIES(apitest zorba)


IF (NOT MSVC)
	TARGET_LINK_LIBRARIES(apitest pthread) 
ENDIF (NOT MSVC)
