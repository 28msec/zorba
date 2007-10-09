/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: list_test.cpp 1 2006-08-31 07:31:37Z paul $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 *	Author: Paul Pedersen
 *
 */

#include "list.h"

#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{

	list<int>* l_p = new list<int>;
	for (uint32_t i = 0; i<50; ++i) {
		l_p->push_back(2*i);
	}

	cout << "l_p->size() = " << l_p->size() << endl;
	list_iterator<int> it  = l_p->begin();
	list_iterator<int> end = l_p->end();
	for ( ; it!=end; ++it) { cout << *it << endl; }

	it  = l_p->begin();
	end = l_p->end();
	for (uint32_t i = 0; i<50 && it!=end; ++i,++it,++it) {
		l_p->insert_after(it.get_curr(), new list_node<int>(2*i+1,NULL,NULL));
	}

	cout << "l_p->size() = " << l_p->size() << endl;
	it  = l_p->begin();
	end = l_p->end();
	for ( ; it!=end; ++it) { cout << *it << endl; }

	for (uint32_t i = 0; i<50; ++i) {
		l_p->push_front(3*i);
	}

	cout << "l_p->size() = " << l_p->size() << endl;
	it  = l_p->begin();
	end = l_p->end();
	for ( ; it!=end; ++it) { cout << *it << endl; }

	list_reverse_iterator<int> r_it  = l_p->rbegin();
	list_reverse_iterator<int> r_end = l_p->rend();
	for ( ; r_it!=r_end; ++r_it) { cout << *r_it << endl; }

	for (int i=0; i<150; ++i) {
		cout << "l["<<i<<"] = " << (*l_p)[i] << endl;
	}

	delete l_p;

	l_p = new list<int>;
	l_p->push_front(10);
	cout << "l[0] = " << (*l_p)[0] << endl;

	delete l_p;

}

