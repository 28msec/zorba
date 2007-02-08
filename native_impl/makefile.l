include ../Makefile.header
SUFX=do
BUILD=Build

qname_pool : qname_pool.h qname_pool.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/qname_pool.${SUFX} qname_pool.cpp

namespace_pool : namespace_pool.h namespace_pool.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/namespace_pool.${SUFX} namespace_pool.cpp

nodestore : nodestore.h nodestore.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/nodestore.${SUFX} nodestore.cpp

html_scanner : html_scanner.h html_scanner.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/html_scanner.${SUFX} html_scanner.cpp
	
scan_handler : scan_handler.h scan_handler.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/scan_handler.${SUFX} scan_handler.cpp
	
source : source.h source.cpp
	g++ -c ${CXXOPT} -o ${BUILD}/source.${SUFX} source.cpp

spectrum : spectrum.h spectrum.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/spectrum.${SUFX} spectrum.cpp

storage_manager : storage_manager.h storage_manager.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/storage_manager.${SUFX} storage_manager.cpp

unicode_decompositions : unicode_decompositions.h unicode_decompositions.cpp
	g++ -c ${CXXOPT} -o ${BUILD}/unicode_decompositions.${SUFX} unicode_decompositions.cpp

xml_handler : xml_handler.h xml_handler.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_handler.${SUFX} xml_handler.cpp

xml_loader : xml_loader.h xml_loader.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_loader.${SUFX} xml_loader.cpp

xml_scanner : xml_scanner.h xml_scanner.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_scanner.${SUFX} xml_scanner.cpp

xml_term : xml_term.h xml_term.cpp
	g++ -c ${CXXOPT} -o ${BUILD}/xml_term.${SUFX} xml_term.cpp

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
		../store/${BUILD}/xml_ostream.${SUFX} \
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

qname_pool_test : qname_pool.h qname_pool.cpp qname_pool_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/qname_pool_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../types/${BUILD}/node_types.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/nodestore.${SUFX} \
		${BUILD}/namespace_pool.${SUFX} \
		${BUILD}/qname_pool.${SUFX} \
	qname_pool_test.cpp

namespace_pool_test : namespace_pool.h namespace_pool.cpp namespace_pool_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/namespace_pool_test \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		${BUILD}/namespace_pool.${SUFX} \
	namespace_pool_test.cpp

nodestore_test : nodestore.h nodestore.cpp nodestore_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/nodestore_test \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		${BUILD}/namespace_pool.${SUFX} \
		${BUILD}/qname_pool.${SUFX} \
		${BUILD}/nodestore.${SUFX} \
	nodestore_test.cpp

spectrum_test : spectrum.h spectrum.cpp spectrum_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/spectrum_test \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		${BUILD}/spectrum.${SUFX} \
	spectrum_test.cpp

storage_manager_test : storage_manager.h storage_manager.cpp storage_manager_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/storage_manager_test \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		${BUILD}/scan_handler.${SUFX} \
		${BUILD}/storage_manager.${SUFX} \
		${BUILD}/spectrum.${SUFX} \
		${BUILD}/xml_scanner.${SUFX} \
	storage_manager_test.cpp

xml_loader_test : xml_loader.h xml_loader.cpp xml_loader_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_loader_test \
		../util/${BUILD}/xqp_exception.${SUFX} \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/mmfile.${SUFX} \
		../util/${BUILD}/fxcharheap.${SUFX} \
		../util/${BUILD}/URI.${SUFX} \
		../util/${BUILD}/tokenbuf.${SUFX} \
		../context/${BUILD}/context.${SUFX} \
		../runtime/${BUILD}/iterator.${SUFX} \
		../store/${BUILD}/xml_ostream.${SUFX} \
		../types/${BUILD}/base_types.${SUFX} \
		../types/${BUILD}/xs_primitive_types.${SUFX} \
		../values/${BUILD}/values.${SUFX} \
		../values/${BUILD}/node_values.${SUFX} \
		../values/${BUILD}/qname_value.${SUFX} \
		../values/${BUILD}/xs_primitive_values.${SUFX} \
		${BUILD}/nodestore.${SUFX} \
		${BUILD}/scan_handler.${SUFX} \
		${BUILD}/xml_loader.${SUFX} \
		${BUILD}/xml_scanner.${SUFX} \
		${BUILD}/xml_handler.${SUFX} \
	xml_loader_test.cpp

xml_scanner_test : xml_scanner.h xml_scanner.cpp xml_scanner_test.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o ${BUILD}/xml_scanner_test \
		../util/${BUILD}/file.${SUFX} \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/xml_scanner.${SUFX} \
		${BUILD}/scan_handler.${SUFX} \
	xml_scanner_test.cpp

xml_term_test : xml_term.h xml_term.cpp xml_term_test.cpp
	g++ ${CXXOPT} -o ${BUILD}/xml_term_test \
		../util/${BUILD}/xqp_exception.${SUFX} \
		${BUILD}/xml_term.${SUFX} \
	xml_term_test.cpp

all : \
	nodestore \
	html_scanner \
	scan_handler \
	source \
	spectrum \
	storage_manager \
	unicode_decompositions \
	xml_loader \
	xml_scanner \
	xml_term 

#xml_handler \

test : \
	nodestore_test \
	spectrum_test \
	storage_manager_test \
	xml_loader_test \
	xml_scanner_test \
	xml_term_test 

#xml_handler_test \


