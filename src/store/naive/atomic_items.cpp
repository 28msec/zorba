/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- */

/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: David Graf, Donald Kossmann, Tim Kraska, Markos zaharioudakis, Nicolae Brinza
 */

#include "zorbatypes/numconversions.h"
#include "store/api/item.h"

#include "util/Assert.h"
#include "errors/error_manager.h"
#include "compiler/parser/query_loc.h"
#include "util/hashfun.h"

#include "system/globalenv.h"

#include "store/naive/atomic_items.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_store.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/store_defs.h"
#include "store/api/item_iterator.h"
#include "context/dynamic_context.h"
#include "zorbatypes/datetime.h"

#define CREATE_XS_TYPE(aType) \
  GET_STORE().getItemFactory()->createQName(SimpleStore::XS_URI, "xs", aType);

#define CREATE_BOOLITEM(aValue) \
  GET_STORE().getItemFactory()->createBoolean(aValue)

namespace zorba { namespace store {


/*******************************************************************************

********************************************************************************/
Item_t AtomicItem::getAtomizationValue() const
{
  Item* lItem = const_cast<AtomicItem *>(this);
  return lItem;
}


Iterator_t AtomicItem::getTypedValue() const
{
  return new ItemIterator(getAtomizationValue()); 
}


/*******************************************************************************
  class QNameItemImpl
********************************************************************************/

void QNameItemImpl::free()
{
  GET_STORE().getQNamePool().remove(this);
}


Item_t QNameItemImpl::getType() const
{
  return GET_STORE().theQNameType;
}

uint32_t QNameItemImpl::hash() const
{
  return hashfun::h32(*thePrefix,
                      hashfun::h32(*theLocal,
                                   hashfun::h32(*theNamespace)));
}


bool QNameItemImpl::equals(Item_t item) const
{
  return (this == item.getp() ||
          (theNamespace->byteEqual(*item->getNamespace().getStore()) &&
           theLocal->byteEqual(*item->getLocalName().getStore())));
}


Item_t QNameItemImpl::getEBV( ) const
{
  ZORBA_ERROR_DESC( ZorbaError::FORG0006, "Effective Boolean Value is not defined for QName!");
  return NULL;
}


xqp_string QNameItemImpl::getStringValue( ) const
{
  return *thePrefix != "" ? *thePrefix + ":" + *theLocal : *theLocal;
}


xqp_string QNameItemImpl::show() const
{
  return "xs:QName(" + *theNamespace + "," + *thePrefix + "," + *theLocal + ")";
}


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
Item_t NCNameItemImpl::getType() const
{
  return GET_FACTORY().createQName(SimpleStore::XS_URI, "xs", "NCName");
}

uint32_t NCNameItemImpl::hash() const
{
  return theValue->hash();
}

bool NCNameItemImpl::equals(Item_t item) const
{
  return item->getStringValue() == xqp_string(theValue.getp());
}

Item_t NCNameItemImpl::getEBV() const
{
  bool b = ! ( *theValue == "" );
  return CREATE_BOOLITEM(b);
}

xqp_string NCNameItemImpl::show() const
{
  return "xs:NCName(" + *theValue + ")";
}


/*******************************************************************************
  class AnyUriItemNaive
********************************************************************************/
Item_t AnyUriItemImpl::getType() const
{
  return GET_FACTORY().createQName(SimpleStore::XS_URI, "xs", "anyURI");
}

uint32_t AnyUriItemImpl::hash() const
{
  return theValue->hash();
}


bool AnyUriItemImpl::equals(Item_t item) const
{
  return item->getStringValue() == xqp_string(theValue.getp());
}


Item_t AnyUriItemImpl::getEBV() const
{
  bool b = ! (*theValue == "");
  return CREATE_BOOLITEM(b);
}


xqp_string AnyUriItemImpl::show() const
{
  return "xs:anyURI(" + *theValue + ")";
}


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
Item_t UntypedAtomicItemImpl::getType() const
{
  return static_cast<SimpleStore*>(&GENV.getStore())->theUntypedAtomicType;
}

uint32_t UntypedAtomicItemImpl::hash() const
{
  return theValue->hash();
}

bool UntypedAtomicItemImpl::equals(Item_t item) const
{
  return item->getStringValue() == xqp_string(theValue.getp());
}

Item_t UntypedAtomicItemImpl::getEBV() const
{
  bool b = ! ( *theValue == "" );
  return CREATE_BOOLITEM(b);
}

xqp_string UntypedAtomicItemImpl::show() const
{
  return "xs:untypedAtomic(" + *theValue + ")";
}


/*******************************************************************************
  class StingItemNaive
********************************************************************************/
Item_t StringItemNaive::getType() const
{
  return CREATE_XS_TYPE("string");
}

uint32_t StringItemNaive::hash() const
{
  return theValue->hash();
}

bool StringItemNaive::equals(Item_t item) const
{
  return item->getStringValue() == xqp_string(theValue.getp());
}
  
Item_t StringItemNaive::getEBV() const
{
  bool b = ! ( *theValue == "" );
  return CREATE_BOOLITEM(b);
}

xqp_string StringItemNaive::show() const
{
  return "xs:string(" + *theValue + ")";
}


/*******************************************************************************
  class DecimalItemNaive
********************************************************************************/
Item_t DecimalItemNaive::getType() const
{
  return CREATE_XS_TYPE("decimal");
}

bool DecimalItemNaive::equals ( Item_t item ) const
{
  return item->getDecimalValue() == theValue;
}

Item_t DecimalItemNaive::getEBV() const
{
  bool b = ( theValue != xqp_decimal::parseInt(0) );
  return CREATE_BOOLITEM(b);
}

xqp_string DecimalItemNaive::getStringValue() const
{
  return NumConversions::decimalToStr(theValue);
}

xqp_string DecimalItemNaive::show() const
{
  return "xs:decimal(" + getStringValue() + ")";
}

bool DecimalItemNaive::isNaN() const {
  return theValue != theValue;
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

Item_t IntItemNaive::getType() const
{
  return CREATE_XS_TYPE("int");
}

bool IntItemNaive::equals ( Item_t item ) const
{
  return item->getIntValue() == theValue;
}
  
Item_t IntItemNaive::getEBV() const
{
  bool b = ( theValue != (int32_t)0 );
  return CREATE_BOOLITEM( b );
}

  xqp_string IntItemNaive::getStringValue() const
	{
    return NumConversions::intToStr(theValue);
	}

  xqp_string IntItemNaive::show() const
	{
		return "xs:int(" + getStringValue() + ")";
	}

/*******************************************************************************
  class IntegerItemNaive
********************************************************************************/
xqp_decimal IntegerItemNaive::getDecimalValue() const
{
  return Decimal::parseInteger ( theValue );
}

Item_t IntegerItemNaive::getType() const
{
  return CREATE_XS_TYPE("integer");
}

bool IntegerItemNaive::equals ( Item_t item ) const
{
  return item->getIntegerValue() == theValue;
}

Item_t IntegerItemNaive::getEBV() const
{
  bool b = ( theValue != xqp_integer::parseInt(0) );
  return CREATE_BOOLITEM( b );
}

  xqp_string IntegerItemNaive::getStringValue() const
	{
		return NumConversions::integerToStr(theValue);
  }

  xqp_string IntegerItemNaive::show() const
	{
		return "xs:integer(" + getStringValue() + ")";
	}
	/* end class IntegerItem */
	
	/* start class DoubleItem */
Item_t DoubleItemNaive::getType() const
{
  return CREATE_XS_TYPE("double");
}

bool DoubleItemNaive::equals ( Item_t item ) const
{
  return item->getDoubleValue() == theValue;
}

Item_t DoubleItemNaive::getEBV() const
{
  bool b;
  if (theValue.isNaN()) {
    b = false;
  } else {
    b = !theValue.isZero();
  }
  return CREATE_BOOLITEM(b);
}

xqp_string DoubleItemNaive::getStringValue() const
{
  return NumConversions::doubleToStr(theValue);
}

xqp_string DoubleItemNaive::show() const
{
  return "xs:double(" + getStringValue() + ")";
}

bool DoubleItemNaive::isNaN() const {
  return theValue.isNaN();
}

bool DoubleItemNaive::isPosOrNegInf() const {
  return theValue.isPosInf() || theValue.isNegInf();
}

  
/*******************************************************************************
  class FloatItemNaive
********************************************************************************/
Item_t FloatItemNaive::getType() const
{
  return CREATE_XS_TYPE("float");
}

bool FloatItemNaive::equals ( Item_t item ) const
{
  return item->getFloatValue() == theValue;
}

Item_t FloatItemNaive::getEBV() const
{
  bool b;
  if (theValue.isNaN()) {
    b = false;
  } else {
    b = !theValue.isZero();
  }
  return CREATE_BOOLITEM(b);
}

xqp_string FloatItemNaive::getStringValue() const
{
  return NumConversions::floatToStr(theValue);
}

xqp_string FloatItemNaive::show() const
{
  return "xs:float(" + getStringValue() + ")";
}

bool FloatItemNaive::isNaN() const {
  return theValue.isNaN();
}

bool FloatItemNaive::isPosOrNegInf() const {
  return theValue.isPosInf() || theValue.isNegInf();
}


/*******************************************************************************
  class BooleanItemNaive
********************************************************************************/
Item_t BooleanItemNaive::getType() const
{
  return CREATE_XS_TYPE("boolean");
}

bool BooleanItemNaive::equals ( Item_t item ) const
{
  return item->getBooleanValue() == theValue;
}

Item_t BooleanItemNaive::getEBV() const
{
  return this->getAtomizationValue();
}

xqp_string BooleanItemNaive::getStringValue() const
{
  if (theValue)
    return "true";
  else
    return "false";
}

xqp_string BooleanItemNaive::show() const
{
  return "xs:boolean(" + getStringValue() + ")";
}

/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
xqp_decimal NonPositiveIntegerItemNaive::getDecimalValue() const {
  return Decimal::parseInteger ( theValue );
}

Item_t NonPositiveIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("nonPositiveInteger");
}

bool NonPositiveIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getIntegerValue();
}

Item_t NonPositiveIntegerItemNaive::getEBV() const {
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
}

xqp_string NonPositiveIntegerItemNaive::getStringValue() const {
  return NumConversions::uintegerToStr(theValue);
}

xqp_string NonPositiveIntegerItemNaive::show() const {
  return "xs:nonPositiveInteger(" + getStringValue() + ")";
}

/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
xqp_decimal NegativeIntegerItemNaive::getDecimalValue() const {
  return Decimal::parseInteger ( theValue );
}

Item_t NegativeIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("negativeInteger");
}

bool NegativeIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getIntegerValue();
}

Item_t NegativeIntegerItemNaive::getEBV() const {
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
}

xqp_string NegativeIntegerItemNaive::getStringValue() const {
  return NumConversions::integerToStr(theValue);
}

xqp_string NegativeIntegerItemNaive::show() const {
  return "xs:negativeInteger(" + getStringValue() + ")";
}

/*******************************************************************************
  class LongItemNaive
********************************************************************************/
xqp_integer LongItemNaive::getIntegerValue() const {
  return Integer::parseLongLong(theValue);
}

xqp_decimal LongItemNaive::getDecimalValue() const {
  return Decimal::parseLongLong(theValue);
}

Item_t LongItemNaive::getType() const {
  return CREATE_XS_TYPE("long");
}

bool LongItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getLongValue();
}

Item_t LongItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string LongItemNaive::getStringValue() const {
  return NumConversions::longLongToStr(theValue);
}

xqp_string LongItemNaive::show() const {
  return "xs:long(" + getStringValue() + ")";
}

/*******************************************************************************
  class ShortItemNaive
********************************************************************************/
xqp_integer ShortItemNaive::getIntegerValue() const {
  return Integer::parseInt((int32_t)theValue); 
}

xqp_decimal ShortItemNaive::getDecimalValue() const {
  return Decimal::parseInt((int32_t)theValue);
}

xqp_long ShortItemNaive::getLongValue() const {
  return static_cast<xqp_long>(theValue);
}

xqp_int ShortItemNaive::getIntValue() const {
  return static_cast<xqp_int>(theValue);
}

Item_t ShortItemNaive::getType() const {
  return CREATE_XS_TYPE("short");
}

bool ShortItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getLongValue();
}

Item_t ShortItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string ShortItemNaive::getStringValue() const {
  return NumConversions::shortToStr(theValue);
}

xqp_string ShortItemNaive::show() const {
  return "xs:short(" + getStringValue() + ")";
}

/*******************************************************************************
  class ByteItemNaive
********************************************************************************/
xqp_integer ByteItemNaive::getIntegerValue() const {
  return Integer::parseInt((int32_t)theValue); 
}

xqp_decimal ByteItemNaive::getDecimalValue() const {
  return Decimal::parseInt((int32_t)theValue);
}

xqp_long ByteItemNaive::getLongValue() const {
  return static_cast<xqp_long>(theValue);
}

xqp_int ByteItemNaive::getIntValue() const {
  return static_cast<xqp_int>(theValue);
}

xqp_short ByteItemNaive::getShortValue() const {
  return static_cast<xqp_short>(theValue);
}

Item_t ByteItemNaive::getType() const {
  return CREATE_XS_TYPE("byte");
}

bool ByteItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getLongValue();
}

Item_t ByteItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string ByteItemNaive::getStringValue() const {
  return NumConversions::byteToStr(theValue);
}

xqp_string ByteItemNaive::show() const {
  return "xs:byte(" + getStringValue() + ")";
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

Item_t NonNegativeIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("nonNegativeInteger");
}

bool NonNegativeIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedIntegerValue();
}

Item_t NonNegativeIntegerItemNaive::getEBV() const {
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
}

xqp_string NonNegativeIntegerItemNaive::getStringValue() const {
  return NumConversions::uintegerToStr(theValue);
}

xqp_string NonNegativeIntegerItemNaive::show() const {
  return "xs:nonNegativeInteger(" + getStringValue() + ")";
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

Item_t UnsignedLongItemNaive::getType() const {
  return CREATE_XS_TYPE("unsignedLong");
}

bool UnsignedLongItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedLongValue();
}

Item_t UnsignedLongItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string UnsignedLongItemNaive::getStringValue() const {
  return NumConversions::ulongLongToStr(theValue);
}

xqp_string UnsignedLongItemNaive::show() const {
  return "xs:unsignedLong(" + getStringValue() + ")";
}

/*******************************************************************************
  class UnsignedIntItemNaive
********************************************************************************/
xqp_integer UnsignedIntItemNaive::getIntegerValue() const {
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

Item_t UnsignedIntItemNaive::getType() const {
  return CREATE_XS_TYPE("unsignedInt");
}

bool UnsignedIntItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedIntValue();
}

Item_t UnsignedIntItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string UnsignedIntItemNaive::getStringValue() const {
  return NumConversions::uintToStr(theValue);
}

xqp_string UnsignedIntItemNaive::show() const {
  return "xs:unsignedInt(" + getStringValue() + ")";
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

Item_t UnsignedShortItemNaive::getType() const {
  return CREATE_XS_TYPE("unsignedShort");
}

bool UnsignedShortItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedShortValue();
}

Item_t UnsignedShortItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string UnsignedShortItemNaive::getStringValue() const {
  return NumConversions::ushortToStr(theValue);
}

xqp_string UnsignedShortItemNaive::show() const {
  return "xs:unsignedShort(" + getStringValue() + ")";
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

Item_t UnsignedByteItemNaive::getType() const {
  return CREATE_XS_TYPE("unsignedByte");
}

bool UnsignedByteItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedByteValue();
}

Item_t UnsignedByteItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string UnsignedByteItemNaive::getStringValue() const {
  return NumConversions::ubyteToStr(theValue);
}

xqp_string UnsignedByteItemNaive::show() const {
  return "xs:unsignedByte(" + getStringValue() + ")";
}

/*******************************************************************************
  class PositiveIntegerItemNaive
********************************************************************************/
xqp_integer PositiveIntegerItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal PositiveIntegerItemNaive::getDecimalValue() const {
  return Decimal::parseInteger(theValue);
}

Item_t PositiveIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("positiveInteger");
}

bool PositiveIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedIntegerValue();
}

Item_t PositiveIntegerItemNaive::getEBV() const {
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
}

xqp_string PositiveIntegerItemNaive::getStringValue() const {
  return NumConversions::uintegerToStr(theValue);
}

xqp_string PositiveIntegerItemNaive::show() const {
  return "xs:positiveInteger(" + getStringValue() + ")";
}

/*******************************************************************************
 * class DateTimeItem
 *******************************************************************************/
int DateTimeItemNaive::createFromDateAndTime(const xqp_date& date, const xqp_time& time, Item_t& item)
{
  DateTimeItemNaive* dtin = new DateTimeItemNaive();
  int result = DateTime::createDateTime(date, time, dtin->theValue);
  item = dtin;
  return result;
}

xqp_string DateTimeItemNaive::getStringValue() const
{
  return theValue->toString();
}
  
Item_t DateTimeItemNaive::getType() const
{
  switch (theValue->getFacet())
  {
  case DateTime::DATE_FACET:
    return CREATE_XS_TYPE("date");
    break;
      
  case DateTime::TIME_FACET:
    return CREATE_XS_TYPE("time");
    break;
    
  case DateTime::GYEARMONTH_FACET:
    return CREATE_XS_TYPE("gYearMonth");
    break;
    
  case DateTime::GYEAR_FACET:
    return CREATE_XS_TYPE("gYear");
    break;
    
  case DateTime::GMONTH_FACET:
    return CREATE_XS_TYPE("gMonth");
    break;

  case DateTime::GMONTHDAY_FACET:
    return CREATE_XS_TYPE("gMonthDay");
    break;
    
  case DateTime::GDAY_FACET:
    return CREATE_XS_TYPE("gDay");
    break;

  default:
  case DateTime::DATETIME_FACET:
    return CREATE_XS_TYPE("dateTime");
    break;
  }
}

bool DateTimeItemNaive::equals(Item_t aItem) const
{
  // TODO: get somehow the RuntimeCB to extract the implicit timezone
  try {
    return 0 == theValue->compare(*aItem->getDateTimeValue(), 0);
    //                                   ZORBA_FOR_CURRENT_THREAD()->get_base_dynamic_context()->get_implicit_timezone());
  } catch (InvalidTimezoneException) {
    ZORBA_ERROR(ZorbaError::FODT0003);
    return false;
  }
}

Item_t DateTimeItemNaive::getEBV() const
{
  // TODO:
  return NULL;
}

xqp_string DateTimeItemNaive::show() const
{
  return theValue->toString();
}

/*******************************************************************************
 * class Duration
 *******************************************************************************/
xqp_duration DurationItemNaive::getDurationValue() const
{
  return theValue;
}

xqp_string DurationItemNaive::getStringValue() const
{
  return theValue->toString();
}
  
Item_t DurationItemNaive::getType() const
{
  // get the effective type or subtype
  DayTimeDuration* dtd = dynamic_cast<DayTimeDuration*>(theValue.getp());
  if (dtd != NULL)
    return CREATE_XS_TYPE("dayTimeDuration");
  
  YearMonthDuration* ymd = dynamic_cast<YearMonthDuration*>(theValue.getp());
  if (ymd != NULL)
    return CREATE_XS_TYPE("yearMonthDuration");
  
  return CREATE_XS_TYPE("duration");
}

bool DurationItemNaive::equals(Item_t aItem) const
{
  return *theValue == *aItem->getDurationValue();
}

Item_t DurationItemNaive::getEBV() const
{
  // TODO:
  return NULL;
}

xqp_string DurationItemNaive::show() const
{
  return theValue->toString();
}

/*******************************************************************************
 * class DayTimeDuration
 *******************************************************************************/
xqp_dayTimeDuration DayTimeDurationItemNaive::getDayTimeDurationValue() const
{
  return theValue;
}

xqp_string DayTimeDurationItemNaive::getStringValue() const
{
  return theValue->toString();
}
  
Item_t DayTimeDurationItemNaive::getType() const
{
  return CREATE_XS_TYPE("dayTimeDuration");
}

bool DayTimeDurationItemNaive::equals(Item_t aItem) const
{
  return *theValue == *aItem->getDayTimeDurationValue();
}

Item_t DayTimeDurationItemNaive::getEBV() const
{
  // TODO:
  return NULL;
}

xqp_string DayTimeDurationItemNaive::show() const
{
  return theValue->toString();
}

/*******************************************************************************
 * class YearMonthDuration
 *******************************************************************************/
xqp_yearMonthDuration YearMonthDurationItemNaive::getYearMonthDurationValue() const
{
  return theValue;
}

xqp_string YearMonthDurationItemNaive::getStringValue() const
{
  return theValue->toString();
}
  
Item_t YearMonthDurationItemNaive::getType() const
{
  return CREATE_XS_TYPE("yearMonthDuration");
}

bool YearMonthDurationItemNaive::equals(Item_t aItem) const
{
  return *theValue == *aItem->getYearMonthDurationValue();
}

Item_t YearMonthDurationItemNaive::getEBV() const
{
  // TODO:
  return NULL;
}

xqp_string YearMonthDurationItemNaive::show() const
{
  return theValue->toString();
}

} // namespace store
} // namespace zorba

