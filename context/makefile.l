include ../Makefile.header
SUFX=do
BUILD=Build

static_context :	context.h static_context.h static_context.cpp 
	g++ ${OPT} -c -o ${BUILD}/static_context.${SUFX} static_context.cpp
    
dynamic_context :	context.h dynamic_context.h dynamic_context.cpp
	g++ ${OPT} -c -o ${BUILD}/dynamic_context.${SUFX} dynamic_context.cpp
    
context_test :	context.h context.cpp context_test.cpp
	g++ ${OPT} -o ${BUILD}/context_test \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/context.${SUFX} \
		context_test.cpp
    
all :	\
 static_context \
 dynamic_context 

test : \
	context_test

