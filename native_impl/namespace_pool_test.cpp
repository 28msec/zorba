/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: namespace_pool_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "namespace_pool.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	namespace_pool nspool("data");

	int a0 = nspool.put("pre0", "http://this.is.my.uri-00/this/is/the/path/00");
	if (a0==-1) {
		cout << "put(\"pre0\",..) returned -1\n";
	}
	int a1 = nspool.put("pre1", "http://this.is.my.uri-01/this/is/the/path/01");
	if (a0==-1) {
		cout << "put(\"pre1\",..) returned -1\n";
	}
	int a2 = nspool.put("pre2", "http://this.is.my.uri-02/this/is/the/path/02");
	if (a0==-1) {
		cout << "put(\"pre2\",..) returned -1\n";
	}
	int a3 = nspool.put("pre3", "http://this.is.my.uri-03/this/is/the/path/03");
	if (a0==-1) {
		cout << "put(\"pre3\",..) returned -1\n";
	}
	int a4 = nspool.put("pre4", "http://this.is.my.uri-04/this/is/the/path/04");
	if (a0==-1) {
		cout << "put(\"pre4\",..) returned -1\n";
	}
	int a5 = nspool.put("pre5", "http://this.is.my.uri-05/this/is/the/path/05");
	if (a0==-1) {
		cout << "put(\"pre5\",..) returned -1\n";
	}
	int a6 = nspool.put("pre6", "http://this.is.my.uri-06/this/is/the/path/06");
	if (a0==-1) {
		cout << "put(\"pre6\",..) returned -1\n";
	}
	int a7 = nspool.put("pre7", "http://this.is.my.uri-07/this/is/the/path/07");
	if (a0==-1) {
		cout << "put(\"pre7\",..) returned -1\n";
	}
	int a8 = nspool.put("pre8", "http://this.is.my.uri-08/this/is/the/path/08");
	if (a0==-1) {
		cout << "put(\"pre8\",..) returned -1\n";
	}
	int a9 = nspool.put("pre9", "http://this.is.my.uri-09/this/is/the/path/09");
	if (a0==-1) {
		cout << "put(\"pre9\",..) returned -1\n";
	}

	cout << "cout = " << nspool.count() << endl;

	string prefix;
	string uri;

	if (!nspool.get(a0, prefix, uri)) {
		cout << "key [" << a0 << "] not found\n";
	} else {
		cout << "key [" << a0 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a1, prefix, uri)) {
		cout << "key [" << a1 << "] not found\n";
	} else {
		cout << "key [" << a1 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a2, prefix, uri)) {
		cout << "key [" << a2 << "] not found\n";
	} else {
		cout << "key [" << a2 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a3, prefix, uri)) {
		cout << "key [" << a3 << "] not found\n";
	} else {
		cout << "key [" << a3 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a4, prefix, uri)) {
		cout << "key [" << a4 << "] not found\n";
	} else {
		cout << "key [" << a4 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a5, prefix, uri)) {
		cout << "key [" << a5 << "] not found\n";
	} else {
		cout << "key [" << a5 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a6, prefix, uri)) {
		cout << "key [" << a6 << "] not found\n";
	} else {
		cout << "key [" << a6 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a7, prefix, uri)) {
		cout << "key [" << a7 << "] not found\n";
	} else {
		cout << "key [" << a7 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a8, prefix, uri)) {
		cout << "key [" << a8 << "] not found\n";
	} else {
		cout << "key [" << a8 << "] = (" << prefix << ", " << uri << ")\n";
	}
	if (!nspool.get(a9, prefix, uri)) {
		cout << "key [" << a9 << "] not found\n";
	} else {
		cout << "key [" << a9 << "] = (" << prefix << ", " << uri << ")\n";
	}

}

