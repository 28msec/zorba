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
#include "zorbatypes/numconversions.h"
#include "store/api/item.h"
#include "store/minimal/min_node_items.h"

#include "util/Assert.h"
#include "errors/error_manager.h"
#include "compiler/parser/query_loc.h"
#include "util/hashfun.h"
#include "runtime/api/runtimecb.h"
#include "system/globalenv.h"

#include "store/minimal/min_atomic_items.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/collection.h"
//#include "store/naive/qname_pool.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_item_factory.h"
#include "store/minimal/min_store_defs.h"
#include "store/api/item_iterator.h"
#include "context/dynamic_context.h"


#define CREATE_XS_TYPE(aType) \
  GET_STORE().getItemFactory()->createQName(SimpleStore::XS_URI, "xs", aType);

#define CREATE_BOOLITEM(aValue) \
  GET_STORE().getItemFactory()->createBoolean(aValue)

namespace zorba { 
  namespace store {


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

//void QNameItemImpl::free()
//{
//  GET_STORE().getQNamePool().remove(this);
//}


Item* QNameItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_QNAME];
}

uint32_t QNameItemImpl::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return hashfun::h32(thePrefix->str(),
                      hashfun::h32(theLocal->str(),
                                   hashfun::h32(theNamespace->str())));
}


bool QNameItemImpl::equals(
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation) const
{
  return (this == item ||
          (theNamespace->byteEqual(*item->getNamespace()) &&
           theLocal->byteEqual(*item->getLocalName())));
}


Item_t QNameItemImpl::getEBV( ) const
{
  ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for QName!");
  return NULL;
}


xqpStringStore_t QNameItemImpl::getStringValue( ) const
{
  if (thePrefix->empty())
    return theLocal;
  else
    return new xqpStringStore(thePrefix->str() + ":" + theLocal->str());
}


bool QNameItemImpl::isId() const
{
  if (thePrefix->byteEqual("xml", 3) &&
      theLocal->byteEqual("id", 2))
    return true;

  return false;
}


bool QNameItemImpl::isBaseUri() const
{
  if (thePrefix->byteEqual("xml", 3) &&
      theLocal->byteEqual("base", 4))
    return true;

  return false;
}


xqp_string QNameItemImpl::show() const
{
  return "xs:QName(" + theNamespace->str() + "," + thePrefix->str() + "," +
                       theLocal->str() + ")";
}


/*******************************************************************************
  class NCNameItemImpl
********************************************************************************/
Item* NCNameItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_NCNAME];
}

uint32_t NCNameItemImpl::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash();
}

bool NCNameItemImpl::equals(
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue);
}

Item_t NCNameItemImpl::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  return CREATE_BOOLITEM(b);
}

xqp_string NCNameItemImpl::show() const
{
  return "xs:NCName(" + theValue->str() + ")";
}


/*******************************************************************************
  class NCNameItemImpl
********************************************************************************/
Item* IDItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_ID];
}


xqp_string IDItemImpl::show() const
{
  return "xs:ID(" + theValue->str() + ")";
}


/*******************************************************************************
  class AnyUriItemNaive
********************************************************************************/
Item* AnyUriItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_ANY_URI];
}

uint32_t AnyUriItemImpl::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash();
}


bool AnyUriItemImpl::equals(
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue.getp());
}


Item_t AnyUriItemImpl::getEBV() const
{
  bool b = ! (theValue->str() == "");
  return CREATE_BOOLITEM(b);
}


xqp_string AnyUriItemImpl::show() const
{
  return "xs:anyURI(" + theValue->str() + ")";
}


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
Item* UntypedAtomicItemImpl::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}

uint32_t UntypedAtomicItemImpl::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash();
}

bool UntypedAtomicItemImpl::equals(
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue.getp());
}

Item_t UntypedAtomicItemImpl::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  return CREATE_BOOLITEM(b);
}

xqp_string UntypedAtomicItemImpl::show() const
{
  return "xs:untypedAtomic(" + theValue->str() + ")";
}


/*******************************************************************************
  class StingItemNaive
********************************************************************************/
Item* StringItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_STRING];
}

uint32_t StringItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash(aCollation);
}

bool StringItemNaive::equals(
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation) const
{
  return item->getStringValueP()->equals(theValue.getp());
}
  
Item_t StringItemNaive::getEBV() const
{
  bool b = ! ( theValue->str() == "" );
  return CREATE_BOOLITEM(b);
}

xqp_string StringItemNaive::show() const
{
  return "xs:string(" + theValue->str() + ")";
}


/*******************************************************************************
  class DecimalItemNaive
********************************************************************************/
Item* DecimalItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_DECIMAL];
}

bool DecimalItemNaive::equals(
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return item->getDecimalValue() == theValue;
}

Item_t DecimalItemNaive::getEBV() const
{
  bool b = ( theValue != xqp_decimal::parseInt(0) );
  return CREATE_BOOLITEM(b);
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
DecimalItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* IntItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INT];
}

bool IntItemNaive::equals (
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return item->getIntValue() == theValue;
}
  
Item_t IntItemNaive::getEBV() const
{
  bool b = ( theValue != (int32_t)0 );
  return CREATE_BOOLITEM( b );
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
IntItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* IntegerItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_INTEGER];
}

bool IntegerItemNaive::equals (
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation ) const
{
  return item->getIntegerValue() == theValue;
}

Item_t IntegerItemNaive::getEBV() const
{
  bool b = ( theValue != xqp_integer::parseInt(0) );
  return CREATE_BOOLITEM( b );
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
  IntegerItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
  {
    return theValue.hash();
  }
	
	/* start class DoubleItem */
Item* DoubleItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_DOUBLE];
}

bool DoubleItemNaive::equals (
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
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

xqpStringStore_t DoubleItemNaive::getStringValue() const
{
  return NumConversions::doubleToStr(theValue).getStore();
}

xqp_string DoubleItemNaive::show() const
{
  return "xs:double(" + getStringValue()->str() + ")";
}

bool DoubleItemNaive::isNaN() const {
  return theValue.isNaN();
}

bool DoubleItemNaive::isPosOrNegInf() const {
  return theValue.isPosInf() || theValue.isNegInf();
}

uint32_t
DoubleItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue.hash();
}
  
/*******************************************************************************
  class FloatItemNaive
********************************************************************************/
Item* FloatItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_FLOAT];
}

bool FloatItemNaive::equals (
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation ) const
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
FloatItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class BooleanItemNaive
********************************************************************************/
Item* BooleanItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_BOOLEAN];
}

bool BooleanItemNaive::equals (
    const Item* item,
    RuntimeCB* aRuntimeCB,
    XQPCollator* aCollation ) const
{
  return item->getBooleanValue() == theValue;
}

uint32_t BooleanItemNaive::hash ( RuntimeCB* aRuntimeCB, XQPCollator* aCollation ) const
{
  return theValue?0:1;
}

Item_t BooleanItemNaive::getEBV() const
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

Item* NonPositiveIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NON_POSITIVE_INTEGER];
}

bool NonPositiveIntegerItemNaive::equals(
   const Item* aItem,
   RuntimeCB* aRuntimeCB,
   XQPCollator* coll ) const
{
  return theValue == aItem->getIntegerValue();
}

Item_t NonPositiveIntegerItemNaive::getEBV() const 
{
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
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
NonPositiveIntegerItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* NegativeIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_NEGATIVE_INTEGER];
}

bool NegativeIntegerItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const 
{
  return theValue == aItem->getIntegerValue();
}

Item_t NegativeIntegerItemNaive::getEBV() const 
{
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
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
NegativeIntegerItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* LongItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_LONG];
}

bool LongItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const 
{
  return theValue == aItem->getLongValue();
}

Item_t LongItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
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
LongItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* ShortItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_SHORT];
}

bool ShortItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return theValue == aItem->getLongValue();
}

Item_t ShortItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
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
ShortItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* ByteItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_BYTE];
}

bool ByteItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return theValue == aItem->getLongValue();
}

Item_t ByteItemNaive::getEBV() const 
{
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
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
ByteItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* NonNegativeIntegerItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_NON_NEGATIVE_INTEGER];
}

bool NonNegativeIntegerItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return theValue == aItem->getUnsignedIntegerValue();
}

Item_t NonNegativeIntegerItemNaive::getEBV() const {
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
}

xqpStringStore_t NonNegativeIntegerItemNaive::getStringValue() const 
{
  return NumConversions::uintegerToStr(theValue).getStore();
}

xqp_string NonNegativeIntegerItemNaive::show() const {
  return "xs:nonNegativeInteger(" + getStringValue()->str() + ")";
}

uint32_t
NonNegativeIntegerItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* UnsignedLongItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_LONG];
}

bool UnsignedLongItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedLongValue();
}

Item_t UnsignedLongItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqpStringStore_t UnsignedLongItemNaive::getStringValue() const {
  return NumConversions::ulongLongToStr(theValue).getStore();
}

xqp_string UnsignedLongItemNaive::show() const {
  return "xs:unsignedLong(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedLongItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* UnsignedIntItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_INT];
}

bool UnsignedIntItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedIntValue();
}

Item_t UnsignedIntItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqpStringStore_t UnsignedIntItemNaive::getStringValue() const {
  return NumConversions::uintToStr(theValue).getStore();
}

xqp_string UnsignedIntItemNaive::show() const {
  return "xs:unsignedInt(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedIntItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* UnsignedShortItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_SHORT];
}

bool UnsignedShortItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedShortValue();
}

Item_t UnsignedShortItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqpStringStore_t UnsignedShortItemNaive::getStringValue() const {
  return NumConversions::ushortToStr(theValue).getStore();
}

xqp_string UnsignedShortItemNaive::show() const {
  return "xs:unsignedShort(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedShortItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* UnsignedByteItemNaive::getType() const {
  return GET_STORE().theSchemaTypeNames[XS_UNSIGNED_BYTE];
}

bool UnsignedByteItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const {
  return theValue == aItem->getUnsignedByteValue();
}

Item_t UnsignedByteItemNaive::getEBV() const {
  bool b = (theValue != 0);
  return CREATE_BOOLITEM(b);
}

xqpStringStore_t UnsignedByteItemNaive::getStringValue() const {
  return NumConversions::ubyteToStr(theValue).getStore();
}

xqp_string UnsignedByteItemNaive::show() const {
  return "xs:unsignedByte(" + getStringValue()->str() + ")";
}

uint32_t
UnsignedByteItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
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

Item* PositiveIntegerItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_POSITIVE_INTEGER];
}

bool PositiveIntegerItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const 
{
  return theValue == aItem->getUnsignedIntegerValue();
}

Item_t PositiveIntegerItemNaive::getEBV() const 
{
  bool b = (theValue != xqp_integer::parseInt(0));
  return CREATE_BOOLITEM(b);
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
PositiveIntegerItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class Base64BinaryItemNaive
********************************************************************************/
Item* Base64BinaryItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_BASE64BINARY];
}

bool Base64BinaryItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
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
Base64BinaryItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue.hash();
}

/*******************************************************************************
  class HexBinaryItemNaive
********************************************************************************/
Item* HexBinaryItemNaive::getType() const 
{
  return GET_STORE().theSchemaTypeNames[XS_HEXBINARY];
}

bool HexBinaryItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
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
HexBinaryItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue.hash();
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

xqpStringStore_t DateTimeItemNaive::getStringValue() const
{
  return theValue->toString().getStore();
}
  
Item* DateTimeItemNaive::getType() const
{
  switch (theValue->getFacet())
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

bool DateTimeItemNaive::equals(const Item* aItem, RuntimeCB* aRuntimeCB, XQPCollator* coll ) const
{
  try {
    return 0 == theValue->compare(*aItem->getDateTimeValue(), 
                                   aRuntimeCB->theDynamicContext->get_implicit_timezone());
  } catch (InvalidTimezoneException) {
    ZORBA_ERROR(FODT0003);
    return false;
  }
}

uint32_t DateTimeItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash(0);
}

Item_t DateTimeItemNaive::getEBV() const
{
  switch (theValue->getFacet())
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
  return theValue->toString();
}

/*******************************************************************************
 * class Duration
 *******************************************************************************/
xqp_duration DurationItemNaive::getDurationValue() const
{
  return theValue;
}

xqp_yearMonthDuration DurationItemNaive::getYearMonthDurationValue() const
{
  YearMonthDuration* ymd = dynamic_cast<YearMonthDuration*>(theValue.getp());
  if (ymd != NULL)
    return theValue;
  else
    return AtomicItem::getYearMonthDurationValue();
}

xqp_dayTimeDuration DurationItemNaive::getDayTimeDurationValue() const
{
  DayTimeDuration* dtd = dynamic_cast<DayTimeDuration*>(theValue.getp());
  if (dtd != NULL)
    return theValue;
  else
    return AtomicItem::getDayTimeDurationValue();
}

xqpStringStore_t DurationItemNaive::getStringValue() const
{
  return theValue->toString().getStore();
}
  
Item* DurationItemNaive::getType() const
{
  // get the effective type or subtype
  DayTimeDuration* dtd = dynamic_cast<DayTimeDuration*>(theValue.getp());
  if (dtd != NULL)
    return GET_STORE().theSchemaTypeNames[XS_DT_DURATION];
  
  YearMonthDuration* ymd = dynamic_cast<YearMonthDuration*>(theValue.getp());
  if (ymd != NULL)
    return GET_STORE().theSchemaTypeNames[XS_YM_DURATION];
  
  return GET_STORE().theSchemaTypeNames[XS_DURATION];
}

bool DurationItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return *theValue == *aItem->getDurationValue();
}

Item_t DurationItemNaive::getEBV() const
{
  ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for Duration!");
  return NULL;
}

xqp_string DurationItemNaive::show() const
{
  return theValue->toString().getStore();
}

uint32_t DurationItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash();
}

/*******************************************************************************
 * class DayTimeDuration
 *******************************************************************************/
xqp_dayTimeDuration DayTimeDurationItemNaive::getDayTimeDurationValue() const
{
  return theValue;
}

xqpStringStore_t DayTimeDurationItemNaive::getStringValue() const
{
  return theValue->toString().getStore();
}
  
Item* DayTimeDurationItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_DT_DURATION];
}

bool DayTimeDurationItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return *theValue == *aItem->getDayTimeDurationValue();
}

Item_t DayTimeDurationItemNaive::getEBV() const
{
  ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for DayTimeDuration!");
  return NULL;
}

xqp_string DayTimeDurationItemNaive::show() const
{
  return theValue->toString();
}

uint32_t DayTimeDurationItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash();
}

/*******************************************************************************
 * class YearMonthDuration
 *******************************************************************************/
xqp_yearMonthDuration YearMonthDurationItemNaive::getYearMonthDurationValue() const
{
  return theValue;
}

xqpStringStore_t YearMonthDurationItemNaive::getStringValue() const
{
  return theValue->toString().getStore();
}
  
Item* YearMonthDurationItemNaive::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_YM_DURATION];
}

bool YearMonthDurationItemNaive::equals(
    const Item* aItem,
    RuntimeCB* aRuntimeCB,
    XQPCollator* coll ) const
{
  return *theValue == *aItem->getYearMonthDurationValue();
}

Item_t YearMonthDurationItemNaive::getEBV() const
{
  ZORBA_ERROR_DESC( FORG0006, "Effective Boolean Value is not defined for YearMonthDuration!");
  return NULL;
}

xqp_string YearMonthDurationItemNaive::show() const
{
  return theValue->toString();
}

uint32_t YearMonthDurationItemNaive::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  return theValue->hash();
}

} // namespace store
} // namespace zorba

