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

#include "../context/common.h"
#include "../values/values.h"
#include "../util/rchandle.h"

namespace xqp {


class QName : public atomic_value
{
protected:
	std::string prefix;
	std::string name;
	nsid ns_id;
	uint32_t arity;

public:
  QName(
		std::string const& prefix,
		std::string const& name,
		uint32_t ns_id,
		uint32_t arity);
		
	QName(
		std::string const& prefix,
		std::string const& name,
		nsid ns_id);

	QName(
		std::string const& name);

	QName(QName const&);
	QName();
	~QName();

public:
	std::string get_prefix() const { return prefix; }
	void set_prefix(std::string const& p) { prefix = p; }

	std::string get_name() const { return name; }
	void set_name(std::string const& n) { name = n; }

	nsid get_ns_id() const { return ns_id; }
	void set_ns_id(nsid id) { ns_id = id; }

	uint32_t get_arity() const { return arity; }
	void set_arity(uint32_t _arity) { arity = _arity; }

	uint32_t hash_value() const;

public:	// atomic_value interface

	std::string describe(context * ctx) const
		{ return prefix.length()>0 ? prefix+':'+name : name; }

	std::ostream& put(std::ostream& os, context * ctx_p) const
		{ return os << (prefix.length()>0 ? prefix+':'+name : name); }

	std::ostream& put(std::ostream& os, context const* ctx_p) const
		{ return os << (prefix.length()>0 ? prefix+':'+name : name); }

	std::ostream& put(std::ostream& os, context & ctx) const
		{ return os << (prefix.length()>0 ? prefix+':'+name : name); }

	std::ostream& put(std::ostream& os, context const& ctx) const
		{ return os << (prefix.length()>0 ? prefix+':'+name : name); }

  bool is_sequence() const { return false; }
  bool is_empty() const { return false; }
  bool is_node() const { return false; }
  bool is_atomic() const { return true; }

  rchandle<item_iterator> atomized_value(context *) const;
	rchandle<item_iterator> effective_boolean_value(context *) const;

};



}	/* namespace xqp*/
#endif	/* XQP_QNAME_H */
