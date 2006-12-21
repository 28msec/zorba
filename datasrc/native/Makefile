OPT=-g
SUFX=do

scan_handler :	scan_handler.cpp scan_handler.h
	g++ -Wall -c ${OPT} -o scan_handler.${SUFX} scan_handler.cpp
scan_handler_test :	scan_handler.cpp scan_handler.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o scan_handler_test \
    scan_handler.${SUFX} \
    scan_handler_test.cpp

unicode_decompositions :	unicode_decompositions.cpp unicode_decompositions.h
	g++ -Wall -c ${OPT} -o unicode_decompositions.${SUFX} unicode_decompositions.cpp
unicode_decompositions_test :	unicode_decompositions.cpp unicode_decompositions.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o unicode_decompositions_test \
    unicode_decompositions.${SUFX} \
    unicode_decompositions_test.cpp

tag_scanner :	tag_scanner.cpp tag_scanner.h
	g++ -Wall -c ${OPT} -o tag_scanner.${SUFX} tag_scanner.cpp
tag_scanner_test :	tag_scanner.cpp tag_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o tag_scanner_test \
    tag_scanner.${SUFX} \
    tag_scanner_test.cpp

xml_tag_scanner :	xml_tag_scanner.cpp xml_tag_scanner.h
	g++ -Wall -c ${OPT} -o xml_tag_scanner.${SUFX} xml_tag_scanner.cpp
xml_tag_scanner_test :	xml_tag_scanner.cpp xml_tag_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG ${OPT} -o xml_tag_scanner_test \
    xml_tag_scanner.${SUFX} \
    xml_tag_scanner_test.cpp

xml_scanner :	xml_scanner.cpp xml_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o xml_scanner.${SUFX} xml_scanner.cpp 
xml_scanner_test :	xml_scanner_test.cpp xml_scanner.cpp xml_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o xml_scanner_test \
    ../../util/xqpexception.o \
    ../../util/file.${SUFX} \
    scan_handler.${SUFX} \
    xml_scanner.${SUFX} \
    xml_scanner_test.cpp

xml_term :	xml_term.cpp xml_term.h
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o xml_term.${SUFX} xml_term.cpp 
xml_term_test :	xml_term_test.cpp xml_term.cpp xml_term.h
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o xml_term_test \
    xml_term.${SUFX} \
    xml_term_test.cpp

html_scanner :	html_scanner.cpp html_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o html_scanner.${SUFX} html_scanner.cpp 
html_scanner_test :	html_scanner_test.cpp html_scanner.cpp html_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o html_scanner_test \
    ../../util/xqpexception.o \
    ../../util/file.${SUFX} \
    scan_handler.${SUFX} \
    html_scanner.${SUFX} \
    html_scanner_test.cpp

xml_handler :	xml_handler.cpp xml_handler.h
	g++ $(LARGEFILEFLAGS) -D DEBUG -Wall -c ${OPT} -o xml_handler.${SUFX} xml_handler.cpp 
xml_handler_test :	xml_handler_test.cpp xml_handler.cpp xml_handler.h xml_handler.${SUFX}
	g++ $(LARGEFILEFLAGS) -D DEBUG -Wall ${OPT} -o xml_handler_test \
    ../../util/xqpexception.o \
    ../../util/file.${SUFX} \
    ../../util/tokenbuf.${SUFX} \
    scan_handler.${SUFX} \
    xml_term.${SUFX} \
    xml_scanner.${SUFX} \
    xml_ostream.${SUFX} \
    xml_handler.${SUFX} \
    xml_handler_test.cpp

xml_ostream :	xml_ostream.cpp xml_ostream.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o xml_ostream.${SUFX} xml_ostream.cpp
xml_ostream_test :	xml_ostream_test.cpp xml_ostream.cpp xml_ostream.h
	g++ $(LARGEFILEFLAGS) -D DEBUG -Wall ${OPT} -o xml_ostream_test \
    ../../util/xqpexception.o \
    ../../types/QName.${SUFX} \
    xml_ostream.${SUFX} \
    xml_ostream_test.cpp

blockstore :	blockstore.cpp blockstore.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o blockstore.${SUFX} blockstore.cpp

xml_store :	xml_store.cpp xml_store.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o xml_store.${SUFX} xml_store.cpp

storage_manager :	storage_manager.cpp storage_manager.h 
	g++ $(LARGEFILEFLAGS) -Wall -c ${OPT} -o storage_manager.${SUFX} storage_manager.cpp
storage_manager_test :	storage_manager_test.cpp storage_manager.cpp storage_manager.h 
	g++ $(LARGEFILEFLAGS) -Wall ${OPT} -o storage_manager_test \
	../../util/file.${SUFX} \
	../../util/xqpexception.o \
	scan_handler.${SUFX} \
	xml_scanner.${SUFX} \
	storage_manager.${SUFX} \
	storage_manager_test.cpp



all :	\
	scan_handler			  \
	unicode_decomposer	\
	tag_scanner 				\
	xml_tag_scanner			\
	xml_scanner					\
	html_scanner


clean:
	$(CleanRule) *.do *.po *.ro *_unittest ${Executables} ${TestExecutables}

