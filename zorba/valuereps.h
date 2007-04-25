/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: valuereps.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_VALUEREPS_H
#define XQP_VALUEREPS_H

#include "runtime/item_iterator.h"
#include "store/itemstore.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

#include <string>
 
namespace xqp {

/*______________________________________________________________________
|  
|  Base class for the zorba value rep hierarchy
|_______________________________________________________________________*/

class objectRep
{
public:
	objectRep() {}
	~objectRep() {}
};


/*______________________________________________________________________
|  
|	 'xquery_exception' encapsulate xquery exceptions
|_______________________________________________________________________*/

class exceptionRep : public objectRep
													
{
public:
	exceptionRep() {}
	~exceptionRep() {}
};


/*______________________________________________________________________
|  
|  'ft_value' encapsulates an xquery full-text search constraint.
|  Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|  [http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class ft_valueRep : public objectRep
{
public:
	ft_valueRep() {}
	~ft_valueRep() {}
};


/*______________________________________________________________________
|  
|  'value' - top of the XQuery value hierarchy
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class sequenceRep : public objectRep
{
public:
	sequence_type_t theType;		// typecode

public:
	sequenceRep(sequence_type_t type) : theType(type) {}
	sequenceRep() : theType(xs_anyType) {}
	~sequenceRep() {}

public:
	sequence_type_t type() const { return theType; }
  std::string describe() const;
};


/*______________________________________________________________________
|  
|  'item' - union of node types and atomic types
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class itemRep : public sequenceRep
{
public:
	itemRep(sequence_type_t type) : sequenceRep(type) {}
	itemRep() {}
	~itemRep() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const;
  std::string describe() const;

public:		// XQuery interface
	std::string string_value() const;
	iterator_t atomized_value() const;
	bool is_empty() const;
	bool is_node() const;
	bool is_atomic() const;
};


/*______________________________________________________________________
|  
|  'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_valueRep :	public itemRep
{
public:
	atomic_valueRep(sequence_type_t type) : itemRep(type) {}
	~atomic_valueRep() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const;
  std::string describe() const;

public:		// XQuery interface
	string string_value() const;
	iterator_t atomized_value() const;

	bool is_empty() const;
	bool is_node() const;
	bool is_atomic() const;
};


} /* namespace xqp */
#endif /* XQP_VALUEREPS_H */

