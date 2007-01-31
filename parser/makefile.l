include ../Makefile.header
SUFX=do
BUILD=Build

xquery_scanner : xquery_scanner.l
	flex -i -t xquery_scanner.l >xquery_scanner.yy.cpp
	g++ ${OPT} -c -o ${BUILD}/xquery_scanner.${SUFX} xquery_scanner.yy.cpp

xquery_parser : xquery_parser.y
	bison -v -t -d xquery_parser.y
	g++ -Wall -g -c -o ${BUILD}/xquery_parser.${SUFX} xquery_parser.tab.c

xquery_driver : xquery_driver.h xquery_driver.cpp
	g++ ${OPT} -c -o ${BUILD}/xquery_driver.${SUFX} xquery_driver.cpp

symbol_table : symbol_table.h symbol_table.cpp
	g++ ${OPT} -c -o ${BUILD}/symbol_table.${SUFX} symbol_table.cpp

parsenodes : parsenodes.h parsenodes.cpp
	g++ ${OPT} -c -o ${BUILD}/parsenodes.${SUFX} parsenodes.cpp

xquery_test : xquery_test.cpp xquery_scanner.l xquery_parser.y xquery_driver.h xquery_driver.cpp
	g++ -Wall -g -o ${BUILD}/xquery_test \
		../context/${BUILD}/context.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/parsenodes.${SUFX} \
		${BUILD}/xquery_scanner.${SUFX} \
		${BUILD}/xquery_parser.${SUFX} \
		${BUILD}/symbol_table.${SUFX} \
		${BUILD}/xquery_driver.${SUFX} \
		xquery_test.cpp

all : \
	parsenodes \
	xquery_parser \
	xquery_scanner \
	xquery_driver \
	symbol_table 

test : \
	xquery_test

