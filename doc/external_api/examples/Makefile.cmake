LDLIBS = -lzorba -licuuc -licudata -licui18n 
CPPFLAGS = -I@CMAKE_INSTALL_PREFIX@/include/zorba
LDFLAGS = -L@CMAKE_INSTALL_PREFIX@/lib

all: examples

examples: examples.cpp simple.cpp sax2.cpp errors.cpp context.cpp serialization.cpp chaining.cpp external_functions.cpp datamanager.cpp
