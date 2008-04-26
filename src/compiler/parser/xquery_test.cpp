#include "compiler/parser/xquery_driver.h"
#include <iostream>
     
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
			driver.get_expr()->put(cout) << std::endl;
		}
	}
}
