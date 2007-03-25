include ../Makefile.header
SUFX=do
BUILD=Build


dom_qname : dom_qname.h dom_qname.cpp
	g++ -c ${CXXOPT} -o ${BUILD}/dom_qname.${SUFX} dom_qname.cpp

dom_nodes : dom_nodes.h dom_nodes.cpp
	g++ -c ${CXXOPT} -o ${BUILD}/dom_nodes.${SUFX} dom_nodes.cpp

dom_iterator : dom_iterator.h dom_iterator.cpp
	g++ -c ${CXXOPT} -o ${BUILD}/dom_iterator.${SUFX} dom_iterator.cpp

dom_namepool : dom_namepool.h dom_namepool.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/dom_namepool.${SUFX} dom_namepool.cpp

dom_xml_handler : dom_xml_handler.h dom_xml_handler.cpp
	g++ -c ${LARGEFILES} ${CXXOPT} -o ${BUILD}/dom_xml_handler.${SUFX} dom_xml_handler.cpp


all : \
	dom_qname \
	dom_nodes \
	dom_iterator \
	dom_namepool \
	dom_xml_handler


test : \
	dom_qname_test \
	dom_nodes_test

