/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_term_test.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "xml_term.h"
#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	xml_term ife1("unit",1,1,"span");			cout << ife1.to_string() << endl;
	xml_term ife2("testing",1,2,"div");		cout << ife2.to_string() << endl;
	xml_term ife3("xml_term",1,3,"font");	cout << ife3.to_string() << endl;
	xml_term ife4("module",1,4,"td");			cout << ife4.to_string() << endl;
	xml_term ife5("appears",1,4,"b");			cout << ife5.to_string() << endl;
	xml_term ife6("to",1,4,"i");					cout << ife6.to_string() << endl;
	xml_term ife7("be",1,4,"table");			cout << ife7.to_string() << endl;
	xml_term ife8("OK",1,4,"title");			cout << ife8.to_string() << endl;
}
