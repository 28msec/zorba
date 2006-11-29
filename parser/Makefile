OPT=-g
SUFX=do

scanner : xquery_scanner.l
	flex -i -t xquery_scanner.l >xquery_scanner.yy.cpp
	g++ -c ${OPT} -o xquery_scanner.${SUFX} xquery_scanner.yy.cpp

parser : xquery_parser.y
	bison -v -d xquery_parser.y
	g++ -c ${OPT} -o xquery_parser.${SUFX} xquery_parser.tab.c

driver : xquery_driver.h xquery_driver.cpp
	g++ -c ${OPT} -o xquery_driver.${SUFX} xquery_driver.cpp

symtab : symbol_table.h symbol_table.cpp
	g++ -c ${OPT} -o symbol_table.${SUFX} symbol_table.cpp

parsenodes : parsenodes.h parsenodes.cpp
	g++ -c ${OPT} -o parsenodes.${SUFX} parsenodes.cpp

test : xquery_test.cpp
	g++ ${OPT} -o xquery_test \
		parsenodes.do \
		xquery_scanner.do \
		xquery_parser.do \
		../util/xqpexception.o \
		../util/file.do \
		../util/mmfile.do \
		../util/fxcharheap.do \
		symbol_table.do \
		xquery_driver.do \
		xquery_test.cpp
