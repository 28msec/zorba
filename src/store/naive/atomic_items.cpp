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
#include "zorbautils/hashfun.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/collation_manager.h"
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "store/api/item.h"
#include "store/naive/node_items.h"

#include "store/naive/atomic_items.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/collection.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_store.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/store_defs.h"
#include "store/naive/item_iterator.h"


#define CREATE_XS_TYPE(aType) \
  GET_STORE().getItemFactory()->createQName(SimpleStore::XS_URI, "xs", aType);

#define CREATE_BOOLITEM(item, aValue) \
  GET_STORE().getItemFactory()->createBoolean(item, aValue)

namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
store::Item_t AtomicItem::getAtomizationValue() const
{
  store::Item* lItem = const_cast<AtomicItem *>(this);
  return lItem;
}


void AtomicItem::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  store::Item* lItem = const_cast<AtomicItem *>(this);
  val = lItem;
}


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
store::Item* UntypedAtomicItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


uint32_t UntypedAtomicItemImpl::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue->hash();
}


store::Item_t UntypedAtomicItemImpl::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqp_string UntypedAtomicItemImpl::show() const
{
  return "xs:untypedAtomic(" + theValue->str() + ")";
}


/*******************************************************************************
  class QNameItemImpl
********************************************************************************/

xqpStringStore_t QNameItemImpl::theEmptyPrefix(new xqpStringStore(""));


QNameItemImpl::~QNameItemImpl() 
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


void QNameItemImpl::free()
{
  GET_STORE().getQNamePool().remove(this);
}


void QNameItemImpl::setLocal(xqpStringStore* local)  
{
  assert(theUnion.theLocal == NULL);

  theUnion.theLocal = local;
  local->addReference(NULL SYNC_PARAM2(local->getRCLock()));
}


void QNameItemImpl::unsetLocal()  
{
  assert(theUnion.theLocal != NULL && isNormalized());

  theUnion.theLocal->removeReference(NULL SYNC_PARAM2(theUnion.theLocal->getRCLock()));
  theUnion.theLocal = NULL;
}


void QNameItemImpl::setNormalized(QNameItemImpl* qn)  
{
  assert(theUnion.theNormQN == NULL);

  theUnion.theNormQN = qn;
  qn->addReference(NULL SYNC_PARAM2(qn->getRCLock()));
}


void QNameItemImpl::unsetNormalized()  
{
  assert(theUnion.theNormQN != NULL && !isNormalized());

  theUnion.theNormQN->removeReference(NULL SYNC_PARAM2(theUnion.theNormQN->getRCLock()));
  theUnion.theNormQN = NULL;
}


uint32_t QNameItemImpl::hash(long timezone, const XQPCollator* aCollation) const
{
  const void* tmp = getNormalized();
  return hashfun::h32(tmp, FNV_32_INIT);
}


store::Item* QNameItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_QNAME];
}


store::Item_t QNameItemImpl::getEBV( ) const
{
  ZORBA_ERROR_DESC(FORG0006, "Effective Boolean Value is not defined for QName!");
  return NULL;
}


xqpStringStore_t QNameItemImpl::getStringValue( ) const
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


void QNameItemImpl::getStringValue(xqpStringStore_t& strval) const
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


void QNameItemImpl::getStringValue(std::string& buf) const
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


bool QNameItemImpl::isIdQName() const
{
  if (getLocalName()->byteEqual("id", 2))
  {
    if (getPrefix()->byteEqual("xml", 3) ||
        theNamespace->byteEqual(SimpleStore::XML_URI, SimpleStore::XML_URI_LEN))
      return true;
  }

  return false;
}


bool QNameItemImpl::isBaseUri() const
{
  if (getLocalName()->byteEqual("base", 4))
  {
    if (getPrefix()->byteEqual("xml", 3) ||
        getNamespace()->byteEqual(SimpleStore::XML_URI, SimpleStore::XML_URI_LEN))
      return true;
  }

  return false;
}


xqp_string QNameItemImpl::show() const
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
  class StringItemNaive
********************************************************************************/
store::Item* StringItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_STRING];
}


uint32_t StringItemNaive::hash(long timezone, const XQPCollator* aCollation) const
{
  if (aCollation == NULL || aCollation->doMemCmp())
    return xqpStringStore::hash(theValue->c_str());

  return theValue->hash(aCollation);
}


bool StringItemNaive::equals(
    const store::Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  if (aCollation == NULL || aCollation->doMemCmp())
    return theValue->byteEqual(other->getString()->str());

  return (theValue->compare(other->getString(), aCollation) == 0);
}
  

long StringItemNaive::compare(
    const Item* other,
    long timezone,
    const XQPCollator* aCollation) const
{
  if (aCollation == NULL || aCollation->doMemCmp())
    return theValue->byteCompare(other->getString()->str());

  return theValue->compare(other->getString(), aCollation);
}


store::Item_t StringItemNaive::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqp_string StringItemNaive::show() const
{
  return "xs:string(" + theValue->str() + ")";
}

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
int DateTimeItemNaive::createFromDateAndTime(
    const xqp_date* date,
    const xqp_time* time,
    store::Item_t& item)
{
  DateTimeItemNaive* dtin = new DateTimeItemNaive();
  int result = DateTime::createDateTime(date, time, dtin->theValue);
  item = dtin;
  return result;
}


xqpStringStore_t DateTimeItemNaive::getStringValue() const
{
  return theValue.toString().getStore();
}


void DateTimeItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.toString().getStore();
}

void DateTimeItemNaive::getStringValue(std::string& buf) const
{
  buf += theValue.toString().c_str();
}


store::Item* DateTimeItemNaive::getType() const
{
  switch (theValue.getFacet())
  {
  case DateTime::DATE_FACET:
    return GET_STORE().theSchemaTypeNames[XS_DATE];
    break;
      
  case DateTime::TIME_FACET:
    return GET_STORE().theSchemaTypeNames[XS_TIME];
    break;
    
  case DateTime::GYEARMONTH_FACET:
    return GET_STORE().theSchemaTypeNames[XS_GYEAR_MONTH];
    break;
    
  case DateTime::GYEAR_FACET:
    return GET_STORE().theSchemaTypeNames[XS_GYEAR];
    break;
    
  case DateTime::GMONTH_FACET:
    return GET_STORE().theSchemaTypeNames[XS_GMONTH];
    break;

  case DateTime::GMONTHDAY_FACET:
    return GET_STORE().theSchemaTypeNames[XS_GMONTH_DAY];
    break;
    
  case DateTime::GDAY_FACET:
    return GET_STORE().theSchemaTypeNames[XS_GDAY];
    break;

  default:
  case DateTime::DATETIME_FACET:
    return GET_STORE().theSchemaTypeNames[XS_DATETIME];
    break;
  }
}


bool DateTimeItemNaive::equals(
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


long DateTimeItemNaive::compare(
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


uint32_t DateTimeItemNaive::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash(0);
}


store::Item_t DateTimeItemNaive::getEBV() const
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


xqp_string DateTimeItemNaive::show() const
{
  return theValue.toString();
}


/*******************************************************************************
  class DurationItem
********************************************************************************/
const xqp_duration& DurationItemNaive::getDurationValue() const
{
  return theValue;
}

const xqp_dayTimeDuration& DurationItemNaive::getDayTimeDurationValue() const
{
  return theValue;
}

const xqp_yearMonthDuration& DurationItemNaive::getYearMonthDurationValue() const
{
  return theValue;
}

xqpStringStore_t DurationItemNaive::getStringValue() const
{
  return theValue.toString().getStore();
}

void DurationItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.toString().getStore();
}

void DurationItemNaive::getStringValue(std::string& buf) const
{
  buf += theValue.toString().c_str();
}


store::Item* DurationItemNaive::getType() const
{
  switch (theValue.getFacet())
  {
  default:
  case Duration::DURATION_FACET:
    return GET_STORE().theSchemaTypeNames[XS_DURATION];
    break;

  case Duration::DAYTIMEDURATION_FACET:
    return GET_STORE().theSchemaTypeNames[XS_DT_DURATION];
    break;

  case Duration::YEARMONTHDURATION_FACET:
    return GET_STORE().theSchemaTypeNames[XS_YM_DURATION];
    break;
  }
}


store::Item_t DurationItemNaive::getEBV() const
{
  ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for Duration!");
  return NULL;
}

xqp_string DurationItemNaive::show() const
{
  return theValue.toString().getStore();
}

uint32_t DurationItemNaive::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}


/*******************************************************************************
  class DoubleItemNaive
********************************************************************************/
store::Item* DoubleItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_DOUBLE];
}


store::Item_t DoubleItemNaive::getEBV() const
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


xqpStringStore_t DoubleItemNaive::getStringValue() const
{
  return NumConversions::doubleToStr(theValue).getStore();
}

void DoubleItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::doubleToStr(theValue).getStore();
}

void DoubleItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::doubleToStr(theValue).c_str();
}

xqp_string DoubleItemNaive::show() const
{
  return "xs:double(" + getStringValue()->str() + ")";
}


bool DoubleItemNaive::isNaN() const 
{
  return theValue.isNaN();
}


bool DoubleItemNaive::isPosOrNegInf() const 
{
  return theValue.isPosInf() || theValue.isNegInf();
}


uint32_t
DoubleItemNaive::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}

  
/*******************************************************************************
  class FloatItemNaive
********************************************************************************/
store::Item* FloatItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_FLOAT];
}


store::Item_t FloatItemNaive::getEBV() const
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

xqpStringStore_t FloatItemNaive::getStringValue() const
{
  return NumConversions::floatToStr(theValue).getStore();
}

void FloatItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::floatToStr(theValue).getStore();
}

void FloatItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::floatToStr(theValue).c_str();
}

xqp_string FloatItemNaive::show() const
{
  return "xs:float(" + getStringValue()->str() + ")";
}

bool FloatItemNaive::isNaN() const {
  return theValue.isNaN();
}

bool FloatItemNaive::isPosOrNegInf() const {
  return theValue.isPosInf() || theValue.isNegInf();
}

uint32_t FloatItemNaive::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}


/*******************************************************************************
  class DecimalItemNaive
********************************************************************************/
store::Item* DecimalItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_DECIMAL];
}


store::Item_t DecimalItemNaive::getEBV() const
{
  bool b = ( theValue != xqp_decimal::parseInt(0) );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t DecimalItemNaive::getStringValue() const
{
  return NumConversions::decimalToStr(theValue).getStore();
}

void DecimalItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::decimalToStr(theValue).getStore();
}

void DecimalItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::decimalToStr(theValue).c_str();
}

bool DecimalItemNaive::isNaN() const 
{
  return theValue != theValue;
}

xqp_string DecimalItemNaive::show() const
{
  return "xs:decimal(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class IntegerItemNaive
********************************************************************************/
xqp_decimal IntegerItemNaive::getDecimalValue() const
{
  return Decimal::parseInteger(theValue);
}

store::Item* IntegerItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INTEGER];
}


store::Item_t IntegerItemNaive::getEBV() const
{
  bool b = ( theValue != xqp_integer::parseInt(0) );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t IntegerItemNaive::getStringValue() const
{
  return NumConversions::integerToStr(theValue).getStore();
}

void IntegerItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::integerToStr(theValue).getStore();
}

void IntegerItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::integerToStr(theValue).c_str();
}

xqp_string IntegerItemNaive::show() const
{
  return "xs:integer(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
store::Item* NonPositiveIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NON_POSITIVE_INTEGER];
}

xqp_string NonPositiveIntegerItemNaive::show() const 
{
  return "xs:nonPositiveInteger(" + getStringValue()->str() + ")";
}

  
/*******************************************************************************
  class NegativeIntegerItemNaive
********************************************************************************/
store::Item* NegativeIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NEGATIVE_INTEGER];
}

xqp_string NegativeIntegerItemNaive::show() const 
{
  return "xs:negativeInteger(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class NonNegativeINtegerItemNaive
********************************************************************************/
store::Item* NonNegativeIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NON_NEGATIVE_INTEGER];
}

xqp_string NonNegativeIntegerItemNaive::show() const 
{
  return "xs:nonNegativeInteger(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class PositiveIntegerItemNaive
********************************************************************************/
store::Item* PositiveIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_POSITIVE_INTEGER];
}


xqp_string PositiveIntegerItemNaive::show() const 
{
  return "xs:positiveInteger(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class LongItemNaive
********************************************************************************/
xqp_decimal LongItemNaive::getDecimalValue() const 
{
  return Decimal::parseLongLong(theValue);
}


xqp_integer LongItemNaive::getIntegerValue() const 
{
  return Integer::parseLongLong(theValue);
}


store::Item* LongItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_LONG];
}


store::Item_t LongItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t LongItemNaive::getStringValue() const 
{
  return NumConversions::longLongToStr(theValue).getStore();
}


void LongItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::longLongToStr(theValue).getStore();
}


void LongItemNaive::getStringValue(std::string& buf) const
{
  buf +=  NumConversions::longLongToStr(theValue).c_str();
}


xqp_string LongItemNaive::show() const 
{
  return "xs:long(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class IntItemNaive
********************************************************************************/
xqp_decimal IntItemNaive::getDecimalValue() const
{
  return Decimal::parseInt( theValue );
}


xqp_integer IntItemNaive::getIntegerValue() const
{
  return Integer::parseInt( theValue );
}


store::Item* IntItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INT];
}


store::Item_t IntItemNaive::getEBV() const
{
  bool b = ( theValue != (int32_t)0 );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t IntItemNaive::getStringValue() const
{
  return NumConversions::intToStr(theValue).getStore();
}


void IntItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::intToStr(theValue).getStore();
}


void IntItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::intToStr(theValue).c_str();
}


xqp_string IntItemNaive::show() const
{
  return "xs:int(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class ShortItemNaive
********************************************************************************/
xqp_decimal ShortItemNaive::getDecimalValue() const 
{
  return Decimal::parseInt((int32_t)theValue);
}


xqp_integer ShortItemNaive::getIntegerValue() const 
{
  return Integer::parseInt((int32_t)theValue); 
}


store::Item* ShortItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_SHORT];
}


store::Item_t ShortItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t ShortItemNaive::getStringValue() const 
{
  return NumConversions::shortToStr(theValue).getStore();
}


void ShortItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::shortToStr(theValue).getStore();
}


void ShortItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::shortToStr(theValue).c_str();
}


xqp_string ShortItemNaive::show() const 
{
  return "xs:short(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class ByteItemNaive
********************************************************************************/
xqp_decimal ByteItemNaive::getDecimalValue() const 
{
  return Decimal::parseInt((int32_t)theValue);
}


xqp_integer ByteItemNaive::getIntegerValue() const 
{
  return Integer::parseInt((int32_t)theValue); 
}


store::Item* ByteItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_BYTE];
}


store::Item_t ByteItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t ByteItemNaive::getStringValue() const 
{
  return NumConversions::byteToStr(theValue).getStore();
}


void ByteItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::byteToStr(theValue).getStore();
}


void ByteItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::byteToStr(theValue).c_str();
}


xqp_string ByteItemNaive::show() const 
{
  return "xs:byte(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedLongItemNaive
********************************************************************************/
xqp_decimal UnsignedLongItemNaive::getDecimalValue() const 
{
  return Decimal::parseULongLong(theValue);
}


xqp_integer UnsignedLongItemNaive::getIntegerValue() const 
{
  return Integer::parseULongLong(theValue);
}


xqp_uinteger UnsignedLongItemNaive::getUnsignedIntegerValue() const 
{
  return Integer::parseULongLong(theValue);
}


store::Item* UnsignedLongItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_LONG];
}


store::Item_t UnsignedLongItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedLongItemNaive::getStringValue() const 
{
  return NumConversions::ulongLongToStr(theValue).getStore();
}


void UnsignedLongItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::ulongLongToStr(theValue).getStore();
}


void UnsignedLongItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::ulongLongToStr(theValue).c_str();
}


xqp_string UnsignedLongItemNaive::show() const 
{
  return "xs:unsignedLong(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedIntItemNaive
********************************************************************************/
xqp_decimal UnsignedIntItemNaive::getDecimalValue() const 
{
  return Decimal::parseUInt(theValue);
}


xqp_integer UnsignedIntItemNaive::getIntegerValue() const 
{
  return Integer::parseInt(theValue);
}


xqp_uinteger UnsignedIntItemNaive::getUnsignedIntegerValue() const 
{
  return Integer::parseInt(theValue);
}


store::Item* UnsignedIntItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_INT];
}


store::Item_t UnsignedIntItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedIntItemNaive::getStringValue() const 
{
  return NumConversions::uintToStr(theValue).getStore();
}


void UnsignedIntItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::uintToStr(theValue).getStore();
}


void UnsignedIntItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::uintToStr(theValue).c_str();
}


xqp_string UnsignedIntItemNaive::show() const 
{
  return "xs:unsignedInt(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedShortItemNaive
********************************************************************************/
xqp_decimal UnsignedShortItemNaive::getDecimalValue() const 
{
  return Decimal::parseInt((uint32_t)theValue);
}


xqp_integer UnsignedShortItemNaive::getIntegerValue() const 
{
  return Integer::parseInt((uint32_t)theValue);
}


xqp_uinteger UnsignedShortItemNaive::getUnsignedIntegerValue() const 
{
  return Integer::parseInt((uint32_t)theValue);
}


store::Item* UnsignedShortItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_SHORT];
}


store::Item_t UnsignedShortItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedShortItemNaive::getStringValue() const 
{
  return NumConversions::ushortToStr(theValue).getStore();
}


void UnsignedShortItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::ushortToStr(theValue).getStore();
}


void UnsignedShortItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::ushortToStr(theValue).c_str();
}


xqp_string UnsignedShortItemNaive::show() const 
{
  return "xs:unsignedShort(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class UnsignedByteItemNaive
********************************************************************************/
xqp_decimal UnsignedByteItemNaive::getDecimalValue() const 
{
  return Decimal::parseUInt((uint32_t)theValue);
}


xqp_integer UnsignedByteItemNaive::getIntegerValue() const 
{
  return Integer::parseInt((uint32_t)theValue);
}


xqp_uinteger UnsignedByteItemNaive::getUnsignedIntegerValue() const 
{
  return Integer::parseInt(theValue);
}


store::Item* UnsignedByteItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_BYTE];
}


store::Item_t UnsignedByteItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqpStringStore_t UnsignedByteItemNaive::getStringValue() const 
{
  return NumConversions::ubyteToStr(theValue).getStore();
}


void UnsignedByteItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = NumConversions::ubyteToStr(theValue).getStore();
}


void UnsignedByteItemNaive::getStringValue(std::string& buf) const
{
  buf += NumConversions::ubyteToStr(theValue).c_str();
}


xqp_string UnsignedByteItemNaive::show() const 
{
  return "xs:unsignedByte(" + getStringValue()->str() + ")";
}


/*******************************************************************************
  class BooleanItemNaive
********************************************************************************/
store::Item* BooleanItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_BOOLEAN];
}

uint32_t BooleanItemNaive::hash ( long timezone, const XQPCollator* aCollation ) const
{
  return theValue?0:1;
}

store::Item_t BooleanItemNaive::getEBV() const
{
  return this->getAtomizationValue();
}

xqpStringStore_t BooleanItemNaive::getStringValue() const
{
  if (theValue)
    return new xqpStringStore("true");
  else
    return new xqpStringStore("false");
}

void BooleanItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  if (theValue)
    strval = new xqpStringStore("true");
  else
    strval = new xqpStringStore("false");
}

void BooleanItemNaive::getStringValue(std::string& buf) const
{
  if (theValue)
    buf += "true";
  else
    buf += "false";
}

xqp_string BooleanItemNaive::show() const
{
  return "xs:boolean(" + getStringValue()->str() + ")";
}




/*******************************************************************************
  class Base64BinaryItemNaive
********************************************************************************/
store::Item* Base64BinaryItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_BASE64BINARY];
}


xqpStringStore_t Base64BinaryItemNaive::getStringValue() const 
{
  return theValue.str().getStore();
}

void Base64BinaryItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.str().getStore();
}

void Base64BinaryItemNaive::getStringValue(std::string& buf) const
{
  buf += theValue.str().c_str();
}

xqp_string Base64BinaryItemNaive::show() const 
{
  return "xs:base64Binary(" + getStringValue()->str() + ")";
}

uint32_t
Base64BinaryItemNaive::hash(long timezone, const XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class HexBinaryItemNaive
********************************************************************************/
store::Item* HexBinaryItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_HEXBINARY];
}


xqpStringStore_t HexBinaryItemNaive::getStringValue() const 
{
  return theValue.str().getStore();
}

void HexBinaryItemNaive::getStringValue(xqpStringStore_t& strval) const
{
  strval = theValue.str().getStore();
}

void HexBinaryItemNaive::getStringValue(std::string& buf) const
{
  buf += theValue.str().c_str();
}

xqp_string HexBinaryItemNaive::show() const 
{
  return "xs:hexBinary(" + getStringValue()->str() + ")";
}

uint32_t
HexBinaryItemNaive::hash(long timezone, const XQPCollator* aCollation) const
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



} // namespace store
} // namespace zorba

