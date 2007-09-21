/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "Boolean.h"
#include "BooleanImpl.h"

namespace xqp
{

	/* begin class GenericOpComparison */
	GenericOpComparison::GenericOpComparison ( const signature& sig) 
		: function ( sig ) {}

	Iterator_t
	GenericOpComparison::operator() ( yy::location loc, vector<Iterator_t>& argv ) const
	{
		if ( !validate_args ( argv ) )
		{
			ZorbaErrorAlerts::error_alert (
			    error_messages::XPST0017_STATIC_FUNCTION_NOT_FOUND,
			    error_messages::STATIC_ERROR,
			    &loc
			);
		}
		return this->createIterator(loc, argv);
	}

	TypeCode
	GenericOpComparison::type_check ( signature& sig ) const
	{
		return xs_boolean;
	}

	bool
	GenericOpComparison::validate_args ( vector<Iterator_t>& argv ) const
	{
		return ( argv.size() == 2 );
	}
	/* end class GenericOpComparison */
	
	/* begin class op_equal */
	op_equal::op_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::GENERAL_EQUAL );
	}
	/* end class op_equal */
	
	/* begin class op_not_equal */
	op_not_equal::op_not_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_not_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::GENERAL_NOT_EQUAL );
	}
	/* end class op_not_equal */
	
	/* begin class op_greater */
	op_greater::op_greater( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_greater::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::GENERAL_GREATER );
	}
	/* end class op_greater */
	
	/* begin class op_greater_equal */
	op_greater_equal::op_greater_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_greater_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::GENERAL_GREATER_EQUAL );
	}
	/* end class op_greater_equal */
	
	/* begin class op_less */
	op_less::op_less( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_less::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::GENERAL_LESS );
	}
	/* end class op_less */
	
	/* begin class op_less_equal */
	op_less_equal::op_less_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_less_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::GENERAL_LESS_EQUAL );
	}
	/* end class op_less_equal */

		/* begin class op_value_equal */
	op_value_equal::op_value_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_value_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::VALUE_EQUAL );
	}
	/* end class op_value_equal */
	
	/* begin class op_value_not_equal */
	op_value_not_equal::op_value_not_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_value_not_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::VALUE_NOT_EQUAL );
	}
	/* end class op_value_not_equal */
	
	/* begin class op_value_greater */
	op_value_greater::op_value_greater( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_value_greater::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::VALUE_GREATER );
	}
	/* end class value_op_greater */
	
	/* begin class op_value_greater_equal */
	op_value_greater_equal::op_value_greater_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_value_greater_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::VALUE_GREATER_EQUAL );
	}
	/* end class op_greater_equal */
	
	/* begin class op_value_less */
	op_value_less::op_value_less( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_value_less::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::VALUE_LESS );
	}
	/* end class op_value_less */
	
	/* begin class op_value_less_equal */
	op_value_less_equal::op_value_less_equal( const signature& sig) : GenericOpComparison(sig) {}
	Iterator_t 
	op_value_less_equal::createIterator ( yy::location loc, std::vector<Iterator_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareIterator::VALUE_LESS_EQUAL );
	}
	/* end class op_value_less_equal */

	/*______________________________________________________________________
	|
	|	15.1.1 fn:boolean
	|	fn:boolean($arg as item()*) as xs:boolean
	|
	|	Computes the effective boolean value of the sequence $arg.
	|_______________________________________________________________________*/
	fn_boolean::fn_boolean ( const signature& sig ) :function ( sig ) {}

	Iterator_t
	fn_boolean::operator() (
	    yy::location loc,
	    vector<Iterator_t>& argv ) const
	{
		if ( !validate_args ( argv ) )
		{
			ZorbaErrorAlerts::error_alert (
			    error_messages::XPST0017_STATIC_FUNCTION_NOT_FOUND,
			    error_messages::STATIC_ERROR,
			    &loc
			);
		}
		return new FnBooleanIterator ( loc, argv[0] );
	}

	TypeCode
	fn_boolean::type_check (
	    signature& sig ) const
	{
		return xs_boolean;
	}

	bool
	fn_boolean::validate_args ( vector<Iterator_t>& argv ) const
	{
		return ( argv.size() == 1 );
	}

}
