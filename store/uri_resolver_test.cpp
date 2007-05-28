/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: uri_resolver_test.cpp 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "uri_resolver.h"
#include "runtime/zorba.h"

#include <iostream>
#include <string>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	zorba* zorp = new zorba();
	uri_resolver res;
	string base(argv[1]);
	string url(argv[2]);
  string result;
  rchandle<source> src_h = res.resolve(base, url);
	istream* is_p = src_h->get_input(zorp);
	assert(is_p!=NULL);
	istream& is = *is_p;
	string line;
	while (true) {
		getline(is,line);
		if (line.length()==0) break;
		cout << line << endl;
	}
}



