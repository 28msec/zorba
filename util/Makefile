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


bitbuffer : bitbuffer.h bitbuffer.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o bitbuffer.do bitbuffer.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o bitbuffer.o bitbuffer.cpp
bitbufferTest : bitbuffer.h bitbuffer.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o bitbuffer_unittest \
		Exception.o \
		bitbuffer.do \
		bitbuffer_unittest.cpp


blockstore :	blockstore.cpp blockstore.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o blockstore.do blockstore.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o blockstore.o blockstore.cpp
blockstoreTest : blockstore.h blockstore.cpp blockstore_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -lpthread -o blockstore_unittest \
		Exception.o \
		bitbuffer.do \
		coder.do \
		logger.do \
		rwlock.do \
		../search/DocPosting.do \
		../search/docid_set.do \
		../search/PostingList.do \
		../search/Scorer.do \
		../docs/tag_scanner.do \
		blockstore.do \
		blockstore_unittest.cpp


coder: coder.h coder.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o coder.do coder.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o coder.o coder.cpp
coderTest : coder.h coder.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o coder_unittest \
		coder.do \
		Exception.o \
		coder_unittest.cpp


Exception :	Exception.cpp	Exception.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -g -o Exception.do Exception.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o Exception.o Exception.cpp


file :	file.cpp file.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o file.do file.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o file.o file.cpp
fileTest :	file_unittest.cpp file.cpp file.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o file_unittest \
		Exception.o \
		file.do \
		file_unittest.cpp


filebuf64 :	filebuf64.cpp filebuf64.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o filebuf64.do filebuf64.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o filebuf64.o filebuf64.cpp
filebuf64Test :	filebuf64_unittest.cpp filebuf64.cpp filebuf64.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o filebuf64_unittest \
		Exception.o \
		filebuf64.do \
		filebuf64_unittest.cpp


filehashTest :	filehash_unittest.cpp filehash.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o filehash_unittest \
		Exception.o \
		fileheap.do \
		tokenizer.do \
		filehash_unittest.cpp


fileheap :	fileheap.cpp fileheap.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o fileheap.do fileheap.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o fileheap.o fileheap.cpp
fileheapTest : 	fileheap_unittest.cpp fileheap.cpp fileheap.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o fileheap_unittest \
		Exception.o \
		tokenizer.do \
		fileheap.do \
		fileheap_unittest.cpp



kvheap :	kvheap.cpp kvheap.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o kvheap.do kvheap.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o kvheap.o kvheap.cpp
kvheapTest : kvheap.h kvheap.cpp kvheap_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -I../core -g -lpthread -o kvheap_unittest \
    blockstore.do \
    coder.do \
    Exception.o \
    kvheap.do \
    logger.do \
    tokenizer.do \
    rwlock.do \
    kvheap_unittest.cpp


cacheTest :	cache_unittest.cpp cache.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -lpthread -o cache_unittest \
		Exception.o \
		tokenizer.do \
		cache_unittest.cpp


hashfunTest :	hashfun_unittest.cpp hashfun.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o hashfun_unittest \
		Exception.o \
		hashfun_unittest.cpp


hashmap :	hashmap.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o hashmap.do hashmap.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o hashmap.o hashmap.cpp
hashmapTest :	hashmap_unittest.cpp hashmap.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -lpthread -o hashmap_unittest \
		Exception.o \
		rwlock.do \
		tokenizer.do \
		hashmap_unittest.cpp


list :	list.cpp list.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o list.do list.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o list.o list.cpp
listTest :	list.cpp list.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o list_unittest \
		Exception.o \
		tokenizer.do \
		list.cpp


logger : logger.h logger.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o logger.do logger.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o logger.o logger.cpp
loggerTest : logger.h logger.cpp logger_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o logger_unittest \
		Exception.o \
		logger.do \
		logger_unittest.cpp


mmarrayTest :	mmarray_unittest.cpp mmarray.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o mmarray_unittest \
		Exception.o \
		tokenizer.do \
		mmarray_unittest.cpp


mmhashmapTest :	mmhashmap_unittest.cpp mmhashmap.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o mmhashmap_unittest \
		Exception.o \
		mmheap.do \
		tokenizer.do \
		mmhashmap_unittest.cpp


mmhash64set :	mmhash64set.cpp mmhash64set.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -c -g -o mmhash64set.do mmhash64set.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o mmhash64set.o mmhash64set.cpp
mmhash64setTest :	mmhash64set_unittest.cpp mmhash64set.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -lpthread -o mmhash64set_unittest \
		Exception.o \
		mmhash64set.do \
		rwlock.do \
		tokenizer.do \
		mmhash64set_unittest.cpp


persistent_charheap :	persistent_charheap.cpp persistent_charheap.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o persistent_charheap.do persistent_charheap.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o persistent_charheap.o persistent_charheap.cpp
persistent_charheap_test : 	persistent_charheap_test.cpp persistent_charheap.cpp persistent_charheap.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o persistent_charheap_test \
		xqpexception.o \
		tokenbuf.do \
		persistent_charheap.do \
		persistent_charheap_test.cpp


mmqueue :	mmqueue.cpp mmqueue.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o mmqueue.do mmqueue.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o mmqueue.o mmqueue.cpp
mmqueueTest :	mmqueue_unittest.cpp mmqueue.cpp mmqueue.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o mmqueue_unittest \
		Exception.o \
		mmheap.do \
		mmqueue.do \
		tokenizer.do \
		mmqueue_unittest.cpp


mmstrhash	:	mmstrhash.cpp mmstrhash.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o mmstrhash.do mmstrhash.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o mmstrhash.o mmstrhash.cpp
mmstrhashTest :	mmstrhash_unittest.cpp mmstrhash.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o mmstrhash_unittest \
		Exception.o \
		mmheap.do \
		mmstrhash.do \
		tokenizer.do \
		mmstrhash_unittest.cpp


mmvectorTest :	mmvector_unittest.cpp mmvector.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o mmvector_unittest \
    Exception.o \
    tokenizer.do \
    mmvector_unittest.cpp


kvmap32 :	kvmap32.cpp kvmap32.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o kvmap32.do kvmap32.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o kvmap32.o kvmap32.cpp
kvmap32Test : kvmap32.h kvmap32.cpp kvmap32_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -I../core -g -lpthread -o kvmap32_unittest \
    coder.do \
    Exception.o \
    logger.o \
    tokenizer.do \
    block.do \
    bucket.do \
    file_mapped_bucket.do \
    block_mapped_bucket.do \
    blockstore.do \
    rwlock.do \
    kvheap.do \
    kvmap32.do \
    kvmap32_unittest.cpp


mmvectorVectorTest :	mmvector_vectortest.cpp mmvector.cpp mmvector.h 
	g++ $(LARGEFILEFLAGS) -Wall -g -o mmvector_vectortest \
		mmheap.do \
		Exception.o \
		mmvector_vectortest.cpp


param_parser : param_parser.cpp param_parser.h
	g++ $(LARGEFILEFLAGS) -Wall -I../repository -c -g -o param_parser.do param_parser.cpp
	g++ $(LARGEFILEFLAGS) -Wall -I../repository -c -O2 -o param_parser.o param_parser.cpp
param_parserTest : param_parser.cpp param_parser.h
	g++ $(LARGEFILEFLAGS) -Wall -I../repository -D DEBUG -g -o param_parser_unittest \
		../repository/stopterm.do \
		param_parser.do \
		tokenizer.do \
		param_parser_unittest.cpp


simple_string :	rchandle.h simple_string.h simple_string.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o simple_string.do simple_string.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o simple_string.o simple_string.cpp
simple_stringTest :	rchandle.h simple_string.h simple_string.cpp simple_string_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -g -O3 -o simple_string \
		simple_string.do \
		simple_string_unittest.cpp


rchandleTest :	rchandle.h rchandle_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -g -o rchandle_unittest \
		rchandle_unittest.cpp


rwlock :	rwlock.cpp rwlock.h 
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o rwlock.do rwlock.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o rwlock.o rwlock.cpp
rwlockTest :	rwlock.cpp rwlock.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -lpthread -o rwlock_unittest \
		rwlock.do \
		rwlock_unittest.cpp; \


sorterTest :	sorter_unittest.cpp sorter.h 
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o sorter_unittest \
		sorter_unittest.cpp


socket : socket.h socket.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o socket.do socket.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o socket.o socket.cpp
socketTest : socket.h socket.cpp socket_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -g -o socket_unittest \
		Exception.o \
		socket.do \
		socket_unittest.cpp


tokenizer : tokenizer.cpp tokenizer.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o tokenizer.do tokenizer.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o tokenizer.o tokenizer.cpp
tokenizerTest : tokenizer_unittest.cpp tokenizer.cpp tokenizer.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o tokenizer_unittest \
		tokenizer.do \
		tokenizer_unittest.cpp


URI : URI.h URI.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o URI.do URI.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o URI.o URI.cpp
URITest : URI.h URI.cpp URI_unittest.cpp
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o URI_unittest \
		URI.do \
		URI_unittest.cpp


utf8_encoder :	utf8_encoder.cpp	utf8_encoder.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o utf8_encoder.do utf8_encoder.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o utf8_encoder.o utf8_encoder.cpp
utf8_encoderTest :	utf8_encoder_unittest.cpp utf8_encoder.cpp	utf8_encoder.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o utf8_encoder_unittest \
		utf8_encoder.do \
		utf8_encoder_unittest.cpp


workq : workq.h workq.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o workq.do workq.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o workq.o workq.cpp


all	: bitbuffer \
	blockstore \
	coder	\
	Exception \
	file \
	filebuf64 \
	filehashTest \
	fileheap \
	cacheTest \
	hashmapTest \
  kvheap \
 	logger \
	mmarrayTest \
	mmhashmapTest \
	mmhash64set \
	mmheap \
	mmqueueTest \
	mmvectorTest \
	param_parser \
  rwlock \
	sorterTest \
	tokenizer \
	utf8_encoder \
	blockstoreTest \
	tokenizerTest \
	param_parserTest \
	mmheapTest \
	fileheapTest \
	fileTest


clean:
	$(CleanRule) *.do *.po *.ro *_unittest ${Executables}

