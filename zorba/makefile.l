include ../Makefile.header
SUFX=do
BUILD=Build

valuereps : valuereps.h valuereps.cpp
	g++ -c ${OPT} -o Build/valuereps.${SUFX} valuereps.cpp

qnamerep : qnamerep.h qnamerep.cpp
	g++ -c ${OPT} -o Build/qnamerep.${SUFX} qnamerep.cpp

stringrep : stringrep.h stringrep.cpp
	g++ -c ${OPT} -o Build/stringrep.${SUFX} stringrep.cpp

primitive_valuereps : primitive_valuereps.h primitive_valuereps.cpp
	g++ -c ${OPT} -o Build/primitive_valuereps.${SUFX} primitive_valuereps.cpp

nodereps : nodereps.h nodereps.cpp
	g++ -c ${OPT} -o Build/nodereps.${SUFX} nodereps.cpp

noderep_iterator : nodereps.h noderep_iterator.h noderep_iterator.cpp
	g++ -c ${OPT} -o Build/noderep_iterator.${SUFX} noderep_iterator.cpp

zorba_ft_values : zorba_ft_values.h zorba_ft_values.cpp
	g++ -c ${OPT} -o Build/zorba_ft_values.${SUFX} zorba_ft_values.cpp

zorba_update_values : zorba_update_values.h zorba_update_values.cpp
	g++ -c ${OPT} -o Build/zorba_update_values.${SUFX} zorba_update_values.cpp

zorba_values : zorba_values.h zorba_values.cpp
	g++ -c ${OPT} -o Build/zorba_values.${SUFX} zorba_values.cpp

zorba_qname : zorba_qname.h zorba_qname.cpp
	g++ -c ${OPT} -o Build/zorba_qname.${SUFX} zorba_qname.cpp

zorba_primitive_values : zorba_primitive_values.h zorba_primitive_values.cpp
	g++ -c ${OPT} -o Build/zorba_primitive_values.${SUFX} zorba_primitive_values.cpp

zorba_iterator : zorba_iterator.h zorba_iterator.cpp
	g++ -c ${OPT} -o Build/zorba_iterator.${SUFX} zorba_iterator.cpp

all : \
	valuereps \
	qnamerep \
	nodereps

#zorba_nodes 
#zorba_qname 

