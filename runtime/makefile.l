include ../Makefile.header
SUFX=do
BUILD=Build

errors : errors.h errors.cpp
	g++ ${OPT} -c -o ${BUILD}/errors.${SUFX} errors.cpp

plan_visitor : plan_visitor.h plan_visitor.cpp
	g++ ${OPT} -c -o ${BUILD}/plan_visitor.${SUFX} plan_visitor.cpp

zorba : zorba.h zorba.cpp
	g++ ${OPT} -c -o ${BUILD}/zorba.${SUFX} zorba.cpp

plan_visitor_test : plan_visitor.h plan_visitor.cpp plan_visitor_test.cpp
	g++ -Wall -g -o ${BUILD}/plan_visitor_test \
		../context/${BUILD}/context.${SUFX} \
		../exprtree/${BUILD}/expr.${SUFX} \
		../exprtree/${BUILD}/normalize_visitor.${SUFX} \
		../store/${BUILD}/qname_cache.${SUFX} \
		../store/${BUILD}/itemstore.${SUFX} \
		../parser/${BUILD}/parsenodes.${SUFX} \
		../parser/${BUILD}/xquery_scanner.${SUFX} \
		../parser/${BUILD}/xquery_parser.${SUFX} \
		../parser/${BUILD}/symbol_table.${SUFX} \
		../parser/${BUILD}/xquery_driver.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../runtime/${BUILD}/errors.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/nodes.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/plan_visitor.${SUFX} \
	plan_visitor_test.cpp


all : \
	errors \
	zorba \
	plan_visitor

test : \
	plan_visitor_test 

