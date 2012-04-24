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
#include "atomic_items.h"

#include <limits.h>

#include <zorba/internal/unique_ptr.h>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "zorbatypes/collation_manager.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/URI.h"

#include "zorbautils/hashfun.h"

#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/collection.h"
#include "qname_pool.h"
#include "simple_store.h"
#include "simple_item_factory.h"
#include "store_defs.h"
#include "item_iterator.h"
#include "node_items.h"
#include "ordpath.h"
#include "tree_id.h"

#include "util/ascii_util.h"
#include "util/string_util.h"
#include "util/utf8_util.h"

#define CREATE_XS_TYPE(aType) \
  GET_STORE().getItemFactory()->createQName(Store::XS_URI, "xs", aType);

#define CREATE_BOOLITEM(item, aValue) \
  GET_STORE().getItemFactory()->createBoolean(item, aValue)

using namespace std;
#ifndef ZORBA_NO_FULL_TEXT
using namespace zorba::locale;
#endif /* ZORBA_NO_FULL_TEXT */

namespace zorba {
namespace simplestore {


/*******************************************************************************

********************************************************************************/
void AtomicItem::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  store::Item* lItem = const_cast<AtomicItem *>(this);
  val = lItem;
}


/*******************************************************************************
  For numeric items or the untyped item: convert this item to a long item,
  if possible, i.e., if the conversion is going to be lossless.
********************************************************************************/
bool AtomicItem::castToLong(store::Item_t& result) const
{
  xs_long longValue;

  result = NULL;

  const AtomicItem* item1 = static_cast<AtomicItem*>(getBaseItem());
  if (item1 == NULL)
    item1 = this;

  switch (item1->getTypeCode())
  {
  case store::XS_UNTYPED_ATOMIC:
  {
    const UntypedAtomicItem* item = static_cast<const UntypedAtomicItem*>(item1);
    try
    {
      longValue = ztd::aton<xs_long>(item->theValue.c_str());
      GET_FACTORY().createLong(result, longValue);
    }
    catch (std::exception const&)
    {
      // ignore
    }
    break;
  }

  case store::XS_DOUBLE:
  case store::XS_FLOAT:
  {
    double doubleValue = item1->getDoubleValue().getNumber();
    longValue = static_cast<xs_long>(doubleValue);

    if (doubleValue == static_cast<double>(longValue))
      GET_FACTORY().createLong(result, longValue);

    break;
  }

  case store::XS_DECIMAL:
  {
    const DecimalItem* item = static_cast<const DecimalItem*>(item1);
    try
    {
      longValue = to_xs_long(item->theValue);
      GET_FACTORY().createLong(result, longValue);
    }
    catch (std::range_error const&)
    {
      // ignore
    }
    break;
  }

  case store::XS_INTEGER:
  case store::XS_NON_POSITIVE_INTEGER:
  case store::XS_NEGATIVE_INTEGER:
  case store::XS_NON_NEGATIVE_INTEGER:
  case store::XS_POSITIVE_INTEGER:
  {
    const IntegerItem* item = static_cast<const IntegerItem*>(item1);
    try
    {
      longValue = item->getLongValue();
      GET_FACTORY().createLong(result, longValue);
    }
    catch (std::range_error const&)
    {
      // ignore
    }
    break;
  }

  case store::XS_UNSIGNED_LONG:
  {
    const UnsignedLongItem* item = static_cast<const UnsignedLongItem*>(item1);
    if ((item->theValue >> 63) == 0)
    {
      longValue = static_cast<xs_long>(item->theValue);
      GET_FACTORY().createLong(result, longValue);
    }
    break;
  }

  default:
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS(__FUNCTION__, typeid(*this).name()));
  }
  }

  return (result != NULL);
}


/*******************************************************************************
  For numeric items: convert this item to a double item. If the conversion is
  a lossy one, set "lossy" to true, otherwise set "lossy" to false. If "force"
  is true, the conversion is done always; otherwise, the conversion is done only
  if it is lossy.
********************************************************************************/
void AtomicItem::coerceToDouble(store::Item_t& result, bool force, bool& lossy) const
{
  xs_double doubleValue;

  result = NULL;

  const AtomicItem* item1 = static_cast<AtomicItem*>(getBaseItem());
  if (item1 == NULL)
    item1 = this;

  switch (item1->getTypeCode())
  {
  case store::XS_DECIMAL:
  {
    const DecimalItem* item = static_cast<const DecimalItem*>(item1);

    doubleValue = item->theValue;

    const xs_decimal decValue(doubleValue);

    lossy = (decValue != item->theValue);
    break;
  }

  case store::XS_INTEGER:
  case store::XS_NON_POSITIVE_INTEGER:
  case store::XS_NEGATIVE_INTEGER:
  case store::XS_NON_NEGATIVE_INTEGER:
  case store::XS_POSITIVE_INTEGER:
  {
    const IntegerItem* item = static_cast<const IntegerItem*>(item1);

    doubleValue = item->getIntegerValue();

    const xs_integer intValue(doubleValue);

    lossy = (intValue != item->getIntegerValue());
    break;
  }

  case store::XS_UNSIGNED_LONG:
  {
    const UnsignedLongItem* item = static_cast<const UnsignedLongItem*>(item1);

    doubleValue = item->theValue;

    xs_unsignedLong ulongValue = static_cast<xs_unsignedLong>(doubleValue.getNumber());

    lossy = (ulongValue != item->theValue);
    break;
  }

  case store::XS_UNSIGNED_INT:
  case store::XS_UNSIGNED_SHORT:
  case store::XS_UNSIGNED_BYTE:
  {
    doubleValue = getUnsignedIntValue();
    lossy = false;
    break;
  }

  case store::XS_LONG:
  {
    const LongItem* item = static_cast<const LongItem*>(item1);

    doubleValue = item->theValue;

    xs_long longValue = static_cast<xs_long>(doubleValue.getNumber());

    lossy = (longValue != item->theValue);
    break;
  }

  case store::XS_INT:
  case store::XS_SHORT:
  case store::XS_BYTE:
  {
    doubleValue = item1->getIntValue();
    lossy = false;
    break;
  }

  default:
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS(__FUNCTION__, typeid(*this).name()));
  }
  }

  if (force || lossy)
    GET_FACTORY().createDouble(result, doubleValue);
}


#if 0
/*******************************************************************************
  For xs:double and xs:float items: convert this item to an xs:long item. If 
  the conversion is a lossy one, set "lossy" to true, otherwise set "lossy" 
  to false. 
********************************************************************************/
void AtomicItem::coerceToLong(
    store::Item_t& result,
    bool& lossy,
    bool& negINF,
    bool& posINF) const
{
  if (getTypeCode() != store::XS_DOUBLE && getTypeCode() != store::XS_FLOAT)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
    ERROR_PARAMS(__FUNCTION__, typeid(*this).name()));
  }

  xs_double doubleObj = getDoubleValue();

  if (doubleObj.isNaN())
    throw ZORBA_EXCEPTION(zerr::ZSTR0041_NAN_COMPARISON);

  int64_t longMax = std::numeric_limits<int64_t>::max();
  int64_t longMin = std::numeric_limits<int64_t>::min();

  int64_t longValue;

  if (doubleObj.isPosInf())
  {
    longValue = longMax;
    lossy = true;
    negINF = false;
    posINF = true;
  }
  else if (doubleObj.isNegInf())
  {
    longValue = longMin;
    lossy = true;
    negINF = true;
    posINF = false;
  }
  else
  {
    double doubleMaxLong = static_cast<double>(longMax);
    double doubleMinLong = static_cast<double>(longMin);

    assert(longMax == static_cast<int64_t>(doubleMaxLong));
    assert(longMin == static_cast<int64_t>(doubleMinLong));

    double doubleValue = doubleObj.getNumber();

    if (doubleValue > doubleMaxLong)
    {
      longValue = longMax;
      lossy = true;
      negINF = false;
      posINF = true;
    }
    else if (doubleValue < doubleMinLong)
    {
      longValue = longMin;
      lossy = true;
      negINF = true;
      posINF = false;
    }
    else
    {
      double doubleFloor = ::floor(doubleValue);
      longValue = static_cast<uint64_t>(doubleFloor);
      lossy = (doubleFloor != doubleValue);
      negINF = false;
      posINF = false;
    }
  }

  GET_FACTORY().createLong(result, longValue);
}
#endif


/*******************************************************************************
  class UserTypedAtomicItem
********************************************************************************/
store::Item* UserTypedAtomicItem::getBaseItem() const 
{
  store::Item* baseItem = theBaseItem.getp();

  while (baseItem->getBaseItem() != NULL)
  {
    baseItem = baseItem->getBaseItem();
  }

  return baseItem;
}


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
bool UntypedAtomicItem::castToUri(store::Item_t& result) const
{
  result = NULL;

  try
  {
    URI uriVal(theValue);
    zstring tmp = uriVal.toString();
    return GET_FACTORY().createAnyURI(result, tmp);
  }
  catch (ZorbaException const&)
  {
    result = NULL;
  }

  return false;
}


bool UntypedAtomicItem::castToString(store::Item_t& result) const
{
  zstring tmp = theValue;
  return GET_FACTORY().createString(result, tmp);
}


bool UntypedAtomicItem::castToDateTime(store::Item_t& result) const
{
  return GET_FACTORY().createDateTime(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToDate(store::Item_t& result) const
{
  return GET_FACTORY().createDate(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToTime(store::Item_t& result) const
{
  return GET_FACTORY().createTime(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToGYear(store::Item_t& result) const
{
  return GET_FACTORY().createGYear(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToGYearMonth(store::Item_t& result) const
{
  return GET_FACTORY().createGYearMonth(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToGMonthDay(store::Item_t& result) const
{
  return GET_FACTORY().createGMonthDay(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToGMonth(store::Item_t& result) const
{
  return GET_FACTORY().createGMonth(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToGDay(store::Item_t& result) const
{
  return GET_FACTORY().createGDay(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToDuration(store::Item_t& result) const
{
  return GET_FACTORY().createDuration(result, theValue.c_str(), theValue.size());
}


bool UntypedAtomicItem::castToDouble(store::Item_t& result) const
{
  try 
  {
    xs_double const doubleValue(theValue.c_str());
    return GET_FACTORY().createDouble(result, doubleValue);
  }
  catch ( std::exception const& ) 
  {
    result = NULL;
    return false;
  }
}


bool UntypedAtomicItem::castToDecimal(store::Item_t& result) const
{
  try
  {
    xs_decimal const decValue(theValue.c_str());
    return GET_FACTORY().createDecimal(result, decValue);
  }
  catch ( std::exception const& )
  {
    result = NULL;
    return false;
  }
}


bool UntypedAtomicItem::castToInteger(store::Item_t& result) const
{
  try
  {
    xs_integer const intValue(theValue.c_str());
    return GET_FACTORY().createInteger(result, intValue);
  }
  catch ( std::exception const& )
  {
    result = NULL;
    return false;
  }
}


bool UntypedAtomicItem::castToHexBinary(store::Item_t& result) const
{
  Base16 value;
  if (Base16::parseString(theValue, value))
  {
    return GET_FACTORY().createHexBinary(result, value);
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool UntypedAtomicItem::castToBase64Binary(store::Item_t& result) const
{
  Base64 value;
  if (Base64::parseString(theValue, value))
  {
    return GET_FACTORY().createBase64Binary(result, value);
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool UntypedAtomicItem::castToBoolean(store::Item_t& result) const
{
  zstring str;
  ascii::trim_whitespace(theValue, &str);
  bool value = true;

  if (ZSTREQ(str, "false") || ZSTREQ(str, "0"))
  {
    value = false;
  }
  else if (!ZSTREQ(str, "true") && !ZSTREQ(str, "1"))
  {
    result = NULL;
    return false;
  }

  return GET_FACTORY().createBoolean(result, value);
}


store::Item* UntypedAtomicItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_UNTYPED_ATOMIC];
}


uint32_t UntypedAtomicItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return utf8::hash(theValue);
}


bool UntypedAtomicItem::equals(
    const store::Item* other,
    long timezone,
    const XQPCollator* collation) const
{
  if (collation == NULL || collation->doMemCmp())
    return theValue == other->getString();

  return (utf8::compare(theValue, other->getString(), collation) == 0);
}


long UntypedAtomicItem::compare(
    const Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  // Note: utf8::compare does byte comparison if the collation is null or
  // requires byte comparison.
  return utf8::compare(theValue, other->getString(), aCollation);
}


bool UntypedAtomicItem::getEBV() const
{
  return ! ( theValue == "" );
}


zstring UntypedAtomicItem::show() const
{
  zstring res("xs:untypedAtomic(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class QNameItem
********************************************************************************/
QNameItem::QNameItem(
    const char* aNamespace,
    const char* aPrefix,
    const char* aLocalName)
  :
  theNormalizedQName(NULL),
  theIsInPool(false)
{
  initializeAsQNameNotInPool(aNamespace, aPrefix, aLocalName);
}


QNameItem::QNameItem(
    const zstring& aNamespace,
    const zstring& aPrefix,
    const zstring& aLocalName)
  :
  theNormalizedQName(NULL),
  theIsInPool(false)
{
  initializeAsQNameNotInPool(aNamespace, aPrefix, aLocalName);
}


void QNameItem::initializeAsQNameNotInPool(
    const zstring& aNamespace,
    const zstring& aPrefix,
    const zstring& aLocalName)
{
  assert(!isValid());

  store::Item_t lPoolQName =
      GET_STORE().getQNamePool().insert(aNamespace, zstring(), aLocalName);

  QNameItem* lNormalized = static_cast<QNameItem*>(lPoolQName.getp());
  assert(lNormalized->isNormalized());

  initializeAsUnnormalizedQName(lNormalized, aPrefix);

  theIsInPool = false;
}


void QNameItem::free()
{
  QNamePool& thePool = GET_STORE().getQNamePool();

  if (theIsInPool)
  {
    thePool.remove(this);
    return;
  }
  
  assert(!isNormalized());

  invalidate(false, NULL);
  delete this;
}


uint32_t QNameItem::hash(long timezone, const XQPCollator* aCollation) const
{
  const void* tmp = theNormalizedQName;
  return hashfun::h32(&tmp, sizeof(void*), FNV_32_INIT);
}


store::Item* QNameItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_QNAME];
}


bool QNameItem::getEBV() const
{
  throw XQUERY_EXCEPTION(err::FORG0006,
  ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "QName"));
}


bool QNameItem::equals(
    const store::Item* item,
    long timezone,
    const XQPCollator* aCollation) const
{
  return theNormalizedQName ==
      static_cast<const QNameItem*>(item)->theNormalizedQName;
}


zstring QNameItem::getStringValue() const
{
  if (thePrefix.empty())
  {
    return getLocalName();
  }
  else
  {
    return (thePrefix + ":" + getLocalName());
  }
}


void QNameItem::getStringValue2(zstring& val) const
{
  if (thePrefix.empty())
  {
    val = getLocalName();
  }
  else
  {
    val.reserve(thePrefix.size() + getLocalName().size() + 1);
    val = thePrefix;
    val += ":";
    val += getLocalName();
  }
}


void QNameItem::appendStringValue(zstring& buf) const
{
  if (thePrefix.empty())
  {
    buf += getLocalName();
  }
  else
  {
    buf.reserve(buf.size() + thePrefix.size() + getLocalName().size() + 1);
    buf += thePrefix;
    buf += ":";
    buf += getLocalName();
  }
}


bool QNameItem::isIdQName() const
{
  if (ZSTREQ(getLocalName(), "id"))
  {
    if (ZSTREQ(getPrefix(), "xml") ||
        ztd::equals(theNamespace, Store::XML_URI, Store::XML_URI_LEN))
      return true;
  }

  return false;
}


bool QNameItem::isBaseUri() const
{
  if (ZSTREQ(getLocalName(), "base"))
  {
    if (ZSTREQ(getPrefix(), "xml") ||
        ztd::equals(getNamespace(), Store::XML_URI, Store::XML_URI_LEN))
      return true;
  }

  return false;
}


zstring QNameItem::show() const
{
  zstring res("xs:QName(");
  res += getNamespace();
  res += ",";
  res += getPrefix();
  res += ",";
  res += getLocalName();
  res += ")";
  return res;
}

/*******************************************************************************
  class NotationItem
********************************************************************************/

NotationItem::NotationItem(
    const zstring& nameSpace,
    const zstring& prefix,
    const zstring& localName)
{
  store::Item_t temp;
  GET_FACTORY().createQName(temp, nameSpace, prefix, localName);
  theQName = static_cast<QNameItem*>(temp.getp());
}


NotationItem::NotationItem(store::Item* qname)
{
  theQName = qname;
}


bool NotationItem::equals(
    const store::Item* item,
    long timezone,
    const XQPCollator* aCollation) const
{
  return theQName->equals(
      static_cast<const NotationItem*>(item)->theQName);
}


store::Item* NotationItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NOTATION];
}


zstring NotationItem::getStringValue() const
{
  return theQName->getStringValue();
}


void NotationItem::getStringValue2(zstring& val) const
{
  theQName->getStringValue2(val);
}


void NotationItem::appendStringValue(zstring& buf) const
{
  theQName->appendStringValue(buf);
}


zstring NotationItem::show() const
{
  zstring res("xs:NOTATION(");
  res += theQName->getStringValue();
  res += ")";
  return res;
}


NotationItem::~NotationItem()
{
}


/*******************************************************************************
  class AnyUriItem
********************************************************************************/
store::Item* AnyUriItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_ANY_URI];
}


uint32_t AnyUriItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return hashfun::h32(theValue.data(), (uint32_t)theValue.size());
}


bool AnyUriItem::getEBV() const
{
  return ! (theValue == "");
}


zstring AnyUriItem::show() const
{
  zstring res("xs:anyURI(");
  res += theValue;
  res += ")";
  return res;
}


bool AnyUriItem::isAncestor(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isAncestor(aOther);
}


bool AnyUriItem::isFollowingSibling(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isFollowingSibling(aOther);
}


bool AnyUriItem::isFollowing(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isFollowing(aOther);
}


bool AnyUriItem::isDescendant(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isDescendant(aOther);
}


bool AnyUriItem::isInSubtreeOf(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isInSubtreeOf(aOther);
}


bool AnyUriItem::isPrecedingSibling(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isPrecedingSibling(aOther);
}


bool AnyUriItem::isPreceding(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isPreceding(aOther);
}


bool AnyUriItem::isChild(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isChild(aOther);
}


bool AnyUriItem::isAttribute(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isAttribute(aOther);
}


bool AnyUriItem::isParent(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isParent(aOther);
}


bool AnyUriItem::isPrecedingInDocumentOrder(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isPrecedingInDocumentOrder(aOther);
}


bool AnyUriItem::isFollowingInDocumentOrder(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isFollowingInDocumentOrder(aOther);
}


store::Item_t AnyUriItem::getLevel() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->getLevel();
}


bool AnyUriItem::isAttribute() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isAttribute();
}


bool AnyUriItem::isComment() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isComment();
}


bool AnyUriItem::isDocument() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isDocument();
}


bool AnyUriItem::isElement() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isElement();
}


bool AnyUriItem::isProcessingInstruction() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isProcessingInstruction();
}


bool AnyUriItem::isText() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isText();
}


bool AnyUriItem::isSibling(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->isSibling(aOther);
}


bool AnyUriItem::inSameTree(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->inSameTree(aOther);
}


bool AnyUriItem::inCollection() const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return static_cast<StructuralAnyUriItem *>(lThisUri.getp())->inCollection();
}


bool AnyUriItem::inSameCollection(const store::Item_t& aOther) const
{
  store::Item_t lThisUri;
  zstring tempValue=theValue;
  GET_FACTORY().createStructuralAnyURI(lThisUri, tempValue);
  return lThisUri->inSameCollection(aOther);
}


/*******************************************************************************
  class StructuralAnyUriItem
********************************************************************************/

StructuralAnyUriItem::StructuralAnyUriItem(
    ulong collectionId,
    const TreeId& treeId, 
    store::StoreConsts::NodeKind nodeKind,
    const OrdPath& ordPath)
  :
  theCollectionId(collectionId),
  theTreeId(treeId),
  theNodeKind(nodeKind),
  theOrdPath(ordPath),
  theEncodedValue("")
{}

StructuralAnyUriItem::StructuralAnyUriItem(const zstring& value)
{
  if (value == "")
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));

  theEncodedValue = value;
  std::istringstream input(theEncodedValue.str());

  ulong prefixlen = (ulong)strlen("zorba:");

  input.width(prefixlen);

  std::string prefix;
  input >> prefix;

  if (!input.good())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));

  if (prefix != "zorba:")
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));

  input >> theCollectionId;

  if (!input.good())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
  
  char period;
  input >> period;
  if (!input.good())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
  if (period != '.')
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
    

  input >> theTreeId;
  if (!input.good())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
  
  input >> period;
  if (!input.good())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
  if (period != '.')
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));

  int lNodeKind;
  input >> lNodeKind;
  theNodeKind = static_cast<store::StoreConsts::NodeKind>(lNodeKind);
  if (!input.good())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
  if (lNodeKind <= 0 || lNodeKind > 6)
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                           ERROR_PARAMS(theEncodedValue));

  input >> period;
  if (period != '.')
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
  if (!input.good())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));
    
  input >> prefix;
  if (!input.eof())
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI,
                          ERROR_PARAMS(theEncodedValue));

  try 
  {
    theOrdPath.deserialize(prefix);
  }
  catch(...) 
  {
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI, ERROR_PARAMS(theEncodedValue));
  }
}

store::Item* StructuralAnyUriItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_ANY_URI];
}


uint32_t StructuralAnyUriItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return hashfun::h32(theEncodedValue.data(), (uint32_t)theEncodedValue.size());
}

void StructuralAnyUriItem::encode() const
{
  ZORBA_FATAL(theNodeKind,"Unexpected node kind");
  std::ostringstream stream;
  stream   << "zorba:"
           << theCollectionId << "."
           << theTreeId << "."
           << static_cast<int>(theNodeKind) << "."
           << theOrdPath.serialize();
  zorba::zstring lValue = stream.str();
  theEncodedValue.take(lValue);
}


zstring StructuralAnyUriItem::show() const
{
  zstring res("xs:anyURI(");
  res += getString();
  res += ")";
  return res;
}
 
bool StructuralAnyUriItem::equals(
        const store::Item* item,
        long timezone,
        const XQPCollator* aCollation) const
{
  const StructuralAnyUriItem* lOther =
      dynamic_cast<const StructuralAnyUriItem*>(item);
  return (lOther &&
      lOther->theCollectionId == theCollectionId &&
      lOther->theTreeId == theTreeId &&
      lOther->theNodeKind == theNodeKind &&
      lOther->theOrdPath == theOrdPath);
}
 
long StructuralAnyUriItem::compare(
      const Item* other,
      long timezone,
      const XQPCollator* aCollation) const
{
  const StructuralAnyUriItem* lOther =
      dynamic_cast<const StructuralAnyUriItem*>(other);
  assert(lOther);
  if (theCollectionId < lOther->theCollectionId)
  {
    return -1;
  }
  if (theCollectionId > lOther->theCollectionId)
  {
    return 1;
  }
  if (theTreeId < lOther->theTreeId)
  {
    return -1;
  }
  if (theTreeId > lOther->theTreeId)
  {
    return 1;
  }
  if (theNodeKind < lOther->theNodeKind)
  {
    return -1;
  }
  if (theNodeKind > lOther->theNodeKind)
  {
    return 1;
  }
  if (theOrdPath < lOther->theOrdPath)
  {
    return -1;
  }
  if (theOrdPath > lOther->theOrdPath)
  {
    return 1;
  }
  return 0;
}
 
zstring StructuralAnyUriItem::getStringValue() const {
  return getString();
}
 
void StructuralAnyUriItem::getStringValue2(zstring& val) const {
  val = getString();
}
 
void StructuralAnyUriItem::appendStringValue(zstring& buf) const {
  buf += getString();
}

bool StructuralAnyUriItem::isAncestor(const store::Item_t& aOther) const
{
  // Is the "other" an ancestor of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isAncestor(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());

    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     theOrdPath.getRelativePosition(other->theOrdPath) == OrdPath::ANCESTOR);
  }
}


bool StructuralAnyUriItem::isFollowingSibling(const store::Item_t& aOther) const
{
  // Is the "other" a following sibling of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isFollowingSibling(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());

    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     other->theNodeKind != store::StoreConsts::attributeNode &&
     theNodeKind != store::StoreConsts::attributeNode &&
     theOrdPath.getRelativePosition2(other->theOrdPath) == OrdPath::FOLLOWING_SIBLING);
  }
}


bool StructuralAnyUriItem::isFollowing(const store::Item_t& aOther) const
{
  // Is the "other" a following node of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isFollowing(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());

    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     theOrdPath.getRelativePosition(other->theOrdPath) == OrdPath::FOLLOWING);
  }
}


bool StructuralAnyUriItem::isDescendant(const store::Item_t& aOther) const
{
  // Is the "other" a descendant of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isDescendant(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     other->theNodeKind != store::StoreConsts::attributeNode &&
     theOrdPath.getRelativePosition(other->theOrdPath) == OrdPath::DESCENDANT);
  }
}


bool StructuralAnyUriItem::isInSubtreeOf(const store::Item_t& aOther) const
{
  // Is the "other" in the subtree rooted at "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isInSubtreeOf(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     theOrdPath.getRelativePosition(other->theOrdPath) == OrdPath::DESCENDANT);
  }
}


bool StructuralAnyUriItem::isPrecedingSibling(const store::Item_t& aOther) const
{
  // Is the "other" a preceding sibling of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isPrecedingSibling(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     other->theNodeKind != store::StoreConsts::attributeNode &&
     theNodeKind != store::StoreConsts::attributeNode &&
     theOrdPath.getRelativePosition2(other->theOrdPath) == OrdPath::PRECEDING_SIBLING);
  }
}


bool StructuralAnyUriItem::isPreceding(const store::Item_t& aOther) const
{
  // Is the "other" a preceding node of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isPreceding(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     theOrdPath.getRelativePosition(other->theOrdPath) == OrdPath::PRECEDING);
  }
}


bool StructuralAnyUriItem::isChild(const store::Item_t& aOther) const
{
  // Is the "other" a child of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isChild(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     other->theNodeKind != store::StoreConsts::attributeNode &&
     theOrdPath.getRelativePosition2(other->theOrdPath) == OrdPath::CHILD);
  }
}


bool StructuralAnyUriItem::isAttribute(const store::Item_t& aOther) const
{
  // Is the "other" an attribute of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isAttribute(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     other->theNodeKind == store::StoreConsts::attributeNode &&
     theOrdPath.getRelativePosition2(other->theOrdPath) == OrdPath::CHILD);
  }
}


bool StructuralAnyUriItem::isParent(const store::Item_t& aOther) const
{
  // Is the "other" an parent of "this"?

  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isParent(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return 
    (other->theCollectionId == theCollectionId &&
     other->theTreeId == theTreeId &&
     theOrdPath.getRelativePosition2(other->theOrdPath) == OrdPath::PARENT);
  }
}


bool StructuralAnyUriItem::isPrecedingInDocumentOrder(const store::Item_t& aOther) const
{
  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isPrecedingInDocumentOrder(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return
    (theCollectionId > other->theCollectionId ||
    (theCollectionId == other->theCollectionId &&
        other->theTreeId < theTreeId) ||
    (theCollectionId == other->theCollectionId &&
        other->theTreeId == theTreeId &&
        theOrdPath > other->theOrdPath));
  }
}


bool StructuralAnyUriItem::isFollowingInDocumentOrder(const store::Item_t& aOther) const
{
  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isFollowingInDocumentOrder(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return
    (theCollectionId < other->theCollectionId ||
    (theCollectionId == other->theCollectionId &&
        theTreeId < other->theTreeId) ||
    (theCollectionId == other->theCollectionId &&
        other->theTreeId == theTreeId &&
        theOrdPath < other->theOrdPath));
  }
}


store::Item_t StructuralAnyUriItem::getLevel() const
{
  store::Item_t lResult;
  GET_FACTORY().createInteger(lResult, xs_integer(theOrdPath.getLevel()));
  return lResult;
}


bool StructuralAnyUriItem::isAttribute() const
{
  return theNodeKind == store::StoreConsts::attributeNode;
}


bool StructuralAnyUriItem::isComment() const
{
  return theNodeKind == store::StoreConsts::commentNode;
}


bool StructuralAnyUriItem::isDocument() const
{
  return theNodeKind == store::StoreConsts::documentNode;
}


bool StructuralAnyUriItem::isElement() const
{
  return theNodeKind == store::StoreConsts::elementNode;
}


bool StructuralAnyUriItem::isProcessingInstruction() const
{
  return theNodeKind == store::StoreConsts::piNode;
}


bool StructuralAnyUriItem::isText() const
{
  return theNodeKind == store::StoreConsts::textNode;
}


bool StructuralAnyUriItem::isSibling(const store::Item_t& aOther) const
{
  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return isSibling(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());

    if (other->theCollectionId == theCollectionId &&
        other->theTreeId == theTreeId &&
        other->theNodeKind != store::StoreConsts::attributeNode &&
        theNodeKind != store::StoreConsts::attributeNode)
    {
      OrdPath::RelativePosition pos = 
      theOrdPath.getRelativePosition2(other->theOrdPath);

      return (pos == OrdPath::FOLLOWING_SIBLING ||
              pos==OrdPath::PRECEDING_SIBLING);
    }
    else
    {
      return false;
    }
  }
}


bool StructuralAnyUriItem::inSameTree(const store::Item_t& aOther) const
{
  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return inSameTree(lOtherUri);
  }
  else
  {
    StructuralAnyUriItem* other = static_cast<StructuralAnyUriItem*>(aOther.getp());
    return (theCollectionId == other->theCollectionId &&
            other->theTreeId == theTreeId);
  }
}


bool StructuralAnyUriItem::inCollection() const
{
  return theCollectionId != 0;
}


bool StructuralAnyUriItem::inSameCollection(const store::Item_t& aOther) const
{
  AnyUriItem* lOtherUriP = static_cast<AnyUriItem *>(aOther.getp());

  if (lOtherUriP->getAnyUriTypeCode() != STRUCTURAL_INFORMATION_ANY_URI)
  {
    store::Item_t lOtherUri;
    zstring tmp = lOtherUriP->getString();
    GET_FACTORY().createStructuralAnyURI(lOtherUri, tmp);
    return inSameCollection(lOtherUri);
  }
  else
  {
    return
    (
     theCollectionId !=0 &&
     theCollectionId == static_cast<StructuralAnyUriItem*>(aOther.getp())->theCollectionId
    );

  }
}


/*******************************************************************************
  class StringItem
********************************************************************************/
store::Item* StringItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_STRING];
}


uint32_t StringItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return utf8::hash(theValue, aCollation);
}


bool StringItem::equals(
    const store::Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  if (aCollation == NULL || aCollation->doMemCmp())
    return theValue == other->getString();

  return (utf8::compare(theValue, other->getString(), aCollation) == 0);
}


long StringItem::compare(
    const Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  // Note: utf8::compare does byte comparison if the collation is null or
  // requires byte comparison.
  return utf8::compare(theValue, other->getString(), aCollation);
}


bool StringItem::getEBV() const
{
  return ! ( theValue == "" );
}


zstring StringItem::show() const
{
  zstring res("xs:string(");
  res += theValue;
  res += ")";
  return res;
}

#ifndef ZORBA_NO_FULL_TEXT
FTTokenIterator_t StringItem::getTokens( 
    TokenizerProvider const &provider,
    Tokenizer::Numbers &numbers,
    iso639_1::type lang,
    bool wildcards ) const
{
  typedef NaiveFTTokenIterator::container_type tokens_t;
  unique_ptr<tokens_t> tokens( new tokens_t );

  Tokenizer::ptr t( provider.getTokenizer( lang, numbers ) );
  AtomicItemTokenizerCallback cb( *t, lang, *tokens );
  cb.tokenize( theValue.data(), theValue.size(), wildcards );

  return FTTokenIterator_t( new NaiveFTTokenIterator( tokens.release() ) );
}
#endif /* ZORBA_NO_FULL_TEXT */


/*******************************************************************************
  class StreamableStringItem
********************************************************************************/
void StreamableStringItem::appendStringValue(zstring& aBuf) const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  aBuf += theValue;
}


long StreamableStringItem::compare( 
    const Item* aOther,
    long aTimezone,
    const XQPCollator* aCollator) const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  return StringItem::compare(aOther, aTimezone, aCollator);
}


bool StreamableStringItem::equals( 
    store::Item const* aItem,
    long aTimezone,
    XQPCollator const* aCollator) const 
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  return StringItem::equals(aItem, aTimezone, aCollator);
}


bool StreamableStringItem::getEBV() const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  return StringItem::getEBV();
}


zstring const& StreamableStringItem::getString() const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  return theValue;
}


zstring StreamableStringItem::getStringValue() const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  return theValue;
}


void StreamableStringItem::getStringValue2(zstring &val) const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  val = theValue;
}


uint32_t StreamableStringItem::hash(
    long aTimezone,
    XQPCollator const* aCollator) const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  return StringItem::hash(aTimezone, aCollator);
}


zstring StreamableStringItem::show() const
{
  if (!theIsMaterialized) 
  {
    materialize();
  }
  return StringItem::show();
}


bool StreamableStringItem::isStreamable() const
{
  return true;
}


bool StreamableStringItem::isSeekable() const
{
  return theIsSeekable;
}


std::istream& StreamableStringItem::getStream()
{
  // a non-seekable stream can only be consumed once
  // we raise an error if getStream is called twice
  // if a query requires a stream to be consumed more than once,
  // the query needs to make sure that the stream is explicitly
  // materialized before
  if (!theIsSeekable && theIsConsumed) 
  {
    throw ZORBA_EXCEPTION( zerr::ZSTR0055_STREAMABLE_STRING_CONSUMED );
  }
  else
  {
    // if the stream is seekable, we seek to the beginning.
    // We are not using theIstream.seekg because the USER_ERROR that is thrown
    // by Zorba is lost possibly in an internal try/catch of the seekg
    std::streambuf * pbuf;
    pbuf = theIstream.rdbuf();
    pbuf->pubseekoff(0, std::ios::beg);
    theIstream.clear();
  }
  theIsConsumed = true;
  return theIstream;
}


StreamReleaser StreamableStringItem::getStreamReleaser()
{
  return theStreamReleaser;
}


void StreamableStringItem::setStreamReleaser(StreamReleaser aReleaser)
{
  theStreamReleaser = aReleaser;
}


void StreamableStringItem::materialize() const
{
  StreamableStringItem* const lSsi = const_cast<StreamableStringItem*>(this);
  std::istream& lStream = lSsi->getStream();

  lSsi->theIsMaterialized = true;
  lSsi->theIsConsumed = true;

  char lBuf[4096];
  while (theIstream) 
  {
    lStream.read(lBuf, sizeof(lBuf));
    lSsi->theValue.append(lBuf, static_cast<unsigned int>(lStream.gcount()));
  }
}


/*******************************************************************************
  class NormalizedStringItem
********************************************************************************/
store::Item* NormalizedStringItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NORMALIZED_STRING];
}


zstring NormalizedStringItem::show() const
{
  zstring res("xs:NormalizedString(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class TokenItem
********************************************************************************/
store::Item* TokenItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_TOKEN];
}


zstring TokenItem::show() const
{
  zstring res("xs:TOKEN(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class LanguageItem
********************************************************************************/
store::Item* LanguageItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_LANGUAGE];
}


zstring LanguageItem::show() const
{
  zstring res("xs:LANGUAGE(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class NMTOKENItem
********************************************************************************/
store::Item* NMTOKENItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NMTOKEN];
}


zstring NMTOKENItem::show() const
{
  zstring res("xs:NMTOKEN(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class NameItem
********************************************************************************/
store::Item* NameItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NAME];
}


zstring NameItem::show() const
{
  zstring res("xs:NAME(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class NCNameItem
********************************************************************************/
store::Item* NCNameItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NCNAME];
}


zstring NCNameItem::show() const
{
  zstring res("xs:NCName(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class IDItem
********************************************************************************/
store::Item* IDItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_ID];
}


zstring IDItem::show() const
{
  zstring res("xs:ID(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class IDREFItem
********************************************************************************/
store::Item* IDREFItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_IDREF];
}


zstring IDREFItem::show() const
{
  zstring res("xs:IDREF(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class ENTITYItem
********************************************************************************/
store::Item* ENTITYItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_ENTITY];
}

zstring ENTITYItem::show() const
{
  zstring res("xs:ENTITY(");
  res += theValue;
  res += ")";
  return res;
}


/*******************************************************************************
  class DateTimeItem
********************************************************************************/
zstring DateTimeItem::getStringValue() const
{
  return theValue.toString();
}


void DateTimeItem::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}

void DateTimeItem::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}


store::SchemaTypeCode DateTimeItem::getTypeCode() const
{
  switch (theValue.getFacet())
  {
  case DateTime::GYEARMONTH_FACET:
    return store::XS_GYEAR_MONTH;

  case DateTime::GYEAR_FACET:
    return store::XS_GYEAR;

  case DateTime::GMONTH_FACET:
    return store::XS_GMONTH;

  case DateTime::GMONTHDAY_FACET:
    return store::XS_GMONTH_DAY;

  case DateTime::GDAY_FACET:
    return store::XS_GDAY;

  case DateTime::DATE_FACET:
    return store::XS_DATE;

  case DateTime::TIME_FACET:
    return store::XS_TIME;

  case DateTime::DATETIME_FACET:
    return store::XS_DATETIME;

  default:
    ZORBA_ASSERT(false);
  }
}


store::Item* DateTimeItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[getTypeCode()];
}


bool DateTimeItem::equals(
    const store::Item* aItem,
    long timezone,
    const XQPCollator* coll) const
{
  try
  {
    return 0 == theValue.compare(&aItem->getDateTimeValue(), timezone);
  }
  catch (InvalidTimezoneException const&)
  {
    throw XQUERY_EXCEPTION(err::FODT0003);
  }
}


long DateTimeItem::compare(
    const Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  try
  {
    return theValue.compare(&other->getDateTimeValue(), timezone);
  }
  catch (InvalidTimezoneException const&)
  {
    throw XQUERY_EXCEPTION(err::FODT0003);
  }
}


uint32_t DateTimeItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash(0);
}


bool DateTimeItem::getEBV() const
{
  switch (theValue.getFacet())
  {
    case DateTime::DATE_FACET:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "xs:Date"));

    case DateTime::TIME_FACET:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "xs:Time"));

    case DateTime::GYEARMONTH_FACET:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "xs:GYearMonth"));

    case DateTime::GYEAR_FACET:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "xs:GYear"));

    case DateTime::GMONTH_FACET:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "xs:GMonth"));

    case DateTime::GMONTHDAY_FACET:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "xs:GMonthDay"));

    case DateTime::GDAY_FACET:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "xs:GDay"));

    default:
      throw XQUERY_EXCEPTION(err::FORG0006,
      ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "dateTime"));
  }
  return false;
}


zstring DateTimeItem::show() const
{
  return theValue.toString();
}


/*******************************************************************************
  class DurationItem
********************************************************************************/
const xs_duration& DurationItem::getDurationValue() const
{
  return theValue;
}


const xs_dayTimeDuration& DurationItem::getDayTimeDurationValue() const
{
  return theValue;
}


const xs_yearMonthDuration& DurationItem::getYearMonthDurationValue() const
{
  return theValue;
}


zstring DurationItem::getStringValue() const
{
  return theValue.toString();
}


void DurationItem::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}


void DurationItem::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}


store::SchemaTypeCode DurationItem::getTypeCode() const
{
  switch (theValue.getFacet())
  {
  case Duration::DURATION_FACET:
    return store::XS_DURATION;

  case Duration::DAYTIMEDURATION_FACET:
    return store::XS_DT_DURATION;

  case Duration::YEARMONTHDURATION_FACET:
  default:
    return store::XS_YM_DURATION;
  }
}


store::Item* DurationItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[getTypeCode()];
}


bool DurationItem::getEBV() const
{
  RAISE_ERROR_NO_LOC(err::FORG0006,
  ERROR_PARAMS(ZED(OperationNotDef_23), ZED(EffectiveBooleanValue), "duration"));
}


zstring DurationItem::show() const
{
  return theValue.toString();
}



/*******************************************************************************
  class DoubleItem
********************************************************************************/
store::Item* DoubleItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_DOUBLE];
}


bool DoubleItem::getEBV() const
{
  if (theValue.isNaN())
  {
    return false;
  }
  else
  {
    return !theValue.isZero();
  }
}


zstring DoubleItem::getStringValue() const
{
  return theValue.toString();
}


void DoubleItem::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}


void DoubleItem::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}


zstring DoubleItem::show() const
{
  zstring res("xs:double(");
  appendStringValue(res);
  res += ")";
  return res;
}


bool DoubleItem::isNaN() const
{
  return theValue.isNaN();
}


bool DoubleItem::isPosOrNegInf() const
{
  return theValue.isPosInf() || theValue.isNegInf();
}


uint32_t
DoubleItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}


/*******************************************************************************
  class FloatItem
********************************************************************************/
store::Item* FloatItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_FLOAT];
}


bool FloatItem::getEBV() const
{
  if (theValue.isNaN()) 
  {
    return false;
  }
  else
  {
    return !theValue.isZero();
  }
}


zstring FloatItem::getStringValue() const
{
  return theValue.toString();
}


void FloatItem::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}


void FloatItem::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}


zstring FloatItem::show() const
{
  zstring res("xs:float(");
  appendStringValue(res);
  res += ")";
  return res;
}


bool FloatItem::isNaN() const
{
  return theValue.isNaN();
}


bool FloatItem::isPosOrNegInf() const
{
  return theValue.isPosInf() || theValue.isNegInf();
}


uint32_t FloatItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}


/*******************************************************************************
  class DecimalItem
********************************************************************************/

store::Item* DecimalItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_DECIMAL];
}


bool DecimalItem::getEBV() const
{
  return ( theValue != xs_decimal::zero() );
}


zstring DecimalItem::getStringValue() const
{
  return theValue.toString();
}


void DecimalItem::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}


void DecimalItem::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}


bool DecimalItem::isNaN() const
{
  return theValue != theValue;
}


zstring DecimalItem::show() const
{
  zstring res("xs:decimal(");
  appendStringValue(res);
  res +=  ")";
  return res;
}


/*******************************************************************************
  class IntegerItemImpl
********************************************************************************/

long IntegerItemImpl::compare( Item const *other, long,
                               const XQPCollator* ) const {
  try
  {
    return theValue.compare( other->getIntegerValue() );
  }
  catch ( ZorbaException const& )
  {
    return getDecimalValue().compare( other->getDecimalValue() );
  }
}

bool IntegerItemImpl::equals( const store::Item* other, long,
                              const XQPCollator*) const
{
  try
  {
    return theValue == other->getIntegerValue();
  }
  catch (ZorbaException const&)
  {
    return getDecimalValue() == other->getDecimalValue();
  }
}

xs_decimal IntegerItemImpl::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_long IntegerItemImpl::getLongValue() const
{
  try
  {
    return to_xs_long(theValue);
  }
  catch ( std::range_error const& )
  {
    RAISE_ERROR_NO_LOC(err::FORG0001,
    ERROR_PARAMS(theValue, ZED(CastFromToFailed_34), "integer", "long"));
  }
}


xs_unsignedInt IntegerItemImpl::getUnsignedIntValue() const
{
  try 
  {
    return to_xs_unsignedInt(theValue);
  }
  catch ( std::range_error const& ) 
  {
    RAISE_ERROR_NO_LOC(err::FORG0001,
    ERROR_PARAMS(theValue, ZED(CastFromToFailed_34), "integer", "unsignedInt"));
  }
}


store::Item* IntegerItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_INTEGER];
}


bool IntegerItemImpl::getEBV() const
{
  return !!theValue.sign();
}


zstring IntegerItemImpl::getStringValue() const
{
  return theValue.toString();
}


void IntegerItemImpl::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}

uint32_t IntegerItemImpl::hash(long, const XQPCollator*) const
{
  return theValue.hash();
}


void IntegerItemImpl::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}


zstring IntegerItemImpl::show() const
{
  zstring res("xs:integer(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class NonPositiveIntegerItem
********************************************************************************/
long NonPositiveIntegerItem::compare( Item const *other, long,
                                      const XQPCollator* ) const {
  try
  {
    return theValue.compare( other->getIntegerValue() );
  }
  catch ( ZorbaException const& )
  {
    return getDecimalValue().compare( other->getDecimalValue() );
  }
}

bool NonPositiveIntegerItem::equals( const store::Item* other, long,
                                     const XQPCollator* ) const
{
  try
  {
    return theValue == other->getIntegerValue();
  }
  catch (ZorbaException const&)
  {
    return getDecimalValue() == other->getDecimalValue();
  }
}

store::Item* NonPositiveIntegerItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NON_POSITIVE_INTEGER];
}

xs_decimal NonPositiveIntegerItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}

xs_integer NonPositiveIntegerItem::getIntegerValue() const
{
  return xs_integer(theValue);
}

xs_long NonPositiveIntegerItem::getLongValue() const
{
  try
  {
    return to_xs_long(theValue);
  }
  catch ( std::range_error const& )
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001,
      ERROR_PARAMS( theValue, ZED( CastFromToFailed_34 ), "integer", "long" )
    );
  }
}

zstring NonPositiveIntegerItem::getStringValue() const
{
  return theValue.toString();
}


void NonPositiveIntegerItem::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}

uint32_t NonPositiveIntegerItem::hash(long, const XQPCollator*) const
{
  return theValue.hash();
}


void NonPositiveIntegerItem::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}

bool NonPositiveIntegerItem::getEBV() const
{
  return !!theValue.sign();
}

zstring NonPositiveIntegerItem::show() const
{
  zstring res("xs:nonPositiveInteger(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class NegativeIntegerItem
********************************************************************************/
store::Item* NegativeIntegerItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NEGATIVE_INTEGER];
}


zstring NegativeIntegerItem::show() const
{
  zstring res("xs:negativeInteger(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class NonNegativeIntegerItem
********************************************************************************/
long NonNegativeIntegerItem::compare( Item const *other, long,
                                      const XQPCollator* ) const {
  try
  {
    return theValue.compare( other->getUnsignedIntegerValue() );
  }
  catch ( ZorbaException const& )
  {
    return getDecimalValue().compare( other->getDecimalValue() );
  }
}

bool NonNegativeIntegerItem::equals( const store::Item* other, long,
                                     const XQPCollator* ) const
{
  try
  {
    return theValue == other->getUnsignedIntegerValue();
  }
  catch (ZorbaException const&)
  {
    return getDecimalValue() == other->getDecimalValue();
  }
}

store::Item* NonNegativeIntegerItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_NON_NEGATIVE_INTEGER];
}


xs_decimal NonNegativeIntegerItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}

xs_integer NonNegativeIntegerItem::getIntegerValue() const
{
  return xs_integer(theValue);
}

xs_long NonNegativeIntegerItem::getLongValue() const
{
  try
  {
    return to_xs_long(theValue);
  }
  catch ( std::range_error const& )
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001,
      ERROR_PARAMS( theValue, ZED( CastFromToFailed_34 ), "integer", "long" )
    );
  }
}

zstring NonNegativeIntegerItem::getStringValue() const
{
  return theValue.toString();
}


void NonNegativeIntegerItem::getStringValue2(zstring& val) const
{
  val = theValue.toString();
}

uint32_t NonNegativeIntegerItem::hash(long, const XQPCollator*) const
{
  return theValue.hash();
}


void NonNegativeIntegerItem::appendStringValue(zstring& buf) const
{
  buf += theValue.toString();
}

bool NonNegativeIntegerItem::getEBV() const
{
  return !!theValue.sign();
}

zstring NonNegativeIntegerItem::show() const
{
  zstring res("xs:nonNegativeInteger(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class PositiveIntegerItem
********************************************************************************/
store::Item* PositiveIntegerItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_POSITIVE_INTEGER];
}


zstring PositiveIntegerItem::show() const
{
  zstring res("xs:positiveInteger(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class LongItem
********************************************************************************/
xs_decimal LongItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_integer LongItem::getIntegerValue() const
{
  return xs_integer(theValue);
}

xs_nonNegativeInteger LongItem::getUnsignedIntegerValue() const {
  return xs_nonNegativeInteger( theValue >= 0 ? theValue : -theValue );
}

store::Item* LongItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_LONG];
}


bool LongItem::getEBV() const
{
  return (theValue != 0);
}


zstring LongItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void LongItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue,&val);
}


void LongItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring LongItem::show() const
{
  zstring res("xs:long(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class IntItem
********************************************************************************/
xs_decimal IntItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_integer IntItem::getIntegerValue() const
{
  return Integer( theValue );
}


store::Item* IntItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_INT];
}


bool IntItem::getEBV() const
{
  return ( theValue != (int32_t)0 );
}


zstring IntItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void IntItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue, &val);
}


void IntItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring IntItem::show() const
{
  zstring res("xs:int(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class ShortItem
********************************************************************************/
xs_decimal ShortItem::getDecimalValue() const
{
  return xs_decimal( theValue );
}


xs_integer ShortItem::getIntegerValue() const
{
  return Integer(theValue);
}


store::Item* ShortItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_SHORT];
}


bool ShortItem::getEBV() const
{
  return (theValue != 0);
}


zstring ShortItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void ShortItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue, &val);
}


void ShortItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring ShortItem::show() const
{
  zstring res("xs:short(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class ByteItem
********************************************************************************/
xs_decimal ByteItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_integer ByteItem::getIntegerValue() const
{
  return Integer(theValue);
}


store::Item* ByteItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_BYTE];
}


bool ByteItem::getEBV() const
{
  return (theValue != 0);
}


zstring ByteItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void ByteItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue, &val);
}


void ByteItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring ByteItem::show() const
{
  zstring res("xs:byte(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class UnsignedLongItem
********************************************************************************/
xs_decimal UnsignedLongItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_integer UnsignedLongItem::getIntegerValue() const
{
  return xs_integer(theValue);
}


xs_nonNegativeInteger UnsignedLongItem::getUnsignedIntegerValue() const
{
  return xs_nonNegativeInteger(theValue);
}


store::Item* UnsignedLongItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_UNSIGNED_LONG];
}


bool UnsignedLongItem::getEBV() const
{
  return (theValue != 0);
}


zstring UnsignedLongItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void UnsignedLongItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue, &val);
}


void UnsignedLongItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring UnsignedLongItem::show() const
{
  zstring res("xs:unsignedLong(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class UnsignedIntItem
********************************************************************************/
xs_decimal UnsignedIntItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_integer UnsignedIntItem::getIntegerValue() const
{
  return Integer(theValue);
}


xs_nonNegativeInteger UnsignedIntItem::getUnsignedIntegerValue() const
{
  return xs_nonNegativeInteger(theValue);
}


store::Item* UnsignedIntItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_UNSIGNED_INT];
}


bool UnsignedIntItem::getEBV() const
{
  return (theValue != 0);
}


zstring UnsignedIntItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void UnsignedIntItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue, &val);
}


void UnsignedIntItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring UnsignedIntItem::show() const
{
  zstring res("xs:unsignedInt(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class UnsignedShortItem
********************************************************************************/
xs_decimal UnsignedShortItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_integer UnsignedShortItem::getIntegerValue() const
{
  return Integer(theValue);
}


xs_nonNegativeInteger UnsignedShortItem::getUnsignedIntegerValue() const
{
  return xs_nonNegativeInteger(theValue);
}


store::Item* UnsignedShortItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_UNSIGNED_SHORT];
}


bool UnsignedShortItem::getEBV() const
{
  return (theValue != 0);
}


zstring UnsignedShortItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void UnsignedShortItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue, &val);
}


void UnsignedShortItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring UnsignedShortItem::show() const
{
  zstring res("xs:unsignedShort(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class UnsignedByteItem
********************************************************************************/
xs_decimal UnsignedByteItem::getDecimalValue() const
{
  return xs_decimal(theValue);
}


xs_integer UnsignedByteItem::getIntegerValue() const
{
  return xs_integer((uint32_t)theValue);
}


xs_nonNegativeInteger UnsignedByteItem::getUnsignedIntegerValue() const
{
  return xs_nonNegativeInteger(theValue);
}


store::Item* UnsignedByteItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_UNSIGNED_BYTE];
}


bool UnsignedByteItem::getEBV() const
{
  return (theValue != 0);
}


zstring UnsignedByteItem::getStringValue() const
{
  zstring result;
  ztd::to_string(theValue, &result);
  return result;
}


void UnsignedByteItem::getStringValue2(zstring& val) const
{
  ztd::to_string(theValue, &val);
}


void UnsignedByteItem::appendStringValue(zstring& buf) const
{
  zstring temp;
  ztd::to_string(theValue, &temp);
  buf += temp;
}


zstring UnsignedByteItem::show() const
{
  zstring res("xs:unsignedByte(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class BooleanItem
********************************************************************************/
store::Item* BooleanItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_BOOLEAN];
}


uint32_t BooleanItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue ? 0 : 1;
}


bool BooleanItem::getEBV() const
{
  return theValue;
}


zstring BooleanItem::getStringValue() const
{
  if (theValue)
    return "true";
  else
    return "false";
}


void BooleanItem::getStringValue2(zstring& val) const
{
  if (theValue)
    val = "true";
  else
    val = "false";
}


void BooleanItem::appendStringValue(zstring& buf) const
{
  if (theValue)
    buf += "true";
  else
    buf += "false";
}


zstring BooleanItem::show() const
{
  zstring res("xs:boolean(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class Base64BinaryItem
********************************************************************************/
bool
Base64BinaryItem::equals(
      const store::Item* other,
      long timezone,
      const XQPCollator* aCollation) const
{
  if (isEncoded() == other->isEncoded())
  {
    size_t this_size, other_size;
    const char* this_data = getBase64BinaryValue(this_size);
    const char* other_data = other->getBase64BinaryValue(other_size);
    return this_size == other_size &&
      memcmp(this_data, other_data, this_size) == 0;
  }
  else
  {
    return getStringValue().compare(other->getStringValue()) == 0;
  }
}


uint32_t
Base64BinaryItem::hash(long timezone, const XQPCollator* aCollation) const
{
  // always need to hash on the string-value because otherwise
  // a base64 item that is encoded would have a different hash-value
  // as a base64 item that is decoded but represents the same binary content
  return utf8::hash(getStringValue(), aCollation);
}


const char*
Base64BinaryItem::getBase64BinaryValue(size_t& size) const
{
  size = theValue.size();
  return &theValue[0];
}


store::Item* Base64BinaryItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_BASE64BINARY];
}


zstring Base64BinaryItem::getStringValue() const
{
  zstring lRes;
  getStringValue2(lRes);
  return lRes;
}


void Base64BinaryItem::getStringValue2(zstring& val) const
{
  val.clear();
  appendStringValue(val);
}


void Base64BinaryItem::appendStringValue(zstring& buf) const
{
  if (theIsEncoded)
  {
    buf.insert(buf.size(), &theValue[0], theValue.size());
  }
  else
  {
    std::vector<char> encoded;
    encoded.reserve(theValue.size());
    Base64::encode(theValue, encoded);
    buf.insert(buf.size(), &encoded[0], encoded.size());
  }
}


zstring Base64BinaryItem::show() const
{
  zstring res("xs:base64Binary(");
  appendStringValue(res);
  res += ")";
  return res;
}


/*******************************************************************************
  class StreamableStringItem
********************************************************************************/
zstring StreamableBase64BinaryItem::getStringValue() const
{
  if (!theIsMaterialized)
  {
    materialize();
  }
  return Base64BinaryItem::getStringValue();
}


void StreamableBase64BinaryItem::getStringValue2(zstring& val) const
{
  if (!theIsMaterialized)
  {
    materialize();
  }
  Base64BinaryItem::getStringValue2(val);
}


void StreamableBase64BinaryItem::appendStringValue(zstring& buf) const
{
  if (!theIsMaterialized)
  {
    materialize();
  }
  Base64BinaryItem::appendStringValue(buf);
}


zstring StreamableBase64BinaryItem::show() const
{
  if (!theIsMaterialized)
  {
    materialize();
  }
  zstring res("xs:base64Binary(");
  appendStringValue(res);
  res += ")";
  return res;
}


uint32_t
StreamableBase64BinaryItem::hash(long timezone, const XQPCollator* aCollation) const
{
  if (!theIsMaterialized)
  {
    materialize();
  }
  return Base64BinaryItem::hash(timezone, aCollation);
}


const char*
StreamableBase64BinaryItem::getBase64BinaryValue(size_t& s) const
{
  if (!theIsMaterialized)
  {
    materialize();
  }
  return Base64BinaryItem::getBase64BinaryValue(s);
}


bool StreamableBase64BinaryItem::isStreamable() const
{
  return true;
}


bool StreamableBase64BinaryItem::isSeekable() const
{
  return theIsSeekable;
}


StreamReleaser StreamableBase64BinaryItem::getStreamReleaser()
{
  return theStreamReleaser;
}


void StreamableBase64BinaryItem::setStreamReleaser(StreamReleaser aReleaser)
{
  theStreamReleaser = aReleaser;
}


std::istream& StreamableBase64BinaryItem::getStream()
{
  // a non-seekable stream can only be consumed once
  // we raise an error if getStream is called twice
  // if a query requires a stream to be consumed more than once,
  // the query needs to make sure that the stream is explicitly
  // materialized before
  if (!theIsSeekable && theIsConsumed) 
  {
    throw ZORBA_EXCEPTION( zerr::ZSTR0055_STREAMABLE_STRING_CONSUMED );
  }
  else
  {
    // if the stream is seekable, we seek to the beginning.
    // We are not using theIstream.seekg because the USER_ERROR that is thrown
    // by Zorba is lost possibly in an internal try/catch of the seekg
    std::streambuf * pbuf;
    pbuf = theIstream.rdbuf();
    pbuf->pubseekoff(0, std::ios::beg);
  }
  theIsConsumed = true;
  return theIstream;
}


void StreamableBase64BinaryItem::materialize() const
{
  StreamableBase64BinaryItem* const s
    = const_cast<StreamableBase64BinaryItem*>(this);
  std::istream& lStream = s->getStream();

  s->theIsMaterialized = true;
  s->theIsConsumed = true;

  if (isSeekable())
  {
    lStream.seekg(0, std::ios::end);
    size_t len = lStream.tellg();
    lStream.seekg(0, std::ios::beg);
    s->theValue.reserve(len);
    char buf[1024];
    while (lStream.good())
    {
      lStream.read(buf, 1024);
      s->theValue.insert(s->theValue.end(), buf, buf+lStream.gcount());
    }
  }
  else
  {
    char buf[4048];
    while (lStream.good())
    {
      lStream.read(buf, 4048);
      s->theValue.reserve(s->theValue.size() + lStream.gcount());
      s->theValue.insert(s->theValue.end(), buf, buf+lStream.gcount());
    }
  }
}


/*******************************************************************************
  class HexBinaryItem
********************************************************************************/
store::Item* HexBinaryItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[store::XS_HEXBINARY];
}


zstring HexBinaryItem::getStringValue() const
{
  return theValue.str();
}


void HexBinaryItem::getStringValue2(zstring& val) const
{
  val = theValue.str();
}


void HexBinaryItem::appendStringValue(zstring& buf) const
{
  buf += theValue.str();
}


zstring HexBinaryItem::show() const
{
  zstring res("xs:hexBinary(");
  appendStringValue(res);
  res += ")";
  return res;
}


uint32_t HexBinaryItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}


/*******************************************************************************
  class ErrorItem
********************************************************************************/
ErrorItem::~ErrorItem()
{
  if (theError)
  {
    delete theError;
    theError = NULL;
  }
}


zstring ErrorItem::show() const
{
  return theError->what();
}


#ifndef ZORBA_NO_FULL_TEXT

/*******************************************************************************
  class AtomicItemTokenizerCallback
********************************************************************************/

AtomicItemTokenizerCallback::AtomicItemTokenizerCallback( 
  Tokenizer &tokenizer,
  locale::iso639_1::type lang,
  container_type &tokens
) :
  tokenizer_( tokenizer ),
  lang_( lang ),
  tokens_( tokens )
{
}

void AtomicItemTokenizerCallback::operator()(
  char const *utf8_s,
  size_type utf8_len,
  size_type token_no, 
  size_type sent_no,
  size_type para_no,
  void*
) {
  FTToken const t( utf8_s, utf8_len, token_no, lang_ );
  tokens_.push_back( t );
}

#endif /* ZORBA_NO_FULL_TEXT */


} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
