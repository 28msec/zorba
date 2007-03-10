include ../Makefile.header
SUFX=do
BUILD=Build

values :	values.h values.cpp
	g++ ${OPT} -c -o ${BUILD}/values.${SUFX} values.cpp

xs_primitive_values :	xs_primitive_values.h xs_primitive_values.cpp
	g++ ${OPT} -c -o ${BUILD}/xs_primitive_values.${SUFX} xs_primitive_values.cpp
   
nodes :	nodes.h nodes.cpp
	g++ ${OPT} -c -o ${BUILD}/nodes.${SUFX} nodes.cpp
    
ft_options :	ft_options.h ft_options.cpp
	g++ ${OPT} -c -o ${BUILD}/ft_options.${SUFX} ft_options.cpp

ft_values :	ft_values.h ft_values.cpp
	g++ ${OPT} -c -o ${BUILD}/ft_values.${SUFX} ft_values.cpp

update_values :	update_values.h update_values.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/update_values.${SUFX} update_values.cpp

qname_test : qname_value.h qname_value.cpp qname_test.cpp
	g++ ${OPT} -o ${BUILD}/qname_test \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/qname_value.${SUFX} \
		qname_test.cpp

xs_primitive_values_test : xs_primitive_values.h xs_primitive_values.cpp xs_primitive_values_test.cpp
	g++ ${OPT} -o ${BUILD}/xs_primitive_values_test \
		../context/${BUILD}/context.${SUFX} \
		../native_impl/${BUILD}/nodestore.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/values.${SUFX} \
		${BUILD}/node_values.${SUFX} \
		${BUILD}/xs_primitive_values.${SUFX} \
		xs_primitive_values_test.cpp

nodes_test : nodes.h nodes.cpp nodes_test.cpp
	g++ ${OPT} -o ${BUILD}/nodes_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../store/${BUILD}/itemstore.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/values.${SUFX} \
		${BUILD}/nodes.${SUFX} \
		nodes_test.cpp

values_test : values.h values.cpp values_test.cpp
	g++ ${OPT} -o ${BUILD}/values_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../store/${BUILD}/qname_cache.${SUFX} \
		../store/${BUILD}/itemstore.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/values.${SUFX} \
		${BUILD}/xs_primitive_values.${SUFX} \
		values_test.cpp

ft_values_test :	ft_values.h ft_values.cpp ft_values_test.cpp
	g++ ${OPT} -o ${BUILD}/ft_values_test \
		${BUILD}/ft_options.${SUFX} \
		${BUILD}/ft_values.${SUFX} \
		ft_values_test.cpp

all : \
	values \
	nodes \
	xs_primitive_values \
	ft_values \
	update_values

test : \
	xs_primitive_values_test \
	nodes_test \
	values_test

