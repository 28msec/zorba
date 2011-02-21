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
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"

#include "runtime/function_item/function_item.h"


namespace zorba
{

namespace store
{


void Item::addReference() const
{
#if defined WIN32 && !defined CYGWIN && !defined ZORBA_FOR_ONE_THREAD_ONLY
  if (isNode())
  {
    InterlockedIncrement(theUnion.treeRCPtr);
    InterlockedIncrement(&theRefCount);
  }
  else
  {
    InterlockedIncrement(&theRefCount);
  }

#else

  if (isNode())
  {
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->acquire());
    ++(*theUnion.treeRCPtr);
    ++theRefCount;
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
  }
  else if (isAtomic() || isError())
  {
    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->acquire());
    ++theRefCount;
    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->release());
  }
  else if (isList())
  {
    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->acquire());
    ++theRefCount;
    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->release());
  }
  else if (isFunction())
  {
    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->acquire());
    ++theRefCount;
    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->release());
  }
  else
  {
    ++theRefCount;
  }

#endif
}


void Item::removeReference()
{
#if defined WIN32 && !defined CYGWIN && !defined ZORBA_FOR_ONE_THREAD_ONLY
  if (isNode())
  {
    InterlockedDecrement(&theRefCount);
    if (!InterlockedDecrement(theUnion.treeRCPtr))
    {
      free();
      return;
    }
  }
  else if (!InterlockedDecrement(&theRefCount))
  {
    free();
    return;
  }

#else

  if (isNode())
  {
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->acquire());

    --theRefCount;
    if (--(*theUnion.treeRCPtr) == 0)
    {
      SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
  }
  else if (isAtomic() || isError())
  {
    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->acquire());

    if (--theRefCount == 0)
    {
      SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->release());
  }
  else if (isList())
  {
    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->acquire());

    if (--theRefCount == 0)
    {
      SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->release());
  }
  else if (isFunction())
  {
    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->acquire());

    if (--theRefCount == 0)
    {
      SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->release());
  }
  else // PUL
  {
    if (--theRefCount == 0)
      free();
  }

#endif
}


bool Item::isNode() const
{
  return ((reinterpret_cast<uint64_t>(theUnion.treeRCPtr) & 0x1) == 0 &&
          theUnion.treeRCPtr != 0);
}


bool Item::isAtomic() const
{
  return ((theUnion.itemKind & ATOMIC) == ATOMIC); 
}


bool Item::isList() const
{
  return ((theUnion.itemKind & LIST) == LIST); 
}


bool Item::isPul() const
{
  return ((theUnion.itemKind & PUL) == PUL);
}


bool Item::isError() const
{
  return ((theUnion.itemKind & ERROR_) == ERROR_);
}


bool Item::isFunction() const
{
  return ((theUnion.itemKind & FUNCTION) == FUNCTION);
}


Item* Item::getBaseItem() const
{
  return NULL;
}


Item* Item::getType() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, typeid (*this).name ());
  return 0;
}


uint32_t Item::hash(long timezone, const XQPCollator* coll) const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Cannot hash items of type " << getType()->getStringValue(),
                        "");
  return 0;
};


bool Item::equals(
    const store::Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
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
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Cannot compare item of type " << getType()->getStringValue()
                        << " with item or type " << other->getType()->getStringValue(),
                        "");
  return 0;
}


Item_t Item::getEBV() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Effective boolean value not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


zstring Item::getStringValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "String value not defined for items of type "
                        << getType()->getStringValue(), "");
}


void Item::getStringValue2(zstring& val) const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "String value not defined for items of type "
                        << getType()->getStringValue(), "");
}


void Item::appendStringValue(zstring& buf) const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "String value not defined for items of type "
                        << getType()->getStringValue(), "");
}



#ifndef ZORBA_NO_FULL_TEXT

FTTokenIterator_t Item::getDocumentTokens( locale::iso639_1::type lang ) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return FTTokenIterator_t( NULL );
}

FTTokenIterator_t Item::getQueryTokens( locale::iso639_1::type, bool ) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return FTTokenIterator_t( NULL );
}

#endif /* ZORBA_NO_FULL_TEXT */

/* ---------------------  Methods for AtomicValues --------------------------- */


/**
 * Accessor for xs:qname
 */
const zstring& Item::getNamespace() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getNamespace() not defined for items of type "
                        << getType()->getStringValue(), "");
}


/**
 * Accessor for xs:qname
 */
const zstring& Item::getPrefix() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getPrefix() not defined for items of type "
                        << getType()->getStringValue(), "");
}


/**
 * Accessor for xs:qname
 */
const zstring& Item::getLocalName() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getLocalName() not defined for items of type "
                        << getType()->getStringValue(), "");
}


/**
 * Accessor for xs:untypedAtomic and xs:string and its subtypes
 */
const zstring& Item::getString() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getString() not defined for items of type "
                        << getType()->getStringValue(), "");
}


/**
 * Accessor for xs:base64Binary
 */
xs_base64Binary Item::getBase64BinaryValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getBase64BinaryValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return xs_base64Binary();
}

/**
 * Accessor for xs:boolean
 */
bool Item::getBooleanValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getBooleanValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return false;
}

/**
 * Accessor for xs:decimal, xs:integer, xs:nonPositiveInteger xs:negativeInteger,
 * xs:nonNegativeInteger xs:positiveInteger, xs:(unsigned)long, xs:(unsigned)int,
 * xs:(unsigned)short, xs:(unsigned)byte
 */
xs_decimal Item::getDecimalValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getDecimalValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return Decimal::parseInt(0);
}


/**
 * Accessor for xs:integer, xs:nonPositiveInteger xs:negativeInteger,
 * xs:nonNegativeInteger xs:positiveInteger, xs:(unsigned)long, xs:(unsigned)int,
 * xs:(unsigned)short, xs:(unsigned)byte
 */
xs_integer Item::getIntegerValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getIntegerValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return Integer::parseInt((int32_t)0);
}


/**
 * Accessor for xs:long, xs:int, xs:short, xs:byte
 */
xs_long Item::getLongValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getLongValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/**
 * Accessor for xs:int, xs:short, xs:byte
 */
xs_int Item::getIntValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getIntValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/**
 * Accessor for xs:short, xs:byte
 */
xs_short Item::getShortValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getShortValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}

/**
 * Accessor for xs:byte
 */
xs_byte Item::getByteValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getByteValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/**
 * Accessor for xs:unsignedLong,  xs:unsignedInt,  xs:unsignedShort,
 *  xs:unsignedByte, xs:nonNegativeInteager, xs:positiveInteger
 */
xs_uinteger Item::getUnsignedIntegerValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getUnsignedIntegerValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return Integer::parseInt(0);
}


/**
 * Accessor for xs:unsignedLong, xs:unsignedInt, xs:unsignedShort, xs:unsignedByte
 */
xs_ulong Item::getUnsignedLongValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getUnsignedLongValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/**
 * Accessor for xs:unsignedInt, xs:unsignedShort, xs:unsignedByte
 */
xs_uint Item::getUnsignedIntValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getUnsignedIntValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/**
 * Accessor for xs:unsignedShort, xs:unsignedByte
 */
xs_ushort Item::getUnsignedShortValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getUnsignedShortValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return 0;
}


/**
 * Accessor for xs:unsignedByte
 */
xs_ubyte Item::getUnsignedByteValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getUnsignedByteValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return 0;
}


/**
 * Accessor for xs:float
 */
xs_float Item::getFloatValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getFloatValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_float);
}


/**
 * Accessor for xs:double
 */
xs_double Item::getDoubleValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getDoubleValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_double);
}


/**
 * Accessor for xs:dateTime, xs:date
 */
const xs_date& Item::getDateValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getDateValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_date);
}

/**
 * Accessor for xs:dateTime
 */
const xs_dateTime& Item::getDateTimeValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getDateTimeValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return *(new xs_dateTime);
}


/**
 * Accessor for xs:time
 */
const xs_time& Item::getTimeValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getTimeValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_time);
}


/**
 * Accessor for xs:gDay
 */
const xs_gDay& Item::getGDayValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getGDayValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_gDay);
}

/**
 * Accessor for xs:gMonth
 */
const xs_gMonth& Item::getGMonthValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getGMonthValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_gMonth);
}

/**
 * Accessor for xs:gMonthDay
 */
const xs_gMonthDay& Item::getGMonthDayValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getGMonthDayValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_gMonthDay);
}

/**
 * Accessor for xs:gYear
 */
const xs_gYear& Item::getGYearValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return *(new xs_gYear);
}

/**
 * Accessor for xs:gYearMonth
 */
const xs_gYearMonth& Item::getGYearMonthValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getGYearMonthValue() not defined for items of type "
                        << getType()->getStringValue(), "");
  return *(new xs_gYearMonth);
}

/**
 * Accessor for xs:duration
 */
const xs_duration& Item::getDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getDurationValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_duration);
}

/**
 * Accessor for xs:dayTimeDuration
 */
const xs_dayTimeDuration& Item::getDayTimeDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getDayTimeDurationValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_dayTimeDuration);
}

/**
 * Accessor for xs:yearMonthDuration
 */
const xs_yearMonthDuration& Item::getYearMonthDurationValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getYearMonthDurationValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return *(new xs_yearMonthDuration);
}


/**
 * Accessor for xs:hexBinary
 */
xs_hexBinary Item::getHexBinaryValue() const
{
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::getHexBinaryValue() not defined for items of type "
                        << getType()->getStringValue(), "");

  return xs_hexBinary();
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
  ZORBA_ERROR_PARAM_OSS(STR0040_TYPE_ERROR,
                        "Item::isPosOrNegInf() not defined for items of type "
                        << getType()->getStringValue(), "");
  return false;
}


/* -----------------------  Methods for Nodes -------------------------------- */


bool Item::isValidated() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


void Item::markValidated()
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


bool Item::isRecursive() const
{
  return true;
}


void Item::getDocumentURI(zstring& uri) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


void Item::getBaseURI(zstring& uri) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


store::Iterator_t Item::getAttributes() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


store::Iterator_t Item::getChildren() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


bool Item::isId() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


bool Item::isIdRefs() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


void Item::getNamespaceBindings(
    NsBindings& bindings,
    StoreConsts::NsScoping ns_scoping) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


store::Item_t Item::getNilled() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return 0;
}


NodeKind Item::getNodeKind() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return StoreConsts::elementNode;
}


store::Item* Item::getNodeName() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}

const store::Collection* Item::getCollection() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


Item* Item::getParent() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return NULL;
}


void Item::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return;
}


bool Item::isInSubstitutionGroup() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
  return false;
}


void Item::getUnparsedEntityPublicId(zstring& val) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


void Item::getUnparsedEntitySystemId(zstring& val) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


const zstring& Item::getTarget() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


zstring Item::show() const
{
  return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
}


void Item::finalizeNode()
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


#if 0
Item* Item::copy(
    store::Item* parent,
    vsize_t pos,
    const CopyMode& copymode) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}
#endif

Item* Item::copy(
    store::Item* parent,
    const CopyMode& copymode) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


#if 0
const std::vector<zorba::store::TupleField>& Item::getTupleFields() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}


int Item::getTupleFieldCount() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

const TupleField& Item::getTupleField(int index) const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}
#endif


error::ZorbaError* Item::getError() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, "ErrorItem");
}

const Item_t Item::getFunctionName() const
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    __FUNCTION__, "FunctionItem");
}

bool Item::isStreamable() const
{
  return false;
}

std::istream& Item::getStream()
{
  ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                        __FUNCTION__, getType()->getStringValue());
}

} // namespace store
} // namespace zorba
/* vim:set et sw=2 ts=2: */
