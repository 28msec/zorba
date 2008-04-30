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
#ifndef ZORBA_STORE_MIN_ATOMIC_ITEMS_H
#define ZORBA_STORE_MIN_ATOMIC_ITEMS_H

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"
#include "zorbatypes/datetime.h"

#include "store/api/item.h"


namespace zorba { 
  namespace store {

/*******************************************************************************

********************************************************************************/
class AtomicItem : public Item
{
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
public:
  AtomicItem() : Item() { }

#else

protected:
  SYNC_CODE(RCLock  theRCLock;)

public:
  AtomicItem() : Item() { SYNC_CODE(theRCLockPtr = &theRCLock;) }
#endif

  virtual ~AtomicItem() {}

  bool isNode() const   { return false; }
  bool isAtomic() const { return true; }
  bool isPul() const    { return false; }

  virtual Item_t getAtomizationValue() const;
  virtual Iterator_t getTypedValue() const;
};


/*******************************************************************************
  class QNameItem
********************************************************************************/
class QNameItemImpl : public AtomicItem
{
//  friend class QNamePool;
//  friend class QNamePoolHashSet;
//  friend class ElementNode;

public:
  xqpStringStore_t  theNamespace;
  xqpStringStore_t  thePrefix;
  xqpStringStore_t  theLocal;

//  uint16_t          thePosition;
//  uint16_t          theNextFree;
//  uint16_t          thePrevFree;
public:
//  QNameItemImpl() : thePosition(0), theNextFree(0), thePrevFree(0) {}
  QNameItemImpl(xqpStringStore  *ns, 
                xqpStringStore  *pre,
                xqpStringStore  *local) : 
      theNamespace(ns), thePrefix(pre), theLocal(local) {}
  QNameItemImpl(const char  *ns, 
                const char  *pre,
                const char  *local) : 
      theNamespace(new xqpStringStore(ns)), 
      thePrefix(new xqpStringStore(pre)), 
      theLocal(new xqpStringStore(local)) {}


  virtual ~QNameItemImpl() { }

private:
//  void free();

//  bool isInCache() const               { return thePosition != 0; }
//  bool isOverflow() const              { return thePosition == 0; }

 public:
  xqpStringStore* getNamespace() const { return theNamespace.getp(); }
  xqpStringStore* getPrefix() const    { return thePrefix.getp(); }
  xqpStringStore* getLocalName() const { return theLocal.getp(); }

  Item* getType() const;
  uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  Item_t getEBV() const;
  xqpStringStore_t getStringValue() const;

  bool isId() const;
  bool isBaseUri() const;

  xqp_string show() const;
};


/*******************************************************************************
  class NCNameItem
********************************************************************************/
class NCNameItemImpl : public AtomicItem
{
protected:
  xqpStringStore_t  theValue;

public:
  NCNameItemImpl(xqpStringStore* aValue) : theValue(aValue)
  {}

  virtual Item* getType() const;
  uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  Item_t getEBV() const;
  xqpStringStore_t getStringValue() const { return theValue.getp(); }
  xqpStringStore* getStringValueP() { return theValue.getp(); }

  virtual xqp_string show() const;
};


/*******************************************************************************
  class IDItem
********************************************************************************/
class IDItemImpl : public NCNameItemImpl
{
public:
  IDItemImpl(xqpStringStore* aValue) : NCNameItemImpl(aValue) { }

  Item* getType() const;

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
  AnyUriItemImpl(xqpStringStore* aValue) : theValue(aValue)
  {}

  Item* getType( ) const;
  uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  Item_t getEBV( ) const;
  xqpStringStore_t getStringValue( ) const { return theValue.getp(); }
  xqpStringStore* getStringValueP() { return theValue.getp(); }
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
  UntypedAtomicItemImpl(xqpStringStore* aValue) : theValue ( aValue ) {}

  UntypedAtomicItemImpl(xqpStringStore_t& aValue) { theValue.transfer(aValue); }

  Item* getType( ) const;
  uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
  Item_t getEBV( ) const;
  xqpStringStore_t getStringValue() const { return theValue; }
  xqpStringStore* getStringValueP() { return theValue.getp(); }
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
  StringItemNaive(const xqpStringStore_t& aValue) : theValue ( aValue ) {}
  
  virtual Item* getType( ) const;
  virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  virtual Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue() const { return theValue; }
  virtual xqpStringStore* getStringValueP() { return theValue.getp(); }
  virtual xqp_string show() const;
};

/*******************************************************************************
 * class DateTimeItem
 *******************************************************************************/
class DateTimeItemNaive : public AtomicItem
{
protected:
  xqp_dateTime theValue;

public:
  DateTimeItemNaive(xqp_dateTime& aValue) : theValue(aValue) { };
  static int createFromDateAndTime(const xqp_date& date, const xqp_time& time, Item_t& item);
  
  virtual xqpStringStore_t getStringValue() const;
  
  virtual xqp_dateTime getDateTimeValue() const { return theValue; }
  virtual xqp_date getDateValue() const { return theValue; }
  virtual xqp_time getTimeValue() const { return theValue; }
  virtual xqp_gYearMonth getGYearMonthValue() const { return theValue; }
  virtual xqp_gYear getGYearValue() const { return theValue; }
  virtual xqp_gMonth getGMonthValue() const { return theValue; }
  virtual xqp_gMonthDay getGMonthDayValue() const { return theValue; }
  virtual xqp_gDay getGDayValue() const { return theValue; }
  
  virtual Item* getType() const;
  virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
  virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const;
  
protected:
  DateTimeItemNaive() { };
};

/*******************************************************************************
 * class DurationItem
 *******************************************************************************/
class DurationItemNaive : public AtomicItem
{
protected:
  xqp_duration theValue;

public:
  DurationItemNaive(xqp_duration& aValue) : theValue(aValue) { };
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_duration getDurationValue() const;
  virtual xqp_yearMonthDuration getYearMonthDurationValue() const;
  virtual xqp_dayTimeDuration getDayTimeDurationValue() const;
  virtual Item* getType() const;
  virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
  virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const;
};

/*******************************************************************************
 * class DayTimeDurationItem
 *******************************************************************************/
class DayTimeDurationItemNaive : public AtomicItem
{
protected:
  xqp_dayTimeDuration theValue;

public:
  DayTimeDurationItemNaive(xqp_dayTimeDuration& aValue) : theValue(aValue) { };
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_dayTimeDuration getDayTimeDurationValue() const;
  virtual Item* getType() const;
  virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
  virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const;
};

/*******************************************************************************
 * class YearMonthDurationItem
 *******************************************************************************/
class YearMonthDurationItemNaive : public AtomicItem
{
protected:
  xqp_yearMonthDuration theValue;

public:
  YearMonthDurationItemNaive(xqp_yearMonthDuration& aValue) : theValue(aValue) { };
  virtual xqpStringStore_t getStringValue() const;
  virtual xqp_yearMonthDuration getYearMonthDurationValue() const;
  virtual Item* getType() const;
  virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
  virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const;
};

/*******************************************************************************
 * 
 *******************************************************************************/

class DecimalItemNaive : public AtomicItem
{
private:
  xqp_decimal theValue;

public:
  DecimalItemNaive ( xqp_decimal aValue ) : theValue( aValue ) {}

  virtual xqp_decimal getDecimalValue() const { return theValue; }

  virtual Item* getType( ) const;
  virtual bool equals(const Item*, RuntimeCB* , XQPCollator* aCollation = 0 ) const;
  virtual Item_t getEBV( ) const;
  virtual xqpStringStore_t getStringValue( ) const;
  virtual xqp_string show() const;
  virtual bool isNaN() const;
  virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
};


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
    
    virtual Item* getType( ) const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
	};

	class IntegerItemNaive : public AtomicItem
	{
  protected:
    xqp_integer theValue;
  public:
    IntegerItemNaive ( xqp_integer aValue ) : theValue ( aValue ) {}
    virtual xqp_integer getIntegerValue() const { return theValue; }
    virtual xqp_decimal getDecimalValue() const;

    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
	};

  class DoubleItemNaive : public AtomicItem
	{
	protected:
		xqp_double theValue;
	public:
		DoubleItemNaive ( xqp_double aValue ) : theValue ( aValue ) {}
		virtual xqp_double getDoubleValue() const { return theValue; }
		
		virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
		virtual Item_t getEBV( ) const;
		virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const;
    virtual bool isPosOrNegInf() const;
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
	};
	
	class FloatItemNaive : public AtomicItem
	{
		xqp_float theValue;
	public:
		FloatItemNaive ( xqp_float aValue ) : theValue ( aValue ) {}
		virtual xqp_float getFloatValue() const { return theValue; }
		
		virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
		virtual Item_t getEBV( ) const;
		virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const;
    virtual bool isPosOrNegInf() const;
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
	};
	
	class BooleanItemNaive : public AtomicItem
	{
  private:
    xqp_boolean theValue;

  public:
    BooleanItemNaive ( xqp_boolean aValue ) : theValue(aValue) {}
    virtual xqp_boolean getBooleanValue() const { return theValue; }

    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
	};
  
  class NonPositiveIntegerItemNaive : public AtomicItem {
  private:
    xqp_integer theValue;
    
  public:
    NonPositiveIntegerItemNaive ( xqp_integer aValue) : theValue(aValue) {}
    virtual xqp_integer getIntegerValue() const { return theValue; }
    virtual xqp_decimal getDecimalValue() const;
    
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class NegativeIntegerItemNaive : public AtomicItem {
  private:
    xqp_integer theValue;
    
  public:
    NegativeIntegerItemNaive ( xqp_integer aValue) : theValue(aValue) {}
    virtual xqp_integer getIntegerValue() const { return theValue; }
    virtual xqp_decimal getDecimalValue() const;
    
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class LongItemNaive : public AtomicItem {
  private:
    xqp_long theValue;
  
  public:
    LongItemNaive ( xqp_long aValue) : theValue(aValue) {}
    virtual xqp_long getLongValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class ShortItemNaive : public AtomicItem {
  private:
    xqp_short theValue;
  
  public:
    ShortItemNaive ( xqp_short aValue)  : theValue(aValue) {}
    virtual xqp_short getShortValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
    virtual xqp_long getLongValue() const;
    virtual xqp_int getIntValue() const;
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class ByteItemNaive : public AtomicItem {
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
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class NonNegativeIntegerItemNaive : public AtomicItem {
  private:
    xqp_uinteger theValue;
  
  public:
    NonNegativeIntegerItemNaive ( xqp_uinteger aValue) : theValue(aValue) {}
    virtual xqp_uinteger getUnsingedIntegerValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class UnsignedLongItemNaive : public AtomicItem {
  private:
    xqp_ulong theValue;
  
  public:
    UnsignedLongItemNaive ( xqp_ulong aValue) : theValue(aValue) {}
    virtual xqp_ulong getUnsignedLongValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
    virtual xqp_uinteger getUnsignedIntegerValue() const;
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class UnsignedIntItemNaive : public AtomicItem {
  private:
    xqp_uint theValue;
  
  public:
    UnsignedIntItemNaive ( xqp_uint aValue) : theValue(aValue) {}
    virtual xqp_uint getUnsignedIntValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
    virtual xqp_uinteger getUnsignedIntegerValue() const;
    virtual xqp_ulong getUnsignedLongValue() const;
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class UnsignedShortItemNaive : public AtomicItem {
  private:
    xqp_ushort theValue;
  
  public:
    UnsignedShortItemNaive ( xqp_ushort aValue)
    : theValue(aValue) {}
    virtual xqp_ushort getUnsignedShortValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
    virtual xqp_uinteger getUnsignedIntegerValue() const;
    virtual xqp_ulong getUnsignedLongValue() const;
    virtual xqp_uint getUnsignedIntValue() const;
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class UnsignedByteItemNaive : public AtomicItem {
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
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV( ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };
  
  class PositiveIntegerItemNaive : public AtomicItem {
  private:
    xqp_uinteger theValue;
  
  public:
    PositiveIntegerItemNaive ( xqp_uinteger aValue) : theValue(aValue) {}
    virtual xqp_uinteger getUnsignedIntegerValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
  
    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual Item_t getEBV() const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };

  class Base64BinaryItemNaive : public AtomicItem {
  private:
     xqp_base64Binary theValue;
  public:
    Base64BinaryItemNaive(xqp_base64Binary aValue) : theValue(aValue) {}
    virtual xqp_base64Binary getBase64BinaryValue() const { return theValue; }

    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };


  class HexBinaryItemNaive : public AtomicItem {
  private:
    xqp_hexBinary theValue;
  public:
    HexBinaryItemNaive(xqp_hexBinary aValue) : theValue(aValue) {}
    virtual xqp_hexBinary getHexBinaryValue() const { return theValue; }

    virtual Item* getType() const;
    virtual bool equals(const Item*, RuntimeCB*, XQPCollator* aCollation = 0 ) const;
    virtual xqpStringStore_t getStringValue() const;
    virtual xqp_string show() const;
    virtual uint32_t hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation = 0) const;
  };

} // namespace store
} // namespace zorba
#endif /* ZORBA_STORE_ATOMIC_ITEMS_H */
