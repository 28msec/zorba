SET(ERRORS_SRCS
   Error.cpp 
   errors.cpp 
   xqp_exception.cpp)

ADD_LIBRARY(errors SHARED ${ERRORS_SRCS})
