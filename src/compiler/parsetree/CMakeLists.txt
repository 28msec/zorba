SET(PARSETREE_SRCS
    parsenode_print_dot_visitor.cpp parsenode_print_xml_visitor.cpp parsenodes.cpp)
    

ADD_LIBRARY(parsetree ${PARSETREE_SRCS})
