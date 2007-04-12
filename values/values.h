/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_VALUES_H
#define XQP_VALUES_H

#include "abstract_values.h"
#include "../runtime/iterator.h"
#include "../store/itemstore.h"
#include "../types/sequence_type.h"

#include <string>
#include <vector>
 
namespace xqp {

class context;

/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/

class object : public abstract_object
{
public:
	object() {}
	~object() {}

};


/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

class xquery_exception :	public object,
													public virtual abstract_xquery_exception
{
public:
	xquery_exception() {}
	~xquery_exception() {}

};


/*______________________________________________________________________
|  
|	'ft_value' encapsulates an xquery full-text search constraint.
|	Refer to "XQuery 1.0 and XPath 2.0 Full-Text"
|	[http://www.w3.org/TR/xquery-full-text/]
|_______________________________________________________________________*/

class ft_value :	public object,
									public abstract_ft_value
{
public:
	ft_value() {}
	~ft_value() {}

};


/*______________________________________________________________________
|  
|	'value' - top of the XQuery value hierarchy
|
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Value]
|_______________________________________________________________________*/

class sequence: public object,
								public abstract_sequence
{
public:
	sequence_type_t m_type;
	uint32_t m_length;

public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	sequence(sequence_type_t type, size_t len) : m_type(type), m_length(len) {}
	sequence() {}
	~sequence() {}

public:		// accessors
	uint32_t length() const { return m_length; }
	uint32_t& length() { return m_length; }
	sequence_type_t type() const { return m_type; }

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class item :	public sequence,
							public abstract_item
{
public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void * p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	item(sequence_type_t type, size_t length) : sequence(type,length) {}
	item() {}
	~item() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "item()"; }
	sequence_type_t type() const { return m_type; }

public:		// XQuery interface
	iterator_t atomized_value() const { return NULL; }
	string string_value() const { return ""; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return false; }
};



/*______________________________________________________________________
|  
|	'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_value :	public item
{
public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	atomic_value(sequence_type_t type, size_t length) : item(type,length) {}
	atomic_value() {}
	~atomic_value() {}

public:		// accessors
  std::ostream& put(std::ostream& os) const { return os; }
  std::string describe() const { return "xs_atomicValue"; }
	sequence_type_t type() const { return m_type; }

public:		// XQuery interface
	iterator_t atomized_value() const { return NULL; }
	string string_value() const { return "xs_atomicValue"; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }
};



/*______________________________________________________________________
|  
|	'node' values defined in 'nodes.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_VALUES_H */

