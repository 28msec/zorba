include ../Makefile.header
SUFX=do
BUILD=Build

sequence_type : sequence_type.h sequence_type.cpp
	g++ $(OPT) -c -o $(BUILD)/sequence_type.$(SUFX) sequence_type.cpp

all :	\
  sequence_type

