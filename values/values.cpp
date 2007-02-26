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
|	'value' - base class for the value hierarchy
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
	return untypedAtomicValue;
}

rchandle<item_iterator> atomic_value::atomized_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}

rchandle<item_iterator> atomic_value::effective_boolean_value(
	context * ctx_p) const
{
	return new item_iterator(ctx_p);
}

string atomic_value::string_value(
	context const* ctx_p) const
{
	return "";
}



} /* namespace xqp */

