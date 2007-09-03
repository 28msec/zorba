/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: qname_cache_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "qname_cache.h"
#include "../util/hashfun.h"
#include "../util/tracer.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	char* blobstore = new char[1<<16];
	uint32_t eos = 0;
	uint32_t eos0;
	qname_cache qncache("data/qncache");
	cout << TRACE << ": qncache allocated\n";

	char uri0[] = "http://this.is.my.uri-00/this/is/the/path/00";
	char uri1[] = "http://this.is.my.uri-01/this/is/the/path/01";
	char uri2[] = "http://this.is.my.uri-02/this/is/the/path/02";
	char uri3[] = "http://this.is.my.uri-03/this/is/the/path/03";
	char uri4[] = "http://this.is.my.uri-04/this/is/the/path/04";
	cout << TRACE << ": URIs allocated\n";

	eos0 = eos; eos = qncache.put(uri0, "pre0", "name0", blobstore, eos);
	cout << &blobstore[eos0] << endl;
	eos0 = eos; eos = qncache.put(uri1, "pre1", "name1", blobstore, eos);
	cout << &blobstore[eos0] << endl;
	eos0 = eos; eos = qncache.put(uri2, "pre2", "name2", blobstore, eos);
	cout << &blobstore[eos0] << endl;
	eos0 = eos; eos = qncache.put(uri3, "pre3", "name3", blobstore, eos);
	cout << &blobstore[eos0] << endl;
	eos0 = eos; eos = qncache.put(uri4, "pre4", "name4", blobstore, eos);
	cout << &blobstore[eos0] << endl;
	cout << TRACE << ": QNames stored:\n";

	qnamekey_t qnkey0 = qncache.get("pre0","name0");
	itemref_t qnref0 = qncache.get_qname(qnkey0);
	cout << "qn0 = [" << &blobstore[qnref0];
	qnref0 += (strlen(&blobstore[qnref0]) + 1);
	cout << "] " << &blobstore[qnref0];
	qnref0 += (strlen(&blobstore[qnref0]) + 1);
	cout << ":" << &blobstore[qnref0] << endl;

	qnamekey_t qnkey1 = qncache.get("pre1","name1");
	itemref_t qnref1 = qncache.get_qname(qnkey1);
	cout << "qn1 = [" << &blobstore[qnref1];
	qnref1 += (strlen(&blobstore[qnref1]) + 1);
	cout << "] " << &blobstore[qnref1];
	qnref1 += (strlen(&blobstore[qnref1]) + 1);
	cout << ":" << &blobstore[qnref1] << endl;

	qnamekey_t qnkey2 = qncache.get("pre2","name2");
	itemref_t qnref2 = qncache.get_qname(qnkey2);
	cout << "qn2 = [" << &blobstore[qnref2];
	qnref2 += (strlen(&blobstore[qnref2]) + 1);
	cout << "] " << &blobstore[qnref2];
	qnref2 += (strlen(&blobstore[qnref2]) + 1);
	cout << ":" << &blobstore[qnref2] << endl;

	qnamekey_t qnkey3 = qncache.get("pre3","name3");
	itemref_t qnref3 = qncache.get_qname(qnkey3);
	cout << "qn3 = [" << &blobstore[qnref3];
	qnref3 += (strlen(&blobstore[qnref3]) + 1);
	cout << "] " << &blobstore[qnref3];
	qnref3 += (strlen(&blobstore[qnref3]) + 1);
	cout << ":" << &blobstore[qnref3] << endl;

	qnamekey_t qnkey4 = qncache.get("pre4","name4");
	itemref_t qnref4 = qncache.get_qname(qnkey4);
	cout << "qn4 = [" << &blobstore[qnref4];
	qnref4 += (strlen(&blobstore[qnref4]) + 1);
	cout << "] " << &blobstore[qnref4];
	qnref4 += (strlen(&blobstore[qnref4]) + 1);
	cout << ":" << &blobstore[qnref4] << endl;

}

