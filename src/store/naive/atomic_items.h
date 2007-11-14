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
class QNameItemImpl : public QNameItem
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

  virtual QNameItem_t getType() const;
  virtual Item_t getAtomizationValue() const;
  virtual uint32_t hash() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV() const;
  virtual xqp_string getStringProperty() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class AnyUriItem
********************************************************************************/
class AnyUriItemImpl : public AnyUriItem
{
protected:
  xqpStringStore_t theValue;

public:
  AnyUriItemImpl(const xqpStringStore& value);
  virtual ~AnyUriItemImpl();

  virtual xqp_string getStringValue() const;
  virtual QNameItem_t getType( ) const;
  virtual Item_t getAtomizationValue( ) const;
  virtual uint32_t hash() const;
  virtual bool equals (Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string getStringProperty( ) const;
  virtual xqp_string show() const;
};


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
class UntypedAtomicItemNaive : public UntypedAtomicItem
{
private:
  xqpStringStore_t theValue;

public:
  UntypedAtomicItemNaive(const xqpStringStore& value);
  virtual ~UntypedAtomicItemNaive();

  virtual xqp_string getStringValue() const;
  virtual QNameItem_t getType( ) const;
  virtual Item_t getAtomizationValue( ) const;
  virtual uint32_t hash() const;
  virtual bool equals ( Item_t ) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string getStringProperty( ) const;
  virtual xqp_string show() const;
};


/*******************************************************************************
  class StringItem
********************************************************************************/
class StringItemNaive : public StringItem
{
protected:
  xqpStringStore_t theValue;
public:
  StringItemNaive(const xqpStringStore& value);
  virtual ~StringItemNaive();
  
  virtual xqp_string getStringValue() const;
  virtual QNameItem_t getType( ) const;
  virtual Item_t getAtomizationValue( ) const;
  virtual uint32_t hash() const;
  virtual bool equals(Item_t) const;
  virtual Item_t getEBV( ) const;
  virtual xqp_string getStringProperty( ) const;
  virtual xqp_string show() const;
};



  class DecimalItemNaive : public DecimalItem
	{
  private:
    long double value_;

  public:
    DecimalItemNaive ( long double value );
    virtual ~DecimalItemNaive();
    virtual long double getDecimalValue() const;

    virtual QNameItem_t getType( ) const;
    virtual Item_t getAtomizationValue( ) const;
    virtual uint32_t hash() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringProperty( ) const;

    virtual xqp_string show() const;
	}; /* class DecimalItem */

  class IntItemNaive : public IntItem
	{
  protected:
    int value_;

  public:
    IntItemNaive ( int value );
    virtual ~IntItemNaive();
    virtual int32_t getIntValue() const;
    virtual long long getIntegerValue() const;
    virtual long double getDecimalValue() const;
    
    virtual QNameItem_t getType( ) const;
    virtual Item_t getAtomizationValue( ) const;
    virtual uint32_t hash() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringProperty() const;

    virtual xqp_string show() const;
	}; /* class IntItem */

	class IntegerItemNaive : public IntegerItem
	{
  protected:
    long long value_;
  public:
    IntegerItemNaive ( long long value );
    virtual ~IntegerItemNaive();
    virtual long long getIntegerValue() const;
    virtual long double getDecimalValue() const;

    virtual QNameItem_t getType() const;
    virtual Item_t getAtomizationValue( ) const;
    virtual uint32_t hash() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringProperty() const;
    
    virtual xqp_string show() const;
	}; /* class IntegerItem */

  class DoubleItemNaive : public DoubleItem
	{
	protected:
		double value;
	public:
		DoubleItemNaive ( double value_arg );
		virtual ~DoubleItemNaive();
		virtual double getDoubleValue() const;
		
		virtual QNameItem_t getType() const;
		virtual Item_t getAtomizationValue( ) const;
    virtual uint32_t hash() const;
		virtual bool equals ( Item_t ) const;
		virtual Item_t getEBV( ) const;
		virtual xqp_string getStringProperty() const;

		virtual xqp_string show() const;
	}; /* class DoubleItem */
	
	class FloatItemNaive : public FloatItem
	{
		float value;
	public:
		FloatItemNaive ( float value_arg );
		virtual ~FloatItemNaive();
		virtual float getFloatValue() const;
		
		virtual QNameItem_t getType() const;
		virtual Item_t getAtomizationValue( ) const;
    virtual uint32_t hash() const;
		virtual bool equals ( Item_t ) const;
		virtual Item_t getEBV( ) const;
		virtual xqp_string getStringProperty() const;

		virtual xqp_string show() const;
	}; /* class FloatItem */
	
	class BooleanItemNaive : public BooleanItem
	{
  private:
    bool value_;

  public:
    BooleanItemNaive ( bool value );
    virtual ~BooleanItemNaive();
    virtual bool getBooleanValue() const;

    virtual QNameItem_t getType() const;
    virtual Item_t getAtomizationValue() const;
    virtual uint32_t hash() const;
    virtual bool equals ( Item_t ) const;
    virtual Item_t getEBV( ) const;
    virtual xqp_string getStringProperty() const;
    
    virtual xqp_string show() const;
	}; /* class BooleanItem */

} /* namespace xqp */
#endif /* XQP_ATOMIC_ITEMS_H */
