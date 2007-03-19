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

class xquery_exception : public object, public abstract_xquery_exception
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

class ft_value : public object, public abstract_ft_value
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

class value	: public object, public abstract_value
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
	value(sequence_type_t type, size_t len) : m_type(type), m_length(len) {}
	value() {}
	~value() {}

public:		// accessors
	sequence_type_t type() const { return m_type; }
	uint32_t length() const { return m_length; }
	uint32_t& length() { return m_length; }

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class item : public value, public abstract_item
{
public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void * p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	item(sequence_type_t type, size_t length) : value(type,length) {}
	item() {}
	~item() {}

public:		// accessors
  std::ostream& put(std::ostream&) const;
  std::string describe() const;

public:		// XQuery interface
	rchandle<item_iterator> atomized_value() const;
	rchandle<item_iterator> effective_boolean_value() const;

	string string_value() const;
	bool is_node() const;
	bool is_atomic() const;
};



/*______________________________________________________________________
|  
|	'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_value : public item, public abstract_atomic_value
{
public:		// storage interface
	void* operator new(size_t n, itemstore& istore) { return istore.alloc(n); }
	void* operator new(size_t n, itemstore& i, off_t o) { return &i[o]; }
	void* operator new(size_t n, void * p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}
	
public:
	atomic_value(sequence_type_t type, size_t length) : item(type,length) {}
	atomic_value() {}
	~atomic_value() {}

public:		// accessors
  std::ostream& put(std::ostream&) const;
  std::string describe() const;

public:		// XQuery interface
	rchandle<item_iterator> atomized_value() const;
	rchandle<item_iterator> effective_boolean_value() const;

	string string_value() const;
	bool is_sequence() const { return false; }
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

