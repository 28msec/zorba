/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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
/*daniel ??
class exceptionRep : public objectRep
													
{
public:
	exceptionRep() {}
	~exceptionRep() {}
};
*/

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
|  'item' - top of the XQuery value hierarchy
|           union of node types and atomic types
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class itemRep : public objectRep
{
public:
	sequence_type_t theType;		// typecode
	uint32_t theLength;					// full length in bytes

public:
	itemRep(sequence_type_t type, uint32_t length)
		: theType(type), theLength(length) {}
	itemRep(sequence_type_t type)
		: theType(type), theLength(0) {}
	itemRep() {}

public:		// accessors
	sequence_type_t type() const { return theType; }
	uint32_t length() const { return theLength; }

	sequence_type_t& type() { return theType; }
	uint32_t& length() { return theLength; }

public:		// output
  std::ostream& put(zorba*,std::ostream&) const;
  std::string describe() const;
	std::string string_value() const;

protected:	// lock out
	itemRep(const itemRep& other) : objectRep (other) {}
	~itemRep() {}

};


/*______________________________________________________________________
|  
|  'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_valueRep :	public itemRep
{
public:
	atomic_valueRep(sequence_type_t type, uint32_t length)
		: itemRep(type,length) {}
	atomic_valueRep(sequence_type_t type)
		: itemRep(type) {}
	atomic_valueRep() {}

public:		// output
  std::ostream& put(zorba*,std::ostream&) const;
  std::string describe() const;
	std::string string_value() const;

protected:	// lock out
	atomic_valueRep(itemRep&) {}
	~atomic_valueRep() {}

};


} /* namespace xqp */
#endif /* XQP_VALUEREPS_H */

