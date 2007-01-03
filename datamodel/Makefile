OPT=-g
SUFX=do
BUILD=build

qname : qname.h qname.cpp
	g++ -c ${OPT} -o ${BUILD}/qname.${SUFX} qname.cpp
qname_test : qname.h qname.cpp qname_test.cpp
	g++ ${OPT} -o ${BUILD}/qname_test \
		../util/xqpexception.o \
		qname.${SUFX} \
		qname_test.cpp

xsd :	xsd.h xsd.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/xsd.${SUFX} xsd.cpp
	
sequence_type : sequence_type.h sequence_type.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/sequence_type.${SUFX} sequence_type.cpp

xdm :	xdm.h xdm.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/xdm.${SUFX} xdm.cpp


	
xdm_test :	xdm.h xdm.cpp xdm_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o ${BUILD}/xdm_test \
    ../types/qname.${SUFX} \
    ../util/tokenbuf.${SUFX} \
    xdm.${SUFX} \
    xdm_test.cpp

    
all :	\
  qname \
  xsd \
  sequence_type \
  xdm
			  

clean:
	$(CleanRule) *.do *.po *.o *_test ${Executables} ${TestExecutables}

