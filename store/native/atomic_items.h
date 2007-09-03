/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

// TODO move into store/nativeStore

#ifndef XQP_ATOMIC_ITEMS_H
#define XQP_ATOMIC_ITEMS_H

#include "../api/item.h"

namespace xqp
{
	typedef uint64_t qnamekey_t;

	class AtomicItem : public Item
	{
			bool isNode() const;
			bool isAtomic() const;
	}; /* class AtomicItem */

	class QNameItem : public AtomicItem
	{
		private:
			xqp_string strNamespace_;
			xqp_string strPrefix_;
			xqp_string strLocal_;

		public:
			QNameItem ( xqp_string, xqp_string, xqp_string );

			xqp_string getQNameNamespace() const;
			xqp_string getQNamePrefix() const;
			xqp_string getQNameLocalName() const;
			qnamekey_t getQNameKey( ) const;

			sequence_type_t getType( ) const;
			Item_t getAtomizationValue( ) const;
			Item_t getEBV( ) const;
			xqp_string getStringProperty( ) const;
	};  /* class QNameItem */

	class StringItem : public AtomicItem
	{
		private:
			xqp_string strValue_;

		public:
			StringItem ( xqp_string value );
			xqp_string getStringValue() const;

			sequence_type_t getType( ) const;
			Item_t getAtomizationValue( ) const;
			Item_t getEBV( ) const;
			xqp_string getStringProperty( ) const;
			xqp_string show() const;
	}; /* class StringItem */


	// TODO +inf, -inf, not-a-number handling
	class DecimalItem : public AtomicItem
	{
		private:
			long double value_;

		public:
			DecimalItem ( long double value );
			long double getDecimalValue() const;

			sequence_type_t getType( ) const;
			Item_t getAtomizationValue( ) const;
			Item_t getEBV( ) const;
			xqp_string getStringProperty( ) const;
	}; /* class DecimalItem */

	// TODO +inf, -inf, not-a-number handling
	class IntItem : public AtomicItem
	{
		protected:
			int value_;

		public:
			IntItem ( int value );
			int32_t getIntValue() const;
			long long getIntegerValue() const;
			long double getDecimalValue() const;

			sequence_type_t getType( ) const;
			Item_t getAtomizationValue( ) const;
			Item_t getEBV( ) const;
			xqp_string getStringProperty() const;
			
			xqp_string show() const;
	}; /* class IntItem */
	
	class IntegerItem : public AtomicItem
	{
		protected:
			long long value_;
		public:
			IntegerItem( long long value );
			long long getIntegerValue() const;
			long double getDecimalValue() const;
			
			sequence_type_t getType() const;
			Item_t getAtomizationValue( ) const;
			Item_t getEBV( ) const;
			xqp_string getStringProperty() const;
			
			xqp_string show() const;
	}; /* class IntegerItem */
	
	class BooleanItem : public AtomicItem
	{
		private:
			bool value_;
			
		public:
			BooleanItem ( bool value );
			bool getBooleanValue() const;
			
			sequence_type_t getType() const;
			Item_t getAtomizationValue() const;
			Item_t getEBV( ) const;
			xqp_string getStringProperty() const;
	}; /* class BooleanItem */

} /* namespace xqp */
#endif /* XQP_VALUES_H */
