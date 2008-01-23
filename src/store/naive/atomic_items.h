/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com), Donald Kossmann, Tim Kraska
 *
 */

#ifndef XQP_ATOMIC_ITEMS_H
#define XQP_ATOMIC_ITEMS_H


#include "util/rchandle.h"
#include "store/api/item.h"

namespace xqp
{

/*******************************************************************************
  class QNameItem
********************************************************************************/
class QNameItemImpl : public AtomicItem
{
  friend class QNamePool;

private:
  xqpStringStore_t  theNamespace;
  xqpStringStore_t  thePrefix;
  xqpStringStore_t  theLocal;

  uint16_t          thePosition;
  uint16_t          theNextFree;
  uint16_t          thePrevFree;

private:
  QNameItemImpl() : thePosition(0), theNextFree(0), thePrevFree(0) {}
 
  virtual ~QNameItemImpl() { }

  void free();

  bool isInCache() const                  { return thePosition != 0; }
  bool isOverflow() const                 { return thePosition == 0; }

 public:
  virtual xqp_string getNamespace() const { return theNamespace; }
  virtual xqp_string getPrefix() const    { return thePrefix; }
  virtual xqp_string getLocalName() const { return theLocal; }

  virtual Item_t getType() const;
  virtual uint32_t hash() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV() const;
  virtual xqp_string getStringValue() const;

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
  AnyUriItemImpl(const xqpStringStore_t& aValue) : theValue(aValue) {}

  virtual Item_t getType( ) const;
  virtual uint32_t hash() const;
  virtual bool equals (Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string getStringValue( ) const { return theValue; }
  virtual xqpStringStore* getStringValueP() { return theValue.get_ptr(); }
  virtual xqp_string show() const;
};


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
class UntypedAtomicItemNaive : public AtomicItem
{
private:
  xqpStringStore_t theValue;

public:
  UntypedAtomicItemNaive(const xqpStringStore_t& aValue) : theValue ( aValue ) {}

  virtual Item_t getType( ) const;
  virtual uint32_t hash() const;
  virtual bool equals ( Item_t ) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string getStringValue() const { return theValue; }
  virtual xqpStringStore* getStringValueP() { return theValue.get_ptr(); }
  virtual xqp_string show() const;
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
  
  virtual Item_t getType( ) const;
  virtual uint32_t hash() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string getStringValue() const { return theValue; }
  virtual xqpStringStore* getStringValueP() { return theValue.get_ptr(); }
  virtual xqp_string show() const;
};


/*******************************************************************************
 * class DateItem
 *******************************************************************************/
class DateItemNaive : public AtomicItem
{
protected:
  xqp_date theValue;

public:
  DateItemNaive(xqp_date& date) : theValue(date) { };
  virtual xqp_string getStringValue() const; 
  virtual xqp_date getDateValue() const;  
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
};

/*******************************************************************************
 * class TimeItem
 *******************************************************************************/
class TimeItemNaive : public AtomicItem
{
protected:
  xqp_time theValue;

public:
  TimeItemNaive(xqp_time& aValue) : theValue(aValue) { };
  virtual xqp_string getStringValue() const;
  virtual xqp_time getTimeValue() const;
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
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
  DateTimeItemNaive(const xqp_date& date, const xqp_time& time);
  virtual xqp_string getStringValue() const;
  virtual xqp_dateTime getDateTimeValue() const;
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
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
  virtual xqp_string getStringValue() const;
  virtual xqp_duration getDurationValue() const;
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
  virtual int32_t getYears() const;
};

/*******************************************************************************
 * class GYearMonthItem
 *******************************************************************************/
class GYearMonthItemNaive : public AtomicItem
{
protected:
  xqp_gYearMonth theValue;

public:
  GYearMonthItemNaive(xqp_gYearMonth& aValue) : theValue(aValue) { };
  virtual xqp_string getStringValue() const;
  virtual xqp_gYearMonth getGYearMonthValue() const;
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
};

/*******************************************************************************
 * class GYearItem
 *******************************************************************************/
class GYearItemNaive : public AtomicItem
{
  protected:
    xqp_gYear theValue;

  public:
    GYearItemNaive(xqp_gYear& aValue) : theValue(aValue) { };
    virtual xqp_string getStringValue() const;
    virtual xqp_gYear getGYearValue() const;
    virtual Item_t getType() const;
    virtual bool equals(Item_t) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string show() const;
};

/*******************************************************************************
 * class GMonthDayItem
 *******************************************************************************/
class GMonthDayItemNaive : public AtomicItem
{
protected:
  xqp_gMonthDay theValue;

public:
  GMonthDayItemNaive(xqp_gMonthDay& aValue) : theValue(aValue) { };
  virtual xqp_string getStringValue() const;
  virtual xqp_gMonthDay getGMonthDayValue() const;
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
};

/*******************************************************************************
 * class GMonthItem
 *******************************************************************************/
class GMonthItemNaive : public AtomicItem
{
protected:
  xqp_gMonth theValue;

public:
  GMonthItemNaive(xqp_gMonth& aValue) : theValue(aValue) { };
  virtual xqp_string getStringValue() const;
  virtual xqp_gMonth getGMonthValue() const;
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
};

/*******************************************************************************
 * class GDayItem
 *******************************************************************************/
class GDayItemNaive : public AtomicItem
{
protected:
  xqp_gDay theValue;

public:
  GDayItemNaive(xqp_gDay& aValue) : theValue(aValue) { };
  virtual xqp_string getStringValue() const;
  virtual xqp_gDay getGDayValue() const;
  virtual Item_t getType() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string show() const;
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

    virtual Item_t getType( ) const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue( ) const;
    virtual xqp_string show() const;
    virtual bool isNaN() const;
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
    
    virtual Item_t getType( ) const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
	};

	class IntegerItemNaive : public AtomicItem
	{
  protected:
    xqp_integer theValue;
  public:
    IntegerItemNaive ( xqp_integer aValue ) : theValue ( aValue ) {}
    virtual xqp_integer getIntegerValue() const { return theValue; }
    virtual xqp_decimal getDecimalValue() const;

    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
	};

  class DoubleItemNaive : public AtomicItem
	{
	protected:
		xqp_double theValue;
	public:
		DoubleItemNaive ( xqp_double aValue ) : theValue ( aValue ) {}
		virtual xqp_double getDoubleValue() const { return theValue; }
		
		virtual Item_t getType() const;
		virtual bool equals ( Item_t ) const;
		virtual Item_t getEBV( ) const;
		virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const;
    virtual bool isPosOrNegInf() const;
	};
	
	class FloatItemNaive : public AtomicItem
	{
		xqp_float theValue;
	public:
		FloatItemNaive ( xqp_float aValue ) : theValue ( aValue ) {}
		virtual xqp_float getFloatValue() const { return theValue; }
		
		virtual Item_t getType() const;
		virtual bool equals ( Item_t ) const;
		virtual Item_t getEBV( ) const;
		virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const;
    virtual bool isPosOrNegInf() const;
	};
	
	class BooleanItemNaive : public AtomicItem
	{
  private:
    xqp_boolean theValue;

  public:
    BooleanItemNaive ( xqp_boolean aValue ) : theValue(aValue) {}
    virtual xqp_boolean getBooleanValue() const { return theValue; }

    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
	};
  
  class NonPositiveIntegerItemNaive : public AtomicItem {
  private:
    xqp_integer theValue;
    
  public:
    NonPositiveIntegerItemNaive ( xqp_integer aValue) : theValue(aValue) {}
    virtual xqp_integer getIntegerValue() const { return theValue; }
    virtual xqp_decimal getDecimalValue() const;
    
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
  };
  
  class NegativeIntegerItemNaive : public AtomicItem {
  private:
    xqp_integer theValue;
    
  public:
    NegativeIntegerItemNaive ( xqp_integer aValue) : theValue(aValue) {}
    virtual xqp_integer getIntegerValue() const { return theValue; }
    virtual xqp_decimal getDecimalValue() const;
    
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
  };
  
  class LongItemNaive : public AtomicItem {
  private:
    xqp_long theValue;
  
  public:
    LongItemNaive ( xqp_long aValue) : theValue(aValue) {}
    virtual xqp_long getLongValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
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
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
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
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
  };
  
  class NonNegativeIntegerItemNaive : public AtomicItem {
  private:
    xqp_uinteger theValue;
  
  public:
    NonNegativeIntegerItemNaive ( xqp_uinteger aValue) : theValue(aValue) {}
    virtual xqp_uinteger getUnsingedIntegerValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
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
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
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
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
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
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
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
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
  };
  
  class PositiveIntegerItemNaive : public AtomicItem {
  private:
    xqp_uinteger theValue;
  
  public:
    PositiveIntegerItemNaive ( xqp_uinteger aValue) : theValue(aValue) {}
    virtual xqp_uinteger getUnsignedIntegerValue() const { return theValue; }
    virtual xqp_integer getIntegerValue() const;
    virtual xqp_decimal getDecimalValue() const;
  
    virtual Item_t getType() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringValue() const;
    virtual xqp_string show() const;
    virtual bool isNaN() const { return false; }
  };

} /* namespace xqp */
#endif /* XQP_ATOMIC_ITEMS_H */
