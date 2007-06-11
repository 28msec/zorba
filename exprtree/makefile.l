include ../Makefile.header
SUFX=do
BUILD=Build

expr : expr.h expr.cpp
	g++ -c ${OPT} -o ${BUILD}/expr.${SUFX} expr.cpp

update_expr : update_expr.h update_expr.cpp
	g++ -c ${OPT} -o ${BUILD}/update_expr.${SUFX} update_expr.cpp

ft_expr : ft_expr.h ft_expr.cpp
	g++ -c ${OPT} -o ${BUILD}/ft_expr.${SUFX} ft_expr.cpp

expr_test : expr.h expr.cpp expr_test.cpp
	g++ -g -o ${BUILD}/expr_test \
		../context/${BUILD}/context.${SUFX} \
		../functions/${BUILD}/signature.${SUFX} \
		../parser/${BUILD}/symbol_table.${SUFX} \
		../runtime/${BUILD}/errors.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../store/${BUILD}/qname_cache.${SUFX} \
		../store/${BUILD}/itemstore.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/nodes.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/expr.${SUFX} \
		expr_test.cpp

normalize_visitor : normalize_visitor.h normalize_visitor.cpp
	g++ ${OPT} -c -o ${BUILD}/normalize_visitor.${SUFX} normalize_visitor.cpp

normalize_visitor_test : normalize_visitor.h normalize_visitor.cpp normalize_visitor_test.cpp
	g++ ${OPT} -o ${BUILD}/normalize_visitor_test \
		../context/${BUILD}/static_context.${SUFX} \
		../context/${BUILD}/dynamic_context.${SUFX} \
		../dom/${BUILD}/dom_namepool.${SUFX} \
		../dom/${BUILD}/dom_nodes.${SUFX} \
		../dom/${BUILD}/dom_qname.${SUFX} \
		../dom/${BUILD}/dom_xml_handler.${SUFX} \
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
		../runtime/${BUILD}/errors.${SUFX} \
		../runtime/${BUILD}/item_iterator.${SUFX} \
		../runtime/${BUILD}/zorba.${SUFX} \
		../store/${BUILD}/scan_handler.${SUFX} \
		../store/${BUILD}/uri_resolver.${SUFX} \
		../store/${BUILD}/xml_scanner.${SUFX} \
		../store/${BUILD}/zorba_uri_resolver.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/primitive_values.${SUFX} \
		../zorba/${BUILD}/zorba_qname.${SUFX} \
		../zorba/${BUILD}/qnamerep.${SUFX} \
		${BUILD}/expr.${SUFX} \
		${BUILD}/normalize_visitor.${SUFX} \
	normalize_visitor_test.cpp

all :	\
  expr \
	update_expr \
	ft_expr \
	normalize_visitor

test : \
	expr_test \
	eval_test \
	normalize_visitor_test

