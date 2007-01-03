/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: [module].h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *	Revision rolls up the set of xsd classes for use with
 *	the zorba XQP package.
 *
 *	@author Paul Pedersen (pcp071098@yahoo.com)
 */


// Code derived from Apache Axis:

/*
 *   Copyright 2003-2004 The Apache Software Foundation.
 *	(c) Copyright IBM Corp. 2004, 2005 All Rights Reserved
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
 *
 *	@author Adrian Dick (adrian.dick@uk.ibm.com)
 */


#ifndef XQP_XSD_H
#define XQP_XSD_H


#include <time.h>
#include <ctime>
#include <string>
#include <vector>

#include "../util/xqpexception.h"

#include "../apr_base64.h"
#include "../HexCoder.h"



namespace xqp {

class Decimal;
class ENTITY;
class IDREF;
class Int;
class Integer;
class Long;
class Name;
class NCName;
class NMTOKEN;
class NonNegativeInteger;
class NonPositiveInteger;
class NormalizedString;
class Short;
class Token;
class UnsignedInt;
class UnsignedLong;
class UnsignedShort;



/*______________________________________________________________________
|  
|
|	The mapping of basic xsd types to the C++ language types.
|	
|	The following xsd basic types are supported:
|	anyURI, base64Binary, boolean, byte, date, dateTime,
|	decimal, double, duration, float, hexBinary, int, integer,
|	long, NMTOKEN, NOTATION, QName, short, string, time,
|	unsignedByte, unsignedInt, unsignedLong, and unsignedShort.
|_______________________________________________________________________*/

typedef std::string					xsd_anyURI;
typedef std::string					xsd_string;
typedef std::string					xsd_normalizedString;
typedef std::string					xsd_token;
typedef std::string					xsd_language;
typedef std::string					xsd_Name;
typedef std::string					xsd_NCName;
typedef std::string					xsd_ID;
typedef std::string					xsd_IDREF;
typedef std::string					xsd_IDREFS;
typedef std::string					xsd_ENTITY;
typedef std::string					xsd_ENTITIES;
typedef std::string					xsd_NMTOKEN;
typedef std::string					xsd_NMTOKENS;
typedef long long						xsd_integer;
typedef int									xsd_int;
typedef long long						xsd_long;
typedef short								xsd_short;
typedef double							xsd_decimal;
typedef float								xsd_float;
typedef double							xsd_double;
typedef bool								xsd_boolean;
typedef signed char					xsd_byte;
typedef std::string					xsd_QName;
typedef std::string					xsd_NOTATION;
typedef struct tm						xsd_dateTime;
typedef struct tm						xsd_date;
typedef struct tm						xsd_time;
typedef struct tm						xsd_gYearMonth;
typedef struct tm						xsd_gYear;
typedef struct tm						xsd_gMonthDay;
typedef struct tm						xsd_gDay;
typedef struct tm						xsd_gMonth;
typedef long								xsd_duration;
typedef unsigned long long	xsd_nonNegativeInteger;
typedef unsigned char				xsd_unsignedByte;
typedef unsigned int				xsd_unsignedInt;
typedef unsigned long long	xsd_unsignedLong;
typedef unsigned short			xsd_unsignedShort;
typedef long long						xsd_nonPositiveInteger;
typedef unsigned long long	xsd_positiveInteger;
typedef long long						xsd_negativeInteger;

typedef struct
{
	xsd_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
} xsd_base64Binary;

typedef struct
{
	xsd_unsignedByte* data; // Binary data
	uint32_t size;					// Length, in bytes
} xsd_hexBinary;

typedef struct
{
	// an array of xml encoded strings.
	std::vector<std::string> _array;

} AnyType;





/*______________________________________________________________________
|  
|	Schema primitive type hierarchy.
|	[http://www.w3.org/TR/xmlschema-2/#built-in-primitive-datatypes]
|_______________________________________________________________________*/

/**
 *	@class AnySimpleType
 *	@brief Interface for all XSD built-in simple type.
 */
class AnySimpleType
{
public:
	AnySimpleType();
	virtual ~AnySimpleType();

public:
	/**
	 * This method provides ability to determine if value is nil.
	 * @return true is value is nil, otherwise false
	 */
	bool isNil();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	virtual void* getValue() = 0;

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	virtual XSDTYPE getType() = 0;

	/**
	 * Provides the contained value in it's on-the-wire string form.
	 * @return Serialized form of value
	 */
	Char* serialize();

	/**
	 * Takes the value in it's on-the-wire string form
	 * @param Serialized form of value
	 */
	void deserialize(const Char* value);

protected:
	/**
	 * Take partially serialized value, process WhiteSpace and validate Pattern.
	 * @param value partially serialized value
	 * @return Serialized form of value
	 */
	Char* serialize(const Char* value) throw (SoapException);

	/**
	 * Set whether or not value is nil
	 * @param nil
	 */
	void setNil(bool nil);

	/**
	 * Replace all XML reserved characters in string
	 * @param value Original string
	 * @return String with all reserved characters replaced
	 */
	const String& replaceReservedCharacters(String& value);

	/**
	 * Creates a WhiteSpace object which preserve original string form
	 * @return WhiteSpace object
	 */
	virtual WhiteSpace* getWhiteSpace();

	/**
	 * Creates an Enumeration object. Enumeration is not defined for IAnySimpleType
	 * so an unset Enumeration object is created.
	 * @return Enumeration object
	 */
	virtual Enumeration* getEnumeration();
   
	/**
	 * Create a Pattern object with no rules
	 * @return Pattern object
	 */
	Pattern* getPattern();

	/**
	 * Reserved Characters
	 */
	enum
	{
		GREATER_THAN_CHAR		=    '>',		/* Greater than character */
		LESSER_THAN_CHAR		=    '<',		/* Less than character */
		SINGLE_QUOTE_CHAR		=    '\'',	/* Single quotation character */
		DOUBLE_QUOTE_CHAR		=    '\"',	/* Double quotation character */
		AMPERSAND_CHAR			=    '&'		/* Ampersand character */
	};
	Char* m_Buf;
   
private:
	bool m_isNil;
	String m_strReturnVal;

};




class AnyURI : public AnySimpleType 
{
public:
	/**
	 * Constructor
	 */
	AnyURI();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	AnyURI(const xsd_anyURI value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value. Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_anyURI getAnyURI();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 * 		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();
    
protected:
	/**
	 * Deserialized AnyURI value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of AnyURI value.
	 * @return Deserialized AnyURI value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_anyURI deserializeAnyURI(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize AnyURI value to it's on-the-wire string form.
	 * @param value The AnyURI value to be serialized.
	 * @return Serialized form of AnyURI value.
	 */
	Char* serialize(const xsd_anyURI value) throw (SoapException);

	/**
	 * Creates a WhiteSpace object to replace whitespace
	 * @return WhiteSpace object set to replace whitespace
	 */
	WhiteSpace* getWhiteSpace();

	/**
	 * Creates a minLength object, used to allocate storage.  By default the AnyURI
	 * object does not have this specified, so this is an unset minLength object.
	 * @return An unset MinLength object
	 */
	MinLength* getMinLength();

	/**
	 * Creates a maxLength object, used to allocate storage.  By default the AnyURI
	 * object does not have this specified, so this is an unset maxLength object.
	 * @return An unset MaxLength object
	 */
	MaxLength* getMaxLength();

	/**
	 * Creates a Length object, used to allocate storage.  By default the AnyURI
	 * object does not have this specified, so this is an unset Length object.
	 * @return An unset Length object
	 */
	Length* getLength();

};




class Base64Binary : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */    
	Base64Binary();
	
	/**
	 * Destructor
	 */    
	~Base64Binary();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Base64Binary(const xsd_base64Binary* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_base64Binary* getBase64Binary();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();
    
protected:
	/**
	 * Deserialized Base64Binary value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Base64Binary value.
	 * @return Deserialized Base64Binary value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_base64Binary * deserializeBase64Binary(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Base64Binary value to it's on-the-wire string form.
	 * @param value The Base64Binary value to be serialized.
	 * @return Serialized form of Base64Binary value.
	 */
	Char* serialize(const xsd_base64Binary * value) throw (SoapException);

	/**
	 * Creates a minLength object, used to allocate storage.  By default the Base64Binary
	 * object does not have this specified, so this is an unset minLength object.
	 * @return An unset MinLength object
	 */
	MinLength* getMinLength();

	/**
	 * Creates a maxLength object, used to allocate storage.  By default the Base64Binary
	 * object does not have this specified, so this is an unset maxLength object.
	 * @return An unset MaxLength object
	 */
	MaxLength* getMaxLength();

	/**
	 * Creates a Length object, used to allocate storage.  By default the Base64Binary
	 * object does not have this specified, so this is an unset Length object.
	 * @return An unset Length object
	 */
	Length* getLength();
	
	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};







class Boolean : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	Boolean();
	
	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Boolean(const xsd_boolean* value);
	
	/**
	 * Destructor
	 */
	~Boolean();

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_boolean* getBoolean();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();
    	
protected:
	/**
	 * Deserialized boolean value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of boolean value.
	 * @return Deserialized boolean value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_boolean * deserializeBoolean(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize boolean value to it's on-the-wire string form.
	 * @param value The boolean value to be serialized.
	 * @return Serialized form of boolean value.
	 */
	Char* serialize(const xsd_boolean * value) throw (SoapException);

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

	/**
	 * Creates an Enumeration object to collapse whitespace
	 * @return Enumeration object set to collapse whitespace
	 */
	Enumeration* getEnumeration();

};





class Byte : public Short
{
public:
	/**
	 * Constructor
	 */
	Byte();

	/**
	 * Destructor
	 */
	~Byte();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Byte(const xsd_byte* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_byte* getByte();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized Byte value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Byte value.
	 * @return Deserialized Byte value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_byte* deserializeByte(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Byte value to it's on-the-wire string form.
	 * @param value The Byte value to be serialized.
	 * @return Serialized form of Byte value.
	 */  
	Char* serialize(const xsd_byte* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the Byte type this is defined as
	 * -128.
	 * @return MinInclusive object
	 */
	virtual MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the Byte type this is defined as
	 * -129.
	 * @return MinExclusive object
	 */
	virtual MinExclusive* getMinExclusive();

	/**
	 * Creates a MaxInclusive object.  For the Byte type this is defined as
	 * 127.
	 * @return MaxInclusive object
	 */
	virtual MaxInclusive* getMaxInclusive();

	/**
	 * Creates a Maxexclusive object.  For the Byte type this is defined as
	 * 128.
	 * @return Maxexclusive object
	 */
	virtual MaxExclusive* getMaxExclusive();

};





class Date : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	Date();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Date(const xsd_date* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_date* getDate();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();
	
protected:
	/**
	 * Deserialized Date value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Date value.
	 * @return Deserialized Date value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_date* deserializeDate(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Date value to it's on-the-wire string form.
	 * @param value The Date value to be serialized.
	 * @return Serialized form of Date value.
	 */
	Char* serialize(const xsd_date* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the Date type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the Date type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();    

	/**
	 * Creates a MaxInclusive object.  For the Date type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the Date type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();    

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class DateTime : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	DateTime();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	DateTime(const xsd_dateTime* value);
	
	/**
	 * Destructor
	 */
	~DateTime();

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_dateTime* getDateTime();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized DateTime value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of DateTime value.
	 * @return Deserialized Date value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_dateTime* deserializeDateTime(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize DateTime value to it's on-the-wire string form.
	 * @param value The DateTime value to be serialized.
	 * @return Serialized form of DateTime value.
	 */
	Char* serialize(const xsd_dateTime* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the DateTime type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the DateTime type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();    

	/**
	 * Creates a MaxInclusive object.  For the DateTime type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the DateTime type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();    

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class Decimal : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	Decimal();
	
	/**
	 * Destructor
	 */
	~Decimal();
	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Decimal(const xsd_decimal* value);
	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();
	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_decimal* getDecimal();
	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();
   
protected:
	/**
	 * Deserialized Decimal value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Decimal value.
	 * @return Deserialized Decimal value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_decimal* deserializeDecimal(const Char* valueAsChar) throw (SoapException);
	/**
	 * Serialize Decimal value to it's on-the-wire string form.
	 * @param value The Decimal value to be serialized.
	 * @return Serialized form of Decimal value.
	 */
	Char* serialize(const xsd_decimal* value) throw (SoapException);
	/**
	 * Creates a MinInclusive object.  For the Decimal type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	virtual MinInclusive* getMinInclusive();
	/**
	 * Creates a MinExclusive object.  For the Decimal type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	virtual MinExclusive* getMinExclusive();
	/**
	 * Creates a MaxInclusive object.  For the Decimal type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	virtual MaxInclusive* getMaxInclusive();
	/**
	 * Creates a MaxExclusive object.  For the Decimal type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	virtual MaxExclusive* getMaxExclusive();
	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();
	/**
	 * Creates a TotalDigits object.  For the Decimal type this is undefined,
	 * so an unset TotalDigits object is created.
	 * @return TotalDigits object
	 */
	TotalDigits* getTotalDigits();
	/**
	 * Creates a FractionDigits object.  For the Decimal type this is undefined,
	 * so an unset FractionDigits object is created.
	 * @return FractionDigits object
	 */
	FractionDigits* getFractionDigits();

};




class Double : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	Double();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Double(const xsd_double* value);
 
	 /**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_double* getDouble();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();
	
protected:
	/**
	 * Deserialized Double value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Double value.
	 * @return Deserialized Double value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_double* deserializeDouble(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Double value to it's on-the-wire string form.
	 * @param value The Double value to be serialized.
	 * @return Serialized form of Double value.
	 */
	Char* serialize(const xsd_double* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the Double type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	virtual MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the Double type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	virtual MinExclusive* getMinExclusive();

	/**
	 * Creates a MaxInclusive object.  For the Double type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	virtual MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the Double type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	virtual MaxExclusive* getMaxExclusive();

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class Duration : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	Duration();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Duration(const xsd_duration* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_duration* getDuration();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized Duration value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Duration value.
	 * @return Deserialized Duration value. 
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_duration* deserializeDuration(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Duration value to it's on-the-wire string form.
	 * @param value The Duration value to be serialized.
	 * @return Serialized form of Duration value.
	 */
	Char* serialize(const xsd_duration* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the Duration type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the Duration type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();

	/**
	 * Creates a MaxInclusive object.  For the Duration type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the Duration type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class ENTITIES : public ENTITY
{
public:
	/**
	 * Constructor
	 */
	ENTITIES();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	ENTITIES(const xsd_ENTITIES value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_ENTITIES getENTITIES();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized ENTITIES value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of ENTITIES value.
	 * @return Deserialized ENTITIES value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_ENTITIES deserializeENTITIES(const Char* valueAsChar) throw (SoapException);

};





class ENTITY : public NCName
{
public:
	/**
	 * Constructor
	 */
	ENTITY();
	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	ENTITY(const xsd_ENTITY value);
	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();
	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_ENTITY getENTITY();
	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized ENTITY value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of ENTITY value.
	 * @return Deserialized ENTITY value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_ENTITY deserializeENTITY(const Char* valueAsChar) throw (SoapException);

};




class Float : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	Float();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Float(const xsd_float* value);

	/**
	 * Destructor
	 */
	~Float();

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_float* getFloat();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized Float value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Float value.
	 * @return Deserialized Float value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_float* deserializeFloat(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Float value to it's on-the-wire string form.
	 * @param value The Float value to be serialized.
	 * @return Serialized form of Float value.
	 */
	Char* serialize(const xsd_float* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the Float type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	virtual MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the Float type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	virtual MinExclusive* getMinExclusive();

	/**
	 * Creates a MaxInclusive object.  For the Float type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	virtual MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the Float type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	virtual MaxExclusive* getMaxExclusive();

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class GDay : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	GDay();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	GDay(const xsd_gDay* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gDay* getGDay();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized GDay value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of GDay value.
	 * @return Deserialized GDay value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gDay* deserializeGDay(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize GDay value to it's on-the-wire string form.
	 * @param value The GDay value to be serialized.
	 * @return Serialized form of GDay value.
	 */
	Char* serialize(const xsd_gDay* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the GDay type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the GDay type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();    

	/**
	 * Creates a MaxInclusive object.  For the GDay type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the GDay type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();    

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class GMonth : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	GMonth();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	GMonth(const xsd_gMonth* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gMonth* getGMonth();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized GMonth value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of GMonth value.
	 * @return Deserialized GMonth value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gMonth* deserializeGMonth(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize GMonth value to it's on-the-wire string form.
	 * @param value The GMonth value to be serialized.
	 * @return Serialized form of GMonth value.
	 */
	Char* serialize(const xsd_gMonth* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the GMonth type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the GMonth type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();    

	/**
	 * Creates a MaxInclusive object.  For the GMonth type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the GMonth type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();    

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class GMonthDay : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	GMonthDay();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	GMonthDay(const xsd_gMonthDay* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gMonthDay* getGMonthDay();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();
  
protected:
	/**
	 * Deserialized GMonthDay value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of GMonthDay value.
	 * @return Deserialized GMonthDay value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gMonthDay* deserializeGMonthDay(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize GMonthDay value to it's on-the-wire string form.
	 * @param value The GMonthDay value to be serialized.
	 * @return Serialized form of GMonthDay value.
	 */
	Char* serialize(const xsd_gMonthDay* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the GMonthDay type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the GMonthDay type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();    

	/**
	 * Creates a MaxInclusive object.  For the GMonthDay type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the GMonthDay type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();    

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};



class GYear : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	GYear();
	
	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	GYear(const xsd_gYear* value);
	
	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gYear* getGYear();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized GYear value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of GYear value.
	 * @return Deserialized GYear value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gYear* deserializeGYear(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize GYear value to it's on-the-wire string form.
	 * @param value The GYear value to be serialized.
	 * @return Serialized form of GYear value.
	 */
	Char* serialize(const xsd_gYear* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the GYear type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the GYear type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();    

	/**
	 * Creates a MaxInclusive object.  For the GYear type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the GYear type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();    

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class GYearMonth : public IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	GYearMonth();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	GYearMonth(const xsd_gYearMonth* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gYearMonth* getGYearMonth();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized GYearMonth value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of GYearMonth value.
	 * @return Deserialized GYearMonth value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_gYearMonth* deserializeGYearMonth(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize GYearMonth value to it's on-the-wire string form.
	 * @param value The GYearMonth value to be serialized.
	 * @return Serialized form of GYearMonth value.
	 */
	Char* serialize(const xsd_gYearMonth* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the GYearMonth type this is undefined, 
	 * so an unset MinInclusive object is created.
	 * @return MinInclusive object
	 */
	MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the GYearMonth type this is undefined, 
	 * so an unset MinExclusive object is created.
	 * @return MinExclusive object
	 */
	MinExclusive* getMinExclusive();    

	/**
	 * Creates a MaxInclusive object.  For the GYearMonth type this is undefined, 
	 * so an unset MaxInclusive object is created.
	 * @return MaxInclusive object
	 */
	MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the GYearMonth type this is undefined, 
	 * so an unset MaxExclusive object is created.
	 * @return MaxExclusive object
	 */
	MaxExclusive* getMaxExclusive();    

	/**
	 * Creates a WhiteSpace object to collapse whitespace
	 * @return WhiteSpace object set to collapse whitespace
	 */
	WhiteSpace* getWhiteSpace();

};




class HexBinary : public IAnySimpleType
{
public:
	/**
	 * Constructor.
 	 */
	HexBinary();

	/**
	 * Destructor.
	 */
	~HexBinary();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	HexBinary(const xsd_hexBinary* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_hexBinary* getHexBinary();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized HexBinary value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of HexBinary value.
	 * @return Deserialized HexBinary value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_hexBinary * deserializeHexBinary(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize HexBinary value to it's on-the-wire string form.
	 * @param value The HexBinary value to be serialized.
	 * @return Serialized form of HexBinary value.
	 */
	Char* serialize(const xsd_hexBinary * value) throw (SoapException);

	/**
	 * Creates a minLength object, used to allocate storage.  By default the HexBinary
	 * object does not have this specified, so this is an unset minLength object.
	 * @return An unset MinLength object
	 */
	MinLength* getMinLength();

	/**
	 * Creates a maxLength object, used to allocate storage.  By default the HexBinary
	 * object does not have this specified, so this is an unset maxLength object.
	 * @return An unset MaxLength object
	 */
	MaxLength* getMaxLength();

	/**
	 * Creates a Length object, used to allocate storage.  By default the HexBinary
	 * object does not have this specified, so this is an unset Length object.
	 * @return An unset Length object
	 */
	Length* getLength();

};




/* Entity reference characters */
const Char XML_ENTITY_REFERENCE_CHARS[]    = "<>&\"\'";

/* Encoded string for less than character */
const Char ENCODED_LESSER_STR[]            = "&lt;";    

/* Encoded string for greator than character */
const Char ENCODED_GREATER_STR[]        = "&gt;";    

/* Encoded string for ampersand character */
const Char ENCODED_AMPERSAND_STR[]        = "&amp;";    

/* Encoded string for single quote character */
const Char ENCODED_DBL_QUOTE_STR[]        = "&quot;";    

/* Encoded string for double quote character */
const Char ENCODED_SGL_QUOTE_STR[]        = "&apos;";    




class ID : public NCName
{
public:
	/**
	 * Constructor
	 */
	ID();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	ID(const xsd_ID value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_ID getID();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized ID value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of ID value.
	 * @return Deserialized ID value. Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_ID deserializeID(const Char* valueAsChar) throw (SoapException);

};




class IDREF : public NCName
{
public:
	/**
	 * Constructor
	 */
	IDREF();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	IDREF(const xsd_IDREF value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_IDREF getIDREF();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized IDREF value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of IDREF value.
	 * @return Deserialized IDREF value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_IDREF deserializeIDREF(const Char* valueAsChar) throw (SoapException);

};





class IDREFS : public IDREF
{
public:
	/**
	 * Constructor
	 */
	IDREFS();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	IDREFS(const xsd_IDREFS value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_IDREFS getIDREFS();
	
	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized IDREFS value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of IDREFS value.
	 * @return Deserialized IDREFS value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_IDREFS deserializeIDREFS(const Char* valueAsChar) throw (SoapException);

};





class Int : public Long
{
public:
	/**
	 * Constructor
	 */
	Int();

	/**
	 * Destructor
	 */
	~Int();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Int(const xsd_int* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_int* getInt();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized Int value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Int value.
	 * @return Deserialized Int value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_int* deserializeInt(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Int value to it's on-the-wire string form.
	 * @param value The Int value to be serialized.
	 * @return Serialized form of Int value.
	 */  
	Char* serialize(const xsd_int* value) throw (SoapException);

	/**
	 * Creates a MinInclusive object.  For the Int type this is defined as
	 * -2147483648.
	 * @return MinInclusive object
	 */
	virtual MinInclusive* getMinInclusive();

	/**
	 * Creates a MinExclusive object.  For the Int type this is defined as
	 * -2147483649.
	 * @return MinExclusive object
	 */
	virtual MinExclusive* getMinExclusive();

	/**
	 * Creates a MaxInclusive object.  For the Int type this is defined as
	 * 2147483647.
	 * @return MaxInclusive object
	 */
	virtual MaxInclusive* getMaxInclusive();

	/**
	 * Creates a MaxExclusive object.  For the Int type this is defined as
	 * 2147483648.
	 * @return MaxExclusive object
	 */
	virtual MaxExclusive* getMaxExclusive();

};





class Integer : public Decimal
{
public:
	/**
	 * Constructor
	 */
	Integer();

	/**
	 * Destructor
	 */
	~Integer();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Integer(const xsd_integer* value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_integer* getInteger();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized Integer value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Integer value.
	 * @return Deserialized Integer value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_integer* deserializeInteger(const Char* valueAsChar) throw (SoapException);

	/**
	 * Serialize Integer value to it's on-the-wire string form.
	 * @param value The Integer value to be serialized.
	 * @return Serialized form of Integer value.
	 */
	Char* serialize(const xsd_integer* value) throw (SoapException);

	/**
	 * Creates a FractionDigits object.  For the Integer type this is defined as 0.
	 * @return FractionDigits object
	 */
	FractionDigits* getFractionDigits();

};




class Language : public Token
{
public:
	/**
	 * Constructor
	 */
	Language();

	/**
	 * Constructor providing a value for later serialization
	 * @param value The value to be serialized
	 */
	Language(const xsd_language value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_language getLanguage();

	/**
	 * Get the deserialized value
	 * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	void* getValue();

protected:
	/**
	 * Deserialized Language value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Language value.
	 * @return Deserialized Language value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd_language deserializeLanguage(const Char* valueAsChar) throw (SoapException);

};





class Long : public Integer
{
public:
  /**
   * Constructor
   */
  Long();

  /**
   * Destructor
   */
  ~Long();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  Long(const xsd_long* value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_long* getLong();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized Long value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of Long value.
   * @return Deserialized Long value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_long* deserializeLong(const Char* valueAsChar) throw (SoapException);

  /**
   * Serialize Long value to it's on-the-wire string form.
   * @param value The Long value to be serialized.
   * @return Serialized form of Long value.
   */  
  Char* serialize(const xsd_long* value) throw (SoapException);

  /**
   * Creates a MinInclusive object.  For the Long type this is defined as
   * -9223372036854775808.
   * @return MinInclusive object
   */
  virtual MinInclusive* getMinInclusive();
  
  /**
   * Creates a MaxInclusive object.  For the Long type this is defined as
   * 9223372036854775807.
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

};





class NCName : public Name
{
public:
  /**
   * Constructor
   */
  NCName();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NCName(const xsd_NCName value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_NCName getNCName();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized NCName value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NCName value.
   * @return Deserialized NCName value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_NCName deserializeNCName(const Char* valueAsChar) throw (SoapException);

};





class NMTOKEN : public Token
{
public:
  /**
   * Constructor
   */
  NMTOKEN();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NMTOKEN(const xsd_NMTOKEN value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_NMTOKEN getNMTOKEN();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized NMTOKEN value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NMTOKEN value.
   * @return Deserialized NMTOKEN value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_NMTOKEN deserializeNMTOKEN(const Char* valueAsChar) throw (SoapException);

};





class NMTOKENS : public NMTOKEN
{
public:
	/**
	 * Constructor
	 */
	NMTOKENS();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NMTOKENS(const xsd_NMTOKENS value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_NMTOKENS getNMTOKENS();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized NMTOKENS value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NMTOKENS value.
   * @return Deserialized NMTOKENS value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_NMTOKENS deserializeNMTOKENS(const Char* valueAsChar) throw (SoapException);

};




class NOTATION : public IAnySimpleType
{
public:
  /**
   * Constructor
   */
  NOTATION();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NOTATION(const xsd_NOTATION value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_NOTATION getNOTATION();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized NOTATION value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NOTATION value.
   * @return Deserialized NOTATION value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
	xsd_NOTATION deserializeNOTATION(const Char* valueAsChar) throw (SoapException);

  /**
   * Serialize NOTATION value to it's on-the-wire string form.
   * @param value The NOTATION value to be serialized.
   * @return Serialized form of NOTATION value.
   */ 
  Char* serialize(const xsd_NOTATION value) throw (SoapException);

  /**
   * Creates a WhiteSpace object to replace whitespace
   * @return WhiteSpace object set to replace whitespace
   */
  WhiteSpace* getWhiteSpace();

  /**
   * Creates a minLength object, used to allocate storage.  By default the NOTATION
   * object does not have this specified, so this is an unset minLength object.
   * @return An unset MinLength object
   */
  MinLength* getMinLength();

  /**
   * Creates a maxLength object, used to allocate storage.  By default the NOTATION
   * object does not have this specified, so this is an unset maxLength object.
   * @return An unset MaxLength object
   */
  MaxLength* getMaxLength();

  /**
   * Creates a Length object, used to allocate storage.  By default the NOTATION
   * object does not have this specified, so this is an unset Length object.
   * @return An unset Length object
   */
  Length* getLength();

};





class Name : public Token
{
public:
  /**
   * Constructor
   */
  Name();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  Name(const xsd_Name value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_Name getName();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized Name value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of Name value.
   * @return Deserialized Name value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_Name deserializeName(const Char* valueAsChar) throw (SoapException);

};






class NegativeInteger : public NonPositiveInteger
{
public:
  /**
   * Constructor
   */
  NegativeInteger();
  
  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NegativeInteger(const xsd_negativeInteger* value) throw (SoapException);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_negativeInteger* getNegativeInteger();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized NegativeInteger value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NegativeInteger value.
   * @return Deserialized NegativeInteger value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_negativeInteger* deserializeNegativeInteger(const Char* valueAsChar) throw (SoapException);

  /**
   * Creates a MaxInclusive object.  For the NegativeInteger type this is
   * defined as -1.  
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

};






class NonNegativeInteger : public Integer
{
public:
  /**
   * Constructor
   */
  NonNegativeInteger();
  
  /**
   * Destructor
   */
  ~NonNegativeInteger();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NonNegativeInteger(const xsd_nonNegativeInteger* value)
	throw (SoapException);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_nonNegativeInteger* getNonNegativeInteger();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  
  /**
   * Deserialized NonNegativeInteger value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NonNegativeInteger value.
   * @return Deserialized NonNegativeInteger value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
   xsd_nonNegativeInteger* deserializeNonNegativeInteger(const Char* valueAsChar)
	 throw (SoapException);

  /**
   * Serialize NonNegativeInteger value to it's on-the-wire string form.
   * @param value The NonNegativeInteger value to be serialized.
   * @return Serialized form of NonNegativeInteger value.
   */
  Char* serialize(const xsd_nonNegativeInteger* value)
	throw (SoapException);

  /**
   * Creates a MinInclusive object.  For the NonNegativeInteger type this is
   * defined as 0.
   * @return MinInclusive object
   */
  virtual MinInclusive* getMinInclusive();

};





class NonPositiveInteger : public Integer
{
public:
  /**
   * Constructor
   */
  NonPositiveInteger();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NonPositiveInteger(const xsd_nonPositiveInteger* value)
	throw (SoapException);
  
  /**
   * Destructor
   */
  ~NonPositiveInteger();

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_nonPositiveInteger* getNonPositiveInteger();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized NonPositiveInteger value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NonPositiveInteger value.
   * @return Deserialized NonPositiveInteger value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_nonPositiveInteger* deserializeNonPositiveInteger(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Creates a MaxInclusive object.  For the NonPositiveInteger type this is
   * defined as 0.
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

};






class NormalizedString : public String
{
public:
  /**
   * Constructor
   */
  NormalizedString();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  NormalizedString(const xsd_normalizedString value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_normalizedString getNormalizedString();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized NormalizedString value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of NormalizedString value.
   * @return Deserialized NormalizedString value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_normalizedString deserializeNormalizedString(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Creates a WhiteSpace object to replace whitespace
   * @return WhiteSpace object set to replace whitespace
   */
  WhiteSpace* getWhiteSpace();

};





class PositiveInteger : public NonNegativeInteger
{
public:
  /**
   * Constructor
   */
  PositiveInteger();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  PositiveInteger(const xsd_positiveInteger* value)
	throw (SoapException);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_positiveInteger* getPositiveInteger();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized PositiveInteger value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of PositiveInteger value.
   * @return Deserialized PositiveInteger value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_positiveInteger* deserializePositiveInteger(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Creates a MinInclusive object.  For the PositiveInteger type this is
   * defined as 1.
   * @return MinInclusive object
   */
  virtual MinInclusive* getMinInclusive();

};





class Short : public Int
{
public:
  /**
   * Constructor
   */
  Short();

  /**
   * Destructor
   */
  ~Short();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  Short(const xsd_short* value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_short* getShort();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized Short value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of Short value.
   * @return Deserialized Short value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_short* deserializeShort(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Serialize Short value to it's on-the-wire string form.
   * @param value The Short value to be serialized.
   * @return Serialized form of Short value.
   */  
  Char* serialize(const xsd_short* value) throw (SoapException);

  /**
   * Creates a MinInclusive object.  For the Short type this is defined as
   * -32768.
   * @return MinInclusive object
   */
  virtual MinInclusive* getMinInclusive();

  /**
   * Creates a MinExclusive object.  For the Short type this is defined as
   * -32769.
   * @return MinExclusive object
   */
  virtual MinExclusive* getMinExclusive();

  /**
   * Creates a MaxInclusive object.  For the Short type this is defined as
   * 32767.
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

  /**
   * Creates a MaxExclusive object.  For the Short type this is defined as
   * 32768.
   * @return MaxExclusive object
   */
  virtual MaxExclusive* getMaxExclusive();

};





class String : public IAnySimpleType
{
public:
  /**
   * Constructor
   */
  String();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  String(const xsd_string value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_string getString();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized String value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of String value.
   * @return Deserialized String value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
	xsd_string deserializeString(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Serialize String value to it's on-the-wire string form.
   * @param value The String value to be serialized.
   * @return Serialized form of String value.
   */   
	Char* serialize(const xsd_string value)
	throw (SoapException);

  /**
   * Creates a minLength object, used to allocate storage.  By default the String
   * object does not have this specified, so this is an unset minLength object.
   * @return An unset MinLength object
   */
  MinLength* getMinLength();

  /**
   * Creates a maxLength object, used to allocate storage.  By default the String
   * object does not have this specified, so this is an unset maxLength object.
   * @return An unset MaxLength object
   */
  MaxLength* getMaxLength();

  /**
   * Creates a Length object, used to allocate storage.  By default the String
   * object does not have this specified, so this is an unset Length object.
   * @return An unset Length object
   */
  Length* getLength();

};





class Time : public IAnySimpleType
{
public:
  /**
   * Constructor
   */
  Time();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  Time(const xsd_time* value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_time* getTime();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
	/**
	 * Deserialized Time value from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of Time value.
	 * @return Deserialized Time value.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
  xsd_time* deserializeTime(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Serialize Time value to it's on-the-wire string form.
   * @param value The Time value to be serialized.
   * @return Serialized form of Time value.
   */
  Char* serialize(const xsd_time* value)
	throw (SoapException);

  /**
   * Creates a MinInclusive object.  For the Time type this is undefined, 
   * so an unset MinInclusive object is created.
   * @return MinInclusive object
   */
  MinInclusive* getMinInclusive();

  /**
   * Creates a MinExclusive object.  For the Time type this is undefined, 
   * so an unset MinExclusive object is created.
   * @return MinExclusive object
   */
  MinExclusive* getMinExclusive();  

  /**
   * Creates a MaxInclusive object.  For the Time type this is undefined, 
   * so an unset MaxInclusive object is created.
   * @return MaxInclusive object
   */
  MaxInclusive* getMaxInclusive();

  /**
   * Creates a MaxExclusive object.  For the Time type this is undefined, 
   * so an unset MaxExclusive object is created.
   * @return MaxExclusive object
   */
  MaxExclusive* getMaxExclusive();  

  /**
   * Creates a WhiteSpace object to collapse whitespace
   * @return WhiteSpace object set to collapse whitespace
   */
  WhiteSpace* getWhiteSpace();

};





class Token : public NormalizedString
{
public:
  /**
   * Constructor
   */
  Token();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  Token(const xsd_token value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_token getToken();

protected:
  /**
   * Deserialized Token value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of Token value.
   * @return Deserialized Token value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_token deserializeToken(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Creates a WhiteSpace object to replace whitespace
   * @return WhiteSpace object set to collapse whitespace
   */
  WhiteSpace* getWhiteSpace();

};





class UnsignedByte : public UnsignedShort
{
public:
  /**
   * Constructor
   */
  UnsignedByte();
  
  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  UnsignedByte(const xsd_unsignedByte* value);
  
  /**
   * Destructor
   */
  ~UnsignedByte();

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedByte* getUnsignedByte();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized UnsignedByte value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of UnsignedByte value.
   * @return Deserialized UnsignedByte value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedByte* deserializeUnsignedByte(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Serialize UnsignedByte value to it's on-the-wire string form.
   * @param value The UnsignedByte value to be serialized.
   * @return Serialized form of UnsignedByte value.
   */  
  Char* serialize(const xsd_unsignedByte* value)
	throw (SoapException);

  /**
   * Creates a MaxInclusive object.  For the UnsignedByte type this is
   * defined as 255.
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

};





class UnsignedInt : public UnsignedLong
{
public:
  /**
   * Constructor
   */
  UnsignedInt();
  
  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  UnsignedInt(const xsd_unsignedInt* value);
  
  /**
   * Destructor
   */
  ~UnsignedInt();

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedInt* getUnsignedInt();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized UnsignedInt value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of UnsignedInt value.
   * @return Deserialized UnsignedInt value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedInt* deserializeUnsignedInt(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Serialize UnsignedInt value to it's on-the-wire string form.
   * @param value The UnsignedInt value to be serialized.
   * @return Serialized form of UnsignedInt value.
   */  
  Char* serialize(const xsd_unsignedInt* value)
	throw (SoapException);

  /**
   * Creates a MaxInclusive object.  For the UnsignedInt type this is
   * defined as 4294967295.
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

};





class UnsignedLong : public NonNegativeInteger
{
public:
  /**
   * Constructor
   */
  UnsignedLong();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  UnsignedLong(const xsd_unsignedLong* value);

  /**
   * Destructor
   */
  ~UnsignedLong();

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedLong* getUnsignedLong();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized UnsignedLong value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of UnsignedLong value.
   * @return Deserialized UnsignedLong value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedLong* deserializeUnsignedLong(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Serialize UnsignedLong value to it's on-the-wire string form.
   * @param value The UnsignedLong value to be serialized.
   * @return Serialized form of UnsignedLong value.
   */  
  Char* serialize(const xsd_unsignedLong* value)
	throw (SoapException);

  /**
   * Creates a MaxInclusive object.  For the UnsignedLong type this is
   * defined as 18446744073709551615.
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

};




class UnsignedShort : public UnsignedInt
{
public:
  /**
   * Constructor
   */
  UnsignedShort();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  UnsignedShort(const xsd_unsignedShort* value);
  
  /**
   * Destructor
   */
  ~UnsignedShort();

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedShort* getUnsignedShort();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
  /**
   * Deserialized UnsignedShort value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of UnsignedShort value.
   * @return Deserialized UnsignedShort value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_unsignedShort* deserializeUnsignedShort(const Char* valueAsChar)
	throw (SoapException);

  /**
   * Serialize UnsignedShort value to it's on-the-wire string form.
   * @param value The UnsignedShort value to be serialized.
   * @return Serialized form of UnsignedShort value.
   */  
  Char* serialize(const xsd_unsignedShort* value)
	throw (SoapException);

  /**
   * Creates a MaxInclusive object.  For the UnsignedShort type this is
   * defined as 65535.
   * @return MaxInclusive object
   */
  virtual MaxInclusive* getMaxInclusive();

};




class XSD_QName : public IAnySimpleType
{
public:
  /**
   * Constructor
   */
  XSD_QName();

  /**
   * Constructor providing a value for later serialization
   * @param value The value to be serialized
   */
  XSD_QName(const xsd_QName value);

  /**
   * Get the xsd type of this simple type.
   * @return the xsd type of this simple type
   */
  XSDTYPE getType();

  /**
   * Get the deserialized value.
   * @return Deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd_QName getQName();

  /**
   * Get the deserialized value
   * @return the deserialized value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  void* getValue();

protected:
	/**
	 * Deserialize QName from it's on-the-wire string form.
	 * @param valueAsChar Serialized form of QName.
	 * @return Deserialized QName.
	 *		Note: it is the responsibility of the calling code to delete this value!
	 */
  xsd_QName deserializeQName(const Char* valueAsChar) throw (SoapException);

  /**
   * Serialize QName to it's on-the-wire string form.
   * @param value The QName to be serialized.
   * @return Serialized form of QName.
   */
  Char* serialize(const xsd_QName value) throw (SoapException);

  /**
   * Creates a WhiteSpace object to collapse whitespace
   * @return WhiteSpace object set to collapse whitespace
   */
  WhiteSpace* getWhiteSpace();

  /**
   * Creates a minLength object, used to allocate storage.  By default the QName
   * object does not have this specified, so this is an unset minLength object.
   * @return An unset MinLength object
   */
  MinLength* getMinLength();

  /**
   * Creates a maxLength object, used to allocate storage.  By default the QName
   * object does not have this specified, so this is an unset maxLength object.
   * @return An unset MaxLength object
   */
  MaxLength* getMaxLength();

  /**
   * Creates a Length object, used to allocate storage.  By default the QName
   * object does not have this specified, so this is an unset Length object.
   * @return An unset Length object
   */
  Length* getLength();

};


}	/* namespace xqp */
#endif	/* XQP_XSD_H */
