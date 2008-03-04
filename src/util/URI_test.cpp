/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: URI_test.cpp,v 1.1 2006/10/09 07:07:50 Paul Pedersen Exp $
 *
 *  Copyright 2005-2006 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "util/URI.h"

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
using namespace zorba;

int main(int argc, char* argv[])
{
  string input;
  while (!cin.eof()) {
    getline(cin, input);
		URI uri(input);
		cout << "scheme:      " << uri.get_scheme() << endl;
		cout << "hostinfo:    " << uri.get_hostinfo() << endl;
		cout << "user:        " << uri.get_user() << endl;
		cout << "password:    " << uri.get_password() << endl;
		cout << "hostname:    " << uri.get_hostname() << endl;
		cout << "port_str:    " << uri.get_port_str() << endl;
		cout << "hostandport: " << uri.get_hostandport() << endl;
		cout << "path:        " << uri.get_path() << endl;
		cout << "query:       " << uri.get_query() << endl;
		cout << "fragment:    " << uri.get_fragment() << endl;
  }
}
