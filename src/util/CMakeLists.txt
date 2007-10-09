# ADD_SUBDIRECTORY(fx)
# ADD_SUBDIRECTORY(utf8)

SET(UTIL_SRCS
    URI.cpp 
    utf8/xqpString.cpp
    fx/fxcharheap.cpp
    fx/mmfile.cpp
    file.cpp
    tokenbuf.cpp
    zorba.cpp
    file_test.cpp
    rwlock.cpp)
    
ADD_LIBRARY(util ${UTIL_SRCS})
# TARGET_LINK_LIBRARIES(util fx)
# TARGET_LINK_LIBRARIES(util utf8)