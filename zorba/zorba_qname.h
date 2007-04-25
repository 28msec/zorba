/* -*- mode: c++; indent-tabs-mode: nil -*-
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

class zorba_qname : public zorba_atomic_value,
											public virtual qname
{
protected:
	qnamerep* rep;

public:
	~zorba_qname() {}
	zorba_qname() {}
	zorba_qname(zorba_qname& qn) : rep(qn.rep)  {}
	zorba_qname(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

public:
	std::string uri() const;
	std::string prefix() const;
	std::string localname() const;
	qnamekey_t qnamekey() const;

private:	// ctor,dtor - lock out default and copy constructors

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;
	std::string describe() const;
	iterator_t atomized_value() const;
	iterator_t effective_boolean_value() const;
	std::string string_value() const;

};


} /* namespace xqp */
#endif /* XQP_ZORBA_QNAME_H */

