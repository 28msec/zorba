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


xqtref_t fn_data_func::return_type (const std::vector<xqtref_t> &arg_types) const 
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  if (TypeOps::is_subtype (*arg_types [0], *RTM.ANY_ATOMIC_TYPE_STAR))
    return arg_types [0];  // includes () case

  TypeConstants::quantifier_t q = TypeOps::quantifier (*arg_types [0]);

  if (TypeOps::is_subtype(*arg_types[0], *RTM.ANY_NODE_TYPE_STAR)) 
  {
    const XQType& type = *arg_types[0];
    if (type.type_kind() == XQType::NODE_TYPE_KIND) 
    {
      const NodeXQType& nType = static_cast<const NodeXQType&>(type);

      store::StoreConsts::NodeKind nodeKind = nType.get_node_kind();

      if (nodeKind == store::StoreConsts::piNode ||
          nodeKind == store::StoreConsts::commentNode)
      {
        return RTM.create_atomic_type(TypeConstants::XS_STRING, q);
      }

      if (nodeKind == store::StoreConsts::documentNode ||
          nodeKind == store::StoreConsts::textNode)
      {
        return RTM.create_atomic_type(TypeConstants::XS_UNTYPED_ATOMIC, q);
      }

      xqtref_t cType = nType.get_content_type();
      if (cType != NULL) 
      {
        if (TypeOps::is_equal(*cType, *RTM.UNTYPED_TYPE))
          return RTM.create_atomic_type(TypeConstants::XS_UNTYPED_ATOMIC, q);
      }
    }
  }

  return RTM.create_atomic_type (TypeConstants::XS_ANY_ATOMIC, q);
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

PlanIter_t fn_string_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnStringIterator(loc, argv, true);
}


} /* namespace zorba */
