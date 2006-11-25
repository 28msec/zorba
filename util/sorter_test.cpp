/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: sorter_test.cpp,v 1.1 2006/10/11 00:01:33 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "sorter.h"

#include <iostream>

using namespace std;
using namespace xqp;

struct key_struct1
{
	uint32_t key;
	uint32_t val;

	key_struct1(
		uint32_t _key,
		uint32_t _val)
	:
		key(_key),
		val(_val)
	{
	}
	~key_struct1() {}
};


struct key_struct2
{
	float key;
	uint32_t val;

	key_struct2(
		float _key,
		uint32_t _val)
	:
		key(_key),
		val(_val)
	{
	}
	~key_struct2() {}
};


int main(int argc, char* argv[])
{
	try {
		vector<key_struct1> v;
		cout << "INPUT:\n";
		for (int k=1; k<=1111; ++k) {
			uint32_t key = k*67 % 1111;	// not quite random..
			cout << "(key,val) = (" << key << ',' << k << ")\n";
			v.push_back(key_struct1(key, k));
		}
		xqp::qsort(v,0,1110);
		cout << "\nOUTPUT:\n";
		vector<key_struct1>::const_iterator it1 = v.begin();
		for ( ; it1!=v.end(); ++it1) {
			cout << "(key,val) = (" << it1->key << ',' << it1->val << ")\n";
		}
		cout << "===========================================\n";


		vector<key_struct2> w;
		cout << "INPUT:\n";
		for (int k=0; k<1090; ++k) {
			uint32_t key = k*67 % 1090;	// not quite random..
			cout << "(key,val) = (" << key << ',' << k << ")\n";
			w.push_back(key_struct2((float)key/1000.0f, k));
		}
		xqp::qsort(w,0,1089);
		cout << "\nOUTPUT:\n";
		uint32_t minval = 1090;
		uint32_t maxval = 0;
		vector<key_struct2>::const_iterator it2 = w.begin();
		for ( ; it2!=w.end(); ++it2) {
			float key = it2->key;
			uint32_t val = it2->val;
			cout << "(key,val) = (" << key << ',' << val << ")\n";
			if (val < minval) minval = val;
			if (val > maxval) maxval = val;
		}
		cout << "Min val = " << minval << endl;
		cout << "Max val = " << maxval << endl;

	} catch (exception& e) {
		cout << "System exception: " << e.what() << endl;
	} catch (...) {
		cout << "Unhandled exception\n";
	}
}
