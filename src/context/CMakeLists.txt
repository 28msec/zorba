SET(CONTEXT_SRCS
    dynamic_context.cpp
    static_context.cpp)
    

ADD_LIBRARY(context SHARED ${CONTEXT_SRCS})
