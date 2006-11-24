OPT=-g

xqpexception : xqpexception.h xqpexception.cpp
	g++ ${OPT} -c -o xqpexception.o xqpexception.cpp


charheap : charheap.h charheap.cpp
	g++ ${OPT} -c -O2 -o charheap.o charheap.cpp
	g++ ${OPT} -c -g -o charheap.do charheap.cpp
charheap_test : charheap.h charheap.cpp charheap_test.cpp
	g++ ${OPT} -o charheap_test \
		xqpexception.o \
		tokenbuf.do \
		charheap.do \
		charheap_test.cpp


tokenbuf : tokenbuf.h tokenbuf.cpp
	g++ ${OPT} -c -g -o tokenbuf.do tokenbuf.cpp
	g++ ${OPT} -c -O2 -o tokenbuf.o tokenbuf.cpp
tokenbuf_test : tokenbuf.h tokenbuf.cpp tokenbuf_test.cpp
	g++ ${OPT} -o tokenbuf_test tokenbuf.o tokenbuf_test.cpp


hashfun_test :	hashfun_test.cpp hashfun.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o hashfun_test \
		Exception.o \
		hashfun_test.cpp


hashmap :	hashmap.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o hashmap.do hashmap.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o hashmap.o hashmap.cpp
hashmap_test :	hashmap_test.cpp hashmap.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -lpthread -o hashmap_test \
		Exception.o \
		rwlock.do \
		tokenizer.do \
		hashmap_test.cpp


list :	list.cpp list.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o list.do list.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o list.o list.cpp
list_test :	list.cpp list.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o list_test \
		Exception.o \
		tokenizer.do \
		list.cpp


logger : logger.h logger.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o logger.do logger.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o logger.o logger.cpp
logger_test : logger.h logger.cpp logger_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o logger_test \
		Exception.o \
		logger.do \
		logger_test.cpp


persistent_charheap :	persistent_charheap.cpp persistent_charheap.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o persistent_charheap.do persistent_charheap.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o persistent_charheap.o persistent_charheap.cpp
persistent_charheap_test : 	persistent_charheap_test.cpp persistent_charheap.cpp persistent_charheap.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o persistent_charheap_test \
		xqpexception.o \
		tokenbuf.do \
		persistent_charheap.do \
		persistent_charheap_test.cpp


rchandle_test :	rchandle.h rchandle_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall -g -o rchandle_test \
		rchandle_test.cpp


rwlock :	rwlock.cpp rwlock.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o rwlock.do rwlock.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o rwlock.o rwlock.cpp
rwlock_test :	rwlock.cpp rwlock.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -lpthread -o rwlock_test \
		rwlock.do \
		rwlock_test.cpp; \


URI : URI.h URI.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o URI.do URI.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o URI.o URI.cpp
URI_test : URI.h URI.cpp URI_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o URI_test \
		URI.do \
		URI_test.cpp


utf8_encoder :	utf8_encoder.cpp	utf8_encoder.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o utf8_encoder.do utf8_encoder.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o utf8_encoder.o utf8_encoder.cpp
utf8_encoder_test :	utf8_encoder_test.cpp utf8_encoder.cpp	utf8_encoder.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o utf8_encoder_test \
		utf8_encoder.do \
		utf8_encoder_test.cpp


all	:	charheap \
	peristent_charheap \
	hashmap_test \
 	logger \
	sorterTest \
	tokenbuf \
	utf8_encoder 


clean:
	$(CleanRule) *.do *.po *.ro *_test ${Executables}

