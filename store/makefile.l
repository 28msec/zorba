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

file_source : file_source.h file_source.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/file_source.${SUFX} file_source.cpp

uri_resolver :	uri_resolver.cpp uri_resolver.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/uri_resolver.${SUFX} uri_resolver.cpp

zorba_uri_resolver :	zorba_uri_resolver.cpp zorba_uri_resolver.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/zorba_uri_resolver.${SUFX} zorba_uri_resolver.cpp

zorba_uri_resolver_test :	zorba_uri_resolver_test.cpp zorba_uri_resolver.cpp zorba_uri_resolver.h uri_resolver.h 
	g++ ${OPT} -o ${BUILD}/uri_resolver_test \
    ../runtime/${BUILD}/zorba.${SUFX} \
    ../util/${BUILD}/xqp_exception.${SUFX} \
    ../util/${BUILD}/file.${SUFX} \
    ../util/${BUILD}/tokenbuf.${SUFX} \
    ../util/${BUILD}/URI.${SUFX} \
    ${BUILD}/uri_resolver.${SUFX} \
    ${BUILD}/zorba_uri_resolver.${SUFX} \
   zorba_uri_resolver_test.cpp

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

namepool : namepool.h namepool.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/namepool.${SUFX} namepool.cpp

itemstore : itemstore.h itemstore.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/itemstore.${SUFX} itemstore.cpp

xml_handler_test : xml_handler.h xml_handler.cpp xml_handler_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_handler_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/errors.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/sequence_type.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/nodes.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/scan_handler.${SUFX} \
		${BUILD}/xml_scanner.${SUFX} \
		${BUILD}/xml_handler.${SUFX} \
		${BUILD}/qname_cache.${SUFX} \
		${BUILD}/itemstore.${SUFX} \
	xml_handler_test.cpp


all : \
	file_source \
	itemstore \
	uri_resolver \
	collation_resolver \
	collection_resolver \
	module_resolver \
	schema_resolver \
	xml_term \
	scan_handler \
	xml_scanner

test : \
	uri_resolver_test \
	xml_handler_test
