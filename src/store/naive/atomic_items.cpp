/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- */

/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: David Graf, Donald Kossmann, Tim Kraska, Markos zaharioudakis
 */

#include "util/numconversions.h"
#include "util/hashfun.h"
#include "util/Assert.h"
#include "errors/error_factory.h"
#include "store/naive/atomic_items.h"
#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"

#define CREATE_XS_TYPE(aType) \
  GET_STORE().getItemFactory().createQName(SimpleStore::XS_URI, "xs", aType);

#define CREATE_BOOLITEM(aValue) \
  GET_STORE().getItemFactory().createBoolean(aValue)

namespace xqp
{

/*******************************************************************************
  class QNameItemImpl
********************************************************************************/

void QNameItemImpl::free()
{
  reinterpret_cast<SimpleStore*>(&Store::getInstance())->getQNamePool().remove(this);
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
  return (this == item.get_ptr() ||
          (theNamespace->byteEqual(*item->getNamespace().getStore()) &&
           theLocal->byteEqual(*item->getLocalName().getStore())));
}


Item_t QNameItemImpl::getEBV( ) const
{
  ZORBA_ERROR_ALERT(AlertCodes::FORG0006,
      NULL, false, "Effective Boolean Value is not defined for QName!");
  return NULL;
}


xqp_string QNameItemImpl::getStringProperty( ) const
{
  return *thePrefix != "" ? *thePrefix + ":" + *theLocal : *theLocal;
}


xqp_string QNameItemImpl::show() const
{
  return "xs:QName(" + *theNamespace + "," + *thePrefix + "," + *theLocal + ")";
}


/*******************************************************************************
  class AnyUriItemNaive
********************************************************************************/
Item_t AnyUriItemImpl::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "anyURI");
}

uint32_t AnyUriItemImpl::hash() const
{
  return theValue->hash();
}


bool AnyUriItemImpl::equals(Item_t item) const
{
  return item->getStringValue() == xqp_string(theValue);
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
  class UntypedAtomicItemNaive
********************************************************************************/
Item_t UntypedAtomicItemNaive::getType() const
{
  return static_cast<SimpleStore*>(&Store::getInstance())->theUntypedAtomicType;
}

uint32_t UntypedAtomicItemNaive::hash() const
{
  return theValue->hash();
}

bool UntypedAtomicItemNaive::equals(Item_t item) const
{
  return item->getStringValue() == xqp_string(theValue);
}

Item_t UntypedAtomicItemNaive::getEBV() const
{
  bool b = ! ( *theValue == "" );
  return CREATE_BOOLITEM(b);
}

xqp_string UntypedAtomicItemNaive::show() const
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
  return item->getStringValue() == xqp_string(theValue);
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
  bool b = ( theValue != 0 );
  return CREATE_BOOLITEM(b);
}

xqp_string DecimalItemNaive::getStringProperty() const
{
  return NumConversions::decimalToStr(theValue);
}

xqp_string DecimalItemNaive::show() const
{
  return "xs:decimal(" + getStringProperty() + ")";
}

/*******************************************************************************
  class IntItemNaive
********************************************************************************/
xqp_integer IntItemNaive::getIntegerValue() const
{
  return static_cast<xqp_integer> ( theValue );
}

xqp_decimal IntItemNaive::getDecimalValue() const
{
  return static_cast<xqp_decimal> ( theValue );
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
  bool b = ( theValue != 0 );
  return CREATE_BOOLITEM( b );
}

  xqp_string IntItemNaive::getStringProperty() const
	{
    return NumConversions::intToStr(theValue);
	}

  xqp_string IntItemNaive::show() const
	{
		return "xs:int(" + getStringProperty() + ")";
	}

/*******************************************************************************
  class IntegerItemNaive
********************************************************************************/
long double IntegerItemNaive::getDecimalValue() const
{
  return static_cast<xqp_decimal> ( theValue );
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
  bool b = ( theValue != 0 );
  return CREATE_BOOLITEM( b );
}

  xqp_string IntegerItemNaive::getStringProperty() const
	{
		return NumConversions::integerToStr(theValue);
  }

  xqp_string IntegerItemNaive::show() const
	{
		return "xs:integer(" + getStringProperty() + ")";
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
  if (theValue != theValue)
    // NaN case
    b = false;
  else
    b = ( theValue != 0 );
  return CREATE_BOOLITEM(b);
}

  xqp_string DoubleItemNaive::getStringProperty() const
	{
		return NumConversions::doubleToStr(theValue);
	}

  xqp_string DoubleItemNaive::show() const
	{
		return "xs:double(" + getStringProperty() + ")";
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
    if (theValue != theValue)
      // NaN case
      b = false;
    else
      b = ( theValue != 0 );
    return CREATE_BOOLITEM(b);
	}

  xqp_string FloatItemNaive::getStringProperty() const
	{
		return NumConversions::floatToStr(theValue);
	}

  xqp_string FloatItemNaive::show() const
	{
		return "xs:float(" + getStringProperty() + ")";
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

xqp_string BooleanItemNaive::getStringProperty() const
{
  if (theValue)
    return "true";
  else
    return "false";
}

xqp_string BooleanItemNaive::show() const
{
  return "xs:boolean(" + getStringProperty() + ")";
}

/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
xqp_decimal NonPositiveIntegerItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal> ( theValue );
}

Item_t NonPositiveIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("nonPositiveInteger");
}

bool NonPositiveIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getIntegerValue();
}

Item_t NonPositiveIntegerItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string NonPositiveIntegerItemNaive::getStringProperty() const {
  return NumConversions::uintegerToStr(theValue);
}

xqp_string NonPositiveIntegerItemNaive::show() const {
  return "xs:nonPositiveInteger(" + getStringProperty() + ")";
}

/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
xqp_decimal NegativeIntegerItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal> ( theValue );
}

Item_t NegativeIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("negativeInteger");
}

bool NegativeIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getIntegerValue();
}

Item_t NegativeIntegerItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string NegativeIntegerItemNaive::getStringProperty() const {
  return NumConversions::integerToStr(theValue);
}

xqp_string NegativeIntegerItemNaive::show() const {
  return "xs:negativeInteger(" + getStringProperty() + ")";
}

/*******************************************************************************
  class LongItemNaive
********************************************************************************/
xqp_integer LongItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal LongItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
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

xqp_string LongItemNaive::getStringProperty() const {
  return NumConversions::longToStr(theValue);
}

xqp_string LongItemNaive::show() const {
  return "xs:long(" + getStringProperty() + ")";
}

/*******************************************************************************
  class ShortItemNaive
********************************************************************************/
xqp_integer ShortItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue); 
}

xqp_decimal ShortItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
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

xqp_string ShortItemNaive::getStringProperty() const {
  return NumConversions::shortToStr(theValue);
}

xqp_string ShortItemNaive::show() const {
  return "xs:short(" + getStringProperty() + ")";
}

/*******************************************************************************
  class ByteItemNaive
********************************************************************************/
xqp_integer ByteItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue); 
}

xqp_decimal ByteItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
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

xqp_string ByteItemNaive::getStringProperty() const {
  return NumConversions::byteToStr(theValue);
}

xqp_string ByteItemNaive::show() const {
  return "xs:byte(" + getStringProperty() + ")";
}


/*******************************************************************************
  class NonNegativeINtegerItemNaive
********************************************************************************/
xqp_integer NonNegativeIntegerItemNaive::getIntegerValue() const {
 return static_cast<xqp_integer>(theValue); 
}

xqp_decimal NonNegativeIntegerItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
}

Item_t NonNegativeIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("nonNegativeInteger");
}

bool NonNegativeIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedIntegerValue();
}

Item_t NonNegativeIntegerItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string NonNegativeIntegerItemNaive::getStringProperty() const {
  return NumConversions::uintegerToStr(theValue);
}

xqp_string NonNegativeIntegerItemNaive::show() const {
  return "xs:nonNegativeInteger(" + getStringProperty() + ")";
}


/*******************************************************************************
  class UnsignedLongItemNaive
********************************************************************************/
xqp_integer UnsignedLongItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal UnsignedLongItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
}

xqp_uinteger UnsignedLongItemNaive::getUnsignedIntegerValue() const {
  return static_cast<xqp_uinteger>(theValue);
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

xqp_string UnsignedLongItemNaive::getStringProperty() const {
  return NumConversions::ulongToStr(theValue);
}

xqp_string UnsignedLongItemNaive::show() const {
  return "xs:unsignedLong(" + getStringProperty() + ")";
}

/*******************************************************************************
  class UnsignedIntItemNaive
********************************************************************************/
xqp_integer UnsignedIntItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal UnsignedIntItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
}

xqp_uinteger UnsignedIntItemNaive::getUnsignedIntegerValue() const {
  return static_cast<xqp_uinteger>(theValue);
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

xqp_string UnsignedIntItemNaive::getStringProperty() const {
  return NumConversions::uintToStr(theValue);
}

xqp_string UnsignedIntItemNaive::show() const {
  return "xs:unsignedInt(" + getStringProperty() + ")";
}


/*******************************************************************************
  class UnsignedShortItemNaive
********************************************************************************/
xqp_integer UnsignedShortItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal UnsignedShortItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
}

xqp_uinteger UnsignedShortItemNaive::getUnsignedIntegerValue() const {
  return static_cast<xqp_uinteger>(theValue);
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

xqp_string UnsignedShortItemNaive::getStringProperty() const {
  return NumConversions::ushortToStr(theValue);
}

xqp_string UnsignedShortItemNaive::show() const {
  return "xs:unsignedShort(" + getStringProperty() + ")";
}

/*******************************************************************************
  class UnsignedByteItemNaive
********************************************************************************/
xqp_integer UnsignedByteItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal UnsignedByteItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
}

xqp_uinteger UnsignedByteItemNaive::getUnsignedIntegerValue() const {
  return static_cast<xqp_uinteger>(theValue);
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

xqp_string UnsignedByteItemNaive::getStringProperty() const {
  return NumConversions::ubyteToStr(theValue);
}

xqp_string UnsignedByteItemNaive::show() const {
  return "xs:unsignedByte(" + getStringProperty() + ")";
}

/*******************************************************************************
  class PositiveIntegerItemNaive
********************************************************************************/
xqp_integer PositiveIntegerItemNaive::getIntegerValue() const {
  return static_cast<xqp_integer>(theValue);
}

xqp_decimal PositiveIntegerItemNaive::getDecimalValue() const {
  return static_cast<xqp_decimal>(theValue);
}

Item_t PositiveIntegerItemNaive::getType() const {
  return CREATE_XS_TYPE("positiveInteger");
}

bool PositiveIntegerItemNaive::equals(Item_t aItem) const {
  return theValue == aItem->getUnsignedIntegerValue();
}

Item_t PositiveIntegerItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqp_string PositiveIntegerItemNaive::getStringProperty() const {
  return NumConversions::uintegerToStr(theValue);
}

xqp_string PositiveIntegerItemNaive::show() const {
  return "xs:positiveInteger(" + getStringProperty() + ")";
}

}/* namespace xqp */
