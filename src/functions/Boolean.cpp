/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "system/globalenv.h"
#include "functions/Boolean.h"
#include "runtime/booleans/compare_types.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/item_iterator.h"
#include "store/api/item_factory.h"
#include "types/typeops.h"

namespace zorba
{

	/* begin class GenericOpComparison */
	GenericOpComparison::GenericOpComparison ( const signature& sig) 
		: function ( sig ) {}

	PlanIter_t
	GenericOpComparison::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return this->createIterator(loc, argv);
	}

	xqtref_t
	GenericOpComparison::type_check ( signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	GenericOpComparison::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 2 );
	}
	/* end class GenericOpComparison */
	
  
  xqtref_t ValueOpComparison::return_type (const std::vector<xqtref_t> &arg_types) const {
    xqtref_t empty = GENV_TYPESYSTEM.EMPTY_TYPE;
    for (int i = 0; i < 2; i++)
      if (TypeOps::is_subtype (*empty, *arg_types [i]))
        return empty;
    return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
  }

  
	/* begin class op_equal */
	op_equal::op_equal( const signature& sig) : GenericOpComparison(sig) {}
	PlanIter_t 
	op_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::GENERAL_EQUAL );
	}
	/* end class op_equal */
	
	/* begin class op_not_equal */
	op_not_equal::op_not_equal( const signature& sig) : GenericOpComparison(sig) {}
	PlanIter_t 
	op_not_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::GENERAL_NOT_EQUAL );
	}
	/* end class op_not_equal */
	
	/* begin class op_greater */
	op_greater::op_greater( const signature& sig) : GenericOpComparison(sig) {}
	PlanIter_t 
	op_greater::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::GENERAL_GREATER );
	}
	/* end class op_greater */
	
	/* begin class op_greater_equal */
	op_greater_equal::op_greater_equal( const signature& sig) : GenericOpComparison(sig) {}
	PlanIter_t 
	op_greater_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::GENERAL_GREATER_EQUAL );
	}
	/* end class op_greater_equal */
	
	/* begin class op_less */
	op_less::op_less( const signature& sig) : GenericOpComparison(sig) {}
	PlanIter_t 
	op_less::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::GENERAL_LESS );
	}
	/* end class op_less */
	
	/* begin class op_less_equal */
	op_less_equal::op_less_equal( const signature& sig) : GenericOpComparison(sig) {}
	PlanIter_t 
	op_less_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::GENERAL_LESS_EQUAL );
	}
	/* end class op_less_equal */

  /* begin class op_value_equal */
	op_value_equal::op_value_equal( const signature& sig) : ValueOpComparison(sig) {}
	PlanIter_t 
	op_value_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::VALUE_EQUAL );
	}
	/* end class op_value_equal */
	
	/* begin class op_value_not_equal */
	op_value_not_equal::op_value_not_equal( const signature& sig) : ValueOpComparison(sig) {}
	PlanIter_t 
	op_value_not_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::VALUE_NOT_EQUAL );
	}
	/* end class op_value_not_equal */
	
	/* begin class op_value_greater */
	op_value_greater::op_value_greater( const signature& sig) : ValueOpComparison(sig) {}
	PlanIter_t 
	op_value_greater::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::VALUE_GREATER );
	}
	/* end class value_op_greater */
	
	/* begin class op_value_greater_equal */
	op_value_greater_equal::op_value_greater_equal( const signature& sig) : ValueOpComparison(sig) {}
	PlanIter_t 
	op_value_greater_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::VALUE_GREATER_EQUAL );
	}
	/* end class op_greater_equal */
	
	/* begin class op_value_less */
	op_value_less::op_value_less( const signature& sig) : ValueOpComparison(sig) {}
	PlanIter_t 
	op_value_less::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::VALUE_LESS );
	}
	/* end class op_value_less */
	
	/* begin class op_value_less_equal */
	op_value_less_equal::op_value_less_equal( const signature& sig) : ValueOpComparison(sig) {}
	PlanIter_t 
	op_value_less_equal::createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const
	{
		return new CompareIterator ( loc, argv[0], argv[1], CompareConsts::VALUE_LESS_EQUAL );
	}
	/* end class op_value_less_equal */

  /* begin class op_is_same_node */
	PlanIter_t
	op_is_same_node::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new OpIsSameNodeIterator ( loc, argv );
	}

	xqtref_t
	op_is_same_node::type_check (
	    signature& sig ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	op_is_same_node::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 2 );
	}
  /* end class op_is_same_node */

  /* begin class op_node_before */
	PlanIter_t
	op_node_before::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new OpNodeBeforeIterator ( loc, argv );
	}

	xqtref_t
	op_node_before::type_check (
	    signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	op_node_before::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 2 );
	}
  /* end class op_node_before */

  /* begin class op_node_after */
	PlanIter_t
	op_node_after::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new OpNodeAfterIterator ( loc, argv );
	}

	xqtref_t
	op_node_after::type_check (
	    signature& sig ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	op_node_after::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 2 );
	}
  /* end class op_node_after */
	
	/* start class op_and */
	op_and::op_and ( const signature& sig ) : function ( sig ) {}

	PlanIter_t
	op_and::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new LogicIterator ( loc, argv[0], argv[1], LogicIterator::AND );
	}

	xqtref_t
	op_and::type_check (
	    signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	op_and::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 2 );
	}
	/* end class op_and */
	
	/*start class op_or */
	op_or::op_or ( const signature& sig ) : function ( sig ) {}

	PlanIter_t
	op_or::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new LogicIterator ( loc, argv[0], argv[1], LogicIterator::OR );
	}

	xqtref_t
	op_or::type_check (
	    signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	op_or::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 2 );
	}
	/* end class op_or */

	/* start class fn_true */
	fn_true::fn_true ( const signature& sig ) :function ( sig ) {}

	PlanIter_t
	fn_true::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new SingletonIterator ( loc, GENV_ITEMFACTORY->createBoolean(true) );
	}

	xqtref_t
	fn_true::type_check (
	    signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	fn_true::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 0 );
	}
	/* end class fn_true */
	
	/* start class fn_false */
	fn_false::fn_false ( const signature& sig ) :function ( sig ) {}

	PlanIter_t
	fn_false::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new SingletonIterator ( loc, GENV_ITEMFACTORY->createBoolean(false) );
	}

	xqtref_t
	fn_false::type_check (
	    signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	fn_false::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 0 );
	}	
	/* end class fn_false */
	
	/* begin class fn_not */
	fn_not::fn_not ( const signature& sig ) :function ( sig ) {}

	PlanIter_t
	fn_not::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new FnBooleanIterator(loc, argv[0], true );
	}

	xqtref_t
	fn_not::type_check (
	    signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	fn_not::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 1 );
	}	
	/* end class fn_not */

	/* start class fn_boolean */
	fn_boolean::fn_boolean ( const signature& sig ) :function ( sig ) {}

	PlanIter_t
	fn_boolean::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
	{
		return new FnBooleanIterator ( loc, argv[0] );
	}

	xqtref_t
	fn_boolean::type_check (
	    signature& /*sig*/ ) const
	{
		return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
	}

	bool
	fn_boolean::validate_args ( std::vector<PlanIter_t>& argv ) const
	{
		return ( argv.size() == 1 );
	}
	/* end class fn_boolean */
}
