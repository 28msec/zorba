include ../Makefile.header
SUFX=do
BUILD=Build

item_iterator : item_iterator.h item_iterator.cpp
	g++ ${OPT} -c -o ${BUILD}/item_iterator.${SUFX} item_iterator.cpp

plan_visitor : plan_visitor.h plan_visitor.cpp
	g++ ${OPT} -c -o ${BUILD}/plan_visitor.${SUFX} plan_visitor.cpp

zorba : zorba.h zorba.cpp
	g++ ${OPT} -c -o ${BUILD}/zorba.${SUFX} zorba.cpp

plan_visitor_test : plan_visitor.h plan_visitor.cpp plan_visitor_test.cpp
	g++ ${OPT} -o ${BUILD}/plan_visitor_test \
		../context/${BUILD}/static_context.${SUFX} \
		../context/${BUILD}/dynamic_context.${SUFX} \
		../dom/${BUILD}/dom_namepool.${SUFX} \
		../dom/${BUILD}/dom_nodes.${SUFX} \
		../dom/${BUILD}/dom_qname.${SUFX} \
		../dom/${BUILD}/dom_xml_handler.${SUFX} \
		../exprtree/${BUILD}/expr.${SUFX} \
		../exprtree/${BUILD}/normalize_visitor.${SUFX} \
		../functions/${BUILD}/library.${SUFX} \
		../functions/${BUILD}/Numerics.${SUFX} \
		../functions/${BUILD}/NumericsImpl.${SUFX} \
		../functions/${BUILD}/Sequences.${SUFX} \
		../functions/${BUILD}/SequencesImpl.${SUFX} \
		../functions/${BUILD}/signature.${SUFX} \
		../parser/${BUILD}/parsenodes.${SUFX} \
		../parser/${BUILD}/xquery_scanner.${SUFX} \
		../parser/${BUILD}/xquery_parser.${SUFX} \
		../parser/${BUILD}/symbol_table.${SUFX} \
		../parser/${BUILD}/xquery_driver.${SUFX} \
		../store/${BUILD}/scan_handler.${SUFX} \
		../store/${BUILD}/uri_resolver.${SUFX} \
		../store/${BUILD}/xml_scanner.${SUFX} \
		../store/${BUILD}/zorba_uri_resolver.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../values/${BUILD}/primitive_values.${SUFX} \
		../zorba/${BUILD}/zorba_qname.${SUFX} \
		../zorba/${BUILD}/qnamerep.${SUFX} \
		../errors/${BUILD}/xqp_exception.${SUFX} \
		../errors/${BUILD}/errors.${SUFX} \
		../errors/${BUILD}/Error.${SUFX} \
		${BUILD}/item_iterator.${SUFX} \
		${BUILD}/zorba.${SUFX} \
		${BUILD}/plan_visitor.${SUFX} \
	plan_visitor_test.cpp


all : \
	item_iterator \
	zorba \
	plan_visitor

test : \
	plan_visitor_test 

