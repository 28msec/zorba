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
#include "util/list.h"

#include <iostream>

using namespace std;
using namespace zorba;

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

