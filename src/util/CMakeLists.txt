SET(UTIL_SRCS
    URI.cpp 
    utf8/xqpString.cpp
    fx/fxcharheap.cpp
    fx/mmfile.cpp
    logging/logger.cc
    logging/loggerconfig.cc
    logging/loggermanager.cc
    file.cpp
    tokenbuf.cpp
    zorba.cpp
    file_test.cpp
    rwlock.cpp)
    
ADD_LIBRARY(util ${UTIL_SRCS})