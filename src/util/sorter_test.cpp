/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "util/sorter.h"

#include <iostream>

using namespace std;
using namespace zorba;

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
