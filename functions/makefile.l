include ../Makefile.header
SUFX=do
BUILD=Build

signature :	signature.h signature.cpp
	g++ ${OPT} -c -o ${BUILD}/signature.${SUFX} signature.cpp

function :	function.h function.cpp
	g++ ${OPT} -c -o ${BUILD}/function.${SUFX} function.cpp

library :	library.h library.cpp
	g++ ${OPT} -c -o ${BUILD}/library.${SUFX} library.cpp

Sequences :	Sequences.h Sequences.cpp
	g++ ${OPT} -c -o ${BUILD}/Sequences.${SUFX} Sequences.cpp

SequencesImpl :	SequencesImpl.h SequencesImpl.cpp
	g++ ${OPT} -c -o ${BUILD}/SequencesImpl.${SUFX} SequencesImpl.cpp

Numerics : Numerics.h Numerics.cpp
	g++ ${OPT} -c -o ${BUILD}/Numerics.${SUFX} Numerics.cpp

function_test :	function.h function.cpp
	g++ ${OPT} -o ${BUILD}/function_test \
		../types/Build/sequence_type.${SUFX} \
		../store/Build/itemstore.${SUFX} \
		../util/Build/file.${SUFX} \
		../util/Build/mmfile.${SUFX} \
		../util/Build/fxcharheap.${SUFX} \
		../util/Build/xqp_exception.${SUFX} \
		../values/Build/qname_value.${SUFX} \
		../values/Build/xs_primitive_values.${SUFX} \
		Build/signature.${SUFX} \
		function.cpp

library_test :	function.h ibrary_test.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/library_test \
		library_test.cpp

Sequences_test : Sequences.h Sequences.cpp Sequences_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/Sequences_test \
		../dom/${BUILD}/dom_qname.${SUFX} \
		../dom/${BUILD}/dom_namepool.${SUFX} \
		../dom/${BUILD}/dom_nodes.${SUFX} \
		../dom/${BUILD}/dom_xml_handler.${SUFX} \
		../runtime/${BUILD}/errors.${SUFX} \
		../runtime/${BUILD}/item_iterator.${SUFX} \
		../runtime/${BUILD}/zorba.${SUFX} \
		../store/${BUILD}/itemstore.${SUFX} \
		../store/${BUILD}/scan_handler.${SUFX} \
		../store/${BUILD}/xml_scanner.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/primitive_values.${SUFX} \
		../zorba/${BUILD}/qnamerep.${SUFX} \
		../zorba/${BUILD}/valuereps.${SUFX} \
		../zorba/${BUILD}/zorba_qname.${SUFX} \
		../zorba/${BUILD}/zorba_value_factory.${SUFX} \
		${BUILD}/library.${SUFX} \
		${BUILD}/signature.${SUFX} \
		${BUILD}/Numerics.${SUFX} \
		${BUILD}/Sequences.${SUFX} \
		${BUILD}/SequencesImpl.${SUFX} \
	Sequences_test.cpp

Numerics_test : Numerics.h Numerics.cpp Numerics_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/Numerics_test \
		../dom/${BUILD}/dom_qname.${SUFX} \
		../dom/${BUILD}/dom_namepool.${SUFX} \
		../dom/${BUILD}/dom_nodes.${SUFX} \
		../dom/${BUILD}/dom_xml_handler.${SUFX} \
		../runtime/${BUILD}/errors.${SUFX} \
		../runtime/${BUILD}/item_iterator.${SUFX} \
		../runtime/${BUILD}/zorba.${SUFX} \
		../store/${BUILD}/itemstore.${SUFX} \
		../store/${BUILD}/scan_handler.${SUFX} \
		../store/${BUILD}/xml_scanner.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/primitive_values.${SUFX} \
		../zorba/${BUILD}/qnamerep.${SUFX} \
		../zorba/${BUILD}/valuereps.${SUFX} \
		../zorba/${BUILD}/zorba_qname.${SUFX} \
		../zorba/${BUILD}/zorba_value_factory.${SUFX} \
		${BUILD}/signature.${SUFX} \
		${BUILD}/library.${SUFX} \
		${BUILD}/Sequences.${SUFX} \
		${BUILD}/SequencesImpl.${SUFX} \
		${BUILD}/Numerics.${SUFX} \
	Numerics_test.cpp


all :	\
	signature \
	function \
	library \
	Sequences \
	SequencesImpl \
	Numerics \
	Numerics_test \
	Sequences_test


test : \
	function_test \
	library_test \
	Sequences_test \
	Numerics_test 

