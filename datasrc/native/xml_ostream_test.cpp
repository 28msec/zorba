
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
		xml_ostream xmlss;

		xmlss << (bool) 1;
		xmlss << (int16_t) 2;
		xmlss << (uint16_t) 3;
		xmlss << (int32_t) 4;
		xmlss << (uint32_t) 5;
		xmlss << (int64_t) 6;
		xmlss << (uint64_t) 7;
		xmlss << (float) 8;
		xmlss << (double) 9;
		xmlss << QName(QName::qn_attr,"xqp","test");
		xmlss.flush();
/*
	friend xml_ostream& operator<<(xml_ostream& os, char ch);
	friend xml_ostream& operator<<(xml_ostream& os, signed char ch);
	friend xml_ostream& operator<<(xml_ostream& os, unsigned char ch);
	friend xml_ostream& operator<<(xml_ostream& os, const char* str);
	friend xml_ostream& operator<<(xml_ostream& os, const signed char* str);
	friend xml_ostream& operator<<(xml_ostream& os, const unsigned char* str);
*/

	} catch (xqpexception& e) {
		cout << "Application exception: " << e.get_msg() << endl;
	} catch (exception& e) {
		cout << "System exception: " << e.what() << endl;
	} catch (...) {
		cout << "Unrecognized exception: " << endl;
	}
}


