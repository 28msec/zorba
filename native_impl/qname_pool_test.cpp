/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_pool_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "qname_pool.h"
#include "namespace_pool.h"
#include "../context/context.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	rchandle<namespace_pool> nspool_h = new namespace_pool("data/nspool");
	qname_pool qnpool("data/qnpool", nspool_h);
	context ctx;

	int a0 = nspool_h->put(1,"pre0","http://this.is.my.uri-00/this/is/the/path/00");
	if (a0==-1) { cout << "put(\"pre0\",..) returned -1\n"; return -1; }
	int a1 = nspool_h->put(1,"pre1","http://this.is.my.uri-01/this/is/the/path/01");
	if (a1==-1) { cout << "put(\"pre1\",..) returned -1\n"; return -1; }
	int a2 = nspool_h->put(1,"pre2","http://this.is.my.uri-02/this/is/the/path/02");
	if (a2==-1) { cout << "put(\"pre2\",..) returned -1\n"; return -1; }
	int a3 = nspool_h->put(2,"pre0", "http://this.is.my.uri-03/this/is/the/path/03");
	if (a3==-1) { cout << "put(\"pre0\",..) returned -1\n"; return -1; }
	int a4 = nspool_h->put(2,"pre1", "http://this.is.my.uri-04/this/is/the/path/02");
	if (a4==-1) { cout << "put(\"pre1\",..) returned -1\n"; return -1; }
	int a5 = nspool_h->put(2,"pre2", "http://this.is.my.uri-05/this/is/the/path/04");
	if (a5==-1) { cout << "put(\"pre2\",..) returned -1\n"; return -1; }

	cout << "count = " << nspool_h->count() << endl;

	string prefix;
	string uri;
	uint32_t q1=0,q2=0,q3=0,q4=0,q5=0,q6=0;

	try { q1 = qnpool.put(1,QName::qn_elem,"pre0:elem1"); }
	catch (bad_arg) { cout << "put(\"pre0:elem1)\",..) failed\n"; }
	try { q2 = qnpool.put(1,QName::qn_elem,"pre0:elem2"); }
	catch (bad_arg) { cout << "put(\"pre0:elem2)\",..) failed\n"; }
	try { q3 = qnpool.put(1,QName::qn_elem,"pre0:elem3"); }
	catch (bad_arg) { cout << "put(\"pre0:elem3)\",..) failed\n"; }
	try { q4 = qnpool.put(2,QName::qn_elem,"pre1:elem1"); }
	catch (bad_arg) { cout << "put(\"pre1:elem1)\",..) failed\n"; }
	try { q5 = qnpool.put(2,QName::qn_elem,"pre1:elem2"); }
	catch (bad_arg) { cout << "put(\"pre1:elem2)\",..) failed\n"; }
	try { q6 = qnpool.put(2,QName::qn_elem,"pre1:elem3"); }
	catch (bad_arg) { cout << "put(\"pre1:elem3)\",..) failed\n"; }

	rchandle<QName> qn1_h, qn2_h, qn3_h, qn4_h, qn5_h, qn6_h;

	if ((qn1_h = qnpool.get(q1))==NULL) {
		cout <<"key ["<<q1<<"] not found\n";
	} else {
		qn1_h->put(cout,&ctx) << endl;
	}
	if ((qn2_h = qnpool.get(q2))==NULL) {
		cout <<"key ["<<q2<<"] not found\n";
	} else {
		qn2_h->put(cout,&ctx) << endl;
	}
	if ((qn3_h = qnpool.get(q3))==NULL) {
		cout <<"key ["<<q3<<"] not found\n";
	} else {
		qn3_h->put(cout,&ctx) << endl;
	}
	if ((qn4_h = qnpool.get(q4))==NULL) {
		cout <<"key ["<<q4<<"] not found\n";
	} else {
		qn4_h->put(cout,&ctx) << endl;
	}
	if ((qn5_h = qnpool.get(q5))==NULL) {
		cout <<"key ["<<q5<< "] not found\n";
	} else {
		qn5_h->put(cout,&ctx) << endl;
	}
	if ((qn6_h = qnpool.get(q6))==NULL) {
		cout <<"key ["<<q6<<"] not found\n";
	} else {
		qn6_h->put(cout,&ctx) << endl;
	}

}

