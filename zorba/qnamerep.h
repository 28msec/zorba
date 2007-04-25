/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qnamerep.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_QNAMEREP_H
#define XQP_QNAMEREP_H

#include "values/values.h"
#include "context/common.h"
#include <string>

namespace xqp {

class itemstore;

class qnamerep : public atomic_value
{
protected:
	std::string name;	// prefix:localname:uri

public:
	~qnamerep() {}
	qnamerep() : atomic_value(xs_qname) {}
	qnamerep(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

public:
	std::string uri() const;
	std::string prefix() const;
	std::string localname() const;
	qnamekey_t qnamekey() const;

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;
	std::string string_value() const;
	std::string describe() const;
	iterator_t atomized_value() const;
	iterator_t effective_boolean_value() const;

};


} /* namespace xqp */
#endif /* XQP_QNAMEREP_H */

