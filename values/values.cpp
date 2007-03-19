/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "values.h"

#include "../context/context.h"
#include "../types/sequence_type.h"
#include "../util/rchandle.h"
#include "../util/tokenbuf.h"
#include "../util/tracer.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace xqp {

class context;

/*______________________________________________________________________
|  
|	'object' - base class for the value hierarchy
|_______________________________________________________________________*/

// no methods here

/*______________________________________________________________________
|  
|	'primitive_update' encapsulates an xquery update action.
|	Refer to "XQuery Update Facility'
|	[http://http://www.w3.org/TR/xqupdate/]
|_______________________________________________________________________*/

// no methods here

/*______________________________________________________________________
|  
|	'xquery_exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

// no methods here

/*______________________________________________________________________
|  
|	'ft_selection' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

// no methods here

/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

// no methods here

/*______________________________________________________________________
|  
|	'item_iterator' - coin of the realm in XQuery: all
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

// no methods here

/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

ostream& item::put(ostream& os) const { return os << ""; }
string item::describe() const { return "item()"; }
bool item::is_node() const { return false; }
bool item::is_atomic() const { return false; }
rchandle<item_iterator> item::atomized_value() const { return NULL; }
rchandle<item_iterator> item::effective_boolean_value() const { return NULL; }
string item::string_value() const { return ""; }


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates value of primitive or derived types
|_______________________________________________________________________*/

ostream& atomic_value::put(ostream& os) const { return os << ""; }
string atomic_value::describe() const { return "data()"; }
rchandle<item_iterator> atomic_value::atomized_value() const { return NULL; }
rchandle<item_iterator> atomic_value::effective_boolean_value() const { return NULL; }
string atomic_value::string_value() const { return ""; }


} /* namespace xqp */

