SET(UTIL_SRCS
    URI.cpp
    fx/mmfile.cpp
    fx/fxcharheap.cpp
    logging/logger.cc
    logging/loggerconfig.cc
    logging/loggermanager.cc
    file.cpp
    tokenbuf.cpp
    zorba.cpp
    rwlock.cpp
    math_helper.cpp)

ADD_SRC_SUBFOLDER(UTIL_SRCS utf8 UTF8_SRCS)

IF (MSVC)
	LIST(APPEND UTIL_SRCS win32/win_pthread.cpp)
ENDIF (MSVC)
    

HEADER_GROUP_SUBFOLDER(UTIL_SRCS fx)
HEADER_GROUP_SUBFOLDER(UTIL_SRCS logging)
HEADER_GROUP_SUBFOLDER(UTIL_SRCS utf8)
HEADER_GROUP_SUBFOLDER(UTIL_SRCS win32)