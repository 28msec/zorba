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
	namespace_pool nspool("data/nspool");
	vector<bool> errorv(10,false);

	int a0 = nspool.put(1,"pre0","http://this.is.my.uri-00/this/is/the/path/00");
	if (a0==-1) {
		cout << "put(\"pre0\",..) returned -1\n";
		errorv[0] = true;
	}
	int a1 = nspool.put(1,"pre1","http://this.is.my.uri-01/this/is/the/path/01");
	if (a0==-1) {
		cout << "put(\"pre1\",..) returned -1\n";
		errorv[1] = true;
	}
	int a2 = nspool.put(1,"pre2","http://this.is.my.uri-02/this/is/the/path/02");
	if (a0==-1) {
		cout << "put(\"pre2\",..) returned -1\n";
		errorv[2] = true;
	}
	int a3 = nspool.put(2,"pre0", "http://this.is.my.uri-03/this/is/the/path/03");
	if (a0==-1) {
		cout << "put(\"pre3\",..) returned -1\n";
		errorv[3] = true;
	}
	int a4 = nspool.put(2,"pre1", "http://this.is.my.uri-04/this/is/the/path/02");
	if (a0==-1) {
		cout << "put(\"pre4\",..) returned -1\n";
		errorv[4] = true;
	}
	int a5 = nspool.put(2,"pre2", "http://this.is.my.uri-05/this/is/the/path/04");
	if (a0==-1) {
		cout << "put(\"pre5\",..) returned -1\n";
		errorv[5] = true;
	}
	int a6 = nspool.put(3,"pre0", "http://this.is.my.uri-06/this/is/the/path/01");
	if (a0==-1) {
		cout << "put(\"pre6\",..) returned -1\n";
		errorv[6] = true;
	}
	int a7 = nspool.put(3,"pre1", "http://this.is.my.uri-07/this/is/the/path/07");
	if (a0==-1) {
		cout << "put(\"pre7\",..) returned -1\n";
		errorv[7] = true;
	}
	int a8 = nspool.put(3,"pre2", "http://this.is.my.uri-08/this/is/the/path/08");
	if (a0==-1) {
		cout << "put(\"pre8\",..) returned -1\n";
		errorv[8] = true;
	}
	int a9 = nspool.put(4,"pre0", "http://this.is.my.uri-09/this/is/the/path/09");
	if (a0==-1) {
		cout << "put(\"pre9\",..) returned -1\n";
		errorv[9] = true;
	}

	cout << "count = " << nspool.count() << endl;

	string prefix;
	string uri;

	if (!errorv[0]) {
		if (!nspool.get_uri(a0, uri)) {
			cout << "key [" << a0 << "] not found\n";
		} else {
			nspool.get_prefix(1,a0,prefix);
			cout << "key [" << a0 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[1]) {
		if (!nspool.get_uri(a1, uri)) {
			cout << "key [" << a1 << "] not found\n";
		} else {
			nspool.get_prefix(1,a1,prefix);
			cout << "key [" << a1 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[2]) {
		if (!nspool.get_uri(a2, uri)) {
			cout << "key [" << a2 << "] not found\n";
		} else {
			nspool.get_prefix(1,a2,prefix);
			cout << "key [" << a2 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[3]) {
		if (!nspool.get_uri(a3, uri)) {
			cout << "key [" << a3 << "] not found\n";
		} else {
			nspool.get_prefix(2,a3,prefix);
			cout << "key [" << a3 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[4]) {
		if (!nspool.get_uri(a4, uri)) {
			cout << "key [" << a4 << "] not found\n";
		} else {
			nspool.get_prefix(2,a4,prefix);
			cout << "key [" << a4 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[5]) {
		if (!nspool.get_uri(a5, uri)) {
			cout << "key [" << a5 << "] not found\n";
		} else {
			nspool.get_prefix(2,a5,prefix);
			cout << "key [" << a5 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[6]) {
		if (!nspool.get_uri(a6, uri)) {
			cout << "key [" << a6 << "] not found\n";
		} else {
			nspool.get_prefix(3,a6,prefix);
			cout << "key [" << a6 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[7]) {
		if (!nspool.get_uri(a7, uri)) {
			cout << "key [" << a7 << "] not found\n";
		} else {
			nspool.get_prefix(3,a7,prefix);
			cout << "key [" << a7 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[8]) {
		if (!nspool.get_uri(a8, uri)) {
			cout << "key [" << a8 << "] not found\n";
		} else {
			nspool.get_prefix(3,a8,prefix);
			cout << "key [" << a8 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}
	if (!errorv[9]) {
		if (!nspool.get_uri(a9, uri)) {
			cout << "key [" << a9 << "] not found\n";
		} else {
			nspool.get_prefix(4,a9,prefix);
			cout << "key [" << a9 << "] = (" << prefix << ", " << uri << ")\n";
		}
	}

}

