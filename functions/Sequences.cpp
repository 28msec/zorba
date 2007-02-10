/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: Sequences.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "Sequences.h"
#include "../context/context.h"
#include "../native_impl/xml_handler.h"
#include "../native_impl/xml_scanner.h"
#include "../native_impl/xml_term.h"
#include "../native_impl/nodestore.h"
#include "../util/file.h"
#include "errors.h"

#include <string>
#include <vector>

using namespace std;
namespace xqp {
  

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
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


/*..........................................
 : 15.5.4 fn:doc                           :
 :.........................................*/
rchandle<document_node> fn_doc(
	context & ctx,
	string const& uri)
{
	uint32_t dnid;
	rchandle<document_node> dn_h;
	rchandle<nodestore> nstore_h = ctx.get_nodestore();

	if (!ctx.get_dnid(uri, dnid)) {
		ctx.set_error(ERR_FODC0005);
		return NULL;
	}
	int k = nstore_h->get(&ctx, nodeid(dnid), dn_h);
	if (k < 0) {
		ctx.set_error(ERR_FODC0005);
		return NULL;
	}

	return dn_h;

}
  

//15.5.5 fn:doc-available

//15.5.6 fn:collection



/*______________________________________________________________________
|
| Extensions
|_______________________________________________________________________*/

/*..........................................
 : document-load                           :
 :.........................................*/
void xqp_document_load(
	context & ctx,
	string const& path,
	string const& baseuri,
	string const& uri)
{
	file f(path);
	if (!f.exists()) {
		ctx.set_error(ERR_FODC0002);
		return;
	}
	unsigned sz = f.get_size();
	size_t n = (sz > (1<<24) ? (1<<24) : (size_t)(sz));
	char* ibuf = new char[n+1];
	try {
		f.readfile(ibuf,n);
	} catch (xqp_exception& e) {
		ctx.set_error(ERR_FODC0002);
		delete[] ibuf;
		return;
	}
	
	xml_scanner xscanner;
	vector<xml_term> xterm_v;
	xml_handler* xhandler_p = new xml_handler(&ctx,baseuri,uri,xterm_v);
	xscanner.scan(ibuf, n, dynamic_cast<scan_handler*>(xhandler_p));
	uint32_t dnid = xhandler_p->get_dnid();
	ctx.put_docuri(path,dnid);

	delete xhandler_p;
	delete[] ibuf;

}
  

} /* namespace xqp */
 
