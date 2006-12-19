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
 *
 *	@author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 *	Revision rolls up the set of xsd classes for use with
 *	the zorba XQueryP package.
 *
 *	@author Paul Pedersen (pcp071098@yahoo.com)
 *
 */

#ifndef XQP_XSD_H
#define XQP_XSD_H

#include <ctime>
#include <string>

#include "xsd_mapping.h"
#include "xsd_constraints.h"
#include "../util/xqpexception.h"



#include <axis/AxisUserAPI.hpp>
#include "../apr_base64.h"
#include "../HexCoder.h"
#include "../../platforms/PlatformAutoSense.hpp"



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


/**
 *   @class IAnySimpleType
 *   @brief Interface for all XSD built-in simple type.
 *
 *   @author Adrian Dick (adrian.dick@uk.ibm.com)
 *
 */
class IAnySimpleType
{
public:
	/**
	 * Constructor
	 */
	IAnySimpleType();
	
	/**
	 * Destructor
	 */
	virtual ~IAnySimpleType();

	/**
	 * This method provides ability to determine if value is nill.
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
	AxisChar* serialize();

	/**
	 * Takes the value in it's on-the-wire string form
	 * @param Serialized form of value
	 */
	void deserialize(const AxisChar* value);

protected:
	/**
	 * Take partially serialized value, process WhiteSpace and validate Pattern.
	 * @param value partially serialized value
	 * @return Serialized form of value
	 */
	AxisChar* serialize(const AxisChar* value) throw (AxisSoapException);

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
	const AxisString& replaceReservedCharacters(AxisString& value);

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
	AxisChar* m_Buf;
   
private:
	bool m_isNil;
	AxisString m_strReturnVal;

};




class AnyURI : public IAnySimpleType 
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
	AnyURI(const xsd__anyURI value);

	/**
	 * Get the xsd type of this simple type.
	 * @return the xsd type of this simple type
	 */
	XSDTYPE getType();

	/**
	 * Get the deserialized value.
	 * @return Deserialized value. Note: it is the responsibility of the calling code to delete this value!
	 */
	xsd__anyURI getAnyURI();

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
	xsd__anyURI deserializeAnyURI(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize AnyURI value to it's on-the-wire string form.
	 * @param value The AnyURI value to be serialized.
	 * @return Serialized form of AnyURI value.
	 */
	AxisChar* serialize(const xsd__anyURI value) throw (AxisSoapException);

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
	Base64Binary(const xsd__base64Binary* value);

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
	xsd__base64Binary* getBase64Binary();

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
	xsd__base64Binary * deserializeBase64Binary(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Base64Binary value to it's on-the-wire string form.
	 * @param value The Base64Binary value to be serialized.
	 * @return Serialized form of Base64Binary value.
	 */
	AxisChar* serialize(const xsd__base64Binary * value) throw (AxisSoapException);

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
	Boolean(const xsd__boolean* value);
	
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
	xsd__boolean* getBoolean();

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
	xsd__boolean * deserializeBoolean(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize boolean value to it's on-the-wire string form.
	 * @param value The boolean value to be serialized.
	 * @return Serialized form of boolean value.
	 */
	AxisChar* serialize(const xsd__boolean * value) throw (AxisSoapException);

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
	Byte(const xsd__byte* value);

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
	xsd__byte* getByte();

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
	xsd__byte* deserializeByte(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Byte value to it's on-the-wire string form.
	 * @param value The Byte value to be serialized.
	 * @return Serialized form of Byte value.
	 */  
	AxisChar* serialize(const xsd__byte* value) throw (AxisSoapException);

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
	Date(const xsd__date* value);

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
	xsd__date* getDate();

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
	xsd__date* deserializeDate(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Date value to it's on-the-wire string form.
	 * @param value The Date value to be serialized.
	 * @return Serialized form of Date value.
	 */
	AxisChar* serialize(const xsd__date* value) throw (AxisSoapException);

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
	DateTime(const xsd__dateTime* value);
	
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
	xsd__dateTime* getDateTime();

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
	xsd__dateTime* deserializeDateTime(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize DateTime value to it's on-the-wire string form.
	 * @param value The DateTime value to be serialized.
	 * @return Serialized form of DateTime value.
	 */
	AxisChar* serialize(const xsd__dateTime* value) throw (AxisSoapException);

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
	Decimal(const xsd__decimal* value);
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
	xsd__decimal* getDecimal();
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
	xsd__decimal* deserializeDecimal(const AxisChar* valueAsChar) throw (AxisSoapException);
	/**
	 * Serialize Decimal value to it's on-the-wire string form.
	 * @param value The Decimal value to be serialized.
	 * @return Serialized form of Decimal value.
	 */
	AxisChar* serialize(const xsd__decimal* value) throw (AxisSoapException);
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
	Double(const xsd__double* value);
 
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
	xsd__double* getDouble();

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
	xsd__double* deserializeDouble(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Double value to it's on-the-wire string form.
	 * @param value The Double value to be serialized.
	 * @return Serialized form of Double value.
	 */
	AxisChar* serialize(const xsd__double* value) throw (AxisSoapException);

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
	Duration(const xsd__duration* value);

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
	xsd__duration* getDuration();

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
	xsd__duration* deserializeDuration(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Duration value to it's on-the-wire string form.
	 * @param value The Duration value to be serialized.
	 * @return Serialized form of Duration value.
	 */
	AxisChar* serialize(const xsd__duration* value) throw (AxisSoapException);

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
	ENTITIES(const xsd__ENTITIES value);

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
	xsd__ENTITIES getENTITIES();

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
	xsd__ENTITIES deserializeENTITIES(const AxisChar* valueAsChar) throw (AxisSoapException);

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
	ENTITY(const xsd__ENTITY value);
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
	xsd__ENTITY getENTITY();
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
	xsd__ENTITY deserializeENTITY(const AxisChar* valueAsChar) throw (AxisSoapException);

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
	Float(const xsd__float* value);

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
	xsd__float* getFloat();

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
	xsd__float* deserializeFloat(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Float value to it's on-the-wire string form.
	 * @param value The Float value to be serialized.
	 * @return Serialized form of Float value.
	 */
	AxisChar* serialize(const xsd__float* value) throw (AxisSoapException);

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
	GDay(const xsd__gDay* value);

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
	xsd__gDay* getGDay();

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
	xsd__gDay* deserializeGDay(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize GDay value to it's on-the-wire string form.
	 * @param value The GDay value to be serialized.
	 * @return Serialized form of GDay value.
	 */
	AxisChar* serialize(const xsd__gDay* value) throw (AxisSoapException);

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
	GMonth(const xsd__gMonth* value);

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
	xsd__gMonth* getGMonth();

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
	xsd__gMonth* deserializeGMonth(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize GMonth value to it's on-the-wire string form.
	 * @param value The GMonth value to be serialized.
	 * @return Serialized form of GMonth value.
	 */
	AxisChar* serialize(const xsd__gMonth* value) throw (AxisSoapException);

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
	GMonthDay(const xsd__gMonthDay* value);

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
	xsd__gMonthDay* getGMonthDay();

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
	xsd__gMonthDay* deserializeGMonthDay(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize GMonthDay value to it's on-the-wire string form.
	 * @param value The GMonthDay value to be serialized.
	 * @return Serialized form of GMonthDay value.
	 */
	AxisChar* serialize(const xsd__gMonthDay* value) throw (AxisSoapException);

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
	GYear(const xsd__gYear* value);
	
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
	xsd__gYear* getGYear();

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
	xsd__gYear* deserializeGYear(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize GYear value to it's on-the-wire string form.
	 * @param value The GYear value to be serialized.
	 * @return Serialized form of GYear value.
	 */
	AxisChar* serialize(const xsd__gYear* value) throw (AxisSoapException);

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
	GYearMonth(const xsd__gYearMonth* value);

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
	xsd__gYearMonth* getGYearMonth();

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
	xsd__gYearMonth* deserializeGYearMonth(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize GYearMonth value to it's on-the-wire string form.
	 * @param value The GYearMonth value to be serialized.
	 * @return Serialized form of GYearMonth value.
	 */
	AxisChar* serialize(const xsd__gYearMonth* value) throw (AxisSoapException);

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
	HexBinary(const xsd__hexBinary* value);

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
	xsd__hexBinary* getHexBinary();

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
	xsd__hexBinary * deserializeHexBinary(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize HexBinary value to it's on-the-wire string form.
	 * @param value The HexBinary value to be serialized.
	 * @return Serialized form of HexBinary value.
	 */
	AxisChar* serialize(const xsd__hexBinary * value) throw (AxisSoapException);

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
const AxisChar XML_ENTITY_REFERENCE_CHARS[]    = "<>&\"\'";

/* Encoded string for less than character */
const AxisChar ENCODED_LESSER_STR[]            = "&lt;";    

/* Encoded string for greator than character */
const AxisChar ENCODED_GREATER_STR[]        = "&gt;";    

/* Encoded string for ampersand character */
const AxisChar ENCODED_AMPERSAND_STR[]        = "&amp;";    

/* Encoded string for single quote character */
const AxisChar ENCODED_DBL_QUOTE_STR[]        = "&quot;";    

/* Encoded string for double quote character */
const AxisChar ENCODED_SGL_QUOTE_STR[]        = "&apos;";    




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
	ID(const xsd__ID value);

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
	xsd__ID getID();

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
	xsd__ID deserializeID(const AxisChar* valueAsChar) throw (AxisSoapException);

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
	IDREF(const xsd__IDREF value);

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
	xsd__IDREF getIDREF();

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
	xsd__IDREF deserializeIDREF(const AxisChar* valueAsChar) throw (AxisSoapException);

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
	IDREFS(const xsd__IDREFS value);

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
	xsd__IDREFS getIDREFS();
	
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
	xsd__IDREFS deserializeIDREFS(const AxisChar* valueAsChar) throw (AxisSoapException);

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
	Int(const xsd__int* value);

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
	xsd__int* getInt();

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
	xsd__int* deserializeInt(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Int value to it's on-the-wire string form.
	 * @param value The Int value to be serialized.
	 * @return Serialized form of Int value.
	 */  
	AxisChar* serialize(const xsd__int* value) throw (AxisSoapException);

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
	Integer(const xsd__integer* value);

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
	xsd__integer* getInteger();

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
	xsd__integer* deserializeInteger(const AxisChar* valueAsChar) throw (AxisSoapException);

	/**
	 * Serialize Integer value to it's on-the-wire string form.
	 * @param value The Integer value to be serialized.
	 * @return Serialized form of Integer value.
	 */
	AxisChar* serialize(const xsd__integer* value) throw (AxisSoapException);

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
	Language(const xsd__language value);

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
	xsd__language getLanguage();

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
	xsd__language deserializeLanguage(const AxisChar* valueAsChar) throw (AxisSoapException);

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
  Long(const xsd__long* value);

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
  xsd__long* getLong();

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
  xsd__long* deserializeLong(const AxisChar* valueAsChar) throw (AxisSoapException);

  /**
   * Serialize Long value to it's on-the-wire string form.
   * @param value The Long value to be serialized.
   * @return Serialized form of Long value.
   */  
  AxisChar* serialize(const xsd__long* value) throw (AxisSoapException);

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
  NCName(const xsd__NCName value);

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
  xsd__NCName getNCName();

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
  xsd__NCName deserializeNCName(const AxisChar* valueAsChar) throw (AxisSoapException);

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
  NMTOKEN(const xsd__NMTOKEN value);

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
  xsd__NMTOKEN getNMTOKEN();

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
  xsd__NMTOKEN deserializeNMTOKEN(const AxisChar* valueAsChar) throw (AxisSoapException);

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
  NMTOKENS(const xsd__NMTOKENS value);

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
  xsd__NMTOKENS getNMTOKENS();

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
  xsd__NMTOKENS deserializeNMTOKENS(const AxisChar* valueAsChar) throw (AxisSoapException);

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
  NOTATION(const xsd__NOTATION value);

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
  xsd__NOTATION getNOTATION();

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
	xsd__NOTATION deserializeNOTATION(const AxisChar* valueAsChar) throw (AxisSoapException);

  /**
   * Serialize NOTATION value to it's on-the-wire string form.
   * @param value The NOTATION value to be serialized.
   * @return Serialized form of NOTATION value.
   */ 
  AxisChar* serialize(const xsd__NOTATION value) throw (AxisSoapException);

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
  Name(const xsd__Name value);

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
  xsd__Name getName();

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
  xsd__Name deserializeName(const AxisChar* valueAsChar) throw (AxisSoapException);

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
  NegativeInteger(const xsd__negativeInteger* value) throw (AxisSoapException);

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
  xsd__negativeInteger* getNegativeInteger();

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
  xsd__negativeInteger* deserializeNegativeInteger(const AxisChar* valueAsChar) throw (AxisSoapException);

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
  NonNegativeInteger(const xsd__nonNegativeInteger* value)
	throw (AxisSoapException);

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
  xsd__nonNegativeInteger* getNonNegativeInteger();

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
   xsd__nonNegativeInteger* deserializeNonNegativeInteger(const AxisChar* valueAsChar)
	 throw (AxisSoapException);

  /**
   * Serialize NonNegativeInteger value to it's on-the-wire string form.
   * @param value The NonNegativeInteger value to be serialized.
   * @return Serialized form of NonNegativeInteger value.
   */
  AxisChar* serialize(const xsd__nonNegativeInteger* value)
	throw (AxisSoapException);

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
  NonPositiveInteger(const xsd__nonPositiveInteger* value)
	throw (AxisSoapException);
  
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
  xsd__nonPositiveInteger* getNonPositiveInteger();

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
  xsd__nonPositiveInteger* deserializeNonPositiveInteger(const AxisChar* valueAsChar)
	throw (AxisSoapException);

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
  NormalizedString(const xsd__normalizedString value);

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
  xsd__normalizedString getNormalizedString();

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
  xsd__normalizedString deserializeNormalizedString(const AxisChar* valueAsChar)
	throw (AxisSoapException);

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
  PositiveInteger(const xsd__positiveInteger* value)
	throw (AxisSoapException);

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
  xsd__positiveInteger* getPositiveInteger();

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
  xsd__positiveInteger* deserializePositiveInteger(const AxisChar* valueAsChar)
	throw (AxisSoapException);

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
  Short(const xsd__short* value);

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
  xsd__short* getShort();

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
  xsd__short* deserializeShort(const AxisChar* valueAsChar)
	throw (AxisSoapException);

  /**
   * Serialize Short value to it's on-the-wire string form.
   * @param value The Short value to be serialized.
   * @return Serialized form of Short value.
   */  
  AxisChar* serialize(const xsd__short* value) throw (AxisSoapException);

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
  String(const xsd__string value);

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
  xsd__string getString();

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
	xsd__string deserializeString(const AxisChar* valueAsChar)
	throw (AxisSoapException);

  /**
   * Serialize String value to it's on-the-wire string form.
   * @param value The String value to be serialized.
   * @return Serialized form of String value.
   */   
	AxisChar* serialize(const xsd__string value)
	throw (AxisSoapException);

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
  Time(const xsd__time* value);

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
  xsd__time* getTime();

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
  xsd__time* deserializeTime(const AxisChar* valueAsChar)
	throw (AxisSoapException);

  /**
   * Serialize Time value to it's on-the-wire string form.
   * @param value The Time value to be serialized.
   * @return Serialized form of Time value.
   */
  AxisChar* serialize(const xsd__time* value)
	throw (AxisSoapException);

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
  Token(const xsd__token value);

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
  xsd__token getToken();

protected:
  /**
   * Deserialized Token value from it's on-the-wire string form.
   * @param valueAsChar Serialized form of Token value.
   * @return Deserialized Token value.
	 *		Note: it is the responsibility of the calling code to delete this value!
   */
  xsd__token deserializeToken(const AxisChar* valueAsChar)
	throw (AxisSoapException);

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
  UnsignedByte(const xsd__unsignedByte* value);
  
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
  xsd__unsignedByte* getUnsignedByte();

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
  xsd__unsignedByte* deserializeUnsignedByte(const AxisChar* valueAsChar)
	throw (AxisSoapException);

  /**
   * Serialize UnsignedByte value to it's on-the-wire string form.
   * @param value The UnsignedByte value to be serialized.
   * @return Serialized form of UnsignedByte value.
   */  
  AxisChar* serialize(const xsd__unsignedByte* value)
	throw (AxisSoapException);

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
  UnsignedInt(const xsd__unsignedInt* value);
  
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
  xsd__unsignedInt* getUnsignedInt();

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
  xsd__unsignedInt* deserializeUnsignedInt(const AxisChar* valueAsChar)
	throw (AxisSoapException);

  /**
   * Serialize UnsignedInt value to it's on-the-wire string form.
   * @param value The UnsignedInt value to be serialized.
   * @return Serialized form of UnsignedInt value.
   */  
  AxisChar* serialize(const xsd__unsignedInt* value)
	throw (AxisSoapException);

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
  UnsignedLong(const xsd__unsignedLong* value);

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
  xsd__unsignedLong* getUnsignedLong();

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
  xsd__unsignedLong* deserializeUnsignedLong(const AxisChar* valueAsChar)
	throw (AxisSoapException);

  /**
   * Serialize UnsignedLong value to it's on-the-wire string form.
   * @param value The UnsignedLong value to be serialized.
   * @return Serialized form of UnsignedLong value.
   */  
  AxisChar* serialize(const xsd__unsignedLong* value)
	throw (AxisSoapException);

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
  UnsignedShort(const xsd__unsignedShort* value);
  
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
  xsd__unsignedShort* getUnsignedShort();

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
  xsd__unsignedShort* deserializeUnsignedShort(const AxisChar* valueAsChar)
	throw (AxisSoapException);

  /**
   * Serialize UnsignedShort value to it's on-the-wire string form.
   * @param value The UnsignedShort value to be serialized.
   * @return Serialized form of UnsignedShort value.
   */  
  AxisChar* serialize(const xsd__unsignedShort* value)
	throw (AxisSoapException);

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
  XSD_QName(const xsd__QName value);

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
  xsd__QName getQName();

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
  xsd__QName deserializeQName(const AxisChar* valueAsChar) throw (AxisSoapException);

  /**
   * Serialize QName to it's on-the-wire string form.
   * @param value The QName to be serialized.
   * @return Serialized form of QName.
   */
  AxisChar* serialize(const xsd__QName value) throw (AxisSoapException);

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
