OPT=-g
SUFX=do
BUILD=Build

qname : qname.h qname.cpp
	g++ -c ${OPT} -o ${BUILD}/qname.${SUFX} qname.cpp
qname_test : qname.h qname.cpp qname_test.cpp
	g++ ${OPT} -o ${BUILD}/qname_test \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/qname.${SUFX} \
		qname_test.cpp

sequence_type : sequence_type.h sequence_type.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/sequence_type.${SUFX} sequence_type.cpp

node_types :	node_types.h node_types.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/node_types.${SUFX} node_types.cpp

types :	types.h types.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/types.${SUFX} types.cpp

all :	\
  qname \
  xsd \
  sequence_type \
  xdm

clean:
	$(CleanRule) *.do *.po *.o *_test ${Executables} ${TestExecutables}

