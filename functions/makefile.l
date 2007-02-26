include ../Makefile.header
SUFX=do
BUILD=Build

Sequences :	Sequences.h Sequences.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/Sequences.${SUFX} Sequences.cpp

Sequences_test : Sequences.h Sequences.cpp Sequences_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/Sequences_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../types/${BUILD}/node_types.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		../native_impl/${BUILD}/scan_handler.${SUFX} \
		../native_impl/${BUILD}/xml_scanner.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../native_impl/${BUILD}/namespace_pool.${SUFX} \
		../native_impl/${BUILD}/qname_pool.${SUFX} \
		../native_impl/${BUILD}/xml_handler.${SUFX} \
		${BUILD}/Sequences.${SUFX} \
	Sequences_test.cpp

signature :	signature.h signature.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/signature.${SUFX} signature.cpp

function_test :	function.h function_test.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/function_test \
		function_test.cpp

library_test :	function.h ibrary_test.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/library_test \
		library_test.cpp

all :	\
	signature \

test : \
	function_test \
	library_test

