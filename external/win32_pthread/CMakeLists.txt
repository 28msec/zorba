SET(PTHREAD_SRCS
  pthread.cpp)

TARGET_LINK_LIBRARIES(pthread ${PTHREAD_SRCS})
SET(requiredlibs ${requiredlibs} pthread)
