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

xml_ostream :	xml_ostream.cpp xml_ostream.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/xml_ostream.${SUFX} xml_ostream.cpp
xml_ostream_test :	xml_ostream_test.cpp xml_ostream.cpp xml_ostream.h
	g++ ${LARGEFILEFLAGS} -D DEBUG -Wall ${OPT} -o ${BUILD}/xml_ostream_test \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/xml_ostream.${SUFX} \
		xml_ostream_test.cpp


xml_istream :	xml_istream.cpp xml_istream.h 
	g++ -Wall -c ${OPT} -o ${BUILD}/xml_istream.${SUFX} xml_istream.cpp
xml_istream_test :	xml_istream_test.cpp xml_istream.cpp xml_istream.h
	g++ ${LARGEFILEFLAGS} -D DEBUG -Wall ${OPT} -o ${BUILD}/xml_istream_test \
  ../util/${BUILD}/xqp_exception.${SUFX} \
  ../values/${BUILD}/qname_value.${SUFX} \
  ${BUILD}/xml_istream.${SUFX} \
  xml_istream_test.cpp


all : \
	uri_resolver \
	collation_resolver \
	collection_resolver \
	module_resolver \
	schema_resolver \
	xml_ostream \
	xml_istream 

test : \
	uri_resolver_test \
	xml_ostream_test 

