include ../Makefile.header
SUFX=do
BUILD=Build

sequence_type : sequence_type.h sequence_type.cpp
	g++ $(OPT) -c -o $(BUILD)/sequence_type.$(SUFX) sequence_type.cpp

node_types :	node_types.h node_types.cpp
	g++ $(OPT) -c -o $(BUILD)/node_types.$(SUFX) node_types.cpp

base_types :	base_types.h base_types.cpp
	g++ $(OPT) -c -o $(BUILD)/base_types.$(SUFX) base_types.cpp

xs_primitive_types :	xs_primitive_types.h xs_primitive_types.cpp
	g++ $(OPT) -c -o $(BUILD)/xs_primitive_types.$(SUFX) xs_primitive_types.cpp

character :	character.h character.cpp
	g++ $(OPT) -c -o $(BUILD)/character.$(SUFX) character.cpp

all :	\
  sequence_type \
	node_types \
	base_types \
	xs_primitive_types \
	character

clean:
	$(CleanRule) *.do *.po *.o *_test $(Executables) $(TestExecutables)

