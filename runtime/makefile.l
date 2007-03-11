include ../Makefile.header
SUFX=do
BUILD=Build

errors : errors.h errors.cpp
	g++ ${OPT} -c -o ${BUILD}/errors.${SUFX} errors.cpp

iterator : iterator.h iterator.cpp
	g++ ${OPT} -c -o ${BUILD}/iterator.${SUFX} iterator.cpp

iterator_test : iterator.h iterator.cpp iterator_test.cpp
	g++ -Wall -g -o ${BUILD}/iterator_test \
		../context/${BUILD}/context.${SUFX} \
		../native_impl/${BUILD}/namespace_pool.${SUFX} \
		../native_impl/${BUILD}/qname_pool.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/iterator.${SUFX} \
		iterator_test.cpp

plan_visitor : plan_visitor.h plan_visitor.cpp
	g++ ${OPT} -c -o ${BUILD}/plan_visitor.${SUFX} plan_visitor.cpp

plan_visitor_test : plan_visitor.h plan_visitor.cpp plan_visitor_test.cpp
	g++ -Wall -g -o ${BUILD}/plan_visitor_test \
		../context/${BUILD}/context.${SUFX} \
		../exprtree/${BUILD}/expr.${SUFX} \
		../exprtree/${BUILD}/eval.${SUFX} \
		../native_impl/${BUILD}/namespace_pool.${SUFX} \
		../native_impl/${BUILD}/qname_pool.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../parser/${BUILD}/parsenodes.${SUFX} \
		../parser/${BUILD}/xquery_scanner.${SUFX} \
		../parser/${BUILD}/xquery_parser.${SUFX} \
		../parser/${BUILD}/symbol_table.${SUFX} \
		../parser/${BUILD}/xquery_driver.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../runtime/${BUILD}/normalize_visitor.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/plan_visitor.${SUFX} \
	plan_visitor_test.cpp


all : \
	iterator \
	plan_visitor

test : \
	iterator_test

