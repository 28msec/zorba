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
  class QNameItemImpl
********************************************************************************/

xqpStringStore_t QNameItemImpl::theEmptyPrefix(new xqpStringStore(""));


QNameItemImpl::~QNameItemImpl() 
{
  if (isValid() && !isNormalized())
  {
    unsetNormalized();
  }
}


void QNameItemImpl::free()
{
  GET_STORE().getQNamePool().remove(this);
}


void QNameItemImpl::setNormalized(QNameItemImpl* qn)  
{
  assert(theLocal == NULL);

  *reinterpret_cast<QNameItemImpl**>(&theLocal) = qn;
  qn->addReference(NULL SYNC_PARAM2(qn->getRCLock()));
}


void QNameItemImpl::unsetNormalized()  
{
  assert(theLocal != NULL && !isNormalized());

  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(theLocal.getp());
  qn->removeReference(NULL SYNC_PARAM2(qn->getRCLock()));
  theLocal.setNull();
}


uint32_t QNameItemImpl::hash(long timezone, XQPCollator* aCollation) const
{
  const void* tmp = getNormalized();
  return hashfun::h32(&tmp, sizeof(*this));
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


bool QNameItemImpl::isId() const
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
  class StringItemNaive
********************************************************************************/
store::Item* StringItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_STRING];
}


uint32_t StringItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue->hash(aCollation);
}


bool StringItemNaive::equals(
    const store::Item* item,
    long timezone,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue.getp());
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
  class NCNameItemImpl
********************************************************************************/
store::Item* NCNameItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_NCNAME];
}


uint32_t NCNameItemImpl::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue->hash();
}


bool NCNameItemImpl::equals(
    const store::Item* item,
    long timezone,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue);
}


store::Item_t NCNameItemImpl::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}


xqp_string NCNameItemImpl::show() const
{
  return "xs:NCName(" + theValue->str() + ")";
}


store::Item* IDItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_ID];
}


/*******************************************************************************
  class IDItemImpl
********************************************************************************/
xqp_string IDItemImpl::show() const
{
  return "xs:ID(" + theValue->str() + ")";
}


/*******************************************************************************
  class AnyUriItem
********************************************************************************/
store::Item* AnyUriItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_ANY_URI];
}

uint32_t AnyUriItemImpl::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue->hash();
}


bool AnyUriItemImpl::equals(
    const store::Item* item,
    long timezone,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue.getp());
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
  class UntypedAtomicItem
********************************************************************************/
store::Item* UntypedAtomicItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


uint32_t UntypedAtomicItemImpl::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue->hash();
}


bool UntypedAtomicItemImpl::equals(
    const store::Item* item,
    long timezone,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue.getp());
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
    XQPCollator* coll) const
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


uint32_t DateTimeItemNaive::hash(long timezone, XQPCollator* aCollation) const
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

bool DurationItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const
{
  return theValue == aItem->getDurationValue();
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

uint32_t DurationItemNaive::hash(long timezone, XQPCollator* aCollation) const
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

bool DecimalItemNaive::equals(
    const store::Item* item,
    long timezone,
    XQPCollator* coll ) const
{
  return item->getDecimalValue() == theValue;
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

xqp_string DecimalItemNaive::show() const
{
  return "xs:decimal(" + getStringValue()->str() + ")";
}

bool DecimalItemNaive::isNaN() const {
  return theValue != theValue;
}

uint32_t
DecimalItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue.hash();
}


/*******************************************************************************
  class IntItemNaive
********************************************************************************/
xqp_integer IntItemNaive::getIntegerValue() const
{
  return Integer::parseInt( theValue );
}

xqp_decimal IntItemNaive::getDecimalValue() const
{
  return Decimal::parseInt( theValue );
}

xqp_long IntItemNaive::getLongValue() const {
  return static_cast<xqp_long>(theValue);
}

store::Item* IntItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INT];
}

bool IntItemNaive::equals (
    const store::Item* item,
    long timezone,
    XQPCollator* coll ) const
{
  return item->getIntValue() == theValue;
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

xqp_string IntItemNaive::show() const
{
  return "xs:int(" + getStringValue()->str() + ")";
}

uint32_t
IntItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return uint32_t(32767) + theValue;
}


/*******************************************************************************
  class IntegerItemNaive
********************************************************************************/
xqp_decimal IntegerItemNaive::getDecimalValue() const
{
  return Decimal::parseInteger ( theValue );
}

store::Item* IntegerItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INTEGER];
}

bool IntegerItemNaive::equals (
    const store::Item* item,
    long timezone,
    XQPCollator* aCollation ) const
{
  return item->getIntegerValue() == theValue;
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

xqp_string IntegerItemNaive::show() const
{
  return "xs:integer(" + getStringValue()->str() + ")";
}

uint32_t
IntegerItemNaive::hash(long timezone, XQPCollator* aCollation) const
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


bool DoubleItemNaive::equals (
    const store::Item* item,
    long timezone,
    XQPCollator* coll ) const
{
  return item->getDoubleValue() == theValue;
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
DoubleItemNaive::hash(long timezone, XQPCollator* aCollation) const
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

bool FloatItemNaive::equals (
    const store::Item* item,
    long timezone,
    XQPCollator* aCollation ) const
{
  return item->getFloatValue() == theValue;
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

uint32_t
FloatItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class BooleanItemNaive
********************************************************************************/
store::Item* BooleanItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_BOOLEAN];
}

bool BooleanItemNaive::equals (
    const store::Item* item,
    long timezone,
    XQPCollator* aCollation ) const
{
  return item->getBooleanValue() == theValue;
}

uint32_t BooleanItemNaive::hash ( long timezone, XQPCollator* aCollation ) const
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

xqp_string BooleanItemNaive::show() const
{
  return "xs:boolean(" + getStringValue()->str() + ")";
}

/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
xqp_decimal NonPositiveIntegerItemNaive::getDecimalValue() const 
{
  return Decimal::parseInteger ( theValue );
}

store::Item* NonPositiveIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NON_POSITIVE_INTEGER];
}

bool NonPositiveIntegerItemNaive::equals(
   const store::Item* aItem,
   long timezone,
   XQPCollator* coll ) const
{
  return theValue == aItem->getIntegerValue();
}

store::Item_t NonPositiveIntegerItemNaive::getEBV() const 
{
  bool b = (theValue != xqp_integer::parseInt(0));
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t NonPositiveIntegerItemNaive::getStringValue() const 
{
  return NumConversions::uintegerToStr(theValue).getStore();
}

xqp_string NonPositiveIntegerItemNaive::show() const 
{
  return "xs:nonPositiveInteger(" + getStringValue()->str() + ")";
}

uint32_t
NonPositiveIntegerItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue.hash();
}
  
/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
xqp_decimal NegativeIntegerItemNaive::getDecimalValue() const 
{
  return Decimal::parseInteger ( theValue );
}

store::Item* NegativeIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NEGATIVE_INTEGER];
}

bool NegativeIntegerItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const 
{
  return theValue == aItem->getIntegerValue();
}

store::Item_t NegativeIntegerItemNaive::getEBV() const 
{
  bool b = (theValue != xqp_integer::parseInt(0));
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t NegativeIntegerItemNaive::getStringValue() const 
{
  return NumConversions::integerToStr(theValue).getStore();
}

xqp_string NegativeIntegerItemNaive::show() const 
{
  return "xs:negativeInteger(" + getStringValue()->str() + ")";
}

uint32_t
NegativeIntegerItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue.hash();
}
  
/*******************************************************************************
  class LongItemNaive
********************************************************************************/
xqp_integer LongItemNaive::getIntegerValue() const 
{
  return Integer::parseLongLong(theValue);
}

xqp_decimal LongItemNaive::getDecimalValue() const 
{
  return Decimal::parseLongLong(theValue);
}

store::Item* LongItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_LONG];
}

bool LongItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const 
{
  return theValue == aItem->getLongValue();
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

xqp_string LongItemNaive::show() const 
{
  return "xs:long(" + getStringValue()->str() + ")";
}

uint32_t
LongItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue % 65535;
}
  
/*******************************************************************************
  class ShortItemNaive
********************************************************************************/
xqp_integer ShortItemNaive::getIntegerValue() const 
{
  return Integer::parseInt((int32_t)theValue); 
}

xqp_decimal ShortItemNaive::getDecimalValue() const 
{
  return Decimal::parseInt((int32_t)theValue);
}

xqp_long ShortItemNaive::getLongValue() const 
{
  return static_cast<xqp_long>(theValue);
}

xqp_int ShortItemNaive::getIntValue() const 
{
  return static_cast<xqp_int>(theValue);
}

store::Item* ShortItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_SHORT];
}

bool ShortItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const
{
  return theValue == aItem->getLongValue();
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

xqp_string ShortItemNaive::show() const 
{
  return "xs:short(" + getStringValue()->str() + ")";
}

uint32_t
ShortItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue;
}

/*******************************************************************************
  class ByteItemNaive
********************************************************************************/
xqp_integer ByteItemNaive::getIntegerValue() const 
{
  return Integer::parseInt((int32_t)theValue); 
}

xqp_decimal ByteItemNaive::getDecimalValue() const 
{
  return Decimal::parseInt((int32_t)theValue);
}

xqp_long ByteItemNaive::getLongValue() const 
{
  return static_cast<xqp_long>(theValue);
}

xqp_int ByteItemNaive::getIntValue() const 
{
  return static_cast<xqp_int>(theValue);
}

xqp_short ByteItemNaive::getShortValue() const 
{
  return static_cast<xqp_short>(theValue);
}

store::Item* ByteItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_BYTE];
}

bool ByteItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const
{
  return theValue == aItem->getLongValue();
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

xqp_string ByteItemNaive::show() const 
{
  return "xs:byte(" + getStringValue()->str() + ")";
}

uint32_t
ByteItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue;
}


/*******************************************************************************
  class NonNegativeINtegerItemNaive
********************************************************************************/
xqp_integer NonNegativeIntegerItemNaive::getIntegerValue() const {
 return theValue; 
}

xqp_decimal NonNegativeIntegerItemNaive::getDecimalValue() const {
  return Decimal::parseInteger(theValue);
}

store::Item* NonNegativeIntegerItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_NON_NEGATIVE_INTEGER];
}

bool NonNegativeIntegerItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const
{
  return theValue == aItem->getUnsignedIntegerValue();
}

store::Item_t NonNegativeIntegerItemNaive::getEBV() const {
  bool b = (theValue != xqp_integer::parseInt(0));
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t NonNegativeIntegerItemNaive::getStringValue() const 
{
  return NumConversions::uintegerToStr(theValue).getStore();
}

xqp_string NonNegativeIntegerItemNaive::show() const {
  return "xs:nonNegativeInteger(" + getStringValue()->str() + ")";
}

uint32_t
NonNegativeIntegerItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class UnsignedLongItemNaive
********************************************************************************/
xqp_integer UnsignedLongItemNaive::getIntegerValue() const {
  return Integer::parseULongLong(theValue);
}

xqp_decimal UnsignedLongItemNaive::getDecimalValue() const {
  return Decimal::parseULongLong(theValue);
}

xqp_uinteger UnsignedLongItemNaive::getUnsignedIntegerValue() const {
  return Integer::parseULongLong(theValue);
}

store::Item* UnsignedLongItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_LONG];
}

bool UnsignedLongItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedLongValue();
}

store::Item_t UnsignedLongItemNaive::getEBV() const {
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t UnsignedLongItemNaive::getStringValue() const {
  return NumConversions::ulongLongToStr(theValue).getStore();
}

xqp_string UnsignedLongItemNaive::show() const {
  return "xs:unsignedLong(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedLongItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue % 65535;
}

/*******************************************************************************
  class UnsignedIntItemNaive
********************************************************************************/
xqp_integer UnsignedIntItemNaive::getIntegerValue() const 
{
  return Integer::parseInt(theValue);
}

xqp_decimal UnsignedIntItemNaive::getDecimalValue() const {
  return Decimal::parseUInt(theValue);
}

xqp_uinteger UnsignedIntItemNaive::getUnsignedIntegerValue() const {
  return Integer::parseInt(theValue);
}

xqp_ulong UnsignedIntItemNaive::getUnsignedLongValue() const {
  return static_cast<xqp_ulong>(theValue);
}

store::Item* UnsignedIntItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_INT];
}

bool UnsignedIntItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedIntValue();
}

store::Item_t UnsignedIntItemNaive::getEBV() const {
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t UnsignedIntItemNaive::getStringValue() const {
  return NumConversions::uintToStr(theValue).getStore();
}

xqp_string UnsignedIntItemNaive::show() const {
  return "xs:unsignedInt(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedIntItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue;
}


/*******************************************************************************
  class UnsignedShortItemNaive
********************************************************************************/
xqp_integer UnsignedShortItemNaive::getIntegerValue() const {
  return Integer::parseInt((uint32_t)theValue);
}

xqp_decimal UnsignedShortItemNaive::getDecimalValue() const {
  return Decimal::parseInt((uint32_t)theValue);
}

xqp_uinteger UnsignedShortItemNaive::getUnsignedIntegerValue() const {
  return Integer::parseInt((uint32_t)theValue);
}

xqp_ulong UnsignedShortItemNaive::getUnsignedLongValue() const {
  return static_cast<xqp_ulong>(theValue);
}

xqp_uint UnsignedShortItemNaive::getUnsignedIntValue() const {
  return static_cast<xqp_uint>(theValue);
}

store::Item* UnsignedShortItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_SHORT];
}

bool UnsignedShortItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedShortValue();
}

store::Item_t UnsignedShortItemNaive::getEBV() const {
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t UnsignedShortItemNaive::getStringValue() const {
  return NumConversions::ushortToStr(theValue).getStore();
}

xqp_string UnsignedShortItemNaive::show() const {
  return "xs:unsignedShort(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedShortItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue;
}

/*******************************************************************************
  class UnsignedByteItemNaive
********************************************************************************/
xqp_integer UnsignedByteItemNaive::getIntegerValue() const {
  return Integer::parseInt((uint32_t)theValue);
}

xqp_decimal UnsignedByteItemNaive::getDecimalValue() const {
  return Decimal::parseUInt((uint32_t)theValue);
}

xqp_uinteger UnsignedByteItemNaive::getUnsignedIntegerValue() const {
  return Integer::parseInt(theValue);
}

xqp_ulong UnsignedByteItemNaive::getUnsignedLongValue() const {
  return static_cast<xqp_ulong>(theValue);
}

xqp_uint UnsignedByteItemNaive::getUnsignedIntValue() const {
  return static_cast<xqp_uint>(theValue);
}

xqp_ushort UnsignedByteItemNaive::getUnsignedShortValue() const {
  return static_cast<xqp_ushort>(theValue);
}

store::Item* UnsignedByteItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_BYTE];
}

bool UnsignedByteItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedByteValue();
}

store::Item_t UnsignedByteItemNaive::getEBV() const {
  bool b = (theValue != 0);
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t UnsignedByteItemNaive::getStringValue() const {
  return NumConversions::ubyteToStr(theValue).getStore();
}

xqp_string UnsignedByteItemNaive::show() const {
  return "xs:unsignedByte(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedByteItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue;
}

/*******************************************************************************
  class PositiveIntegerItemNaive
********************************************************************************/
xqp_integer PositiveIntegerItemNaive::getIntegerValue() const 
{
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal PositiveIntegerItemNaive::getDecimalValue() const 
{
  return Decimal::parseInteger(theValue);
}

store::Item* PositiveIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_POSITIVE_INTEGER];
}

bool PositiveIntegerItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const 
{
  return theValue == aItem->getUnsignedIntegerValue();
}

store::Item_t PositiveIntegerItemNaive::getEBV() const 
{
  bool b = (theValue != xqp_integer::parseInt(0));
  store::Item_t bVal;
  CREATE_BOOLITEM(bVal, b);
  return bVal;
}

xqpStringStore_t PositiveIntegerItemNaive::getStringValue() const 
{
  return NumConversions::uintegerToStr(theValue).getStore();
}

xqp_string PositiveIntegerItemNaive::show() const 
{
  return "xs:positiveInteger(" + getStringValue()->str() + ")";
}

uint32_t
PositiveIntegerItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class Base64BinaryItemNaive
********************************************************************************/
store::Item* Base64BinaryItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_BASE64BINARY];
}

bool Base64BinaryItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const {
  return theValue.equal(aItem->getBase64BinaryValue());
}

xqpStringStore_t Base64BinaryItemNaive::getStringValue() const {
  return theValue.str().getStore();
}

xqp_string Base64BinaryItemNaive::show() const {
  return "xs:base64Binary(" + getStringValue()->str() + ")";
}

uint32_t
Base64BinaryItemNaive::hash(long timezone, XQPCollator* aCollation) const
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

bool HexBinaryItemNaive::equals(
    const store::Item* aItem,
    long timezone,
    XQPCollator* coll ) const {
  return theValue.equal(aItem->getHexBinaryValue());
}

xqpStringStore_t HexBinaryItemNaive::getStringValue() const {
  return theValue.str().getStore();
}

xqp_string HexBinaryItemNaive::show() const {
  return "xs:hexBinary(" + getStringValue()->str() + ")";
}

uint32_t
HexBinaryItemNaive::hash(long timezone, XQPCollator* aCollation) const
{
  return theValue.hash();
}



} // namespace store
} // namespace zorba

