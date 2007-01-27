/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_value.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_QNAME_VALUE_H
#define XQP_QNAME_VALUE_H

#include <ostream>
#include <string>

#include "../values/values.h"
#include "../util/rchandle.h"

namespace xqp {


class QName : public atomic_value
{
public:
	enum qname_type_t {
		qn_var,		// variable name
		qn_attr,	// attribute name
		qn_elem,	// element name
		qn_type,	// type name
		qn_func,	// function name
		qn_optn,	// prolog option name
		qn_ns,		// ns prefix 
		qn_pi,		// pi target
		qn_prag,	// pragma label
		qn_none		// uninitialized
	};

protected:
	enum qname_type_t type;
	std::string prefix;
	std::string name;
	uint64_t namespace_hash;

public:
	QName(
		enum qname_type_t,
		std::string const& prefix,
		std::string const& name,
		uint64_t namespace_hash);

	QName(
		enum qname_type_t,
		std::string const& prefix,
		std::string const& name);

	QName(
		enum qname_type_t,
		std::string const& name);

	QName(enum qname_type_t);
	QName(QName const&);
	QName();
	~QName();

public:
	enum qname_type_t get_type() const { return type; };

	std::string get_prefix() const { return prefix; }
	void set_prefix(std::string const& p) { prefix = p; }

	std::string get_name() const { return name; }
	void set_name(std::string const& n) { name = n; }

	uint64_t get_namespace_hash() const { return namespace_hash; }
	void set_namespace_hash(uint64_t h) { namespace_hash = h; }

public:	// atomic_value interface

	std::string describe(context const& ctx) const
		{ return prefix.length()>0 ? prefix+':'+name : name; }

	std::ostream& put(std::ostream& os, context const& ctx) const
		{ return os << (prefix.length()>0 ? prefix+':'+name : name); }

  enum type::typecode get_typecode() const
		{ return type::XS_QNAME; }

  bool is_sequence() const { return false; }
  bool is_empty() const { return false; }
  bool is_node() const { return false; }
  bool is_atomic() const { return true; }

  rchandle<item_iterator> atomized_value(context &) const;
	rchandle<item_iterator> effective_boolean_value(context &) const;

};


/*______________________________________________________________________
|  
|	opaque implementation-defined QName id
|
|	qnameid's index into a QName pool which manages QName
|	namespace URIs and localnames.
|_______________________________________________________________________*/

class qnameid
{
public:
	bool operator==(qnameid const&) const;
	static rchandle<QName> get_qname(qnameid const&);
	static qnameid put_qname(rchandle<QName>);

};


}	/* namespace xqp*/
#endif	/* XQP_QNAME_H */
