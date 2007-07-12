/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: sax_interface_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

  
#include "sax_interface.h"
#include <iostream>

using namespace std;
using namespace SAX;


int main(int argc, char* argv[])
{
	AttributesImpl a;
	a.addAttribute("uri", "localname", "qname", "type", "value", false, false);
	XMLReaderImpl d;
	XMLFilterImpl c(d);
	DefaultHandler e;
	LocatorImpl f("publicId","systemId",1,10,"encoding","XML version");
	SAXParseException g;
	XMLReaderImpl h;
	XMLFilterImpl j(h);
	AttributesImpl k;

}


