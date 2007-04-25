/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: primitive_valuereps.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *	Author: Paul Pedersen (pcp071098@yahoo.com)
 */

#ifndef XQP_PRIMITIVE_VALUEREPS_H
#define XQP_PRIMITIVE_VALUEREPS_H

#include "valuereps.h"
#include "../types/sequence_type.h"

namespace xqp {


class numericRep : public atomic_valueRep
{
protected:
	long double theVal;

public:
	numericRep(sequence_type_t t, long double);
	~numericRep() {}

public:
	long double val() const { return theVal; }
	std::ostream& put(std::ostream&) const;

};


class timeRep : public atomic_valueRep
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
	struct tm theVal;

public:
	timeRep(sequence_type_t, struct tm);
	~timeRep() {}

	// ctor from string
	// 6-arg ctor

public:
	// 6 getters
	std::ostream& put(std::ostream&) const;

};


class stringRep : public atomic_valueRep
{
protected:
	const std::string& theVal;

public:
	stringRep(const std::string&);
	~stringRep() {}

public: 
	std::string val() const { return theVal; }
	std::ostream& put(std::ostream&) const;

};


class binaryRep : public atomic_valueRep
{
protected:
	unsigned char* theVal;
	size_t length;

public:
	binaryRep(unsigned char*, size_t length);
	~binaryRep();

public: 
	unsigned char* val() const { return theVal; }
	std::ostream& put(std::ostream&) const;

};


class booleanRep : public atomic_valueRep
{
protected:
	bool theVal;
	
public:
	booleanRep(bool _val) : atomic_valueRep(xs_boolean), theVal(_val) { }
	~booleanRep() {}

public:
	bool val() const { return theVal; }
	std::ostream& put(std::ostream&) const;

};



}	/* namespace xqp */
#endif	/* XQP_ZORBA_PRIMITIVE_VALUEREPS_H */
