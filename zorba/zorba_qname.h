/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: zorba_qname.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_ZORBA_QNAME_H
#define XQP_ZORBA_QNAME_H

#include "zorba_values.h"

#include "context/common.h"
#include "runtime/item_iterator.h"
#include "values/values.h"
#include "values/qname.h"

#include <string>

namespace xqp {

class itemstore;
class qnamerep;
class zorba;

class zorba_qname : public zorba_atomic_value,
											public qname
{
protected:
	qnamerep* rep;

public:
	~zorba_qname() {}
	zorba_qname() {}
	zorba_qname(zorba_qname& qn) : item (qn), atomic_value (qn), zorba_atomic_value (qn), qname (qn), rep(qn.rep)  {}
	zorba_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

public:		// accessors
	std::string uri() const;
	std::string prefix() const;
	std::string localname() const;
	qnamekey_t qnamekey() const;

public:		// internal interface
	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

public:		// XQuery interface
	sequence_type_t type() const { return xs_qname; }
	iterator_t atomized_value(zorba*, yy::location &loc) const;
	iterator_t string_value(zorba*, yy::location &loc) const;
	iterator_t effective_boolean_value(zorba*, yy::location &loc) const;

public:		// output,debugging
	std::ostream& put(zorba*,std::ostream& os) const;
	std::string describe(zorba*) const;
	std::string str(zorba*) const;

};


} /* namespace xqp */
#endif /* XQP_ZORBA_QNAME_H */

