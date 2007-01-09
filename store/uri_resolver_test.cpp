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
#include <iostream>
#include <string>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	uri_resolver res;
	string base(argv[1]);
	string url(argv[2]);
  string result;
  res.resolve(base, url, result);
	cout << result << endl;
}


