/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author John Cowan,Paul Pedersen (pcp071098@yahoo.com)
 * @file context/context_test.cpp
 *
 */

#include "context/context.h"
#include <typeinfo>

using namespace std;
using namespace zorba;

int main(int argc, char* argv[])
{
	try {
		context ctx;
		rchandle<QName> var1_h = new QName("var1");
		rchandle<QName> var2_h = new QName("var2");
		rchandle<QName> var3_h = new QName("var3");

		rchandle<item_iterator> it1_h = new SingletonIterator(&ctx,string("value-1"));
		rchandle<item_iterator> it2_h = new SingletonIterator(&ctx,string("value-2"));
		rchandle<item_iterator> it3_h = new SingletonIterator(&ctx,string("value-3"));

		// var 1
		rchandle<var_binding> vb1_h = new var_binding(var1_h, it1_h, item_type());
		ctx.push_var(vb1_h);
		rchandle<item_iterator> itv1_h = ctx.get_var_value(vb1_h->get_qname());
		item_iterator* itv1_p = &*itv1_h;
		if (itv1_p==NULL) {
			cout << "itv1_p==NULL, bailing\n";
			exit(-1);
		}
		vb1_h->get_qname()->put(cout,&ctx) << " = ";
		while (!(itv1_p->done())) { 
			itv1_p->next()->put(cout,&ctx) << endl;
		}

		// var 2
		rchandle<var_binding> vb2_h = new var_binding(var2_h, it2_h, item_type());
		ctx.push_var(vb2_h);
		rchandle<item_iterator> itv2_h = ctx.get_var_value(vb2_h->get_qname());
		item_iterator* itv2_p = &*itv2_h;
		if (itv2_p==NULL) {
			cout << "itv2_p==NULL, bailing\n";
			exit(-1);
		}
		vb2_h->get_qname()->put(cout,&ctx) << " = ";
		while (!(itv2_p->done())) {
			itv2_p->next()->put(cout,&ctx) << endl;
		}

		// shadow var1
		rchandle<var_binding> vb3_h = new var_binding(var1_h, it3_h, item_type());
		ctx.push_var(vb3_h);
		rchandle<item_iterator> itv3_h = ctx.get_var_value(vb3_h->get_qname());
		item_iterator* itv3_p = &*itv3_h;
		if (itv3_p==NULL) {
			cout << "itv3_p==NULL, bailing\n";
			exit(-1);
		}
		vb3_h->get_qname()->put(cout,&ctx) << " = ";
		while (!(itv3_p->done())) {
			itv3_p->next()->put(cout,&ctx) << endl;
		}

	} catch (exception& e) {
		cout << "exception: " << e.what() << endl;
	} catch (...) {
		cout << "...\n";
	}
}
