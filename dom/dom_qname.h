
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_qname.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_DOM_QNAME_H
#define XQP_DOM_QNAME_H

#include "dom_values.h"
#include "../context/common.h"
#include "../values/abstract_values.h"
#include "../values/abstract_nodes.h"

#include <string>
#include <vector>

namespace xqp {

class dom_qname : public abstract_qname
{
protected:
	std::string iuri;
	std::string iprefix;
	std::string ilocalname;

public:
	dom_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

	dom_qname(const dom_qname& qn);
	~dom_qname() {}

public:
	std::string uri() const { return iuri; }
	std::string prefix() const { return iprefix; }
	std::string localname() const { return ilocalname; }
	qnamekey_t nodeid() const;

	static qnamekey_t hashkey(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;
	std::string describe() const;

};


} /* namespace xqp */
#endif /* XQP_DOM_QNAME_H */



