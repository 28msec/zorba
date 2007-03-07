/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_VALUES_H
#define XQP_VALUES_H

#include "../runtime/iterator.h"
#include "../store/itemstore.h"
#include "../types/sequence_type.h"
#include "../util/rchandle.h"

#include <string>
#include <vector>
 
namespace xqp {

class context;

/*______________________________________________________________________
|  
|	Base class for the value hierarchy
|_______________________________________________________________________*/

class object : public rcobject
{
public:
	object() {}
	virtual ~object() {}

};



/*______________________________________________________________________
|  
|	'exception' encapsulates an xquery exception.
|_______________________________________________________________________*/

class xquery_exception : public object
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

class ft_value : public object
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

class value	: public object
{
protected:
	sequence_type_t m_type;
	size_t m_length;

public:
	value(sequence_type_t t, size_t l) : m_type(t), m_length(l) {}
	virtual ~value() {}
	void* operator new(size_t, itemstore&);
	void* operator new(size_t, void*);
	void operator delete(void*) {}

public:
	sequence_type_t type() const { return m_type; }
	size_t length() const { return m_length; }
  virtual std::ostream& put(std::ostream&, context *) const;
  virtual std::string describe(context *) const;
	virtual rchandle<item_iterator> atomized_value(context *) const;
	virtual rchandle<item_iterator> effective_boolean_value(context *) const;
	virtual bool is_sequence() const;
	virtual bool is_empty() const;

};


/*______________________________________________________________________
|  
|	'item' - union of node types and atomic types
|	[http://www.w3.org/TR/xquery-semantics/doc-fs-Item]
|_______________________________________________________________________*/

class item : public value
{
public:
	item(sequence_type_t type, size_t length) : value(type,length) {}
	virtual ~item() {}

	void* operator new(size_t, itemstore&);
	void* operator new(size_t, void*);
	void operator delete(void*) {}

public:
  virtual std::ostream& put(std::ostream&, context *) const;
  virtual std::string describe(context *) const;
	virtual rchandle<item_iterator> atomized_value(context *) const;
	virtual rchandle<item_iterator> effective_boolean_value(context *) const;
	virtual std::string string_value(context const*) const;

	virtual bool is_node() const;
	virtual bool is_atomic() const;
};


/*______________________________________________________________________
|  
|	'atomic_value' encapsulates values of primitive or derived types
|_______________________________________________________________________*/

class atomic_value : public item
{
public:
	atomic_value(sequence_type_t type, size_t length) : item(type,length) {}
	virtual ~atomic_value() {}

public:
  virtual std::ostream& put(std::ostream&, context *) const;
  virtual std::string describe(context *) const;
	virtual rchandle<item_iterator> atomized_value(context *) const;
	virtual rchandle<item_iterator> effective_boolean_value(context *) const;
	virtual std::string string_value(context const*) const;
	virtual sequence_type_t get_type() const;

	bool is_sequence() const { return false; }
	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }
};


/*______________________________________________________________________
|  
|	'qname_value' encapsulates XML QNames
|_______________________________________________________________________*/

class qname_value : public value 
{
protected:
	uint64_t m_qnamekey;
	itemref_t m_qnameref;
	char rest[0];
	/*
		char[] localname
		namespace_node namespace
	*/

	void* operator new(size_t, itemstore&);
	void* operator new(size_t, void*);
	void operator delete(void*) {}

private:	// ctor,dtor - lock out
	qname_value(qname_value& qn) : value(xs_qname,0) {}
	qname_value() : value(xs_qname,0) {}
	~qname_value() {}

public:		// output,debugging
	std::ostream& put(std::ostream& os,context * ctx) const { return os; }

};


/*______________________________________________________________________
|  
|	'uri_value' encapsulates URIs
|_______________________________________________________________________*/

class uri_value : public value 
{
protected:
	uint64_t m_urikey;
	itemref_t m_uriref;
	char rest[0];
	/*
		char[] uri
	*/

	void* operator new(size_t, itemstore&);
	void* operator new(size_t, void*);
	void operator delete(void*) {}

private:	// ctor,dtor - lock out
	uri_value(uri_value& qn) : value(xs_anyURI,0) {}
	uri_value() : value(xs_anyURI,0) {}
	~uri_value() {}

public:		// output,debugging
	std::ostream& put(std::ostream& os,context * ctx) const { return os; }

};




/*______________________________________________________________________
|  
|	'node' values defined in 'nodes.h'
|_______________________________________________________________________*/

} /* namespace xqp */
#endif /* XQP_VALUES_H */

