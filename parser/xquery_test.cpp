/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xquery_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include <iostream>
#include "xquery_driver.h"
     
int main (int argc, char *argv[])
{
	xquery_driver driver(cout);
	for (++argv; argv[0]; ++argv) {
		if (*argv == std::string("-p")) {
			driver.trace_parsing = true;
		}
		else if (*argv == std::string ("-s")) {
			driver.trace_scanning = true;
		}
		else {
			driver.parse(*argv);
			std::cout << *driver.get_expr() << std::endl;
		}
	}
}
