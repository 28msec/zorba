include ../Makefile.header
SUFX=do
BUILD=Build

function_impl :	function_impl.h function_impl.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/function_impl.${SUFX} function_impl.cpp

signature :	signature.h signature.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/signature.${SUFX} signature.cpp

function_impl_test :	function_impl.h function_impl.cpp function_impl_test.cpp
	g++ ${LARGEFILEFLAGS} -Wall ${OPT} -o ${BUILD}/function_impl_test \
		../context/${BUILD}/context.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/signature.${SUFX} \
		${BUILD}/function_impl.${SUFX} \
	function_impl_test.cpp

all :	\
	signature \
  function_impl 

test : \
	function_impl_test

