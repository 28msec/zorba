/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: context_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "context.h"
#include <typeinfo>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	try {
		context ctx;
		rchandle<QName> var1_h = new QName(QName::qn_var, "var1");
		rchandle<QName> var2_h = new QName(QName::qn_var, "var2");
		rchandle<QName> var3_h = new QName(QName::qn_var, "var3");

		rchandle<item_iterator> it1_h = new singleton_iterator(ctx,"value-1");
		rchandle<item_iterator> it2_h = new singleton_iterator(ctx,"value-2");
		rchandle<item_iterator> it3_h = new singleton_iterator(ctx,"value-3");

		rchandle<var_binding> vb_h = new var_binding(var1_h, it1_h, item_type());
		vb_h->get_qname()->put(cout,ctx) << endl;

		ctx.push_var(vb_h);

		rchandle<item_iterator> it_h = ctx.get_var_value(vb_h->get_qname());
		item_iterator* it_p = &*it_h;

		if (it_p==NULL) {
			cout << "it_p==NULL, bailing\n";
			exit(-1);
		}
		while (!(it_p->done())) {
			it_p->next()->put(cout,ctx) << endl;
		}

	} catch (exception& e) {
		cout << "exception: " << e.what() << endl;
	} catch (...) {
		cout << "...\n";
	}
}
