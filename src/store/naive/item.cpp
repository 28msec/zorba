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
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, typeid (*this).name ());
  return 0;
}


uint32_t Item::hash(long timezone, const XQPCollator* coll) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
};


bool Item::equals(const store::Item*, long timezone, const XQPCollator* aCollation) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


long Item::compare(const store::Item*, long timezone, const XQPCollator* aCollation) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


Item_t Item::getEBV() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


Item_t Item::getAtomizationValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore_t Item::getStringValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


void Item::getStringValue(xqpStringStore_t& strval) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


void Item::getStringValue(std::string& buf) const 
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}



/**
 * Helper method with is used to return a StringValue of an store::Item
 * by pointer instead of rchandle
 */
xqpStringStore* Item::getStringValueP() const 
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}



/* -------------------  Methods for AtomicValues ------------------------------ */
/**
 *  getXValue functions:
 *  @return  value of type X
 *
 *  Assuming that the item is an AtomicValue of a particular kind X, return the value
 *  of the item. Implementations of X, e.g., a specific DoubleValue implementation, will override
 *  its specific getXValue method (i.e., getDoubleValue) and not change any of the other methods.
 *  Implementations of the seven kinds of nodes should not override the definition of these
 *  methods.
 */
  
/** Accessor for xs:base64Binary
 */
xqp_base64Binary Item::getBase64BinaryValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return xqp_base64Binary();
}

/** Accessor for xs:boolean
 */
bool Item::getBooleanValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}

/** Accessor for xs:decimal, xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
 * xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
 */
xqp_decimal Item::getDecimalValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return Decimal::parseInt(0);
}

/** Accessor for xs:int
 */
xqp_int Item::getIntValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}

/** Accessor for xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
 * xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
 */
xqp_integer Item::getIntegerValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return Integer::parseInt((int32_t)0);
}

/** Accessor for xs:long
 */
xqp_long Item::getLongValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}

/** Accessor for xs:short
 */
xqp_short Item::getShortValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}

/** Accessor for xs:nonNegativeInteager, xs:positiveInteger
 */
xqp_uinteger Item::getUnsignedIntegerValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return Integer::parseInt(0);
}

/** Accessor for xs:unsignedChar, xs:unsignedByte
 */
xqp_ubyte Item::getUnsignedByteValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}

xqp_byte Item::getByteValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}

/** Accessor for xs:date
 */
const xqp_date& Item::getDateValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_date);
}

/** Accessor for xs:dateTime
 */
const xqp_dateTime& Item::getDateTimeValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_dateTime);
}

/** Accessor for xs:double
 */
const xqp_double& Item::getDoubleValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_double);
}

/** Accessor for xs:duration
 */
const xqp_duration& Item::getDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_duration);
}

/* Accessor for xs:dayTimeDuration
  */
const xqp_dayTimeDuration& Item::getDayTimeDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_dayTimeDuration);
}

/*Accessor for xs:yearMonthDuration
  */
const xqp_yearMonthDuration& Item::getYearMonthDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_yearMonthDuration);
}

/** Accessor for xs:ENTITIES, xs:IDREFS, xs:NMTOKENS
 */
std::vector<xqp_string> Item::getStringVectorValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return std::vector<xqp_string>();
}

/** Accessor for xs:float
 */
xqp_float Item::getFloatValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return xqp_float::parseInt(0);
}

/** Accessor for xs:gDay
 */
const xqp_gDay& Item::getGDayValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_gDay);
}

/** Accessor for xs:gMonth
 */
const xqp_gMonth& Item::getGMonthValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_gMonth);
}

/** Accessor for xs:gMonthDay
 */
const xqp_gMonthDay& Item::getGMonthDayValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_gMonthDay);
}

/** Accessor for xs:gYear
 */
const xqp_gYear& Item::getGYearValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_gYear);
}

/** Accessor for xs:gYearMonth
 */
const xqp_gYearMonth& Item::getGYearMonthValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_gYearMonth);
}

/** Accessor for xs:hexBinary
 */
xqp_hexBinary Item::getHexBinaryValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return xqp_hexBinary();
}

/** Accessor for xs:nonNegativeIntegerValue, xs:positiveInteger, xs:unsignedInt
 */
xqp_uint Item::getUnsignedIntValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}

/** Accessor for xs:time
 */
const xqp_time& Item::getTimeValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xqp_time);
}

/** Accessor for xs:unsignedLong
 */
xqp_ulong Item::getUnsignedLongValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}

/** Accessor for xs:unsignedShort
 */
xqp_ushort Item::getUnsignedShortValue() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
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
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}

/* -------------------  Methods for Nodes ------------------------------------- */

/**
 *  getNodeProperty functions - Accessor of XDM (see XDM specification, Section 5)
 *  @return  value of node property
 *
 *  Assuming that the item is a node, return the properties of that particular node.
 *  Since all these properties are defined on all seven kinds of nodes (documents, elements,
 *  attributes, etc.), the implementations of all seven kinds of nodes must override these
 *  methods. Implementations of atomic values should keep the default (error) implementation
 *  of these methods.
 */


xqpStringStore* Item::getDocumentURI() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore_t Item::getBaseURI() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


store::Iterator_t Item::getAttributes() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


store::Iterator_t Item::getChildren() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


bool Item::isId() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


bool Item::isIdRefs() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


void Item::getNamespaceBindings(
    NsBindings& bindings,
    StoreConsts::NsScoping ns_scoping) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


store::Item_t Item::getNilled() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


NodeKind Item::getNodeKind() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return StoreConsts::elementNode;
}


store::Item* Item::getNodeName() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


Item* Item::getParent() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


void Item::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return;
}


xqpStringStore* Item::getNamespace() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore* Item::getPrefix() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore* Item::getLocalName() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore* Item::getUnparsedEntityPublicId() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore* Item::getUnparsedEntitySystemId() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqpStringStore* Item::getTarget() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


xqp_string Item::show() const
{
  return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
}


void Item::finalizeNode()
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


Item* Item::copy(
    store::Item* parent,
    long pos,
    const CopyMode& copymode) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


void Item::applyUpdates(std::set<zorba::store::Item*>& validationNodes)
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

const std::vector<zorba::store::TupleField>& Item::getTupleFields() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

int Item::getTupleFieldCount() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

const TupleField& Item::getTupleField(int index) const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


error::ZorbaError* Item::getError() const
{
  ZORBA_ERROR_PARAM_OSS(XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, "ErrorItem");
}


} // namespace store
} // namespace zorba
