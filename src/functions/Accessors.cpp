/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "functions/Accessors.h"
#include "runtime/accessors/AccessorsImpl.h"

using namespace std;

namespace zorba {

fn_data_func::fn_data_func ( const signature& sig ) : function ( sig ) {}

PlanIter_t
fn_data_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  if ( !validate_args ( argv ) )
	{
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);
  }
  return new FnDataIterator ( loc, argv );
}


xqtref_t
fn_data_func::type_check (
	  signature& /*sig*/ ) const
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


PlanIter_t fn_root_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
	{
    ZORBA_ERROR_LOC(  ZorbaError::XPST0017, loc);
  }

  return new FnRootIterator(loc, argv);
}


xqtref_t fn_root_func::type_check(signature& /*sig*/) const
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


PlanIter_t fn_nodename_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
	{
    ZORBA_ERROR_LOC(  ZorbaError::XPST0017, loc);
  }

  return new FnNodeNameIterator(loc, argv);
}


xqtref_t fn_nodename_func::type_check(signature& /*sig*/) const
{
  return GENV_TYPESYSTEM.QNAME_TYPE_QUESTION;
}


bool fn_nodename_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

/*******************************************************************************
  2.2 fn:nilled
********************************************************************************/
fn_nilled_func::fn_nilled_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_nilled_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
  {
    ZORBA_ERROR_LOC(ZorbaError::XPST0017, loc);
  }

  return new FnNilledIterator(loc, argv);
}


xqtref_t fn_nilled_func::type_check(signature& /*sig*/) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
}


bool fn_nilled_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

/*******************************************************************************
  2.5 fn:base-uri
********************************************************************************/
fn_base_uri_func::fn_base_uri_func(const signature& sig) : function (sig)
{
}

PlanIter_t fn_base_uri_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
  {
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);
  }

  return new FnBaseUriIterator(loc, argv);
}

xqtref_t fn_base_uri_func::type_check(signature&) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
}

bool fn_base_uri_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

/*******************************************************************************
  2.6 fn:document-uri
********************************************************************************/
fn_document_uri_func::fn_document_uri_func(const signature& sig) : function (sig)
{
}

PlanIter_t fn_document_uri_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
  {
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);
  }

  return new FnDocumentUriIterator(loc, argv);
}

xqtref_t fn_document_uri_func::type_check(signature&) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
}

bool fn_document_uri_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

/*******************************************************************************
  
********************************************************************************/
fn_name_func::fn_name_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_name_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
	{
    ZORBA_ERROR_LOC(  ZorbaError::XPST0017, loc);
  }

  PlanIter_t nnIter = new FnNodeNameIterator(loc, argv);
  std::vector<PlanIter_t> lVec;
  lVec.push_back(nnIter);
  return new FnStringIterator(loc, lVec, true);
}


xqtref_t fn_name_func::type_check(signature& /*sig*/) const
{
  return GENV_TYPESYSTEM.QNAME_TYPE_QUESTION;
}


bool fn_name_func::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

} /* namespace zorba */
