SET(UTIL_SRCS
    URI.cpp
    fx/mmfile.cpp
    fx/fxcharheap.cpp
    logging/logger.cc
    logging/loggerconfig.cc
    logging/loggermanager.cc
    file.cpp
    tokenbuf.cpp
    rwlock.cpp
    properties.cpp
    XmlWhitespace.cpp)

ADD_SRC_SUBFOLDER(UTIL_SRCS web WEB_SRCS)
    

HEADER_GROUP_SUBFOLDER(UTIL_SRCS fx)
HEADER_GROUP_SUBFOLDER(UTIL_SRCS logging)
HEADER_GROUP_SUBFOLDER(UTIL_SRCS utf8)
HEADER_GROUP_SUBFOLDER(UTIL_SRCS win32)
