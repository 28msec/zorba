/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: list_test.cpp 1 2006-08-31 07:31:37Z paul $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "list.h"

#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{

	list<int> l;
	for (uint32_t i = 0; i<50; ++i) {
		l.push_back(2*i);
	}

	cout << "l.size() = " << l.size() << endl;
	list_iterator<int> it  = l.begin();
	list_iterator<int> end = l.end();
	for ( ; it!=end; ++it) { cout << *it << endl; }

	it  = l.begin();
	end = l.end();
	for (uint32_t i = 0; i<50 && it!=end; ++i,++it,++it) {
		l.insert_after(it.get_curr(), new list_node<int>(2*i+1,NULL,NULL));
	}

	cout << "l.size() = " << l.size() << endl;
	it  = l.begin();
	end = l.end();
	for ( ; it!=end; ++it) { cout << *it << endl; }

}

