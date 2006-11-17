OPT=-g

xqpexception : xqpexception.h xqpexception.cpp
	g++ ${OPT} -c -o xqpexception.o xqpexception.cpp

charheap : charheap.h charheap.cpp
	g++ ${OPT} -c -o charheap.o charheap.cpp
charheap_test : charheap.h charheap.cpp charheap_test.cpp
	g++ ${OPT} -o charheap_test \
		Exception.o \
		charheap.cpp

tokenbuf : tokenbuf.h tokenbuf.cpp
	g++ ${OPT} -c -o tokenbuf.o tokenbuf.cpp
tokenbuf_test : tokenbuf.h tokenbuf.cpp tokenbuf_test.cpp
	g++ ${OPT} -c -o tokenbuf_test \
		tokenbuf.o
		tokenbuf_test.cpp
