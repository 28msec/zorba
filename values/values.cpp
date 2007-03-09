/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "values.h"

#include "../types/sequence_type.h"
#include "../util/rchandle.h"
#include "../util/tokenbuf.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace xqp {

#define EMPTY_SEQUENCE(X) item_iterator((X))

class context;

/*______________________________________________________________________
|  
|	'object' - base class for the value hierarchy
|_______________________________________________________________________*/

// no methods currently


/*______________________________________________________________________
|  
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/

// no methods currently


/*______________________________________________________________________
|  
|	'xquery_exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

// no methods currently


/*______________________________________________________________________
|  
|	'ft_selection' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

// no methods currently


/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

void * value::operator new(
	size_t node_size,
	itemstore& istore)
{
	return istore.alloc(node_size);
}

void * value::operator new(
	size_t node_size,
	void * p)
{
	return p;
}

ostream& value::put(ostream& os, context * ctx_p) const 
{
	return os << "";
}

string value::describe(context * ctx_p) const
{
	return "data()";
}

bool value::is_sequence() const
{
	return false;
}

bool value::is_empty() const
{
	return false;
}

rchandle<item_iterator> value::atomized_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}

rchandle<item_iterator> value::effective_boolean_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}



/*______________________________________________________________________
|  
|	'item_iterator' - coin of the realm in XQuery: all
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

// no methods currently


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

void * item::operator new(
	size_t node_size,
	itemstore& istore)
{
	return istore.alloc(node_size);
}

void * item::operator new(
	size_t node_size,
	void * p)
{
	return p;
}

ostream& item::put(ostream& os, context * ctx_p) const
{
	return os << "";
}

string item::describe(context * ctx_p) const
{
	return "item()";
}

bool item::is_node() const
{
	return false;
}

bool item::is_atomic() const
{
	return false;
}

rchandle<item_iterator> item::atomized_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}

rchandle<item_iterator> item::effective_boolean_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}

string item::string_value(
	context const* ctx_p) const
{
	return "";
}



/*______________________________________________________________________
|  
|	'atomic_value' encapsulates value of primitive or derived types
|_______________________________________________________________________*/

ostream& atomic_value::put(ostream& os, context * ctx_p) const
{
	return os << "";
}

string atomic_value::describe(context * ctx_p) const
{
	return "data()";
}

sequence_type_t atomic_value::get_type() const
{
	return xs_untypedAtomicValue;
}

rchandle<item_iterator> atomic_value::atomized_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> atomic_value::effective_boolean_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

string atomic_value::string_value(
	context const* ctx_p) const
{
	return "";
}



/*______________________________________________________________________
|  
|	'qname_value' encapsulates XML QNames
|_______________________________________________________________________*/

qname_value::qname_value(
	itemstore& istore,
	string const& qname_s)
:
	value(xs_anyURI,0),
	m_qnamekey(hashfun::h64(qname_s)),
	m_nameref(istore.eos()+1)
{
	uint32_t sz = istore.eos();
	size_t n = qname_s.find(':');
	string prefix = (n!=string::npos?qname_s.substr(0,n):"");
	string localname = (n!=string::npos?qname_s.substr(n+1):qname_s);
	istore.add_text(prefix);
	m_prefixref = istore.eos();
	istore.add_text(localname);
	m_length = (istore.eos() - sz);
}

string qname_value::prefix(
	itemstore& istore) const
{
	return istore.get_text(m_nameref);
}

string qname_value::localname(
	itemstore& istore) const
{
	return istore.get_text(m_prefixref);
}

void* qname_value::operator new(
	size_t n,
	itemstore& istore)
{
	istore.assure_bytes(n);
	return istore.eos_p();
}

void* qname_value::operator new(
	size_t n,
	void* p)
{
	return p;
}

ostream& qname_value::put(ostream& os, context * ctx_p) const
{
	return os << "";
}

string qname_value::describe(context * ctx_p) const
{
	return "xs_qname()";
}

rchandle<item_iterator> qname_value::atomized_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

rchandle<item_iterator> qname_value::effective_boolean_value(
	context * ctx_p) const
{
	return &item_iterator::empty_sequence;
}

string qname_value::string_value(
	context const* ctx_p) const
{
	return "";
}


} /* namespace xqp */

