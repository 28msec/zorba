OPT=-g
SUFX=do

xqpexception : xqpexception.h xqpexception.cpp
	g++ ${OPT} -c -o xqpexception.o xqpexception.cpp


persistent_vector_test : 	persistent_vector_test.cpp persistent_vector.h 
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o persistent_vector_test \
		xqpexception.o \
		tokenbuf.${SUFX} \
		persistent_vector_test.cpp


tokenbuf : tokenbuf.h tokenbuf.cpp
	g++ -c ${OPT} -o tokenbuf.${SUFX} tokenbuf.cpp
tokenbuf_test : tokenbuf.h tokenbuf.cpp tokenbuf_test.cpp
	g++ ${OPT} -o tokenbuf_test tokenbuf.${SUFX} \
		xqpexception.o \
		file.${SUFX} \
		tokenbuf_test.cpp


hashfun_test :	hashfun_test.cpp hashfun.h 
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o hashfun_test \
		xqpexception.o \
		hashfun_test.cpp


hashmap :	hashmap.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o hashmap.${SUFX} hashmap.cpp
hashmap_test :	hashmap_test.cpp hashmap.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -lpthread -o hashmap_test \
		xqpexception.o \
		rwlock.${SUFX} \
		tokenbuf.${SUFX} \
		hashmap_test.cpp


list_test :	list_test.cpp list.h 
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o list_test \
		list_test.cpp


logger : logger.h logger.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o logger.${SUFX} logger.cpp
logger_test : logger.h logger.cpp logger_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o logger_test \
		xqpexception.o \
		logger.${SUFX} \
		logger_test.cpp


rchandle_test :	rchandle.h rchandle_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o rchandle_test \
		rchandle_test.cpp


rwlock :	rwlock.cpp rwlock.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o rwlock.${SUFX} rwlock.cpp
rwlock_test :	rwlock_test.cpp rwlock.cpp rwlock.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -lpthread -o rwlock_test \
		rwlock.${SUFX} \
		rwlock_test.cpp; \


sorter_test :	sorter_test.cpp sorter.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o sorter_test \
		sorter_test.cpp; \


URI : URI.h URI.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o URI.${SUFX} URI.cpp
URI_test : URI.h URI.cpp URI_test.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o URI_test \
		URI.${SUFX} \
		URI_test.cpp


utf8_encoder :	utf8_encoder.cpp	utf8_encoder.h
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o utf8_encoder.${SUFX} utf8_encoder.cpp
utf8_encoder_test :	utf8_encoder_test.cpp utf8_encoder.cpp	utf8_encoder.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o utf8_encoder_test \
		utf8_encoder.${SUFX} \
		utf8_encoder_test.cpp


file :	file.cpp file.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o file.${SUFX} file.cpp
file_test :	file_test.cpp file.cpp file.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o file_test \
		xqpexception.o \
		tokenbuf.${SUFX} \
		file.${SUFX} \
		file_test.cpp; \


mmfile :	mmfile.cpp mmfile.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o mmfile.${SUFX} mmfile.cpp
mmfile_test :	mmfile_test.cpp mmfile.cpp mmfile.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o mmfile_test \
		xqpexception.o \
		tokenbuf.${SUFX} \
		mmfile.${SUFX} \
		mmfile_test.cpp; \


fxarray_test :	fxarray_test.cpp fxarray.h mmfile.h mmfile.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o fxarray_test \
		xqpexception.o \
		tokenbuf.${SUFX} \
		mmfile.${SUFX} \
		fxarray_test.cpp; \

fxvector_test :	fxvector_test.cpp fxvector.h mmfile.h mmfile.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o fxvector_test \
		xqpexception.o \
		tokenbuf.${SUFX} \
		mmfile.${SUFX} \
		fxvector_test.cpp; \

fxcharheap : fxcharheap.h fxcharheap.cpp
	g++ ${OPT} -c ${OPT} -o fxcharheap.${SUFX} fxcharheap.cpp
fxcharheap_test : fxcharheap.h fxcharheap.cpp fxcharheap_test.cpp
	g++ ${OPT} -o fxcharheap_test \
		xqpexception.o \
		tokenbuf.${SUFX} \
		mmfile.${SUFX} \
		file.${SUFX} \
		fxcharheap.${SUFX} \
		fxcharheap_test.cpp



all	: \
	charheap \
	perisistent_charheap \
 	logger \
	rwlock \
	tokenbuf \
	utf8_encoder \
	URI \


test : \
	charheap_test \
	persistent_charheap_test \
	hashfun_test \
	hashmap_test \
	rchandle_test \
	rwlock_test \
	sorter_test \
	tokenbuf_test \
	utf8_encoder_test 

clean:
	$(CleanRule) *.${SUFX} *.po *.ro *_test ${Executables}

