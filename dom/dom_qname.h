/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: dom_qname.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_DOM_QNAME_H
#define XQP_DOM_QNAME_H

#include "context/common.h"
#include "values/qname.h"
#include "parser/location.hh"

#include <string>
#include <vector>

namespace xqp {

class zorba;

class dom_qname : public qname
{
protected:
	std::string the_uri;
	std::string the_prefix;
	std::string the_localname;

public:
	dom_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

	dom_qname(const dom_qname& qn);
	~dom_qname() {}

public:		// accessors
	qnamekey_t nodeid() const;
	std::string uri() const { return the_uri; }
	std::string prefix() const { return the_prefix; }
	std::string localname() const { return the_localname; }
	std::string str(zorba*) const;
	qnamekey_t qnamekey() const { return hashkey(the_uri,the_prefix,the_localname); }

	static qnamekey_t hashkey(
	const std::string& uri,
	const std::string& prefix,
	const std::string& localname);

public:		// XQuery interface
	sequence_type_t type() const { return xs_qname; }
	iterator_t string_value(zorba*, yy::location &loc) const;
	iterator_t effective_boolean_value(zorba*, yy::location &loc) const;
	iterator_t atomized_value(zorba*, yy::location &loc) const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

public:		// output,debugging
	std::ostream& put(zorba*,std::ostream& os) const;
	std::string describe(zorba*) const;

};


} /* namespace xqp */
#endif /* XQP_DOM_QNAME_H */



