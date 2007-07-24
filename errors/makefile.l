include ../Makefile.header
SUFX=do
BUILD=Build

all :	\
 Build/Error.${SUFX} \
 Build/errors.${SUFX} \
 Build/xqp_exception.${SUFX}


Build/Error.${SUFX} :	Error.h Errors.h Error.cpp ../util/rchandle.h ../runtime/zorba.h
	g++ ${OPT} -c -o ${BUILD}/Error.${SUFX} Error.cpp
    
Build/errors.${SUFX} :	errors.h xqp_exception.h errors.cpp
	g++ ${OPT} -c -o ${BUILD}/errors.${SUFX} errors.cpp
    
Build/xqp_exception.${SUFX} : xqp_exception.h xqp_exception.cpp
	g++ ${CXXOPT} -c -o ${BUILD}/xqp_exception.${SUFX} xqp_exception.cpp

    


