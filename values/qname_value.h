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
	itemref_t m_uriref;
	char rest[0];
	/*
		char[] localname
	*/

public:
	void* operator new(size_t n,itemstore& istore);
	void* operator new(size_t n,itemstore& i, itemref_t o) { return &i[o]; }
	void* operator new(size_t n, void* p) { return p; }
	void* operator new(size_t n, const void* p) { return (void*)p; }
	void  operator delete(void*) {}

public:
	qname_value() {}
	qname_value(itemstore&, itemref_t uriref, const std::string& qname);

public:
	std::string prefix() const;
	std::string localname() const;
	std::string uri(itemstore&) const;
	nodeid_t id(itemstore& istore) const;

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

