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
#include "stdafx.h"

#include <typeinfo>

#include <zorba/error.h>
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

#include "zorbatypes/datetime.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store_defs.h"
#include "atomic_items.h"
#include "node_items.h"
#include "json_items.h"

#include "runtime/hof/function_item.h"


namespace zorba
{

namespace store
{


Item::~Item() {
  // out-of-line since it's virtual
}

void Item::free()
{
  delete this;
}


void Item::addReference() const
{
  switch (getKind())
  {
  case NODE:
  {
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->acquire());
    ++(*theUnion.treeRCPtr);
    ++theRefCount;
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
    return;
  }
  case OBJECT:
  case ARRAY:
  {
    SYNC_CODE(static_cast<const simplestore::json::JSONItem*>(this)->getRCLock()->acquire());
    ++theRefCount;
    SYNC_CODE(static_cast<const simplestore::json::JSONItem*>(this)->getRCLock()->release());
    return;
  }
  case ATOMIC:
  case ERROR_:
  {
    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->acquire());
    ++theRefCount;
    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->release());
    return;
  }
  case LIST:
  {
    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->acquire());
    ++theRefCount;
    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->release());
    return;
  }
  case FUNCTION:
  {
    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->acquire());
    ++theRefCount;
    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->release());
    return;
  }
  case PUL:
  {
    ++theRefCount;
    return;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }  
  }
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

  switch (getKind())
  {
  case NODE:
  {
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->acquire());

    assert(theRefCount > 0);

    --theRefCount;
    if (--(*theUnion.treeRCPtr) == 0)
    {
      SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
    return;
  }
  case OBJECT:
  case ARRAY:
  {
    SYNC_CODE(static_cast<const simplestore::json::JSONItem*>(this)->getRCLock()->acquire());
    assert(theRefCount > 0);

    if (--theRefCount == 0)
    {
      SYNC_CODE(static_cast<const simplestore::json::JSONItem*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const simplestore::json::JSONItem*>(this)->getRCLock()->release());
    return;
  }
  case ATOMIC:
  case ERROR_:
  {
    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->acquire());

    assert(theRefCount > 0);

    if (--theRefCount == 0)
    {
      SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->release());
    return;
  }
  case LIST:
  {
    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->acquire());

    if (--theRefCount == 0)
    {
      SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->release());
    return;
  }
  case FUNCTION:
  {
    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->acquire());

    if (--theRefCount == 0)
    {
      SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->release());
      free();
      return;
    }

    SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->release());
    return;
  }
  case  PUL:
  {
    if (--theRefCount == 0)
      free();

    return;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }
#endif
}


long Item::getRefCount() const
{
  long refCount = 0;

  if (getKind() != ATOMIC)
    std::cout << "Kind: " << getKind() << std::endl;
  switch (getKind())
  {
    case NODE:
    {
      SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->acquire());
      refCount = theRefCount;
      SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
      break;
    }
    case OBJECT:
    case ARRAY:
    {
      SYNC_CODE(static_cast<const simplestore::json::JSONItem*>(this)->getRCLock()->acquire());
      refCount = theRefCount;
      SYNC_CODE(static_cast<const simplestore::json::JSONItem*>(this)->getRCLock()->release());
      break;
    }
    case ATOMIC:
    case ERROR_:
    {
      SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->acquire());
      refCount = theRefCount;
      SYNC_CODE(static_cast<const simplestore::AtomicItem*>(this)->getRCLock()->release());
      break;
    }
    case LIST:
    {
      SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->acquire());
      refCount = theRefCount;
      SYNC_CODE(static_cast<const simplestore::ItemVector*>(this)->getRCLock()->release());
      break;
    }
    case FUNCTION:
    {
      SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->acquire());
      refCount = theRefCount;
      SYNC_CODE(static_cast<const FunctionItem*>(this)->getRCLock()->release());
      break;
    }
    case PUL:
    {
      refCount = theRefCount;
      break;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
  }

  return refCount;
}


size_t Item::alloc_size() const
{
  return 0;
}


size_t Item::dynamic_size() const
{
  return sizeof( *this );
}


zstring Item::printKind() const
{
  switch (getKind())
  {
  case ATOMIC:
    return "atomic";

  case NODE:
    return "node";

  case OBJECT:
    return "object";

  case ARRAY:
    return "array";

  case FUNCTION:
    return "function";

  case PUL:
    return "pul";

  case ERROR_:
    return "error";

  default:
    return "unknown";
  }
}


Item* Item::getBaseItem() const
{
  return NULL;
}


Item* Item::getType() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, typeid(*this).name() )
  );
}

bool Item::haveSimpleContent() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, typeid(*this).name() )
  );
}


uint32_t Item::hash(long timezone, const XQPCollator* coll) const
{
  throw ZORBA_EXCEPTION(zerr::ZSTR0040_TYPE_ERROR,
  ERROR_PARAMS(ZED(NoHashItemOfType_2), getType()->getStringValue()));
};


bool Item::equals(const store::Item* other, long tz, const XQPCollator* c) const
{
  throw ZORBA_EXCEPTION(zerr::ZSTR0040_TYPE_ERROR,
  ERROR_PARAMS(ZED(NoCompareTypes_23),
               getType()->getStringValue(),
               other->getType()->getStringValue()));
}


long Item::compare(
    const store::Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  throw ZORBA_EXCEPTION(zerr::ZSTR0040_TYPE_ERROR,
  ERROR_PARAMS(ZED(NoCompareTypes_23),
               getType()->getStringValue(),
               other->getType()->getStringValue()));
}


bool Item::getEBV() const
{
  throw ZORBA_EXCEPTION(zerr::ZSTR0040_TYPE_ERROR,
  ERROR_PARAMS(ZED(OperationNotDef_23),
               ZED(EffectiveBooleanValue),
               getType()->getStringValue()));
}


zstring Item::getStringValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "string-value",
      getType()->getStringValue()
    )
  );
}


void Item::getStringValue2(zstring& val) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "string-value",
      getType()->getStringValue()
    )
  );
}


void Item::appendStringValue(zstring& buf) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), ZED( AppendStringValue ),
      getType()->getStringValue()
    )
  );
}


#ifndef ZORBA_NO_FULL_TEXT
FTTokenIterator_t
Item::getTokens( TokenizerProvider const&, Tokenizer::State&,
                 locale::iso639_1::type, bool ) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, typeid(*this).name() )
  );
}
#endif /* ZORBA_NO_FULL_TEXT */

/* ---------------------  Methods for AtomicValues --------------------------- */


/**
 * Accessor for xs:qname
 */
const zstring& Item::getNamespace() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getNamespace()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:qname
 */
const zstring& Item::getPrefix() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getPrefix()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:qname
 */
const zstring& Item::getLocalName() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getLocalName()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:untypedAtomic and xs:string and its subtypes
 */
const zstring& Item::getString() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getString()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:base64Binary
 */
const char* Item::getBase64BinaryValue(size_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getBase64BinaryValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Checks whether a base64 item's content is already encoded
 *
 * @return true only if it is.
 */
bool Item::isEncoded() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::isEncoded()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:boolean
 */
bool Item::getBooleanValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getBooleanValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:decimal, xs:integer, xs:nonPositiveInteger xs:negativeInteger,
 * xs:nonNegativeInteger xs:positiveInteger, xs:(unsigned)long, xs:(unsigned)int,
 * xs:(unsigned)short, xs:(unsigned)byte
 */
xs_decimal Item::getDecimalValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getDecimalValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:integer, xs:nonPositiveInteger xs:negativeInteger,
 * xs:nonNegativeInteger xs:positiveInteger, xs:(unsigned)long, xs:(unsigned)int,
 * xs:(unsigned)short, xs:(unsigned)byte
 */
xs_integer Item::getIntegerValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getIntegerValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:long, xs:int, xs:short, xs:byte
 */
xs_long Item::getLongValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getLongValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:int, xs:short, xs:byte
 */
xs_int Item::getIntValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getIntValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:short, xs:byte
 */
xs_short Item::getShortValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getShortValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:byte
 */
xs_byte Item::getByteValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getByteValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:unsignedLong,  xs:unsignedInt,  xs:unsignedShort,
 *  xs:unsignedByte, xs:nonNegativeInteager, xs:positiveInteger
 */
xs_nonNegativeInteger Item::getUnsignedIntegerValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getUnsignedIntegerValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:unsignedLong, xs:unsignedInt, xs:unsignedShort, xs:unsignedByte
 */
xs_unsignedLong Item::getUnsignedLongValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getUnsignedLongValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:unsignedInt, xs:unsignedShort, xs:unsignedByte
 */
xs_unsignedInt Item::getUnsignedIntValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getUnsignedIntValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:unsignedShort, xs:unsignedByte
 */
xs_unsignedShort Item::getUnsignedShortValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getUnsignedShortValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:unsignedByte
 */
xs_unsignedByte Item::getUnsignedByteValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getUnsignedByteValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:float
 */
xs_float Item::getFloatValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getFloatValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:double
 */
xs_double Item::getDoubleValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getDoubleValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:dateTime, xs:date
 */
const xs_date& Item::getDateValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getDateValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:dateTime
 */
const xs_dateTime& Item::getDateTimeValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getDateTimeValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:time
 */
const xs_time& Item::getTimeValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getTimeValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:gDay
 */
const xs_gDay& Item::getGDayValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getGDayValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:gMonth
 */
const xs_gMonth& Item::getGMonthValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getGMonthValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:gMonthDay
 */
const xs_gMonthDay& Item::getGMonthDayValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getGMonthDayValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:gYear
 */
const xs_gYear& Item::getGYearValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

/**
 * Accessor for xs:gYearMonth
 */
const xs_gYearMonth& Item::getGYearMonthValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getGYearMonthValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:duration
 */
const xs_duration& Item::getDurationValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getDurationValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:dayTimeDuration
 */
const xs_dayTimeDuration& Item::getDayTimeDurationValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getDayTimeDurationValue()",
      getType()->getStringValue()
    )
  );
}

/**
 * Accessor for xs:yearMonthDuration
 */
const xs_yearMonthDuration& Item::getYearMonthDurationValue() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getYearMonthDurationValue()",
      getType()->getStringValue()
    )
  );
}


/**
 * Accessor for xs:hexBinary
 */
char const* Item::getHexBinaryValue(size_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::getHexBinaryValue()",
      getType()->getStringValue()
    )
  );
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
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0040_TYPE_ERROR,
    ERROR_PARAMS(
      ZED( OperationNotDef_23 ), "Item::isPosOrNegInf()",
      getType()->getStringValue()
    )
  );
}


/* -----------------------  Methods for Nodes -------------------------------- */


bool Item::isValidated() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


void Item::markValidated()
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


bool Item::isRecursive() const
{
  return true;
}


void Item::getDocumentURI(zstring& uri) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


void Item::getBaseURI(zstring& uri) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


store::Iterator_t Item::getAttributes() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


store::Iterator_t Item::getChildren() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


bool Item::isId() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


bool Item::isIdRefs() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


void Item::getNamespaceBindings(
    NsBindings& bindings,
    StoreConsts::NsScoping ns_scoping) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


bool Item::getNilled() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


NodeKind Item::getNodeKind() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


store::Item* Item::getNodeName() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


zstring Item::getNamespacePrefix() const
{
  throw ZORBA_EXCEPTION(zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
  ERROR_PARAMS(__FUNCTION__, getType()->getStringValue()));
}


zstring Item::getNamespaceUri() const
{
  throw ZORBA_EXCEPTION(zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
  ERROR_PARAMS(__FUNCTION__, getType()->getStringValue()));
}


const store::Collection* Item::getCollection() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


Item* Item::getParent() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


void Item::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


bool Item::isInSubstitutionGroup() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


void Item::getUnparsedEntityPublicId(zstring& val) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


void Item::getUnparsedEntitySystemId(zstring& val) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


const zstring& Item::getTarget() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


zstring Item::show() const
{
  return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
}


zstring Item::toString() const
{
  return show();
}


void Item::finalizeNode()
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isAncestor(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isFollowingSibling(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isFollowing(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isInSubtreeOf(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isDescendant(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isPrecedingSibling(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isPreceding(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isChild(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isAttribute(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isParent(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isPrecedingInDocumentOrder(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isFollowingInDocumentOrder(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

store::Item_t
Item::getLevel() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isSibling(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isAttributeRef() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isCommentRef() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isDocumentRef() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


bool
Item::isElementRef() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isProcessingInstructionRef() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::isTextRef() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::inSameTree(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::inCollection() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool
Item::inSameCollection(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

store::Item_t
Item::leastCommonAncestor(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


#if 0
Item* Item::copy(
    store::Item* parent,
    vsize_t pos,
    const CopyMode& copymode) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}
#endif

Item* Item::copy(
    store::Item* parent,
    const CopyMode& copymode) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}


store::StoreConsts::JSONItemKind Item::getJSONItemKind() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

bool Item::isCollectionRoot() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

xs_integer
Item::getArraySize() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

store::Item_t
Item::getArrayValue(const xs_integer&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

store::Iterator_t
Item::getArrayValues() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

store::Iterator_t
Item::getObjectKeys() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

store::Item_t
Item::getObjectValue(const store::Item_t&) const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue())
  );
}


xs_integer
Item::getNumObjectPairs() const
{
  throw ZORBA_EXCEPTION(zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
  ERROR_PARAMS(__FUNCTION__, getType()->getStringValue()));
}


ZorbaException* Item::getError() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, "ErrorItem" )
  );
}

const Item_t Item::getFunctionName() const
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, "FunctionItem" )
  );
}

bool Item::isStreamable() const
{
  return false;
}

bool Item::isSeekable() const
{
  return false;
}

void
Item::ensureSeekable()
{
}

std::istream& Item::getStream()
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

StreamReleaser Item::getStreamReleaser()
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

void Item::setStreamReleaser(StreamReleaser /*aReleaser*/)
{
  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

void Item::swap(Item* anotherItem)
{
  if(isNode())
  {
    assert(anotherItem->isNode());
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->acquire());
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(anotherItem)->getRCLock()->acquire());
    // Swap trees.
    assert(theUnion.treeRCPtr);
    assert(anotherItem->theUnion.treeRCPtr);
    std::swap(theUnion.treeRCPtr, anotherItem->theUnion.treeRCPtr);

    // Adjust counters.
    *theUnion.treeRCPtr += theRefCount;
    *theUnion.treeRCPtr -= anotherItem->theRefCount;
    *anotherItem->theUnion.treeRCPtr -= theRefCount;
    *anotherItem->theUnion.treeRCPtr += anotherItem->theRefCount;
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(this)->getRCLock()->release());
    SYNC_CODE(static_cast<const simplestore::XmlNode*>(anotherItem)->getRCLock()->release());
    return;
  }

  throw ZORBA_EXCEPTION(
    zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS( __FUNCTION__, getType()->getStringValue() )
  );
}

std::ostream& operator<<( std::ostream &o, Item::ItemKind k ) {
  switch ( k ) {
    case Item::NODE:      o << "node";      break;
    case Item::ATOMIC:    o << "atomic";    break;
    case Item::PUL:       o << "pul";       break;
    case Item::FUNCTION:  o << "function";  break;
    case Item::LIST:      o << "list";      break;
    case Item::OBJECT:    o << "object";    break;
    case Item::ARRAY:     o << "array";     break;
    case Item::ERROR_:    o << "error";     break;
    default:
      o << "<unknown ItemKind: " << (int)k << '>';
  }
  return o;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace store
} // namespace zorba
/* vim:set et sw=2 ts=2: */
