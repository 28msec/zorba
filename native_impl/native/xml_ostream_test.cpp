
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_ostream_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "xml_ostream.h"
#include <iostream>
#include "../../types/qname.h"
#include "../../util/xqpexception.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[]) 
{
	try {
		xml_ostream xos;

		xos << QName(QName::qn_elem,"test");
		xos << QName(QName::qn_attr,"attr-1");
		xos << "value-1";
		xos << QName(QName::qn_attr,"attr-2");
		xos << "value-2";
		xos << "Here is text node-1";
		xos << "Here is text node-2";
		xos << "Here is text node-3";

		xos.flush();

	} catch (xqpexception& e) {
		cout << "Application exception: " << e.get_msg() << endl;
	} catch (exception& e) {
		cout << "System exception: " << e.what() << endl;
	} catch (...) {
		cout << "Unrecognized exception: " << endl;
	}
}


