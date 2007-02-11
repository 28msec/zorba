include ../Makefile.header
SUFX=do
BUILD=Build

normalize_visitor : normalize_visitor.h normalize_visitor.cpp
	g++ ${OPT} -c -o ${BUILD}/normalize_visitor.${SUFX} normalize_visitor.cpp

iterator : iterator.h iterator.cpp
	g++ ${OPT} -c -o ${BUILD}/iterator.${SUFX} iterator.cpp

iterator_test : iterator.h iterator.cpp iterator_test.cpp
	g++ -Wall -g -o ${BUILD}/iterator_test \
		../context/${BUILD}/context.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/iterator.${SUFX} \
		iterator_test.cpp

all : iterator

test : iterator_test

