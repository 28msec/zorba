include ../Makefile.header
SUFX=do

noderep : noderep.h noderep.cpp
	g++ -c ${CXXOPT} -o Build/noderep.${SUFX} noderep.cpp

all : \
	noderep 

test : \

