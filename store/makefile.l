include ../Makefile.header
SUFX=do
BUILD=Build

buildVersion :
	echo "#ifndef BUILD_VERSION_DEFINED" > buildVersion.h
	echo -n "#define BUILD_SVN_VERSION \"" >> buildVersion.h
	echo -n `svn info | grep ^Revision` >> buildVersion.h
	echo "\"" >> buildVersion.h
	echo -n "#define BUILD_WHOAMI \"" >> buildVersion.h
	echo -n `whoami` >> buildVersion.h
	echo "\"" >> buildVersion.h
	echo "#endif" >> buildVersion.h


uri_resolver :	uri_resolver.cpp uri_resolver.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/uri_resolver.${SUFX} uri_resolver.cpp
uri_resolver_test :	uri_resolver_test.cpp uri_resolver.cpp uri_resolver.h 
	g++ -Wall ${OPT} -o ${BUILD}/uri_resolver_test \
    ../util/${BUILD}/tokenbuf.${SUFX} \
    ../util/${BUILD}/URI.${SUFX} \
    ${BUILD}/uri_resolver.${SUFX} \
    uri_resolver_test.cpp

collation_resolver :	collection_resolver.cpp collection_resolver.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/collation_resolver.${SUFX} collection_resolver.cpp
collation_resolver_test : collection_resolver_test.cpp collection_resolver.cpp collection_resolver.h 
	g++ -Wall ${OPT} -o ${BUILD}/collation_resolver_test \
    ../util/${BUILD}/tokenbuf.${SUFX} \
    ../util/${BUILD}/URI.${SUFX} \
    ${BUILD}/collation_resolver.${SUFX} \
    collation_resolver_test.cpp

collection_resolver :	collection_resolver.cpp collection_resolver.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/collection_resolver.${SUFX} collection_resolver.cpp
collection_resolver_test : collection_resolver_test.cpp collection_resolver.cpp collection_resolver.h 
	g++ -Wall ${OPT} -o ${BUILD}/collection_resolver_test \
    ../util/${BUILD}/tokenbuf.${SUFX} \
    ../util/${BUILD}/URI.${SUFX} \
    ${BUILD}/collection_resolver.${SUFX} \
    collection_resolver_test.cpp

module_resolver :	module_resolver.cpp module_resolver.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/module_resolver.${SUFX} module_resolver.cpp
module_resolver_test : module_resolver_test.cpp module_resolver.cpp module_resolver.h 
	g++ -Wall ${OPT} -o ${BUILD}/module_resolver_test \
    ../util/${BUILD}/tokenbuf.${SUFX} \
    ../util/${BUILD}/URI.${SUFX} \
    ${BUILD}/module_resolver.${SUFX} \
		module_resolver_test.cpp

schema_resolver :	schema_resolver.cpp schema_resolver.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/schema_resolver.${SUFX} schema_resolver.cpp
schema_resolver_test : schema_resolver_test.cpp schema_resolver.cpp schema_resolver.h 
	g++ -Wall ${OPT} -o ${BUILD}/schema_resolver_test \
    ../util/${BUILD}/tokenbuf.${SUFX} \
    ../util/${BUILD}/URI.${SUFX} \
    ${BUILD}/schema_resolver.${SUFX} \
		schema_resolver_test.cpp

scan_handler : scan_handler.h scan_handler.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/scan_handler.${SUFX} scan_handler.cpp

xml_handler : xml_handler.h xml_handler.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_handler.${SUFX} xml_handler.cpp

xml_loader : xml_loader.h xml_loader.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_loader.${SUFX} xml_loader.cpp

xml_scanner : xml_scanner.h xml_scanner.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_scanner.${SUFX} xml_scanner.cpp

xml_term : xml_term.h xml_term.cpp
	g++ -c ${CXXOPT} -o ${BUILD}/xml_term.${SUFX} xml_term.cpp

qname_cache : qname_cache.h qname_cache.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/qname_cache.${SUFX} qname_cache.cpp

qname_cache_test : qname_cache.h qname_cache.cpp qname_cache_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/qname_cache_test \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/qname_cache.${SUFX} \
	qname_cache_test.cpp

itemstore : itemstore.h itemstore.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/itemstore.${SUFX} itemstore.cpp

itemstore_test : itemstore.h itemstore.cpp itemstore_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/itemstore_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/nodes.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/itemstore.${SUFX} \
	itemstore_test.cpp

xml_handler_test : xml_handler.h xml_handler.cpp xml_handler_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_handler_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../types/${BUILD}/node_types.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/scan_handler.${SUFX} \
		${BUILD}/xml_scanner.${SUFX} \
		${BUILD}/xml_handler.${SUFX} \
		${BUILD}/nodestore.${SUFX} \
		${BUILD}/namespace_pool.${SUFX} \
		${BUILD}/qname_pool.${SUFX} \
	xml_handler_test.cpp

all : \
	qname_cache \
	itemstore \
	uri_resolver \
	collation_resolver \
	collection_resolver \
	module_resolver \
	schema_resolver \
	xml_term \
	xml_scanner \
	xml_handler

test : \
	uri_resolver_test \
	xml_handler_test

