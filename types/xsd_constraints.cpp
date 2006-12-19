/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xsd_constraints.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Code derived from the Apache Axis WSDL package. (See following license.)
 *
 */

#include "xsd_constraints.h"

#include <sstream>
#include <string>

#include "../util/xqpexception.h"


/*______________________________________________________________________
|
|	Original software license from Apache Axis source code
|	(http://ws.apache.org/axis/)
|_______________________________________________________________________*/
// Copyright 2003-2004 The Apache Software Foundation.
// (c) Copyright IBM Corp. 2004, 2005 All Rights Reserved
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


using namespace std;
namespace xqp {


bool IConstrainingFacet::isSet()
{
	return m_isSet;
}




Enumeration::Enumeration()
:
	IConstrainingFacet(false),
	m_Enumeration(NULL),
	m_NumberOfValues(0)
{
}

Enumeration::Enumeration(
	char** enumeration,
	int numberOfValues)
:
	IConstrainingFacet(true)
{
	m_Enumeration = new char*[numberOfValues];
	memcpy(m_Enumeration, enumeration, (numberOfValues * sizeof(char*)));
	m_NumberOfValues = numberOfValues;
}
    
Enumeration::~Enumeration()
{
	if (m_Enumeration) {
		delete [] m_Enumeration;
		m_Enumeration = NULL;
	}
}

void Enumeration::validateEnumeration(
	const char* value) throw (xqpexception)
{
	for ( int count = 0 ; count < m_NumberOfValues ; count++) {
		if (strcmp(m_Enumeration[count], value)==0 ) return;
	}

	/*
	 * If we got this far we didn't find a matching value
	 * So throw xqpexception
	 */
	ostringstream exceptionMessage;
	exceptionMessage <<
		"Value to be serialized does not match any of the values specified"
		" by Enmeration for this type.  MinInclusive = ";
	for (uint32_t element = 0; element < m_NumberOfValues; ++element)
	{
		exceptionMessage << m_Enumeration[element] << ", ";
	}
	exceptionMessage << "Value = " << value << ".";
	throw xqpexception("validateEnumeration",
            				 const_cast<char*>(exceptionMessage.str().c_str()));
}




FractionDigits::FractionDigits()
:
	IConstrainingFacet(false),
	m_FractionDigits(0)
{
}

FractionDigits::FractionDigits(
	int fractionDigits)
:
	IConstrainingFacet(true),
	m_FractionDigits(fractionDigits)
{
}

int FractionDigits::getFractionDigits()
{
	return m_FractionDigits;
}
    



Length::Length()
:
	IConstrainingFacet(false),
	m_Length(0)
{
}

Length::Length(
	int length)
:
	IConstrainingFacet(true),
	m_Length(length)
{
}

int Length::getLength()
{
	return m_Length;
}
    




MaxExclusive::MaxExclusive(int64_t maxExclusive)
:
	IConstrainingFacet(true)
{
	m_MaxExclusive.longlongMaxExclusive = maxExclusive;
}

MaxExclusive::MaxExclusive(uint64_t maxExclusive)
:
	IConstrainingFacet(true)
{
	m_MaxExclusive.unsignedLongLongMaxExclusive = maxExclusive;
}

MaxExclusive::MaxExclusive(double maxExclusive)
:
	IConstrainingFacet(true)
{
	m_MaxExclusive.doubleMaxExclusive = maxExclusive;
}
    
MaxExclusive::MaxExclusive(struct tm maxExclusive)
:
	IConstrainingFacet(true)
{
	m_MaxExclusive.structTMMaxExclusive = maxExclusive;
}

MaxExclusive::MaxExclusive()
:
	IConstrainingFacet(false)
{
}
    
int64_t MaxExclusive::getMaxExclusiveAsLongLong()
{
	return m_MaxExclusive.longlongMaxExclusive;
}

uint64_t MaxExclusive::getMaxExclusiveAsUnsignedLongLong()
{
	return m_MaxExclusive.unsignedLongLongMaxExclusive;
}
    
double MaxExclusive::getMaxExclusiveAsDouble()
{
	return m_MaxExclusive.doubleMaxExclusive;
}
    
struct tm MaxExclusive::getMaxExclusiveAsStructTM()
{
	return m_MaxExclusive.structTMMaxExclusive;
}
    



MaxInclusive::MaxInclusive(int64_t maxInclusive)
:
	IConstrainingFacet(true)
{
	m_MaxInclusive.longlongMaxInclusive = maxInclusive;
}

MaxInclusive::MaxInclusive(uint64_t maxInclusive)
:
	IConstrainingFacet(true)
{
	m_MaxInclusive.unsignedLongLongMaxInclusive = maxInclusive;
}

MaxInclusive::MaxInclusive(double maxInclusive)
:
	IConstrainingFacet(true)
{
	m_MaxInclusive.doubleMaxInclusive = maxInclusive;
}
    
MaxInclusive::MaxInclusive(struct tm maxInclusive)
:
	IConstrainingFacet(true)
{
	m_MaxInclusive.structTMMaxInclusive = maxInclusive;
}

MaxInclusive::MaxInclusive()
:
	IConstrainingFacet(false)
{
}
    
int64_t MaxInclusive::getMaxInclusiveAsLongLong()
{
	return m_MaxInclusive.longlongMaxInclusive;
}

uint64_t MaxInclusive::getMaxInclusiveAsUnsignedLongLong()
{
	return m_MaxInclusive.unsignedLongLongMaxInclusive;
}
    
double MaxInclusive::getMaxInclusiveAsDouble()
{
	return m_MaxInclusive.doubleMaxInclusive;
}
    
struct tm MaxInclusive::getMaxInclusiveAsStructTM()
{
	return m_MaxInclusive.structTMMaxInclusive;
}
    





MaxLength::MaxLength()
:
	IConstrainingFacet(false),
	m_MaxLength(0)
{
}

MaxLength::MaxLength(int maxLength)
:
	IConstrainingFacet(true),
	m_MaxLength(maxLength)
{
}

int MaxLength::getMaxLength()
{
	return m_MaxLength;
}
    




MinExclusive::MinExclusive(int64_t minExclusive)
:
	IConstrainingFacet(true)
{
	m_MinExclusive.longlongMinExclusive = minExclusive;
}

MinExclusive::MinExclusive(uint64_t minExclusive)
:
	IConstrainingFacet(true)
{
	m_MinExclusive.unsignedLongLongMinExclusive = minExclusive;
}

MinExclusive::MinExclusive(double minExclusive)
:
	IConstrainingFacet(true)
{
	m_MinExclusive.doubleMinExclusive = minExclusive;
}
    
MinExclusive::MinExclusive(struct tm minExclusive)
:
	IConstrainingFacet(true)
{
	m_MinExclusive.structTMMinExclusive = minExclusive;
}

MinExclusive::MinExclusive()
:
	IConstrainingFacet(false)
{
}
    
int64_t MinExclusive::getMinExclusiveAsLongLong()
{
	return m_MinExclusive.longlongMinExclusive;
}

uint64_t MinExclusive::getMinExclusiveAsUnsignedLongLong()
{
	return m_MinExclusive.unsignedLongLongMinExclusive;
}
    
double MinExclusive::getMinExclusiveAsDouble()
{
	return m_MinExclusive.doubleMinExclusive;
}
    
struct tm MinExclusive::getMinExclusiveAsStructTM()
{
	return m_MinExclusive.structTMMinExclusive;
}
    




MinInclusive::MinInclusive(int64_t minInclusive)
:
	IConstrainingFacet(true)
{
	m_MinInclusive.longlongMinInclusive = minInclusive;
}

MinInclusive::MinInclusive(uint64_t minInclusive)
:
	IConstrainingFacet(true)
{
	m_MinInclusive.unsignedLongLongMinInclusive = minInclusive;
}

MinInclusive::MinInclusive(double minInclusive)
:
	IConstrainingFacet(true)
{
	m_MinInclusive.doubleMinInclusive = minInclusive;
}
    
MinInclusive::MinInclusive(struct tm minInclusive)
:
	IConstrainingFacet(true)
{
	m_MinInclusive.structTMMinInclusive = minInclusive;
}

MinInclusive::MinInclusive()
:
	IConstrainingFacet(false)
{
}
    
int64_t MinInclusive::getMinInclusiveAsLongLong()
{
	return m_MinInclusive.longlongMinInclusive;
}

uint64_t MinInclusive::getMinInclusiveAsUnsignedLongLong()
{
	return m_MinInclusive.unsignedLongLongMinInclusive;
}
    
double MinInclusive::getMinInclusiveAsDouble()
{
	return m_MinInclusive.doubleMinInclusive;
}
    
struct tm MinInclusive::getMinInclusiveAsStructTM()
{
	return m_MinInclusive.structTMMinInclusive;
}
    




MinLength::MinLength()
:
	IConstrainingFacet(false),
	m_MinLength(0)
{
}

MinLength::MinLength(
	int minLength)
:
	IConstrainingFacet(true),
	m_MinLength(minLength)
{
}

int MinLength::getMinLength()
{
	return m_MinLength;
}
    




Pattern::Pattern()
:
	IConstrainingFacet(false),
	m_Pattern(NULL)
{
}

Pattern::Pattern(char* pattern)
:
	IConstrainingFacet(true)
{
	if (m_Pattern) {
		delete [] m_Pattern;
		m_Pattern = NULL;
	}
	m_Pattern = pattern;
}
    
Pattern::~Pattern()
{
	if (m_Pattern) {
		delete [] m_Pattern;
		m_Pattern = NULL;
	}
}

void Pattern::validatePattern(const char* value)
throw (xqpexception)
{
	/*
 	 * Currently has no effect.
	 * Needs to validate the given string matches the regular expression
	 * provided to the constructor.
	 */
}




TotalDigits::TotalDigits()
:
	IConstrainingFacet(false),
	m_TotalDigits(0)
{
}

TotalDigits::TotalDigits(
	int totalDigits)
:
	IConstrainingFacet(true),
	m_TotalDigits(totalDigits)
{
}

int TotalDigits::getTotalDigits()
{
	return m_TotalDigits;
}




WhiteSpace::WhiteSpace()
:
	IConstrainingFacet(true),
	m_WhiteSpace(PRESERVE),
	m_Buf(NULL)
{
}

WhiteSpace::~WhiteSpace()
{
	delete [] m_Buf;
}

WhiteSpace::WhiteSpace(
	whiteSpaceValue whiteSpace)
:
	IConstrainingFacet(true),
	m_Buf(NULL),
	m_WhiteSpace(whiteSpace)
{
}

const char* WhiteSpace::processWhiteSpace(
	const char* valueToProcess)
{
	string valueAsString = valueToProcess;
	char* returnValue = NULL;
     
	switch (m_WhiteSpace) {
	case PRESERVE: {
		return valueToProcess;
	}
	case REPLACE: {
		returnValue = (char*) replaceWhiteSpace(valueAsString).c_str();
		break;
	}
	case COLLAPSE: {
		returnValue = (char*) collapseWhiteSpace(valueAsString).c_str();               
		break;
	}
	}
        
	if (m_Buf) {
		delete [] m_Buf;
		m_Buf = NULL;
	}
	m_Buf = new char[strlen (returnValue) + 1];
	strcpy (m_Buf, returnValue);
	return m_Buf;
}
    
/**
 * Replaces all occurances of tab, line feed and carriage return with space
 * 
 * @param value The string to have white space characters replaced.
 * @return string The string with all white space characters replaced.
 */
const string& WhiteSpace::replaceWhiteSpace(
	string& value)
{
	m_strReturnVal = "";
	if (value.empty ()) return value;

	// Find white space characters and returns the first position
	unsigned long nPos = value.find_first_of (WHITE_SPACE_CHARS);
    
	// Check for position validity 
	if (string::npos==nPos) return value;
    
	unsigned long nOldIdx = 0; 
	while (string::npos != nPos)
	{
		m_strReturnVal.append(value.substr (nOldIdx, nPos - nOldIdx));
		m_strReturnVal.append(" ");

		// Get old position
		nOldIdx = ++nPos;    

		// Find the next white space characters from previous found position
		nPos = value.find_first_of(WHITE_SPACE_CHARS, nPos);
	}
    
	unsigned long nDataLen = value.length ();    // Get the length of the field value
	unsigned long nLen = nDataLen - nOldIdx;      // Get remaining number of characters   

	if (nLen > 0) {
		m_strReturnVal.append(value.substr(nOldIdx, nLen)); 
	}
	return m_strReturnVal;
}

/**
 * Collapses all white space in a string.
 * All occurances of tab, line feed and carriage return are replaced with
 * space, after which all sequences of spaces are collapsed to a single space.
 * 
 * @param value The string to have all white space collapsed
 * @return string The string with all white space collapsed.
 */
string const& WhiteSpace::collapseWhiteSpace(
	string& value)
{
	if (value.empty ()) return value;
	string replacedValue = replaceWhiteSpace(value);

	// Strip leading and trailing space
	string leadingStripped = stripLeadingWhiteSpace(replacedValue);
	replacedValue = stripTrailingWhiteSpace(leadingStripped);

	// Initialize return value to empty string
	m_strReturnVal = "";

	// Find space character and return the first position
	unsigned long nPos = replacedValue.find_first_of(' ');
    
	// Check for position validity */
	if (string::npos == nPos) {
		m_strReturnVal.assign(replacedValue);
		return m_strReturnVal;
	}
    
	unsigned long nOldIdx = 0; 
	while (string::npos != nPos)
	{
		m_strReturnVal.append(replacedValue.substr(nOldIdx, nPos - nOldIdx));

		// Only copy space character if NOT followed by another space character
		if (replacedValue.at(nPos+1) != ' ') {
			m_strReturnVal.append(" ");
		}

		// Get old position
		nOldIdx = ++nPos; 

		// Find the next entity reference characters from previous found position
		nPos = replacedValue.find_first_of(' ', nPos);
	}
    
	unsigned long nDataLen = replacedValue.length ();	// Get the length of the field value
	unsigned long nLen = nDataLen - nOldIdx;					// Get remaining number of characters   
	if (nLen > 0) {
		m_strReturnVal.append(replacedValue.substr(nOldIdx, nLen)); 
	}
	return m_strReturnVal;
}

const string& WhiteSpace::stripLeadingWhiteSpace(string& value)
{
	while (value.size() > 0)
	{
		if (isspace(value.at(0))) {
			value.erase(0, 1);
		}
		else {
			break;
		}
	}
	return value;
}

string const& WhiteSpace::stripTrailingWhiteSpace(
	string& value)
{
	while (value.size() > 0)
	{
		if (isspace(value.at(value.size() - 1))) {
			value.erase(value.size() - 1, 1);
		}
		else {
			break;
		}
	}
	return value;
}


}	/* namespace xqp */
