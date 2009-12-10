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
 
#include <vector>

#include "functions/accessors_impl.h"
#include "functions/single_seq_func.h"
#include "functions/function_impl.h"
#include "runtime/accessors/accessors.h"
#include "functions/func_accessors.h"

#include "types/typeops.h"

#include "system/globalenv.h"


namespace zorba 
{

/*******************************************************************************
  
********************************************************************************/
xqtref_t fn_data::return_type(const std::vector<xqtref_t>& arg_types) const
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  if (TypeOps::is_subtype(*arg_types[0], *RTM.ANY_ATOMIC_TYPE_STAR))
    return arg_types[0];  // includes () case

  const XQType& argType = *arg_types[0];
  TypeConstants::quantifier_t q = TypeOps::quantifier(argType);

  if (argType.type_kind() == XQType::NODE_TYPE_KIND)
  {
    const NodeXQType& nType = static_cast<const NodeXQType&>(argType);

    store::StoreConsts::NodeKind nodeKind = nType.get_node_kind();

    if (nodeKind == store::StoreConsts::piNode ||
        nodeKind == store::StoreConsts::commentNode)
    {
      return RTM.create_builtin_atomic_type(TypeConstants::XS_STRING, q);
    }

    if (nodeKind == store::StoreConsts::documentNode ||
        nodeKind == store::StoreConsts::textNode)
    {
      return RTM.create_builtin_atomic_type(TypeConstants::XS_UNTYPED_ATOMIC, q);
    }
    
    xqtref_t cType = nType.get_content_type();
    if (cType != NULL)
    {
      if (cType->isList())
      {
        const XQType* itemType = static_cast<const UserDefinedXQType*>(cType.getp())->
                                 getListItemType();
        return RTM.create_type(*itemType, TypeConstants::QUANT_STAR);
      }
      else if (TypeOps::is_equal(*cType, *RTM.UNTYPED_TYPE))
      {
        return RTM.create_builtin_atomic_type(TypeConstants::XS_UNTYPED_ATOMIC, q);
      }
      else if (TypeOps::is_subtype(*cType, *RTM.ANY_ATOMIC_TYPE_STAR))
      {
        return RTM.create_type(*cType, q);
      }
    }
  }

  return RTM.create_builtin_atomic_type(TypeConstants::XS_ANY_ATOMIC,
                                        TypeConstants::QUANT_STAR);
}


/*******************************************************************************
  
********************************************************************************/
PlanIter_t fn_name_func::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  PlanIter_t nnIter = new NodeNameIterator(sctx, loc, argv);
  std::vector<PlanIter_t> lVec;
  lVec.push_back(nnIter);
  return new FnStringIterator(sctx, loc, lVec, true);
}


/*******************************************************************************
  
********************************************************************************/
PlanIter_t fn_string::codegen(
      CompilerCB* /*cb*/,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      AnnotationHolder& ann) const
{
  return new FnStringIterator(sctx, loc, argv, true);
}


/*******************************************************************************
  
********************************************************************************/
void populate_context_accessors_impl(static_context* sctx)
{
  DECL(sctx, fn_name_func,
       (createQName(XQUERY_FN_NS, "fn", "name"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, GENV_TYPESYSTEM.STRING_TYPE_ONE));
}



} /* namespace zorba */
