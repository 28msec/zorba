include ../Makefile.header
SUFX=do

dom_qname : dom_qname.h dom_qname.cpp
	g++ -c ${CXXOPT} -o Build/dom_qname.${SUFX} dom_qname.cpp

dom_nodes : dom_nodes.h dom_nodes.cpp
	g++ -c ${CXXOPT} -o Build/dom_nodes.${SUFX} dom_nodes.cpp

dom_namepool : dom_namepool.h dom_namepool.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o Build/dom_namepool.${SUFX} dom_namepool.cpp

dom_xml_handler : dom_xml_handler.h dom_xml_handler.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o Build/dom_xml_handler.${SUFX} dom_xml_handler.cpp

dom_xml_handler_test : dom_xml_handler_test.cpp dom_xml_handler.h dom_xml_handler.cpp
	g++ ${LARGEFILES} ${CXXOPT} -o Build/dom_xml_handler_test \
		../runtime/Build/errors.${SUFX} \
		../runtime/Build/item_iterator.${SUFX} \
		../runtime/Build/zorba.${SUFX} \
		../store/Build/itemstore.${SUFX} \
		../store/Build/scan_handler.${SUFX} \
		../store/Build/xml_scanner.${SUFX} \
		../util/Build/file.${SUFX} \
		../util/Build/mmfile.${SUFX} \
		../util/Build/fxcharheap.${SUFX} \
		../util/Build/xqp_exception.${SUFX} \
		../zorba/Build/qnamerep.${SUFX} \
		../values/Build/primitive_values.${SUFX} \
		Build/dom_qname.${SUFX} \
		Build/dom_namepool.${SUFX} \
		Build/dom_nodes.${SUFX} \
		Build/dom_xml_handler.${SUFX} \
		dom_xml_handler_test.cpp

all : \
	dom_qname \
	dom_nodes \
	dom_namepool \
	dom_xml_handler


test : \
	dom_qname_test \
	dom_nodes_test

