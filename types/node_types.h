/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_types.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

/*______________________________________________________________________
|
| Includes classes supporting each of the 7 node types defined in:
|   XQuery 1.0 and XPath 2.0 Data Model (NODE_TYPES)
|   [http://www.w3.org/TR/xpath-datamodel/]
|_______________________________________________________________________*/
 
#ifndef XQP_NODE_TYPES_H
#define XQP_NODE_TYPES_H

#include "../runtime/item_iterator.h"
#include "../context/context.h"
#include "../util/rchandle.h"

namespace xqp {

class node_type : public item_type
{
protected:
	static node_type the_instance;

public:
	static node_type const& get_instance();

public: //	item_type interface
	virtual bool is_atomic_type() const
		{ return false; }
	virtual item_type const* get_supertype() const
		{ return &item_type::get_instance(); }
	virtual item_type const* get_primitive_type() const
		{ return NULL; }
	virtual type::typecode get_typecode() const
		{ return type::NODE_TYPE; }

	virtual bool matches(item const*, context const*) const;
	virtual xs_anyAtomicType const* get_atomized_type() const;
	virtual std::string describe() const;

};


class document_node_type : public node
{
protected:
	static document_node_type the_instance;

public:
	static document_node_type const& get_instance();

public: //	item_type interface
	item_type const* get_supertype() const
		{ return &node_type::get_instance(); }
	type::typecode get_typecode() const
		{ return type::

	bool matches(item const*, context const*) const;
	xs_anyAtomicType const* get_atomized_type() const;
	std::string describe() const;

};



class element_node : public node
{
protected:
	static element_node_type the_instance;

public:
	static element_node_type const& get_instance();

public: //	item_type interface
	bool is_atomic_type() const;
	bool matches(item const*, context const*) const;
	item_type const* get_supertype() const;
	item_type const* get_primitive_type() const;
	type::typecode get_typecode() const;
	xs_anyAtomicType const* get_atomized_type() const;
	std::string describe() const;
	
};



class attribute_node : public node
{
protected:
	static attribute_node_type the_instance;

public:
	static attribute_node_type const& get_instance();

public: //	item_type interface
	bool is_atomic_type() const;
	bool matches(item const*, context const*) const;
	item_type const* get_supertype() const;
	item_type const* get_primitive_type() const;
	type::typecode get_typecode() const;
	xs_anyAtomicType const* get_atomized_type() const;
	std::string describe() const;

};



class ns_node : public node
{
protected:
	static ns_node_type the_instance;

public:
	static ns_node_type const& get_instance();

public: //	item_type interface
	bool is_atomic_type() const;
	bool matches(item const*, context const*) const;
	item_type const* get_supertype() const;
	item_type const* get_primitive_type() const;
	type::typecode get_typecode() const;
	xs_anyAtomicType const* get_atomized_type() const;
	std::string describe() const;

};



class pi_node : public node
{
protected:
	static pi_node_type the_instance;

public:
	static pi_node_type const& get_instance();

public: //	item_type interface
	bool is_atomic_type() const;
	bool matches(item const*, context const*) const;
	item_type const* get_supertype() const;
	item_type const* get_primitive_type() const;
	type::typecode get_typecode() const;
	xs_anyAtomicType const* get_atomized_type() const;
	std::string describe() const;

};



class text_node : public node
{
protected:
	static text_node_type the_instance;

public:
	static text_node_type const& get_instance();

public: //	item_type interface
	bool is_atomic_type() const;
	bool matches(item const*, context const*) const;
	item_type const* get_supertype() const;
	item_type const* get_primitive_type() const;
	type::typecode get_typecode() const;
	xs_anyAtomicType const* get_atomized_type() const;
	std::string describe() const;

};


}	/* namespace xqp */
#endif /* XQP_NODE_TYPES_H */
