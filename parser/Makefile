OPT=-g
SUFX=do
BUILD=Build

scanner : xquery_scanner.l
	flex -i -t xquery_scanner.l >xquery_scanner.yy.cpp
	g++ -c ${OPT} -o ${BUILD}/xquery_scanner.${SUFX} xquery_scanner.yy.cpp

scanner0 : xquery_scanner.l
	flex -i -t xquery_scanner.l >${BUILD}/xquery_scanner.yy.cpp

parser : xquery_parser.y
	bison -v -t -d xquery_parser.y
	g++ -c ${OPT} -o ${BUILD}/xquery_parser.${SUFX} xquery_parser.tab.c

parser0 : xquery_parser.y
	bison -v -t -d xquery_parser.y

driver : xquery_driver.h xquery_driver.cpp
	g++ -c ${OPT} -o ${BUILD}/xquery_driver.${SUFX} xquery_driver.cpp

symtab : symbol_table.h symbol_table.cpp
	g++ -c ${OPT} -o ${BUILD}/symbol_table.${SUFX} symbol_table.cpp

parsenodes : parsenodes.h parsenodes.cpp
	g++ -c ${OPT} -o ${BUILD}/parsenodes.${SUFX} parsenodes.cpp

test : xquery_test.cpp xquery_scanner.l xquery_parser.y xquery_driver.h xquery_driver.cpp
	g++ ${OPT} -o ${BUILD}/xquery_test \
		../datamodel/${BUILD}/qname.do \
		../util/${BUILD}/xqp_exception.o \
		../util/${BUILD}/file.do \
		../util/${BUILD}/mmfile.do \
		../util/${BUILD}/fxcharheap.do \
		../util/${BUILD}/URI.do \
		${BUILD}/parsenodes.do \
		${BUILD}/xquery_scanner.do \
		${BUILD}/xquery_parser.do \
		${BUILD}/symbol_table.do \
		${BUILD}/xquery_driver.do \
		xquery_test.cpp

all : \
	parsenodes \
	parser \
	scanner \
	driver \
	symtab \
	test
