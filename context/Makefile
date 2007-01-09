OPT=-g
SUFX=do
BUILD=Build

context :	context.h context.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/context.${SUFX} context.cpp
    
all :	\
 context 

clean:
	$(CleanRule) *.do *.po *.o *_test ${Executables} ${TestExecutables}

