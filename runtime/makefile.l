include ../Makefile.header
SUFX=do
BUILD=Build

iterator : iterator.h iterator.cpp
	g++ ${OPT} -c -o ${BUILD}/iterator.${SUFX} iterator.cpp

iterator_test : iterator.h iterator.cpp iterator_test.cpp
	g++ -Wall -g -o ${BUILD}/iterator_test \
		../context/${BUILD}/context.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/iterator.${SUFX} \
		iterator_test.cpp

all : iterator

test : iterator_test

