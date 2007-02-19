include ../Makefile.header
SUFX=do
BUILD=Build

expr : expr.h expr.cpp
	g++ -c ${OPT} -o ${BUILD}/expr.${SUFX} expr.cpp

eval : expr.h expr.cpp eval.cpp
	g++ -c ${OPT} -o ${BUILD}/eval.${SUFX} eval.cpp

update_expr : update_expr.h update_expr.cpp
	g++ -c ${OPT} -o ${BUILD}/update_expr.${SUFX} update_expr.cpp

ft_expr : ft_expr.h ft_expr.cpp
	g++ -c ${OPT} -o ${BUILD}/ft_expr.${SUFX} ft_expr.cpp

expr_test : expr.h expr.cpp expr_test.cpp
	g++ -g -o ${BUILD}/expr_test \
		../context/${BUILD}/context.${SUFX} \
		../native_impl/${BUILD}/namespace_pool.${SUFX} \
		../native_impl/${BUILD}/qname_pool.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../parser/${BUILD}/symbol_table.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/eval.${SUFX} \
		${BUILD}/expr.${SUFX} \
		expr_test.cpp

eval_test : expr.h expr.cpp eval_test.cpp
	g++ -g -o ${BUILD}/eval_test \
		../context/${BUILD}/context.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../parser/${BUILD}/symbol_table.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/expr.${SUFX} \
		${BUILD}/eval.${SUFX} \
		eval_test.cpp

normalize_visitor : normalize_visitor.h normalize_visitor.cpp
	g++ ${OPT} -c -o ${BUILD}/normalize_visitor.${SUFX} normalize_visitor.cpp

normalize_visitor_test : normalize_visitor.h normalize_visitor.cpp normalize_visitor_test.cpp
	g++ -Wall -g -o ${BUILD}/normalize_visitor_test \
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
		${BUILD}/normalize_visitor.${SUFX} \
	normalize_visitor_test.cpp

plan_visitor : plan_visitor.h plan_visitor.cpp
	g++ ${OPT} -c -o ${BUILD}/plan_visitor.${SUFX} plan_visitor.cpp


all :	\
  expr \
	eval \
	update_expr \
	ft_expr

test : \
	expr_test \
	eval_test

