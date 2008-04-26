#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "functions/Accessors.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "types/typeops.h"

using namespace std;

namespace zorba {

PlanIter_t
fn_data_func::codegen(
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann ) const
{
  return new FnDataIterator ( loc, argv[0] );
}


xqtref_t fn_data_func::return_type (const std::vector<xqtref_t> &arg_types) const {
  if (TypeOps::is_subtype (*arg_types [0], *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
    return arg_types [0];
  else
    return sig.return_type ();
}

/*******************************************************************************
  
********************************************************************************/
fn_root_func::fn_root_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_root_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnRootIterator(loc, argv);
}





/*******************************************************************************
  
********************************************************************************/
fn_nodename_func::fn_nodename_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_nodename_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnNodeNameIterator(loc, argv);
}





/*******************************************************************************
  2.2 fn:nilled
********************************************************************************/
fn_nilled_func::fn_nilled_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_nilled_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnNilledIterator(loc, argv);
}





/*******************************************************************************
  2.5 fn:base-uri
********************************************************************************/
fn_base_uri_func::fn_base_uri_func(const signature& sig) : function (sig)
{
}

PlanIter_t fn_base_uri_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnBaseUriIterator(loc, argv);
}



/*******************************************************************************
  2.6 fn:document-uri
********************************************************************************/
fn_document_uri_func::fn_document_uri_func(const signature& sig) : function (sig)
{
}

PlanIter_t fn_document_uri_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDocumentUriIterator(loc, argv);
}



/*******************************************************************************
  
********************************************************************************/
fn_name_func::fn_name_func(const signature& sig) : function (sig)
{
}


PlanIter_t fn_name_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  PlanIter_t nnIter = new FnNodeNameIterator(loc, argv);
  std::vector<PlanIter_t> lVec;
  lVec.push_back(nnIter);
  return new FnStringIterator(loc, lVec, true);
}



} /* namespace zorba */
