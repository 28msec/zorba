/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <typeinfo>

#include <zorba/error.h>
#include "zorbaerrors/error_manager.h"
#include "zorbatypes/datetime.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/naive/store_defs.h"


namespace zorba 
{ 

namespace store 
{


Item*
Item::getType( ) const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, typeid (*this).name ());
  return 0;
}


uint32_t Item::hash(long timezone, const XQPCollator* coll) const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Cannot hash items of type " << getType()->getStringValue(),
                        "");
  return 0;
};


bool Item::equals(
    const store::Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Cannot compare item of type " << getType()->getStringValue()
                        << " with item or type " << other->getType()->getStringValue(),
                        "");
  return false;
}


long Item::compare(
    const store::Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Cannot compare item of type " << getType()->getStringValue()
                        << " with item or type " << other->getType()->getStringValue(),
                        "");
  return 0;
}


Item_t Item::getEBV() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Effective boolean value not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


Item_t Item::getAtomizationValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore_t Item::getStringValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "String value not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


void Item::getStringValue(xqpStringStore_t& strval) const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "String value not defined for items of type "
                        << getType()->getStringValue(), "");
}


void Item::getStringValue(std::string& buf) const 
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "String value not defined for items of type "
                        << getType()->getStringValue(), "");
}



/**
 * Helper method with is used to return a StringValue of an store::Item
 * by pointer instead of rchandle
 */
xqpStringStore* Item::getStringValueP() const 
{
  XQUERY_ERROR code = STR0010_TYPE_ERROR;
  ZORBA_ERROR_PARAM_OSS(code,
                        "getStringValueP() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}



/* ---------------------  Methods for AtomicValues --------------------------- */


/** 
 * Accessor for xs:qname
 */
xqpStringStore* Item::getNamespace() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getNamespace() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/** 
 * Accessor for xs:qname
 */
xqpStringStore* Item::getPrefix() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getPrefix() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/** 
 * Accessor for xs:qname
 */
xqpStringStore* Item::getLocalName() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getLocalName() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/**
 * Accessor for xs:untypedAtomic and xs:string and its subtypes
 */
xqpStringStore* Item::getString() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getString() not defined for items of type "
                        << getType()->getStringValue(), "");
  return NULL;
}


/** 
 * Accessor for xs:base64Binary
 */
xqp_base64Binary Item::getBase64BinaryValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getBase64BinaryValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return xqp_base64Binary();
}

/**
 * Accessor for xs:boolean
 */
bool Item::getBooleanValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getBooleanValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return false;
}

/**
 * Accessor for xs:decimal, xs:integer, xs:nonPositiveInteger xs:negativeInteger,
 * xs:nonNegativeInteger xs:positiveInteger, xs:(unsigned)long, xs:(unsigned)int,
 * xs:(unsigned)short, xs:(unsigned)byte
 */
xqp_decimal Item::getDecimalValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getDecimalValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return Decimal::parseInt(0);
}


/**
 * Accessor for xs:integer, xs:nonPositiveInteger xs:negativeInteger,
 * xs:nonNegativeInteger xs:positiveInteger, xs:(unsigned)long, xs:(unsigned)int,
 * xs:(unsigned)short, xs:(unsigned)byte
 */
xqp_integer Item::getIntegerValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getIntegerValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return Integer::parseInt((int32_t)0);
}


/** 
 * Accessor for xs:long, xs:int, xs:short, xs:byte
 */
xqp_long Item::getLongValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getLongValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/**
 * Accessor for xs:int, xs:short, xs:byte
 */
xqp_int Item::getIntValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getIntValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/**
 * Accessor for xs:short, xs:byte
 */
xqp_short Item::getShortValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getShortValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}

/**
 * Accessor for xs:byte
 */
xqp_byte Item::getByteValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getByteValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/** 
 * Accessor for xs:unsignedLong,  xs:unsignedInt,  xs:unsignedShort, 
 *  xs:unsignedByte, xs:nonNegativeInteager, xs:positiveInteger
 */
xqp_uinteger Item::getUnsignedIntegerValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getUnsignedIntegerValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return Integer::parseInt(0);
}


/** 
 * Accessor for xs:unsignedLong, xs:unsignedInt, xs:unsignedShort, xs:unsignedByte 
 */
xqp_ulong Item::getUnsignedLongValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getUnsignedLongValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/** 
 * Accessor for xs:unsignedInt, xs:unsignedShort, xs:unsignedByte 
 */
xqp_uint Item::getUnsignedIntValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getUnsignedIntValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/** 
 * Accessor for xs:unsignedShort, xs:unsignedByte
 */
xqp_ushort Item::getUnsignedShortValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getUnsignedShortValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/** 
 * Accessor for xs:unsignedByte
 */
xqp_ubyte Item::getUnsignedByteValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getUnsignedByteValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/** 
 * Accessor for xs:float
 */
const xqp_float& Item::getFloatValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getFloatValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_float);
}


/** 
 * Accessor for xs:double
 */
const xqp_double& Item::getDoubleValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getDoubleValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_double);
}


/** 
 * Accessor for xs:dateTime, xs:date
 */
const xqp_date& Item::getDateValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getDateValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_date);
}

/** 
 * Accessor for xs:dateTime
 */
const xqp_dateTime& Item::getDateTimeValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getDateTimeValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return *(new xqp_dateTime);
}


/** 
 * Accessor for xs:time
 */
const xqp_time& Item::getTimeValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getTimeValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_time);
}


/** 
 * Accessor for xs:gDay
 */
const xqp_gDay& Item::getGDayValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getGDayValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_gDay);
}

/** 
 * Accessor for xs:gMonth
 */
const xqp_gMonth& Item::getGMonthValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getGMonthValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_gMonth);
}

/** 
 * Accessor for xs:gMonthDay
 */
const xqp_gMonthDay& Item::getGMonthDayValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getGMonthDayValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_gMonthDay);
}

/** 
 * Accessor for xs:gYear
 */
const xqp_gYear& Item::getGYearValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_gYear);
}

/** 
 * Accessor for xs:gYearMonth
 */
const xqp_gYearMonth& Item::getGYearMonthValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getGYearMonthValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return *(new xqp_gYearMonth);
}

/** 
 * Accessor for xs:duration
 */
const xqp_duration& Item::getDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getDurationValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_duration);
}

/** 
 * Accessor for xs:dayTimeDuration
 */
const xqp_dayTimeDuration& Item::getDayTimeDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getDayTimeDurationValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_dayTimeDuration);
}

/**
 * Accessor for xs:yearMonthDuration
 */
const xqp_yearMonthDuration& Item::getYearMonthDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getYearMonthDurationValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xqp_yearMonthDuration);
}

/** 
 * Accessor for xs:ENTITIES, xs:IDREFS, xs:NMTOKENS
 */
std::vector<xqp_string> Item::getStringVectorValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getStringVectorValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return std::vector<xqp_string>();
}


/** 
 * Accessor for xs:hexBinary
 */
xqp_hexBinary Item::getHexBinaryValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::getHexBinaryValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return xqp_hexBinary();
}


/**
 * Helper method for numeric atomic items
 * @return true, if containing number is not-a-number (possible for floating-point numbers)
 */
bool Item::isNaN() const
{
  return false;
}

/**
 * Helper method for numeric atomic items
 * @return true, if containing numbers represents -INF or +INF
 */
bool Item::isPosOrNegInf() const
{
  ZORBA_ERROR_PARAM_OSS(STR0010_TYPE_ERROR,
                        "Item::isPosOrNegInf() not defined for items of type "
                        << getType()->getStringValue(), "");
  return false;
}


/* -----------------------  Methods for Nodes -------------------------------- */


bool Item::isValidated() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


void Item::markValidated()
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


xqpStringStore* Item::getDocumentURI() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore_t Item::getBaseURI() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


store::Iterator_t Item::getAttributes() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


store::Iterator_t Item::getChildren() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


bool Item::isId() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


bool Item::isIdRefs() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


void Item::getNamespaceBindings(
    NsBindings& bindings,
    StoreConsts::NsScoping ns_scoping) const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


store::Item_t Item::getNilled() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


NodeKind Item::getNodeKind() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return StoreConsts::elementNode;
}


store::Item* Item::getNodeName() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


Item* Item::getParent() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


void Item::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return;
}


xqpStringStore* Item::getUnparsedEntityPublicId() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore* Item::getUnparsedEntitySystemId() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore* Item::getTarget() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqp_string Item::show() const
{
  return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
}


void Item::finalizeNode()
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


Item* Item::copy(
    store::Item* parent,
    ulong pos,
    const CopyMode& copymode) const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


void Item::applyUpdates(std::set<zorba::store::Item*>& validationNodes)
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

const std::vector<zorba::store::TupleField>& Item::getTupleFields() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

int Item::getTupleFieldCount() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

const TupleField& Item::getTupleField(int index) const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


error::ZorbaError* Item::getError() const
{
  ZORBA_ERROR_PARAM_OSS(STR0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, "ErrorItem");
}


} // namespace store
} // namespace zorba
