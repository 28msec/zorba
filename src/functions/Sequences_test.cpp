/**
 * @file Sequences_test.cpp
 * @author Paul Pedersen
 * @copyright 2006-2007 FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 */

#include "Sequences.h"
#include "library.h"

#include "context/common.h"
#include "dom/dom_nodes.h"
#include "store/itemstore.h"
#include "util/tokenbuf.h"
#include "util/tracer.h"
#include "errors/xqp_exception.h"
#include "values/item.h"
#include "zorba/zorba_value_factory.h"

#include <iostream>
#include <typeinfo>


using namespace std;
using namespace xqp;


/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|
|_______________________________________________________________________*/

//15.1.1 fn:boolean
//15.1.2 op:concatenate
//15.1.3 fn:index-of
//15.1.4 fn:empty
//15.1.5 fn:exists
//15.1.6 fn:distinct-values
//15.1.7 fn:insert-before
//15.1.8 fn:remove
//15.1.9 fn:reverse
//15.1.10 fn:subsequence
//15.1.11 fn:unordered

/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
//15.2.2 fn:one-or-more
//15.2.3 fn:exactly-one

/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal
//15.3.2 op:union
//15.3.3 op:intersect
//15.3.4 op:except

/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count
//15.4.2 fn:avg
//15.4.3 fn:max
//15.4.4 fn:min
//15.4.5 fn:sum

/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to
//15.5.2 fn:id
//15.5.3 fn:idref



//15.5.4 fn:doc
//-------------
void _doc(
	zorba* zorp,
	string const& uri)
{
	dynamic_context* dctx_p = zorp->get_dynamic_context();
	value_factory* valfac_p = zorp->get_value_factory();
	assert(valfac_p!=NULL);
	rchandle<atomic_value> uri_h = valfac_p->make_xs_string(uri);
	vector<Iterator_t> argv;
	argv.push_back(new SingletonIterator(&*uri_h));
	const function* fn_doc_p = dctx_p->get_function(library::fn_doc_key);
	assert(fn_doc_p!=NULL);
	const function& fn_doc = *fn_doc_p;
	Iterator_t iter_h = fn_doc(zorp, argv);
	if (iter_h==NULL) { cout << "Error: doc returned NULL\n"; return; }
	iter_h->open();
	if (iter_h->done()) { cout << "Error: doc returned empty\n"; return; }
	Item_t i_h = iter_h->next();
	if (i_h->type()!=documentNode) { cout << "Error: non-doc node\n"; return; }
	cout << "\n======================\n";
	i_h->put(zorp,cout) << endl;
}



//15.5.5 fn:doc-available
//15.5.6 fn:collection



int main(int argc, char* argv[])
{

  try {
		zorba* zorp = new zorba();
		itemstore* istore = new itemstore();
		zorba_value_factory* factory = new zorba_value_factory();
		static_context* sctx_p   = new static_context(zorp,NULL);

		dynamic_context* dctx_p = new dynamic_context(zorp, NULL);
		library lib(zorp);
		dctx_p->set_library(&lib);
	
		zorp->set_data_manager(istore);
		zorp->set_value_factory(factory);
		zorp->set_static_context(sctx_p);
		zorp->set_dynamic_context(dctx_p);

    string cmdline, cmd, arg1, arg2, arg3;
    uint32_t arg_count = 0;

    while (true) {
      getline(cin, cmdline);
      if (cmdline.length()==0) continue;

      tokenbuf tokbuf(cmdline.c_str()," ");
      tokbuf.set_lowercase(false);
      tokbuf.set_return_delims(false);

      tokenbuf::token_iterator it = tokbuf.begin();
      tokenbuf::token_iterator end = tokbuf.end();

      cmd = *it;
      if (it!=end) { ++it; arg1 = *it; ++arg_count; }
      if (it!=end) { ++it; arg2 = *it; ++arg_count; }
      if (it!=end) { ++it; arg3 = *it; ++arg_count; }

      cout << "cmd = " << cmd << endl;
      if (arg_count>0) cout << "arg1 = " << arg1 << endl;
      if (arg_count>1) cout << "arg2 = " << arg2 << endl;
      if (arg_count>2) cout << "arg3 = " << arg3 << endl;

      if (cmd=="quit" || cmd=="exit") break;
      else if (cmd=="doc") _doc(zorp,arg1);

			errors::errcode err = zorp->get_error();
			if (err>0) {
				cout << cmd << ": error: " << errors::decode(err) << endl;
			}
		}
	} catch (xqp_exception& e) {
		cout << "application exception: " << e.what() << '\t' << e.get_msg() << endl;
	} catch (exception& e) {
		cout << "system exception: " << e.what() << endl;
	} catch (...) {
		cout << "Error" << endl;
	}

}

