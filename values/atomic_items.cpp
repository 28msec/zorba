	/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#include "../values/atomic_items.h"
#include "../runtime/zorba.h"
#include "util/hashfun.h"

namespace xqp
{
	/* start class AtomicItem */
	bool AtomicItem::isNode() const
	{
		return false;
	}
	bool AtomicItem::isAtomic() const
	{
		return true;
	}
	/* end class AtomicItem */

	/* start class QNameItem */
	QNameItem::QNameItem
	( std::string namspace, std::string prefix, std::string local ) :strNamespace_ ( namspace ),strPrefix_ ( prefix ),strLocal_ ( local )
	{}

	xqp_string QNameItem::getQNameNamespace() const
	{
		return this->strNamespace_;
	}

	xqp_string QNameItem::getQNamePrefix() const
	{
		return this->strPrefix_;
	}

	xqp_string QNameItem::getQNameLocalName() const
	{
		return this->strLocal_;
	}
	
	qnamekey_t QNameItem::getQNameKey( ) const
	{
		return hashfun::h64(this->strPrefix_,hashfun::h64(this->strLocal_,hashfun::h64(this->strNamespace_)));
	}

	sequence_type_t QNameItem::getType( ) const
	{
		return xs_qname;
	}

	Item_t QNameItem::getAtomizationValue( ) const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createQName(this->strNamespace_, this->strPrefix_, this->strLocal_);
	}
	Item_t QNameItem::getEBV( ) const
	{
		// TODO Throw correct Error because EBV for QName is not defined
		return NULL;
	}
	xqp_string QNameItem::getStringProperty( ) const
	{
		return this->strPrefix_ != "" ? this->strPrefix_ + ":" + this->strLocal_ : this->strLocal_;
	}
	/* end class QNameItem */

	/* start class StringItem */
	StringItem::StringItem ( xqp_string value ) :strValue_ ( value ) {}

	xqp_string StringItem::getStringValue() const
	{
		return this->strValue_;
	}

	sequence_type_t StringItem::getType() const
	{
		return xs_string;
	}

	Item_t StringItem::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createString(this->strValue_);
	}

	Item_t StringItem::getEBV() const
	{
		bool b = ! ( this->strValue_ == "" );
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( b );
	}

	xqp_string StringItem::getStringProperty() const
	{
		return this->strValue_;
	}
	/* end class StringItem */

	/* start class DecimalItem */
	DecimalItem::DecimalItem ( long double value ) :value_ ( value ) {}

	long double DecimalItem::getDecimalValue() const
	{
		return this->value_;
	}
	
	long double DecimalItem::getNumericValue() const
	{
		return this->value_;
	}

	sequence_type_t DecimalItem::getType() const
	{
		return xs_decimal;
	}

	Item_t DecimalItem::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createDecimal(this->value_);
	}

	Item_t DecimalItem::getEBV() const
	{
		bool b = ( this->value_ == 0 );
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( b );
	}

	xqp_string DecimalItem::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value_;
		return xqp_string ( tmp.str() );
	}
	/* end class DecimalItem */

	/* start class IntItem */
	IntItem::IntItem ( int value ) :value_ ( value ) {}
	
	int32_t IntItem::getIntValue() const
	{
		return this->value_;
	}
	
	long double IntItem::getNumericValue() const
	{
		return this->value_;
	}
	
	sequence_type_t IntItem::getType() const
	{
		return xs_int;
	}
	
	Item_t IntItem::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createInt(this->value_);
	}
	
	Item_t IntItem::getEBV() const
	{
		bool b = ( this->value_ == 0 );
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( b );
	}
	
	xqp_string IntItem::getStringProperty() const
	{
		std::ostringstream tmp;
		tmp << this->value_;
		return xqp_string(tmp.str());
	}
	
	xqp_string IntItem::show() const {
		return "xs:int(" + this->getStringProperty() + ")";
	}
	/* end class IntItem */
	
	/* start class IntegerItem */
	IntegerItem::IntegerItem ( int value ) :IntItem ( value ) {}
	
	sequence_type_t IntegerItem::getType() const
	{
		return xs_integer;
	}
	
	Item_t IntegerItem::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(this->value_);
	}
	
	xqp_string IntegerItem::show() const {
		return "xs:integer(" + this->getStringProperty() + ")";
	}
	/* end class IntegerItem */
	
	/* start class BooleanItem */
	BooleanItem::BooleanItem ( bool value ) :value_ ( value ) {}
	
	bool BooleanItem::getBooleanValue() const
	{
		return this->value_;
	}
	
	sequence_type_t BooleanItem::getType() const
	{
		return xs_boolean;
	}
	
	Item_t BooleanItem::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(this->value_);
	}
	
	Item_t BooleanItem::getEBV() const
	{
		return this->getAtomizationValue();
	}
	
	xqp_string BooleanItem::getStringProperty() const
	{
		if (this->value_)
			return "true";
		else
			return "false";
	}
	/* end class BooleanItem */

}/* namespace xqp */
