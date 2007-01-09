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
#include "../util/rchandle.h"

#include <string>
#include <vector>


namespace xqp {

class context;

/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/


/*______________________________________________________________________
|  
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/


/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/


/*______________________________________________________________________
|  
|	'ft_selection' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/


/*______________________________________________________________________
|  
|	'function' encapsulates an xquery function object
|_______________________________________________________________________*/


/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

void value::put(std::ostream& os, context const& ctx) const 
{
	os << "";
}

void value::describe(std::ostream& os, context const& ctx) const
{
	os << "";
}

bool value::is_sequence() const
{
	return false;
}

bool value::is_empty() const
{
	return false;
}


/*______________________________________________________________________
|  
|	'item_iterator' - coin of the realm in XQuery: all
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

void item::put(std::ostream& os, context const& ctx) const
{
	os << "";
}

void item::describe(std::ostream& os, context const& ctx) const
{
	os << "";
}

bool item::is_node() const
{
	return false;
}

bool item::is_atomic() const
{
	return false;
}


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates value of primitive or derived types
|_______________________________________________________________________*/

void atomic_value::put(std::ostream& os, context const& ctx) const
{
	os << "";
}

void atomic_value::describe(std::ostream& os, context const& ctx) const
{
	os << "":
}

enum type::typename atomic_value::get_typename() const
{
	return ITEM_TYPE;
}


} /* namespace xqp */

