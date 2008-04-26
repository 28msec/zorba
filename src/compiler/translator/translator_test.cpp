#include "compiler/translator/translator.h"
#include "compiler/parser/xquery_driver.h"
#include <iostream>

using namespace std;
using namespace zorba;

int main(int argc, char* argv[])
{
	zorba* zorp = new zorba();
	static_context* sctx_p   = new static_context(zorp,NULL);
	dynamic_context* dctx_p = new dynamic_context(zorp, NULL);

	library lib(zorp);
	dctx_p->set_library(&lib);

	zorp->set_static_context(sctx_p);
	zorp->set_dynamic_context(dctx_p);

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
				n_p->put(cout) << endl;
	
				translator nvs(zorp);
				MainModule* mm_p;
				QueryBody* qb_p;
				Expr* ex_p;
	
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

				ex_p->accept(nvs);
				rchandle<expr> e_h = nvs.pop_nodestack();

				cout << endl;

				if (e_h==NULL) {
					cout << "e_h==NULL\n";
				}
				else {
					e_h->put(zorp,cout) << endl;
				}
			}
		}
	} catch (xqp_exception & e) {
		cout << "application exception: " << e.get_msg() << " - " << e.what() << endl;
	} catch (...) {
		cout << "catch all exception\n";
	}
}

