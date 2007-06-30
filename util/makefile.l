include ../Makefile.header
SUFX=o
BUILD=Build

xqp_exception : xqp_exception.h xqp_exception.cpp
	g++ ${CXXOPT} -c -o ${BUILD}/xqp_exception.${SUFX} xqp_exception.cpp

tokenbuf : tokenbuf.h tokenbuf.cpp
	g++ ${CXXOPT} -c -o ${BUILD}/tokenbuf.${SUFX} tokenbuf.cpp
tokenbuf_test : tokenbuf.h tokenbuf.cpp tokenbuf_test.cpp
	g++ ${CXXOPT} -o ${BUILD}/tokenbuf_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/file.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
	tokenbuf_test.cpp

rwlock :	rwlock.cpp rwlock.h 
	g++ ${CXXOPT} -c -o ${BUILD}/rwlock.${SUFX} rwlock.cpp
rwlock_test :	rwlock_test.cpp rwlock.cpp rwlock.h 
	g++ -D DEBUG ${CXXOPT} -lpthread -o ${BUILD}/rwlock_test \
		${BUILD}/rwlock.${SUFX} \
	rwlock_test.cpp; \

hashfun_test :	hashfun_test.cpp hashfun.h 
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/hashfun_test \
		${BUILD}/xqp_exception.${SUFX} \
	hashfun_test.cpp

hashmap_test :	hashmap_test.cpp hashmap.h 
	g++ ${LARGEFILES} -D DEBUG ${CXXOPT} -lpthread -o ${BUILD}/hashmap_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/rwlock.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
	hashmap_test.cpp

list_test :	list_test.cpp list.h 
	g++ ${CXXOPT} -o ${BUILD}/list_test \
		list_test.cpp

logger : logger.h logger.cpp
	g++ ${CXXOPT} -c -o ${BUILD}/logger.${SUFX} logger.cpp
logger_test : logger.h logger.cpp logger_test.cpp
	g++ ${LARGEFILES} -D DEBUG ${CXXOPT} -o ${BUILD}/logger_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/logger.${SUFX} \
	logger_test.cpp

rchandle_test :	rchandle.h rchandle_test.cpp
	g++ ${CXXOPT} -o ${BUILD}/rchandle_test \
		rchandle_test.cpp

sorter_test :	sorter_test.cpp sorter.h 
	g++ -D DEBUG ${CXXOPT} -o ${BUILD}/sorter_test \
		sorter_test.cpp; \

URI : URI.h URI.cpp
	g++ -c ${CXXOPT} -c -o ${BUILD}/URI.${SUFX} URI.cpp
URI_test : URI.h URI.cpp URI_test.cpp
	g++ -D DEBUG ${CXXOPT} -o ${BUILD}/URI_test \
		${BUILD}/URI.${SUFX} \
	URI_test.cpp

utf8_encoder :	utf8_encoder.cpp	utf8_encoder.h
	g++ ${CXXOPT} -c -o ${BUILD}/utf8_encoder.${SUFX} utf8_encoder.cpp
utf8_encoder_test :	utf8_encoder_test.cpp utf8_encoder.cpp	utf8_encoder.h
	g++ -D DEBUG ${CXXOPT} -o ${BUILD}/utf8_encoder_test \
		${BUILD}/utf8_encoder.${SUFX} \
	utf8_encoder_test.cpp

file :	file.cpp file.h 
	g++ ${LARGEFILES} ${CXXOPT} -c -o ${BUILD}/file.${SUFX} file.cpp
file_test :	file_test.cpp file.cpp file.h 
	g++ ${LARGEFILES} -D DEBUG ${CXXOPT} -o ${BUILD}/file_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
		${BUILD}/file.${SUFX} \
	file_test.cpp; \

mmfile :	mmfile.cpp mmfile.h 
	g++ -DDEBUG ${LARGEFILES} -c ${CXXOPT} -o ${BUILD}/mmfile.${SUFX} mmfile.cpp
mmfile_test :	mmfile_test.cpp mmfile.cpp mmfile.h 
	g++ ${LARGEFILES} -D DEBUG ${CXXOPT} -o ${BUILD}/mmfile_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
		${BUILD}/mmfile.${SUFX} \
	mmfile_test.cpp; \

fxarray_test :	fxarray_test.cpp fxarray.h mmfile.h mmfile.cpp
	g++ ${LARGEFILES} -D DEBUG ${CXXOPT} -o ${BUILD}/fxarray_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
		${BUILD}/mmfile.${SUFX} \
	fxarray_test.cpp; \

fxvector_test :	fxvector_test.cpp fxvector.h mmfile.h mmfile.cpp
	g++ ${LARGEFILES} -D DEBUG ${CXXOPT} -o ${BUILD}/fxvector_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
		${BUILD}/mmfile.${SUFX} \
	fxvector_test.cpp; \

fxcharheap : fxcharheap.h fxcharheap.cpp
	g++ ${CXXOPT} ${LARGEFILES} -c ${OPT} -o ${BUILD}/fxcharheap.${SUFX} fxcharheap.cpp
fxcharheap_test : fxcharheap.h fxcharheap.cpp fxcharheap_test.cpp
	g++ ${CXXOPT} ${LARGEFILES} -o ${BUILD}/fxcharheap_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
		${BUILD}/mmfile.${SUFX} \
		${BUILD}/file.${SUFX} \
		${BUILD}/fxcharheap.${SUFX} \
	fxcharheap_test.cpp

fxhashmap_test :	fxhashmap_test.cpp fxhashmap.h 
	g++ ${LARGEFILES} -D DEBUG ${CXXOPT} -lpthread -o ${BUILD}/fxhashmap_test \
		${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/rwlock.${SUFX} \
		${BUILD}/tokenbuf.${SUFX} \
		${BUILD}/mmfile.${SUFX} \
		${BUILD}/file.${SUFX} \
		${BUILD}/fxcharheap.${SUFX} \
	fxhashmap_test.cpp


all	: \
	xqp_exception \
	rwlock \
	tokenbuf \
	hashfun_test \
	hashmap_test \
	file \
	tokenbuf_test \
	file_test \
	mmfile \
	fxarray_test \
	fxvector_test \
	fxcharheap \
	fxcharheap_test \
	fxhashmap_test \
	list_test \
	rchandle_test \
	sorter_test \
	utf8_encoder \
	URI \


