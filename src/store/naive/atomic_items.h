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

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"
#include "zorbatypes/datetime.h"

#include "store/api/item.h"


namespace zorba { namespace simplestore {

class QNameItemNorm;

typedef rchandle<QNameItemNorm> NormalizedQName_t;


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
  AtomicItem() : store::Item() { theRCLockPtr = &theRCLock; }
#endif

  virtual ~AtomicItem() {}

  bool isNode() const   { return false; }
  bool isAtomic() const { return true; }
  bool isPul() const    { return false; }
  bool isTuple() const  { return false; }

  virtual store::Item_t getAtomizationValue() const;
  virtual void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
};


/*******************************************************************************
  class QNameItem
********************************************************************************/
class QNameItemImpl : public AtomicItem
{
  friend class QNamePool;
  friend class QNamePoolHashSet;
  friend class ElementNode;

private:
  static xqpStringStore_t theEmptyPrefix;

private:
  xqpStringStore_t  theNamespace;
  xqpStringStore_t  thePrefix;
  xqpStringStore_t  theLocal;

  uint16_t          thePosition;
  uint16_t          theNextFree;
  uint16_t          thePrevFree;

protected:
  QNameItemImpl() : thePosition(0), theNextFree(0), thePrevFree(0) {}

  void free();

  bool isValid() const      { return theLocal != NULL; }

  bool isInCache() const    { return thePosition != 0; }
  bool isOverflow() const   { return thePosition == 0; }

  bool isNormalized() const { return thePrefix->empty(); }

  QNameItemImpl* getNormalized() const
  {
    return (isNormalized() ?
            const_cast<QNameItemImpl*>(this) :
            reinterpret_cast<QNameItemImpl*>(theLocal.getp()));
  }

  QNameItemImpl* detachNormalized() 
  {
    assert(!isNormalized());
    QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(theLocal.getp());
    theLocal.setNull();
    return qn;
  }

  void setNormalized(QNameItemImpl* qn);  

  void unsetNormalized();

public:
  virtual ~QNameItemImpl();

  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* item,
        long timezone = 0,
        XQPCollator* aCollation = 0) const
  {
    return (getNormalized() == 
            reinterpret_cast<const QNameItemImpl*>(item)->getNormalized());
  }

  xqpStringStore* getNamespace() const { return theNamespace.getp(); }
  xqpStringStore* getPrefix() const    { return thePrefix.getp(); }
  xqpStringStore* getLocalName() const { return getNormalized()->theLocal.getp(); }

  store::Item* getType() const;
  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;

  bool isId() const;
  bool isBaseUri() const;

  xqp_string show() const;
};


/*******************************************************************************
  class StringItem
********************************************************************************/
class StringItemNaive : public AtomicItem
{
protected:
  xqpStringStore_t theValue;
public:
  StringItemNaive(xqpStringStore_t& value) { theValue.transfer(value); }
  
  virtual store::Item* getType( ) const;
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const { return theValue; }
  virtual xqpStringStore* getStringValueP() const { return theValue.getp(); }
  virtual xqp_string show() const;
};


/*******************************************************************************
  class NCNameItem
********************************************************************************/
class NCNameItemImpl : public AtomicItem
{
protected:
  xqpStringStore_t  theValue;

public:
  NCNameItemImpl(xqpStringStore_t& value)
  {
    theValue.transfer(value);
  }

  virtual store::Item* getType() const;
  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
  bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  store::Item_t getEBV() const;
  xqpStringStore_t getStringValue() const { return theValue.getp(); }
  xqpStringStore* getStringValueP() const { return theValue.getp(); }

  virtual xqp_string show() const;
};


/*******************************************************************************
  class IDItem
********************************************************************************/
class IDItemImpl : public NCNameItemImpl
{
public:
  IDItemImpl(xqpStringStore_t& value) : NCNameItemImpl(value) { }

  store::Item* getType() const;

  virtual xqp_string show() const;
};



/*******************************************************************************
  class AnyUriItem
********************************************************************************/
class AnyUriItemImpl : public AtomicItem
{
protected:
  xqpStringStore_t theValue;

public:
  AnyUriItemImpl(xqpStringStore_t& value) { theValue.transfer(value); }

  store::Item* getType( ) const;
  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
  bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  store::Item_t getEBV( ) const;
  xqpStringStore_t getStringValue( ) const { return theValue.getp(); }
  xqpStringStore* getStringValueP() const  { return theValue.getp(); }
  xqp_string show() const;
};


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
class UntypedAtomicItemImpl : public AtomicItem
{
private:
  xqpStringStore_t theValue;

public:
  UntypedAtomicItemImpl(xqpStringStore_t& value) { theValue.transfer(value); }

  store::Item* getType( ) const;
  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
  bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  store::Item_t getEBV( ) const;
  xqpStringStore_t getStringValue() const { return theValue; }
  xqpStringStore* getStringValueP() const { return theValue.getp(); }
  xqp_string show() const;
};


/*******************************************************************************
  class DateTimeItem
********************************************************************************/
class DateTimeItemNaive : public AtomicItem
{
protected:
  DateTime theValue;

public:
  static int createFromDateAndTime(
        const xqp_date* date,
        const xqp_time* time,
        store::Item_t& item);

  DateTimeItemNaive(const DateTime* aValue) : theValue(*aValue) { };
  
  const xqp_dateTime& getDateTimeValue() const { return theValue; }
  const xqp_date& getDateValue() const { return theValue; }
  const xqp_time& getTimeValue() const { return theValue; }
  const xqp_gYearMonth& getGYearMonthValue() const { return theValue; }
  const xqp_gYear& getGYearValue() const { return theValue; }
  const xqp_gMonth& getGMonthValue() const { return theValue; }
  const xqp_gMonthDay& getGMonthDayValue() const { return theValue; }
  const xqp_gDay& getGDayValue() const { return theValue; }
  
  store::Item* getType() const;

  bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;

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

public:
  DurationItemNaive(const xqp_duration* aValue) : theValue(*aValue) { };

  xqpStringStore_t getStringValue() const;
  const xqp_duration& getDurationValue() const;
  const xqp_dayTimeDuration& getDayTimeDurationValue() const;
  const xqp_yearMonthDuration& getYearMonthDurationValue() const;
  store::Item* getType() const;
  bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  store::Item_t getEBV( ) const;
  xqp_string show() const;
  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class DayTimeDurationItem
********************************************************************************/
/*
class DayTimeDurationItemNaive : public AtomicItem
{
protected:
  DayTimeDuration theValue;
  Duration durationCastValue;

public:
  DayTimeDurationItemNaive(const xqp_dayTimeDuration* aValue);

  xqpStringStore_t getStringValue() const;
  const xqp_dayTimeDuration& getDayTimeDurationValue() const;
  const xqp_duration& getDurationValue() const;
  store::Item* getType() const;
  bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  store::Item_t getEBV( ) const;
  xqp_string show() const;
  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};
*/

/*******************************************************************************
  class YearMonthDurationItem
********************************************************************************/
/*
class YearMonthDurationItemNaive : public AtomicItem
{
protected:
  YearMonthDuration theValue;
  Duration durationCastValue;

public:
  YearMonthDurationItemNaive(const xqp_yearMonthDuration* aValue);
  xqpStringStore_t getStringValue() const;
  const xqp_yearMonthDuration& getYearMonthDurationValue() const;
  const xqp_duration& getDurationValue() const;
  store::Item* getType() const;
  bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0) const;
  store::Item_t getEBV( ) const;
  xqp_string show() const;
  uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};
*/

/*******************************************************************************
  class DecimalItemNaive
********************************************************************************/
class DecimalItemNaive : public AtomicItem
{
private:
  xqp_decimal theValue;

public:
  DecimalItemNaive ( xqp_decimal aValue ) : theValue( aValue ) {}

  virtual xqp_decimal getDecimalValue() const { return theValue; }

  virtual store::Item* getType( ) const;
  virtual bool equals(const store::Item*, long timezone = 0 , XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue( ) const;
  virtual xqp_string show() const;
  virtual bool isNaN() const;
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class IntegerItemNaive
********************************************************************************/
class IntegerItemNaive : public AtomicItem
{
 protected:
  xqp_integer theValue;

 public:
  IntegerItemNaive ( xqp_integer aValue ) : theValue ( aValue ) {}
  virtual xqp_integer getIntegerValue() const { return theValue; }
  virtual xqp_decimal getDecimalValue() const;

  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class NonPositiveIntegerItemNaive
********************************************************************************/
class NonPositiveIntegerItemNaive : public AtomicItem 
{
 private:
  xqp_integer theValue;
    
 public:
  NonPositiveIntegerItemNaive ( xqp_integer aValue) : theValue(aValue) {}
  virtual xqp_integer getIntegerValue() const { return theValue; }
  virtual xqp_decimal getDecimalValue() const;
    
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class NegativeIntegerItemNaive
********************************************************************************/
class NegativeIntegerItemNaive : public AtomicItem 
{
 private:
  xqp_integer theValue;
    
 public:
  NegativeIntegerItemNaive ( xqp_integer aValue) : theValue(aValue) {}
  virtual xqp_integer getIntegerValue() const { return theValue; }
  virtual xqp_decimal getDecimalValue() const;
    
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};
  

/*******************************************************************************
  class NonNegativeIntegerItemNaive
********************************************************************************/
class NonNegativeIntegerItemNaive : public AtomicItem 
{
 private:
  xqp_uinteger theValue;
  
 public:
  NonNegativeIntegerItemNaive ( xqp_uinteger aValue) : theValue(aValue) {}
  virtual xqp_uinteger getUnsingedIntegerValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class PositiveIntegerItemNaive
********************************************************************************/
class PositiveIntegerItemNaive : public AtomicItem 
{
 private:
  xqp_uinteger theValue;
  
 public:
  PositiveIntegerItemNaive ( xqp_uinteger aValue) : theValue(aValue) {}
  virtual xqp_uinteger getUnsignedIntegerValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV() const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class IntItemNaive
********************************************************************************/
class IntItemNaive : public AtomicItem
{
 protected:
  xqp_int theValue;

 public:
  IntItemNaive ( xqp_int aValue ) : theValue ( aValue ) {}

  virtual int32_t getIntValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  virtual xqp_long getLongValue() const;
    
  virtual store::Item* getType( ) const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class UnsignedIntItemNaive
********************************************************************************/
class UnsignedIntItemNaive : public AtomicItem 
{
 private:
  xqp_uint theValue;
  
 public:
  UnsignedIntItemNaive ( xqp_uint aValue) : theValue(aValue) {}
  virtual xqp_uint getUnsignedIntValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  virtual xqp_uinteger getUnsignedIntegerValue() const;
  virtual xqp_ulong getUnsignedLongValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class LongItemNaive
********************************************************************************/
class LongItemNaive : public AtomicItem 
{
 private:
  xqp_long theValue;
  
 public:
  LongItemNaive ( xqp_long aValue) : theValue(aValue) {}
  virtual xqp_long getLongValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class UnsignedLongItemNaive
********************************************************************************/
class UnsignedLongItemNaive : public AtomicItem 
{
 private:
  xqp_ulong theValue;
  
 public:
  UnsignedLongItemNaive ( xqp_ulong aValue) : theValue(aValue) {}
  virtual xqp_ulong getUnsignedLongValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  virtual xqp_uinteger getUnsignedIntegerValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class ShortItemNaive
********************************************************************************/  
class ShortItemNaive : public AtomicItem 
{
 private:
  xqp_short theValue;
  
 public:
  ShortItemNaive ( xqp_short aValue)  : theValue(aValue) {}
  virtual xqp_short getShortValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  virtual xqp_long getLongValue() const;
  virtual xqp_int getIntValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};
  

/*******************************************************************************
  class UnsignedShortItemNaive
********************************************************************************/
class UnsignedShortItemNaive : public AtomicItem 
{
 private:
  xqp_ushort theValue;
  
 public:
  UnsignedShortItemNaive ( xqp_ushort aValue) : theValue(aValue) {}

  virtual xqp_ushort getUnsignedShortValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  virtual xqp_uinteger getUnsignedIntegerValue() const;
  virtual xqp_ulong getUnsignedLongValue() const;
  virtual xqp_uint getUnsignedIntValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class ByteItemNaive
********************************************************************************/
class ByteItemNaive : public AtomicItem 
{
 private:
  xqp_byte theValue;
  
 public:
  ByteItemNaive ( xqp_byte aValue) : theValue(aValue) {}
  virtual xqp_byte getByteValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  virtual xqp_long getLongValue() const;
  virtual xqp_int getIntValue() const;
  virtual xqp_short getShortValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class UnsignedByteItemNaive
********************************************************************************/
class UnsignedByteItemNaive : public AtomicItem 
{
 private:
  xqp_ubyte theValue;
  
 public:
  UnsignedByteItemNaive ( xqp_ubyte aValue) : theValue(aValue) {}

  virtual xqp_ubyte getUnsignedByteValue() const { return theValue; }
  virtual xqp_integer getIntegerValue() const;
  virtual xqp_decimal getDecimalValue() const;
  virtual xqp_uinteger getUnsignedIntegerValue() const;
  virtual xqp_ulong getUnsignedLongValue() const;
  virtual xqp_uint getUnsignedIntValue() const;
  virtual xqp_ushort getUnsignedShortValue() const;
  
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const { return false; }
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class DoubleItemNaive
********************************************************************************/
class DoubleItemNaive : public AtomicItem
{
protected:
	xqp_double theValue;

public:
	DoubleItemNaive(const xqp_double& aValue ) : theValue( aValue ) {}

	virtual const xqp_double& getDoubleValue() const { return theValue; }
	
	virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
	virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const;
  virtual bool isPosOrNegInf() const;
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};
	

/*******************************************************************************
  class FloatItemNaive
********************************************************************************/
class FloatItemNaive : public AtomicItem
{
  xqp_float theValue;

public:
  FloatItemNaive ( xqp_float aValue ) : theValue ( aValue ) {}
  virtual xqp_float getFloatValue() const { return theValue; }
	
  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual bool isNaN() const;
  virtual bool isPosOrNegInf() const;
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class BooleanItemNaive
********************************************************************************/
class BooleanItemNaive : public AtomicItem
{
 private:
  xqp_boolean theValue;

 public:
  BooleanItemNaive ( xqp_boolean aValue ) : theValue(aValue) {}
  virtual xqp_boolean getBooleanValue() const { return theValue; }

  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
  virtual store::Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
};
  

/*******************************************************************************
  class Base64BinaryItemNaive
********************************************************************************/
class Base64BinaryItemNaive : public AtomicItem 
{
private:
  xqp_base64Binary theValue;

public:
  Base64BinaryItemNaive(xqp_base64Binary aValue) : theValue(aValue) {}
  virtual xqp_base64Binary getBase64BinaryValue() const { return theValue; }

  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};


/*******************************************************************************
  class HexBinaryItemNaive
********************************************************************************/
class HexBinaryItemNaive : public AtomicItem 
{
 private:
  xqp_hexBinary theValue;

 public:
 HexBinaryItemNaive(xqp_hexBinary aValue) : theValue(aValue) {}
  virtual xqp_hexBinary getHexBinaryValue() const { return theValue; }

  virtual store::Item* getType() const;
  virtual bool equals(const store::Item*, long timezone = 0, XQPCollator* aCollation = 0 ) const;
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_string show() const;
  virtual uint32_t hash(long timezone = 0, XQPCollator* aCollation = 0) const;
};

} // namespace store
} // namespace zorba
#endif /* ZORBA_STORE_ATOMIC_ITEMS_H */
