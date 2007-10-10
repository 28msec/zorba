SET(API_SRCS
    serialization/serializer.cpp)
    

ADD_LIBRARY(api SHARED ${API_SRCS})

