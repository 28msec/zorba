/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xsd_constraints.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Code derived from the Apache Axis WSDL package (see following license).
 *
 */

#ifndef XQP_XSD_CONSTRAINTS_H
#define XQP_XSD_CONSTRAINTS_H


/*
 *   Copyright 2003-2004 The Apache Software Foundation.
// (c) Copyright IBM Corp. 2004, 2005 All Rights Reserved
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include "../util/xqpexception.h"
#include "xsd_mapping.h"
//#include "../../../platforms/PlatformAutoSense.hpp"
#include <ctime>


namespace xqp {
 
/**
 *   @class IConstrainingFacet
 *   @brief Interface for all XSD constraining facets
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class IConstrainingFacet {

public:
    
	IConstrainingFacet(bool b) : m_isSet(b) {}
	virtual ~IConstrainingFacet () {}

	/**
	 * To allow checking if a value has been set on this constraining facet.
	 */    
	bool isSet();
    
protected:
	bool m_isSet;

};



/**
 *   @class Enumeration
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class Enumeration : public IConstrainingFacet
{
public:
	Enumeration();
	Enumeration(char** enumeration, int numberOfValues);
	~Enumeration();

public:
	void validateEnumeration(const char* value) throw (xqpexception);
    
private:
	char** m_Enumeration;
	int m_NumberOfValues;

};




/**
 *   @class FractionDigits
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class FractionDigits : public IConstrainingFacet
{
public:
	FractionDigits();
	FractionDigits(int fractionDigits);

public:
	int getFractionDigits();
    
private:
	int m_FractionDigits;

};




/**
 *   @class Length
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class Length : public IConstrainingFacet
{
public:
	Length();
	Length(int length);
	int getLength();
    
private:
	int m_Length;

};




/**
 *   @class MaxExclusive
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */

class MaxExclusive : public IConstrainingFacet
{
public:
	MaxExclusive();
	MaxExclusive(int64_t maxExclusive);
	MaxExclusive(uint64_t maxExclusive);
	MaxExclusive(double maxExclusive);
	MaxExclusive(struct tm maxExclusive);

public:
	int64_t getMaxExclusiveAsLongLong();
	uint64_t getMaxExclusiveAsUnsignedLongLong();
	double getMaxExclusiveAsDouble();
	struct tm getMaxExclusiveAsStructTM();
    
private:
	union
	{
		int64_t longlongMaxExclusive;
		uint64_t unsignedLongLongMaxExclusive;
		double doubleMaxExclusive;  
		struct tm structTMMaxExclusive;
	} m_MaxExclusive;

};




/**
 *   @class MaxInclusive
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */

class MaxInclusive : public IConstrainingFacet
{
public:
	MaxInclusive();
	MaxInclusive(int64_t maxInclusive);
	MaxInclusive(uint64_t maxInclusive);
	MaxInclusive(double maxInclusive);
	MaxInclusive(struct tm maxInclusive);

public:
	int64_t getMaxInclusiveAsLongLong();
	uint64_t getMaxInclusiveAsUnsignedLongLong();
	double getMaxInclusiveAsDouble();
	struct tm getMaxInclusiveAsStructTM();
    
private:
	union
	{
		int64_t longlongMaxInclusive;
		uint64_t unsignedLongLongMaxInclusive;
		double doubleMaxInclusive;  
		struct tm structTMMaxInclusive;
	} m_MaxInclusive;

};




/**
 *   @class MaxLength
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */

class MaxLength : public IConstrainingFacet
{
public:
	MaxLength();
	MaxLength(int maxLength);

public:
	int getMaxLength();
    
private:
	int m_MaxLength;

};




/**
 *   @class MinExclusive
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */

class MinExclusive : public IConstrainingFacet
{
public:
	MinExclusive();
	MinExclusive(int64_t minExclusive);
	MinExclusive(uint64_t minExclusive);
	MinExclusive(double minExclusive);
	MinExclusive(struct tm minExclusive);

public:
	int64_t getMinExclusiveAsLongLong();
	uint64_t getMinExclusiveAsUnsignedLongLong();
	double getMinExclusiveAsDouble();
	struct tm getMinExclusiveAsStructTM();
    
private:
	union
	{
		int64_t longlongMinExclusive;
		uint64_t unsignedLongLongMinExclusive;
		double doubleMinExclusive;  
		struct tm structTMMinExclusive;
	} m_MinExclusive;

};




/**
 *   @class MinInclusive
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */

class MinInclusive : public IConstrainingFacet
{
public:
	MinInclusive();
	MinInclusive(int64_t minInclusive);
	MinInclusive(uint64_t minInclusive);
	MinInclusive(double minInclusive);
	MinInclusive(struct tm minInclusive);

public:
	int64_t getMinInclusiveAsLongLong();
	uint64_t getMinInclusiveAsUnsignedLongLong();
	double getMinInclusiveAsDouble();
	struct tm getMinInclusiveAsStructTM();
    
private:
	union
	{
		int64_t longlongMinInclusive;
		uint64_t unsignedLongLongMinInclusive;
		double doubleMinInclusive;  
		struct tm structTMMinInclusive;
	} m_MinInclusive;

};




/**
 *   @class MinLength
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class MinLength : public IConstrainingFacet
{
public:
	MinLength();
	MinLength(int minLength);

public:
	int getMinLength();
    
private:
	int m_MinLength;

};




/**
 *   @class Pattern
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class Pattern : public IConstrainingFacet
{
public:
	Pattern();
	Pattern(char* pattern);
	~Pattern();

public:
	void validatePattern(const char* value) throw (xqpexception);
    
private:
	char* m_Pattern;

};




/**
 *   @class TotalDigits
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class TotalDigits : public IConstrainingFacet
{
public:
	TotalDigits();
	TotalDigits(int totalDigits);

public:
	int getTotalDigits();
    
private:
	int m_TotalDigits;

};




/**
 *   @class WhiteSpace
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
const char WHITE_SPACE_CHARS[]    = "\t\r\n";

typedef enum
{
	PRESERVE,
	REPLACE,
	COLLAPSE
} whiteSpaceValue;

class WhiteSpace : public IConstrainingFacet
{
public:
	WhiteSpace();
	WhiteSpace(whiteSpaceValue whiteSpace);
	~WhiteSpace();

public:	
	const char* processWhiteSpace(const char* valueToProcess);

private:
	std::string const& replaceWhiteSpace(std::string& value);
	std::string const& collapseWhiteSpace(std::string& value);
	std::string const& stripLeadingWhiteSpace(std::string& value);
	std::string const& stripTrailingWhiteSpace(std::string& value);

	enum
	{
		TAB_CHARACTER = '\t',
		LINE_FEED_CHARACTER = '\r',
		CARRIAGE_RETURN_CHARACTER = '\n'
	};

	whiteSpaceValue m_WhiteSpace;
	char* m_Buf;
	std::string m_strReturnVal;

};



}	/* namespace xqp */
#endif /* XQP_XSD_CONSTRAINTS_H */
