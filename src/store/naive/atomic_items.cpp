/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
*
*  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
*
*    Copyright 2006-2007 FLWOR Foundation.
*  Author: David Graf (david.graf@28msec.com), Donald Kossmann, Tim Kraska
*
*/


#include "store/naive/atomic_items.h"
#include "util/zorba.h"
#include "store/api/item.h"

namespace xqp
{
	/* start class QNameItem */
  QNameItemNaive::QNameItemNaive ( xqp_string _namespace, xqp_string prefix, xqp_string localname )
			:
			strNamespace_ ( _namespace ), strPrefix_ ( prefix ), strLocal_ ( localname ) {}

  QNameItemNaive::~QNameItemNaive() {}

  xqp_string QNameItemNaive::getNamespace() const
	{
		return this->strNamespace_;
	}

  xqp_string QNameItemNaive::getPrefix() const
	{
		return this->strPrefix_;
	}

  xqp_string QNameItemNaive::getLocalName() const
	{
		return this->strLocal_;
	}

  qnamekey_t QNameItemNaive::getQNameKey( ) const
	{
		return Item::createQNameKey ( this->strNamespace_, this->strPrefix_, this->strLocal_ );
	}

  TypeCode QNameItemNaive::getType( ) const
	{
		return xs_qname;
	}

  Item_t QNameItemNaive::getAtomizationValue( ) const
	{
		return zorba::getItemFactory()->createQName ( this->strNamespace_, this->strPrefix_, this->strLocal_ );
	}

  bool QNameItemNaive::equals ( Item_t item ) const
	{
		return ( item->getNamespace() == this->strNamespace_
		         && item->getLocalName() == this->strLocal_ );
	}

  Item_t QNameItemNaive::getEBV( ) const
	{
		ZorbaErrorAlerts::error_alert (
		    error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
		    error_messages::RUNTIME_ERROR,
		    NULL,
		    false,
		    "Effective Boolean Value is not defined for QName!"
		);
		return NULL;
	}
  xqp_string QNameItemNaive::getStringProperty( ) const
	{
		return this->strPrefix_ != "" ? this->strPrefix_ + ":" + this->strLocal_ : this->strLocal_;
	}
  xqp_string QNameItemNaive::show() const
	{
		return "xs:qname(" + this->strNamespace_ + "," + this->strPrefix_ + "," + this->strLocal_ + ")";
	}
	/* end class QNameItem */

	/* start class UntypedAtomicItem */
  UntypedAtomicItemNaive::UntypedAtomicItemNaive ( xqp_string value ) : strValue_ ( value ) {}

  UntypedAtomicItemNaive::~UntypedAtomicItemNaive() {}

  xqp_string UntypedAtomicItemNaive::getStringValue() const
	{
		return this->strValue_;
	}

  TypeCode UntypedAtomicItemNaive::getType() const
	{
		return xs_untypedAtomicValue;
	}

  Item_t UntypedAtomicItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createUntypedAtomic ( this->strValue_ );
	}

  bool UntypedAtomicItemNaive::equals ( Item_t item ) const
	{
		return item->getStringValue() == this->strValue_;
	}

  Item_t UntypedAtomicItemNaive::getEBV() const
	{
		bool b = ! ( this->strValue_ == "" );
		return zorba::getItemFactory()->createBoolean ( b );
	}

  xqp_string UntypedAtomicItemNaive::getStringProperty() const
	{
		return this->strValue_;
	}

  xqp_string UntypedAtomicItemNaive::show() const
	{
		return "xs:untypedAtomic(" + this->strValue_ + ")";
	}
	/* end class UntypedAtomicItem */

	/* start class StringItem */
  StringItemNaive::StringItemNaive ( const xqp_string& value ) : strValue_ ( value ) {}

  StringItemNaive::~StringItemNaive() {}
  
  xqp_string StringItemNaive::getStringValue() const
  {
    return this->strValue_;
  }

  TypeCode StringItemNaive::getType() const
	{
		return xs_string;
	}

  Item_t StringItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createString ( this->strValue_ );
	}

  bool StringItemNaive::equals ( Item_t item ) const
	{
		return item->getStringValue() == this->strValue_;
	}
  
  Item_t StringItemNaive::getEBV() const
  {
    bool b = ! ( this->strValue_ == "" );
    return zorba::getItemFactory()->createBoolean ( b );
  }

  xqp_string StringItemNaive::getStringProperty() const
  {
    return this->strValue_;
  }

  xqp_string StringItemNaive::show() const
	{
		return "xs:string(" + this->strValue_ + ")";
	}
	/* end class StringItem */

	/* start class DecimalItem */
  DecimalItemNaive::DecimalItemNaive ( long double value ) :value_ ( value ) {}
  DecimalItemNaive::~DecimalItemNaive() {}
  long double DecimalItemNaive::getDecimalValue() const
	{
		return this->value_;
	}

  TypeCode DecimalItemNaive::getType() const
	{
		return xs_decimal;
	}

  Item_t DecimalItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createDecimal ( this->value_ );
	}

  bool DecimalItemNaive::equals ( Item_t item ) const
	{
		return item->getDecimalValue() == this->value_;
	}

  Item_t DecimalItemNaive::getEBV() const
	{
		bool b = ( this->value_ != 0 );
		return zorba::getItemFactory()->createBoolean ( b );
	}

  xqp_string DecimalItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value_;
		return xqp_string ( tmp.str() );
	}

  xqp_string DecimalItemNaive::show() const
	{
		return "xs:decimal(" + this->getStringProperty() + ")";
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

  TypeCode IntItemNaive::getType() const
	{
		return xs_int;
	}

  Item_t IntItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createInt ( this->value_ );
	}

  bool IntItemNaive::equals ( Item_t item ) const
	{
		return item->getIntValue() == this->value_;
	}

  Item_t IntItemNaive::getEBV() const
	{
		bool b = ( this->value_ != 0 );
		return zorba::getItemFactory()->createBoolean ( b );
	}

  xqp_string IntItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value_;
		return xqp_string ( tmp.str() );
	}

  xqp_string IntItemNaive::show() const
	{
		return "xs:int(" + this->getStringProperty() + ")";
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

  TypeCode IntegerItemNaive::getType() const
	{
		return xs_integer;
	}

  Item_t IntegerItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createInteger ( this->value_ );
	}

  bool IntegerItemNaive::equals ( Item_t item ) const
	{
		return item->getIntegerValue() == this->value_;
	}

  Item_t IntegerItemNaive::getEBV() const
	{
		bool b = ( this->value_ != 0 );
		return zorba::getItemFactory()->createBoolean ( b );
	}

  xqp_string IntegerItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value_;
		return xqp_string ( tmp.str() );
	}

  xqp_string IntegerItemNaive::show() const
	{
		return "xs:integer(" + this->getStringProperty() + ")";
	}
	/* end class IntegerItem */
	
	/* start class DoubleItem */
  DoubleItemNaive::DoubleItemNaive ( double value_arg ) :value ( value_arg ) {}
  DoubleItemNaive::~DoubleItemNaive() {}

  double DoubleItemNaive::getDoubleValue() const
	{
		return this->value;
	}

  TypeCode DoubleItemNaive::getType() const
	{
		return xs_double;
	}

  Item_t DoubleItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createDouble ( this->value );
	}

  bool DoubleItemNaive::equals ( Item_t item ) const
	{
		return item->getDoubleValue() == this->value;
	}

  Item_t DoubleItemNaive::getEBV() const
	{
		bool b = ( this->value != 0 );
		return zorba::getItemFactory()->createBoolean ( b );
	}

  xqp_string DoubleItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value;
		return xqp_string ( tmp.str() );
	}

  xqp_string DoubleItemNaive::show() const
	{
		return "xs:double(" + this->getStringProperty() + ")";
	}
	/* end class DoubleItem */
	
	/* start class FloatItem */
  FloatItemNaive::FloatItemNaive( float value_arg ) :value ( value_arg ) {}
  FloatItemNaive::~FloatItemNaive() {}

  float FloatItemNaive::getFloatValue() const
	{
		return this->value;
	}

  TypeCode FloatItemNaive::getType() const
	{
		return xs_double;
	}

  Item_t FloatItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createFloat ( this->value );
	}

  bool FloatItemNaive::equals ( Item_t item ) const
	{
		return item->getFloatValue() == this->value;
	}

  Item_t FloatItemNaive::getEBV() const
	{
		bool b = ( this->value != 0 );
		return zorba::getItemFactory()->createBoolean ( b );
	}

  xqp_string FloatItemNaive::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value;
		return xqp_string ( tmp.str() );
	}

  xqp_string FloatItemNaive::show() const
	{
		return "xs:float(" + this->getStringProperty() + ")";
	}
	/* end class FloatItem */

	/* start class BooleanItem */
  BooleanItemNaive::BooleanItemNaive ( bool value ) :value_ ( value ) {}
  BooleanItemNaive::~BooleanItemNaive() {}

  bool BooleanItemNaive::getBooleanValue() const
	{
		return this->value_;
	}

  TypeCode BooleanItemNaive::getType() const
	{
		return xs_boolean;
	}

  Item_t BooleanItemNaive::getAtomizationValue() const
	{
		return zorba::getItemFactory()->createBoolean ( this->value_ );
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
		return "xs:boolean(" + this->getStringProperty() + ")";
	}
	/* end class BooleanItem */

}/* namespace xqp */
