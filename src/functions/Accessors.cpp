/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "errors/error_factory.h"
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
    ZorbaAlertFactory::error_alert (
		   ZorbaError::XPST0017,
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
		   ZorbaError::XPST0017,
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

/*******************************************************************************
  
********************************************************************************/
fn_nodename_func::fn_nodename_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_nodename_func::operator() (
    const yy::location& loc,
    vector<PlanIter_t>& argv) const
{
  if (!validate_args(argv))
	{
    ZORBA_ERROR_ALERT(
		   ZorbaError::XPST0017,
       &loc
		);
  }

  return new FnNodeNameIterator(loc, argv[0]);
}


TypeSystem::xqtref_t fn_nodename_func::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.QNAME_TYPE_QUESTION;
}


bool fn_nodename_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

/*******************************************************************************
  
********************************************************************************/
fn_name_func::fn_name_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_name_func::operator() (
    const yy::location& loc,
    vector<PlanIter_t>& argv) const
{
  if (!validate_args(argv))
	{
    ZORBA_ERROR_ALERT(
		   ZorbaError::XPST0017,
       &loc
		);
  }

  PlanIter_t nnIter = new FnNodeNameIterator(loc, argv[0]);

  return new FnStringIterator(loc, nnIter, true);
}


TypeSystem::xqtref_t fn_name_func::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.QNAME_TYPE_QUESTION;
}


bool fn_name_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

} /* namespace xqp */
