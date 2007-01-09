

html_scanner :	html_scanner.cpp html_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o html_scanner.do html_scanner.cpp 
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o html_scanner.o html_scanner.cpp 
	g++ $(LARGEFILEFLAGS) -Wall -c -pg -O2 -o html_scanner.po html_scanner.cpp 
html_scannerTest :	html_scanner.cpp html_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o html_scanner_unittest \
    html_scanner.do \
    html_scanner_unittest.cpp

scan_handler :	scan_handler.cpp scan_handler.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o scan_handler.do scan_handler.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o scan_handler.o scan_handler.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -pg -O2 -o scan_handler.po scan_handler.cpp
scan_handlerTest :	scan_handler.cpp scan_handler.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o scan_handler_unittest \
    scan_handler.do \
    scan_handler_unittest.cpp


tag_scanner :	tag_scanner.cpp tag_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o tag_scanner.do tag_scanner.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o tag_scanner.o tag_scanner.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -pg -O2 -o tag_scanner.po tag_scanner.cpp
tag_scannerTest :	tag_scanner.cpp tag_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o tag_scanner_unittest \
    tag_scanner.do \
    tag_scanner_unittest.cpp


unicode_decomposer :	unicode_decomposer.cpp unicode_decomposer.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o unicode_decomposer.do unicode_decomposer.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o unicode_decomposer.o unicode_decomposer.cpp
	g++ $(LARGEFILEFLAGS) -Wall -c -pg -O2 -o unicode_decomposer.po unicode_decomposer.cpp
unicode_decomposerTest :	unicode_decomposer.cpp unicode_decomposer.h
	g++ $(LARGEFILEFLAGS) -Wall -D DEBUG -g -o unicode_decomposer_unittest \
    unicode_decomposer.do \
    unicode_decomposer_unittest.cpp


xml_scanner :	xml_scanner.cpp xml_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -c -g -o xml_scanner.do xml_scanner.cpp 
	g++ $(LARGEFILEFLAGS) -Wall -c -O2 -o xml_scanner.o xml_scanner.cpp 
	g++ $(LARGEFILEFLAGS) -Wall -c -pg -O2 -o xml_scanner.po xml_scanner.cpp 
xml_scannerTest :	xml_scanner_unittest.cpp xml_scanner.cpp xml_scanner.h
	g++ $(LARGEFILEFLAGS) -Wall -g -o xml_scanner_unittest \
    ../core/Exception.o \
    ../core/File.do \
    ../core/logger.do \
    scan_handler.do \
    xml_scanner.do \
    xml_scanner_unittest.cpp


all :	\
	tag_scanner					\
	unicode_decomposer	\
	scan_handler			  \
	html_scanner	  		\
	xml_scanner


clean:
	$(CleanRule) *.do *.po *.ro *_unittest ${Executables} ${TestExecutables}

