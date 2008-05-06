/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
    return arg_types [0];  // includes () case
  else
    return GENV_TYPESYSTEM.create_atomic_type (TypeConstants::XS_ANY_ATOMIC, TypeOps::quantifier (*arg_types [0]));
}

/*******************************************************************************
  
********************************************************************************/

PlanIter_t fn_root_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnRootIterator(loc, argv);
}





/*******************************************************************************
  
********************************************************************************/

PlanIter_t fn_nodename_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnNodeNameIterator(loc, argv);
}





/*******************************************************************************
  2.2 fn:nilled
********************************************************************************/

PlanIter_t fn_nilled_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnNilledIterator(loc, argv);
}





/*******************************************************************************
  2.5 fn:base-uri
********************************************************************************/
PlanIter_t fn_base_uri_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnBaseUriIterator(loc, argv);
}



/*******************************************************************************
  2.6 fn:document-uri
********************************************************************************/
PlanIter_t fn_document_uri_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDocumentUriIterator(loc, argv);
}



/*******************************************************************************
  
********************************************************************************/

PlanIter_t fn_name_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  PlanIter_t nnIter = new FnNodeNameIterator(loc, argv);
  std::vector<PlanIter_t> lVec;
  lVec.push_back(nnIter);
  return new FnStringIterator(loc, lVec, true);
}



} /* namespace zorba */
