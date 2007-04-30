/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: primitive_values.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *	Author: John Cowan,Paul Pedersen
 */

#ifndef XQP_PRIMITIVE_VALUES_H
#define XQP_PRIMITIVE_VALUES_H

#include "values.h"
#include "context/common.h"
#include "runtime/item_iterator.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"
#include <time.h>

namespace xqp {

class numericValue : public atomic_value
{
protected:
	sequence_type_t theType;
	long double theVal;

public:
	numericValue(sequence_type_t, long double);
	~numericValue() {}

public:
	long double val() const { return theVal; }
	std::ostream& put(std::ostream&) const;
	std::string describe() const;
	std::string string_value() const;

public:		// XQuery interface
	sequence_type_t type() const { return theType; }

	iterator_t atomized_value(zorba*) const { return NULL; }
	iterator_t effective_boolean_value(zorba*) const { return NULL; }
	iterator_t string_value(zorba*) const { return NULL; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class timeValue : public atomic_value
{
protected:
/*
	int32_t start_month;			// negative in BCE era
	uint64_t start_second;
	uint32_t month_duration;
	uint64_t second_duration;
	uint32_t month_period;
	uint64_t second_period;
*/
	sequence_type_t theType;
	struct tm theVal;

public:
	timeValue(sequence_type_t, struct tm);
	timeValue(const std::string&);
	~timeValue() {}

	// 6-arg ctor
	// 6 getters

public:
	std::ostream& put(std::ostream&) const;
	std::string describe() const;
	std::string string_value() const;

public:		// XQuery interface
	sequence_type_t type() const { return theType; }

	iterator_t atomized_value(zorba*) const { return NULL; }
	iterator_t effective_boolean_value(zorba*) const { return NULL; }
	iterator_t string_value(zorba*) const { return NULL; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }


};


class stringValue : public atomic_value
{
protected:
	sequence_type_t theType;
	std::string theVal;

public:
	stringValue(sequence_type_t,const std::string&);
	stringValue(const std::string&);
	~stringValue() {}

public: 
	std::string val() const { return theVal; }
	std::ostream& put(std::ostream&) const;
	std::string describe() const;
	std::string string_value() const;

	stringValue& operator=(const stringValue& v)
		{ theVal = v.theVal; return *this; }

public:		// XQuery interface
	sequence_type_t type() const { return theType; }

	iterator_t atomized_value(zorba*) const;
	iterator_t effective_boolean_value(zorba*) const;
	iterator_t string_value(zorba*) const;

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


class binaryValue : public atomic_value
{
protected:
	sequence_type_t theType;
	unsigned char* theVal;
	size_t theLength;

public:
	binaryValue(sequence_type_t, const void*, size_t length);
	~binaryValue();

public: 
	unsigned char* val() const { return theVal; }
	std::ostream& put(std::ostream&) const;
	std::string describe() const;
	std::string string_value() const;

public:		// XQuery interface
	sequence_type_t type() const { return theType; }

	iterator_t atomized_value(zorba*) const { return NULL; }
	iterator_t effective_boolean_value(zorba*) const { return NULL; }
	iterator_t string_value(zorba*) const { return NULL; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }


};


class booleanValue : public atomic_value
{
protected:
	sequence_type_t theType;
	bool theVal;
	
public:
	booleanValue(bool b);
	~booleanValue() {}

public:
	bool val() const { return theVal; }
	std::ostream& put(std::ostream&) const;
	std::string describe() const;
	std::string string_value() const;

public:		// XQuery interface
	sequence_type_t type() const { return theType; }

	iterator_t atomized_value(zorba*) const { return NULL; }
	iterator_t effective_boolean_value(zorba*) const { return NULL; }
	iterator_t string_value(zorba*) const { return NULL; }

	bool is_empty() const { return false; }
	bool is_node() const { return false; }
	bool is_atomic() const { return true; }

};


}	/* namespace xqp */
#endif	/* XQP_PRIMITIVE_VALUES_H */
