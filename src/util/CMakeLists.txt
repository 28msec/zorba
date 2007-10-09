ADD_SUBDIRECTORY(fx)
ADD_SUBDIRECTORY(utf8)

SET(UTIL_SRCS
    URI.cpp
    file.cpp
    rwlock.cpp
    tokenbuf.cpp
    zorba.cpp)
    
ADD_LIBRARY(util ${UTIL_SRCS})
TARGET_LINK_LIBRARIES(util fx)
TARGET_LINK_LIBRARIES(util utf8)