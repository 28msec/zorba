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

#include "../api/item.h"

namespace xqp
{
	typedef uint64_t qnamekey_t;

	class AtomicItem : public Item
	{
		public:
			virtual ~AtomicItem();
			bool isNode() const;
			bool isAtomic() const;

			virtual Iterator_t getTypedValue() const;
	}; /* class AtomicItem */

	class QNameItem : public AtomicItem
	{
		private:
			xqp_string strNamespace_;
			xqp_string strPrefix_;
			xqp_string strLocal_;

		public:
			QNameItem ( xqp_string, xqp_string, xqp_string );
			virtual ~QNameItem();

			virtual xqp_string getNamespace() const;
			virtual xqp_string getPrefix() const;
			virtual xqp_string getLocalName() const;
			virtual qnamekey_t getQNameKey( ) const;

			virtual TypeCode getType( ) const;
			virtual Item_t getAtomizationValue( ) const;
			virtual bool equals ( Item_t ) const;
			virtual Item_t getEBV( ) const;
			virtual xqp_string getStringProperty( ) const;

			virtual xqp_string show() const;
	};  /* class QNameItem */

	class UntypedAtomicItem : public AtomicItem
	{
		protected:
			xqp_string strValue_;

		public:
			UntypedAtomicItem ( xqp_string value );
			virtual ~UntypedAtomicItem();
			virtual xqp_string getStringValue() const;

			virtual sequence_type_t getType( ) const;
			virtual Item_t getAtomizationValue( ) const;
			virtual bool equals ( Item_t ) const;
			virtual Item_t getEBV( ) const;
			virtual xqp_string getStringProperty( ) const;

			virtual xqp_string show() const;
	}; /* class UntypedAtomicItem */

	class StringItem : public UntypedAtomicItem
	{
		public:
			StringItem ( xqp_string value );
			virtual ~StringItem();

			virtual TypeCode getType( ) const;
			virtual Item_t getAtomizationValue( ) const;
			virtual bool equals ( Item_t ) const;

			virtual xqp_string show() const;
	}; /* class StringItem */


	class DecimalItem : public AtomicItem
	{
		private:
			long double value_;

		public:
			DecimalItem ( long double value );
			virtual ~DecimalItem();
			virtual long double getDecimalValue() const;

			virtual TypeCode getType( ) const;
			virtual Item_t getAtomizationValue( ) const;
			virtual bool equals ( Item_t ) const;
			virtual Item_t getEBV( ) const;
			virtual xqp_string getStringProperty( ) const;

			virtual xqp_string show() const;
	}; /* class DecimalItem */

	class IntItem : public AtomicItem
	{
		protected:
			int value_;

		public:
			IntItem ( int value );
			virtual ~IntItem();
			virtual int32_t getIntValue() const;
			virtual long long getIntegerValue() const;
			virtual long double getDecimalValue() const;

			virtual TypeCode getType( ) const;
			virtual Item_t getAtomizationValue( ) const;
			virtual bool equals ( Item_t ) const;
			virtual Item_t getEBV( ) const;
			virtual xqp_string getStringProperty() const;

			virtual xqp_string show() const;
	}; /* class IntItem */

	class IntegerItem : public AtomicItem
	{
		protected:
			long long value_;
		public:
			IntegerItem ( long long value );
			virtual ~IntegerItem();
			virtual long long getIntegerValue() const;
			virtual long double getDecimalValue() const;

			virtual TypeCode getType() const;
			virtual Item_t getAtomizationValue( ) const;
			virtual bool equals ( Item_t ) const;
			virtual Item_t getEBV( ) const;
			virtual xqp_string getStringProperty() const;

			virtual xqp_string show() const;
	}; /* class IntegerItem */

	class BooleanItem : public AtomicItem
	{
		private:
			bool value_;

		public:
			BooleanItem ( bool value );
			virtual ~BooleanItem();
			virtual bool getBooleanValue() const;

			virtual TypeCode getType() const;
			virtual Item_t getAtomizationValue() const;
			virtual bool equals ( Item_t ) const;
			virtual Item_t getEBV( ) const;
			virtual xqp_string getStringProperty() const;

			virtual xqp_string show() const;
	}; /* class BooleanItem */

} /* namespace xqp */
#endif /* XQP_ATOMIC_ITEMS_H */
