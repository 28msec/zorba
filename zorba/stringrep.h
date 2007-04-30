/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: stringrep.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_STRINGREP_H
#define XQP_STRINGREP_H

#include "values/values.h"
#include "context/common.h"
#include <string>

namespace xqp {

class itemstore;

class stringrep : public atomic_value
{
protected:
	uint32_t theLength;
	char rest[0];

public:
	stringrep() : theLength(0) {}
	stringrep(itemstore&,const std::string& s);
	~stringrep() {}

public:		// storage interface
	void* operator new(size_t nBytes, void* p) { return p; }
	void* operator new(size_t nBytes, const void* p) { return (void*)p; }
	void* operator new(size_t n, size_t m) { return new char[n+m]; }
	void  operator delete(void*) {}

public:		// accessors
	std::string string_value() const;
	uint32_t length() const { return theLength; }

public: 	// XQuery atomic_value
	sequence_type_t type() const { return xs_string; }
	iterator_t atomized_value(zorba*) const;
	iterator_t effective_boolean_value(zorba*) const;
	iterator_t string_value(zorba*) const;

	bool is_empty() const;
	bool is_node() const;
	bool is_atomic() const;

public:		// output,debugging
	std::ostream& put(std::ostream& os) const;
	std::string describe() const;

};


} /* namespace xqp */
#endif /* XQP_STRINGREP_H */

