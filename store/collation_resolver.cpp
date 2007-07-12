/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collation_resolver.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: Paul Pedersen
 *
 */


#include "collation_resolver.h"

using namespace std;
namespace xqp {

void test()
{
	collation_resolver<string> coll;
	rchandle<comparator<string> > comp = coll.resolve("foo");
}

} /* namespace xqp */

