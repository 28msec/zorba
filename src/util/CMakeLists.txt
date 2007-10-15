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
    rwlock.cpp)

IF (MSVC)
	LIST(APPEND UTIL_SRCS win32/win_pthread.cpp)
ENDIF (MSVC)
    

