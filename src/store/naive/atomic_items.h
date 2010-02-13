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
#ifndef ZORBA_STORE_ATOMIC_ITEMS_H
#define ZORBA_STORE_ATOMIC_ITEMS_H

#include "store/api/item.h"

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"
#include "zorbatypes/datetime.h"

#include "zorbaerrors/errors.h"


namespace zorba
{

namespace simplestore
{

/*******************************************************************************

********************************************************************************/
class AtomicItem : public store::Item
{
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
public:
  AtomicItem() : store::Item() { }

#else

protected:
  SYNC_CODE(RCLock  theRCLock;)

public:
  AtomicItem() : store::Item() { SYNC_CODE(theRCLockPtr = &theRCLock;) }
#endif

  ~AtomicItem() {}

  bool isNode() const   { return false; }
  bool isAtomic() const { return true; }
  bool isPul() const    { return false; }
  bool isTuple() const  { return false; }
  bool isError() const  { return false; }

  store::Item_t getAtomizationValue() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
};


/*******************************************************************************
  class UserTypedAtomicItem
********************************************************************************/
class UserTypedAtomicItemImpl : public AtomicItem
{
protected:
  store::Item_t theBaseItem;
  store::Item_t theTypeName;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  UserTypedAtomicItemImpl(
        store::Item_t& baseItem,
        store::Item_t& typeName)
  {
    theBaseItem.transfer(baseItem);
    theTypeName.transfer(typeName);
  }

  UserTypedAtomicItemImpl() {}

public:
  const store::Item* getBaseItem() const { return theBaseItem; }

  store::Item* getType() const { return theTypeName.getp(); }

  uint32_t hash(long timezone = 0, const XQPCollator* collation = 0) const
  {
    return theBaseItem->hash(timezone, collation);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    if (other->getBaseItem() == NULL)
      return theBaseItem->equals(other, timezone, collation);
    else
      return theBaseItem->equals(other->getBaseItem(), timezone, collation);
  }

  long compare(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    if (other->getBaseItem() == NULL)
      return theBaseItem->compare(other, timezone, collation);
    else
      return theBaseItem->compare(other->getBaseItem(), timezone, collation);
  }

  store::Item_t getEBV() const { return theBaseItem->getEBV(); }

  xqpStringStore_t getStringValue() const { return theBaseItem->getStringValue(); }

  void getStringValue(xqpStringStore_t& strval) const 
  {
    theBaseItem->getStringValue(strval);
  }

  void getStringValue(std::string& buf) const { theBaseItem->getStringValue(buf); }

  xqpStringStore* getString() const { return theBaseItem->getString(); }

  xqp_base64Binary getBase64BinaryValue() const { return theBaseItem->getBase64BinaryValue(); }

  xqp_hexBinary getHexBinaryValue() const { return theBaseItem->getHexBinaryValue(); }

  bool getBooleanValue() const { return theBaseItem->getBooleanValue(); }

  const xqp_double& getDoubleValue() const { return theBaseItem->getDoubleValue(); }

  const xqp_float& getFloatValue() const { return theBaseItem->getFloatValue(); }

  xqp_decimal getDecimalValue() const { return theBaseItem->getDecimalValue(); }

  xqp_integer getIntegerValue() const { return theBaseItem->getIntegerValue(); }

  xqp_uinteger getUnsignedIntegerValue() const { return theBaseItem->getUnsignedIntegerValue(); }

  xqp_long getLongValue() const { return theBaseItem->getLongValue(); }

  xqp_int getIntValue() const { return theBaseItem->getIntValue(); }

  xqp_short getShortValue() const { return theBaseItem->getShortValue(); }

  xqp_byte getByteValue() const { return theBaseItem->getByteValue(); }

  xqp_ulong getUnsignedLongValue() const { return theBaseItem->getUnsignedLongValue(); }

  xqp_uint getUnsignedIntValue() const { return theBaseItem->getUnsignedIntValue(); }

  xqp_ushort getUnsignedShortValue() const { return theBaseItem->getUnsignedShortValue(); }

  xqp_ubyte getUnsignedByteValue() const { return theBaseItem->getUnsignedByteValue(); }

  bool isNaN() const { return theBaseItem->isNaN(); }

  bool isPosOrNegInf() const { return theBaseItem->isPosOrNegInf(); }

  const xqp_dateTime& getDateTimeValue() const { return theBaseItem->getDateTimeValue(); }

  const xqp_date& getDateValue() const { return theBaseItem->getDateValue(); }

  const xqp_time& getTimeValue() const { return theBaseItem->getTimeValue(); }

  const xqp_gYearMonth& getGYearMonthValue() const { return theBaseItem->getGYearMonthValue(); }

  const xqp_gYear& getGYearValue() const { return theBaseItem->getGYearValue(); }

  const xqp_gMonth& getGMonthValue() const { return theBaseItem->getGMonthValue(); }

  const xqp_gMonthDay& getGMonthDayValue() const { return theBaseItem->getGMonthDayValue(); }

  const xqp_gDay& getGDayValue() const { return theBaseItem->getGDayValue(); }

  const xqp_duration& getDurationValue() const { return theBaseItem->getDurationValue(); }

  const xqp_dayTimeDuration& getDayTimeDurationValue() const { return theBaseItem->getDayTimeDurationValue(); }

  const xqp_yearMonthDuration& getYearMonthDurationValue() const { return theBaseItem->getYearMonthDurationValue(); }

  std::vector<xqp_string> getStringVectorValue() const { return theBaseItem->getStringVectorValue(); }

  xqp_string show() const { return theBaseItem->show(); }
};


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
class UntypedAtomicItemImpl : public AtomicItem
{
protected:
  xqpStringStore_t theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  UntypedAtomicItemImpl(xqpStringStore_t& value) { theValue.transfer(value); }

  UntypedAtomicItemImpl() {}

public:
  store::Item* getType( ) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue->byteEqual(other->getString());
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const { return theValue; }
  xqpStringStore* getStringValueP() const { return theValue.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theValue; }
  void getStringValue(std::string& buf) const { buf += theValue->str(); }

  xqpStringStore* getString() const { return theValue.getp(); }

  xqp_string show() const;
};


/*******************************************************************************
  class QNameItem
********************************************************************************/
class QNameItem : public AtomicItem
{
  friend class QNamePool;

protected:
  static xqpStringStore_t theEmptyPrefix;

  xqpStringStore_t    theNamespace;
  xqpStringStore_t    thePrefix;

  union
  {
    xqpStringStore  * theLocal;
    QNameItem       * theNormQN;
  }                   theUnion;

  uint16_t            thePosition;
  uint16_t            theNextFree;
  uint16_t            thePrevFree;

protected:
  QNameItem() 
    :
    thePosition(0),
    theNextFree(0),
    thePrevFree(0) 
  {
    theUnion.theLocal = NULL;
  }
  
  void free();

  bool isValid() const { return theUnion.theLocal != NULL; }

  bool isInCache() const { return thePosition != 0; }

  bool isOverflow() const { return thePosition == 0; }

  bool isNormalized() const { return thePrefix->empty(); }

  QNameItem* detachNormalized() 
  {
    assert(!isNormalized());
    QNameItem* qn = theUnion.theNormQN;
    theUnion.theNormQN = NULL;
    return qn;
  }

  void setNormalized(QNameItem* qn);  

  void unsetNormalized();

  void setLocal(xqpStringStore* local);

  void unsetLocal();

public:
  virtual ~QNameItem();

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* item,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return (getNormalized() == static_cast<const QNameItem*>(item)->getNormalized());
  }

  xqpStringStore* getNamespace() const { return theNamespace.getp(); }

  xqpStringStore* getPrefix() const    { return thePrefix.getp(); }

  xqpStringStore* getLocalName() const { return getNormalized()->theUnion.theLocal; }

  store::Item* getType() const;

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isIdQName() const;

  bool isBaseUri() const;

  QNameItem* getNormalized() const
  {
    return (isNormalized() ?
            const_cast<QNameItem*>(this) :
            theUnion.theNormQN);
  }

  xqp_string show() const;
};


/*******************************************************************************
  class AnyUriItem
********************************************************************************/
class AnyUriItemImpl : public AtomicItem
{
protected:
  xqpStringStore_t theValue;

protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  AnyUriItemImpl(xqpStringStore_t& value) { theValue.transfer(value); }

  AnyUriItemImpl() {}

public:
  store::Item* getType( ) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* item,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return item->getString()->byteEqual(theValue.getp());
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    xqpStringStore* otherStr = other->getString();
    return theValue->byteCompare(otherStr->c_str(), otherStr->bytes());
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const { return theValue.getp(); }
  xqpStringStore* getStringValueP() const  { return theValue.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theValue; }
  void getStringValue(std::string& buf) const { buf += theValue->str(); }

  xqpStringStore* getString() const { return theValue.getp(); }

  xqp_string show() const;
};


/*******************************************************************************
  class StringItem
********************************************************************************/
class StringItemNaive : public AtomicItem
{
protected:
  xqpStringStore_t theValue;

protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  StringItemNaive(xqpStringStore_t& value) { theValue.transfer(value); }

  StringItemNaive() {}
  
public:
  virtual store::Item* getType( ) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item*,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const { return theValue; }
  xqpStringStore* getStringValueP() const { return theValue.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theValue; }
  void getStringValue(std::string& buf) const { buf += theValue->str(); }

  xqpStringStore* getString() const { return theValue.getp(); }

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NormalizedStringItemImpl
********************************************************************************/
class NormalizedStringItemImpl : public StringItemNaive
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  NormalizedStringItemImpl(xqpStringStore_t& value) : StringItemNaive(value) {}

public:
  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class TokenItemImpl
********************************************************************************/
class TokenItemImpl : public NormalizedStringItemImpl
{
public:
  TokenItemImpl(xqpStringStore_t& value) : NormalizedStringItemImpl(value) {}

  virtual store::Item* getType() const;
  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class LanguageItem
********************************************************************************/
class LanguageItemImpl : public TokenItemImpl
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  LanguageItemImpl(xqpStringStore_t& value) : TokenItemImpl(value) {}

public:
  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NMTOKENItemImpl
********************************************************************************/
class NMTOKENItemImpl : public TokenItemImpl
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  NMTOKENItemImpl(xqpStringStore_t& value) : TokenItemImpl(value) {}

public:
  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NameItem
********************************************************************************/
class NameItemImpl : public TokenItemImpl
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  NameItemImpl(xqpStringStore_t& value) : TokenItemImpl(value) {}

public:
  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NCNameItem
********************************************************************************/
class NCNameItemImpl : public NameItemImpl
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  NCNameItemImpl(xqpStringStore_t& value) : NameItemImpl(value) {}

public:
  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class IDItem
********************************************************************************/
class IDItemImpl : public NCNameItemImpl
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  IDItemImpl(xqpStringStore_t& value) : NCNameItemImpl(value) { }

public:
  store::Item* getType() const;

  virtual xqp_string show() const;
};

/*******************************************************************************
  class IDREFItem
********************************************************************************/
class IDREFItemImpl : public NCNameItemImpl
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  IDREFItemImpl(xqpStringStore_t& value) : NCNameItemImpl(value) { }

public:
  store::Item* getType() const;

  virtual xqp_string show() const;
};

/*******************************************************************************
  class ENTITYItemImpl
********************************************************************************/
class ENTITYItemImpl : public NCNameItemImpl
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  ENTITYItemImpl(xqpStringStore_t& value) : NCNameItemImpl(value) { }

public:
  store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class DateTimeItem
********************************************************************************/
class DateTimeItemNaive : public AtomicItem
{
protected:
  DateTime theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  DateTimeItemNaive(const DateTime* aValue) : theValue(*aValue) { };
  
public:
  const xqp_dateTime& getDateTimeValue() const { return theValue; }
  const xqp_date& getDateValue() const { return theValue; }
  const xqp_time& getTimeValue() const { return theValue; }
  const xqp_gYearMonth& getGYearMonthValue() const { return theValue; }
  const xqp_gYear& getGYearValue() const { return theValue; }
  const xqp_gMonth& getGMonthValue() const { return theValue; }
  const xqp_gMonthDay& getGMonthDayValue() const { return theValue; }
  const xqp_gDay& getGDayValue() const { return theValue; }
  
  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item*,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;

protected:
  DateTimeItemNaive() { };
};


/*******************************************************************************
  class DurationItem
********************************************************************************/
class DurationItemNaive : public AtomicItem
{
protected:
  Duration theValue;

protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  DurationItemNaive(const xqp_duration* aValue) : theValue(*aValue) { };

  DurationItemNaive() {}

public:
  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  const xqp_duration& getDurationValue() const;
  const xqp_dayTimeDuration& getDayTimeDurationValue() const;
  const xqp_yearMonthDuration& getYearMonthDurationValue() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue == other->getDurationValue();
  }


  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue.compare(other->getDurationValue());
  }

  store::Item_t getEBV( ) const;

  xqp_string show() const;
};


/*******************************************************************************
  class DoubleItemNaive
********************************************************************************/
class DoubleItemNaive : public AtomicItem
{
protected:
	xqp_double theValue;

protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
	DoubleItemNaive(const xqp_double& aValue) : theValue( aValue ) {}

  DoubleItemNaive() {}

public:
	const xqp_double& getDoubleValue() const { return theValue; }
	
  bool isNaN() const;
  bool isPosOrNegInf() const;

	store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue == other->getDoubleValue();
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    if (theValue.isNaN() || other->getDoubleValue().isNaN())
      return 2;

    return theValue.compare(other->getDoubleValue());
  }

	store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};
	

/*******************************************************************************
  class FloatItemNaive
********************************************************************************/
class FloatItemNaive : public AtomicItem
{
  xqp_float theValue;

protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  FloatItemNaive(const xqp_float& aValue) : theValue ( aValue ) {}

  FloatItemNaive() {}

public:
  const xqp_float& getFloatValue() const { return theValue; }
	
  bool isNaN() const;
  bool isPosOrNegInf() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue == other->getFloatValue();
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    if (theValue.isNaN() || other->getFloatValue().isNaN())
      return 2;

    return theValue.compare(other->getFloatValue());
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class DecimalItemNaive

                               decimal
                                  |
                                  |
                               integer
                                  |
              ------------------------------------------
              |                   |                    |
       nonPositiveInteger  nonNegativeInteger         long
              |                   |                    |
              |            -----------------          int
        negativeInteger    |               |           |
                           |               |         short
                     positiveInteger   unsignedLong    |
                                           |         byte
                                       unsignedInt 
                                           |
                                       unsingedShort
                                           |
                                       unsingedByte

********************************************************************************/
class DecimalItemNaive : public AtomicItem
{
protected:
  xqp_decimal theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  DecimalItemNaive(const xqp_decimal& aValue) : theValue(aValue) {}

  DecimalItemNaive() {}

public:
  xqp_decimal getDecimalValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue.hash();
  }

  bool equals(
        const store::Item* other,
        long timezone = 0 ,
        const XQPCollator* aCollation = 0) const
  {
    return theValue == other->getDecimalValue();
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue.compare(other->getDecimalValue());
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue( ) const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const;

  xqp_string show() const;
};


/*******************************************************************************
  class IntegerItemNaive
********************************************************************************/
class IntegerItemNaive : public AtomicItem
{
protected:
  xqp_integer theValue;

protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  IntegerItemNaive(const xqp_integer& aValue) : theValue ( aValue ) {}

  IntegerItemNaive() {}

public:
  xqp_integer getIntegerValue() const { return theValue; }
  xqp_decimal getDecimalValue() const;

  virtual store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue.hash();
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return theValue == other->getIntegerValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return theValue.compare(other->getIntegerValue());
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const { return false; }

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
class NonPositiveIntegerItemNaive : public IntegerItemNaive
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  NonPositiveIntegerItemNaive(const xqp_integer& aValue) : IntegerItemNaive(aValue) {}

  NonPositiveIntegerItemNaive() {}
    
public:
  store::Item* getType() const;

  xqp_string show() const;
};


/*******************************************************************************
  class NegativeIntegerItemNaive
********************************************************************************/
class NegativeIntegerItemNaive : public IntegerItemNaive
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  NegativeIntegerItemNaive(const xqp_integer& aValue) : IntegerItemNaive(aValue) {}

  NegativeIntegerItemNaive() {}
    
public:
  store::Item* getType() const;

  xqp_string show() const;
};
  

/*******************************************************************************
  class NonNegativeIntegerItemNaive

  Note: xqp_uinteger is typedef of Integer
********************************************************************************/
class NonNegativeIntegerItemNaive : public IntegerItemNaive
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  NonNegativeIntegerItemNaive(const xqp_uinteger& aValue) : IntegerItemNaive(aValue) {}

  NonNegativeIntegerItemNaive() {}

public:
  xqp_uinteger getUnsignedIntegerValue() const { return theValue; }

  store::Item* getType() const;

  xqp_string show() const;
};


/*******************************************************************************
  class PositiveIntegerItemNaive
********************************************************************************/
class PositiveIntegerItemNaive : public  IntegerItemNaive
{
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  PositiveIntegerItemNaive(const xqp_uinteger& aValue) : IntegerItemNaive(aValue) { }

  PositiveIntegerItemNaive() {}

public:
  xqp_uinteger getUnsignedIntegerValue() const { return theValue; }

  store::Item* getType() const;

  xqp_string show() const;
};


/*******************************************************************************
  class LongItemNaive
********************************************************************************/
class LongItemNaive : public AtomicItem 
{
protected:
  xqp_long theValue;
  
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  LongItemNaive(xqp_long aValue) : theValue(aValue) {}

  LongItemNaive() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;
  
  xqp_long getLongValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const { return false; }

  xqp_string show() const;
};


/*******************************************************************************
  class IntItemNaive
********************************************************************************/
class IntItemNaive : public AtomicItem
{
protected:
  xqp_int theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  IntItemNaive(xqp_int aValue) : theValue(aValue) {}

  IntItemNaive() {}

public:
  bool isNaN() const { return false; }

  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  int32_t getIntValue() const { return theValue; }
    
  store::Item* getType( ) const;

  virtual uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return uint32_t(32767) + theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class ShortItemNaive
********************************************************************************/  
class ShortItemNaive : public AtomicItem 
{
protected:
  xqp_short theValue;
  
  // make sure that only created by the factory
  friend class BasicItemFactory;
  ShortItemNaive ( xqp_short aValue)  : theValue(aValue) {}

  ShortItemNaive() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  xqp_int getIntValue() const { return static_cast<xqp_int>(theValue); }

  xqp_short getShortValue() const { return theValue; }
  
  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;

  bool isNaN() const { return false; }
};


/*******************************************************************************
  class ByteItemNaive
********************************************************************************/
class ByteItemNaive : public AtomicItem 
{
protected:
  xqp_byte theValue;
  
  // make sure that only created by the factory
  friend class BasicItemFactory;
  ByteItemNaive(xqp_byte aValue) : theValue(aValue) {}

  ByteItemNaive() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  xqp_int getIntValue() const { return static_cast<xqp_int>(theValue); }

  xqp_short getShortValue() const { return static_cast<xqp_short>(theValue); }
  
  xqp_byte getByteValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const { return false; }

  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedLongItemNaive
********************************************************************************/
class UnsignedLongItemNaive : public AtomicItem 
{
protected:
  xqp_ulong theValue;
  
  // make sure that only created by the factory
  friend class BasicItemFactory;
  UnsignedLongItemNaive(xqp_ulong aValue) : theValue(aValue) {}

  UnsignedLongItemNaive() {}

 public:
  bool isNaN() const { return false; }

  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_ulong getUnsignedLongValue() const { return theValue; }
  
  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedIntItemNaive
********************************************************************************/
class UnsignedIntItemNaive : public AtomicItem 
{
protected:
  xqp_uint theValue;
  
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  UnsignedIntItemNaive(xqp_uint aValue) : theValue(aValue) {}

  UnsignedIntItemNaive() {}

public:
  bool isNaN() const { return false; }

  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_ulong getUnsignedLongValue() const { return static_cast<xqp_ulong>(theValue); }

  xqp_uint getUnsignedIntValue() const { return theValue; }
  
  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;
 
  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedShortItemNaive
********************************************************************************/
class UnsignedShortItemNaive : public AtomicItem 
{
protected:
  xqp_ushort theValue;
  
protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  UnsignedShortItemNaive ( xqp_ushort aValue) : theValue(aValue) {}

  UnsignedShortItemNaive() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_ulong getUnsignedLongValue() const { return static_cast<xqp_ulong>(theValue); }

  xqp_uint getUnsignedIntValue() const { return static_cast<xqp_uint>(theValue); }
  
  xqp_ushort getUnsignedShortValue() const { return theValue; }

  bool isNaN() const { return false; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedByteItemNaive
********************************************************************************/
class UnsignedByteItemNaive : public AtomicItem 
{
protected:
  xqp_ubyte theValue;
  
  // make sure that only created by the factory
  friend class BasicItemFactory;
  UnsignedByteItemNaive(xqp_ubyte aValue) : theValue(aValue) {}

  UnsignedByteItemNaive() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_ulong getUnsignedLongValue() const { return static_cast<xqp_ulong>(theValue); }

  xqp_uint getUnsignedIntValue() const { return static_cast<xqp_uint>(theValue); }

  xqp_ushort getUnsignedShortValue() const { return static_cast<xqp_ushort>(theValue); }
  
  xqp_ubyte getUnsignedByteValue() const { return theValue; }

  bool isNaN() const { return false; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class BooleanItemNaive
********************************************************************************/
class BooleanItemNaive : public AtomicItem
{
protected:
  xqp_boolean theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  BooleanItemNaive(xqp_boolean aValue) : theValue(aValue) {}

  BooleanItemNaive() {}

public:
  xqp_boolean getBooleanValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return other->getBooleanValue() == theValue;
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return (theValue == other->getBooleanValue() ?
            0 :
            (theValue == false ? -1 : 1));
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};
  

/*******************************************************************************
  class Base64BinaryItemNaive
********************************************************************************/
class Base64BinaryItemNaive : public AtomicItem 
{
protected:
  xqp_base64Binary theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  Base64BinaryItemNaive(xqp_base64Binary aValue) : theValue(aValue) {}

  Base64BinaryItemNaive() {}

public:
  xqp_base64Binary getBase64BinaryValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    return theValue.equal(other->getBase64BinaryValue());
  }

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class HexBinaryItemNaive
********************************************************************************/
class HexBinaryItemNaive : public AtomicItem 
{
protected:
  xqp_hexBinary theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  HexBinaryItemNaive(xqp_hexBinary aValue) : theValue(aValue) {}

  HexBinaryItemNaive() {}

public:
  xqp_hexBinary getHexBinaryValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    return theValue.equal(other->getHexBinaryValue());
  }
  
  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class ErrorItem

  An ErrorItem obj stores a pointer to a ZorbaError obj. The ZorbaError obj is
  not created by the store, but once a pointer to it is set inside an ErrorItem
  obj, the ErrorItem obj assumes ownership of the ZorbaError. The getError()
  method returns the zorbaError pointer, but if the caller needs to access the
  ZobaError obj beyond the lifetime of the ErrorItem, they must make a deep
  copy of it.

  This design is due to the fact that ZorbaError class is visible to the store
  lib, but subclasses of ZorbaError (like ZorbaUserError) may not be visible,
  so ErrorItem cannot do much with an error obj other than storing a pointer
  to it (and calling the virtual free() method on that pointer when the
  ErrorItem gets destroyed).
********************************************************************************/
class ErrorItemNaive : public AtomicItem 
{
protected:
  error::ZorbaError * theError;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  ErrorItemNaive(error::ZorbaError* error) : theError(error) {}

public:
  ~ErrorItemNaive();

  bool isError() const  { return true; }

  error::ZorbaError* getError() const { return theError; }

  xqp_string show() const;

protected:
  // Disable copy
  ErrorItemNaive(const ErrorItemNaive& other);
  ErrorItemNaive& operator=(const ErrorItemNaive& other);
};

} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_STORE_ATOMIC_ITEMS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
