/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "system/globalenv.h"
#include "functions/Accessors.h"
#include "runtime/accessors/AccessorsImpl.h"

namespace xqp {

fn_data_func::fn_data_func ( const signature& sig ) : function ( sig ) {}

PlanIter_t
fn_data_func::operator() (
    const yy::location& loc,
    vector<PlanIter_t>& argv ) const
{
  if ( !validate_args ( argv ) )
	{
    ZorbaErrorAlerts::error_alert (
		   error_messages::XPST0017,
       &loc
		);
  }
  return new FnDataIterator ( loc, argv[0] );
}


TypeSystem::xqtref_t
fn_data_func::type_check (
	  signature& sig ) const
{
// 		return xs_anySimpleTypeSeq;
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


bool
fn_data_func::validate_args ( vector<PlanIter_t>& argv ) const
{
  return ( argv.size() == 1 );
}



/*******************************************************************************
  
********************************************************************************/
fn_root_func::fn_root_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_root_func::operator() (
    const yy::location& loc,
    vector<PlanIter_t>& argv) const
{
  if (!validate_args(argv))
	{
    ZORBA_ERROR_ALERT(
		   error_messages::XPST0017,
       &loc
		);
  }

  return new FnRootIterator(loc, argv[0]);
}


TypeSystem::xqtref_t fn_root_func::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
}


bool fn_root_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}



	
} /* namespace xqp */
