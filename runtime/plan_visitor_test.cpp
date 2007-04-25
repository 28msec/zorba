/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: plan_visitor_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "plan_visitor.h"
#include "../exprtree/normalize_visitor.h"
#include "../parser/xquery_driver.h"
#include <iostream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	context ctx;
	xquery_driver driver(cout);

	try {

		for (++argv; argv[0]; ++argv) {
			if (*argv == std::string("-p")) {
				driver.trace_parsing = true;
			}
			else if (*argv == std::string ("-s")) {
				driver.trace_scanning = true;
			}
			else {
				driver.parse(*argv);
				parsenode* n_p = driver.get_expr();
				cout << endl;
				cout << "Parse tree:\n";
				n_p->put(cout) << endl;
	
				normalize_visitor normvs(&ctx);
				MainModule * mm_p;
				QueryBody * qb_p;
				Expr * ex_p;
	
				if ((mm_p = dynamic_cast<MainModule*>(n_p))==NULL) {
					cout << "Parse error: expecting MainModule\n";
					return -1;
				}
				if ((qb_p = dynamic_cast<QueryBody*>(&*mm_p->get_query_body()))==NULL) {
					cout << "Parse error: expecting MainModule->QueryBody\n";
					return -1;
				}
				if ((ex_p = dynamic_cast<Expr*>(&*qb_p->get_expr()))==NULL) {
					cout << "Parse error: expecting MainModule->QueryBody->Expr\n";
					return -1;
				}

				cout << "Normalization run:\n";
				ex_p->accept(normvs);
				rchandle<expr> e_h = normvs.pop_nodestack();

				cout << endl;
				cout << "Normalized expression tree:\n";
				if (e_h==NULL) {
					cout << "e_h==NULL\n";
					return -1;
				}
				e_h->put(cout,ctx) << endl;

				cout << "Plan run:\n";
				plan_visitor planvs(&ctx);
				e_h->accept(planvs);
				rchandle<item_iterator> it_h = planvs.pop_itstack();

				cout << endl;
				cout << "Iterator run:\n";
				if (it_h==NULL) {
					cout << "it_h==NULL\n";
					return -1;
				}

				it_h->open();
				while (!it_h->done()) {
					item* i_p = it_h->next();
					if (i_p==NULL) continue;
					i_p->put(cout,&ctx) << endl;
				}
				it_h->close();
			}
		}
	} catch (xqp_exception & e) {
		cout << "application exception: " << e.get_msg() << " - " << e.what() << endl;
	} catch (...) {
		cout << "catch all exception\n";
	}
}

