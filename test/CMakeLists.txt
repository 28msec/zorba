SET(QUERY_EXEC_SRCS timer.cpp 
    query_exec.cpp)

ADD_EXECUTABLE(query_exec ${QUERY_EXEC_SRCS})

TARGET_LINK_LIBRARIES(query_exec zorba pthread)