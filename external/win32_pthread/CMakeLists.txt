SET(PTHREAD_SRCS
  pthread.cpp)

ADD_LIBRARY(pthread ${PTHREAD_SRCS})
SET(requiredlibs ${requiredlibs} pthread)
