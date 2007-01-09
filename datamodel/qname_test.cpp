/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "qname.h"
#include <iostream>
#include "../util/xqpexception.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[]) 
{
	try {
		QName q1(QName::qn_attr,"xqp","test1");
		QName q2(QName::qn_elem,"xqp:test2");
		QName q3(QName::qn_func);

		cout << "test1.prefix = " << q1.get_prefix() << endl;
		cout << "test1.name = " << q1.get_name() << endl;
		cout << "test2.prefix = " << q2.get_prefix() << endl;
		cout << "test2.name = " << q2.get_name() << endl;
		cout << "test3.prefix = " << q3.get_prefix() << endl;
		cout << "test3.name = " << q3.get_name() << endl;
		
		q1.put(cout); cout << endl;
		q2.put(cout); cout << endl;
		q3.put(cout); cout << endl;

	} catch (xqpexception& e) {
		cout << "Application exception: " << e.get_msg() << endl;
	} catch (exception& e) {
		cout << "System exception: " << e.what() << endl;
	} catch (...) {
		cout << "Unrecognized exception: " << endl;
	}
}


