include ../Makefile.header
SUFX=do
BUILD=Build

expr : expr.h expr.cpp
	g++ -c ${OPT} -o ${BUILD}/expr.${SUFX} expr.cpp

expr_test : expr.h expr.cpp expr_test.cpp
	g++ -g -o ${BUILD}/expr_test \
		../context/${BUILD}/context.${SUFX} \
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

eval : expr.h expr.cpp eval.cpp
	g++ -c ${OPT} -o ${BUILD}/eval.${SUFX} eval.cpp
eval_test : expr.h expr.cpp eval_test.cpp
	g++ -g -o ${BUILD}/eval_test \
		../context/${BUILD}/context.${SUFX} \
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

update_expr : update_expr.h update_expr.cpp
	g++ -c ${OPT} -o ${BUILD}/update_expr.${SUFX} update_expr.cpp

ft_expr : ft_expr.h ft_expr.cpp
	g++ -c ${OPT} -o ${BUILD}/ft_expr.${SUFX} ft_expr.cpp



all :	\
  expr \
	update_expr \
	ft_expr


#expr_test \
