OPT=-g
SUFX=do

xdm :	xdm.h xdm.cpp
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -c -o xdm.${SUFX} xdm.cpp

    
xdm_test :	xdm.h xdm.cpp xdm_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o xdm_test \
    ../types/qname.${SUFX} \
    ../util/tokenbuf.${SUFX} \
    xdm.${SUFX} \
    xdm_test.cpp

all :	\
	xdm_test			  

clean:
	$(CleanRule) *.do *.po *.ro *_test ${Executables} ${TestExecutables}

