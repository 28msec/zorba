/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ZORBA_VALUES_H
#define XQP_ZORBA_VALUES_H

#include "../types/sequence_type.h"
#include "../util/rchandle.h"

#include <string>
 
namespace xqp {

class context;
class itemstore;

/*______________________________________________________________________
|  
|  Base class for the zorba value hierarchy
|_______________________________________________________________________*/

class zorba_object
{
public:
	typedef rchandle<item_iterator> itref_t;

public:
	zorba_object() {}
	~zorba_object() {}
};


/*______________________________________________________________________
|  
|	 'xquery_exception' encapsulate xquery exceptions
|_______________________________________________________________________*/

class zorba_xquery_exception : public zorba_object
													
{
public:
	zorba_xquery_exception() {}
	~zorba_xquery_exception() {}
};


/*______________________________________________________________________
|  
|  'ft_value' encapsulates an xquery full-text search constraint.
|  Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|  [http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class zorba_ft_value : public zorba_object
{
public:
	zorba_ft_value() {}
	~zorba_ft_value() {}
};


/*______________________________________________________________________
|  
|  'value' - top of the XQuery value hierarchy
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class zorba_sequence : public zorba_object
{
public:
	sequence_type_t m_type;
	uint32_t m_length;	// storage size

public:
	zorba_sequence(sequence_type_t type, size_t len) : m_type(type), m_length(len) {}
	zorba_sequence() {}
	~zorba_sequence() {}

public:		// accessors
  std::string describe() const { return "item*"; }
	uint32_t length() const { return m_length; }
	uint32_t& length() { return m_length; }
	sequence_type_t type() const { return m_type; }

};


/*______________________________________________________________________
|  
|  'item' - union of node types and atomic types
|  [http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class zorba_item : public zorba_sequence
{
public:
	zorba_item(sequence_type_t type, size_t length) : sequence(type,length) {}
	zorba_item() {}
	~zorba_item() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "item"; }
	sequence_type_t type() const { return m_type; }

public:		// XQuery interface
	itref_t atomized_value() const { return NULL; }
	string string_value() const { return ""; }
	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return false; }
};



/*______________________________________________________________________
|  
|  'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class zorba_atomic_value :	public zorba_item
{
public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	zorba_atomic_value(sequence_type_t type, size_t length) : item(type,length) {}
	zorba_atomic_value() {}
	~zorba_atomic_value() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "xs_atomicValue"; }
	sequence_type_t type() const { return m_type; }

public:		// XQuery interface
	itref_t atomized_value() const { return NULL; }
	string string_value() const { return "xs_atomicValue"; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }
};



/*______________________________________________________________________
|  
|  node values defined in 'zorba_nodes.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_ZORBA_VALUES_H */

