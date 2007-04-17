/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: valuerep.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_VALUEREP_H
#define XQP_VALUEREP_H

#include "../runtime/item_iterator.h"
#include "../store/itemstore.h"
#include "../types/sequence_type.h"
#include "../util/rchandle.h"

#include <string>
 
namespace xqp {

class context;

/*______________________________________________________________________
|  
|  Base class for the zorba value hierarchy
|_______________________________________________________________________*/

class objectrep
{
public:
	typedef rchandle<item_iterator> itref_t;

public:
	objectrep() {}
	~objectrep() {}
};


/*______________________________________________________________________
|  
|	 'xquery_exception' encapsulate xquery exceptions
|_______________________________________________________________________*/

class xquery_exception_rep : public objectrep
													
{
public:
	xquery_exception_rep() {}
	~xquery_exception_rep() {}
};


/*______________________________________________________________________
|  
|  'ft_value' encapsulates an xquery full-text search constraint.
|  Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|  [http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class ft_valuerep : public objectrep
{
public:
	ft_valuerep() {}
	~ft_valuerep() {}
};


/*______________________________________________________________________
|  
|  'value' - top of the XQuery value hierarchy
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class sequencerep : public objectrep
{
public:
	sequence_type_t theType;		// typecode
	uint32_t theLength;					// storage size in bytes

public:
	sequencerep(sequence_type_t type, size_t len)
		: theType(type), theLength(len) {}
	sequencerep() {}
	~sequencerep() {}

public:		// accessors
	uint32_t length() const { return theLength; }
	uint32_t& length() { return theLength; }
	sequence_type_t type() const { return theType; }

public:
  std::string describe() const;
};


/*______________________________________________________________________
|  
|  'item' - union of node types and atomic types
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class itemrep : public sequencerep
{
public:
	itemrep(sequence_type_t type, size_t length)
		: sequencerep(type,length) {}
	itemrep() {}
	~itemrep() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const;
  std::string describe() const;

public:		// XQuery interface
	itref_t atomized_value() const;
	string string_value() const;
	bool is_empty() const;
	bool is_node() const;
	bool is_atomic() const;
};



/*______________________________________________________________________
|  
|  'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_valuerep :	public itemrep
{
public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	atomic_valuerep(sequence_type_t type, size_t length)
		: itemrep(type,length) {}
	atomic_valuerep() {}

private:
	~atomic_valuerep() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const;
  std::string describe() const;

public:		// XQuery interface
	itref_t atomized_value() const;
	string string_value() const;

	bool is_empty() const;
	bool is_node() const;
	bool is_atomic() const;
};



/*______________________________________________________________________
|  
|  nodereps defined in 'noderep.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_ZORBA_VALUES_H */

