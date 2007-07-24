include ../Makefile.header
SUFX=do
BUILD=Build

trace_handler : trace_handler.h trace_handler.cpp
	g++ ${OPT} -c -o ${BUILD}/trace_handler.${SUFX} trace_handler.cpp

all : \
	error_handler \
	trace_handler

