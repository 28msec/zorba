/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: Sequences_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "Sequences.h"

#include "../context/common.h"
#include "../dom/dom_values.h"
#include "../dom/dom_nodes.h"
#include "../util/tokenbuf.h"
#include "../util/tracer.h"
#include "../util/xqp_exception.h"

#include <iostream>
#include <typeinfo>


using namespace std;
using namespace xqp;

// debugging
uint32_t qname_buf[1<<16];
uint32_t eos = 0;

qname_value* fn_doc_fname_p;
fn_doc fn_doc_(signature(fn_doc_fname_p,xs_string,documentNode));

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
	vector<iterator_t> argv;
	xs_stringValue* uri_p = zorp->get_value_factory()->make_xs_string(uri);
	argv.push_back(new singleton_iterator(uri_p));
	iterator_t it = fn_doc_(zorp, argv);
	cout << TRACE << " : fn_doc_ returned" << endl;
	if (it==NULL) { cout << "Error: doc returned NULL\n"; return; }
	cout << TRACE << " : fn_doc_ returned non-NULL" << endl;
	if (it->done()) { cout << "Error: doc returned empty\n"; return; }
	cout << TRACE << " : fn_doc_ returned non-empty" << endl;

	//item* i_p = (item*)it->next();
	//cout << TRACE << " : item type = " << typeid(*i_p).name() << endl;
	//if (i_p->type()!=documentNode) { cout << "Error: non-doc node\n"; return; }
	//cout << TRACE << " : item has document node type" << endl;

	dom_document_node* dn_p = (dom_document_node*)it->next();
	cout << TRACE << " : cast item as document node" << endl;
	if (dn_p==NULL) { cout << TRACE << " : dn_p==NULL" << endl; return; }
	cout << "\n======================\n"; dn_p->put(cout) << endl;
}



//15.5.5 fn:doc-available
//15.5.6 fn:collection



void init()
{
	fn_doc_fname_p = new(&qname_buf[eos]) qname_value(XQUERY_FN,"fn","doc");
	eos += fn_doc_fname_p->length();
}


int main(int argc, char* argv[])
{
  try {
    string cmdline, cmd, arg1, arg2, arg3;
    uint32_t arg_count = 0;
		zorba zor;

		init();

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
      else if (cmd=="doc") _doc(&zor,arg1);

			errors::errcode err = zor.get_error();
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

