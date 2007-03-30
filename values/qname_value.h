/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_value.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_QNAME_VALUE_H
#define XQP_QNAME_VALUE_H

#include "abstract_values.h"
#include "abstract_qname.h"
#include "values.h"
#include "../context/common.h"
#include "../runtime/abstract_iterator.h"

#include <string>

namespace xqp {

class itemstore;

class qname_value : public atomic_value, public abstract_qname
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	char rest[0];
	/*
		xs_stringValue  `prefix:localname:uri`
	*/

public:
	void* operator new(size_t n, itemstore&);
	void* operator new(size_t n, itemstore&, itemref_t);
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:
	qname_value() {}
	qname_value(
		const std::string& uri,
		const std::string& prefix,
		const std::string& localname);

public:
	std::string uri() const;
	std::string prefix() const;
	std::string localname() const;
	qnamekey_t qnamekey() const;

private:	// ctor,dtor - lock out default and copy constructors
	qname_value(qname_value& qn) : atomic_value(xs_qname,0) {}
	~qname_value() {}

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;
	string describe() const;

	iterator_t atomized_value() const;
	iterator_t effective_boolean_value() const;
	std::string string_value() const;

};


} /* namespace xqp */
#endif /* XQP_QNAME_VALUE_H */

