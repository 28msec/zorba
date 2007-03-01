/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: hashfun_test.cpp,v 1.1 2006/10/09 07:07:54 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *	Author: Paul Pedersen
 *
 */

#include "hashfun.h"

#include <iostream>
#include <string>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	string line;
	unsigned key = 0;
	while (!cin.eof()) {
		getline(cin, line);
		key = hashfun::h32(line);
		cout << "h(" << line << ") = " << key << endl;
		uint64_t key1 = hashfun::h64(line);
		cout << "h64(" << line << ") = " << key1 << endl;
		uint64_t key2 = hashfun::h64(line);
		cout << "h64(" << line << ") = " << key2 << endl;
		uint32_t key3 = (uint32_t)key2;
		cout << "(unsigned)h64(" << line << ") = " << key3 << endl;
	}
}
