SET(LOGGING_SRCS
    logger.cc
    loggerconfig.cc
    loggermanager.cc)
    



ADD_LIBRARY(logging SHARED ${LOGGING_SRCS})