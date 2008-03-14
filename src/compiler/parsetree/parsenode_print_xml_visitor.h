#ifndef ZORBA_PARSENODE_PRINT_XML_VISITOR_H
#define ZORBA_PARSENODE_PRINT_XML_VISITOR_H

#include <iostream>
#include <ostream>
/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (const 2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace zorba {

  void print_parsetree_xml (std::ostream &, parsenode *p);

} // namespace

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
