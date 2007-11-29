/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
*
*  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
*
*    Copyright 2006-2007 FLWOR Foundation.
*  Author: David Graf (david.graf@28msec.com), Donald Kossmann, Tim Kraska
*
*/

#include "util/hashfun.h"
#include "util/Assert.h"
#include "errors/Error.h"
#include "store/naive/atomic_items.h"
#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/naive/qname_pool.h"
#include "store/naive/simple_store.h"

namespace xqp
{

/*******************************************************************************
  class QNameItem
********************************************************************************/

void QNameItemImpl::free()
{
  reinterpret_cast<SimpleStore*>(&Store::getInstance())->getQNamePool().remove(this);
}


QNameItem_t QNameItemImpl::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "QName");
}


Item_t QNameItemImpl::getAtomizationValue( ) const
{
  return Store::getInstance().getItemFactory().
         createQName(theNamespace, thePrefix, theLocal).get_ptr();
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
          (theNamespace->byteEqual(item->getNamespace().getStore()) &&
           theLocal->byteEqual(item->getLocalName().getStore())));
}


Item_t QNameItemImpl::getEBV( ) const
{
  ZorbaErrorAlerts::error_alert (
        error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
		    error_messages::RUNTIME_ERROR,
		    NULL,
		    false,
		    "Effective Boolean Value is not defined for QName!");
  return NULL;
}


xqp_string QNameItemImpl::getStringProperty( ) const
{
  return *thePrefix != "" ? *thePrefix + ":" + *theLocal : *theLocal;
}


xqp_string QNameItemImpl::show() const
{
  return "xs:qname(" + *theNamespace + "," + *thePrefix + "," + *theLocal + ")";
}


/*******************************************************************************
  class AnyUriItem
********************************************************************************/

AnyUriItemImpl::AnyUriItemImpl(const xqpStringStore_t& value) 
  :
  theValue(value)
{
}
  
AnyUriItemImpl::~AnyUriItemImpl()
{
}
  
xqp_string AnyUriItemImpl::getStringValue() const
{
  return theValue;
}

QNameItem_t AnyUriItemImpl::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "anyURI");
}

Item_t AnyUriItemImpl::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createAnyURI(theValue).get_ptr();
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
  return Store::getInstance().getItemFactory().createBoolean(b);
}


xqp_string AnyUriItemImpl::getStringProperty() const
{
  return theValue;
} 


xqp_string AnyUriItemImpl::show() const
{
  return *theValue;
}


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
UntypedAtomicItemNaive::UntypedAtomicItemNaive(const xqpStringStore_t& value)
  :
  theValue(value)
{
}

UntypedAtomicItemNaive::~UntypedAtomicItemNaive()
{
}

xqp_string UntypedAtomicItemNaive::getStringValue() const
{
  return theValue;
}

QNameItem_t UntypedAtomicItemNaive::getType() const
{
  return static_cast<SimpleStore*>(&Store::getInstance())->theUntypedAtomicType;
}

Item_t UntypedAtomicItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().
         createUntypedAtomic(theValue).get_ptr();
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
  return Store::getInstance().getItemFactory().createBoolean(b);
}

xqp_string UntypedAtomicItemNaive::getStringProperty() const
{
  return theValue;
}

xqp_string UntypedAtomicItemNaive::show() const
{
  return *theValue;
}


/*******************************************************************************
  class StingItem
********************************************************************************/
StringItemNaive::StringItemNaive(const xqpStringStore_t& value)
  :
  theValue(value)
{
}

StringItemNaive::~StringItemNaive()
{
}
  
xqp_string StringItemNaive::getStringValue() const
{
  return theValue;
}

QNameItem_t StringItemNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "string");
}

Item_t StringItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createString(theValue);
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
  return Store::getInstance().getItemFactory().createBoolean(b);
}

xqp_string StringItemNaive::getStringProperty() const
{
  return theValue;
}

xqp_string StringItemNaive::show() const
{
  return *theValue;
}


/*******************************************************************************
  class DecimalItem
********************************************************************************/
DecimalItemNaive::DecimalItemNaive ( long double value ) :value_ ( value ) {}

DecimalItemNaive::~DecimalItemNaive() {}

long double DecimalItemNaive::getDecimalValue() const
{
  return this->value_;
}

QNameItem_t DecimalItemNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "decimal");
}

Item_t DecimalItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().
         createDecimal ( this->value_ );
}

uint32_t DecimalItemNaive::hash() const
{
  Assert(0);
  return 0;
}

bool DecimalItemNaive::equals ( Item_t item ) const
{
  return item->getDecimalValue() == this->value_;
}

Item_t DecimalItemNaive::getEBV() const
{
  bool b = ( this->value_ != 0 );
  return Store::getInstance().getItemFactory().createBoolean ( b );
}

xqp_string DecimalItemNaive::getStringProperty() const
{
  std::ostringstream tmp;
  tmp << this->value_;
  return xqp_string ( tmp.str() );
}

xqp_string DecimalItemNaive::show() const
{
  return this->getStringProperty();
}
/* end class DecimalItem */

/* start class IntItem */
IntItemNaive::IntItemNaive ( int value ) :value_ ( value ) {}

IntItemNaive::~IntItemNaive() {}

int32_t IntItemNaive::getIntValue() const
{
  return this->value_;
}

long long IntItemNaive::getIntegerValue() const
{
  return static_cast<long long> ( this->value_ );
}

long double IntItemNaive::getDecimalValue() const
{
  return static_cast<long double> ( this->value_ );
}

QNameItem_t IntItemNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "int");
}

Item_t IntItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createInt(this->value_ );
}

uint32_t IntItemNaive::hash() const
{
  Assert(0);
  return 0;
}

bool IntItemNaive::equals ( Item_t item ) const
{
  return item->getIntValue() == this->value_;
}
  
Item_t IntItemNaive::getEBV() const
{
  bool b = ( this->value_ != 0 );
  return Store::getInstance().getItemFactory().createBoolean ( b );
}

  xqp_string IntItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value_;
		return xqp_string ( tmp.str() );
	}

  xqp_string IntItemNaive::show() const
	{
		return this->getStringProperty();
	}
	/* end class IntItem */

	/* start class IntegerItem */
  IntegerItemNaive::IntegerItemNaive ( long long value ) :value_ ( value ) {}
  IntegerItemNaive::~IntegerItemNaive() {}

	long long IntegerItemNaive::getIntegerValue() const
	{
		return this->value_;
	}

long double IntegerItemNaive::getDecimalValue() const
{
  return static_cast<long double> ( this->value_ );
}

QNameItem_t IntegerItemNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "integer");
}

Item_t IntegerItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createInteger(this->value_ );
}

uint32_t IntegerItemNaive::hash() const
{
  Assert(0);
  return 0;
}

bool IntegerItemNaive::equals ( Item_t item ) const
{
  return item->getIntegerValue() == this->value_;
}

Item_t IntegerItemNaive::getEBV() const
{
  bool b = ( this->value_ != 0 );
  return Store::getInstance().getItemFactory().createBoolean ( b );
}

  xqp_string IntegerItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value_;
		return xqp_string ( tmp.str() );
	}

  xqp_string IntegerItemNaive::show() const
	{
		return this->getStringProperty();
	}
	/* end class IntegerItem */
	
	/* start class DoubleItem */
  DoubleItemNaive::DoubleItemNaive ( double value_arg ) :value ( value_arg ) {}
  DoubleItemNaive::~DoubleItemNaive() {}

  double DoubleItemNaive::getDoubleValue() const
	{
		return this->value;
	}

QNameItem_t DoubleItemNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "double");
}

Item_t DoubleItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createDouble(this->value );
}

uint32_t DoubleItemNaive::hash() const
{
  Assert(0);
  return 0;
}

bool DoubleItemNaive::equals ( Item_t item ) const
{
  return item->getDoubleValue() == this->value;
}

Item_t DoubleItemNaive::getEBV() const
{
  bool b = ( this->value != 0 );
  return Store::getInstance().getItemFactory().createBoolean(b);
}

  xqp_string DoubleItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value;
		return xqp_string ( tmp.str() );
	}

  xqp_string DoubleItemNaive::show() const
	{
		return this->getStringProperty();
	}
	/* end class DoubleItem */
	
	/* start class FloatItem */
  FloatItemNaive::FloatItemNaive( float value_arg ) :value ( value_arg ) {}
  FloatItemNaive::~FloatItemNaive() {}

  float FloatItemNaive::getFloatValue() const
	{
		return this->value;
	}

QNameItem_t FloatItemNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "float");
}

Item_t FloatItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createFloat(this->value);
}

uint32_t FloatItemNaive::hash() const
{
  Assert(0);
  return 0;
}

  bool FloatItemNaive::equals ( Item_t item ) const
	{
		return item->getFloatValue() == this->value;
	}

  Item_t FloatItemNaive::getEBV() const
	{
		bool b = ( this->value != 0 );
		return Store::getInstance().getItemFactory().createBoolean(b);
	}

  xqp_string FloatItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value;
		return xqp_string ( tmp.str() );
	}

  xqp_string FloatItemNaive::show() const
	{
		return this->getStringProperty();
	}
	/* end class FloatItem */

/* start class BooleanItem */
BooleanItemNaive::BooleanItemNaive ( bool value ) :value_ ( value ) {}

BooleanItemNaive::~BooleanItemNaive() {}

bool BooleanItemNaive::getBooleanValue() const
{
  return this->value_;
}

QNameItem_t BooleanItemNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(SimpleStore::XS_URI, "xs", "boolean");
}

Item_t BooleanItemNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createBoolean(this->value_);
}

uint32_t BooleanItemNaive::hash() const
{
  Assert(0);
  return 0;
}

bool BooleanItemNaive::equals ( Item_t item ) const
{
  return item->getBooleanValue() == this->value_;
}

Item_t BooleanItemNaive::getEBV() const
{
  return this->getAtomizationValue();
}

xqp_string BooleanItemNaive::getStringProperty() const
{
  if ( this->value_ )
    return "true";
  else
    return "false";
}

xqp_string BooleanItemNaive::show() const
{
  return this->getStringProperty();
}
/* end class BooleanItem */

}/* namespace xqp */
