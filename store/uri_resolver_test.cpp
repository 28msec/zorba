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
  rchandle<source> src_h = res.resolve(base, url);
}


/* class uri_resolver:
string get_base(URI const&); 
string get_base(string const&); 
bool make_absolute( string const& base, string const& url, string& result);
bool make_absolute( URI const& base, URI const& url, string& result);
rchandle<source> resolve( string const& base, string const& uri);
rchandle<source> resolve( URI const& base, URI const& uri);
*/

