/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "values.h"
#include "xs_primitive_values.h"

#include "../context/common.h"
#include "../store/itemstore.h"
#include "../util/tracer.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	itemstore istore("data/itemstore");
	fxvector<itemref_t>* refv_p;

	if (argc>1) {
		refv_p = new fxvector<itemref_t>(argv[1]);
	}
	else {
		refv_p = new fxvector<itemref_t>;
	}
	fxvector<itemref_t>& refv = *refv_p;

	if (refv.size()>0) {
		fxvector<itemref_t>::const_iterator it = refv.begin();
		for (; it!=refv.end(); ++it) {
			value* v_p = new(istore,*it) value();
			sequence_type_t type = v_p->type();
			cout	<< '['<<sequence_type::describe(type)<<"] ";

			switch (type) {
			case xs_qname: {
				qname_value* q_p = static_cast<qname_value*>(v_p);
				cout << q_p->prefix(istore) << ':' << q_p->localname(istore) << endl;
				break;
			}
			case textNode: {
				text_node* t_p = static_cast<text_node*>(v_p);
				cout << t_p->str(&ctx) << endl;
				break;
			}
			default: cout << "???";
			}

		}
		cout << "done\n";
		return 0;
	}

	// xs_string
	// ---------
	vector<item*> ptrv;
	ptrv.push_back(new(istore) xs_stringValue(istore,"name00001"));
	ptrv.push_back(new(istore) xs_stringValue(istore,"name00002"));
	ptrv.push_back(new(istore) xs_stringValue(istore,"name00003"));

	vector<item*>::const_iterator it = ptrv.begin();
	for (; it!=ptrv.end(); ++it) {
		xs_stringValue* s_p = static_cast<xs_stringValue*>(*it);
		cout	<< '[' << sequence_type::describe(s_p->type()) << "] "
					<< s_p->str() << endl;
	}
	
	// xs_double
	// ---------
	ptrv.clear();
	ptrv.push_back(new(istore) xs_doubleValue(1.0));
	ptrv.push_back(new(istore) xs_doubleValue(2.0));
	ptrv.push_back(new(istore) xs_doubleValue(3.0));

	it = ptrv.begin();
	for (; it!=ptrv.end(); ++it) {
		xs_doubleValue* d_p = static_cast<xs_doubleValue*>(*it);
		cout	<< '[' << sequence_type::describe(d_p->type()) << "] "
					<< d_p->val() << endl;
	}
	
	// xs_qname
	// --------
	vector<qnamekey_t> keyv;
	vector<itemref_t> itv;

	string name1 = "pre1:name000001";
	string name2 = "pre2:name000002";
	string name3 = "pre3:name000003";

	keyv.push_back(hashfun::h64(name1));
	itv.push_back(istore.eos());
	new(istore) xs_stringValue(istore,name1);

	keyv.push_back(hashfun::h64(name2));
	itv.push_back(istore.eos());
	new(istore) xs_stringValue(istore,name2);

	keyv.push_back(hashfun::h64(name3));
	itv.push_back(istore.eos());
	new(istore) xs_stringValue(istore,name3);

	ptrv.clear();
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) qname_value(istore,keyv[0],itv[0]));
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) qname_value(istore,keyv[1],itv[1]));
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) qname_value(istore,keyv[2],itv[2]));
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) qname_value(istore,keyv[0],itv[0]));
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) qname_value(istore,keyv[1],itv[1]));
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) qname_value(istore,keyv[2],itv[2]));

	it = ptrv.begin();
	for (; it!=ptrv.end(); ++it) {
		qname_value* q_p = static_cast<qname_value*>(*it);
		cout	<< '[' << sequence_type::describe(q_p->type()) << "] "
					<< q_p->prefix(istore) << ':'
					<< q_p->localname(istore) << endl;
	}

	// text nodes
	// ----------
	ptrv.clear();

	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) text_node(&ctx,"this is the first text block"));
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) text_node(&ctx,"this is the second text block"));
	refv.push_back(istore.eos());
	ptrv.push_back(new(istore) text_node(&ctx,"this is the third text block"));

	it = ptrv.begin();
	for (; it!=ptrv.end(); ++it) {
		text_node* t_p = static_cast<text_node*>(*it);
		cout << '[' << sequence_type::describe(t_p->type()) << "] ";
		cout << t_p->str(&ctx) << endl;
	}

	cout << "done\n";
	
}

