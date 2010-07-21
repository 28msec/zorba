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

#include <memory>

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "zorbatypes/collation_manager.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/URI.h"

#include "zorbautils/hashfun.h"
#include "zorbautils/icu_tokenizer.h"

#include "store/api/item.h"
#include "store/naive/node_items.h"

#include "store/naive/atomic_items.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_item_factory.h"
#include "store/naive/store_defs.h"
#include "store/naive/item_iterator.h"


#define CREATE_XS_TYPE(aType) \
  GET_STORE().getItemFactory()->createQName(SimpleStore::XS_URI, "xs", aType);

#define CREATE_BOOLITEM(item, aValue) \
  GET_STORE().getItemFactory()->createBoolean(item, aValue)

using namespace std;

namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
store::Item_t AtomicItem::getAtomizationValue() const
{
  store::Item* lItem = const_cast<AtomicItem *>(this);
  return lItem;
}


/*******************************************************************************

********************************************************************************/
void AtomicItem::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  store::Item* lItem = const_cast<AtomicItem *>(this);
  val = lItem;
}


/*******************************************************************************
  For numeric items or the untyped item: convert this item to a long item, 
  if possible.
********************************************************************************/
void AtomicItem::castToLong(store::Item_t& result) const
{
  xqp_long longValue;

  result = NULL;

  switch (getTypeCode())
  {
  case XS_UNTYPED_ATOMIC:
  {
    const UntypedAtomicItem* item = static_cast<const UntypedAtomicItem*>(this);
    if (NumConversions::strToLong(item->theValue->c_str(), longValue))
      GET_FACTORY().createLong(result, longValue);

    break;
  }

  case XS_DECIMAL:
  {
    const DecimalItem* item = static_cast<const DecimalItem*>(this);
    if (NumConversions::decimalToLong(item->theValue, longValue))
      GET_FACTORY().createLong(result, longValue);

    break;
  }

  case XS_INTEGER:
  case XS_NON_POSITIVE_INTEGER:
  case XS_NEGATIVE_INTEGER:
  case XS_NON_NEGATIVE_INTEGER:
  case XS_POSITIVE_INTEGER:
  {
    const IntegerItem* item = static_cast<const IntegerItem*>(this);
    if (NumConversions::integerToLong(item->theValue, longValue))
      GET_FACTORY().createLong(result, longValue);

    break;
  }

  case XS_UNSIGNED_LONG:
  {
    const UnsignedLongItem* item = static_cast<const UnsignedLongItem*>(this);
    if ((item->theValue >> 63) == 0)
    {
      longValue = static_cast<xqp_long>(item->theValue);
      GET_FACTORY().createLong(result, longValue);
    }
    break;
  }

  default:
  {
    ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                          __FUNCTION__, typeid (*this).name ());
  }
  }
}


/*******************************************************************************
  For numeric items: convert this item to a double item. If the conversion is
  a lossy one, set "lossy" to true, otherwise set "lossy" to false. If "force"
  is true, the conversion is done always; otherwise, the conversion is done only
  if it is lossy.
********************************************************************************/
void AtomicItem::coerceToDouble(store::Item_t& result, bool force, bool& lossy) const
{
  xqp_double doubleValue;

  result = NULL;

  switch (getTypeCode())
  {
  case XS_DECIMAL:
  {
    const DecimalItem* item = static_cast<const DecimalItem*>(this);

    doubleValue = xqp_double::parseDecimal(item->theValue);

    xqp_decimal decValue;
    Decimal::parseDouble(doubleValue, decValue);

    lossy = (decValue != item->theValue);
    break;
  }

  case XS_INTEGER:
  case XS_NON_POSITIVE_INTEGER:
  case XS_NEGATIVE_INTEGER:
  case XS_NON_NEGATIVE_INTEGER:
  case XS_POSITIVE_INTEGER:
  {
    const IntegerItem* item = static_cast<const IntegerItem*>(this);

    doubleValue = xqp_double::parseInteger(item->theValue);

    xqp_integer intValue;
    Integer::parseDouble(doubleValue, intValue);

    lossy = (intValue != item->theValue);
    break;
  }

  case XS_UNSIGNED_LONG:
  {
    const UnsignedLongItem* item = static_cast<const UnsignedLongItem*>(this);

    doubleValue = xqp_double::parseULong(item->theValue);

    xqp_ulong ulongValue = static_cast<xqp_ulong>(doubleValue.getNumber());

    lossy = (ulongValue != item->theValue);
    break;
  }
  case XS_UNSIGNED_INT:
  {
    const UnsignedIntItem* item = static_cast<const UnsignedIntItem*>(this);

    doubleValue = xqp_double::parseUInt(item->theValue);
    lossy = false;
    break;
  }
  case XS_UNSIGNED_SHORT:
  {
    const UnsignedShortItem* item = static_cast<const UnsignedShortItem*>(this);

    doubleValue = xqp_double::parseUInt(item->theValue);

    lossy = false;
    break;
  }
  case XS_UNSIGNED_BYTE:
  {
    const UnsignedByteItem* item = static_cast<const UnsignedByteItem*>(this);

    doubleValue = xqp_double::parseUInt(item->theValue);

    lossy = false;
    break;
  }

  case XS_LONG:
  {
    const LongItem* item = static_cast<const LongItem*>(this);

    doubleValue = xqp_double::parseLong(item->theValue);

    xqp_long longValue = static_cast<xqp_long>(doubleValue.getNumber());

    lossy = (longValue != item->theValue);
    break;
  }
  case XS_INT:
  {
    const IntItem* item = static_cast<const IntItem*>(this);

    doubleValue = xqp_double::parseLong(item->theValue);
    lossy = false;
    break;
  }
  case XS_SHORT:
  {
    const ShortItem* item = static_cast<const ShortItem*>(this);

    doubleValue = xqp_double::parseInt(item->theValue);
    lossy = false;
    break;
  }
  case XS_BYTE:
  {
    const ByteItem* item = static_cast<const ByteItem*>(this);

    doubleValue = xqp_double::parseInt(item->theValue);
    lossy = false;
    break;
  }

  default:
  {
    ZORBA_ERROR_PARAM_OSS(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE,
                          __FUNCTION__, typeid (*this).name ());
  }
  }

  if (force || lossy)
    GET_FACTORY().createDouble(result, doubleValue);
}


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
void UntypedAtomicItem::castToUri(store::Item_t& result) const
{
  try
  {
    URI uriVal(theValue);
    GET_FACTORY().createAnyURI(result, uriVal.toString()->c_str());
  }
  catch (error::ZorbaError& e)
  {
    result = NULL;
  }
}


void UntypedAtomicItem::castToString(store::Item_t& result) const
{
  xqpStringStore_t tmp(theValue);
  GET_FACTORY().createString(result, tmp);
}


void UntypedAtomicItem::castToDateTime(store::Item_t& result) const
{
  GET_FACTORY().createDateTime(result, theValue);
}


void UntypedAtomicItem::castToDate(store::Item_t& result) const
{
  GET_FACTORY().createDate(result, theValue);
}


void UntypedAtomicItem::castToTime(store::Item_t& result) const
{
  GET_FACTORY().createTime(result, theValue);
}


void UntypedAtomicItem::castToGYear(store::Item_t& result) const
{
  GET_FACTORY().createGYear(result, theValue);
}


void UntypedAtomicItem::castToGYearMonth(store::Item_t& result) const
{
  GET_FACTORY().createGYearMonth(result, theValue);
}


void UntypedAtomicItem::castToGMonthDay(store::Item_t& result) const
{
  GET_FACTORY().createGMonthDay(result, theValue);
}


void UntypedAtomicItem::castToGMonth(store::Item_t& result) const
{
  GET_FACTORY().createGMonth(result, theValue);
}


void UntypedAtomicItem::castToGDay(store::Item_t& result) const
{
  GET_FACTORY().createGDay(result, theValue);
}


void UntypedAtomicItem::castToDuration(store::Item_t& result) const
{
  GET_FACTORY().createDuration(result, theValue);
}


void UntypedAtomicItem::castToDouble(store::Item_t& result) const
{
  xqp_double doubleValue;
  if (NumConversions::strToDouble(theValue->c_str(), doubleValue))
  {
    GET_FACTORY().createDouble(result, doubleValue);
  }
  else
  {
    result = NULL;
  }
}


void UntypedAtomicItem::castToDecimal(store::Item_t& result) const
{
  xqp_decimal decValue;
  if (NumConversions::strToDecimal(theValue->c_str(), decValue))
  {
    GET_FACTORY().createDecimal(result, decValue);
  }
  else
  {
    result = NULL;
  }
}


void UntypedAtomicItem::castToInteger(store::Item_t& result) const
{
  xqp_integer intValue;
  if (NumConversions::strToInteger(theValue->c_str(), intValue))
  {
    GET_FACTORY().createInteger(result, intValue);
  }
  else
  {
    result = NULL;
  }
}


void UntypedAtomicItem::castToHexBinary(store::Item_t& result) const
{
  Base16 value;
  if (Base16::parseString(theValue, value))
  {
    GET_FACTORY().createHexBinary(result, value);
  }
  else
  {
    result = NULL;
  }
}


void UntypedAtomicItem::castToBase64Binary(store::Item_t& result) const
{
  Base64 value;
  if (Base64::parseString(theValue, value))
  {
    GET_FACTORY().createBase64Binary(result, value);
  }
  else
  {
    result = NULL;
  }
}


void UntypedAtomicItem::castToBoolean(store::Item_t& result) const
{
  xqpStringStore_t str = theValue->trim(" \t\r\n", 4);
  bool value = true;

  if (str->byteEqual("false", 5) || str->byteEqual("0", 1))
  {
    value = false;
  }
  else if (!str->byteEqual("true", 4) && !str->byteEqual("1", 1))
  {
    result = NULL;
    return;
  }

  GET_FACTORY().createBoolean(result, value);
}


store::Item* UntypedAtomicItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


uint32_t UntypedAtomicItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue->hash();
}


store::Item_t UntypedAtomicItem::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqp_string UntypedAtomicItem::show() const
{
  return "xs:untypedAtomic(" + theValue->str() + ")";
}


/*******************************************************************************
  class QNameItemImpl
********************************************************************************/

xqpStringStore_t QNameItem::theEmptyPrefix(new xqpStringStore(""));


QNameItem::~QNameItem() 
{
  if (isValid())
  {
    if (isNormalized())
    {
      unsetLocal();
    }
    else
    {
      unsetNormalized();
    }
  }
}


void QNameItem::free()
{
  GET_STORE().getQNamePool().remove(this);
}


void QNameItem::setLocal(xqpStringStore* local)  
{
  assert(theUnion.theLocal == NULL);

  theUnion.theLocal = local;
  local->addReference(NULL SYNC_PARAM2(local->getRCLock()));
}


void QNameItem::unsetLocal()  
{
  assert(theUnion.theLocal != NULL && isNormalized());

  theUnion.theLocal->removeReference(NULL SYNC_PARAM2(theUnion.theLocal->getRCLock()));
  theUnion.theLocal = NULL;
}


void QNameItem::setNormalized(QNameItem* qn)  
{
  assert(theUnion.theNormQN == NULL);

  theUnion.theNormQN = qn;
  qn->addReference(NULL SYNC_PARAM2(qn->getRCLock()));
}


void QNameItem::unsetNormalized()  
{
  assert(theUnion.theNormQN != NULL && !isNormalized());

  theUnion.theNormQN->removeReference(NULL SYNC_PARAM2(theUnion.theNormQN->getRCLock()));
  theUnion.theNormQN = NULL;
}


uint32_t QNameItem::hash(long timezone, const XQPCollator* aCollation) const
{
  const void* tmp = getNormalized();
  return hashfun::h32(tmp, FNV_32_INIT);
}


store::Item* QNameItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_QNAME];
}


store::Item_t QNameItem::getEBV( ) const
{
  ZORBA_ERROR_DESC(FORG0006, "Effective Boolean Value is not defined for QName!");
  return NULL;
}


xqpStringStore_t QNameItem::getStringValue( ) const
{
  if (thePrefix->empty()) 
  {
    return getLocalName();
  }
  else 
  {
    return new xqpStringStore(thePrefix->str() + ":" + getLocalName()->str());
  }
}


void QNameItem::getStringValue(xqpStringStore_t& strval) const
{
  if (thePrefix->empty()) 
  {
    strval = getLocalName();
  }
  else 
  {
    strval = new xqpStringStore(thePrefix->str() + ":" + getLocalName()->str());
  }
}


void QNameItem::getStringValue(std::string& buf) const
{
  if (thePrefix->empty()) 
  {
    buf += getLocalName()->str();
  }
  else 
  {
    buf += thePrefix->str();
    buf += ":";
    buf += getLocalName()->str();
  }
}


bool QNameItem::isIdQName() const
{
  if (getLocalName()->byteEqual("id", 2))
  {
    if (getPrefix()->byteEqual("xml", 3) ||
        theNamespace->byteEqual(SimpleStore::XML_URI, SimpleStore::XML_URI_LEN))
      return true;
  }

  return false;
}


bool QNameItem::isBaseUri() const
{
  if (getLocalName()->byteEqual("base", 4))
  {
    if (getPrefix()->byteEqual("xml", 3) ||
        getNamespace()->byteEqual(SimpleStore::XML_URI, SimpleStore::XML_URI_LEN))
      return true;
  }

  return false;
}


xqp_string QNameItem::show() const
{
  return "xs:QName(" + getNamespace()->str() + "," + getPrefix()->str() + "," +
                       getLocalName()->str() + ")";
}


/*******************************************************************************
  class AnyUriItem
********************************************************************************/
store::Item* AnyUriItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_ANY_URI];
}

uint32_t AnyUriItemImpl::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue->hash();
}


store::Item_t AnyUriItemImpl::getEBV() const
{
  bool b = ! (theValue->str() == "");
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqp_string AnyUriItemImpl::show() const
{
  return "xs:anyURI(" + theValue->str() + ")";
}


/*******************************************************************************
  class StringItem
********************************************************************************/
store::Item* StringItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_STRING];
}


uint32_t StringItem::hash(long timezone, const XQPCollator* aCollation) const
{
  if (aCollation == NULL || aCollation->doMemCmp())
    return xqpStringStore::hash(theValue->c_str());

  return theValue->hash(aCollation);
}


bool StringItem::equals(
    const store::Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  if (aCollation == NULL || aCollation->doMemCmp())
    return theValue->byteEqual(other->getString());

  return (theValue->compare(other->getString(), aCollation) == 0);
}
  

long StringItem::compare(
    const Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  if (aCollation == NULL || aCollation->doMemCmp())
    return theValue->byteCompare(other->getString());

  return theValue->compare(other->getString(), aCollation);
}


store::Item_t StringItem::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqp_string StringItem::show() const
{
  return "xs:string(" + theValue->str() + ")";
}

#ifndef ZORBA_NO_FULL_TEXT

void AtomicItemTokenizer::operator()( char const *utf8_s, int utf8_len,
                                      int token_no, int sent_no, int para_no,
                                      void* ) 
{
  FTToken t( utf8_s, utf8_len, token_no, sent_no, lang_ );
  tokens_.push_back( t );
}


FTTokenIterator_t
StringItem::getDocumentTokens( locale::iso639_1::type lang) const 
{
  auto_ptr<Tokenizer> tokenizer( Tokenizer::create() );
  NaiveFTTokenIterator::FTTokens *tokens = new NaiveFTTokenIterator::FTTokens;
  AtomicItemTokenizer atomic_tokenizer( *tokenizer, lang, *tokens );
  xqpStringStore const *const xText = getStringValue();
  atomic_tokenizer.tokenize( xText->c_str(), xText->size() );
  return FTTokenIterator_t( new NaiveFTTokenIterator( tokens ) );
}


FTTokenIterator_t
StringItem::getQueryTokens( locale::iso639_1::type lang,
                                 bool wildcards ) const 
{
  auto_ptr<Tokenizer> tokenizer( Tokenizer::create( wildcards ) );
  NaiveFTTokenIterator::FTTokens *tokens = new NaiveFTTokenIterator::FTTokens;
  AtomicItemTokenizer atomic_tokenizer( *tokenizer, lang, *tokens );
  xqpStringStore const *const xText = getStringValue();
  atomic_tokenizer.tokenize( xText->c_str(), xText->size() );
  return FTTokenIterator_t( new NaiveFTTokenIterator( tokens ) );
}

#endif /* ZORBA_NO_FULL_TEXT */

/*******************************************************************************
  class NormalizedStringItemImpl
********************************************************************************/
store::Item* NormalizedStringItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_NORMALIZED_STRING];
}

xqp_string NormalizedStringItemImpl::show() const
{
  return "xs:NormalizedString(" + theValue->str() + ")";
}


/*******************************************************************************
  class TokenItemImpl
********************************************************************************/
store::Item* TokenItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_TOKEN];
}


uint32_t TokenItemImpl::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue->hash();
}

xqp_string TokenItemImpl::show() const
{
  return "xs:TOKEN(" + theValue->str() + ")";
}


/*******************************************************************************
  class LanguageItemImpl
********************************************************************************/
store::Item* LanguageItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_LANGUAGE];
}


xqp_string LanguageItemImpl::show() const
{
  return "xs:LANGUAGE(" + theValue->str() + ")";
}

/*******************************************************************************
  class NMTOKENItemImpl
********************************************************************************/
store::Item* NMTOKENItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_NMTOKEN];
}


xqp_string NMTOKENItemImpl::show() const
{
  return "xs:NMTOKEN(" + theValue->str() + ")";
}

/*******************************************************************************
  class NameItemImpl
********************************************************************************/
store::Item* NameItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_NAME];
}


xqp_string NameItemImpl::show() const
{
  return "xs:NAME(" + theValue->str() + ")";
}


/*******************************************************************************
  class NCNameItemImpl
********************************************************************************/
store::Item* NCNameItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_NCNAME];
}


xqp_string NCNameItemImpl::show() const
{
  return "xs:NCName(" + theValue->str() + ")";
}


/*******************************************************************************
  class IDItemImpl
********************************************************************************/
store::Item* IDItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_ID];
}

xqp_string IDItemImpl::show() const
{
  return "xs:ID(" + theValue->str() + ")";
}


/*******************************************************************************
  class IDREFItemImpl
********************************************************************************/
store::Item* IDREFItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_IDREF];
}

xqp_string IDREFItemImpl::show() const
{
  return "xs:IDREF(" + theValue->str() + ")";
}


/*******************************************************************************
  class ENTITYItemImpl
********************************************************************************/
store::Item* ENTITYItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_ENTITY];
}

xqp_string ENTITYItemImpl::show() const
{
  return "xs:ENTITY(" + theValue->str() + ")";
}


/*******************************************************************************
  class DateTimeItem
********************************************************************************/
xqpStringStore_t DateTimeItem::getStringValue() const
{
  return theValue.toString().getStore();
}


void DateTimeItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.toString().getStore();
}

void DateTimeItem::getStringValue(std::string& buf) const
{
  buf += theValue.toString().c_str();
}


SchemaTypeCode DateTimeItem::getTypeCode() const 
{
  switch (theValue.getFacet())
  {
  case DateTime::GYEARMONTH_FACET:
    return XS_GYEAR_MONTH;
    
  case DateTime::GYEAR_FACET:
    return XS_GYEAR;
    
  case DateTime::GMONTH_FACET:
    return XS_GMONTH;

  case DateTime::GMONTHDAY_FACET:
    return XS_GMONTH_DAY;
    
  case DateTime::GDAY_FACET:
    return XS_GDAY;

  case DateTime::DATE_FACET:
    return XS_DATE;
      
  case DateTime::TIME_FACET:
    return XS_TIME;

  case DateTime::DATETIME_FACET:
    return XS_DATETIME;

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
  catch (InvalidTimezoneException)
  {
    ZORBA_ERROR(FODT0003);
    return false;
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
  catch (InvalidTimezoneException)
  {
    ZORBA_ERROR(FODT0003);
    return false;
  }
}


uint32_t DateTimeItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash(0);
}


store::Item_t DateTimeItem::getEBV() const
{
  switch (theValue.getFacet())
  {
    case DateTime::DATE_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for xs:Date!");
      break;
      
    case DateTime::TIME_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for xs:Time!");
      break;
    
    case DateTime::GYEARMONTH_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for xs:GYearMonth!");
      break;
    
    case DateTime::GYEAR_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for xs:GYear!");
      break;
    
    case DateTime::GMONTH_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for xs:GMonth!");
      break;

    case DateTime::GMONTHDAY_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for xs:GMonthDay!");
      break;
    
    case DateTime::GDAY_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for xs:GDay!");
      break;

    default:
    case DateTime::DATETIME_FACET:
      ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for DateTime!");
      break;
  }
  return NULL;
}


xqp_string DateTimeItem::show() const
{
  return theValue.toString();
}


/*******************************************************************************
  class DurationItem
********************************************************************************/
const xqp_duration& DurationItem::getDurationValue() const
{
  return theValue;
}


const xqp_dayTimeDuration& DurationItem::getDayTimeDurationValue() const
{
  return theValue;
}


const xqp_yearMonthDuration& DurationItem::getYearMonthDurationValue() const
{
  return theValue;
}


xqpStringStore_t DurationItem::getStringValue() const
{
  return theValue.toString();
}


void DurationItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.toString();
}


void DurationItem::getStringValue(std::string& buf) const
{
  buf += theValue.toString()->c_str();
}


SchemaTypeCode DurationItem::getTypeCode() const
{
  switch (theValue.getFacet())
  {
  case Duration::DURATION_FACET:
    return XS_DURATION;

  case Duration::DAYTIMEDURATION_FACET:
    return XS_DT_DURATION;

  case Duration::YEARMONTHDURATION_FACET:
  default:
    return XS_YM_DURATION;
  }
}


store::Item* DurationItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[getTypeCode()];
}


store::Item_t DurationItem::getEBV() const
{
  ZORBA_ERROR_DESC(FORG0006, "Effective Boolean Value is not defined for Duration!");
  return NULL;
}


xqp_string DurationItem::show() const
{
  return theValue.toString().getp();
}



/*******************************************************************************
  class DoubleItem
********************************************************************************/
store::Item* DoubleItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_DOUBLE];
}


store::Item_t DoubleItem::getEBV() const
{
  bool b;
  if (theValue.isNaN()) 
  {
    b = false;
  }
  else
  {
    b = !theValue.isZero();
  }
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t DoubleItem::getStringValue() const
{
  return NumConversions::doubleToStr(theValue);
}

void DoubleItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::doubleToStr(theValue);
}

void DoubleItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::doubleToStr(theValue)->c_str();
}

xqp_string DoubleItem::show() const
{
  return "xs:double(" + getStringValue()->str() + ")";
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
  return GET_STORE().theSchemaTypeNames[XS_FLOAT];
}


store::Item_t FloatItem::getEBV() const
{
  bool b;
  if (theValue.isNaN()) {
    b = false;
  } else {
    b = !theValue.isZero();
  }
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t FloatItem::getStringValue() const
{
  return NumConversions::floatToStr(theValue);
}

void FloatItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::floatToStr(theValue);
}

void FloatItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::floatToStr(theValue)->c_str();
}

xqp_string FloatItem::show() const
{
  return "xs:float(" + getStringValue()->str() + ")";
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
  return GET_STORE().theSchemaTypeNames[XS_DECIMAL];
}


store::Item_t DecimalItem::getEBV() const
{
  bool b = ( theValue != xqp_decimal::parseInt(0) );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t DecimalItem::getStringValue() const
{
  return NumConversions::decimalToStr(theValue);
}

void DecimalItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::decimalToStr(theValue);
}

void DecimalItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::decimalToStr(theValue)->c_str();
}


bool DecimalItem::isNaN() const 
{
  return theValue != theValue;
}


xqp_string DecimalItem::show() const
{
  return "xs:decimal(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class IntegerItem
********************************************************************************/
xqp_decimal IntegerItem::getDecimalValue() const
{
  return Decimal::parseInteger(theValue);
}


xqp_long IntegerItem::getLongValue() const
{
  xqp_long longValue;

  if (NumConversions::integerToLong(theValue, longValue))
    return longValue;

  ZORBA_ERROR_DESC(FORG0001, "Failed to downcast an integer value to a long value");

  return 0;
}


store::Item* IntegerItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INTEGER];
}


store::Item_t IntegerItem::getEBV() const
{
  bool b = ( theValue != xqp_integer::parseInt(0) );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t IntegerItem::getStringValue() const
{
  return NumConversions::integerToStr(theValue);
}


void IntegerItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::integerToStr(theValue);
}


void IntegerItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::integerToStr(theValue)->c_str();
}

xqp_string IntegerItem::show() const
{
  return "xs:integer(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class NonPositiveIntegerItem
********************************************************************************/
store::Item* NonPositiveIntegerItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NON_POSITIVE_INTEGER];
}

xqp_string NonPositiveIntegerItem::show() const 
{
  return "xs:nonPositiveInteger(" + getStringValue()->str() + ")";
}

  
/*******************************************************************************
  class NegativeIntegerItem
********************************************************************************/
store::Item* NegativeIntegerItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NEGATIVE_INTEGER];
}

xqp_string NegativeIntegerItem::show() const 
{
  return "xs:negativeInteger(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class NonNegativeINtegerItem
********************************************************************************/
store::Item* NonNegativeIntegerItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NON_NEGATIVE_INTEGER];
}

xqp_string NonNegativeIntegerItem::show() const 
{
  return "xs:nonNegativeInteger(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class PositiveIntegerItem
********************************************************************************/
store::Item* PositiveIntegerItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_POSITIVE_INTEGER];
}


xqp_string PositiveIntegerItem::show() const 
{
  return "xs:positiveInteger(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class LongItem
********************************************************************************/
xqp_decimal LongItem::getDecimalValue() const 
{
  return Decimal::parseLongLong(theValue);
}


xqp_integer LongItem::getIntegerValue() const 
{
  return Integer::parseLong(theValue);
}


store::Item* LongItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_LONG];
}


store::Item_t LongItem::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t LongItem::getStringValue() const 
{
  return NumConversions::longToStr(theValue);
}


void LongItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::longToStr(theValue);
}


void LongItem::getStringValue(std::string& buf) const
{
  buf +=  NumConversions::longToStr(theValue)->c_str();
}


xqp_string LongItem::show() const 
{
  return "xs:long(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class IntItem
********************************************************************************/
xqp_decimal IntItem::getDecimalValue() const
{
  return Decimal::parseInt(theValue);
}


xqp_integer IntItem::getIntegerValue() const
{
  return Integer::parseInt( theValue );
}


store::Item* IntItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INT];
}


store::Item_t IntItem::getEBV() const
{
  bool b = ( theValue != (int32_t)0 );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t IntItem::getStringValue() const
{
  return NumConversions::intToStr(theValue);
}


void IntItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::intToStr(theValue);
}


void IntItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::intToStr(theValue)->c_str();
}


xqp_string IntItem::show() const
{
  return "xs:int(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class ShortItem
********************************************************************************/
xqp_decimal ShortItem::getDecimalValue() const 
{
  return Decimal::parseInt((int32_t)theValue);
}


xqp_integer ShortItem::getIntegerValue() const 
{
  return Integer::parseInt((int32_t)theValue); 
}


store::Item* ShortItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_SHORT];
}


store::Item_t ShortItem::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t ShortItem::getStringValue() const 
{
  return NumConversions::shortToStr(theValue);
}


void ShortItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::shortToStr(theValue);
}


void ShortItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::shortToStr(theValue)->c_str();
}


xqp_string ShortItem::show() const 
{
  return "xs:short(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class ByteItem
********************************************************************************/
xqp_decimal ByteItem::getDecimalValue() const 
{
  return Decimal::parseInt((int32_t)theValue);
}


xqp_integer ByteItem::getIntegerValue() const 
{
  return Integer::parseInt((int32_t)theValue); 
}


store::Item* ByteItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_BYTE];
}


store::Item_t ByteItem::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t ByteItem::getStringValue() const 
{
  return NumConversions::byteToStr(theValue);
}


void ByteItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::byteToStr(theValue);
}


void ByteItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::byteToStr(theValue)->c_str();
}


xqp_string ByteItem::show() const 
{
  return "xs:byte(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedLongItem
********************************************************************************/
xqp_decimal UnsignedLongItem::getDecimalValue() const 
{
  return Decimal::parseULongLong(theValue);
}


xqp_integer UnsignedLongItem::getIntegerValue() const 
{
  return Integer::parseULong(theValue);
}


xqp_uinteger UnsignedLongItem::getUnsignedIntegerValue() const 
{
  return Integer::parseULong(theValue);
}


store::Item* UnsignedLongItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_LONG];
}


store::Item_t UnsignedLongItem::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedLongItem::getStringValue() const 
{
  return NumConversions::ulongToStr(theValue);
}


void UnsignedLongItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::ulongToStr(theValue);
}


void UnsignedLongItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::ulongToStr(theValue)->c_str();
}


xqp_string UnsignedLongItem::show() const 
{
  return "xs:unsignedLong(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedIntItem
********************************************************************************/
xqp_decimal UnsignedIntItem::getDecimalValue() const 
{
  return Decimal::parseUInt(theValue);
}


xqp_integer UnsignedIntItem::getIntegerValue() const 
{
  return Integer::parseInt(theValue);
}


xqp_uinteger UnsignedIntItem::getUnsignedIntegerValue() const 
{
  return Integer::parseInt(theValue);
}


store::Item* UnsignedIntItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_INT];
}


store::Item_t UnsignedIntItem::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedIntItem::getStringValue() const 
{
  return NumConversions::uintToStr(theValue);
}


void UnsignedIntItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::uintToStr(theValue);
}


void UnsignedIntItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::uintToStr(theValue)->c_str();
}


xqp_string UnsignedIntItem::show() const 
{
  return "xs:unsignedInt(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedShortItem
********************************************************************************/
xqp_decimal UnsignedShortItem::getDecimalValue() const 
{
  return Decimal::parseInt((uint32_t)theValue);
}


xqp_integer UnsignedShortItem::getIntegerValue() const 
{
  return Integer::parseInt((uint32_t)theValue);
}


xqp_uinteger UnsignedShortItem::getUnsignedIntegerValue() const 
{
  return Integer::parseInt((uint32_t)theValue);
}


store::Item* UnsignedShortItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_SHORT];
}


store::Item_t UnsignedShortItem::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedShortItem::getStringValue() const 
{
  return NumConversions::ushortToStr(theValue);
}


void UnsignedShortItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::ushortToStr(theValue);
}


void UnsignedShortItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::ushortToStr(theValue)->c_str();
}


xqp_string UnsignedShortItem::show() const 
{
  return "xs:unsignedShort(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedByteItem
********************************************************************************/
xqp_decimal UnsignedByteItem::getDecimalValue() const 
{
  return Decimal::parseUInt((uint32_t)theValue);
}


xqp_integer UnsignedByteItem::getIntegerValue() const 
{
  return Integer::parseInt((uint32_t)theValue);
}


xqp_uinteger UnsignedByteItem::getUnsignedIntegerValue() const 
{
  return Integer::parseInt(theValue);
}


store::Item* UnsignedByteItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_BYTE];
}


store::Item_t UnsignedByteItem::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedByteItem::getStringValue() const 
{
  return NumConversions::ubyteToStr(theValue);
}


void UnsignedByteItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::ubyteToStr(theValue);
}


void UnsignedByteItem::getStringValue(std::string& buf) const
{
  buf += NumConversions::ubyteToStr(theValue)->c_str();
}


xqp_string UnsignedByteItem::show() const 
{
  return "xs:unsignedByte(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class BooleanItem
********************************************************************************/
store::Item* BooleanItem::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_BOOLEAN];
}

uint32_t BooleanItem::hash ( long timezone, const XQPCollator* aCollation ) const
{
  return theValue?0:1;
}

store::Item_t BooleanItem::getEBV() const
{
  return this->getAtomizationValue();
}

xqpStringStore_t BooleanItem::getStringValue() const
{
  if (theValue)
    return new xqpStringStore("true");
  else
    return new xqpStringStore("false");
}

void BooleanItem::getStringValue(xqpStringStore_t& strval) const
{
  if (theValue)
    strval = new xqpStringStore("true");
  else
    strval = new xqpStringStore("false");
}

void BooleanItem::getStringValue(std::string& buf) const
{
  if (theValue)
    buf += "true";
  else
    buf += "false";
}

xqp_string BooleanItem::show() const
{
  return "xs:boolean(" + getStringValue()->str() + ")";
}




/*******************************************************************************
  class Base64BinaryItem
********************************************************************************/
store::Item* Base64BinaryItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_BASE64BINARY];
}


xqpStringStore_t Base64BinaryItem::getStringValue() const 
{
  return theValue.str();
}


void Base64BinaryItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.str();
}


void Base64BinaryItem::getStringValue(std::string& buf) const
{
  buf += theValue.str()->c_str();
}


xqp_string Base64BinaryItem::show() const 
{
  return "xs:base64Binary(" + getStringValue()->str() + ")";
}


uint32_t
Base64BinaryItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class HexBinaryItem
********************************************************************************/
store::Item* HexBinaryItem::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_HEXBINARY];
}


xqpStringStore_t HexBinaryItem::getStringValue() const 
{
  return theValue.str();
}

void HexBinaryItem::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.str();
}

void HexBinaryItem::getStringValue(std::string& buf) const
{
  buf += theValue.str()->c_str();
}

xqp_string HexBinaryItem::show() const 
{
  return "xs:hexBinary(" + getStringValue()->str() + ")";
}

uint32_t
HexBinaryItem::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}


/*******************************************************************************
  class ErrorItem
********************************************************************************/
ErrorItemNaive::~ErrorItemNaive()
{
  if (theError)
  {
    theError->free();
    theError = NULL;
  }
}


xqp_string ErrorItemNaive::show() const
{
  return theError->toString();
}



} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
